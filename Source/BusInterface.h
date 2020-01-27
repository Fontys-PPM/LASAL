#ifndef BUSINTERFACE_H
#pragma once
#define BUSINTERFACE_H

//*****************************************************************************
//** NEWINST COMMANDS (Range reserved for bus interface: 0x8200 - 0x823F)    **
//*****************************************************************************

// Commands that the Bus IF provides
// Commands id range from 0x8200 to 0x822F
#define _BUS_IF_ADD_CALLBACK              16#8200  // Add callback pointer for HWConnect/Init done 
#define _BUS_IF_ADD_DO                    16#8201  // Add a data object
#define _BUS_IF_UPDATE_DO                 16#8202  // Update a data object
#define _BUS_IF_RESET_DO                  16#8203  // Reset a data object
#define _BUS_IF_ADD_TASK                  16#8204  // Add Task
#define _BUS_IF_RD_DA                     16#8205  // Direct read Access
#define _BUS_IF_WR_DA                     16#8206  // Direct write Access
#define _BUS_IF_SET_RUN_STATE             16#8207  // Set the run state of the DO
#define _BUS_IF_SET_ONLINE                16#8208  // Sets the online Server
#define _BUS_IF_GET_BUSCYCLE_TIME         16#8209  // Returns the Bus cycle time, and the ISO Start time offset (if available)
#define _BUS_IF_SET_DO_PRESCALER          16#820A  // Adds Prescaler to passed DO
#define _BUS_IF_SET_TASKS_PRESCALER       16#820B  // Adds Prescaler for the Task callbacks
#define _BUS_IF_SET_SYNC                  16#820C  // Sets sync data for the passed sync
#define _BUS_IF_WAIT_4_POST_INIT          16#820D  // tell the bus manager that we need some extra time in init
#define _BUS_IF_POST_INIT_FINISHED        16#820E  // tell the bus manager that we can leave the init now
#define _BUS_IF_GET_HW_PATH               16#820F  // get the hardware path of the module (VARAN Path)
#define _BUS_IF_SET_REQUIRED_ERROR        16#8210  // set required error to next instance
#define _BUS_IF_CREATE_MUTEX              16#8211  // creates mutex with specified name
#define _BUS_IF_SET_REQUIRED              16#8212  // sets the businterface to required (if possible)
#define _BUS_IF_GET_DEACTIVATED_STATE     16#8213  // gets the state of deactivation
#define _BUS_IF_GET_OBJECT_THIS_PTR       16#8214  // get object this pointer via hardware path
#define _BUS_IF_WRITE_VIA_SDO             16#8215  // send SDO write memory command
#define _BUS_IF_READ_VIA_SDO              16#8216  // send SDO read memory command
#define _BUS_IF_ADD_MOVE_DO               16#8217  // Add a Move data object
#define _BUS_IF_UPDATE_MOVE_DO            16#8218  // Update a Move data object
#define _BUS_IF_GET_INTERFACE_TYPE        16#8219  // Get the type of the interface (VARAN, Local, SDIAS,...)
#define _BUS_IF_IS_VARAN_AVAILABLE        16#821A  // Check if it's behind a VARAN Module and we can use the Move-CMD
#define _BUS_IF_GET_ACCESS_INFO           16#821B  // get everything that's needed to create a move command
#define _BUS_IF_GET_NODE_HANDLE           16#821C  // get node handle to use OS interface for SDIAS
#define _BUS_IF_DO_CREATION_FINISHED      16#821D  // tell the bus manager we are finished with creating our DOs
#define _BUS_IF_DO_MEM_READY              16#821E  // ask the bus manager if all post-init modules are finished with creating their DOs
#define _BUS_IF_SET_ERROR                 16#821F  // set any error to next instance (1st parameter of type t_e_varanerrors, 2nd pointer to string which is added to service provider if not NIL)
#define _BUS_IF_GET_REQUIRED_SETTING      16#8220  // check if the bus interface instance is set required (client set to 1 or set via other circumstances in init)
#define _BUS_IF_MOVE_DO_CREATION_FINISHED 16#8221  // tell the bus manager we are finished with creating our Move DOs
#define _BUS_IF_MOVE_DO_MEM_READY         16#8222  // ask the bus manager if all post-init modules are finished with creating their move DOs
#define _BUS_IF_TRIGGER_ISO_TASK          16#8223  // start the iso task (needed for watchdog trigger of sdias on local SDIAS during initialisation)
#define _BUS_IF_GET_BUS_READY_AVAILABLE   16#8224  // check if the bus ready interface is available
#define _BUS_IF_LOG_ERROR_MSG             16#8225  // Logs an Error Message
#define _BUS_IF_LOG_VALUES                16#8226  // Logs Values
#define _BUS_IF_ADD_RESET_DETECTION_4_DO  16#8227  // select a DO which can be used to detect a periphery reset at the hardware (preferably one that is always enabled)
#define _BUS_IF_SET_CLASS_STATE           16#8228  // Set the ClassState of the BusInterface, type is t_e_VaranErrors
#define _BUS_IF_GET_CLASS_STATE           16#8229  // Get the ClassState of the BusInterface, type is t_e_VaranErrors
#define _BUS_IF_SET_PARAM                 16#822A  // Set Parameter 
#define _BUS_IF_GET_PARAM                 16#822B  // Get Parameter like Serial Number, FPGA Version, DeviceID, Retry Counter ....
#define _BUS_IF_SET_SYNC_DIVIDER          16#822C  // Sets sync data for the passed sync and divider setting
#define _BUS_IF_WRITE_VIA_SDO_CTRL        16#822D  // send SDO write control command
#define _BUS_IF_READ_VIA_SDO_CTRL         16#822E  // send SDO read control command
#define _BUS_IF_RT_SYNC_READY             16#822F  // the module is ready with syncing the modules in rt


