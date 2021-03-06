/**
  ******************************************************************************
  * @file    rh850f1l_clk.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Clock Control module.
  ******************************************************************************
  */
#ifndef RH850F1L_CLK_H
#define RH850F1L_CLK_H

#include "rh850f1l.h"

#define CPUCLK2 40000000//40MHz max

/*Clock Oscillator registers mask or value*/
#define ROSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define ROSCCLK_FREQUENCY   (8*1024*1024) //Hi IntOSC frequency8MHz

#define MOSCENTRG_MASK      ((uint32_t)(0x01))
#define MOSCDISTRG_MASK     ((uint32_t)(0x01 << 1))
#define MOSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define MOSCAMPSEL_MASK     ((uint32_t)(0x03))
#define MOSCCLKST_MASK      ((uint32_t)0x1FFFF)
#define MOSC_STABLE_TIME   (2*ROSCCLK_FREQUENCY/100) //when HI OSC actived,about 2ms

#define SOSCENTRG_MASK      ((uint32_t)(0x01))
#define SOSCDISTRG_MASK     ((uint32_t)(0x01 << 1))
#define SOSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define SOSCCLKST_MASK      ((uint32_t)0x3FFFFFFF)
#define SOSC_STABLE_TIME    (2*ROSCCLK_FREQUENCY)

#define PLLENTRG_MASK       ((uint32_t)0x01 << 0)
#define PLLDISTRG_MASK      ((uint32_t)0x01 << 1)
#define PLLCLKACT_MASK      ((uint32_t)0x01 << 2)

#define PLLC_OUTBSEL_OFFSET 16
#define PLLC_OUTBSEL_MASK   ((uint32_t)0x01 << PLLC_OUTBSEL_OFFSET) //bit 16
#define PLLC_M_BITOFFSET    11
#define PLLC_M_MASK         ((uint32_t)0x03 << PLLC_M_BITOFFSET) //bit 12,11
#define PLLC_PA_BITOFFSET   8
#define PLLC_PA_MASK        ((uint32_t)0x07 << PLLC_PA_BITOFFSET)  //bit 10,9,8
#define PLLC_N_BITOFFSET    0
#define PLLC_N_MASK         ((uint32_t)0x3F << PLLC_N_BITOFFSET)  //bit 5,4,3,2,1,0
#define PLLC_MASK           (PLLC_OUTBSEL_MASK | PLLC_M_MASK| PLLC_PA_MASK | PLLC_N_MASK)
/*MainOSC 16MHz outsel =0 ,Mr = 2 -- > M Bit[12:11] = 01,pa = 4,Nr = 40 --> N Bit[5:0] = 10 0111*/
#define PLLC_OUTBSEL        0
#define PLLC_MR             2 //16 MHz ≤ fX ≤ 24 MHz
#define PLLC_PAR            4 //60 MHz to 80 MHz
#define PLLC_NR             40

/*Clock Selector registers mask or value*/
#define CPUCLK_SRC_EMCLK    ((uint32_t)0x01) //01B: EMCLK (default)
#define CPUCLK_SRC_MOSC     ((uint32_t)0x02) //10B: MainOSC
#define CPUCLK_SRC_CPLLCLK  ((uint32_t)0x03) //11B: CPLLCLK

#define CPUCLK_CTL_DIVI_1   ((uint32_t)0x01) //001B: CKSC_CPUCLKS_CTL selection /1 (Default)
#define CPUCLK_CTL_DIVI_2   ((uint32_t)0x02) //010B: CKSC_CPUCLKS_CTL selection /2
#define CPUCLK_CTL_DIVI_4   ((uint32_t)0x03) //011B: CKSC_CPUCLKS_CTL selection /4
#define CPUCLK_CTL_DIVI_8   ((uint32_t)0x04) //100B: CKSC_CPUCLKS_CTL selection /8

#define IPERI1_SRC_CPUCLK2  ((uint32_t)0x01) //01B: CPUCLK2 (default)
#define IPERI1_SRC_PPLLCLK  ((uint32_t)0x02) //10B: PPLLCLK

#define IPERI2_SRC_CPUCLK2  ((uint32_t)0x01) //01B: CPUCLK2 (default)
#define IPERI2_SRC_PPLLCLK2 ((uint32_t)0x02) //10B: PPLLCLK2

