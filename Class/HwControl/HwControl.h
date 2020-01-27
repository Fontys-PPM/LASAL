#ifndef HW_CONTROL_H
#pragma once
#define HW_CONTROL_H

// Definitions for installing Update-Calls
#ifndef SCANDEFS_H
#define SCANDEFS_H
  #define CALL_OPTION_RT_PRESCAN  2#0001
  #define CALL_OPTION_RT_POSTSCAN 2#0010
  #define CALL_OPTION_CYCLIC      2#0100
  #define CALL_OPTION_POST_INIT   2#1000
#endif // SCANDEFS_H

#define TASK_SELECT_CORE0         16#0
#define TASK_SELECT_CORE1         16#1
#define TASK_SELECT_COREMAX       TASK_SELECT_CORE1   //max. number of supported cores from hw control

#define LSL_ITASK_VERSION_MULTICORE_SUPPORT 0x12  //Version since OS_AddRtFuncEx, ... are supported
#define DEBUG_API_VERSION_MULTICORE_SUPPORT 0x02  //Version since SaveFunction method is supported

// maximum time for the initilisation after the last init in ms
#define POST_INIT_TIMEOUT               30000

// newinst commands
#define CMD_POST_INIT_CALL          16#8002 // when the init is blocked but the realtime is already running everything gets called so it can wait until init is finished
#define CMD_NEED_POST_INIT_CALL     16#8003 // when a module needs to initialize during last init it calls the newinst of the varanmanager with this parameter
#define CMD_POST_INIT_FINISHED      16#8004 // when the module is ready (CMD_NEED_LAST_INIT_CALL has to be called before)
#define CMD_FORCE_POST_INIT_END     16#8005 // when the Post init runs init runs into timeout, this call is used by HWControl to stop the post init phase in the VM. Otherwise UpDateCy of HWK is not called
#define CMD_HWCONTROL_LOGIN         16#8006 // general login to hwcontrol to get callbacks for post init, cyclic and realtime pre-/postscan
#define CMD_POST_INIT_RT_READY      16#8007 // when the hwcontrol has finished post init it asks every module if it's also ready with it's rt
#define CMD_POST_INIT_DO_SORT       16#8008 // command for the varan managers to sort their DOs (safety first, then all others)            
#define CMD_HWC_ERROR_TO_DIASM      16#8009 // command to send an error of the hw control to the diasmaster (necessary to stop cyclic task)
#define CMD_POST_INIT_RT_SYNC       16#800A // when the hwcontrol has finished post init it asks every module if it got the sync in realtime up and running
#define CMD_SET_VARANMANAGER_ERROR  16#800B // command to set a VaranManagerError
#define CMD_EXTEND_POST_INIT_TIME   16#800C // command to extend the timeout of the post init phase by a customable amount of time in [ms]
#define CMD_SET_POSTINIT_DONE       16#800D // diasmaster is called whith this command when the of post-init of the HW-Control is done, no parameters are used
#define CMD_IS_POSTINIT_DONE        16#800E // query the diasmaster if the of post-init of HW-Control is done, pResult^.aData[0]$BOOL = true/false
#define CMD_GET_SUPPORTED_FEATURES  16#800F // command for classes to get supported features from hwcontrol

//newinst commands new range (0x80D0 - 0x80DF)
#define CMD_LOGIN_VARANMANAGER                16#80D0 // command to login varanmanager to hwcontrol
#define CMD_DISABLE_VARANMANAGER              16#80D1 // command to remove varanmanager from hwcontrol
#define CMD_POST_INIT_DISTRIBUTE_TASKTIMES    16#80D2 // command will be called at the beginning of the newinst to distribute the task infos to all logged in objects
#define CMD_GET_HW_TIMESTAMP                  16#80D3 // command to fetch timestamp for smart IO modules

