#ifndef _TDL104_DEFS_H_
#define _TDL104_DEFS_H_

/*******************************************************
 *	Description  :  Defining Register of TDL104 - Power Datalogger
 *	Creator      :	Mohammad Jamshdinejad
 *	Creation Date:	2018-05-21
 *  File Version :	1.0
 *
 *	TODO:
 *		 Add Description for defines that needs.
 *
 *******************************************************/


/************ Function 3 defines ************/

#define F3_2_TIME_MIN			0	// Range : 0 to 59
#define F3_2_TIME_HOUR			1	// Range : 0 to 23
#define F3_2_TIME_D_AD			2	// Range : 1 to 31
#define F3_2_TIME_M_AD			3	// Range : 1 to 12
#define F3_2_TIME_Y_AD			4	// Range : 0 to 99
#define F3_2_REC_PERIOD			5
#define F3_2_MAXI_AVG			6
#define F3_2_PT_COEFF			7	// Range : less than 4000
#define F3_2_CT_COEFF			8	// Range : less than 1000
#define F3_2_CT_NUM				9
#define F3_2_TRIF_TIME_1		10
#define F3_2_TRIF_TIME_2		11
#define F3_2_TRIF_TIME_3		12
#define F3_2_TRIF_DAY			13
#define F3_2_DAYLIGHT_SAVEING	14
#define F3_2_
#define F3_2_
#define F3_2_
#define F3_2_PASSWORD			39
#define F3_2_TIME_D_SH			40
#define F3_2_TIME_M_SH			41
#define F3_2_TIME_Y_SH			42
#define F3_2_TIME_D_NAME_SH		43
#define F3_2_RELAY_STATUS		44
#define F3_2_
#define F3_2_
#define F3_2_
#define F3_30_GREAD_0_14		256
#define F3_48_GREAD_15_38		257
#define F3_36_GREAD_40_57		258

enum {
	REC_1_MIN =0,
	REC_2_MIN =1,
	REC_5_MIN =2,
	REC_10_MIN=3,
	REC_15_MIN=4,
	REC_30_MIN=5,
	REC_60_MIN=6
} REC_PERIOD;

enum {
	NON=0,
	SUN =1,
	MON =2,
	TUE =3,
	WED =4,
	THU =5,
	FRI =6,
	SAT =7
} DAY_NAMES;

enum {
	//OVER_VOLTAGE =1,
	//UNDER_VOLTAGE,
	//OVER_CURRENT,
	//OVER_ACTIVE_POWER,
	//UNDER_ACTIVE_POWER,
	//OVER_REACTIVE_POWER,
	OVER_THD_V=7,
	OVER_THD_I
} RELAY_STATUS;


/************ Function 4 defines ************/

#define F4_4_V1		0
#define F4_4_V2		1
#define F4_4_V3		2
#define F4_4_VAVE	3
#define F4_4_VU		4
#define F4_4_V12	5
#define F4_4_V23	6
#define F4_4_V31	7
#define F4_4_I1		8
#define F4_4_I2		9
#define F4_4_I3		10
#define F4_4_IAVE	11
#define F4_4_IN		12
#define F4_4_P1		13
#define F4_4_P2		14
#define F4_4_P3		15
#define F4_4_Q1		16
#define F4_4_Q2		17
#define F4_4_Q3		18
#define F4_4_S1		19
#define F4_4_S2		20
#define F4_4_S3		21
#define F4_4_PTOT	22
#define F4_4_QTOT	23
#define F4_4_STOT	24
#define F4_2_PF1	25
#define F4_2_PF2	26
#define F4_2_PF3	27
#define F4_2_FREQ	28		//
#define F4_2_TEMP	29
#define F4_2_THD_V1 30
#define F4_2_THD_V2 31
#define F4_2_THD_V3 32
#define F4_2_THD_I1 33
#define F4_2_THD_I2 34
#define F4_2_THD_I3 35

#define F4_2_RELAY_ACTIVATE	36		// Values  is in low byte

#define F4_24_PEAK_COUNTER		44
#define F4_24_NORMAL_COUNTER	45
#define F4_24_LOW_COUNTER		46
#define F4_24_HOLYDAY_COUNTER	47

#define F4_122_GREAD_0_35		256		// Read all parameter values
#define F4_96_GREAD_44_47		256		// Read all counter values


enum {
	DEACTIVE =0,
	OVER_VOLTAGE,
	UNDER_VOLTAGE,
	OVER_CURRENT,
	OVER_ACTIVE_POWER,
	UNDER_ACTIVE_POWER,
	OVER_REACTIVE_POWER,
	OVER_THD_V1,
	OVER_THD_V2,
	OVER_THD_V3,
	OVER_THD_I1,
	OVER_THD_I2,
	OVER_THD_I3
} RELAY_ACTIVATE;


/************ Function 6 defines ************/
/* Read codes are sames as F3. */
/* for write on registers, Fisrt must be write password */


/************ ERROR defines ************/
#define ERR_FUNCTION		1	// invalid function code
#define ERR_DATA_ADDRESS	2	// Invalid address
#define ERR_DATA_VALUE		3	// Invalid value
#define ERR_DEVICE_FAILURE	4	// No ACCESs - Write Password first




#endif	// _TDL104_DEFS_H_