// Commands that the Bus IF sends
// Commands id range from 0x8230 to 0x823F
#define _BUS_IF_HWCONNECT                 16#8230
#define _BUS_IF_HWDISCONNECT              16#8231
#define _BUS_IF_HWINTERRUPT               16#8232
#define _BUS_IF_CHECK_DEVICE_ID           16#8233
#define _BUS_IF_INIT_ACCESSES             16#8234
#define _BUS_IF_INIT_MODULE               16#8235
#define _BUS_IF_SDO_RESPONSE              16#8236
#define _BUS_IF_DATA_POINTER_AVAILABLE    16#8237
#define _BUS_IF_GET_TASK_INFO             16#8238
#define _BUS_IF_POST_INIT_RT_READY        16#8239
#define _BUS_IF_HWSUB_BUS_READY           16#823A
#define _BUS_IF_RESET_DETECTED            16#823B
#define _BUS_IF_RESET_GONE_DETECTED       16#823C

// other defines
#define _BUS_IF_INVALID_DO_HANDLE       16#FFFFFFFF



// Commands for _BUS_IF_SET_PARAM and _BUS_IF_GET_PARAM
#define _BUS_IF_DEVICEADDRESS          0
#define _BUS_IF_DEVICEID               1
#define _BUS_IF_VENDORID               2
#define _BUS_IF_SERIALNO_LENGTH        3
#define _BUS_IF_SERIALNO_DATA          4
#define _BUS_IF_FPGA_VERSION           5
#define _BUS_IF_RETRYCOUNTER           6
#define _BUS_IF_HW_VERSION             7
#define _BUS_IF_DEVICEID_DIAGNOSIS     8
#define _BUS_IF_DISABLE_DEVICE         9
#define _BUS_IF_ENABLE_DEVICE         10

    
//*****************************************************************************
//** TYPES                                                                   **
//*****************************************************************************

	TYPE
    
    t_BusIFRetvalErrorcode :
    (
      _BUS_IF_RETVAL_OK,
      _BUS_IF_RETVAL_ERROR_DO_LIST_FULL,
      _BUS_IF_RETVAL_ERROR_CREATE_DO_FAILED,
      _BUS_IF_RETVAL_ERROR_INVALID_POINTER,
      _BUS_IF_RETVAL_ERROR_INVALID_HANDLE,
      _BUS_IF_RETVAL_ERROR_UPDATEDO_DOLENGTH,
      _BUS_IF_RETVAL_ERROR_BUSCYCLE_TIME_NOT_AVAILABLE,
      _BUS_IF_RETVAL_ERROR_INVALID_SYNC,
      _BUS_IF_RETVAL_ERROR_INVALID_DATA,
      _BUS_IF_RETVAL_ERROR_NOT_SUPPORTED,
      _BUS_IF_RETVAL_ERROR_CREATE_MUTEX_FAILED,
      _BUS_IF_RETVAL_ERROR_DIRECT_ACCESS_FAILED,
      _BUS_IF_RETVAL_ERROR_MOVE_DO_LIST_FULL,
      _BUS_IF_RETVAL_ERROR_CREATE_MOVE_DO_FAILED,
      _BUS_IF_RETVAL_ERROR_UPDATE_MOVE_DO_FAILED,     
      _BUS_IF_RETVAL_ERROR_NO_CALLBACK_INSTALLED
    )$UDINT;
  
    t_BusIFRDWR :
    (
      _BUS_IF_READ,
      _BUS_IF_WRITE,
      _BUS_IF_READ_WRITE
    )$UINT;
    
    t_BusIFRunState :
    (
      _BUS_IF_RUN_STATE_NO_RUN,
      _BUS_IF_RUN_STATE_SINGLE_RUN,
      _BUS_IF_RUN_STATE_CONT_RUN
    )$USINT;
    
    t_BusIFPriority :
    (
      _BUS_IF_ISO,
      _BUS_IF_ASY,
      _BUS_IF_ISO_MOVE,   // DO needs special priority because it is part of a Move DO (Source, Move or Destination)
      _BUS_IF_ASY_MOVE    // DO needs special priority because it is part of a Move DO (Source, Move or Destination)
    )$UINT;
    
    t_DOCfg : STRUCT
      pHandle           : PLSL_VARANFRAME;
      pDataRead         : ^void;
      pDataWrite        : ^void;
      lengthRead        : UINT;
      lengthWrite       : UINT;
      maxLengthRead     : UINT;    // Maximum length of DO, defined on creation
      maxLengthWrite    : UINT;    // Maximum length of DO, defined on creation  
      AddrOffsetRead    : HDINT;
      AddrOffsetWrite   : HDINT;
      RdWr              : t_BusIFRDWR;
      Priority          : t_BusIFPriority;
      OldRetryCounter   : USINT;
      Enable            : USINT;
      EnableFlag        : USINT;      
      PreScaler         : USINT;    // Needs to be saved because it will not be readable in the future.
      IsLongDO          : BOOL;
      pLongDOSettings   : ^t_VaranDOSettingsLong;
      b_DOIsRunning     : t_SingleRunState;
      b_DOIsChangable   : BOOL;
      pLocalRdMem       : ^void;
      pLocalWrMem       : ^void;
    END_STRUCT;
    
    t_DOMoveCfg : STRUCT
      pHandle           : PLSL_VARANFRAME;      
      sourceDOHandle    : UDINT;
      pSourceDOData     : ^void;
      sourceDOOffset    : UDINT;
      destDOHandle      : UDINT;
      pDestDOData       : ^void;
      destDOOffset      : UDINT;
      lengthMove        : UINT;
      lengthMoveMax     : UINT;
      Priority          : t_BusIFPriority;       
      b_DOIsRunning     : t_SingleRunState;
      p_MovSettings  : ^t_VaranDOSettingsMov; // poiter into DPRAM      
    END_STRUCT;
    
    t_SDIASDOCfg : STRUCT
      pControlByte      : ^t_SDIAS_ControlByte;
      pStatusByte       : ^t_SDIAS_StateByte;
      pDataRead         : ^void;
      pDataWrite        : ^void;
      lengthRead        : UINT;
      lengthWrite       : UINT;
      AddrOffsetRead    : HDINT;
      AddrOffsetWrite   : HDINT;
      RdWr              : t_BusIFRDWR;
      Priority          : t_BusIFPriority;
      Enable            : USINT;
      EnableFlag        : USINT;      
      b_DOIsRunning     : t_SingleRunState;
      AccessHandle      : UDINT;
    END_STRUCT;
    
    // Struct for the ADD CALLBACK command
    t_BusIFAddCallback : STRUCT
    
      pthis : pVirtualBase;   
      
    END_STRUCT;
    
    // Struct for the ADD DO command    
    t_AddDOCfg : STRUCT

      ui_length_read      : UINT;
      ud_addressoff_read  : HDINT;
      
      ui_length_write     : UINT;      
      ud_addressoff_write : HDINT; 
      
      RdWr                : t_BusIFRDWR;
      Priority            : t_BusIFPriority ;
      
      b_DOIsChangable     : BOOL;
      // if these pointers are available, the return-values (pDataRead/pDataWrite) are not being used
      ppDataRead : pVoid;
      ppDataWrite : pVoid;
      
      ud_WaitForAccessHandle  : UDINT;  // pointer on internal access element => 0 = INVALID
      b_UseLocalCopy : BOOL;
    END_STRUCT;
    
    // Struct for the ADD DO return value    
    t_AddDORet : STRUCT

      retcode       : t_BusIFRetvalErrorcode;
      sd_retval     : DINT;
       
      Handle        : UDINT;
      
      pDataRead     : ^void;      
      pDataWrite    : ^void; 
      
      AccessHandle  : UDINT;
    END_STRUCT;
    
    // Struct for the UPDATE DO command
    t_UpdateDOCfg : STRUCT
      Handle              : UDINT;
      
      ud_length_read      : UINT;
      ud_addressoff_read  : HDINT;
      
      ud_length_write     : UINT;      
      ud_addressoff_write : HDINT;      
    END_STRUCT;
    
    // Struct for the RESET DO command
    t_ResetDOCfg : STRUCT
      Handle              : UDINT;
    END_STRUCT;
    
    
    // Struct for the ADDTASK command
    t_TaskCfg : STRUCT
      Priority      : t_BusIFPriority;
      pthis         : UDINT;
      callOptions   : USINT;
    END_STRUCT;
    
    // Struct for the RDDO and WRDO command
    t_RDWRDOCfg : STRUCT
      ud_AddOffset  : HDINT;
      ud_length     : UDINT;
      p_ud_data     : ^void;
    END_STRUCT;    

    // Struct for the Set run state command
    t_SetRunStateCfg  : STRUCT
      handle          : UDINT;
      newRunState     : t_BusIFRunState;
    END_STRUCT;

    // Struct for the Set online Server command
    t_SetOnlineCfg  : STRUCT
      val             : DINT;   // New Server value
    END_STRUCT;
    
    // Struct for the GetBusCycleTime (Return Value)
    t_GetBusCycleTime  : STRUCT
      retcode         : t_BusIFRetvalErrorcode;
      udBusCycleTime  : UDINT;  // [ns]
      udIsoStartPoint : UDINT;  // [ns]
      udMainTimer     : UDINT;  // [us]
    END_STRUCT;
    
    // Struct for _BUS_IF_SET_DO_PRESCALER
    t_SetDoPrescaler  : STRUCT 
      Handle          : UDINT;
      
      Prescaler       : USINT;
    END_STRUCT;

    // Struct for _BUS_IF_SET_TASKS_PRESCALER
    t_TaskPreScaler : STRUCT
      Prescaler         : USINT;
      RtPreScanTrigger  : USINT;
      RtPostScanTrigger : USINT;
      CyTrigger         : USINT;      
    END_STRUCT;
    
    // Struct for _BUS_IF_SET_SYNC
    t_SyncData   : STRUCT 
      us_sync_nr 	            : USINT;
      sd_offset 	            : DINT;
      us_period_multiplier 	  : USINT;
      us_frame_count_threshold : USINT;
      us_enable_frame_count 	: USINT;
      b_use_divider_sync      : BOOL;
    END_STRUCT;
    
    // Struct for the _BUS_IF_SEND_SDIAS_SDO_REQUEST command
    t_SDIASSDORequest : STRUCT
      ud_Command          : UDINT;
      ud_SDIAS_Addr       : HDINT;
      ud_DataLength       : UDINT;
      p_RequestBuffer     : ^void;
      p_SDO_Handle        : ^UDINT;      
    END_STRUCT;

    // Struct for the _BUS_IF_GET_SDIAS_SDO_RESPONSE command
    t_SDIASSDOResponse : STRUCT
      ud_SDO_Handle       : UDINT;
      ud_BufferLength     : UDINT;
      p_ResponseBuffer    : ^void;
      p_ResponseLength    : ^UDINT;
    END_STRUCT;
    
     // Struct for the ADD MOVE DO command    
    t_AddMoveDOCfg : STRUCT

      ud_length_move      : UINT;
      
      ud_handle_source      : UDINT;
      ud_addressoff_source  : HDINT;
      p_sourcedata           : ^void;
      
      ud_handle_dest     : UDINT;
      ud_addressoff_dest : HDINT;
      p_destdata         : ^void;
      
      Priority            : t_BusIFPriority ;      
      
    END_STRUCT;
    
    // Struct for the ADD DO return value    
    t_AddMoveDORet : STRUCT

      retcode       : t_BusIFRetvalErrorcode;
      sd_retval     : DINT;
       
      Handle        : UDINT;
      
    END_STRUCT;
    
    // Struct for the UPDATE Move DO command
    t_UpdateDOMoveCfg : STRUCT
      Handle              : UDINT;
      
      ud_length_move      : UINT;
      
      ud_handle_source      : UDINT;
      ud_addressoff_source  : HDINT;
      p_sourcedata           : ^void;
      
      ud_handle_dest     : UDINT;
      ud_addressoff_dest : HDINT;
      p_destdata         : ^void;     
      
    END_STRUCT;    

    // Return Struct for the access info command
    t_AccessInfoRet : STRUCT
      retcode       : t_BusIFRetvalErrorcode;
      ud_handle      : UDINT;
      ud_addressoff  : HDINT;
      p_dataDPRAM    : ^void;      
    END_STRUCT;    
    
    // Struct for the Logg Error info command
    t_LogErrorMsg : STRUCT
      e_msg 	      : ^CHAR;
      p_extThis1 	  : pVirtualBase;
      p_extThis2 	  : pVirtualBase;     
    END_STRUCT; 
    
    // Struct for the Logg Value info command
    t_LogValue      : STRUCT
      e_msg 	      : ^CHAR;
      p_extThis 	  : pVirtualBase;
      val1 	        : UDINT;
      val2 	        : UDINT;
      val3 	        : UDINT;      
    END_STRUCT;     

    t_BusIFType :
    (
      _BUS_IF_TYPE_VARAN,
      _BUS_IF_TYPE_SDIAS,
      _BUS_IF_TYPE_LOCAL
    )$UDINT;

  END_TYPE 
#endif