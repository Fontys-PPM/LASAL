//HFILTER:1
#ifndef VARANMANAGER_BASE_H
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define VARANMANAGER_BASE_H

//***********************************************************************************
//** VaranMaster Headerfile     	                                               **
//***********************************************************************************

//***********************************************
//** Defines                                   **
//***********************************************

//#define VM_CLASS_TIME_MEASUREMENT		// to activate time measurement of varan classes (should be deactivated)
//#define VARAN_TIME_MEASUREMENT_SINGLE_OBJECTS  // to activate time measurement of single objects in the manager (times are saved in the handle list)
//#define VARAN_DIAGNOSE              // to activate diagnose for varan

//Varan Manager class version //BleErn 04.01.2011 17:17: Revision is now fetched from class properties!
//#define VM_VERSION_MAJOR		1
//#define VM_VERSION_MINOR		31

//define for new os functions
#define VM_DISABLE_DEVICE_AVAILABLE		16#118F		//enable and disable port available until os version 1.1.143

//os version to check if interrupt for DA-Buffer is available (in the same version the LongDOs are supported by DAs)
#define VM_DA_BUFFER_AVAILABLE		    16#126A		// OS Version 01.02.106

//os version where the complete DMA/Payload support is available (Properties for the VM, does not yet exist)
#define VM_FULL_PAYLOAD_AVAILABLE     16#FFFF

// Loader version where PostInit is available 02.02.137
#define VM_POST_INIT_AVAILABLE        16#2289

// INTERFACE_MULTIVARANMANAGER verison which added the following Methods:
// MULTI_VARAN_iGetIsoDuration
// MULTI_VARAN_iCheckIsoState
// MULTI_VARAN_iExecuteDol 
// The Property VM_PROP_TASK_STATE_ASY
#define VM_MULTIVARAN_DOL_TIMING_AVAILABLE                  16#00001001

// INTERFACE_MULTIVARANMANAGER version which added the following methods
// MULTI_VARAN_iInsertDOIntoDOL
// INTERFACE_MULTIVARANMANAGER version which added the following DOL Type Option
// VARAN_DOL_NOT_INSERT_DO_INTO_DOL
#define VM_MULTIVARAN_ADD_DO_INTO_DOL                       16#00001003

//INTERFACE_MULTIVARANMANAGER version which added the following properties
// VM_PROP_PAYLOAD_DMA_CHANNEL_ENABLE
#define VM_MULTIVARAN_VERSION_DMA_CHANNEL_ENABLE            16#00001004

//Define own defines because the defines in the lsl_st_varan.h File are not st-conform. They use "<<" instead of "shl" so we would get a compiler error.
#define VM_MULTIVARAN_DMA_CHANNEL_ENABLE_ISO_RD             (1 shl 0) //PAYLOAD_DMA_ENABLE_ISO_RD
#define VM_MULTIVARAN_DMA_CHANNEL_ENABLE_ISO_WR             (1 shl 1) //PAYLOAD_DMA_ENABLE_ISO_WR
#define VM_MULTIVARAN_DMA_CHANNEL_ENABLE_ASY_RD             (1 shl 2) //PAYLOAD_DMA_ENABLE_ASY_RD
#define VM_MULTIVARAN_DMA_CHANNEL_ENABLE_ASY_WR             (1 shl 3) //PAYLOAD_DMA_ENABLE_ASY_WR

// INTERFACE_MULTIVARANMANAGER version which added the following properties
// VM_PROP_REQUIRED_ERROR_ENABLED
// VM_PROP_ISO_START_TIME
#define VM_MULTIVARAN_DOL_SET_REQUIRED_ERROR_ISO_START_TIME 16#00001005

//INTERFACE_MULTIVARANMANAGER version which added the following methods
//MULTI_VARAN_ICONFIGUREPLLSYNCOUT
//MULTI_VARAN_iGetSystemProperty

// INTERFACE_MULTIVARANMANAGER version which added the following properties
//SYS_PROP_MANAGER_COUNT
#define VM_MULTIVARAN_VERSION_GET_SYSTEM_PROPERTY_AVAILABLE 16#00001006