//newinst commands hw diagnosis 0x83B0 - 0x83CF
#define CMD_GET_HARDWARE_TREE_ENTRY 16#83B0 // returns the next hardwaretree entry. Input Var of type: t_HWCGetHardwareTreeEntryIn, Output Var of type: t_HWCGetHardwareTreeEntryOut
#define CMD_GET_HARDWARE_DIAGNOSIS  16#83B1 // returns the diagnose data for the passed hardwaretree entry: Input Var of type: t_HWCGetHardwareDiagnosisIn, Output Var of type t_HWCGetHardwareDiagnosisOut

#define HWC_INVALID_DEVICE_ID 16#FFFFFFFF

#define HWCONTROL_MAX_FIRSTCALL_OBJECTS 10  //maximal amount of objects which are able to login as first objects to hw control


//#define HWCONTROL_TIME_MEASUREMENT          //Activates measurements of RtWork and RtPostScan in HwControl

#ifdef HWCONTROL_TIME_MEASUREMENT
  
  #define HWCONTROL_TIME_MEASUREMENT_DELAY    10000     //Delay after time measurement is started in ms
  #define HWCONTROL_TIME_MEASUREMENT_CNT      30000     //Amount of cycles how long the time measurement is running
  
  #define HWCONTROL_SYSTRACE_RTPRESCAN_START                      0x1000
  #define HWCONTROL_SYSTRACE_RTPRESCAN_START_FIRST_CALL_OBJECTS   0x1001
  #define HWCONTROL_SYSTRACE_RTPRESCAN_START_VARAN_MANAGERS       0x1002
  #define HWCONTROL_SYSTRACE_RTPRESCAN_START_DIAS_CDIAS_OTHER     0x1003
  #define HWCONTROL_SYSTRACE_RTPRESCAN_START_HW_OBJECTS           0x1004
  #define HWCONTROL_SYSTRACE_RTPRESCAN_FINISH                     0x1005
    
  #define HWCONTROL_SYSTRACE_RTPOSTSCAN_START                     0x1010
  #define HWCONTROL_SYSTRACE_RTPOSTSCAN_START_VARAN_MANAGERS      0x1012
  #define HWCONTROL_SYSTRACE_RTPOSTSCAN_START_HW_OBJECTS          0x1013
  #define HWCONTROL_SYSTRACE_RTPOSTSCAN_FINISH                    0x1014
  
  #define HWCONTROL_SYSTRACE_CYWORK_START                         0x1020
  #define HWCONTROL_SYSTRACE_CYWORK_START_VARAN_MANAGERS          0x1021
  #define HWCONTROL_SYSTRACE_CYWORK_START_HW_OBJECTS              0x1022  
  #define HWCONTROL_SYSTRACE_CYWORK_FINISH                        0x1023
  
#endif

#define HWCONTROL_SYSTRACE_RTPRESCAN_FINISHED_FIRST_CALL_OBJECTS  0x4857434F  //"HwCo" as ascii (1.215.775.599 = 0x4857434F = "HwCo")

#define HWCONTROL_SYSTRACE_TYPE                                 ((TRECGRP_USER0 SHL 16)          OR 16#0000)


// maximal size of logged object name in characters. if it's longer it will be shortened by HWC_LimitObjName to fit in a memory sized HWC_MAX_OBJECT_NAME_SIZE + 1 for termination
#define HWC_MAX_OBJECT_NAME_SIZE  50

// number of characters to take from the end when shrinking the name ("BeginningOfObjectName" + "~" + END_CHARS)
#define HWC_OBJECT_NAME_END_CHARS 10


