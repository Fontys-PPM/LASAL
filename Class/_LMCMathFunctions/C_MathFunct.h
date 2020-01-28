#ifndef _C_MATHFUNCT_H_
  #define _C_MATHFUNCT_H_
  
// ***************************************************************************************
// ***************************************************************************************
// ** FUNCTIONS for _LMCAxis                                                            **
// ***************************************************************************************
// ***************************************************************************************
  
FUNCTION GLOBAL __cdecl CalcPubModulo
	VAR_INPUT
		inputValue 	: DINT;
		ModuloValue 	: DINT;
	END_VAR
	VAR_OUTPUT
		OutputValue 	: DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl SetRoundPosC
	VAR_INPUT
		NewValue 	  : DINT;
    JerkRed     : DINT;
    pPosFilterLo : ^DINT;
    pPosFilterHi : ^DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl CorrRoundPosC
	VAR_INPUT
		Diff    	  : DINT;
    JerkRed     : DINT;
    pPosFilterLo : ^UDINT;
    pPosFilterHi : ^DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl vRampUp
	VAR_INPUT
		aTiksDecc   : DINT;
    pvTrapVk    : ^DINT;
    pvTrapNk    : ^UDINT;
	END_VAR;

FUNCTION GLOBAL __cdecl vRampDown
	VAR_INPUT
		aTiksDecc   : DINT;
    pvTrapVk    : ^DINT;
    pvTrapNk    : ^UDINT;
	END_VAR;

FUNCTION GLOBAL __cdecl vRampUpExt
	VAR_INPUT
		aTiksDecc   : DINT;
    pvTrap      : ^DINT;
    pvTrapVk    : ^DINT;
    pvTrapNk    : ^UDINT;
	END_VAR;

FUNCTION GLOBAL __cdecl vRampDownExt
	VAR_INPUT
		aTiksDecc   : DINT;
    pvTrap      : ^DINT;
    pvTrapVk    : ^DINT;
    pvTrapNk    : ^UDINT;
	END_VAR;

FUNCTION GLOBAL __cdecl Load_aSetC
	VAR_INPUT
		A_set 	    : DINT;
		D_Set       : DINT;
		HiRes2 	    : DINT;
    paTiksDecc   : ^DINT;
    paTiksDeccVk : ^DINT;
    pDecMaxTiks  : ^DINT;
    paTiksAcc    : ^DINT;
    paTiksAccVk  : ^DINT;
    pAccMaxTiks  : ^DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl CalcBrakeDistance
	VAR_INPUT
		_V 	: DINT;
		_A 	: DINT;
	END_VAR
	VAR_OUTPUT
		Distance 	: DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl CalcDecel
	VAR_INPUT
		_V 	: DINT;
		_DIST 	: DINT;
	END_VAR
	VAR_OUTPUT
		dDCC 	: DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl AddSpeed
	VAR_INPUT
		aTiksAcc    : DINT;
		aTiksDec    : DINT;
    vTemp       : DINT;
    pvTrap      : ^DINT;
    pvTrapNk    : ^UDINT;
	END_VAR;
  
FUNCTION GLOBAL __cdecl AddSpeed_Nk
	VAR_INPUT
		aTiksAcc    : DINT;
		aTiksDec    : DINT;
    vTemp       : DINT;
    vTempNk     : UDINT;
    pvTrap      : ^DINT;
    pvTrapVk    : ^DINT;
    pvTrapNk    : ^UDINT;
	END_VAR;

FUNCTION GLOBAL __cdecl AddPosition
	VAR_INPUT
    vTrap      : DINT;
    vTrapNk    : UDINT;
    pTrapPos   : ^DINT;
    pTrapPosNk : ^UDINT;
	END_VAR;

// ***************************************************************************************
// ***************************************************************************************
// ** FUNCTIONS for _LMCProfile                                                         **
// ***************************************************************************************
// ***************************************************************************************


FUNCTION GLOBAL __cdecl CalcPolyRoundCon
  VAR_INPUT
    BahnLaenge : LREAL;
    BahnIst    : LREAL;
  END_VAR
	VAR_OUTPUT
    fBahn    : LREAL;
	END_VAR;


FUNCTION GLOBAL __cdecl CalcPosPolyRound
	VAR_INPUT
		KoDiff  	: LREAL;
		BahnIst 	: LREAL;
		KoFacRound 	: LREAL;
		fBahn 	: LREAL;
	END_VAR
	VAR_OUTPUT
		Dist  	: LREAL;
	END_VAR;
  

FUNCTION GLOBAL __cdecl MulDiv64C
VAR_INPUT
	input		: DINT;
	multiply		: DINT;
	divisor		: DINT;
END_VAR
VAR_OUTPUT
	res		: DINT;
END_VAR;

  
FUNCTION GLOBAL __cdecl CalcArcLength
	VAR_INPUT
		dAngle 	: ^LREAL;
		dRadius 	: LREAL;
	END_VAR
	VAR_OUTPUT
		dArclength 	: LREAL;
	END_VAR;


// ***************************************************************************************
// ***************************************************************************************
// ** Common FUNCTIONS                                                                  **
// ***************************************************************************************
// ***************************************************************************************

FUNCTION GLOBAL __cdecl MulDiv64Ext
	VAR_INPUT
		input 	: DINT;
		multiply 	: DINT;
		divisor 	: DINT;
		pErrorInfo 	: ^iprStates;
	END_VAR
	VAR_OUTPUT
		dResult 	: DINT;
	END_VAR;

FUNCTION GLOBAL __cdecl MulDiv64_64
	VAR_INPUT
		pResHigh 	 : ^DINT;
		pResLow 	 : ^UDINT;
    inputHigh  : DINT;
    inputLow   : UDINT;
		multiplier : DINT;
		divisor 	 : DINT;
	END_VAR;
  
#endif
