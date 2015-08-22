/*
 * vf500_sound.c
 *
 *  Created on: May 28, 2015
 *      Author: sid
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>
#include <linux/clk.h>
#include <linux/of_platform.h>
#include <linux/export.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <uapi/asm-generic/errno-base.h>
#include <linux/of_irq.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/initval.h>
#include <sound/control.h>

#include <linux/interrupt.h>

#include "fsl_vf500_snd.h"

//todo: test different frequencies, mixer, stereo, test different divider (64)


static char *clk_name[] = {"pdb_clk", "dac0_clk", "dac1_clk", "dmamux2_clk", "dmamux3_clk"};

/*static int voltab[] =
{
	2539,1244,614,404,298,235,192,162,139,122,107,96,86,78,71,64,
	59,54,50,46,42,39,36,33,31,28,26,24,22,20,18,16
};*/
static int voltab[] =
{
  1600,526,311,219,167,135,112,95,83,73,65,58,52,47,43,39,
  36,33,31,28,26,24,22,21,19,18,16,15,14,12,11,10
};


#define REGMAP_PDB	0
#define REGMAP_DAC0	1
#define REGMAP_DAC1	2
#define REGMAP_DMA	3
#define REGMAP_DMAMUX2	4
#define REGMAP_DMAMUX3	5

struct sound_reg
{
	struct clk *clk[5];
	struct regmap *regmap[6];
	struct snd_card *card;
	struct platform_device *pdev;
	struct snd_pcm_substream *substream;			//todo save runtime instead???
	int ack_periode_pos;
	int vol, vol_adjust;
	int en_pin;
	int diffSigOffsetWord;
};

static const struct of_device_id sound_of_match[] =
{
	{ .compatible = "fsl,sound" },
	{ }
};

static const struct regmap_config sound_regmap_config[] =
{
	{ .reg_bits = 32, .reg_stride = 4, .val_bits = 32, .max_register = PDB_DACINT1, .cache_type = REGCACHE_NONE, },
	{ .reg_bits = 32, .reg_stride = 4, .val_bits = 32, .max_register = DAC_STATCTRL, .cache_type = REGCACHE_NONE, },
	{ .reg_bits = 32, .reg_stride = 4, .val_bits = 32, .max_register = DAC_STATCTRL, .cache_type = REGCACHE_NONE, },
	{ .reg_bits = 32, .reg_stride = 4, .val_bits = 32, .max_register = 0x2000, .cache_type = REGCACHE_NONE, },
	{ .reg_bits = 32, .reg_stride = 4, .val_bits = 32, .max_register = 0x1000, .cache_type = REGCACHE_NONE, },
	{ .reg_bits = 32, .reg_stride = 4, .val_bits = 32, .max_register = 0x1000, .cache_type = REGCACHE_NONE, },
};

/* hardware definition */
static struct snd_pcm_hardware snd_mychip_playback_hw = {
        .info = (SNDRV_PCM_INFO_NONINTERLEAVED |
        	SNDRV_PCM_INFO_BLOCK_TRANSFER),			//mmap define removed
        .formats =          SNDRV_PCM_FMTBIT_S16_LE,
        .rates =            SNDRV_PCM_RATE_8000_48000,
        .rate_min =         8000,
        .rate_max =         48000,
        .channels_min =     1,
        .channels_max =     1,
        .buffer_bytes_max = 32768,
        .period_bytes_min = 2048,
        .period_bytes_max = 32768,
        .periods_min =      1,
        .periods_max =      1024,
};

static irqreturn_t snd_pcm_irq(int irq, void *dev_id)
{
	struct sound_reg *sound_reg = dev_id;
	unsigned int position, phys_addr;
	irqreturn_t ret = IRQ_NONE;
	//int test;

	/*clear interrupt */
	ret = regmap_update_bits(sound_reg->regmap[REGMAP_PDB], PDB_SC, PDB_SC_PDBIF_MASK, 0);
	if (ret)
	{
		printk("unable to clear irq\n");
		return IRQ_NONE;
	}


        /* get the current hardware pointer */
	ret = regmap_read(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_SADDR, &phys_addr);
	//ret += regmap_read(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_SADDR, &test);

	//printk("%x-%x\n", phys_addr, test);

	if(ret)
	{
		printk("unable to read DMA1_TCD0_SADDR: %i\n", ret);
		return -1;
	}
	position = (phys_addr - sound_reg->substream->runtime->dma_addr) >> 1;   //adjusted to samples

	//printk("I pos:%i\n", position);


	if(position >= (sound_reg->ack_periode_pos+sound_reg->substream->runtime->period_size) || position < sound_reg->ack_periode_pos)
	{
//		printk("I note\n");
		snd_pcm_period_elapsed(sound_reg->substream);
		sound_reg->ack_periode_pos += sound_reg->substream->runtime->period_size;
		sound_reg->ack_periode_pos %= (sound_reg->substream->runtime->buffer_size);
//		printk("I acked: %i\n", sound_reg->ack_periode_pos);
	}
	else
	{
//		printk("I not quite there\n");
	}

//read proper address from dac dma???

	ret = IRQ_HANDLED;
	return ret;
}