//INTERFACE_MULTIVARANMANAGER version which supports all features
#define VM_MULTIVARAN_VERSION_FULL_PAYLOAD_AVAILABLE        16#FFFF

//INTERFACE_MULTIVARANMANAGER version which added the following functions and properties
//Functions
//=======================
//iReportVaranError
//iTriggerWatchdog
//iIncrementSyncCounter
//iGetIsoDuration
//iGetTimeUpCounter
//iSetApplicationCallback
//
//properties
//SYS_PROP_OPERATIONAL_STATE
//VM_PROP_GLOBAL_FAILED_ACCESS_COUNTER
//VM_PROP_ASY_TIME_UP_COUNTER
//VM_PROP_PLL_SYNC_TIME_FRAME_COUNTER
//VM_PROP_PLL_STATUS_REGISTER
//VM_PROP_SYNC_COUNTER
//VM_PROP_PLL_SYSTEM_PERIOD_TIME
//VM_PROP_PLL_SYSTEM_PERIOD_DIVIDER
//VM_PROP_TIME_UP_COUNTER_BETWEEN_PLL_TICKS
//VC_OPT_PROP_BUFFER_ADDRESS_ISO
//VM_PROP_TASK_STATE_ISO
//VM_PROP_PLL_SHIFTED_PHASE
//VM_PROP_VARAN_PROTOCOL_VERSION
//VM_PROP_PLL_SYSTEM_PERIOD_TIME
//VM_PROP_PLL_SYSTEM_PERIOD_DIVIDER
//VM_PROP_PLL_DELTA_PHASE
//VM_PROP_TASK_STATE_ISO
//VM_PROP_IRQ_DURATION
//VM_PROP_IRQ_SCAN_RATE
//VM_PROP_MAX_COMMAND_EXECUTION_TIME
//ND_PROP_CONNECTION_STATE
//DO_PROP_RETRY_TIMEOUT
//DO_PROP_RETRY_TIMEOUT

//max number of varan manager classes
#define MAX_VARAN_MANAGERS		2

// Definitions for installing Update-Calls
#ifndef SCANDEFS_H
#define SCANDEFS_H
  #define CALL_OPTION_RT_PRESCAN  2#0001
  #define CALL_OPTION_RT_POSTSCAN 2#0010
  #define CALL_OPTION_CYCLIC      2#0100
  #define CALL_OPTION_POST_INIT   2#1000
#endif // SCANDEFS_H


//Task Control/Enable 
//  Bit 0: Direct Access 
//  Bit 1: Isochronous 
//  Bit 2: Asynchronous 
//  Bit 3: Administration 
//  Bit 5..6: Reserved 
//  Bit 7: Required Enable
//
// constant to switch off iso task (AND connection)
#define VM_DISABLE_ISO_TASK   2#11111101

//defines for DO settings
#define VM_ALLOWED_RETRIES				2			//(default: 2)number of allowed retries
#define VM_RETRY_TIMEOUT_DA				12340		//for direct accesses (128Byte see Design Spec Varan)
#define VM_RETRY_TIMEOUT_STD_OFFSET		3000		//standard timeout for a varan DO (2000ns) + option for analyser (1000ns)
#define VM_TIMEOUT_ONE_BYTE				80			//timeout time for one byte (varan)
#define VM_TIMEOUT_ONE_CDIAS			1000			//timeout for one cdias access
#define	VM_HUB_DELAY_TIME				1100		//Time delay of one varan hub (added to retry timeout time per hub)
#define VM_MAX_PLL_SYNC_MISS			3			//maximum value of missing pll input syncs
#define VM_CONST_FPGA_DELAY				16#6D		//is 1,09µs (in 10ns steps)

#define VM_START_HANDLES		50			//number of class handles at startup
#define VM_EXTEND_HANDLES		25			//number of handles to extend handle list

#define VM_CONTROL_ACCESS		0			//control access for installing default data objects
#define VM_MEMORY_ACCESS		1			//memory access for installing default data objects

#define	VM_DO_OFFSET_RD			7			//offset to get pointer to address of data object (pointer ReadData - 7)
#define	VM_DO_OFFSET_WR			6			//offset to get pointer to address of data object (pointer WriteData - 6)
#define	VM_DO_OFFSET_RDWR		11			//offset to get pointer to address of data object (pointer WriteData - 11)

