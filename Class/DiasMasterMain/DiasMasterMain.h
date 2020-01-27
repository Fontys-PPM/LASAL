#ifndef DiasMasterMain_H
#pragma once
#define DiasMasterMain_H

//***********************************************************************************
//** DiasMasterMain Headerfile                                                     **
//***********************************************************************************

//***********************************************
//** Defines                                   **
//***********************************************
#define DIASRetryCounterOffset  16#0008		// offset of the DIAS retry counter in the control area
#define OSVersionDIASIO		      16#1151		// OS must have a version number of at least 01.01.80 to support
											// OS based DIAS IO

// define to disable DIAS ERROR for direct accesses on DIAS (asynchron method timeout error)
//#define DIASMASTER_DISABLE_DIAS_ERROR_ON_DIRECT_ACCESS

#define DmTimeReserveIM			3			//reserve time at the end of Rt IM programm (25µs steps) (default: 3)

#define DIASMASTERC_OBJECT_PATH_DIAS      16#83000002   // Object Path for DiasMaster Length = 2 (First 2byte), Domain = 0 (3rd byte), Escape Sequence DIAS (4th byte) 
#define DIASMASTERC_OBJECT_PATH_CDIAS     16#82000002   //  Object Path for DiasMaster Length = 2 (First 2byte), Domain = 0 (3rd byte), Escape Sequence DIAS (4th byte) 

#define DIASMASTERC_MAX_MODULE_NO 500 // Max number of CDIAS + DIAS Modules that are saved for HW Diagnosis


//***********************************************
//** Types                                     **
//***********************************************
TYPE
	MYLSL_ITASK                 : STRUCT
		AddCyclicFunction         : pVoid;
		AddCyclicObject           : pVoid;
		RemoveCyclicTask          : pVoid;
		SignalCyclicTask          : pVoid;
		AddRealTimeFunction       : pVoid;
		AddRealTimeObject         : pVoid;
		RemoveRealTimeTask        : pVoid;
		SignalRealTimeTask        : pVoid;
		StartMeasCyclicTask       : pVoid;
		StopMeasCyclicTask        : pVoid;
		StartMeasRealTimeTask     : pVoid;
		StopMeasRealTimeTask      : pVoid;
		AddFrgFunction            : pVoid;
		AddFrgObject              : pVoid;
		SuspendFrgTask            : pVoid;
		ResumeFrgTask             : pVoid;
		InitTaskModul             : pVoid;
		GetPointerToTaskList      : pVoid;
		AddHPUserObject           : pVoid;  // THR RTOS V5.06: High Priority User task object
		MoveObject                : pVoid;  // pr: V5.43
		SetNbrOfLdrPhaseObjects   : pVoid;  // pr: V5.43
		Dummy4                    : pVoid;
		GetKernelCyclic			      : pVoid;
		SuspendKernelCyclic		    : PVoid;
	END_STRUCT;
END_TYPE

//#SR011 start
#ifndef SaveThisPointer

	#pragma pack (push,1)
	TYPE

	  DEBUGAPI : STRUCT

	    version   : UDINT;
	    size      : UDINT;

	    pSaveThisPointer : pvoid;

	  END_STRUCT;

	END_TYPE
	#pragma pack (pop)

#endif
//#SR011 end

//**********************************************
//** Macros                                   **
//**********************************************
// pr V5.43:
(*
#ifndef OS_SetNbrOfLdrPhaseObjects

	FUNCTION GLOBAL __cdecl P_SetNbrOfLdrPhaseObjects
	VAR_INPUT
		nbrOfObjs	: UDINT;
	END_VAR
	VAR_OUTPUT 
		result		: DINT;
	END_VAR;

	#define OS_SetNbrOfLdrPhaseObjects(p1) _LSL_POS^.piTask^$MYLSL_ITASK.SetNbrOfLdrPhaseObjects $ P_SetNbrOfLdrPhaseObjects(p1);
#endif

// pr V5.43:
#ifndef OS_MoveObject

	FUNCTION GLOBAL __cdecl P_MoveObject
	VAR_INPUT
		thisPtr		: pVoid;
		taskType	: UDINT;
		flags		: UDINT;
	END_VAR
	VAR_OUTPUT 
		result		: DINT;
	END_VAR;

	#define OS_MoveObject(p1,p2,p3) _LSL_POS^.piTask^$MYLSL_ITASK.MoveObject $ P_MoveObject(p1,p2,p3);

#endif
*)

//ws004
FUNCTION __cdecl P_ReadKenn
VAR_INPUT
  pDIAS  : pVoid;
  us_mod : usint;
END_VAR
VAR_OUTPUT
  result : usint;
END_VAR;

#define OS_DIAS_ReadKenn(p1,p2)         	_LSL_POS^.piDIAS^.GetModID $ P_ReadKenn(p1,p2);