/* open playback */
static int snd_playback_open(struct snd_pcm_substream *substream)
{
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);
//	struct platform_device *pdev = sound_reg->pdev;
        struct snd_pcm_runtime *runtime = substream->runtime;
        int ret, irq;
        //printk("snd_playback_open\n");

        /*store substream pointer*/   //todo: temp
        sound_reg->substream = substream;

        runtime->hw = snd_mychip_playback_hw;
        /* more hardware-initialization will be done here */

        irq = platform_get_irq(sound_reg->pdev, 0);
	if (irq < 0) {
		printk("no irq\n");
		return irq;
	}

	/*clear interrupt */
	ret = regmap_update_bits(sound_reg->regmap[REGMAP_PDB], PDB_SC, PDB_SC_PDBIF_MASK, 0);
	if (ret)
	{
		printk("unable to clear irq\n");
		return IRQ_NONE;
	}

	ret = request_irq(irq, snd_pcm_irq, 0, "fsl-snd", sound_reg);
        if (ret) {
		printk("can't register ISR for IRQ %u (ret=%i)\n", 145, ret);
		return ret;
	}

	return 0;
}

/* close playback */
static int snd_playback_close(struct snd_pcm_substream *substream)
{
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);

        /* the hardware-specific codes will be here */
        int irq = platform_get_irq(sound_reg->pdev, 0);
        //printk("snd_playback_close\n");

        free_irq(irq, sound_reg);

        return 0;

}

/* hw_free callback */
static int snd_pcm_hw_free(struct snd_pcm_substream *substream)
{
	//printk("snd_pcm_hw_free\n");
        return snd_pcm_lib_free_pages(substream);
}

/* hw_params callback */
static int snd_pcm_hw_params(struct snd_pcm_substream *substream, struct snd_pcm_hw_params *hw_params)
{
	int rv;
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);

        //printk("snd_pcm_hw_params, size %i\n", params_buffer_bytes(hw_params));
        sound_reg->diffSigOffsetWord = params_buffer_bytes(hw_params)>>1;

	rv = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params)<<1);

	if (rv < 0)
	{
		printk("pcm audio buffer allocation failure %i\n", rv);
		return rv;
	}

	return 0;

//        return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}

/* prepare callback */
static int snd_pcm_prepare(struct snd_pcm_substream *substream)
{
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);
 	struct snd_pcm_runtime *runtime = substream->runtime;
 	int ret, smod, rateinv, idly = 65536, pdb_prescaler;

        //printk("snd_pcm_prepare\n");

	if(!(snd_mychip_playback_hw.formats & (1UL<<runtime->format)))
	{
		printk("Unsupported format for playback: %i\n", runtime->format);
		return -1000;
	}

	ret = substream->runtime->buffer_size<<1;
	for(smod=0; ret>1; smod++)
	{
		ret >>= 1;
		if((ret&1) && ret!=1)
		{
			printk("Substream buffer size is not a power of 2: %i\n", substream->dma_buffer.bytes);
			return -1001;
		}
	}

	if(smod>31)
	{
		printk("Substream buffer size to big: %i\n", smod);
		return -1002;
	}

	//for some fancy reason, we can not do floating point operation here... workaround:
	switch(runtime->rate)
	{
	case 8000:
		pdb_prescaler = 6;
		rateinv = 129-1;
		break;
	case 11025:
		pdb_prescaler = 5;
		rateinv = 187-1;
		break;
	case 16000:
		pdb_prescaler = 5;
		rateinv = 129-1;
		break;
	case 22050:
		pdb_prescaler = 6;
		rateinv = 47-1;
		break;
	case 32000:
		pdb_prescaler = 6;
		rateinv = 32-1;
		break;
	case 44100:
		pdb_prescaler = 5;
		rateinv = 47-1;
		break;
	case 48000:
		pdb_prescaler = 5;
		rateinv = 43-1;		//11 for further computation
		break;
	default:
		printk("unsupported rate: %i\n", runtime->rate);
		return -1003;
	}

	/* compute interrupt time and fit it into 16bit counter */
	idly = runtime->period_size * (rateinv+1);
	while(idly > 65536)
		idly>>=1;
	idly--;				//-1 to address 0 counter value?make


	//printk("rateinv %i\n", rateinv);


        /* set up the hardware with the current configuration
         * for example...
         */

        //printk("rate %i\n", runtime->rate);
        //printk("channels %i\n", runtime->channels);
        //printk("dma_addr %x dma_buffer.size %i\n", runtime->dma_addr, substream->dma_buffer.bytes);
        //printk("periode size %i\n", (int)runtime->period_size);

	/*
	 * Configure DMA
	 */
	//DMAMUX2->CHCFG[0]