#define VM_WATCHDOG_TRIGGER_TIME	100	//trigger watchdog every 100ms
#define VM_MAX_SYNC_OUTS			4
#define VM_SYNC_CPU_ID        1   // = PLL IRQ
#define VM_SYNC_OUT_ID				2   // VARAN Manager Trigger

#define VM_MAX_RETRY_TIMEOUT_MULTIPLE	200000

//defines for CIV's
#define CIV_CDIAS_HANDLES			100	//a maximum of 100 cdias access per CIV [max: 255](12Byte per access are required)
#define CIV_USER_IRQ				8	//maximum of 1 user irq per cdias module
#define CIV_SYSTEM_IRQ				8	//maximum of 1 system irq per cdias module

#define VM_SPI_PAGE_SIZE			               256
#define VM_SPI_IDENT_LIST           16#8000_0000
#define VM_SPI_SERIALNO_ID          16#0500_0000
#define VM_SPI_DOCU_ID              16#0700_0000
#define VM_SPI_MULTIFILE_ID         16#0800_0000
#define VM_SPI_CALIB_ID             16#0A00_0000
#define VM_SPI_FLASH_CONFIG_ID      16#0200_0000
#define VM_SPI_VENDOR_NAME_ID       16#0300_0000
#define VM_SPI_DEVICE_NAME_ID       16#0400_0000
#define VM_SPI_ORDERING_NO_ID       16#0600_0000
#define VM_SPI_IDENTIFICATION_LIST	16#0100_0000


#define VM_SPI_OS_VERSION     16#1212 //read/write SPI Flash requires OS version 1.2.18

#define VM_CLIENT_HEADER_SIZE     4
#define VM_CLIENT_OFFSET			    16#00    // 0C
#define VM_CLIENT_ISO_RD_OFFSET		16#0400  // 0400
#define VM_CLIENT_ISO_WR_OFFSET		16#0000  // 0000
#define VM_CLIENT_ASY_RD_OFFSET		16#1400  // 1400
#define VM_CLIENT_ASY_WR_OFFSET		16#1000  // 1000
#define VM_CLIENT_DA_RD_OFFSET		16#3400  // 3400
#define VM_CLIENT_DA_WR_OFFSET		16#3000  // 3000
#define VM_CLIENT_MAX_BUFFER_USE  1024     // 1008
#define VM_CLIENT_ISO_SWITCH_ID   16#83

#define VM_FLEXHUB_READ_ID        16#7FFFFFFF

// define maximum size of serial number string in bytes (used in classes flexhub and varan_base)
#define SERNO_STRING_SIZE  256

//VaranManager Fehler
#define VM_ERROR_TIMESLICE_IRQ  1
#define VM_ERROR_TIMESLICE      2
#define	VM_ERROR_WATCHDOG       3
#define VM_ERROR_REQUIRED       4
#define VM_ERROR_DEVICE         5

// priorities for execution (primary for safety DOs, where 1=read, 2=copy and 3=write) used in type of DO-Access
#define VM_PRIORITY_FILTER          16#0000FF00 // to check if a priority is set
#define VM_PRIORITY_1               16#00000100 // read access
#define VM_PRIORITY_2               16#00000200 // internal copy/move command
#define VM_PRIORITY_3               16#00000300 // write access

// Default priorities for read/write/WaitForevent Payload DOs
#define VM_PRIORITY_DEFAULT         1000

#define VM_PRIORITY_READ_DO         9000  // Lowest Priority
#define VM_PRIORITY_WAIT_DO         5000  
#define VM_PRIORITY_WRITE_DO        1000  // Highest Priority

#define VM_PRIORITY_SAFETY_READ_DO   1000
#define VM_PRIORITY_SAFETY_MOVE_DO   2000
#define VM_PRIORITY_SAFETY_WRITE_DO  3000

#define VM_PRIORITY_INVALID   16#FFFFFFFF // Used to check if no priority was specified

