//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
#RE_IN_DE
#pragma define (store)
#if _LSL_COMPILERVERSION >= 42
HwControl : CLASS;
#endif
_AxisBase : CLASS_PUBLIC
	TYPE
	  _LMCAXIS_POSINFOMODE :
	  (
	    POSINFO_TIME,
	    POSINFO_DISTANCE
	  )$UDINT;
	  _LMCAXIS_READPARAMETER_LREAL :
	  (
	    LMCAXIS_PAR_RD2_JMAX
	  )$UDINT;
	  CmdControl :
	  (
	    IPRPowerOn,
	    IPRPowerOff,
	    IPRMoveRelative,
	    IPRMoveAbsolute,
	    IPRMoveReference,
	    IPRMoveEndless,
	    IPRMoveHand,
	    IPRStopMove,
	    IPRCoupleGearVelocity,
	    IPRCoupleDeltaPos,
	    IPRCoupleUserPos,
	    IPRCoupleProfilePos,
	    IPRCoupleGearRelative,
	    IPRCoupleGearAbsolute,
	    IPRCoupleCurveTab,
	    IPRSetSWEndPos,
	    IPRSetPosition,
	    IPRChangeCoupleSettings,
	    IPRTuneAxis,
	    IPRReadPosition,
	    IPRReadVelocity,
	    IPRInPosition,
	    IPRReadAxisStatus,
	    IPRReadAxisError,
	    IPRReadMasterInfo,
	    IPRSetFollowMode,
	    IPRReferenceReady,
	    IPRInpositionOk,
	    IPRCoupleGearPolynom,
	    IPRSetParameter,
	    IPRSetAdjustment,
	    IPRReadParameter,
	    IPRReadSWEndPos,
	    IPRCalcMovingTime,
	    IPRQuitError,
	    IPRCalcMaxSlavePath,
	    IPRCalcExtToAppliPos,
	    IPRReadUserData,
	    IPRGetMasterInformation,
	    IPR_SetErrorToMasterCoupleMonitoring
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk _BusInterfaceSdiasDriveMng
_BusInterfaceSdiasDriveMng : CLASS_PUBLIC
#include "..\class\_drivemngbase\drivemngbase.h"
	TYPE
#pragma pack(push, 1)
	  t_ReadValuePtr : STRUCT
	    a_SyncValues : ARRAY [0..4] OF DINT;
	    bs_InputStates : BSINT
	    [
	      1 OptionBoardInputState,
	    ];
	  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
	  t_WriteValuePtr : STRUCT
	    a_SyncValues : ARRAY [0..4] OF DINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk _DriveAxisBase
_DriveAxisBase : CLASS_PUBLIC
#include "..\Class\_DriveMngBase\SDDDefinitions.h"
#include "..\Class\HwControl\HwControl.h"
	TYPE
#pragma pack(push, 1)
	  _SDDMEMHEADER : STRUCT
	    udCRC32 : UDINT;
	    udLen : UDINT;
	    udVersion : UDINT;
	    AxOffset : DINT;
	    AxLength : UDINT;
	    AxName : ARRAY [0..20] OF CHAR;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk _DriveMngBase
_DriveMngBase : CLASS_PUBLIC
#include "..\Class\_DriveMngBase\SDDDefinitions.h"
#include "..\class\_drivemngbase\drivemngbase.h"
	TYPE
#pragma pack(push, 1)
	  _SDDBFENTRY : STRUCT
	    bFinished : DINT;
	    uiParaIndex : UINT;
	    usParaSubIndex : USINT;
	    usRDWR : USINT;
	    bsDataInfo : BSINT
	    [
	      1 DataLength1,
	      2 DataLength2,
	      3 res1,
	      4 res2,
	      5 Offset1,
	      6 Offset2,
	      7 res3,
	      8 res4,
	    ];
	    dValue : ARRAY [0..11] OF USINT;
	    pThisObj : ^void;
	    usEntry : USINT;
	    bSent : BOOL;
	    udTimeStamp : UDINT;
	  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
	  _SDDRINGBUFFER : STRUCT
	    pStart : ^_SDDBFENTRY;
	    pEnd : ^_SDDBFENTRY;
	    pRead : ^_SDDBFENTRY;
	    pWrite : ^_SDDBFENTRY;
	    ActEntries : DINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
_LMCRefBase : CLASS_PUBLIC
	TYPE
#pragma pack(push, 1)
	  _LMCAXIS_REFDATA : STRUCT
	    Status : iprStates;
	    Velocity : DINT;
	    Acc : DINT;
	    vSetRef1 : DINT;
	    vSetRef2 : DINT;
	    PosWindow : DINT;
	    LatchPosRef : DINT;
	    Speed : DINT;
	  END_STRUCT;
#pragma pack(pop)
	  _LMCREF_READPARAMETER :
	  (
	    ZPULSE_DIST
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk _LMCAxisBase
_LMCAxisBase : CLASS_PUBLIC
#include <.\lsl_st_systrace.h>
#include "..\Class\_LMCAxisBase\C_MathAxis.h"
#include "..\Class\_LMCAxisBase\_LMCTraceView.h"
	TYPE
	  _CommandList :
	  (
	    CPowerOn,
	    CPowerOff,
	    CInposition,
	    CMoveHand,
	    CMoveEndless,
	    CMoveAbsolut,
	    CMoveReference,
	    CMoveRelative,
	    CStopMove,
	    CCoupleGearAbsolute,
	    CCoupleGearRelative,
	    CCoupleGearVelocity,
	    CCoupleCurveTab,
	    CCoupleUserPos,
	    CCoupleDeltaPos,
	    CCoupleProfilePos,
	    CSetPosition,
	    CSetAutoOffset,
	    CSetCoupleParameter,
	    CSetParameter,
	    CReadPosition,
	    CSetSWEndPos,
	    CReadSWEndPos,
	    CReadAxisError,
	    CReadAxisStatus,
	    CReadMasterInfo,
	    CReadVelocity,
	    CReadParameter,
	    CTuneAxis:=28,
	    CInternModuloOverFlow:=29,
	    CFollowMode:=30,
	    CCoupleGearPolynom:=31,
	    CCoupleAdditivePosDiff:=32,
	    CCoupleCAM,
	    CMoveShortestWay,
	    CCalcMovingTime,
	    CQuitError,
	    CCalcMaxSlavePath,
	    CCalcExtToAppliPos,
	    CChangeMoveSettings,
	    CGetPosInfoBeforeRampDown,
	    CSetDynSWEndPos,
	    CQuickStop
	  )$UDINT;
	  _CoupleMonitorExtendedConfig : BDINT
	  [
	    1 ReportErrorToMaster,
	    2 ReportSlaveErrorToMaster,
	    3 ReportMasterErrorToSlave,
	    4 ReportSlaveErrorToSlave,
	    5 SwLimitMonitoring,
	    6 PowerOffMonitoring,
	  ];
	  _LogStruct : STRUCT
	    Command : _CommandList;
	    CommandoResult : _LMCAXIS_CMDERROR;
	    TimeStamp : UDINT;
	    RTStamp : UDINT;
	  END_STRUCT;
	  _LogFile : STRUCT
	    Logmode : DINT;
	    AccesNr : DINT;
	    LogData : ARRAY [0..101] OF _LogStruct;
	  END_STRUCT;
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk _LMCMathFunctions
_LMCMathFunctions : CLASS_PUBLIC
#include "..\Class\_LMCMathFunctions\C_MathFunct.h"
	TYPE
#pragma pack(push, 4)
	  _coeff_ : STRUCT
	    coA : LREAL;
	    coB : LREAL;
	    coC : LREAL;
	    coD : LREAL;
	    coE : LREAL;
	  END_STRUCT;
#pragma pack(pop)
	  _COORD_2D : ARRAY [0..1] OF DINT;
#pragma pack(push, 4)
	  _LMC_VECTOR3 : STRUCT
	    coord_x1 : LREAL;
	    coord_x2 : LREAL;
	    coord_x3 : LREAL;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
_LMCPublisher : CLASS_PUBLIC
	TYPE
	  _Config_ : BDINT
	  [
	    1 VirtualAxis,
	    2 RealAxis,
	  ];
	  _LMCPublisher_Cmd :
	  (
	    _LOGINCMD:=123
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
_SerLib : CLASS_PUBLIC
	TYPE
	  CmdCommand :
	  (
	    StartUserIPR,
	    StopUserIPR,
	    SerCloseIPR,
	    SerSendIPR,
	    RecvCharIPR,
	    SetOnlineIPR,
	    GetRecvStateIPR,
	    GetSendStateIPR,
	    GetErrorIPR,
	    IsInitializedIPR,
	    ClearRecBufferIPR,
	    RtsOnOffIPR,
	    rdRtsIPR,
	    rdCtsIPR,
	    DtrOnOffIPR,
	    rdDtrIPR,
	    rdDcdIPR,
	    rdDsrIPR,
	    rdRiIPR,
	    SetRSModeIPR,
	    GetRSModeIPR,
	    GetInterfaceTypeIPR
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk _VaranDriveBase
_VaranDriveBase : CLASS_PUBLIC
	TYPE
#pragma pack(push, 1)
	  t_ReadValuePtr : STRUCT
	    a_SyncValues : ARRAY [0..4] OF DINT;
	    bs_InputStates : BSINT
	    [
	      1 OptionBoardInputState,
	    ];
	  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
	  t_WriteValuePtr : STRUCT
	    a_SyncValues : ARRAY [0..4] OF DINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
MerkerEx : CLASS_PUBLIC
#include <.\lsl_st_mt.h>
	TYPE
	  Cmdm_udLength :
	  (
	    GET_DATA_PTR,
	    EXCHANGE_DATA_PTR,
	    SAVE_DATA_TO_RAMEXFILE
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
MoveController : CLASS_PUBLIC
	TYPE
	  _State :
	  (
	    _Safe,
	    _Homing,
	    _Idle,
	    _MovingAbsolute,
	    _moveready,
	    _MovingRelative,
	    _Pick,
	    _Place,
	    _Error
	  )$UDINT;
	  _Status :
	  (
	    _Idle,
	    _PowerOn,
	    _PowerIsOn,
	    _refRun,
	    _RefrunOk,
	    _MoveAbosolute,
	    _InPosition
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
SafetyCDIAS_Base : CLASS_PUBLIC
#include "..\Class\SafetyCDIAS_Base\SafetyCDIAS_Base.h"
#include "..\Source\interfaces\lsl_st_safety.h"
#include "..\Class\SafetyManager\SafetyManager.h"
	TYPE
	  FrameTypeType : BSINT
	  [
	    1 Cfg,
	    2 ToP,
	    3 Standard,
	    4 PDO,
	    5 TDO,
	    6 Reserved1,
	    7 Reserved2,
	    8 Response,
	  ];
#pragma pack(push, 1)
	  SDOStdHeader : STRUCT
	    CRC : UDINT;
	    Cmd : USINT;
	    Typ : FrameTypeType;
	    SeqNr : USINT;
	    Len : USINT;
	  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
	  SDOHeader : STRUCT
	    StdHeader : SDOStdHeader;
	    SrcAdr : HDINT;
	    DstAdr : HDINT;
	    SessId : UDINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
SafetyUDP : CLASS_PUBLIC
	TYPE
	  _FSM_UDP_ERROR :
	  (
	    _NO_ERROR_UDP_ERROR:=0,
	    _INIT_TCP_USER_UDP_ERROR:=4294967295,
	    _NO_IP_ADDRESS_UDP_ERROR:=4294967294,
	    _NO_MEMORY_SOCKET_UDP_ERROR:=4294967293,
	    _NO_MEMORY_SENDBUFFER_UDP_ERROR:=4294967292,
	    _INVALID_HANDLE_UDP_ERROR:=4294967291,
	    _SHUTDOWN_UDP_ERROR:=4294967290,
	    _CLOSESOCKET_UDP_ERROR:=4294967289,
	    _ALLOCATE_SOCKET_UDP_ERROR:=4294967288,
	    _SET_BIND_UDP_ERROR:=4294967287,
	    _RECV_UDP_ERROR:=4294967286,
	    _SEND_UDP_ERROR:=4294967285,
	    _NO_LOCAL_IP_UDP_ERROR:=4294967284,
	    _NO_DESTINATION_IP_UDP_ERROR:=4294967283,
	    _INVALID_UDP_PORT_UDP_ERROR,
	    _INVALID_INTERFACE_NUMBER_UDP_ERROR,
	    _NO_MEMORY_RECEIVE_BUFFER_UDP_ERROR,
	    _NO_MEMORY_CONNECTION_BUFFER_UDP_ERROR
	  )$DINT;
	  _FSM_UDP_USER :
	  (
	    _STATE_INIT_UDP,
	    _STATE_IDLE_UDP,
	    _STATE_SOCK_UDP,
	    _STATE_CONNECT_UDP,
	    _STATE_ONLY_SEND_UDP,
	    _STATE_RECV_UDP,
	    _STATE_SEND_UDP,
	    _STATE_SHUTDOWN_UDP,
	    _STATE_CLOSE_SOCK_UDP,
	    _STATE_ERROR_UDP
	  )$UDINT;
	  _INITSTEPS :
	  (
	    _NO_OPERATION,
	    _ADD_SOCKET,
	    _CHECK_IF_SOCKET_OPEN,
	    _BIND_SOCKET,
	    _CLOSE_CON
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
SdiasBase : CLASS_PUBLIC
#include "..\Class\SdiasManager\SdiasManager.h"
#include "..\Class\SdiasBase\SdiasBase.h"
#include "..\Class\HwControl\HwControl.h"
#include "..\Source\interfaces\lsl_st_hardwaretree.h"
#include "..\Source\interfaces\lsl_st_mt.h"
	TYPE
	  t_b_SdiasFWState : BINT
	  [
	    1 VoltageNotOk,
	    2 NoSync,
	    3 FlashDataCRCError,
	    4 RAMDataCRCError,
	    5 FlashUnsafe,
	    6 BusTimeNotSupported,
	    7 ToggleBit,
	  ];
#pragma pack(push, 1)
	  t_s_SdiasFWStateStandard : STRUCT
	    ErrorBits : t_b_SdiasFWState;
	    Reserved : UINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
SR022 : CLASS_PUBLIC
	TYPE
#pragma pack(push, 1)
	  t_SR_Fw_State : STRUCT
	    biFWErrorBits : SdiasBase::t_b_SdiasFWState;
	    biErrorState : BINT
	    [
	      1 bExternDCNotOKLatched,
	      2 bWrongSequence,
	      3 bAbsoluteTimeError,
	      4 bMotorCurrentHighLatched,
	      5 bMotorCurrentTooHighLatched,
	      6 bPeripheryResetMotorLatched,
	      7 bInductionVoltageTooHighLatched,
	      8 bOverTemp95CLatched,
	      9 bi2tErrorLatched,
	      10 Bit10,
	      11 Bit11,
	      12 Bit12,
	      13 Bit13,
	      14 Bit14,
	      15 Bit15,
	      16 Bit16,
	    ];
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
ST151Base : CLASS_PUBLIC
	TYPE
	  bd_EnabledFreqLimit : BDINT
	  [
	    1 FullStep,
	    2 HalfStep,
	    3 MicroStepping4,
	    4 MicroStepping8,
	    5 MicroStepping16,
	    6 MicroStepping32,
	    7 MicroStepping64,
	    8 Bit8,
	    9 Bit9,
	    10 Bit10,
	    11 Bit11,
	    12 Bit12,
	    13 Bit13,
	    14 Bit14,
	    15 Bit15,
	    16 Bit16,
	    17 Bit17,
	    18 Bit18,
	    19 Bit19,
	    20 Bit20,
	    21 Bit21,
	    22 Bit22,
	    23 Bit23,
	    24 Bit24,
	    25 Bit25,
	    26 Bit26,
	    27 Bit27,
	    28 Bit28,
	    29 Bit29,
	    30 Bit30,
	    31 Bit31,
	    32 Bit32,
	  ];
	  bd_ExtendedStateWord : BDINT
	  [
	    1 ZeroPosition,
	    2 OverTempWarning,
	    3 OverTempFailure,
	    4 OverCurrentFailureGND,
	    5 OverCurrentFailureBridge1,
	    6 OverCurrentFailureBridge2,
	    7 Encoder5VOk,
	    8 Bit8,
	    9 BridgeVoltageTooLow,
	    10 BridgeVoltageTooHigh,
	    11 ExternEnableSTO1,
	    12 ExternEnableSTO2,
	    13 SafetyStartUpOK,
	    14 MotorEnableError,
	    15 ThreeTimeSyncInLost,
	    16 SafeRampDownPending,
	    17 LoadWarning,
	    18 LoadDisableBridge,
	    19 LoadDisableResistor,
	    20 Bit20,
	    21 Bit21,
	    22 Bit22,
	    23 Bit23,
	    24 Bit24,
	    25 Bit25,
	    26 Bit26,
	    27 Bit27,
	    28 Bit28,
	    29 Bit29,
	    30 Bit30,
	    31 Bit31,
	    32 Bit32,
	  ];
	END_TYPE
END_CLASS;
#pragma define (restore)
VirtualBaseInit : CLASS_PUBLIC
	TYPE
	  CmdData :
	  (
	    GET_ADD_INFO,
	    READ_DATA,
	    WRITE_DATA,
	    READ_DATA_OFF,
	    WRITE_DATA_OFF
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)

#RE_IN_DE