//	ret =  regmap_write(sound_reg->regmap[REGMAP_DMAMUX2], 0, DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(32));
	ret =  regmap_write(sound_reg->regmap[REGMAP_DMAMUX2], 0, DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(32) | (DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(33))<<8);

	//DMA_ERQ
//	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA_ERQ, DMA_ERQ_ERQ0_MASK);
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA_ERQ, DMA_ERQ_ERQ0_MASK | DMA_ERQ_ERQ1_MASK);

	/*Set Source Address*/
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_SADDR, runtime->dma_addr);
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_SADDR, runtime->dma_addr + \
		(sound_reg->diffSigOffsetWord<<1));

	/* Destination address */
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_DADDR, 0x400CC000u);	//DAC0_DAT0
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_DADDR, 0x400CD000u);	//DAC1_DAT0

	/* Source and Destination Modulo off, source and destination size 1 = 32 bits - 4 bytes */
	/* Source offset disabled */
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_ATTR_SOFF, \
		((DMA_ATTR_SMOD(smod) | DMA_ATTR_SSIZE(1) | DMA_ATTR_DSIZE(1))<<16) | 2); //9 1 1 2 //org 2 2 4
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_ATTR_SOFF, \
		((DMA_ATTR_SMOD(smod) | DMA_ATTR_SSIZE(1) | DMA_ATTR_DSIZE(1))<<16) | 2); //9 1 1 2 //org 2 2 4

	/* Transfer N bytes per transaction */
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_NBYTES_MLNO, 32);	//32	//change to org 8
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_NBYTES_MLNO, 32);	//32	//change to org 8

	/* SLAST No adjust needed */
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_SLAST, 0);//0
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_SLAST, 0);//0

	/* No link channel to channel, 1 transaction */
	/* Destination offset disabled */
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_CITER_ELINKYES__ELINKNO_DOFF, \
		(DMA_CITER_ELINKNO_CITER(1)<<16) | 2);		//org 4
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_CITER_ELINKYES__ELINKNO_DOFF, \
		(DMA_CITER_ELINKNO_CITER(1)<<16) | 2);		//org 4

	/* adjustment to	destination address */
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_DLASTSGA, -32);		//org -8???
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_DLASTSGA, -32);		//org -8???

	//??
	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_BITER_ELINKYES__ELINKNO_CSR,
		(DMA_BITER_ELINKNO_BITER(1)<<16) | 0);
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_BITER_ELINKYES__ELINKNO_CSR,
		(DMA_BITER_ELINKNO_BITER(1)<<16) | 0);

	if (ret)
	{
		return -EPERM;
	}

	/*
	 * Configure PDB
	 */
	/*Configure PDB, Enable PDB*/
	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_SC, PDB_SC_PDBEN_MASK);

	/*Set DAC Interval*/
	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_DACINT0, rateinv); //PDB_DAC_INTERVAL-1
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_DACINT1, rateinv); //PDB_DAC_INTERVAL-1

	/*Configure PDB interrupt delay register*/
	/* note: need to be done prior to PDB_SC_LDOK_MASK*/
	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_IDLY, idly);
	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_MOD, idly);

	/*PDB Prescaler*/
	/*PDB Software Trigger*/
	/*PDB Continuous Mode*/
	/*Load Values*/
	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_SC,
			PDB_SC_PDBEN_MASK | PDB_SC_PRESCALER(pdb_prescaler) | PDB_SC_MULT(0) |
			PDB_SC_TRGSEL(15) | PDB_SC_CONT_MASK | PDB_SC_LDOK_MASK | PDB_SC_PDBIE_MASK);

	/*Enable DAC Interval*/
	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_DACINTC0, PDB_DACINTC_TOE_MASK);
