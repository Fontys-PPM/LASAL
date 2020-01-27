#ifndef SDIAS_MANAGER_H
#pragma once
#define SDIAS_MANAGER_H



//*****************************************************************************
//** SDO ERROR CODES                                                         **
//*****************************************************************************

#define SDIAS_SDO_ERROR_INVALID_MSG_CNT         0x00010000
#define SDIAS_SDO_ERROR_MSG_CNT_NOT_SUCCESSIVE  0x00010001
#define SDIAS_SDO_ERROR_INVALID_CMD             0x00010002
#define SDIAS_SDO_ERROR_INVALID_SUBCMD          0x00010003
#define SDIAS_SDO_ERROR_INVALID_PLACE           0x00010004
#define SDIAS_SDO_ERROR_INVALID_CMD_LENGTH      0x00010005
#define SDIAS_SDO_ERROR_INVALID_ACCESS_OFFSET   0x00010006
#define SDIAS_SDO_ERROR_INVALID_ACCESS_LENGTH   0x00010007
#define SDIAS_SDO_ERROR_INTERNAL_TIMEOUT        0x00010008
#define SDIAS_SDO_ERROR_GENERAL_ERROR           0x00010009
#define SDIAS_SDO_ERROR_MSG_CNT_CHANGED         0x0001000A
#define SDIAS_SDO_ERROR_CLIENT_NOT_READY        0x0001000B
#define SDIAS_SDO_ERROR_MNG_DPRAM_FAILURE       0x0001000C
#define SDIAS_SDO_ERROR_ACCESS_NOT_ALLOWED      0x0001000D
#define SDIAS_SDO_ERROR_FLASH_ACCESS_FAILED     0x0001000E
#define SDIAS_SDO_ERROR_INVALID_PARAMETERS      0x0001000F


//*****************************************************************************
//** NEWINST COMMANDS (Range reserved for SDIAS: 0x8250 - 0x827F)            **
//*****************************************************************************

// newinst commands (Range reserved for SDIAS: 0x8250 - 0x827F)

// commands from clients to manager 
#define SDIAS_CMD_ADD_RD_ACCESS             0x8250
#define SDIAS_CMD_ADD_WR_ACCESS             0x8251
#define SDIAS_CMD_SDO_SEND_REQUEST          0x8252
#define SDIAS_CMD_CHANGE_LED_STATE          0x8253
#define SDIAS_CMD_DA_RD_ACCESS              0x8254
#define SDIAS_CMD_DA_WR_ACCESS              0x8255
#define SDIAS_CMD_REQUIRED_ERROR            0x8256
#define SDIAS_CMD_INIT_STATE_LOGIN          0x8257
#define SDIAS_CMD_GET_HW_PATH               0x8258
#define SDIAS_CMD_INSTALL_CYCLIC_TASK       0x8259
#define SDIAS_CMD_GET_CONNECTION_TYPE       0x8260
#define SDIAS_CMD_GET_MIB_ADDR              0x8261 // command to get pointer to info block (needed for diagnosis classes)
#define SDIAS_CMD_GET_MOI_ADDR              0x8262 // command to get pointer to object info (needed for diagnosis classes)
#define SDIAS_CMD_ADD_DYN_RD_ACCESS         0x8263
#define SDIAS_CMD_ADD_DYN_WR_ACCESS         0x8264
#define SDIAS_CMD_CHANGE_DYN_ACCESS         0x8265
#define SDIAS_CMD_CREATE_MUTEX              0x8266
#define SDIAS_CMD_IS_VARAN_AVAILABLE        0x8267
#define SDIAS_CMD_GET_OWN_OBJECTPATH        0x8268 // command to get own object path (needed for command Get Hardwaretree entry)
#define SDIAS_CMD_ADD_DEVICE_ID             0x8269 // command to add valid device ids (needed that hardwareclass of vi022 works for a vi021 e.g.)
#define SDIAS_CMD_GET_SUPPORTED_FEATURES    0x826A // command to get info bits about supported features from sdias manager class

// commands from manager to clients
#define SDIAS_CMD_DEVICE_INFO               0x8270
#define SDIAS_CMD_SDO_RESPONSE              0x8271
#define SDIAS_CMD_DATA_POINTER_AVAILABLE    0x8272
#define SDIAS_CMD_INIT_ACCESSES             0x8273
#define SDIAS_CMD_DEVICE_INFO2              0x8274


//*****************************************************************************
//** OTHER DEFINES                                                           **
//*****************************************************************************

// define this to deactivate task checks (less VARAN load if SDIAS manager is behind VARAN. ATTENTION: RETRIES OF SINGLE ACCESSES ARE ALSO NOT CHECKED!)
//#define SDIAS_DEACTIVATE_TASK_CHECKS