#define CPUCLKS_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define CPUCLKS_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask
#define CPUCLKD_CTL_MASK    ((uint32_t)0x07) //CKSC_CPUCLKD_CTL Bit Mask
#define CPUCLKD_ACT_MASK    ((uint32_t)0x07) //CKSC_CPUCLKD_ACT Bit Mask
#define IPERI1S_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define IPERI1S_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask
#define IPERI2S_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define IPERI2S_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask

/* ILIN_CTL_DIVI_4 and ILIN_CTL_DIVI_8 are only available in UART mode.*/
#define ILINS_CTL_MASK      ((uint32_t)0x03) //CKSC_ILINS_CTL Bit Mask
#define ILINS_ACT_MASK      ((uint32_t)0x03) //CKSC_ILINS_ACT Bit Mask
#define ILIN_CTL_DIVI_1     ((uint32_t)0x01) //01B: CKSC_ILINS_CTL selection /1 (Default)
#define ILIN_CTL_DIVI_4     ((uint32_t)0x02) //10B: CKSC_ILINS_CTL selection /4
#define ILIN_CTL_DIVI_8     ((uint32_t)0x03) //11B: CKSC_ILINS_CTL selection /8

#define ICANS_CTL_MASK      ((uint32_t)0x03) //CKSC_ICANS_CTL Bit Mask
#define ICANS_ACT_MASK      ((uint32_t)0x03) //CKSC_ICANS_ACT Bit Mask
#define ICANOSCD_CTL_MASK   ((uint32_t)0x03) //CKSC_ICANOSCD_CTL Bit Mask
#define ICANOSCD_ACT_MASK   ((uint32_t)0x03) //CKSC_ICANOSCD_ACT  Bit Mask

#define ICSIS_CTL_MASK       ((uint32_t)0x03) //CKSC_ICSIS_CTL bit mask
#define ICSIS_ACT_MASK       ((uint32_t)0x03) //CKSC_ICSIS_ACT bit mask

#define FOUT_DIV_MASK       ((uint32_t)0x3F) //FOUTDIV Mask
#define FOUTSYNC_MASK       ((uint32_t)0x01) //FOUTSTAT FOUTSYNC Mask
#define FOUTCLKACT_MASK     ((uint32_t)0x01 << 1) //FOUTSTAT FOUTCLKACT Mask

#define AFOUTS_CTL_MASK     ((uint32_t)0x07) //C_AWO_FOUT Source Clock Selection Register Mask
#define AFOUTS_ACT_MASK     ((uint32_t)0x07) //C_AWO_FOUT Source Clock Active Register Mas

#define AWDTAD_CTL_MASK     ((uint32_t)0x03)
#define AWDTAD_ACT_MASK     ((uint32_t)0x03)

#define ARTCAS_CTL_MASK     ((uint32_t)0x03)
#define ARTCAS_ACT_MASK     ((uint32_t)0x03)
#define ARTCAD_CTL_MASK     ((uint32_t)0x07)
#define ARTCAD_ACT_MASK     ((uint32_t)0x07)

#define ARTCA_DIVI_DISABLE  ((uint32_t)0x00)//(Default)
#define ARTCA_CTL_DIVI_1    ((uint32_t)0x01) //001B: CKSC_ARTCAS_CTL selection /1
#define ARTCA_CTL_DIVI_2    ((uint32_t)0x02) //010B: CKSC_ARTCAS_CTL selection /2
#define ARTCA_CTL_DIVI_4    ((uint32_t)0x03) //011B: CKSC_ARTCAS_CTL selection /4
#define ARTCA_CTL_DIVI_8    ((uint32_t)0x04) //100B: CKSC_ARTCAS_CTL selection /8

#define AADCAS_CTL_MASK     ((uint32_t)0x03)
#define AADCAS_ACT_MASK     ((uint32_t)0x03)
#define AADCAD_CTL_MASK     ((uint32_t)0x03)
#define AADCAD_ACT_MASK     ((uint32_t)0x03)

#define AADCA_CTL_DIVI_1    ((uint32_t)0x01) //01B: CKSC_AADCAS_CTL selection /1 (default)
#define AADCA_CTL_DIVI_2    ((uint32_t)0x02) //10B: CKSC_AADCAS_CTL selection /2


typedef enum {
    OSC_DISABLE,
    OSC_ENABLE = !OSC_DISABLE,
}OSC_OPT_Type;

typedef enum {
    OSC_INACTIVE,
    OSC_ACTIVED = !OSC_INACTIVE,
}OSC_STATUS_Type;