/**/	ret += regmap_write(sound_reg->regmap[REGMAP_PDB], PDB_DACINTC1, PDB_DACINTC_TOE_MASK);

	if (ret)
	{
		return -EPERM;
	}

	/*
	 * DAC
	 */
	ret = regmap_write(sound_reg->regmap[REGMAP_DAC0], DAC_STATCTRL,
			DAC_STATCTRL_DACBFUP_MASK | DAC_STATCTRL_DACBFEN | DAC_STATCTRL_DMAEN |
			DAC_STATCTRL_DACEN | DAC_STATCTRL_DACRFS | DAC_STATCTRL_DACBTIEN | DAC_STATCTRL_LPEN );
	ret += regmap_write(sound_reg->regmap[REGMAP_DAC1], DAC_STATCTRL,
			DAC_STATCTRL_DACBFUP_MASK | DAC_STATCTRL_DACBFEN | DAC_STATCTRL_DMAEN |
			DAC_STATCTRL_DACEN | DAC_STATCTRL_DACRFS | DAC_STATCTRL_DACBTIEN | DAC_STATCTRL_LPEN );

	if (ret)
	{
		return -EPERM;
	}



        return 0;
}

/* trigger callback */
static int snd_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
//        int i;
//        unsigned short *ptr16;
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);

        //printk("snd_pcm_trigger: %i\n", cmd);

        switch (cmd) {
        case SNDRV_PCM_TRIGGER_START:

        	/*reset ack*/
        	sound_reg->ack_periode_pos = 0;

        	//enable amp
		gpio_set_value(sound_reg->en_pin, 1);

                /*Trigger PDB*/
        	return regmap_update_bits(sound_reg->regmap[REGMAP_PDB], PDB_SC, PDB_SC_SWTRIG_MASK, PDB_SC_SWTRIG_MASK);
                break;
        case SNDRV_PCM_TRIGGER_STOP:
                /* do something to stop the PCM engine */

  /*      	ptr16 = (void *)substream->dma_buffer.area;
        	for(i=0; i<512; i++)
        	{
        		printk("%04x ", ptr16[i]);
        		if(i%8 == 7)
        	        	printk("\n");

        	}
*/

        	//disable amp
		gpio_set_value(sound_reg->en_pin, 0);

        	/*Disable  PDB*/
        	return regmap_update_bits(sound_reg->regmap[REGMAP_PDB], PDB_SC, PDB_SC_PDBEN_MASK, 0);
                break;
        default:
                return -EINVAL;
        }
        return 0;
}

/* pointer callback */
static snd_pcm_uframes_t snd_pcm_pointer(struct snd_pcm_substream *substream)
{
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);
        unsigned int current_ptr;
        int ret;
        unsigned int phys_addr;

        /* get the current hardware pointer */
	ret = regmap_read(sound_reg->regmap[REGMAP_DMA], DMA1_TCD0_SADDR, &phys_addr);
	ret += regmap_read(sound_reg->regmap[REGMAP_DMA], DMA1_TCD1_SADDR, &phys_addr + (sound_reg->diffSigOffsetWord<<1));
	if(ret)
	{
		printk("unable to read DMA1_TCD0_SADDR: %i\n", ret);
		return -1;
	}

        current_ptr = phys_addr - sound_reg->substream->runtime->dma_addr;
        //printk("snd_pcm_pointer %i\n", (int)bytes_to_frames(substream->runtime, current_ptr));


	return bytes_to_frames(substream->runtime, current_ptr);

}

static int snd_pcm_copy(struct snd_pcm_substream *substream, int channel, snd_pcm_uframes_t pos,
		void __user *buf, snd_pcm_uframes_t count)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct sound_reg *sound_reg = snd_pcm_substream_chip(substream);

	unsigned short *to = (void *) runtime->dma_area + frames_to_bytes(runtime, pos);
	short *from = buf;
	int i;

	//printk("copy: %isamples@%i\n", (int)count, (int)pos);

	for(i=0; i<frames_to_bytes(runtime, count)/sizeof(unsigned short); i++)
	{
		//to[i] = from[i]>>4;
		int16_t in = from[i] / (sound_reg->vol_adjust);

		//ensure limits
		if(in > 2047)
			in = 2047;
		else if(in < -2047)
			in  = -2047;

		to[i] = (uint16_t)(in + 0x800);
		to[i+sound_reg->diffSigOffsetWord] = 0x1000 - to[i];
	}

	return 0;
}