#ifdef SDIAS_DEACTIVATE_TASK_CHECKS
// if this is not defined, the retry checks are also not done (only to save time in RT)
#define SDIAS_CHECK_ALL_RETRIES
#endif


#define SDIAS_MAX_MODULE_NO         64
#define SDIAS_MAX_PLACE_NR          SDIAS_MAX_MODULE_NO-1

#define SDIAS_MAX_SDO_READ_LENGTH   33
#define SDIAS_MAX_SDO_SPI_READ_LENGTH   SDIAS_MAX_SDO_READ_LENGTH - 1  // 1 Byte Offset 
#define SDIAS_MAX_SDO_WRITE_LENGTH  33

// manager place used for SDO requests which are adressed to the sdias manager itself
#define SDIAS_MANAGER_PLACE         128

#define SDIAS_MAX_PDO_SIZE          128
#define SDIAS_SDO_RESPONSE_TIMEOUT  SDIAS_SDO_TIMEOUT * 2

// 16#FFFF is defined as value where the FPGA is not waiting for another DO
#define SDIAS_INVALID_VOLATILE_WAIT_HANDLE  16#FFFF

// if an dynamic parameter (length or offset) did not chance => use this value
#define SDIAS_UNCHANGED_DYNAMIC_PARA      16#FFFFFFFF

// timeout for pending SDO requests in ms for manager, clients have to take this multiplied by 2
#define SDIAS_SDO_TIMEOUT                1000

// mask to get the tasks from the task config of the sdias client
#define SDIAS_TASK_MASK_RT_PRE              2#001
#define SDIAS_TASK_MASK_RT_POST             2#010
#define SDIAS_TASK_MASK_CY                  2#100

#define SDIAS_SYNCSTART_COUNTDOWN           50
#define SDIAS_PREOP_DATAVALID_TIMEOUT    10000  // [ms] 10s

//*****************************************************************************
//** TYPES                                                                   **
//*****************************************************************************

	TYPE