typedef enum {
    MOSC_AMP_HIGH,      //00b,20 MHz < fX ≤ 24 MHz
    MOSC_AMP_MID_HIGH,  //01b,16 MHz < fX ≤ 20 MHz
    MOSC_AMP_MID_LOW,   //10b,8 MHz < fX ≤ 16 MHz
    MOSC_AMP_LOW,       //11b,8 MHz
}MOSC_AMP_GAIN_Type;

typedef enum {
    M_OSC_TYPE,//Main OSC
    S_OSC_TYPE,//Sub OSC
    R_OSC_TYPE,//HI Int OSC
    PLL_TYPE,//PLL
}X_OSC_Type;

typedef enum { //Domain Clock
    AWDTA,ATAUJ,ARTCA,AADCA,AFOUT,//AWO_Domain
    CPUCLK,IPERI1,IPERI2,ILIN,IADCA,ICAN,ICANOSC,ICSI,//ISO Domain
    DOMAIN_CLK_TYPE_MAX,
}DOMAIN_CLK_Type;

typedef enum { //return after Setting CLock Domain
    SET_SRC_CLK_FAIL,
    SET_CLK_DIVIDER_FAIL = SET_SRC_CLK_FAIL,
    SET_CLK_DOMAIN_SUCCESS,
    SET_OTHER_FAIL,
}SET_CLK_DOMAIN_RET_Type;

typedef struct {
    uint32_t src_clk_ctl_val;
    uint32_t clk_divider_val;
}SET_CLK_DOMAIN_Struct;

typedef enum {
    AFOUT_SRC_DISABLED,//Disabled (default)
    AFOUT_SRC_MOSC, //001B: MainOSC
    AFOUT_SRC_RH,   //010B: HS IntOSC
    AFOUT_SRC_LH,   //011B: LS IntOSC
    AFOUT_SRC_SOSC, //100B: SubOSC*2
    AFOUT_SRC_CPLLCLK2, //101B: CPLLCLK2
    AFOUT_SRC_PPLLCLK4, //110B: PPLLCLK4
}AFOUT_SRC_CLK_Type;

typedef enum{
    AWDTA_LSOSC_128 = 1,//LS IntOSC / 128 (default)
    AWDTA_LSOSC_1,// LS IntOSC / 1
}AWDTA_DIV_SEL_Type;

typedef enum{
    ARTCA_DISABLED,//00B: Disable (default)
    ARTCA_SUBOSC,  //01B: SubOSC*1
    ARTCA_MAINOSC, //10B: MainOSC*2
    ARTCA_LSINTOSC,//11B: LS IntOSC
}ARTCA_SRC_SEL_Type;

typedef enum{
    AADCA_DISABLED, //00B: Disabled
    AADCA_HSIntOSC, //01B: HS IntOSC (default)
    AADCA_MAINOSC,  //10B: MainOSC
    AADCA_PPLLCLK2, //11B: PPLLCLK2
}AADCA_SRC_SEL_Type;

typedef enum{
    ILIN_SRC_DISABLED,//00B:Disabled
    ILIN_SRC_CPUCLK2, //01B: CPUCLK2 (default)
    ILIN_SRC_MAINOSC, //10B: MainOSC
    ILIN_SRC_PPLLCLK2,//11B:PPLLCLK2
}ILIN_SRC_CLK_Type;

typedef enum{
    ICAN_SRC_DISABLED, //00B:Disabled
    ICAN_SRC_MAINOSC, //01B: MainOSC
    ICAN_SRC_CPLLCLK, //10B: CPLLCLK
    ICAN_SRC_CPUCLK,  //11B: CPUCLK (default)
}ICAN_SRC_CLK_Type;

typedef enum{
    ICANOSC_DIV_DISABLED, //00B:Disabled (default)
    ICANOSC_DIV_MAINOSC_1, //01B: MainOSC /1
    ICANOSC_DIV_MAINOSC_2, //10B: MainOSC /2
}ICANOSC_DIV_CLK_Type;

typedef enum{
    ICSI_SRC_DISABLED, //00B: Disabled
    ICSI_SRC_CPUCLK,   //01B: CPUCLK (default)
    ICSI_SRC_PPLLCLK,  //10B: PPLLCLK
}ICSI_SRC_CLK_Type;

void Clock_MOSC_Config(OSC_OPT_Type opt);
void Clock_SOSC_Config(OSC_OPT_Type opt);
OSC_STATUS_Type Clock_OSC_Get_Status(X_OSC_Type otp);
void Clock_PLL_Config(OSC_OPT_Type opt);

#endif //RH850F1L_CLK_H