static int snd_pcm_silence(struct snd_pcm_substream *substream, int channel,
		       snd_pcm_uframes_t pos, snd_pcm_uframes_t count)
{
	printk("silence hmmm???\n");
	return 0;
}

/* operators */
static struct snd_pcm_ops snd_playback_ops = {
        .open =        snd_playback_open,
        .close =       snd_playback_close,
        .ioctl =       snd_pcm_lib_ioctl,
        .hw_params =   snd_pcm_hw_params,
        .hw_free =     snd_pcm_hw_free,
        .prepare =     snd_pcm_prepare,
        .trigger =     snd_pcm_trigger,
        .pointer =     snd_pcm_pointer,
        .copy =        snd_pcm_copy,
        .silence =     snd_pcm_silence,
};

static int snd_ctl_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
        uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
        uinfo->count = 1;
        uinfo->value.integer.min = 0;
        uinfo->value.integer.max = 31;
        //printk("get vol info\n");

        return 0;
}

static int snd_ctl_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
        struct sound_reg *sound_reg = snd_kcontrol_chip(kcontrol);
        ucontrol->value.integer.value[0] = sound_reg->vol;
        //printk("get vol %i\n", sound_reg->vol);
        return 0;
}


static int snd_ctl_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct sound_reg *sound_reg = snd_kcontrol_chip(kcontrol);
        int changed = 0;
        //printk("set vol %li\n", ucontrol->value.integer.value[0]);
        if (sound_reg->vol != ucontrol->value.integer.value[0])
        {
        	sound_reg->vol = ucontrol->value.integer.value[0];
        	sound_reg->vol_adjust = voltab[sound_reg->vol];
                changed = 1;
        }
        return changed;
}


static struct snd_kcontrol_new card_ctl = {
        .iface = SNDRV_CTL_ELEM_IFACE_MIXER,
        .name = "Playback Volume",
        .index = 0,
        .access = SNDRV_CTL_ELEM_ACCESS_READWRITE,
        .private_value = 0xffff,
        .info = snd_ctl_info,
        .get = snd_ctl_get,
        .put = snd_ctl_put,
};