#pragma pack(push, 1)
    t_SDIAS_ControlByte : BSINT
	    [
	    1 EnableDO,
      2 EnableFlexRead,
      3 EnableFlexWrite,
      4 ForceMemAccess,
      5 ForceCtrlAccess,
      8 EnableDetailedAnswer,
	    ];
    
    t_SDIAS_ControlStructDynamic : STRUCT
      ControlByte   : t_SDIAS_ControlByte;
      usLength      : USINT;
      hiOffset      : HINT;
    END_STRUCT;
    
    t_SDIAS_ControlStructDynamicFar : STRUCT
      ControlByte   : t_SDIAS_ControlByte;
      usLengthRd    : USINT;
      hiOffsetRd    : HINT;
      usLengthWr    : USINT;
      hiOffsetWr    : HINT;
    END_STRUCT;

    t_SDIAS_StateByte : BSINT
	    [
	    1 ExecutionToggleBit,
      2 DeviceNotSync,
      3 PeripheryResetLatched,
      4 ExecutionCompleted,
      5 AccessFailed,
      6 RetryCounterBit0,
      7 RetryCounterBit1,
      8 RetryCounterBit2,
	    ];

    t_SDIAS_pControlByte: ^t_SDIAS_ControlByte;

    t_SDIAS_pStateByte: ^t_SDIAS_StateByte;

    t_SDIAS_DefaultAccess : STRUCT
      hiOffset      : HINT;
      usLength      : USINT;
      pControlByte  : t_SDIAS_pControlByte;
      pStateByte    : t_SDIAS_pStateByte;
      pData         : ^void;
    END_STRUCT;

    t_SDIAS_DefaultAccesses : STRUCT
      ReadAccess    : t_SDIAS_DefaultAccess;
      WriteAccess   : t_SDIAS_DefaultAccess;
    END_STRUCT;    

	  t_SDIAS_SDO_Cmd :
	  (
      SDIAS_SDO_CMD_INVALID             :=0x0000,
      SDIAS_SDO_CMD_MEM_READ            :=0x0101,
      SDIAS_SDO_CMD_MEM_WRITE           :=0x0201,
      SDIAS_SDO_CMD_CTRL_READ           :=0x0102,
      SDIAS_SDO_CMD_CTRL_WRITE          :=0x0202,
      SDIAS_SDO_CMD_SPI_READ            :=0x0103,
      SDIAS_SDO_CMD_SPI_WRITE           :=0x0203,
      SDIAS_SDO_CMD_SET_NEW_END         :=0x0111,
      SDIAS_SDO_CMD_REBUILD_SDIAS       :=0x0211,
      SDIAS_SDO_CMD_GET_ALLOWED_RETRIES :=0x0311,
      SDIAS_SDO_CMD_SET_ALLOWED_RETRIES :=0x0411,
      SDIAS_SDO_CMD_REBOOT              :=0x0112,
      SDIAS_SDO_CMD_START_BOOTLOADER    :=0x0212,
      SDIAS_SDO_CMD_INTERNAL_READ_PMB   :=0x0312,
      SDIAS_SDO_CMD_INTERNAL_WRITE_PMB  :=0x0412,
      SDIAS_SDO_CMD_SPECIAL_PMB_ACCESS  :=0x0512,
      SDIAS_SDO_CMD_WRITE_UC_FLASH      :=0x0612,
      SDIAS_SDO_CMD_READ_UC_FLASH       :=0x0712, 
      SDIAS_SDO_CMD_READ_UC_RAM         :=0x0812,
      SDIAS_SDO_CMD_WRITE_USER_FLASH    :=0x0912,
      SDIAS_SDO_CMD_READ_USER_FLASH     :=0x0A12
    )$UINT;

    t_SDIAS_SDO_RdWr_Head : STRUCT
      Offset : HINT;
      Length : USINT;
    END_STRUCT;
    
    t_SDIAS_SDO_Rd_SPI_Head : STRUCT
      PageAdress: HINT;
      PageOffset: HSINT;    
      Length : USINT;
    END_STRUCT;
	
    t_SDIAS_STD_CMD_DO : STRUCT
      iAdrInfoWrData      : HINT;    // Address in dpram of control information to write data
      iAdrInfoRdData      : HINT;    // Address in dpram of control information to read data
      iAdrVolWaitFlag     : HINT;    // Address in dpram of volatile wait flag
      iScratchpad_ErrInfo : UINT;    // Scratchpad data resulting in error info (by FPGA)
      iCmdType            : USINT;   // Command type of access
      iNoOfReadBytes      : USINT;   // Number of bytes used in read command
      iModAddrRdCmd       : HINT;    // Module address of read command (Base adr + offset)
      iReserved           : USINT;   // Not used atm
      iNoOfWriteBytes     : USINT;   // Number of bytes used in write command
      iModAddrWrCmd       : HINT;    // Module address of write command (Base adr + offset)
    
    END_STRUCT;
    
    t_SDIAS_BROADCAST_CMD_DO : STRUCT
      iAdrInfoWrData      : HINT;    // Address in dpram of control information to write data
      iAdrInfoRdData      : HINT;    // Address in dpram of control information to read data
      iAdrVolWaitFlag     : HINT;    // Address in dpram of volatile wait flag
      iScratchpad_ErrInfo : UINT;    // Scratchpad data resulting in error info (by FPGA)
      iCmdType            : USINT;   // Command type of access
      iNoOfReadBytes      : USINT;   // Number of bytes used in read command
      iModAddrRdWrCmd     : HINT;    // Module address of read/write command (Base adr + offset)
      iReserved           : USINT;   // Not used atm
      iCmdSubtype         : HSINT;   // CMD SubType: A0..Read and distribute data of a Clients FPP, B0 Read and distribute data of the Manafers FPP
      iNoOfWriteBytes     : USINT;   // Number of bytes used in write command      
      iReserved2          : USINT;   // Not used atm
    
    END_STRUCT;    
  
    // --- data struct of sdias configuration registers (slave side)  
    t_SDIAS_DOL_DESC : STRUCT
      iBaseAddr       : HINT;
      iEndAddr        : HINT;
      iBaseAddrData   : HINT;
      iEndAddrData    : HINT;
      iMaxUsage       : UINT;
      iUsageDOL       : UINT;
      iUsageData      : UINT;
      iOffEndCmd      : HINT;
      iOffFirstData   : HINT;
      iOffLastData    : HINT; 
      
    END_STRUCT;
    
	  t_SDIAS_ConnectionType :
	  (
      SDIAS_CON_UNDEFINED               :=0x0000, // value not set yet
      SDIAS_CON_VIA_VARAN_uC            :=0x0001, // connected via VARAN and there's a µC or OS who install the data objects and maintain the bus
      SDIAS_CON_LOCAL_uC                :=0x0002  // local SDIAS and there's a µC or OS who install the data objects and maintain the bus
    )$UINT;
    
    t_SDIAS_SupportedFeatureBits1  : BDINT
	    [
	    1 DefAcc4InitAcc,  //Default accesses from the single modules are available in the init access method
      2 TimeBroadCastSupported,  // Control Read/Broadcast Write Command is supported (OS, Manager, HWControl)
	    ];
    
    t_AccessOffLen : STRUCT
      hiOffset : HINT;
      usLength : USINT;
    END_STRUCT;

    t_ModuleInfo : STRUCT
      ModuleID              : UINT;
      HWVersion             : HSINT;
      FPGAVersion           : HSINT;
      SerialNo              : ARRAY [0..9] OF CHAR;
      ReadAccess            : t_AccessOffLen;
      ReadDODataRdOffset    : HINT;
      ReadDODataWrOffset    : HINT;
      WriteAccess           : t_AccessOffLen;
      WriteDODataRdOffset   : HINT;
      WriteDODataWrOffset   : HINT;
      SDIASProtocolVersion  : HINT;
      HWVersionMidLow       : UINT;
    END_STRUCT;

    t_TaskMeasurementInfo : STRUCT
      WrPayloadOffset : HINT;
      RdPayloadOffset : HINT;
    END_STRUCT;

    t_MappingID :
    (
      UnusedMapping:=0,
      DAList:=1,
      DAWrPayload:=2,
      DARdPayload:=3,
      SDOReqBufCh1:=4,
      SDOReqBufCh2:=5,
      SDOReqBufCh3:=6,
      SDOReqBufCh4:=7,
      SDORespBufCh1:=8,
      SDORespBufCh2:=9,
      SDORespBufCh3:=10,
      SDORespBufCh4:=11,
      IsoWrList:=12,
      IsoRdList:=13,
      IsoWrPayload:=14,
      IsoRdPayload:=15
    )$USINT;

    t_MappingInfo : STRUCT
      MappingID     : t_MappingID;
      StartAddress  : HINT;
      EndAddress    : HINT;
      ActUsage      : UINT;
    END_STRUCT;

    t_ManagerInfoBlock : STRUCT
      ModuleInfos : ARRAY [0..SDIAS_MAX_PLACE_NR] OF t_ModuleInfo;
      GeneralInfo : STRUCT
        FirmwareVersion : HINT;
        IsoWrTask       : t_TaskMeasurementInfo;
        IsoRdTask       : t_TaskMeasurementInfo;
        HandshakeFrom_uC: BSINT
        [
          1 IsoTaskRunning,  // Iso Tasks are automatically started controlled by µC" 
        ];
        HandshakeTo_uC  : BSINT
        [
          1 Request2StopIso,  // Request the µC to stop automatic starting of Iso Tasks" 
        ];
        Reserved        : ARRAY [0..51] OF USINT;
      END_STRUCT;
      MappingInfo : STRUCT
        MappingInfoNo : USINT;
        aMappingInfos : ARRAY [0..14] OF t_MappingInfo;
      END_STRUCT;
    END_STRUCT;

    t_eAccessType :
    (
      _NotSet,
      _Read,
      _Write,
      _ReadDynamic,
      _WriteDynamic
    )$UDINT;

    t_AccessElement : STRUCT
      eAccessType     : t_eAccessType;
      usPlace         : USINT;
      hiOffset        : HINT;
      uiLength        : UINT;
      bCtrlAcc0       : BOOL;
      bIsFarAcc       : BOOL;
      ppData          : pVoid;
      ppStateByte     : ^t_SDIAS_pStateByte;
      ppControlByte   : ^t_SDIAS_pControlByte;
      pWaitForAccess  : ^t_AccessElement;
      udOSDOHandle    : UDINT;
      pNext           : ^t_AccessElement;
    END_STRUCT;

    t_ModuleObjectInfo : STRUCT
      pThis                 : ^SdiasBase;
      pInitState            : ^t_e_VaranErrors;
      bPreScan              : BOOL;
      bPostScan             : BOOL;
      bCyclic               : BOOL;
      OldRetryCounter       : UDINT;
      Required              : DINT;
      pDefaultAccesses      : ^t_SDIAS_DefaultAccesses;
      AccessNo              : UDINT;
      pFirstAccess          : ^t_AccessElement;
      ModuleInitDuration_us : UDINT;
      RtTime_us             : UDINT;
      RtTimeMax_us          : UDINT;
      RtPostTime_us         : UDINT;
      RtPostTimeMax_us      : UDINT;
    END_STRUCT;
    
    t_ModuleObjectInfoS2 : STRUCT
      pThis                 : ^VaranS2Base;
      pInitState            : ^t_e_VaranErrors;
      bPreScan              : BOOL;
      bPostScan             : BOOL;
      bCyclic               : BOOL;
      OldRetryCounter       : UDINT;
      Required              : DINT;
      pDefaultAccesses      : ^t_SDIAS_DefaultAccesses;
      AccessNo              : UDINT;
      pFirstAccess          : ^t_AccessElement;
      ModuleInitDuration_us : UDINT;
      RtTime_us             : UDINT;
      RtTimeMax_us          : UDINT;
      RtPostTime_us         : UDINT;
      RtPostTimeMax_us      : UDINT;
      Place                 : UDINT;
      pNext                 : ^t_ModuleObjectInfoS2;
    END_STRUCT;
    
    t_SDIAS_UpdateRTPreOp :
	  (
      SDIAS_RTPREOP_CHECKSYNC           :=0x1000,
      SDIAS_RTPREOP_CHECKDATAVALID      :=0x2000      
    )$UDINT;
    
#pragma pack(pop)
  END_TYPE

#endif