//*****************************************************************************
//** TYPES                                                                   **
//*****************************************************************************

	TYPE
    t_HwObjListSettings : BDINT
	    [
	    1 RtPreScan,              //Object will be called in Rt Prescan
      2 RtPostScan,             //Object will be called in Rt Postscan
      3 Cyclic,                 //Object will be called in Cyclic
      4 PostInit,               //Object will be called in Post-Init
      5 CoreSelect,             //Object wants to be called from specific CPU-core (0 --> object will be called from core 0)
      6 TimeSet,                //Objects wants to set Realtime and Cyclic call which influence the task times
	    ];
      
    t_HWC_SupportedFeatureBits1  : BDINT
	    [
	    1 PostInitDoneCmdCalled,  //CMD_SET_POSTINIT_DONE will be called at the end of the post init phase
      2 CalculateTaskInfo,      //HwControl calculates the task settings (RT,CY) for each core due to the times of the logged in objects
	    ];
      
      
    t_HWCRetvalReturnCode :
    (
      _HWC_RETVAL_OK,
      _HWC_RETVAL_OK_MODULE_FOUND, 
      _HWC_RETVAL_OK_HWTSTR_RETURNED, 
      _HWC_RETVAL_OK_SDIAS_SPI_ACCESS_BUSY,
      _HWC_RETVAL_OK_END_OF_LIST,
      _HWC_RETVAL_ERROR,    
      _HWC_RETVAL_ERROR_WRONG_HARDWARE,
      _HWC_RETVAL_ERROR_NO_HARDWARE,
      _HWC_RETVAL_ERROR_NO_CALIB_DATA_FOUND,
      _HWC_RETVAL_ERROR_CLASS_NOT_ONLINE,
      _HWC_RETVAL_ERROR_VARAN_MODULE_NOT_FOUND,
      _HWC_RETVAL_ERROR_SDIAS_MODULE_NOT_FOUND,
      _HWC_RETVAL_ERROR_CDIAS_MODULE_NOT_FOUND,
      _HWC_RETVAL_ERROR_DIAS_MODULE_NOT_FOUND,
      _HWC_RETVAL_ERROR_AXIS_MODULE_NOT_FOUND,
      _HWC_RETVAL_ERROR_VARAN_SPI_ACCESS_FAILED,
      _HWC_RETVAL_ERROR_SDIAS_SPI_ACCESS_FAILED
    )$UDINT;

    // Input Paramater struct for newinst command CMD_GET_HARDWARE_TREE_ENTRY
    t_HWCGetHardwareTreeEntryIn : STRUCT
      pStr_LastHardewareTreeEntry : ^Char;   // Pointer to the last HW String entry. Pass nil if you want the first HW String entry.
      us_current_index        : USINT;   //Points to the current entry of hardwaretree string
      us_current_length       : USINT;
    END_STRUCT;
    
    // Output Paramater struct for newinst command CMD_GET_HARDWARE_TREE_ENTRY
    t_HWCGetHardwareTreeEntryOut : STRUCT
      retcode         : t_HWCRetvalReturnCode;    // Return code
      pStr_NextHardewareTreeEntry : ^Char;   // Pointer to which the requested HW String entry will be stored. The maximum stringlength of (TODO determin) byte must be reserved. Pointer is guaranteed o be valid until the next call 
    END_STRUCT;
    
    // Input Paramater struct for newinst command CMD_GET_HARDWARE_DIAGNOSIS
    t_HWCGetHardwareDiagnosisIn : STRUCT
      pStr_HardewareTreeEntry : ^Char;   // Pointer to the HW String entry for which the Diagnose data is requested
      us_current_index        : USINT;   //Points to the current entry of hardwaretree string
      us_current_length       : USINT;
    END_STRUCT;
    
    t_HWCGetHardwareDiagnosisOutType :   
    (
      _HWC_DIAG_ID_INVALID,                         // this signals a non valid information (no data specified)
      _HWC_DIAG_ID_SAFETY_FIRMWARE_VERSION,         // firmware version of a safety module (HDINT)
      _HWC_DIAG_ID_SAFETY_DESIGNER_PROJECT_NAME,    // safety designer project name string at a safety module (zero terminated string)
      _HWC_DIAG_ID_SAFETY_DESIGNER_PROJECT_REVISION // safety designer project revision string at a safety module (zero terminated string)
    )$UDINT;

    
    t_HWCGetHardwareDiagnosisOutDynExt : STRUCT
      DiagID          : t_HWCGetHardwareDiagnosisOutType;
      ud_Version      : UDINT; // version of the structure beginning at 1 (0 = invalid)
      p_Next          : ^t_HWCGetHardwareDiagnosisOutDynExt;
      ud_DataLength   : UDINT;