// Defines for the commands of the Control NewInst method
// Commands start at 0x8010 and go to 0x804F
#define VM_CMD_IS_PAYLOAD_SUPPORTED       16#8010
#define VM_CMD_IS_RDWR_SEPARAT_SUPPORTED  16#8011
#define VM_CMD_GET_MODULE_HANDLE          16#8012
#define VM_CMD_ADD_DO                     16#8013
#define VM_CMD_ADD_MOV_DO                 16#8014
#define VM_CMD_GET_DATA_POINTERS          16#8015
#define VM_CMD_NEED_POST_INIT_CALL        16#8017 // when a module needs to initialize during last init it calls the newinst of the varanmanager with this parameter
#define VM_CMD_POST_INIT_FINISHED         16#8018 // when the module is ready (CMD_NEED_LAST_INIT_CALL has to be called before)
#define VM_CMD_IS_DMA_ACTIVE              16#8019 // MULTI_VARAN Interface is in use, FPGA supports DMA Controller
#define VM_CMD_INSERT_DO_TO_DOL           16#801A // insert data object into a data object list or only into memory for this list (if only in memory it can be linked to the list via VM_CMD_LINK_DO_TO_DOL)
#define VM_CMD_LINK_DO_TO_DOL             16#801B // link an existing data object into a data object list
#define VM_CMD_DO_CREATION_FINISHED       16#801C // a post init object tells the varan manager it has finished DO creation
#define VM_CMD_DO_MEM_READY               16#801D // a post init object asks the varan manager if all post init objects have finished DO creation
#define VM_CMD_MOVE_DO_CREATION_FINISHED  16#801E // a post init object tells the varan manager it has finished Move DO creation
#define VM_CMD_MOVE_DO_MEM_READY          16#801F // a post init object asks the varan manager if all post init objects have finished Move DO creation
#define VM_CMD_SET_MUX_THIS               16#8020 // give the this pointer of the varan base to the mux object
#define VM_CMD_INSTALL_MUX_CALLBACKS      16#8021 // tell the mux to install it's callbacks
#define VM_CMD_INSTALL_DUMMY_CALLBACK     16#8022 // install callback without remembering the module (for module connection detection)
#define VM_CMD_SYNC_SEND_READY            16#8023 // a post init object tells the varan manager it is ready with sending the sync                      
#define VM_CMD_GET_SYSTEM_MANAGER_CNT     16#8024 // returns the number of varanmanager delivered from the OS                     


// Return Codes of the Control NewInst method
#define VM_CMD_OK                    0
#define VM_CMD_NOT_IMPLEMENTED      -1001
#define VM_CMD_WRONG_OS             -1002
#define VM_CMD_ERROR_MODULE_HANDLE  -1003
#define VM_CMD_ERROR_DO_HANDLE      -1004
#define VM_CMD_ERROR_EMPTY_POINTER  -1005
#define VM_CMD_ERROR_INVALID_TIMEOUT-1006
#define VM_CMD_ERROR_NO_PROPERTY    -1007   // all property values are invalid (= default value) => no property to change
#define VM_CMD_ERROR_NEW_INST       -1008

// Defines for Payload DO's single run support, s t_SingleRunState
#define SR_STATE_NOTHING          0
#define SR_STATE_ENABLE_ME        1
#define SR_STATE_DISABLE_ME       2
#define SR_STATE_LEAVE_ME_ENABLED 3

// Define for the SetDOProperty command
#define VM_DO_PROPERTY_INVALID    16#FFFFFFFF

#ifdef HWK_SHOW_PRAGMA_MESSAGES
// Define that activate access exceptions,
// if a method is called that does not support payload and the payload flag is set
// and vice versa
#pragma message("LanSte 27.08.2013 09:08 \ Remove define for release")
#define VM_DEBUG_PAYLOAD
#endif