FUNCTION __cdecl P_ReadRegister
VAR_INPUT
  pDIAS   : pVoid;
  ui_offs : uint;
  us_data : ^usint;
END_VAR
VAR_OUTPUT
  result  : dint;
END_VAR;

#define OS_DIAS_ReadRegister(p1,p2,p3)  	_LSL_POS^.piDIAS^.ReadRegister $ P_ReadRegister(p1,p2,p3);

FUNCTION __cdecl P_WriteRegister
VAR_INPUT
  pDIAS   : pVoid;
  ui_offs : uint;
  us_data : usint;
END_VAR
VAR_OUTPUT
  result  : dint;
END_VAR;

#define OS_DIAS_WriteRegister(p1,p2,p3)  	_LSL_POS^.piDIAS^.WriteRegister $ P_WriteRegister(p1,p2,p3);


FUNCTION __cdecl P_WriteWord
VAR_INPUT
  pDIAS   	: pVoid;
  us_mod 	: usint;
  ui_off	: uint;
  ui_data 	: uint;
END_VAR
VAR_OUTPUT
  result  	: dint;
END_VAR;

#define OS_DIAS_WriteWord(p1,p2,p3,p4)		_LSL_POS^.piDIAS^.WriteWord $ P_WriteWord(p1,p2,p3,p4);

FUNCTION __cdecl P_WriteByte
VAR_INPUT
  pDIAS   	: pVoid;
  us_mod 	: usint;
  ui_off 	: uint;
  us_data 	: usint;
END_VAR
VAR_OUTPUT
  result  	: dint;
END_VAR;

#define OS_DIAS_WriteByte(p1,p2,p3,p4)		_LSL_POS^.piDIAS^.WriteByte $ P_WriteByte(p1,p2,p3,p4);

FUNCTION __cdecl P_WriteCtrl
VAR_INPUT
  pDIAS   	: pVoid;
  us_mod 	: usint;
  ui_off 	: uint;
  us_data 	: usint;
END_VAR
VAR_OUTPUT
  result  	: dint;
END_VAR;

//this is already defined in rtos_interfaces.h but in a strange way
#define OS_DIAS_WriteCtrl_(p1,p2,p3,p4)		_LSL_POS^.piDIAS^.WriteCtrl $ P_WriteCtrl(p1,p2,p3,p4);

FUNCTION __cdecl P_ReadWord
VAR_INPUT
  pDIAS   	: pVoid;
  us_mod 	: usint;
  ui_off 	: uint;
  ui_data 	: ^uint;
END_VAR
VAR_OUTPUT
  result  	: dint;
END_VAR;

#define OS_DIAS_ReadWord(p1,p2,p3,p4)		_LSL_POS^.piDIAS^.ReadWord $ P_ReadWord(p1,p2,p3,p4);

FUNCTION __cdecl P_ReadByte
VAR_INPUT
  pDIAS   	: pVoid;
  us_mod 	: usint;
  ui_off 	: uint;
  us_data 	: ^usint;
END_VAR
VAR_OUTPUT
  result  	: dint;
END_VAR;

#define OS_DIAS_ReadByte(p1,p2,p3,p4)		_LSL_POS^.piDIAS^.ReadByte $ P_ReadByte(p1,p2,p3,p4);

// /ws004

//#SR008 start
#ifndef OS_KernelLog0

	FUNCTION __CDECL P_KernelLog0
	VAR_INPUT
	  msg	:^CHAR;
	END_VAR;

	#define OS_KernelLog0(p1) 					p_KernelLog $ P_KernelLog0(p1);

	FUNCTION __CDECL P_KernelLog1
	VAR_INPUT
	  msg	:^CHAR;
	  Var1	: DINT;
	END_VAR;

	#define OS_KernelLog1(p1,p2)				p_KernelLog $ P_KernelLog1(p1,p2);

	FUNCTION __CDECL P_KernelLog2
	VAR_INPUT
	  msg	:^CHAR;
	  Var1	: DINT;
	  Var2	: DINT;
	END_VAR;

	#define OS_KernelLog2(p1,p2,p3)				p_KernelLog $ P_KernelLog2(p1,p2,p3);

	FUNCTION __CDECL P_KernelLog3
	VAR_INPUT
	  msg	:^CHAR;
	  Var1	: DINT;
	  Var2	: DINT;
	  Var3	: DINT;
	END_VAR;

	#define OS_KernelLog3(p1,p2,p3,p4)				p_KernelLog $ P_KernelLog3(p1,p2,p3,p4);
#endif
//#SR008 end

//#SR011 start
#ifndef SaveThisPointer

	FUNCTION GLOBAL __cdecl P_SaveThisPointer
	VAR_INPUT
	  pThis     : pvoid;
	  reserved  : UDINT;
	END_VAR;

	#define SaveThisPointer(p1,p2)  			p_DebugAPI^.pSaveThisPointer $ P_SaveThisPointer(p1,p2)

#endif
//#SR011 end

#endif