//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
TYPE
  SvrCh__Config__PTofCls__LMCPublisher : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCPublisher::_Config_;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh__Config__PTofCls__LMCPublisher : STRUCT
    pCh : ^SvrCh__Config__PTofCls__LMCPublisher;
    dData : _LMCPublisher::_Config_;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh__LMCAXIS_ERROR : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_ERROR;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh__LMCAXIS_ERROR : STRUCT
    pCh : ^SvrCh__LMCAXIS_ERROR;
    dData : _LMCAXIS_ERROR;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh__LMCAXIS_STATUS : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_STATUS;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh__LMCAXIS_STATUS : STRUCT
    pCh : ^SvrCh__LMCAXIS_STATUS;
    dData : _LMCAXIS_STATUS;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh__POSFLAGS : STRUCT
    pMeth : ^CHMETH;
    dData : _POSFLAGS;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh__POSFLAGS : STRUCT
    pCh : ^SvrCh__POSFLAGS;
    dData : _POSFLAGS;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_CncFlags : STRUCT
    pMeth : ^CHMETH;
    dData : CncFlags;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_CncFlags : STRUCT
    pCh : ^SvrCh_CncFlags;
    dData : CncFlags;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_DINT : STRUCT
    pMeth : ^CHMETH;
    dData : DINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_DINT : STRUCT
    pCh : ^SvrCh_DINT;
    dData : DINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_FeSetup : STRUCT
    pMeth : ^CHMETH;
    dData : FeSetup;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_FeSetup : STRUCT
    pCh : ^SvrCh_FeSetup;
    dData : FeSetup;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_IO_State : STRUCT
    pMeth : ^CHMETH;
    dData : IO_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_IO_State : STRUCT
    pCh : ^SvrCh_IO_State;
    dData : IO_State;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_UDINT : STRUCT
    pMeth : ^CHMETH;
    dData : UDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_UDINT : STRUCT
    pCh : ^SvrCh_UDINT;
    dData : UDINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrChCmd_t_e_VaranErrors : STRUCT
    pMeth : ^CMDMETH;
    dData : t_e_VaranErrors;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd__BusInterfaceSdiasDriveMng : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^_BusInterfaceSdiasDriveMng;
  END_STRUCT;
  SvrChCmd_DINT : STRUCT
    pMeth : ^CMDMETH;
    dData : DINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd__Can : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_Can;
  END_STRUCT;
  CltChCmd__CanLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_CanLib;
  END_STRUCT;
  CltChCmd__CheckSum : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_CheckSum;
  END_STRUCT;
  SvrChCmd_iprStates : STRUCT
    pMeth : ^CMDMETH;
    dData : iprStates;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd__DriveAxisBase : STRUCT
    pCh : ^SvrChCmd_iprStates;
    dData : iprStates;
    pCmd : ^_DriveAxisBase;
  END_STRUCT;
  CltChCmd__DriveAxisSet : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_DriveAxisSet;
  END_STRUCT;
  CltChCmd__DriveMngBase : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^_DriveMngBase;
  END_STRUCT;
  CltChCmd__FileSys : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_FileSys;
  END_STRUCT;
  CltChCmd__Linker : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_Linker;
  END_STRUCT;
  CltChCmd__LMCABSEncoder : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCABSEncoder;
  END_STRUCT;
  SvrChCmd__LMCAXIS_OPMODE : STRUCT
    pMeth : ^CMDMETH;
    dData : _LMCAXIS_OPMODE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd__LMCAxis : STRUCT
    pCh : ^SvrChCmd__LMCAXIS_OPMODE;
    dData : _LMCAXIS_OPMODE;
    pCmd : ^_LMCAxis;
  END_STRUCT;
  CltChCmd__LMCAxisBase : STRUCT
    pCh : ^SvrChCmd__LMCAXIS_OPMODE;
    dData : _LMCAXIS_OPMODE;
    pCmd : ^_LMCAxisBase;
  END_STRUCT;
  CltChCmd__LMCAxisRef : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCAxisRef;
  END_STRUCT;
  CltChCmd__LMCAxisVis : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCAxisVis;
  END_STRUCT;
  CltChCmd__LMCAxisVisInt : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCAxisVisInt;
  END_STRUCT;
  CltChCmd__LMCAxisVisLogHandle : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCAxisVisLogHandle;
  END_STRUCT;
  CltChCmd__LMCAxisVisLogViewer : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCAxisVisLogViewer;
  END_STRUCT;
  CltChCmd__LMCAxisVisPara : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCAxisVisPara;
  END_STRUCT;
  CltChCmd__LMCMathFunctions : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCMathFunctions;
  END_STRUCT;
  CltChCmd__LMCPublisher : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCPublisher;
  END_STRUCT;
  CltChCmd__LMCRefBase : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCRefBase;
  END_STRUCT;
  CltChCmd__LMCSafety : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_LMCSafety;
  END_STRUCT;
  CltChCmd__MultiTask : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_MultiTask;
  END_STRUCT;
  CltChCmd__OSKernel : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_OSKernel;
  END_STRUCT;
  CltChCmd__SerLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_SerLib;
  END_STRUCT;
  CltChCmd__StdLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_StdLib;
  END_STRUCT;
  CltChCmd__TaskObjectControl : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_TaskObjectControl;
  END_STRUCT;
  CltChCmd__VaranDriveBase : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^_VaranDriveBase;
  END_STRUCT;
  CltChCmd_ASCII_BIN : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^ASCII_BIN;
  END_STRUCT;
  CltChCmd_CommandRouter : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^CommandRouter;
  END_STRUCT;
  SvrChCmd__FSM_TCP_USER : STRUCT
    pMeth : ^CMDMETH;
    dData : _FSM_TCP_USER;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_CommandServer : STRUCT
    pCh : ^SvrChCmd__FSM_TCP_USER;
    dData : _FSM_TCP_USER;
    pCmd : ^CommandServer;
  END_STRUCT;
  CltChCmd_Controller : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Controller;
  END_STRUCT;
  SvrChCmd_UDINT : STRUCT
    pMeth : ^CMDMETH;
    dData : UDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_CriticalSection : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^CriticalSection;
  END_STRUCT;
  CltChCmd_DiasMaster : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DiasMaster;
  END_STRUCT;
  CltChCmd_DiasMasterC : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DiasMasterC;
  END_STRUCT;
  CltChCmd_DiasMasterPostScan : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DiasMasterPostScan;
  END_STRUCT;
  CltChCmd_DINT : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  CltChCmd_EEPROM : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^EEPROM;
  END_STRUCT;
  CltChCmd_Hub_Base : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Hub_Base;
  END_STRUCT;
  CltChCmd_Hub_Base_Root : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Hub_Base_Root;
  END_STRUCT;
  CltChCmd_HwControl : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HwControl;
  END_STRUCT;
  CltChCmd_HwControlBase : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HwControlBase;
  END_STRUCT;
  CltChCmd_HWRtPostScan : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HWRtPostScan;
  END_STRUCT;
  CltChCmd_I2CCDIAS : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^I2CCDIAS;
  END_STRUCT;
  CltChCmd_MerkerEx : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^MerkerEx;
  END_STRUCT;
  SvrChCmd__Status_PTofCls_MoveController : STRUCT
    pMeth : ^CMDMETH;
    dData : MoveController::_Status;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_MoveController : STRUCT
    pCh : ^SvrChCmd__Status_PTofCls_MoveController;
    dData : MoveController::_Status;
    pCmd : ^MoveController;
  END_STRUCT;
  SvrChCmd_ProfileCommandStatus : STRUCT
    pMeth : ^CMDMETH;
    dData : ProfileCommandStatus;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_ProfileCommandStatus : STRUCT
    pCh : ^SvrChCmd_ProfileCommandStatus;
    dData : ProfileCommandStatus;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  CltChCmd_RAMex : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^RAMex;
  END_STRUCT;
  CltChCmd_RamFile : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^RamFile;
  END_STRUCT;
  CltChCmd_SafetyManager : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SafetyManager;
  END_STRUCT;
  CltChCmd_SdiasHubBase : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SdiasHubBase;
  END_STRUCT;
  CltChCmd_SdiasManager : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^SdiasManager;
  END_STRUCT;
  CltChCmd_SigCLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SigCLib;
  END_STRUCT;
  CltChCmd_ST151_IntVisu : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^ST151_IntVisu;
  END_STRUCT;
  CltChCmd_ST151Base : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^ST151Base;
  END_STRUCT;
  CltChCmd_String : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^String;
  END_STRUCT;
  SvrChCmd_IO_State : STRUCT
    pMeth : ^CMDMETH;
    dData : IO_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_SyncCall : STRUCT
    pCh : ^SvrChCmd_IO_State;
    dData : IO_State;
    pCmd : ^SyncCall;
  END_STRUCT;
  CltChCmd_t_e_VaranErrors : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  CltChCmd_Varan_Base : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^Varan_Base;
  END_STRUCT;
  CltChCmd_VaranManager_Base : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^VaranManager_Base;
  END_STRUCT;
  CltChCmd_WatchdogDias : STRUCT
    pCh : ^SvrChCmd_IO_State;
    dData : IO_State;
    pCmd : ^WatchdogDias;
  END_STRUCT;
  SvrCh__CommandList_PTofCls__LMCAxisBase : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAxisBase::_CommandList;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__DRIVETYPE : STRUCT
    pMeth : ^CHMETH;
    dData : _DRIVETYPE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__FSM_UDP_ERROR_PTofCls_SafetyUDP : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyUDP::_FSM_UDP_ERROR;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__FSM_UDP_USER_PTofCls_SafetyUDP : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyUDP::_FSM_UDP_USER;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__I_HC_Type : STRUCT
    pMeth : ^CHMETH;
    dData : _I_HC_Type;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__INITSTEPS_PTofCls_SafetyUDP : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyUDP::_INITSTEPS;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_CMDERROR : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_CMDERROR;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_ERROR_CONFIG : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_ERROR_CONFIG;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_MOVE_RELATIVE_MODE : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_MOVE_RELATIVE_MODE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_MOVEDIRECTION : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_MOVEDIRECTION;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_MOVEPROFILE : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_MOVEPROFILE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_POSMODE : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_POSMODE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_POWER_OFF_MODE : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_POWER_OFF_MODE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_REFMODE : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_REFMODE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_SETPARAMETER : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_SETPARAMETER;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_SETPOSITION : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_SETPOSITION;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCAXIS_SETSWENDPOS : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCAXIS_SETSWENDPOS;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__LMCCONTROLLERTYPE : STRUCT
    pMeth : ^CHMETH;
    dData : _LMCCONTROLLERTYPE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__SDDAXISSTATE : STRUCT
    pMeth : ^CHMETH;
    dData : _SDDAXISSTATE;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__SDDUSERCMD : STRUCT
    pMeth : ^CHMETH;
    dData : _SDDUSERCMD;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__State_PTofCls_MoveController : STRUCT
    pMeth : ^CHMETH;
    dData : MoveController::_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_bd_EnabledFreqLimit_PTofCls_ST151Base : STRUCT
    pMeth : ^CHMETH;
    dData : ST151Base::bd_EnabledFreqLimit;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_bd_ExtendedStateWord_PTofCls_ST151Base : STRUCT
    pMeth : ^CHMETH;
    dData : ST151Base::bd_ExtendedStateWord;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_BDINT : STRUCT
    pMeth : ^CHMETH;
    dData : BDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_DS402_Control : STRUCT
    pMeth : ^CHMETH;
    dData : DS402_Control;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_DS402_State : STRUCT
    pMeth : ^CHMETH;
    dData : DS402_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_HDINT : STRUCT
    pMeth : ^CHMETH;
    dData : HDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_SafetyConfigStateType : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyConfigStateType;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_t_e_VaranErrors : STRUCT
    pMeth : ^CHMETH;
    dData : t_e_VaranErrors;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_t_SR_Fw_State_PTofCls_SR022 : STRUCT
    pMeth : ^CHMETH;
    dData : SR022::t_SR_Fw_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
END_TYPE
