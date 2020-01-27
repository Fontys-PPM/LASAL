#ifndef _LSL_ST_CDIAS_EEPROM
#pragma once
#define _LSL_ST_CDIAS_EEPROM


TYPE
  _LSL_CDIAS_EEPROM   :STRUCT
    F_LSL_CDIAS_EEPROM     : pVoid;
  END_STRUCT;
END_TYPE



FUNCTION GLOBAL __cdecl P_READ_CDIAS_EEPROM
VAR_INPUT
  Station   : USINT;
  Offset 	: UINT;
  ptr   	: pVoid;
END_VAR
VAR_OUTPUT
  retval    : DINT;
END_VAR;

#define OS_READ_CDIAS_EEPROM(p1, p2, p3) _LSL_CDIAS_EEPROM^.F_LSL_CDIAS_EEPROM $ P_READ_CDIAS_EEPROM(p1, p2, p3)


(******************************************************************************
 * Define EEPROM commands.
 ******************************************************************************)

//
// Interface Definition
//
TYPE
	LSL_IFLASH : STRUCT

  	// Reserved
  	Reserved1    : pVoid;
  	Reserved2    : pVoid;
  	Reserved3    : pVoid;
  	Reserved4    : pVoid;
  	Reserved5    : pVoid;
  	Reserved6    : pVoid;
  	Reserved7    : pVoid;
  	Reserved8    : pVoid;
  	Reserved9    : pVoid;
  	Reserved10   : pVoid;

  	// Read CDIAS EEPROM
  	EEReadCDIAS  : pVoid;

  	// Read CDIAS EEPROM
  	EEWriteCDIAS : pVoid;

  END_STRUCT;
END_TYPE

// for convenience Makro for EEWriteCDIAS with pointer pFlashInfo
FUNCTION __CDECL GLOBAL P_EEWriteCDIAS
VAR_INPUT
	usPlace   	: USINT;
  	uiAddress 	: UDINT;
  	usData		: USINT;
END_VAR
VAR_OUTPUT
	retval  : DINT;
END_VAR;
#define IFLASH_EEWRITECDIAS(p1,p2,p3)  pFlashInfo^.EEWriteCDIAS $ P_EEWriteCDIAS(p1,p2,p3)


#endif