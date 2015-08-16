/*
 * vf500_sound.h
 *
 *  Created on: May 28, 2015
 *      Author: sid
 */

#ifndef VF500_SOUND_H_
#define VF500_SOUND_H_

/*
 *
 *  PDB
 *
 */

#define PDB_SC				0x0000
#define PDB_MOD				0x0004
#define PDB_CNT				0x0008
#define PDB_IDLY			0x000C
#define PDB_CH0C1			0x0010
#define PDB_CH0S			0x0014
#define PDB_CH0DLY0			0x0018
#define PDB_CH0DLY1			0x001C
#define PDB_CH1C1			0x0038
#define PDB_CH1S			0x003C
#define PDB_CH1DLY0			0x0040
#define PDB_CH1DLY1			0x0044
#define PDB_DACINTC0			0x0150
#define PDB_DACINT0			0x0154
#define PDB_DACINTC1			0x0158
#define PDB_DACINT1			0x015C


/* SC Bit Fields */
#define PDB_SC_LDOK_MASK                         0x1u
#define PDB_SC_LDOK_SHIFT                        0
#define PDB_SC_CONT_MASK                         0x2u
#define PDB_SC_CONT_SHIFT                        1
#define PDB_SC_MULT_MASK                         0xCu
#define PDB_SC_MULT_SHIFT                        2
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        0x20u
#define PDB_SC_PDBIE_SHIFT                       5
#define PDB_SC_PDBIF_MASK                        0x40u
#define PDB_SC_PDBIF_SHIFT                       6
#define PDB_SC_PDBEN_MASK                        0x80u
#define PDB_SC_PDBEN_SHIFT                       7
#define PDB_SC_TRGSEL_MASK                       0xF00u
#define PDB_SC_TRGSEL_SHIFT                      8
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    0x7000u
#define PDB_SC_PRESCALER_SHIFT                   12
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        0x8000u
#define PDB_SC_DMAEN_SHIFT                       15
#define PDB_SC_SWTRIG_MASK                       0x10000u
#define PDB_SC_SWTRIG_SHIFT                      16
#define PDB_SC_PDBEIE_MASK                       0x20000u
#define PDB_SC_PDBEIE_SHIFT                      17
#define PDB_SC_LDMOD_MASK                        0xC0000u
#define PDB_SC_LDMOD_SHIFT                       18
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK)
/* MOD Bit Fields */
#define PDB_MOD_MOD_MASK                         0xFFFFu
#define PDB_MOD_MOD_SHIFT                        0
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK)
/* CNT Bit Fields */
#define PDB_CNT_CNT_MASK                         0xFFFFu
#define PDB_CNT_CNT_SHIFT                        0
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK)
/* IDLY Bit Fields */
#define PDB_IDLY_IDLY_MASK                       0xFFFFu
#define PDB_IDLY_IDLY_SHIFT                      0
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK)
/* C1 Bit Fields */
#define PDB_C1_EN_MASK                           0xFFu
#define PDB_C1_EN_SHIFT                          0
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK)
#define PDB_C1_TOS_MASK                          0xFF00u
#define PDB_C1_TOS_SHIFT                         8
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK)
#define PDB_C1_BB_MASK                           0xFF0000u
#define PDB_C1_BB_SHIFT                          16
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK)
/* S Bit Fields */
#define PDB_S_ERR_MASK                           0xFFu
#define PDB_S_ERR_SHIFT                          0
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK)
#define PDB_S_CF_MASK                            0xFF0000u
#define PDB_S_CF_SHIFT                           16
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK)
/* DLY Bit Fields */
#define PDB_DLY_DLY_MASK                         0xFFFFu
#define PDB_DLY_DLY_SHIFT                        0
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK)
/* DACINTC Bit Fields */
#define PDB_DACINTC_TOE_MASK                     0x1u
#define PDB_DACINTC_TOE_SHIFT                    0
#define PDB_DACINTC_EXT_MASK                     0x2u
#define PDB_DACINTC_EXT_SHIFT                    1
/* DACINT Bit Fields */
#define PDB_DACINT_INT_MASK                      0xFFFFu
#define PDB_DACINT_INT_SHIFT                     0
#define PDB_DACINT_INT(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_DACINT_INT_SHIFT))&PDB_DACINT_INT_MASK)

/*
 *
 * DAC
 *
 */

#define DAC_DAT0			0x0000
#define DAC_DAT1			0x0004
#define DAC_DAT2			0x0008
#define DAC_DAT3			0x000C
#define DAC_DAT4			0x0010
#define DAC_DAT5			0x0014
#define DAC_DAT6			0x0018
#define DAC_DAT7			0x001C
#define DAC_STATCTRL			0x0020

#define DAC_STATCTRL_DACBFRP_MASK	0xF0000000u
#define DAC_STATCTRL_DACBFUP_MASK	0x0F000000
#define DAC_STATCTRL_DMAEN		0x00800000
		//2 bit reserved
#define DAC_STATCTRL_DACBFWM_MASK	0x00180000
#define DAC_STATCTRL_DACBFMD_MASK	0x00060000
#define DAC_STATCTRL_DACBFEN		0x00010000
#define DAC_STATCTRL_DACEN		0x00008000
#define DAC_STATCTRL_DACRFS		0x00004000
#define DAC_STATCTRL_DACTRGSEL		0x00002000
#define DAC_STATCTRL_DACSWTRG		0x00001000
#define DAC_STATCTRL_LPEN		0x00000800
#define DAC_STATCTRL_DACBWIEN		0x00000400
#define DAC_STATCTRL_DACBTIEN		0x00000200
#define DAC_STATCTRL_DACBBIEN		0x00000100
		//4 bits reserved
#define DAC_STATCTRL_DACBFWMF		0x00000004
#define DAC_STATCTRL_DACBFRPTF		0x00000002
#define DAC_STATCTRL_DACBFRPBF		0x00000001



/*
 *
 * DMA
 *
 */


#define DMA_CR			0x00
#define DMA_ES			0x04
#define DMA_ERQ			0x0C
#define DMA_EEI			0x14
#define DMA_SERQ		0x1B
#define DMA_CERQ		0x1A
#define DMA_SEEI		0x19
#define DMA_CEEI		0x18
#define DMA_CINT		0x1F
#define DMA_CERR		0x1E
#define DMA_SSRT		0x1D
#define DMA_CDNE		0x1C
#define DMA_INTR		0x24
#define DMA_ERR			0x2C

#define DMA1_TCD0_SADDR				0x1000
#define DMA1_TCD0_ATTR_SOFF			0x1004		//lower 16bit DMA1_TCD0_SOFF
#define DMA1_TCD0_NBYTES_MLNO			0x1008
#define DMA1_TCD0_NBYTES_MLOFFNO		0x1008
#define DMA1_TCD0_NBYTES_MLOFFYES		0x1008
#define DMA1_TCD0_SLAST				0x100C
#define DMA1_TCD0_DADDR				0x1010
#define DMA1_TCD0_CITER_ELINKYES__ELINKNO_DOFF	0x1014		//lower 16bit DMA1_TCD0_DOFF
#define DMA1_TCD0_DLASTSGA			0x1018
#define DMA1_TCD0_BITER_ELINKYES__ELINKNO_CSR	0x101C		//lower 16bit DMA1_TCD0_CSR

#define DMA1_TCD1_SADDR				0x1020
#define DMA1_TCD1_ATTR_SOFF			0x1024		//lower 16bit DMA1_TCD0_SOFF
#define DMA1_TCD1_NBYTES_MLNO			0x1028
#define DMA1_TCD1_NBYTES_MLOFFNO		0x1028
#define DMA1_TCD1_NBYTES_MLOFFYES		0x1028
#define DMA1_TCD1_SLAST				0x102C
#define DMA1_TCD1_DADDR				0x1030
#define DMA1_TCD1_CITER_ELINKYES__ELINKNO_DOFF	0x1034		//lower 16bit DMA1_TCD0_DOFF
#define DMA1_TCD1_DLASTSGA			0x1038
#define DMA1_TCD1_BITER_ELINKYES__ELINKNO_CSR	0x103C		//lower 16bit DMA1_TCD0_CSR