static int sound_driver_probe(struct platform_device *pdev)
{
	int i, ret;
	struct sound_reg *sound_reg;
	const struct of_device_id *match;
	struct resource *mem_res;
	void __iomem *base;

	struct snd_pcm *pcm;

	//unsigned short *ptr;

	//printk("Sound probe\n");

	//required???
	match = of_match_node(sound_of_match, pdev->dev.of_node);

	sound_reg = devm_kzalloc(&pdev->dev, sizeof(struct sound_reg), GFP_KERNEL);
	if (IS_ERR(sound_reg))
		return -ENOMEM;

	platform_set_drvdata(pdev, sound_reg);


	/*
	 *
	 * ALSA
	 *
	 */

	sound_reg->vol = 20; //todo magic number
	sound_reg->vol_adjust = voltab[sound_reg->vol];

	///&pdev->dev correct?? something does not seem to work properly
	ret = snd_card_new(&pdev->dev, SNDRV_DEFAULT_IDX1, SNDRV_DEFAULT_STR1, THIS_MODULE, 0, &sound_reg->card);
	if (ret < 0)
	{
		dev_err(&pdev->dev, "new soundcard.\n");
		snd_card_free(sound_reg->card);
		return -ENOMEM;
	}
	strcpy(sound_reg->card->driver, "vf500_sound");
        strcpy(sound_reg->card->shortname, "vf500snd");
        strcpy(sound_reg->card->longname, "VF500 DAC Sound Driver");

        sound_reg->pdev = pdev;

	ret = snd_pcm_new(sound_reg->card, "vf500_pcm", 0, 1, 0, &pcm);
	if (ret)
	{
		dev_err(&pdev->dev, "new soundcard2\n");
		return -ENOMEM;
	}

        /* set operators */
        snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_playback_ops);
        pcm->private_data = sound_reg;
        strcpy(pcm->name, "My PCM");
        pcm->info_flags = SNDRV_PCM_INFO_HALF_DUPLEX;

        /* control */
        ret = snd_ctl_add(sound_reg->card, snd_ctl_new1(&card_ctl, sound_reg));
        if (ret < 0){
        	dev_err(&pdev->dev, " snd_ctl register\n");
                return ret;
        }

        ret = snd_card_register(sound_reg->card);
	if (ret < 0) {
		dev_err(&pdev->dev, " snd_card_register\n");
		return ret;
	}

        /* pre-allocation of buffers */
        /* NOTE: this may fail */
        ret = snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV, &pdev->dev, 64*1024, 64*1024);

        //printk("addr %x\n", pcm->streams[0].substream->dma_buffer.addr);

        //printk("addr %ul\n", pcm->streams[1].substream->dma_buffer.addr);
	/*
	 *
	 *
	 * Hardware
	 *
	 *
	 */


	//regmap
	for(i=0; i<sizeof(sound_regmap_config)/sizeof(struct regmap_config); i++)
	{
		mem_res = platform_get_resource(pdev, IORESOURCE_MEM, i);
		base = devm_ioremap_resource(&pdev->dev, mem_res);
		if (IS_ERR(base))
			return -ENOMEM;

		sound_reg->regmap[i] = devm_regmap_init_mmio(&pdev->dev, base, &sound_regmap_config[i]);
		if (IS_ERR(sound_reg->regmap[i]))
			return PTR_ERR(sound_reg->regmap[i]);
	}

	//Clocks
	for(i=0; i<sizeof (clk_name) / sizeof (*clk_name); i++)
	{
		sound_reg->clk[i] = devm_clk_get(&pdev->dev, clk_name[i]);	//org NULL
		if (IS_ERR(sound_reg->clk[i]))
		{
			dev_err(&pdev->dev, "Get clock failed.\n");
			return PTR_ERR(sound_reg->clk[i]);
		}

		ret = clk_prepare_enable(sound_reg->clk[i]);
		if (ret)
		{
			dev_err(&pdev->dev, "Enable clock failed.\n");
			return ret;
		}
	}

	//EN pin
	if (of_gpio_count(pdev->dev.of_node) != 1)
		return -ENODEV;

	sound_reg->en_pin = of_get_gpio(pdev->dev.of_node, 0);
	if (!gpio_is_valid(sound_reg->en_pin))
	{
		dev_err(&pdev->dev, "%s: invalid GPIO pins, en=%d\n", pdev->dev.of_node->full_name, sound_reg->en_pin);
		return -ENODEV;
	}


	if ((gpio_request(sound_reg->en_pin, "Sound enable") == 0) &&
	    (gpio_direction_output(sound_reg->en_pin, 1) == 0))
	{
		gpio_set_value(sound_reg->en_pin, 0);

		gpio_export(sound_reg->en_pin, 0);
	}
	else
	{
		dev_err(&pdev->dev, "Could not obtain GPIO for Sound enable\n");
		return -ENODEV;
	}

	//test memory
//	ptr = kmalloc(sizeof(unsigned short)*512, GFP_KERNEL);
//	if(ptr == NULL)
//		return -ENOMEM;
//	memcpy(ptr, u16aDAC_Val, sizeof(unsigned short) * 512);
	//phys_addr = virt_to_phys(ptr);

	//memcpy(pcm->streams[0].substream->dma_buffer.area, u16aDAC_Val, sizeof(unsigned short) * 512);


	printk("vf500 sound probed\n");

	return 0;
}

static int sound_driver_remove(struct platform_device *pdev)
{
	int i;
	struct sound_reg *sound_reg;

	printk("vf500 remove\n");

	sound_reg = platform_get_drvdata(pdev);
	if (IS_ERR(sound_reg))
		return -ENOMEM;

	//das soll funktionieren??
	snd_card_free(sound_reg->card);

	for (i = 0; i < sizeof (clk_name) / sizeof (*clk_name); i++)
		clk_disable_unprepare(sound_reg->clk[i]);

	gpio_free(sound_reg->en_pin);

	return 0;
}

static int sound_suspend(struct device *dev)
{
	printk("suspend\n");
	return 0;
}

static int sound_resume(struct device *dev)
{
	printk("resume\n");
	return 0;
}

static const struct dev_pm_ops sound_pm_ops =
{
	SET_SYSTEM_SLEEP_PM_OPS(sound_suspend, sound_resume)
};

static struct platform_driver sound_driver =
{
	.driver =
	{
		.name = "vf500-sound",
		.owner = THIS_MODULE,
		.of_match_table = sound_of_match,
		.pm = &sound_pm_ops,
	},
	.probe = sound_driver_probe,
	.remove = sound_driver_remove,
};


module_platform_driver(sound_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Juergen Eckert juergen@familie-eckert.de");
MODULE_DESCRIPTION("VF50 sound");