//    Data linear in memory (size of ud_DataLength)
    END_STRUCT;

    t_pHWCGetHardwareDiagnosisOutDynExt      : ^t_HWCGetHardwareDiagnosisOutDynExt;

    // Output Paramater struct for newinst command CMD_GET_HARDWARE_DIAGNOSIS
    // All String Pointers guaranteed to be valid until the next call 
    t_HWCGetHardwareDiagnosisOut : STRUCT
      retcode           : t_HWCRetvalReturnCode;    // Return code      
      ClassState        : t_e_VaranErrors;
      pStr_DeviceName   : ^Char;
      ud_DeviceID       : UDINT;
      pStr_VendorName   : ^Char;
      ud_VendorID       : UDINT;
      pStr_SerialNo     : ^Char;
      pStr_OrderingNo   : ^Char;
      ud_LicenseNo      : UDINT;
      hd_HWVersion      : HDINT;
      ud_Variante       : UDINT;
      hd_FPGAVersion    : HDINT;
      pStr_FWVersion    : ^Char;
      hd_SafetyNumber   : HDINT;
      ud_Place          : UDINT;
      ud_AxisNo         : UDINT;
      ud_reserved_size  : UDINT;
      pud_reserved      : ^UDINT;
      ud_user_size      : UDINT;
      pud_user          : ^UDINT;
      p_DynExtList      : ^t_HWCGetHardwareDiagnosisOutDynExt;

    END_STRUCT;

    t_GetHwTimestampCmd : STRUCT
      udVersion     : UDINT;
      udCoreSelect  : UDINT;
    END_STRUCT;

    t_GetHwTimestampResult : STRUCT
      udVersion     : UDINT;    
      uiTimeStamp   : UINT;
    END_STRUCT;
    
    //For NewInst CMD_POST_INIT_DISTRIBUTE_TASKTIMES
    t_Distribute_TaskTimes_Cmd : STRUCT
      udVersion         : UDINT;  //Version of the command
      udRtTaskTime_us   : UDINT;  //Calculated realtime task time in µs
      udCyTaskTime_us   : UDINT;  //Calculated cylcic task time in µs
    END_STRUCT;

    t_HwControlTimes : STRUCT
      ActTime : UDINT;
      AvgTime : UDINT;
      MinTime : UDINT;
      MaxTime : UDINT;
    END_STRUCT;

    t_HwControlTimeHelp : STRUCT
      udCycleCnt  : UDINT;
      bRestart    : BOOL;
      bFinished   : BOOL;
    END_STRUCT;
    
    t_HwControl_Times_SINGLE : STRUCT
      sRtPrescan_Total        : t_HwControlTimes;
      sRtPrescan_FirstCallHW  : t_HwControlTimes;
      sRtPrescan_HwObjects    : t_HwControlTimes;
      sRtPrescan_Varan        : t_HwControlTimes;
      sRtPrescan_Other        : t_HwControlTimes;
      sRtPostscan_Total       : t_HwControlTimes;
      sRtPostscan_HwObjects   : t_HwControlTimes;
      sRtPostscan_Varan       : t_HwControlTimes;
      sCyWork_Total           : t_HwControlTimes;
      sCyWork_HwObjects       : t_HwControlTimes;
      sCyWork_Varan           : t_HwControlTimes;
      sRtPreScan_Help         : t_HwControlTimeHelp;
      sRtPostScan_Help        : t_HwControlTimeHelp;
      sCywork_Help            : t_HwControlTimeHelp;
    END_STRUCT;

  END_TYPE
  
#endif


//**********************************************
//** Macros                                   **
//**********************************************
//for logging functions
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