#define DMAMUX_CHCFG_SOURCE_MASK                 0x3Fu
#define DMAMUX_CHCFG_SOURCE_SHIFT                0
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   0x40u
#define DMAMUX_CHCFG_TRIG_SHIFT                  6
#define DMAMUX_CHCFG_ENBL_MASK                   0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT                  7


/* CR Bit Fields */
#define DMA_CR_EDBG_MASK                         0x2u
#define DMA_CR_EDBG_SHIFT                        1
#define DMA_CR_ERCA_MASK                         0x4u
#define DMA_CR_ERCA_SHIFT                        2
#define DMA_CR_ERGA_MASK                         0x8u
#define DMA_CR_ERGA_SHIFT                        3
#define DMA_CR_HOE_MASK                          0x10u
#define DMA_CR_HOE_SHIFT                         4
#define DMA_CR_HALT_MASK                         0x20u
#define DMA_CR_HALT_SHIFT                        5
#define DMA_CR_CLM_MASK                          0x40u
#define DMA_CR_CLM_SHIFT                         6
#define DMA_CR_EMLM_MASK                         0x80u
#define DMA_CR_EMLM_SHIFT                        7
#define DMA_CR_GRP0PRI_MASK                      0x300u
#define DMA_CR_GRP0PRI_SHIFT                     8
#define DMA_CR_GRP0PRI(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CR_GRP0PRI_SHIFT))&DMA_CR_GRP0PRI_MASK)
#define DMA_CR_GRP1PRI_MASK                      0xC00u
#define DMA_CR_GRP1PRI_SHIFT                     10
#define DMA_CR_GRP1PRI(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CR_GRP1PRI_SHIFT))&DMA_CR_GRP1PRI_MASK)
#define DMA_CR_ECX_MASK                          0x10000u
#define DMA_CR_ECX_SHIFT                         16
#define DMA_CR_CX_MASK                           0x20000u
#define DMA_CR_CX_SHIFT                          17
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                          0x1u
#define DMA_ES_DBE_SHIFT                         0
#define DMA_ES_SBE_MASK                          0x2u
#define DMA_ES_SBE_SHIFT                         1
#define DMA_ES_SGE_MASK                          0x4u
#define DMA_ES_SGE_SHIFT                         2
#define DMA_ES_NCE_MASK                          0x8u
#define DMA_ES_NCE_SHIFT                         3
#define DMA_ES_DOE_MASK                          0x10u
#define DMA_ES_DOE_SHIFT                         4
#define DMA_ES_DAE_MASK                          0x20u
#define DMA_ES_DAE_SHIFT                         5
#define DMA_ES_SOE_MASK                          0x40u
#define DMA_ES_SOE_SHIFT                         6
#define DMA_ES_SAE_MASK                          0x80u
#define DMA_ES_SAE_SHIFT                         7
#define DMA_ES_ERRCHN_MASK                       0x1F00u
#define DMA_ES_ERRCHN_SHIFT                      8
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                          0x4000u
#define DMA_ES_CPE_SHIFT                         14
#define DMA_ES_GPE_MASK                          0x8000u
#define DMA_ES_GPE_SHIFT                         15
#define DMA_ES_ECX_MASK                          0x10000u
#define DMA_ES_ECX_SHIFT                         16
#define DMA_ES_VLD_MASK                          0x80000000u
#define DMA_ES_VLD_SHIFT                         31
/* ERQ Bit Fields */
#define DMA_ERQ_ERQ0_MASK                        0x1u
#define DMA_ERQ_ERQ0_SHIFT                       0
#define DMA_ERQ_ERQ1_MASK                        0x2u
#define DMA_ERQ_ERQ1_SHIFT                       1
#define DMA_ERQ_ERQ2_MASK                        0x4u
#define DMA_ERQ_ERQ2_SHIFT                       2
#define DMA_ERQ_ERQ3_MASK                        0x8u
#define DMA_ERQ_ERQ3_SHIFT                       3
#define DMA_ERQ_ERQ4_MASK                        0x10u
#define DMA_ERQ_ERQ4_SHIFT                       4
#define DMA_ERQ_ERQ5_MASK                        0x20u
#define DMA_ERQ_ERQ5_SHIFT                       5
#define DMA_ERQ_ERQ6_MASK                        0x40u
#define DMA_ERQ_ERQ6_SHIFT                       6
#define DMA_ERQ_ERQ7_MASK                        0x80u
#define DMA_ERQ_ERQ7_SHIFT                       7
#define DMA_ERQ_ERQ8_MASK                        0x100u
#define DMA_ERQ_ERQ8_SHIFT                       8
#define DMA_ERQ_ERQ9_MASK                        0x200u
#define DMA_ERQ_ERQ9_SHIFT                       9
#define DMA_ERQ_ERQ10_MASK                       0x400u
#define DMA_ERQ_ERQ10_SHIFT                      10
#define DMA_ERQ_ERQ11_MASK                       0x800u
#define DMA_ERQ_ERQ11_SHIFT                      11
#define DMA_ERQ_ERQ12_MASK                       0x1000u
#define DMA_ERQ_ERQ12_SHIFT                      12
#define DMA_ERQ_ERQ13_MASK                       0x2000u
#define DMA_ERQ_ERQ13_SHIFT                      13
#define DMA_ERQ_ERQ14_MASK                       0x4000u
#define DMA_ERQ_ERQ14_SHIFT                      14
#define DMA_ERQ_ERQ15_MASK                       0x8000u
#define DMA_ERQ_ERQ15_SHIFT                      15
#define DMA_ERQ_ERQ16_MASK                       0x10000u
#define DMA_ERQ_ERQ16_SHIFT                      16
#define DMA_ERQ_ERQ17_MASK                       0x20000u
#define DMA_ERQ_ERQ17_SHIFT                      17
#define DMA_ERQ_ERQ18_MASK                       0x40000u
#define DMA_ERQ_ERQ18_SHIFT                      18
#define DMA_ERQ_ERQ19_MASK                       0x80000u
#define DMA_ERQ_ERQ19_SHIFT                      19
#define DMA_ERQ_ERQ20_MASK                       0x100000u
#define DMA_ERQ_ERQ20_SHIFT                      20
#define DMA_ERQ_ERQ21_MASK                       0x200000u
#define DMA_ERQ_ERQ21_SHIFT                      21
#define DMA_ERQ_ERQ22_MASK                       0x400000u
#define DMA_ERQ_ERQ22_SHIFT                      22
#define DMA_ERQ_ERQ23_MASK                       0x800000u
#define DMA_ERQ_ERQ23_SHIFT                      23
#define DMA_ERQ_ERQ24_MASK                       0x1000000u
#define DMA_ERQ_ERQ24_SHIFT                      24
#define DMA_ERQ_ERQ25_MASK                       0x2000000u
#define DMA_ERQ_ERQ25_SHIFT                      25
#define DMA_ERQ_ERQ26_MASK                       0x4000000u
#define DMA_ERQ_ERQ26_SHIFT                      26
#define DMA_ERQ_ERQ27_MASK                       0x8000000u
#define DMA_ERQ_ERQ27_SHIFT                      27
#define DMA_ERQ_ERQ28_MASK                       0x10000000u
#define DMA_ERQ_ERQ28_SHIFT                      28
#define DMA_ERQ_ERQ29_MASK                       0x20000000u
#define DMA_ERQ_ERQ29_SHIFT                      29
#define DMA_ERQ_ERQ30_MASK                       0x40000000u
#define DMA_ERQ_ERQ30_SHIFT                      30
#define DMA_ERQ_ERQ31_MASK                       0x80000000u
#define DMA_ERQ_ERQ31_SHIFT                      31
/* EEI Bit Fields */
#define DMA_EEI_EEI0_MASK                        0x1u
#define DMA_EEI_EEI0_SHIFT                       0
#define DMA_EEI_EEI1_MASK                        0x2u
#define DMA_EEI_EEI1_SHIFT                       1
#define DMA_EEI_EEI2_MASK                        0x4u
#define DMA_EEI_EEI2_SHIFT                       2
#define DMA_EEI_EEI3_MASK                        0x8u
#define DMA_EEI_EEI3_SHIFT                       3
#define DMA_EEI_EEI4_MASK                        0x10u
#define DMA_EEI_EEI4_SHIFT                       4
#define DMA_EEI_EEI5_MASK                        0x20u
#define DMA_EEI_EEI5_SHIFT                       5
#define DMA_EEI_EEI6_MASK                        0x40u
#define DMA_EEI_EEI6_SHIFT                       6
#define DMA_EEI_EEI7_MASK                        0x80u
#define DMA_EEI_EEI7_SHIFT                       7
#define DMA_EEI_EEI8_MASK                        0x100u
#define DMA_EEI_EEI8_SHIFT                       8
#define DMA_EEI_EEI9_MASK                        0x200u
#define DMA_EEI_EEI9_SHIFT                       9
#define DMA_EEI_EEI10_MASK                       0x400u
#define DMA_EEI_EEI10_SHIFT                      10
#define DMA_EEI_EEI11_MASK                       0x800u
#define DMA_EEI_EEI11_SHIFT                      11
#define DMA_EEI_EEI12_MASK                       0x1000u
#define DMA_EEI_EEI12_SHIFT                      12
#define DMA_EEI_EEI13_MASK                       0x2000u
#define DMA_EEI_EEI13_SHIFT                      13
#define DMA_EEI_EEI14_MASK                       0x4000u
#define DMA_EEI_EEI14_SHIFT                      14
#define DMA_EEI_EEI15_MASK                       0x8000u
#define DMA_EEI_EEI15_SHIFT                      15
#define DMA_EEI_EEI16_MASK                       0x10000u
#define DMA_EEI_EEI16_SHIFT                      16
#define DMA_EEI_EEI17_MASK                       0x20000u
#define DMA_EEI_EEI17_SHIFT                      17
#define DMA_EEI_EEI18_MASK                       0x40000u
#define DMA_EEI_EEI18_SHIFT                      18
#define DMA_EEI_EEI19_MASK                       0x80000u
#define DMA_EEI_EEI19_SHIFT                      19
#define DMA_EEI_EEI20_MASK                       0x100000u
#define DMA_EEI_EEI20_SHIFT                      20
#define DMA_EEI_EEI21_MASK                       0x200000u
#define DMA_EEI_EEI21_SHIFT                      21
#define DMA_EEI_EEI22_MASK                       0x400000u
#define DMA_EEI_EEI22_SHIFT                      22
#define DMA_EEI_EEI23_MASK                       0x800000u
#define DMA_EEI_EEI23_SHIFT                      23
#define DMA_EEI_EEI24_MASK                       0x1000000u
#define DMA_EEI_EEI24_SHIFT                      24
#define DMA_EEI_EEI25_MASK                       0x2000000u
#define DMA_EEI_EEI25_SHIFT                      25
#define DMA_EEI_EEI26_MASK                       0x4000000u
#define DMA_EEI_EEI26_SHIFT                      26
#define DMA_EEI_EEI27_MASK                       0x8000000u
#define DMA_EEI_EEI27_SHIFT                      27
#define DMA_EEI_EEI28_MASK                       0x10000000u
#define DMA_EEI_EEI28_SHIFT                      28
#define DMA_EEI_EEI29_MASK                       0x20000000u
#define DMA_EEI_EEI29_SHIFT                      29
#define DMA_EEI_EEI30_MASK                       0x40000000u
#define DMA_EEI_EEI30_SHIFT                      30
#define DMA_EEI_EEI31_MASK                       0x80000000u
#define DMA_EEI_EEI31_SHIFT                      31
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                       0x1Fu
#define DMA_CEEI_CEEI_SHIFT                      0
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                       0x40u
#define DMA_CEEI_CAEE_SHIFT                      6
#define DMA_CEEI_NOP_MASK                        0x80u
#define DMA_CEEI_NOP_SHIFT                       7
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                       0x1Fu
#define DMA_SEEI_SEEI_SHIFT                      0
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                       0x40u
#define DMA_SEEI_SAEE_SHIFT                      6
#define DMA_SEEI_NOP_MASK                        0x80u
#define DMA_SEEI_NOP_SHIFT                       7
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                       0x1Fu
#define DMA_CERQ_CERQ_SHIFT                      0
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                       0x40u
#define DMA_CERQ_CAER_SHIFT                      6
#define DMA_CERQ_NOP_MASK                        0x80u
#define DMA_CERQ_NOP_SHIFT                       7
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                       0x1Fu
#define DMA_SERQ_SERQ_SHIFT                      0
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                       0x40u
#define DMA_SERQ_SAER_SHIFT                      6
#define DMA_SERQ_NOP_MASK                        0x80u
#define DMA_SERQ_NOP_SHIFT                       7
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                       0x1Fu
#define DMA_CDNE_CDNE_SHIFT                      0
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                       0x40u
#define DMA_CDNE_CADN_SHIFT                      6
#define DMA_CDNE_NOP_MASK                        0x80u
#define DMA_CDNE_NOP_SHIFT                       7
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                       0x1Fu
#define DMA_SSRT_SSRT_SHIFT                      0
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                       0x40u
#define DMA_SSRT_SAST_SHIFT                      6
#define DMA_SSRT_NOP_MASK                        0x80u
#define DMA_SSRT_NOP_SHIFT                       7
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                       0x1Fu
#define DMA_CERR_CERR_SHIFT                      0
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                       0x40u
#define DMA_CERR_CAEI_SHIFT                      6
#define DMA_CERR_NOP_MASK                        0x80u
#define DMA_CERR_NOP_SHIFT                       7
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                       0x1Fu
#define DMA_CINT_CINT_SHIFT                      0
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                       0x40u
#define DMA_CINT_CAIR_SHIFT                      6
#define DMA_CINT_NOP_MASK                        0x80u
#define DMA_CINT_NOP_SHIFT                       7
/* INT Bit Fields */
#define DMA_INT_INT0_MASK                        0x1u
#define DMA_INT_INT0_SHIFT                       0
#define DMA_INT_INT1_MASK                        0x2u
#define DMA_INT_INT1_SHIFT                       1
#define DMA_INT_INT2_MASK                        0x4u
#define DMA_INT_INT2_SHIFT                       2
#define DMA_INT_INT3_MASK                        0x8u
#define DMA_INT_INT3_SHIFT                       3
#define DMA_INT_INT4_MASK                        0x10u
#define DMA_INT_INT4_SHIFT                       4
#define DMA_INT_INT5_MASK                        0x20u
#define DMA_INT_INT5_SHIFT                       5
#define DMA_INT_INT6_MASK                        0x40u
#define DMA_INT_INT6_SHIFT                       6
#define DMA_INT_INT7_MASK                        0x80u
#define DMA_INT_INT7_SHIFT                       7
#define DMA_INT_INT8_MASK                        0x100u
#define DMA_INT_INT8_SHIFT                       8
#define DMA_INT_INT9_MASK                        0x200u
#define DMA_INT_INT9_SHIFT                       9
#define DMA_INT_INT10_MASK                       0x400u
#define DMA_INT_INT10_SHIFT                      10
#define DMA_INT_INT11_MASK                       0x800u
#define DMA_INT_INT11_SHIFT                      11
#define DMA_INT_INT12_MASK                       0x1000u
#define DMA_INT_INT12_SHIFT                      12
#define DMA_INT_INT13_MASK                       0x2000u
#define DMA_INT_INT13_SHIFT                      13
#define DMA_INT_INT14_MASK                       0x4000u
#define DMA_INT_INT14_SHIFT                      14
#define DMA_INT_INT15_MASK                       0x8000u
#define DMA_INT_INT15_SHIFT                      15
#define DMA_INT_INT16_MASK                       0x10000u
#define DMA_INT_INT16_SHIFT                      16
#define DMA_INT_INT17_MASK                       0x20000u
#define DMA_INT_INT17_SHIFT                      17
#define DMA_INT_INT18_MASK                       0x40000u
#define DMA_INT_INT18_SHIFT                      18
#define DMA_INT_INT19_MASK                       0x80000u
#define DMA_INT_INT19_SHIFT                      19
#define DMA_INT_INT20_MASK                       0x100000u
#define DMA_INT_INT20_SHIFT                      20
#define DMA_INT_INT21_MASK                       0x200000u
#define DMA_INT_INT21_SHIFT                      21
#define DMA_INT_INT22_MASK                       0x400000u
#define DMA_INT_INT22_SHIFT                      22
#define DMA_INT_INT23_MASK                       0x800000u
#define DMA_INT_INT23_SHIFT                      23
#define DMA_INT_INT24_MASK                       0x1000000u
#define DMA_INT_INT24_SHIFT                      24
#define DMA_INT_INT25_MASK                       0x2000000u
#define DMA_INT_INT25_SHIFT                      25
#define DMA_INT_INT26_MASK                       0x4000000u
#define DMA_INT_INT26_SHIFT                      26
#define DMA_INT_INT27_MASK                       0x8000000u
#define DMA_INT_INT27_SHIFT                      27
#define DMA_INT_INT28_MASK                       0x10000000u
#define DMA_INT_INT28_SHIFT                      28
#define DMA_INT_INT29_MASK                       0x20000000u
#define DMA_INT_INT29_SHIFT                      29
#define DMA_INT_INT30_MASK                       0x40000000u
#define DMA_INT_INT30_SHIFT                      30
#define DMA_INT_INT31_MASK                       0x80000000u
#define DMA_INT_INT31_SHIFT                      31
/* ERR Bit Fields */
#define DMA_ERR_ERR0_MASK                        0x1u
#define DMA_ERR_ERR0_SHIFT                       0
#define DMA_ERR_ERR1_MASK                        0x2u
#define DMA_ERR_ERR1_SHIFT                       1
#define DMA_ERR_ERR2_MASK                        0x4u
#define DMA_ERR_ERR2_SHIFT                       2
#define DMA_ERR_ERR3_MASK                        0x8u
#define DMA_ERR_ERR3_SHIFT                       3
#define DMA_ERR_ERR4_MASK                        0x10u
#define DMA_ERR_ERR4_SHIFT                       4
#define DMA_ERR_ERR5_MASK                        0x20u
#define DMA_ERR_ERR5_SHIFT                       5
#define DMA_ERR_ERR6_MASK                        0x40u
#define DMA_ERR_ERR6_SHIFT                       6
#define DMA_ERR_ERR7_MASK                        0x80u
#define DMA_ERR_ERR7_SHIFT                       7
#define DMA_ERR_ERR8_MASK                        0x100u
#define DMA_ERR_ERR8_SHIFT                       8
#define DMA_ERR_ERR9_MASK                        0x200u
#define DMA_ERR_ERR9_SHIFT                       9
#define DMA_ERR_ERR10_MASK                       0x400u
#define DMA_ERR_ERR10_SHIFT                      10
#define DMA_ERR_ERR11_MASK                       0x800u
#define DMA_ERR_ERR11_SHIFT                      11
#define DMA_ERR_ERR12_MASK                       0x1000u
#define DMA_ERR_ERR12_SHIFT                      12
#define DMA_ERR_ERR13_MASK                       0x2000u
#define DMA_ERR_ERR13_SHIFT                      13
#define DMA_ERR_ERR14_MASK                       0x4000u
#define DMA_ERR_ERR14_SHIFT                      14
#define DMA_ERR_ERR15_MASK                       0x8000u
#define DMA_ERR_ERR15_SHIFT                      15
#define DMA_ERR_ERR16_MASK                       0x10000u
#define DMA_ERR_ERR16_SHIFT                      16
#define DMA_ERR_ERR17_MASK                       0x20000u
#define DMA_ERR_ERR17_SHIFT                      17
#define DMA_ERR_ERR18_MASK                       0x40000u
#define DMA_ERR_ERR18_SHIFT                      18
#define DMA_ERR_ERR19_MASK                       0x80000u
#define DMA_ERR_ERR19_SHIFT                      19
#define DMA_ERR_ERR20_MASK                       0x100000u
#define DMA_ERR_ERR20_SHIFT                      20
#define DMA_ERR_ERR21_MASK                       0x200000u
#define DMA_ERR_ERR21_SHIFT                      21
#define DMA_ERR_ERR22_MASK                       0x400000u
#define DMA_ERR_ERR22_SHIFT                      22
#define DMA_ERR_ERR23_MASK                       0x800000u
#define DMA_ERR_ERR23_SHIFT                      23
#define DMA_ERR_ERR24_MASK                       0x1000000u
#define DMA_ERR_ERR24_SHIFT                      24
#define DMA_ERR_ERR25_MASK                       0x2000000u
#define DMA_ERR_ERR25_SHIFT                      25
#define DMA_ERR_ERR26_MASK                       0x4000000u
#define DMA_ERR_ERR26_SHIFT                      26
#define DMA_ERR_ERR27_MASK                       0x8000000u
#define DMA_ERR_ERR27_SHIFT                      27
#define DMA_ERR_ERR28_MASK                       0x10000000u
#define DMA_ERR_ERR28_SHIFT                      28
#define DMA_ERR_ERR29_MASK                       0x20000000u
#define DMA_ERR_ERR29_SHIFT                      29
#define DMA_ERR_ERR30_MASK                       0x40000000u
#define DMA_ERR_ERR30_SHIFT                      30
#define DMA_ERR_ERR31_MASK                       0x80000000u
#define DMA_ERR_ERR31_SHIFT                      31
/* HRS Bit Fields */
#define DMA_HRS_HRS0_MASK                        0x1u
#define DMA_HRS_HRS0_SHIFT                       0
#define DMA_HRS_HRS1_MASK                        0x2u
#define DMA_HRS_HRS1_SHIFT                       1
#define DMA_HRS_HRS2_MASK                        0x4u
#define DMA_HRS_HRS2_SHIFT                       2
#define DMA_HRS_HRS3_MASK                        0x8u
#define DMA_HRS_HRS3_SHIFT                       3
#define DMA_HRS_HRS4_MASK                        0x10u
#define DMA_HRS_HRS4_SHIFT                       4
#define DMA_HRS_HRS5_MASK                        0x20u
#define DMA_HRS_HRS5_SHIFT                       5
#define DMA_HRS_HRS6_MASK                        0x40u
#define DMA_HRS_HRS6_SHIFT                       6
#define DMA_HRS_HRS7_MASK                        0x80u
#define DMA_HRS_HRS7_SHIFT                       7
#define DMA_HRS_HRS8_MASK                        0x100u
#define DMA_HRS_HRS8_SHIFT                       8
#define DMA_HRS_HRS9_MASK                        0x200u
#define DMA_HRS_HRS9_SHIFT                       9
#define DMA_HRS_HRS10_MASK                       0x400u
#define DMA_HRS_HRS10_SHIFT                      10
#define DMA_HRS_HRS11_MASK                       0x800u
#define DMA_HRS_HRS11_SHIFT                      11
#define DMA_HRS_HRS12_MASK                       0x1000u
#define DMA_HRS_HRS12_SHIFT                      12
#define DMA_HRS_HRS13_MASK                       0x2000u
#define DMA_HRS_HRS13_SHIFT                      13
#define DMA_HRS_HRS14_MASK                       0x4000u
#define DMA_HRS_HRS14_SHIFT                      14
#define DMA_HRS_HRS15_MASK                       0x8000u
#define DMA_HRS_HRS15_SHIFT                      15
#define DMA_HRS_HRS16_MASK                       0x10000u
#define DMA_HRS_HRS16_SHIFT                      16
#define DMA_HRS_HRS17_MASK                       0x20000u
#define DMA_HRS_HRS17_SHIFT                      17
#define DMA_HRS_HRS18_MASK                       0x40000u
#define DMA_HRS_HRS18_SHIFT                      18
#define DMA_HRS_HRS19_MASK                       0x80000u
#define DMA_HRS_HRS19_SHIFT                      19
#define DMA_HRS_HRS20_MASK                       0x100000u
#define DMA_HRS_HRS20_SHIFT                      20
#define DMA_HRS_HRS21_MASK                       0x200000u
#define DMA_HRS_HRS21_SHIFT                      21
#define DMA_HRS_HRS22_MASK                       0x400000u
#define DMA_HRS_HRS22_SHIFT                      22
#define DMA_HRS_HRS23_MASK                       0x800000u
#define DMA_HRS_HRS23_SHIFT                      23
#define DMA_HRS_HRS24_MASK                       0x1000000u
#define DMA_HRS_HRS24_SHIFT                      24
#define DMA_HRS_HRS25_MASK                       0x2000000u
#define DMA_HRS_HRS25_SHIFT                      25
#define DMA_HRS_HRS26_MASK                       0x4000000u
#define DMA_HRS_HRS26_SHIFT                      26
#define DMA_HRS_HRS27_MASK                       0x8000000u
#define DMA_HRS_HRS27_SHIFT                      27
#define DMA_HRS_HRS28_MASK                       0x10000000u
#define DMA_HRS_HRS28_SHIFT                      28
#define DMA_HRS_HRS29_MASK                       0x20000000u
#define DMA_HRS_HRS29_SHIFT                      29
#define DMA_HRS_HRS30_MASK                       0x40000000u
#define DMA_HRS_HRS30_SHIFT                      30
#define DMA_HRS_HRS31_MASK                       0x80000000u
#define DMA_HRS_HRS31_SHIFT                      31
/* DCHPRI3 Bit Fields */
#define DMA_DCHPRI3_CHPRI_MASK                   0xFu
#define DMA_DCHPRI3_CHPRI_SHIFT                  0
#define DMA_DCHPRI3_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_CHPRI_SHIFT))&DMA_DCHPRI3_CHPRI_MASK)
#define DMA_DCHPRI3_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI3_GRPPRI_SHIFT                 4
#define DMA_DCHPRI3_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_GRPPRI_SHIFT))&DMA_DCHPRI3_GRPPRI_MASK)
#define DMA_DCHPRI3_DPA_MASK                     0x40u
#define DMA_DCHPRI3_DPA_SHIFT                    6
#define DMA_DCHPRI3_ECP_MASK                     0x80u
#define DMA_DCHPRI3_ECP_SHIFT                    7
/* DCHPRI2 Bit Fields */
#define DMA_DCHPRI2_CHPRI_MASK                   0xFu
#define DMA_DCHPRI2_CHPRI_SHIFT                  0
#define DMA_DCHPRI2_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_CHPRI_SHIFT))&DMA_DCHPRI2_CHPRI_MASK)
#define DMA_DCHPRI2_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI2_GRPPRI_SHIFT                 4
#define DMA_DCHPRI2_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_GRPPRI_SHIFT))&DMA_DCHPRI2_GRPPRI_MASK)
#define DMA_DCHPRI2_DPA_MASK                     0x40u
#define DMA_DCHPRI2_DPA_SHIFT                    6
#define DMA_DCHPRI2_ECP_MASK                     0x80u
#define DMA_DCHPRI2_ECP_SHIFT                    7
/* DCHPRI1 Bit Fields */
#define DMA_DCHPRI1_CHPRI_MASK                   0xFu
#define DMA_DCHPRI1_CHPRI_SHIFT                  0
#define DMA_DCHPRI1_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_CHPRI_SHIFT))&DMA_DCHPRI1_CHPRI_MASK)
#define DMA_DCHPRI1_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI1_GRPPRI_SHIFT                 4
#define DMA_DCHPRI1_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_GRPPRI_SHIFT))&DMA_DCHPRI1_GRPPRI_MASK)
#define DMA_DCHPRI1_DPA_MASK                     0x40u
#define DMA_DCHPRI1_DPA_SHIFT                    6
#define DMA_DCHPRI1_ECP_MASK                     0x80u
#define DMA_DCHPRI1_ECP_SHIFT                    7
/* DCHPRI0 Bit Fields */
#define DMA_DCHPRI0_CHPRI_MASK                   0xFu
#define DMA_DCHPRI0_CHPRI_SHIFT                  0
#define DMA_DCHPRI0_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_CHPRI_SHIFT))&DMA_DCHPRI0_CHPRI_MASK)
#define DMA_DCHPRI0_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI0_GRPPRI_SHIFT                 4
#define DMA_DCHPRI0_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_GRPPRI_SHIFT))&DMA_DCHPRI0_GRPPRI_MASK)
#define DMA_DCHPRI0_DPA_MASK                     0x40u
#define DMA_DCHPRI0_DPA_SHIFT                    6
#define DMA_DCHPRI0_ECP_MASK                     0x80u
#define DMA_DCHPRI0_ECP_SHIFT                    7
/* DCHPRI7 Bit Fields */
#define DMA_DCHPRI7_CHPRI_MASK                   0xFu
#define DMA_DCHPRI7_CHPRI_SHIFT                  0
#define DMA_DCHPRI7_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_CHPRI_SHIFT))&DMA_DCHPRI7_CHPRI_MASK)
#define DMA_DCHPRI7_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI7_GRPPRI_SHIFT                 4
#define DMA_DCHPRI7_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_GRPPRI_SHIFT))&DMA_DCHPRI7_GRPPRI_MASK)
#define DMA_DCHPRI7_DPA_MASK                     0x40u
#define DMA_DCHPRI7_DPA_SHIFT                    6
#define DMA_DCHPRI7_ECP_MASK                     0x80u
#define DMA_DCHPRI7_ECP_SHIFT                    7
/* DCHPRI6 Bit Fields */
#define DMA_DCHPRI6_CHPRI_MASK                   0xFu
#define DMA_DCHPRI6_CHPRI_SHIFT                  0
#define DMA_DCHPRI6_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_CHPRI_SHIFT))&DMA_DCHPRI6_CHPRI_MASK)
#define DMA_DCHPRI6_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI6_GRPPRI_SHIFT                 4
#define DMA_DCHPRI6_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_GRPPRI_SHIFT))&DMA_DCHPRI6_GRPPRI_MASK)
#define DMA_DCHPRI6_DPA_MASK                     0x40u
#define DMA_DCHPRI6_DPA_SHIFT                    6
#define DMA_DCHPRI6_ECP_MASK                     0x80u
#define DMA_DCHPRI6_ECP_SHIFT                    7
/* DCHPRI5 Bit Fields */
#define DMA_DCHPRI5_CHPRI_MASK                   0xFu
#define DMA_DCHPRI5_CHPRI_SHIFT                  0
#define DMA_DCHPRI5_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_CHPRI_SHIFT))&DMA_DCHPRI5_CHPRI_MASK)
#define DMA_DCHPRI5_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI5_GRPPRI_SHIFT                 4
#define DMA_DCHPRI5_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_GRPPRI_SHIFT))&DMA_DCHPRI5_GRPPRI_MASK)
#define DMA_DCHPRI5_DPA_MASK                     0x40u
#define DMA_DCHPRI5_DPA_SHIFT                    6
#define DMA_DCHPRI5_ECP_MASK                     0x80u
#define DMA_DCHPRI5_ECP_SHIFT                    7
/* DCHPRI4 Bit Fields */
#define DMA_DCHPRI4_CHPRI_MASK                   0xFu
#define DMA_DCHPRI4_CHPRI_SHIFT                  0
#define DMA_DCHPRI4_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_CHPRI_SHIFT))&DMA_DCHPRI4_CHPRI_MASK)
#define DMA_DCHPRI4_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI4_GRPPRI_SHIFT                 4
#define DMA_DCHPRI4_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_GRPPRI_SHIFT))&DMA_DCHPRI4_GRPPRI_MASK)
#define DMA_DCHPRI4_DPA_MASK                     0x40u
#define DMA_DCHPRI4_DPA_SHIFT                    6
#define DMA_DCHPRI4_ECP_MASK                     0x80u
#define DMA_DCHPRI4_ECP_SHIFT                    7
/* DCHPRI11 Bit Fields */
#define DMA_DCHPRI11_CHPRI_MASK                  0xFu
#define DMA_DCHPRI11_CHPRI_SHIFT                 0
#define DMA_DCHPRI11_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI11_CHPRI_SHIFT))&DMA_DCHPRI11_CHPRI_MASK)
#define DMA_DCHPRI11_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI11_GRPPRI_SHIFT                4
#define DMA_DCHPRI11_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI11_GRPPRI_SHIFT))&DMA_DCHPRI11_GRPPRI_MASK)
#define DMA_DCHPRI11_DPA_MASK                    0x40u
#define DMA_DCHPRI11_DPA_SHIFT                   6
#define DMA_DCHPRI11_ECP_MASK                    0x80u
#define DMA_DCHPRI11_ECP_SHIFT                   7
/* DCHPRI10 Bit Fields */
#define DMA_DCHPRI10_CHPRI_MASK                  0xFu
#define DMA_DCHPRI10_CHPRI_SHIFT                 0
#define DMA_DCHPRI10_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI10_CHPRI_SHIFT))&DMA_DCHPRI10_CHPRI_MASK)
#define DMA_DCHPRI10_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI10_GRPPRI_SHIFT                4
#define DMA_DCHPRI10_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI10_GRPPRI_SHIFT))&DMA_DCHPRI10_GRPPRI_MASK)
#define DMA_DCHPRI10_DPA_MASK                    0x40u
#define DMA_DCHPRI10_DPA_SHIFT                   6
#define DMA_DCHPRI10_ECP_MASK                    0x80u
#define DMA_DCHPRI10_ECP_SHIFT                   7
/* DCHPRI9 Bit Fields */
#define DMA_DCHPRI9_CHPRI_MASK                   0xFu
#define DMA_DCHPRI9_CHPRI_SHIFT                  0
#define DMA_DCHPRI9_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI9_CHPRI_SHIFT))&DMA_DCHPRI9_CHPRI_MASK)
#define DMA_DCHPRI9_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI9_GRPPRI_SHIFT                 4
#define DMA_DCHPRI9_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI9_GRPPRI_SHIFT))&DMA_DCHPRI9_GRPPRI_MASK)
#define DMA_DCHPRI9_DPA_MASK                     0x40u
#define DMA_DCHPRI9_DPA_SHIFT                    6
#define DMA_DCHPRI9_ECP_MASK                     0x80u
#define DMA_DCHPRI9_ECP_SHIFT                    7
/* DCHPRI8 Bit Fields */
#define DMA_DCHPRI8_CHPRI_MASK                   0xFu
#define DMA_DCHPRI8_CHPRI_SHIFT                  0
#define DMA_DCHPRI8_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI8_CHPRI_SHIFT))&DMA_DCHPRI8_CHPRI_MASK)
#define DMA_DCHPRI8_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI8_GRPPRI_SHIFT                 4
#define DMA_DCHPRI8_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI8_GRPPRI_SHIFT))&DMA_DCHPRI8_GRPPRI_MASK)
#define DMA_DCHPRI8_DPA_MASK                     0x40u
#define DMA_DCHPRI8_DPA_SHIFT                    6
#define DMA_DCHPRI8_ECP_MASK                     0x80u
#define DMA_DCHPRI8_ECP_SHIFT                    7
/* DCHPRI15 Bit Fields */
#define DMA_DCHPRI15_CHPRI_MASK                  0xFu
#define DMA_DCHPRI15_CHPRI_SHIFT                 0
#define DMA_DCHPRI15_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI15_CHPRI_SHIFT))&DMA_DCHPRI15_CHPRI_MASK)
#define DMA_DCHPRI15_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI15_GRPPRI_SHIFT                4
#define DMA_DCHPRI15_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI15_GRPPRI_SHIFT))&DMA_DCHPRI15_GRPPRI_MASK)
#define DMA_DCHPRI15_DPA_MASK                    0x40u
#define DMA_DCHPRI15_DPA_SHIFT                   6
#define DMA_DCHPRI15_ECP_MASK                    0x80u
#define DMA_DCHPRI15_ECP_SHIFT                   7
/* DCHPRI14 Bit Fields */
#define DMA_DCHPRI14_CHPRI_MASK                  0xFu
#define DMA_DCHPRI14_CHPRI_SHIFT                 0
#define DMA_DCHPRI14_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI14_CHPRI_SHIFT))&DMA_DCHPRI14_CHPRI_MASK)
#define DMA_DCHPRI14_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI14_GRPPRI_SHIFT                4
#define DMA_DCHPRI14_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI14_GRPPRI_SHIFT))&DMA_DCHPRI14_GRPPRI_MASK)
#define DMA_DCHPRI14_DPA_MASK                    0x40u
#define DMA_DCHPRI14_DPA_SHIFT                   6
#define DMA_DCHPRI14_ECP_MASK                    0x80u
#define DMA_DCHPRI14_ECP_SHIFT                   7
/* DCHPRI13 Bit Fields */
#define DMA_DCHPRI13_CHPRI_MASK                  0xFu
#define DMA_DCHPRI13_CHPRI_SHIFT                 0
#define DMA_DCHPRI13_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI13_CHPRI_SHIFT))&DMA_DCHPRI13_CHPRI_MASK)
#define DMA_DCHPRI13_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI13_GRPPRI_SHIFT                4
#define DMA_DCHPRI13_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI13_GRPPRI_SHIFT))&DMA_DCHPRI13_GRPPRI_MASK)
#define DMA_DCHPRI13_DPA_MASK                    0x40u
#define DMA_DCHPRI13_DPA_SHIFT                   6
#define DMA_DCHPRI13_ECP_MASK                    0x80u
#define DMA_DCHPRI13_ECP_SHIFT                   7
/* DCHPRI12 Bit Fields */
#define DMA_DCHPRI12_CHPRI_MASK                  0xFu
#define DMA_DCHPRI12_CHPRI_SHIFT                 0
#define DMA_DCHPRI12_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI12_CHPRI_SHIFT))&DMA_DCHPRI12_CHPRI_MASK)
#define DMA_DCHPRI12_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI12_GRPPRI_SHIFT                4
#define DMA_DCHPRI12_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI12_GRPPRI_SHIFT))&DMA_DCHPRI12_GRPPRI_MASK)
#define DMA_DCHPRI12_DPA_MASK                    0x40u
#define DMA_DCHPRI12_DPA_SHIFT                   6
#define DMA_DCHPRI12_ECP_MASK                    0x80u
#define DMA_DCHPRI12_ECP_SHIFT                   7
/* DCHPRI19 Bit Fields */
#define DMA_DCHPRI19_CHPRI_MASK                  0xFu
#define DMA_DCHPRI19_CHPRI_SHIFT                 0
#define DMA_DCHPRI19_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI19_CHPRI_SHIFT))&DMA_DCHPRI19_CHPRI_MASK)
#define DMA_DCHPRI19_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI19_GRPPRI_SHIFT                4
#define DMA_DCHPRI19_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI19_GRPPRI_SHIFT))&DMA_DCHPRI19_GRPPRI_MASK)
#define DMA_DCHPRI19_DPA_MASK                    0x40u
#define DMA_DCHPRI19_DPA_SHIFT                   6
#define DMA_DCHPRI19_ECP_MASK                    0x80u
#define DMA_DCHPRI19_ECP_SHIFT                   7
/* DCHPRI18 Bit Fields */
#define DMA_DCHPRI18_CHPRI_MASK                  0xFu
#define DMA_DCHPRI18_CHPRI_SHIFT                 0
#define DMA_DCHPRI18_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI18_CHPRI_SHIFT))&DMA_DCHPRI18_CHPRI_MASK)
#define DMA_DCHPRI18_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI18_GRPPRI_SHIFT                4
#define DMA_DCHPRI18_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI18_GRPPRI_SHIFT))&DMA_DCHPRI18_GRPPRI_MASK)
#define DMA_DCHPRI18_DPA_MASK                    0x40u
#define DMA_DCHPRI18_DPA_SHIFT                   6
#define DMA_DCHPRI18_ECP_MASK                    0x80u
#define DMA_DCHPRI18_ECP_SHIFT                   7
/* DCHPRI17 Bit Fields */
#define DMA_DCHPRI17_CHPRI_MASK                  0xFu
#define DMA_DCHPRI17_CHPRI_SHIFT                 0
#define DMA_DCHPRI17_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI17_CHPRI_SHIFT))&DMA_DCHPRI17_CHPRI_MASK)
#define DMA_DCHPRI17_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI17_GRPPRI_SHIFT                4
#define DMA_DCHPRI17_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI17_GRPPRI_SHIFT))&DMA_DCHPRI17_GRPPRI_MASK)
#define DMA_DCHPRI17_DPA_MASK                    0x40u
#define DMA_DCHPRI17_DPA_SHIFT                   6
#define DMA_DCHPRI17_ECP_MASK                    0x80u
#define DMA_DCHPRI17_ECP_SHIFT                   7
/* DCHPRI16 Bit Fields */
#define DMA_DCHPRI16_CHPRI_MASK                  0xFu
#define DMA_DCHPRI16_CHPRI_SHIFT                 0
#define DMA_DCHPRI16_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI16_CHPRI_SHIFT))&DMA_DCHPRI16_CHPRI_MASK)
#define DMA_DCHPRI16_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI16_GRPPRI_SHIFT                4
#define DMA_DCHPRI16_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI16_GRPPRI_SHIFT))&DMA_DCHPRI16_GRPPRI_MASK)
#define DMA_DCHPRI16_DPA_MASK                    0x40u
#define DMA_DCHPRI16_DPA_SHIFT                   6
#define DMA_DCHPRI16_ECP_MASK                    0x80u
#define DMA_DCHPRI16_ECP_SHIFT                   7
/* DCHPRI23 Bit Fields */
#define DMA_DCHPRI23_CHPRI_MASK                  0xFu
#define DMA_DCHPRI23_CHPRI_SHIFT                 0
#define DMA_DCHPRI23_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI23_CHPRI_SHIFT))&DMA_DCHPRI23_CHPRI_MASK)
#define DMA_DCHPRI23_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI23_GRPPRI_SHIFT                4
#define DMA_DCHPRI23_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI23_GRPPRI_SHIFT))&DMA_DCHPRI23_GRPPRI_MASK)
#define DMA_DCHPRI23_DPA_MASK                    0x40u
#define DMA_DCHPRI23_DPA_SHIFT                   6
#define DMA_DCHPRI23_ECP_MASK                    0x80u
#define DMA_DCHPRI23_ECP_SHIFT                   7
/* DCHPRI22 Bit Fields */
#define DMA_DCHPRI22_CHPRI_MASK                  0xFu
#define DMA_DCHPRI22_CHPRI_SHIFT                 0
#define DMA_DCHPRI22_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI22_CHPRI_SHIFT))&DMA_DCHPRI22_CHPRI_MASK)
#define DMA_DCHPRI22_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI22_GRPPRI_SHIFT                4
#define DMA_DCHPRI22_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI22_GRPPRI_SHIFT))&DMA_DCHPRI22_GRPPRI_MASK)
#define DMA_DCHPRI22_DPA_MASK                    0x40u
#define DMA_DCHPRI22_DPA_SHIFT                   6
#define DMA_DCHPRI22_ECP_MASK                    0x80u
#define DMA_DCHPRI22_ECP_SHIFT                   7
/* DCHPRI21 Bit Fields */
#define DMA_DCHPRI21_CHPRI_MASK                  0xFu
#define DMA_DCHPRI21_CHPRI_SHIFT                 0
#define DMA_DCHPRI21_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI21_CHPRI_SHIFT))&DMA_DCHPRI21_CHPRI_MASK)
#define DMA_DCHPRI21_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI21_GRPPRI_SHIFT                4
#define DMA_DCHPRI21_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI21_GRPPRI_SHIFT))&DMA_DCHPRI21_GRPPRI_MASK)
#define DMA_DCHPRI21_DPA_MASK                    0x40u
#define DMA_DCHPRI21_DPA_SHIFT                   6
#define DMA_DCHPRI21_ECP_MASK                    0x80u
#define DMA_DCHPRI21_ECP_SHIFT                   7
/* DCHPRI20 Bit Fields */
#define DMA_DCHPRI20_CHPRI_MASK                  0xFu
#define DMA_DCHPRI20_CHPRI_SHIFT                 0
#define DMA_DCHPRI20_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI20_CHPRI_SHIFT))&DMA_DCHPRI20_CHPRI_MASK)
#define DMA_DCHPRI20_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI20_GRPPRI_SHIFT                4
#define DMA_DCHPRI20_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI20_GRPPRI_SHIFT))&DMA_DCHPRI20_GRPPRI_MASK)
#define DMA_DCHPRI20_DPA_MASK                    0x40u
#define DMA_DCHPRI20_DPA_SHIFT                   6
#define DMA_DCHPRI20_ECP_MASK                    0x80u
#define DMA_DCHPRI20_ECP_SHIFT                   7
/* DCHPRI27 Bit Fields */
#define DMA_DCHPRI27_CHPRI_MASK                  0xFu
#define DMA_DCHPRI27_CHPRI_SHIFT                 0
#define DMA_DCHPRI27_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI27_CHPRI_SHIFT))&DMA_DCHPRI27_CHPRI_MASK)
#define DMA_DCHPRI27_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI27_GRPPRI_SHIFT                4
#define DMA_DCHPRI27_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI27_GRPPRI_SHIFT))&DMA_DCHPRI27_GRPPRI_MASK)
#define DMA_DCHPRI27_DPA_MASK                    0x40u
#define DMA_DCHPRI27_DPA_SHIFT                   6
#define DMA_DCHPRI27_ECP_MASK                    0x80u
#define DMA_DCHPRI27_ECP_SHIFT                   7
/* DCHPRI26 Bit Fields */
#define DMA_DCHPRI26_CHPRI_MASK                  0xFu
#define DMA_DCHPRI26_CHPRI_SHIFT                 0
#define DMA_DCHPRI26_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI26_CHPRI_SHIFT))&DMA_DCHPRI26_CHPRI_MASK)
#define DMA_DCHPRI26_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI26_GRPPRI_SHIFT                4
#define DMA_DCHPRI26_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI26_GRPPRI_SHIFT))&DMA_DCHPRI26_GRPPRI_MASK)
#define DMA_DCHPRI26_DPA_MASK                    0x40u
#define DMA_DCHPRI26_DPA_SHIFT                   6
#define DMA_DCHPRI26_ECP_MASK                    0x80u
#define DMA_DCHPRI26_ECP_SHIFT                   7
/* DCHPRI25 Bit Fields */
#define DMA_DCHPRI25_CHPRI_MASK                  0xFu
#define DMA_DCHPRI25_CHPRI_SHIFT                 0
#define DMA_DCHPRI25_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI25_CHPRI_SHIFT))&DMA_DCHPRI25_CHPRI_MASK)
#define DMA_DCHPRI25_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI25_GRPPRI_SHIFT                4
#define DMA_DCHPRI25_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI25_GRPPRI_SHIFT))&DMA_DCHPRI25_GRPPRI_MASK)
#define DMA_DCHPRI25_DPA_MASK                    0x40u
#define DMA_DCHPRI25_DPA_SHIFT                   6
#define DMA_DCHPRI25_ECP_MASK                    0x80u
#define DMA_DCHPRI25_ECP_SHIFT                   7
/* DCHPRI24 Bit Fields */
#define DMA_DCHPRI24_CHPRI_MASK                  0xFu
#define DMA_DCHPRI24_CHPRI_SHIFT                 0
#define DMA_DCHPRI24_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI24_CHPRI_SHIFT))&DMA_DCHPRI24_CHPRI_MASK)
#define DMA_DCHPRI24_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI24_GRPPRI_SHIFT                4
#define DMA_DCHPRI24_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI24_GRPPRI_SHIFT))&DMA_DCHPRI24_GRPPRI_MASK)
#define DMA_DCHPRI24_DPA_MASK                    0x40u
#define DMA_DCHPRI24_DPA_SHIFT                   6
#define DMA_DCHPRI24_ECP_MASK                    0x80u
#define DMA_DCHPRI24_ECP_SHIFT                   7
/* DCHPRI31 Bit Fields */
#define DMA_DCHPRI31_CHPRI_MASK                  0xFu
#define DMA_DCHPRI31_CHPRI_SHIFT                 0
#define DMA_DCHPRI31_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI31_CHPRI_SHIFT))&DMA_DCHPRI31_CHPRI_MASK)
#define DMA_DCHPRI31_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI31_GRPPRI_SHIFT                4
#define DMA_DCHPRI31_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI31_GRPPRI_SHIFT))&DMA_DCHPRI31_GRPPRI_MASK)
#define DMA_DCHPRI31_DPA_MASK                    0x40u
#define DMA_DCHPRI31_DPA_SHIFT                   6
#define DMA_DCHPRI31_ECP_MASK                    0x80u
#define DMA_DCHPRI31_ECP_SHIFT                   7
/* DCHPRI30 Bit Fields */
#define DMA_DCHPRI30_CHPRI_MASK                  0xFu
#define DMA_DCHPRI30_CHPRI_SHIFT                 0
#define DMA_DCHPRI30_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI30_CHPRI_SHIFT))&DMA_DCHPRI30_CHPRI_MASK)
#define DMA_DCHPRI30_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI30_GRPPRI_SHIFT                4
#define DMA_DCHPRI30_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI30_GRPPRI_SHIFT))&DMA_DCHPRI30_GRPPRI_MASK)
#define DMA_DCHPRI30_DPA_MASK                    0x40u
#define DMA_DCHPRI30_DPA_SHIFT                   6
#define DMA_DCHPRI30_ECP_MASK                    0x80u
#define DMA_DCHPRI30_ECP_SHIFT                   7
/* DCHPRI29 Bit Fields */
#define DMA_DCHPRI29_CHPRI_MASK                  0xFu
#define DMA_DCHPRI29_CHPRI_SHIFT                 0
#define DMA_DCHPRI29_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI29_CHPRI_SHIFT))&DMA_DCHPRI29_CHPRI_MASK)
#define DMA_DCHPRI29_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI29_GRPPRI_SHIFT                4
#define DMA_DCHPRI29_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI29_GRPPRI_SHIFT))&DMA_DCHPRI29_GRPPRI_MASK)
#define DMA_DCHPRI29_DPA_MASK                    0x40u
#define DMA_DCHPRI29_DPA_SHIFT                   6
#define DMA_DCHPRI29_ECP_MASK                    0x80u
#define DMA_DCHPRI29_ECP_SHIFT                   7
/* DCHPRI28 Bit Fields */
#define DMA_DCHPRI28_CHPRI_MASK                  0xFu
#define DMA_DCHPRI28_CHPRI_SHIFT                 0
#define DMA_DCHPRI28_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI28_CHPRI_SHIFT))&DMA_DCHPRI28_CHPRI_MASK)
#define DMA_DCHPRI28_GRPPRI_MASK                 0x30u
#define DMA_DCHPRI28_GRPPRI_SHIFT                4
#define DMA_DCHPRI28_GRPPRI(x)                   (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI28_GRPPRI_SHIFT))&DMA_DCHPRI28_GRPPRI_MASK)
#define DMA_DCHPRI28_DPA_MASK                    0x40u
#define DMA_DCHPRI28_DPA_SHIFT                   6
#define DMA_DCHPRI28_ECP_MASK                    0x80u
#define DMA_DCHPRI28_ECP_SHIFT                   7
/* SADDR Bit Fields */
#define DMA_SADDR_SADDR_MASK                     0xFFFFFFFFu
#define DMA_SADDR_SADDR_SHIFT                    0
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK)
/* SOFF Bit Fields */
#define DMA_SOFF_SOFF_MASK                       0xFFFFu
#define DMA_SOFF_SOFF_SHIFT                      0
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK)
/* ATTR Bit Fields */
#define DMA_ATTR_DSIZE_MASK                      0x7u
#define DMA_ATTR_DSIZE_SHIFT                     0
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK)
#define DMA_ATTR_DMOD_MASK                       0xF8u
#define DMA_ATTR_DMOD_SHIFT                      3
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK)
#define DMA_ATTR_SSIZE_MASK                      0x700u
#define DMA_ATTR_SSIZE_SHIFT                     8
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK)
#define DMA_ATTR_SMOD_MASK                       0xF800u
#define DMA_ATTR_SMOD_SHIFT                      11
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK)
/* NBYTES_MLNO Bit Fields */
#define DMA_NBYTES_MLNO_NBYTES_MASK              0xFFFFFFFFu
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             0
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK)
/* NBYTES_MLOFFNO Bit Fields */
#define DMA_NBYTES_MLOFFNO_NBYTES_OE_MASK        0x3FFFFFFFu
#define DMA_NBYTES_MLOFFNO_NBYTES_OE_SHIFT       0
#define DMA_NBYTES_MLOFFNO_NBYTES_OE(x)          (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_OE_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_OE_MASK)
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            0x40000000u
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           30
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            0x80000000u
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           31
/* NBYTES_MLOFFYES Bit Fields */
#define DMA_NBYTES_MLOFFYES_NBYTES_OD_MASK       0x3FFu
#define DMA_NBYTES_MLOFFYES_NBYTES_OD_SHIFT      0
#define DMA_NBYTES_MLOFFYES_NBYTES_OD(x)         (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_OD_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_OD_MASK)
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           0x3FFFFC00u
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          10
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           0x40000000u
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          30
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           0x80000000u
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          31
/* SLAST Bit Fields */
#define DMA_SLAST_SLAST_MASK                     0xFFFFFFFFu
#define DMA_SLAST_SLAST_SHIFT                    0
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK)
/* DADDR Bit Fields */
#define DMA_DADDR_DADDR_MASK                     0xFFFFFFFFu
#define DMA_DADDR_DADDR_SHIFT                    0
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK)
/* DOFF Bit Fields */
#define DMA_DOFF_DOFF_MASK                       0xFFFFu
#define DMA_DOFF_DOFF_SHIFT                      0
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK)
/* CITER_ELINKNO Bit Fields */
#define DMA_CITER_ELINKNO_CITER_MASK             0x7FFFu
#define DMA_CITER_ELINKNO_CITER_SHIFT            0
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK)
#define DMA_CITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_CITER_ELINKNO_ELINK_SHIFT            15
/* CITER_ELINKYES Bit Fields */
#define DMA_CITER_ELINKYES_CITER_LE_MASK         0x1FFu
#define DMA_CITER_ELINKYES_CITER_LE_SHIFT        0
#define DMA_CITER_ELINKYES_CITER_LE(x)           (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_LE_SHIFT))&DMA_CITER_ELINKYES_CITER_LE_MASK)
#define DMA_CITER_ELINKYES_LINKCH_MASK           0x3E00u
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK)
#define DMA_CITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_CITER_ELINKYES_ELINK_SHIFT           15
/* DLAST_SGA Bit Fields */
#define DMA_DLAST_SGA_DLASTSGA_MASK              0xFFFFFFFFu
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             0
#define DMA_DLAST_SGA_DLASTSGA(x)                (((uint32_t)(((uint32_t)(x))<<DMA_DLAST_SGA_DLASTSGA_SHIFT))&DMA_DLAST_SGA_DLASTSGA_MASK)
/* CSR Bit Fields */
#define DMA_CSR_START_MASK                       0x1u
#define DMA_CSR_START_SHIFT                      0
#define DMA_CSR_INTMAJOR_MASK                    0x2u
#define DMA_CSR_INTMAJOR_SHIFT                   1
#define DMA_CSR_INTHALF_MASK                     0x4u
#define DMA_CSR_INTHALF_SHIFT                    2
#define DMA_CSR_DREQ_MASK                        0x8u
#define DMA_CSR_DREQ_SHIFT                       3
#define DMA_CSR_ESG_MASK                         0x10u
#define DMA_CSR_ESG_SHIFT                        4
#define DMA_CSR_MAJORELINK_MASK                  0x20u
#define DMA_CSR_MAJORELINK_SHIFT                 5
#define DMA_CSR_ACTIVE_MASK                      0x40u
#define DMA_CSR_ACTIVE_SHIFT                     6
#define DMA_CSR_DONE_MASK                        0x80u
#define DMA_CSR_DONE_SHIFT                       7
#define DMA_CSR_MAJORLINKCH_MASK                 0x1F00u
#define DMA_CSR_MAJORLINKCH_SHIFT                8
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK)
#define DMA_CSR_BWC_MASK                         0xC000u
#define DMA_CSR_BWC_SHIFT                        14
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK)
/* BITER_ELINKNO Bit Fields */
#define DMA_BITER_ELINKNO_BITER_MASK             0x7FFFu
#define DMA_BITER_ELINKNO_BITER_SHIFT            0
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK)
#define DMA_BITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_BITER_ELINKNO_ELINK_SHIFT            15
/* BITER_ELINKYES Bit Fields */
#define DMA_BITER_ELINKYES_BITER_LE_MASK         0x1FFu
#define DMA_BITER_ELINKYES_BITER_LE_SHIFT        0
#define DMA_BITER_ELINKYES_BITER_LE(x)           (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_LE_SHIFT))&DMA_BITER_ELINKYES_BITER_LE_MASK)
#define DMA_BITER_ELINKYES_LINKCH_MASK           0x3E00u
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK)
#define DMA_BITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_BITER_ELINKYES_ELINK_SHIFT           15

#endif /* VF500_SOUND_H_ */