//***********************************************
//** Types                                     **
//***********************************************
TYPE

	t_CallBackInterrupt	: STRUCT
		ud_Handle	: UDINT;
		ud_Error	: UDINT;
	END_STRUCT;

  t_SingleRunState : BSINT
    [
    1 StartRequest,
    2 IsRunning,
    3 ContRun,
    ];
    

  t_VM_CMD_AddDO : STRUCT  //! <Type Public="true" Name="t_VM_CMD_AddDO"/>
    p_ud_DoHandle : ^UDINT;
    ud_ModuleHandle : UDINT;
    ud_b_DoRequired : UDINT;
    ud_DolType : UDINT;
    ud_Command : UDINT;
    ud_Priority : UDINT;
    ud_PreScalerCounterThreshold : UDINT;
    ud_PreScalerCounterStartValue : UDINT;
    ud_OffsetRead : UDINT;
    ud_LengthRead : UDINT;
    ud_OffsetWrite : UDINT;
    ud_LengthWrite : UDINT;
    ud_Filter       : UDINT;
    ud_Slices   : UDINT;
    ud_WritePayloadType : UDINT;
  END_STRUCT;
  
  t_VM_CMD_AddMovDo : STRUCT  //! <Type Public="true" Name="t_VM_CMD_AddMovDo"/>
    p_ud_DoHandle : ^UDINT;
    ud_b_DoRequired : UDINT;
    ud_DolType : UDINT;
    ud_Priority : UDINT;
    ud_PreScalerCounterThreshold : UDINT;
    ud_PreScalerCounterStartValue : UDINT;
    ud_SourceReadDoHandle : UDINT;
    ud_SourceReadOffset : UDINT;
    ud_DestinationWriteDoHandle : UDINT;
    ud_DestinationWriteOffset : UDINT;
    ud_LengthMove : UDINT;
  END_STRUCT;

  t_VM_CMD_GetDataPointers : STRUCT  //! <Type Public="true" Name="t_VM_CMD_GetDataPointers"/>
    ud_DoHandle : UDINT;
    p_ud_ReadData : ^UDINT;
    p_ud_WriteData : ^UDINT;
  END_STRUCT;

  t_VM_CMD_GetModuleHandle : STRUCT  //! <Type Public="true" Name="t_VM_CMD_GetModuleHandle"/>
    p_us_position_info : ^USINT;
    p_ud_module_handle : ^UDINT;
  END_STRUCT;

  // Achtung bei Erweiterung diese Types. Idente Typen sind auch in den Klassen SdiasManager, VaranS2Manager, VaranManager definiert. 
  t_VM_CMD_NEED_POST_INIT_CALL_SETTINGS : BSINT
    [  
    1 Wait4DOCreation,
    2 Wait4MoveDOCreation,
    3 Wait4SyncSend,
    ];    
  

#ifndef VARAN_TIME_MEASUREMENT_DEACTIVATE

  t_s_CyRtTime      : STRUCT
    ud_CallTime     : UDINT;
    ud_ActTime      : UDINT;
    ud_MaxTime      : UDINT;
    ud_Timemark     : UDINT;
  END_STRUCT;
  
  t_s_IsoAsyVaranTime : STRUCT
    us_NotFirstRun    : USINT;
    ud_ActUsageRate   : UDINT;
    ud_MaxUsageRate   : UDINT;
    ud_Timestamp      : UDINT;
  END_STRUCT;
    
  t_VaranManagerTimes : STRUCT
    s_Realtime        : t_s_CyRtTime;
    s_IsoVaranTime    : t_s_IsoAsyVaranTime;
    s_Cyclic          : t_s_CyRtTime;
    s_AsyVaranTime    : t_s_IsoAsyVaranTime;
    ud_MaxResponseTime: UDINT;
  END_STRUCT;
  
#else

  t_VaranManagerTimes : USINT;
  t_s_CyRtTime        : USINT;
  t_s_IsoAsyVaranTime : USINT;
  
#endif

#ifdef VARAN_TIME_MEASUREMENT_SINGLE_OBJECTS

  t_s_SingleObjTimeMeasurement      : STRUCT
    aObjname        : ARRAY [0..255] OF CHAR;
    ud_ActTime      : UDINT;
    ud_MinTime      : UDINT;
    ud_MaxTime      : UDINT;
  END_STRUCT;
  
#else

  t_s_SingleObjTimeMeasurement : USINT;
  
#endif

#ifdef VM_CLASS_TIME_MEASUREMENT

#define   VaranTime_Rt              0
#define   VaranTime_RtPostScan      1
#define   VaranTime_Cy              2

	t_TimeMeasurementVaran : STRUCT
		us_Activate			: UDINT;
		ud_Timemark			: UDINT;
		ud_ActualTime		: UDINT;
		ud_MinimalTime		: UDINT;
		ud_MaximalTime		: UDINT;
		ud_AverageTime		: UDINT;
		ud_AverageSum		: UDINT;
		ud_AverageCounter	: UDINT;
	END_STRUCT;
