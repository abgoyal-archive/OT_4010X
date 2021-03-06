
#include "mt6575_emi.h"

#define NUM_EMI_RECORD (1)

int num_of_emi_records = NUM_EMI_RECORD ;

EMI_SETTINGS emi_settings[] =
{
     
	//H9DA4GH4JJAMCR_4EM
	{
		0x0101,		/* TYPE */
		{0xAD,0xBC,0x90,0x55,0x54,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		0x0002202E,		/* EMI_CONA_VAL */
		0x88008800,		/* DRAMC_DRVCTL0_VAL */
		0x88008800,		/* DRAMC_DRVCTL1_VAL */
		0x00000005,		/* DRAMC_DLE_VAL */
		0x22824154,		/* DRAMC_ACTIM_VAL */
		0x00000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0040560,		/* DRAMC_CONF1_VAL */
		0x8283405C,		/* DRAMC_DDR2CTL_VAL */
		0x9F068CA0,		/* DRAMC_TEST2_3_VAL */
		0x00403361,		/* DRAMC_CONF2_VAL */
		0x11642842,		/* DRAMC_PD_CTRL_VAL */
		0x00000000,		/* DRAMC_PADCTL3_VAL */
		0x00000000,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		{0x10000000,0x10000000,0,0},		/* DRAM RANK SIZE */
		{0,0},		/* reserved 2 */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* EMMC FW ID */
		5,		/* EMMC ID/FW ID checking length */
		0x1,		/* sub_version */
		0x00000032,		/* DDR1_MODE_REG */
		0x00000020		/* DDR1_EXT_MODE_REG */
	}
};
