#ifndef  __LSL_SYSINFO_H
#pragma once
#define  __LSL_SYSINFO_H

// Interface
#define INTERFACE_LSL_SYSINFO            "LSL_SYSINFO"

// defines for possible Error Codes
#define LSL_SYSINFO_ERR_NONE		0		// no error
#define LSL_SYSINFO_ERR_ID			-1		// Unknown ID for SYSINFO_GetProperty
#define LSL_SYSINFO_ERR_NOT_AVAIL	-2		// Information for given ID not available on this CPU
#define LSL_SYSINFO_ERR_BUF			-3		// Invalid Buffer or Buffer length

TYPE
  LSL_SYSINFO_ID :
  (
	LSL_SYSINFO_ID_CPU_PLATFORM_STR := 1,	// STRING: (ARM,X86,..)
	LSL_SYSINFO_ID_CPU_PLATFORM,			// DINT: ECpuPlatformX86=0, ECpuPlatformArm
	LSL_SYSINFO_ID_CPU_TYPE,				// DINT: ECpuTypeX86=0, ECpuTypeVortex, ECpuTypeArm, ECpuTypeArmV5, ECpuTypeArmV7
	LSL_SYSINFO_ID_CPU_COUNT,				// DINT: count of cpu core(s)
	LSL_SYSINFO_ID_CPU_CLOCK,				// DINT	(kHz)
	
	LSL_SYSINFO_ID_PLATFORM_NAME_STR := 20,	// STRING: eeprom name of the CPU
	LSL_SYSINFO_ID_PLATFORM_TYPE,			// DINT: DESTPLC_...

	// DMI only on X86 systems
	LSL_SYSINFO_DMI_BIOS_DATE		 := 30,	// string:
	LSL_SYSINFO_DMI_BIOS_VENDOR,			// string:
	LSL_SYSINFO_DMI_BIOS_VERSION,			// string:
	LSL_SYSINFO_DMI_BOARD_NAME,				// string:
	LSL_SYSINFO_DMI_BOARD_SERIAL,			// string:
	LSL_SYSINFO_DMI_BOARD_VENDOR,			// string:
	LSL_SYSINFO_DMI_BOARD_VERSION,			// string:
	LSL_SYSINFO_DMI_CHASSIS_SERIAL,			// string:
	LSL_SYSINFO_DMI_CHASSIS_TYPE,			// string:
	LSL_SYSINFO_DMI_CHASSIS_VENDOR,			// string:
	LSL_SYSINFO_DMI_CHASSIS_VERSION,		// string:
	LSL_SYSINFO_DMI_PRODUCT_NAME,			// string:
	LSL_SYSINFO_DMI_PRODUCT_SERIAL,			// string:
	LSL_SYSINFO_DMI_PRODUCT_UUID,			// string:
	LSL_SYSINFO_DMI_PRODUCT_VERSION,		// string:
	LSL_SYSINFO_DMI_SYS_VENDOR,				// string:
	
	LSL_SYSINFO_ID_TEMPSENS0 := 50,			// DINT: temperature in milli Celsius
	LSL_SYSINFO_ID_TEMPSENS_BOARD0 := 50,	// DINT: temperature in milli Celsius
	LSL_SYSINFO_ID_TEMPSENS_BOARD1,			// DINT: temperature in milli Celsius
	LSL_SYSINFO_ID_TEMPSENS_BOARD2,			// DINT: temperature in milli Celsius
	
	LSL_SYSINFO_ID_TEMPSENS_CPU0 := 55,		// DINT: temperature in milli Celsius
	LSL_SYSINFO_ID_TEMPSENS_CPU1,			// DINT: temperature in milli Celsius
	LSL_SYSINFO_ID_TEMPSENS_CPU2,			// DINT: temperature in milli Celsius
	LSL_SYSINFO_ID_TEMPSENS_CPU3,			// DINT: temperature in milli Celsius

	// 90..99 SD-Card (SWISSBIT) Information
	LSL_SYSINFO_SDCARD_VENDOR		:= 90,	// STRING: vendor name
	LSL_SYSINFO_SDCARD_MODEL,				// STRING: model name
	LSL_SYSINFO_SDCARD_FIRMWARE,			// STRING: firmware version string
	LSL_SYSINFO_SDCARD_MAX_AVERAGE_ERASE_CNT,// DINT: max limit of average erase count
	LSL_SYSINFO_SDCARD_AVERAGE_ERASE_CNT,	// DINT: current average erase count
	LSL_SYSINFO_SDCARD_POWER_ON_CNT,		// DINT: power on counter

	LSL_SYSINFO_ID_LAST						// not used, id not importe
	)$UDINT;
END_TYPE

TYPE
	#pragma pack (push, 1)
	LSL_SYSINFO_TYPE : STRUCT
		version	: UDINT;
		SYSINFO_GetProperty : pVoid;
	END_STRUCT;
	#pragma pack (pop)
END_TYPE

////////////////////////////////////////////////////////////////////////////////
// LASAL Function Prototypes
////////////////////////////////////////////////////////////////////////////////
FUNCTION __CDECL GLOBAL P_SYSINFO_GetProperty
	VAR_INPUT
		id	: LSL_SYSINFO_ID;
		pBuf : pVoid;
		len : UDINT;
	END_VAR
	VAR_OUTPUT
		retval	: DINT;
	END_VAR;


////////////////////////////////////////////////////////////////////////////////
// LASAL MACROS
////////////////////////////////////////////////////////////////////////////////
#define OS_SYSINFO_GET_PROP(pSYSINFO,p1,p2,p3) pSYSINFO^.SYSINFO_GetProperty $ P_SYSINFO_GetProperty(p1,p2,p3)

#endif