#else
	t_TimeMeasurementVaran 	: USINT;
#endif
	
#ifdef VARAN_DIAGNOSE
  t_s_VaranDiagnose : STRUCT
    cmd_Input       : STRUCT
      ManagerNr     : UDINT;  
      BaseAddress   : UDINT;
      CounterLength : UDINT;
      Counter1      : UDINT;
      Counter2      : UDINT;
      Counter3      : UDINT;
      Counter4      : UDINT;
      Counter5      : UDINT;
    END_STRUCT;
    InputSize       : UDINT;
    cmd_Output      : STRUCT
      RetCode       : UDINT;
      Flags         : BDINT;
      Counter1      : UDINT;
      Counter2      : UDINT;
      Counter3      : UDINT;
      Counter4      : UDINT;
    END_STRUCT;
    OldCounter      : STRUCT
      Counter1      : UDINT;
      Counter2      : UDINT;
      Counter3      : UDINT;
      Counter4      : UDINT;
    END_STRUCT;
    OutputSize      : UDINT;
    Command :       (
	    Deactivate,
      Activate,
	    Reset
                    )$UDINT;
    TimeCounter     : UDINT;
    Counter         : UDINT;
    ActiveMerker    : BOOL;
  END_STRUCT;
#else 
  t_s_VaranDiagnose : USINT;
#endif

#pragma pack(push, 1)

	t_VaranDOSettingsRd	: STRUCT
		us_Command		: USINT;
		ud_Address		: UDINT;
		us_ByteCnt		: USINT;
		us_CommandRecv	: USINT;
	END_STRUCT;

	t_VaranDOSettingsWr	: STRUCT
		us_Command		: USINT;
		ud_Address		: UDINT;
		us_ByteCnt		: USINT;
	END_STRUCT;

	t_VaranDOSettingsRdWr	: STRUCT
		us_Command			: USINT;
		ud_AddressRd		: UDINT;
		us_ByteCntRd		: USINT;
		ud_AddressWr		: UDINT;
		us_ByteCntWr		: USINT;
	END_STRUCT;

	t_VaranDOSettingsMov	: STRUCT
		ud_AddressDest  : UDINT;
		ud_AddressSrc		: UDINT;
    ui_ByteCnt      : UINT;
	END_STRUCT;

	t_VaranDOSettingsLong	: STRUCT
		us_Command      : HSINT;
		ud_Address		  : HDINT;
    ui_ByteCount0   : UINT;
    us_ByteCount1   : USINT;
	END_STRUCT;

#pragma pack(pop)

END_TYPE

//to run our hardware even user debug in realtime
#ifndef SaveThisPointer

	#pragma pack (push,1)
	TYPE

	  DEBUGAPI : STRUCT

	    version   : UDINT;
	    size      : UDINT;

	    pSaveThisPointer : pVoid;
      pSaveFunction    : pVoid;
	  END_STRUCT;

	END_TYPE
	#pragma pack (pop)

#endif


//**********************************************
//** Macros                                   **
//**********************************************

//to run our hardware even user debug in realtime
#ifndef SaveThisPointer

	FUNCTION GLOBAL __cdecl P_SaveThisPointer
	VAR_INPUT
	  pThis     : pvoid;
	  reserved  : UDINT;  //Used as corenumber if version of debug API is >= 2
	END_VAR;

	#define SaveThisPointer(p1,p2)  			p_DebugAPI^.pSaveThisPointer $ P_SaveThisPointer(p1,p2)

#endif

#ifndef SaveFunction

  FUNCTION GLOBAL __cdecl P_SaveFunction
  VAR_INPUT
    pFunc   : pvoid;
    pParam  : pvoid;
    core    : UDINT;
  END_VAR;

  #define SaveFunction(p1,p2,p3)  			p_DebugAPI^.pSaveFunction $ P_SaveFunction(p1,p2,p3)


#endif

//HFILTER:1
#endif
//HFILTER:
