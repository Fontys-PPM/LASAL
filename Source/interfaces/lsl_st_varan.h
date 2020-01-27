(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_varan.h                                                                       *)
(*                                                                                      *)
(* enthält die Definitionen für das VARAN Interface                                     *)
(*                                                                                      *)
(* HH                                                                                   *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
//HFILTER:1
#ifndef __LSL_ST_VARAN
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define __LSL_ST_VARAN



//
// Defines
//

// Interfaces
#define INTERFACE_VARANMANAGER                  "IVARANMANAGER"
#define INTERFACE_MULTIVARANMANAGER             "IMULTIVARANMANAGER"

// Ergebniscodes
#define VARANMANAGER_OK                                   0
#define VARANMANAGER_DRIVER_NOT_EXISTS                   -1
#define VARANMANAGER_DOL_TYPE_WRONG                      -2
#define VARANMANAGER_RUN_STATUS_WRONG                    -3
#define VARANMANAGER_DO_HANDLE_INVALID                   -4
#define VARANMANAGER_DO_RAM_FULL                         -5
#define VARANMANAGER_DO_CMD_INVALID                      -6
#define VARANMANAGER_MANAGER_NOT_EXISTS                  -7
#define VARANMANAGER_DOL_ADDRESS_INVALID                 -8
#define VARANMANAGER_UNKNOWN_COMMAND                     -9
#define VARANMANAGER_COMPONENT_NOT_EXISTS               -10
#define VARANMANAGER_CLIENT_NOT_EXISTS                  -11
#define VARANMANAGER_CDIAS_EEPROM_NOT_EXISTS            -12
#define VARANMANAGER_CDIAS_EEPROM_NO_GRANT              -13
#define VARANMANAGER_CDIAS_EEPROM_NACK                  -14
#define VARANMANAGER_PORT_NOT_EXISTS                    -15
#define VARANMANAGER_PORT_IS_UPLINK                     -16
#define VARANMANAGER_PORT_NO_LINK                       -17
#define VARANMANAGER_NO_MUTEX                           -18
#define VARANMANAGER_NO_TASK                            -19
#define VARANMANAGER_ID_NOT_FOUND                       -20
#define VARANMANAGER_ID_NOT_INITIALIZED                 -21
#define VARANMANAGER_INVALID_DEVICE_ADDRESS             -22
#define VARANMANAGER_CALLBACK_NOT_HANDLED               -23
#define VARANMANAGER_NO_MEM                             -24
#define VARANMANAGER_NO_LEGACY_WD                       -25
#define VARANMANAGER_ADMIN_DOL_EXECUTION_ERROR          -26
#define VARANMANAGER_DA_DOL_EXECUTION_ERROR             -27
#define VARANMANAGER_SPI_FLASH_NO_ACCESS                -28
#define VARANMANAGER_CLIENT_NOT_READY                   -29
#define VARANMANAGER_CLIENT_DISABLED                    -30
#define VARANMANAGER_CLIENT_CANT_ENABLE                 -31
#define VARANMANAGER_CDIAS_ADDRESS_INVALID              -32
#define VARANMANAGER_SPI_FLASH_INVALID                  -33
#define VARANMANAGER_SPI_DOL_ID_INVALID                 -34
#define VARANMANAGER_SPI_DOL_INVALID                    -35
#define VARANMANAGER_SPI_REQUIRED_LIST_ERROR            -36
#define VARANMANAGER_SPI_CHKSUM_ERROR                   -37
#define VARANMANAGER_PARAMETER_INVALID                  -38
#define VARANMANAGER_DO_TYPE_NOT_SUPPORTED              -39
#define VARANMANAGER_DMA_ERROR                          -40
#define VARANMANAGER_PROPERTY_ID_INVALID                -41
#define VARANMANAGER_PROPERTY_VALUE_INVALID             -42
#define VARANMANAGER_DO_NUMBER_OVERFLOW                 -43
#define VARANMANAGER_API_USAGE_NOT_ALLOWED              -44
#define VARANMANAGER_NODE_TYPE_WRONG                    -45
#define VARANMANAGER_DATA_LENGTH_INVALID                -46
#define VARANMANAGER_DO_TYPE_INVALID                    -47
#define VARANMANAGER_OPERATION_NOT_ALLOWED              -48
#define VARANMANAGER_NODE_NUMBER_OVERFLOW               -49
#define VARANMANAGER_NO_HANDLE_FOUND                    -50
#define VARANMANAGER_INVALID_DO_PRIORITY                -51
#define VARANMANAGER_NO_MAILBOX                         -52
#define VARANMANAGER_PLL_SYNC_OUT_ID_INVALID            -53

//
// Max Anzahl Hubs
//
#define VARAN_MAX_DEPTH                         255


//
// Callback reason
//

// device connnect
#define VARANMANAGER_CB_CONNECT                 0

// device disconnect
#define VARANMANAGER_CB_DISCONNECT              1

// required DO error
#define VARANMANAGER_CB_REQ_ERROR               2

// not required DO error
#define VARANMANAGER_CB_NOT_REQ_ERROR           3

// fatal error on DO
#define VARANMANAGER_FATAL_ERROR                4

// time slice error
#define VARANMANAGER_CB_TIME_SLICE_ERROR        5

// watchdog error
#define VARANMANAGER_CB_WATCHDOG_ERROR          6

// client IRQ
#define VARANMANAGER_CB_CLIENT_IRQ              7

// device enable
#define VARANMANAGER_CB_ENABLE                  8

// device disable
#define VARANMANAGER_CB_DISABLE                 9

// irq task interrupt
#define VARANMANAGER_CB_IRQ_TASK               10

// Varan Manager Client Wechselbuffer DA Interrupt
#define VARANMANAGER_CB_VMC_BUF_DA             12

// dias error (on CIV521 or DIV511)
#define VARANMANAGER_CB_DIAS_ERROR             13

// cdias error (CDIAS Module required behind a CIV)
#define VARANMANAGER_CB_CDIAS_ERROR            14

// VARAN interface version 0x00001109

// sub buses of varan interface module initialized (e.g. VI021)
#define VARANMANAGER_CB_SUB_BUSES_INITIALIZED  15

//
// DO Types
//

// Standard DO
#define VARAN_DO_TYPE_STANDARD                      0x00

// Long DO
#define VARAN_DO_TYPE_LONG                          0x01

// IRQ DO
#define VARAN_DO_TYPE_IRQ                           0x02

// Standard DO with payload pointer
#define VARAN_DO_TYPE_STANDARD_PAYLOAD              0x03

// IRQ DO with payload pointer
#define VARAN_DO_TYPE_IRQ_PAYLOAD                   0x04

// Move/copy DO
#define VARAN_DO_TYPE_MOVE_COPY                     0x10

// Latch time up counter
#define VARAN_DO_TYPE_LATCH_TIME_UP_COUNTER         0x11

// Latch time up counter between PLL ticks
#define VARAN_DO_TYPE_LATCH_TIME_UP_COUNTER_PLL     0x12

// Move/copy DO with payload pointer
#define VARAN_DO_TYPE_MOVE_COPY_PAYLOAD             0x13

// "Wait for Event"-DO (DO type only exists in variant with payload pointer)
#define VARAN_DO_TYPE_EVENT_PAYLOAD                 0x14


//
// DOL Types
//

// highest priority DOL, ISO
#define VARAN_DOL_DA                            0x0001

// ISO - must finisch in one frame, interrupts ASY
#define VARAN_DOL_ISO                           0x0002

// ASY - no length and no time constraints, interrupts ADMIN
#define VARAN_DOL_ASY                           0x0003

// for foreign traffic, mostly executed by the OS
#define VARAN_DOL_ADMIN                         0x0004

// for foreign traffic, mostly executed by the OS
#define VARAN_DOL_IRQ                           0x0005

// create DO but don't insert it into DOL
// (supported by LSL_MULTI_VARAN from version 01.00.003)
#define VARAN_DOL_NOT_INSERT_DO_INTO_DOL        0x80000000

//
// DOL Execution type
//

// don't wait for completion - default
#define VARAN_DOL_EXECUTE_NOWAIT    0x00000000

// wait for completion
#define VARAN_DOL_EXECUTE_WAIT      0x80000000



//
// DO Run Status
//

// nicht aktiv
#define VARAN_DO_NO_RUN       0x00

// single
#define VARAN_DO_SINGLE_RUN   0x01

// continous
#define VARAN_DO_CONT_RUN     0x02

// required
#define VARAN_DO_REQUIRED     0x04

// execute until FIFO empty
#define VARAN_DO_EXECUTE_FIFO_EMPTY   	0x08


//
// Device requireness
// 

// default
#define VARAN_DEVICE_DEFAULT  0

// required
#define VARAN_DEVICE_REQUIRED 1



//
// Device Status (tagVARANNODE->ucStatus)
//

// Port wurde disabled
#define VARAN_DEVICE_DISABLED     0x01

// Fehler im SPI-Flash (Checksumme falsch)
#define VARAN_DEVICE_NOT_READY    0x02

// Fehler im SPI-Flash (Checksumme falsch)
#define VARAN_DEVICE_SPI_ERROR    0x04



//
// Commands & SubCommands
//

// Global Write
#define VARAN_CMD_GLOBAL_WRITE              0x00
#define VARAN_CMD_GLOBAL_WRITE_SYNC         0x01
#define VARAN_CMD_GLOBAL_WRITE_RESET        0x02
#define VARAN_CMD_GLOBAL_WRITE_CLEAR        0x03
#define VARAN_CMD_GLOBAL_WRITE_WD           0x04

// Memory Read
#define VARAN_CMD_MEMORY_READ               0x10

// Memory Write
#define VARAN_CMD_MEMORY_WRITE              0x20

// Memory Read Write
#define VARAN_CMD_MEMORY_READ_WRITE         0x30

// Control Read
#define VARAN_CMD_CONTROL_READ              0x40

// Control Write
#define VARAN_CMD_CONTROL_WRITE             0x50

// Control Read Write
#define VARAN_CMD_CONTROL_READ_WRITE        0x60

// Foreign Packet Request
#define VARAN_CMD_FOREIGN_PACKET_REQ        0x70

// Foreign Packet Response
#define VARAN_CMD_FOREIGN_PACKET_RESPONSE   0x80

// Multiple Memory Read Write
// AddDotoDOL:
//  Byte 0 (Bits 0-7):    0x90
//  Byte 1 (Bits 8-15):   Filter
//  byte 2 (Bits 16-23):  max. Anzahl der Clients
#define VARAN_CMD_MULTIPLE_MEMORY_RW        0x90

// Foreign Packet
#define VARAN_CLIENT_FP_SAFETY				0x01C2

//
// Foreign Packet Constants
//
#define VARAN_FPR_SAFETY_ID					2

// align auf 1 Byte erzwingen
#pragma pack(push, 1)


// 
// VARAN Node Info Block
//
TYPE
  LSL_VARANNODEINFO : STRUCT

  // Länge des Header - inkl. Feld "uiLenHeader"
  uiLenHeader : UDINT;

  // Address
  uiAddress : UDINT ;

  // Status Info
  ucStatus : USINT;

  // Ports
  ucPorts : USINT;

  // FPGA version
  ucFPGAVersion : USINT;

  // reseved
  ucReserved2 : USINT;

  // VendorID
  uiVendorID : UDINT;

  // DeviceID;
  uiDeviceID : UDINT;

  // Response Time
  uiResponseTime : UDINT;

  // Response Time Maximum
  uiResponseTimeMax : UDINT;

  // Link-Stati der Downlink-Ports
  uiLinks : UDINT;

  END_STRUCT;
END_TYPE

// Zeiger auf Struktur - wegen Parameter
TYPE
  PLSL_VARANNODEINFO : ^LSL_VARANNODEINFO;
END_TYPE



//
// VARAN Frame
//
TYPE
  LSL_VARANFRAME : STRUCT

  // DO type
  ucDOType : USINT;

  // Control / Status
  ucCtrlStat : USINT;

  // Execution Prescaler
  ucExePrescaler : USINT;

  // Execution Prescaler Counter
  ucExePrescalerCnt : USINT;

  // next Frame
  pNext : ^LSL_VARANFRAME;

  // Pointer to Device Data
  pDeviceData : UDINT;

  // Error Info
  uiErrorInfo : UDINT;

  // allowed retrys
  ucRetrys : USINT;

  // Retry Counter
  ucRetryCounter : USINT;

  // unsigned short receive buffer length
  usReserved1 : UINT;

  // retry timeout
  uiRetryTimeout : UDINT;

  // unsigned short Send buffer length
  usSendBufferLength : UINT;

  // length of expected answer
  usLengthofExpAnswer : UINT;

  // response time
  uiResponseTime : UDINT;

  END_STRUCT;
END_TYPE


// Zeiger auf Struktur - wegen Parameter
TYPE
  PLSL_VARANFRAME : ^LSL_VARANFRAME;
END_TYPE

//
// VARAN Frame PayloadMove Header
// For debug casting
//
TYPE
  LSL_VARANFRAMEMOVEHEADER : STRUCT

  // DO type
  ucDOType : USINT;

  // Control / Status
  ucCtrlStat : USINT;

  // Execution Prescaler
  ucExePrescaler : USINT;

  // Execution Prescaler Counter
  ucExePrescalerCnt : USINT;

  // next Frame
  pNext : UDINT;

  // Pointer to Device Data
  pDeviceData : UDINT;

  // Error Info
  uiErrorInfo : UDINT;
  
  // Destination pointer
  puiDestination : ^UDINT;
  
  // Source pointer
  puiSource : ^UDINT;
  
  // Number of Bytes
  usByteCount : UINT;
  
  END_STRUCT;
END_TYPE

//
// VARAN Frame Payload Header
// For debug casting
//
TYPE
  LSL_VARANFRAMEPAYLOADHEADER : STRUCT

  // DO type
  ucDOType : USINT;

  // Control / Status
  ucCtrlStat : USINT;

  // Execution Prescaler
  ucExePrescaler : USINT;

  // Execution Prescaler Counter
  ucExePrescalerCnt : USINT;

  // next Frame
  pNext : UDINT;

  // Pointer to Device Data
  pDeviceData : UDINT;

  // Error Info
  uiErrorInfo : UDINT;

  // allowed retrys
  ucRetrys : USINT;

  // Retry Counter
  ucRetryCounter : USINT;

  // unsigned short receive buffer length
  usReserved1 : UINT;

  // retry timeout
  uiRetryTimeout : UDINT;

  // unsigned short Send buffer length
  usSendBufferLength : UINT;

  // length of expected answer
  usLengthofExpAnswer : UINT;

  // response time
  uiResponseTime : UDINT;
  
  // Offset in DPRam on Write Payload DO
  usOffsetWritePayload : HINT; 
  
  // Length in DPRam of Write Payload DO
  usLengthWritePayload : UINT;
  
  // Offset in DPRam on Read Payload DO
  usOffsetReadPayload : HINT;
  
  // Length in DPRam of Read Payload DO
  usLengthReadPayload : UINT;
  
  // Data Object Command
  ucCommand :HSINT;
  
  // Data Object Filter
  ucDOFilter : HSINT;
  
  // Data Object Slices
  ucDOSlices : HSINT;
  
  // Data Object Command Address
  uiDOCommandAddr : HDINT;
  
  // Data Object Command Byte Count
  ucDOByteCount : UINT;
  
  // Data Object Command Address
  uiDOCommandAddrRW : HDINT;
  
  // Data Object Command Byte Count
  usDOByteCountRW : UINT;
  
  END_STRUCT;
END_TYPE

//
// VARAN Frame Write Payload DO
// Read is only 1 Status Byte
// For debug casting
//
TYPE
  LSL_VARANFRAMEWRITEPAYLOAD : STRUCT

  // Control
  ucControl : BSINT;
  
  // Retry timeout in ns
  uiRetryTimeout : UDINT;
  
  // Send buffer length
  usSendBufferLength : UINT;
   
  // Length of expected answer
  usLengthofExpAnswer : UINT;
  
  // Data Object Command Address
  uiDOCommandAddr : HDINT;
  
  // Data Object Command Byte Count
  ucDOByteCount : UINT;
  
  // Data Object Command Address
  uiDOCommandAddrRW : HDINT;
  
  // Data Object Command Byte Count
  usDOByteCountRW : UINT;
  
  END_STRUCT;
END_TYPE

//
// VARAN Frame PayloadMove Header
// For debug casting
//
TYPE
  LSL_VARANFRAMEPAYLOADMOVEHEADER : STRUCT

  // DO type
  ucDOType : USINT;

  // Control / Status
  ucCtrlStat : USINT;

  // Execution Prescaler
  ucExePrescaler : USINT;

  // Execution Prescaler Counter
  ucExePrescalerCnt : USINT;

  // next Frame
  pNext : UDINT;

  // Pointer to Device Data
  pDeviceData : UDINT;

  // Error Info
  uiErrorInfo : UDINT;
  
  // Offset in DPRam on Write Payload DO
  usOffsetWriteDO : HINT;
  
  // Length in DPRam of Write Payload DO
  usLengthWriteDO : UINT;
  
  // Offset in DPRam on Read Payload DO
  usOffsetReadDO : HINT;  
  
  // Length in DPRam of Read Payload DO
  usLengthReadDO : UINT;  
  
  END_STRUCT;
END_TYPE

//
// VARAN Frame PayloadMove Write DO
// Read is only 1 Status Byte
// For debug casting
//

TYPE
  LSL_VARANFRAMEMOVEWRITEPAYLOAD : STRUCT
  
  // Control
  ucControl : BSINT;
  
  // Destination pointer
  puiDestination : ^UDINT;
  
  // Source pointer
  puiSource : ^UDINT;
  
  // Number of Bytes
  usByteCount : UINT;
  
  END_STRUCT;
END_TYPE

//
// TaskControl / Status
//
TYPE
  LSL_TASKCONTROLSTATUS : STRUCT

  // Frame
  pFrames : ^LSL_VARANFRAME;

  // Handshake
  ucHandshake : USINT;

  // Reserved
  ucReserved1 : array [1..3] of USINT;

  // Task Time up counter
  uiTTUpCounter : UDINT;

  // Reserved
  uiReserved2 : UDINT;    

  END_STRUCT;
END_TYPE



//
// Error Info
//
TYPE
  LSL_ERRORINFO : STRUCT

  // Pointer on DO
  uiErrDO : UDINT;

  // Error task
  ucErrTask : USINT;

  // Reserved
  ucReserved1 : array [1..3] of USINT;

  // Error Info
  uiErrorInfo : UDINT;

  // Reserved
  ucReserved2 : array [1..4] of USINT;

  END_STRUCT;
END_TYPE



// 
// CONTROL Block
//
TYPE
  LSL_CONTROLBLOCK : STRUCT

  // 
  // Task Control / Status Area - Offset 0x00
  //

  // Task Control / Status DA
  sDA : LSL_TASKCONTROLSTATUS;

  // Task Control / Status ISO
  sISO : LSL_TASKCONTROLSTATUS;

  // Task Control / Status ASY
  sASY : LSL_TASKCONTROLSTATUS;

  // Task Control / Status ADMIN
  sAdmin : LSL_TASKCONTROLSTATUS;

  // Task Control / Status Reserved
  sIRQ : LSL_TASKCONTROLSTATUS;

  //
  // Control / Status Area - Offset 0x60
  //

  // Time up Counter
  uiTUpCounter : UDINT;

  // Task Control Enable
  ucTCEnable : USINT;

  // reserved
  ucReserved2 : array [1..3] of USINT;

  // Time Up COunter between PLL ticks
  uiTUpCounterBPLLTicks : UDINT;

  // ISO Start Point
  uiIsoStartPoint : UDINT;

  // Task priority switch
  uiTaskPrioSwitchADMIN : UDINT;

  // maximum Time for command execution
  uiMaxTimeCmdExecution : UDINT;

  // DPRAM size
  uiDPRAMSize : UDINT;
  
  // Pointer on program RAM
  uiDPRAMBaseAddress : UDINT;

  //
  // IRQ / Errorhandling - Offset 0x90
  //

  // global retry Counter
  ucGlobalretryCounter : USINT;

  // Reserved
  ucReserved5 : array [1..3] of USINT;

  // Manager IRQ
  ucManagerIRQ : USINT;

  // IRQ Enable for Task Executed
  ucIRQEnTE : USINT;

  // IRQ Quit for Task Executed
  ucIRQQuitTE : USINT;

  // Reserved
  ucReserved6 : array [1..9] of USINT;

  //
  // Error Info
  //

  // Required frame
  sErrRequired : LSL_ERRORINFO;

  // Not Required
  sErrNotRequired : LSL_ERRORINFO;

  // Fatal
  sErrFatal : LSL_ERRORINFO;

  END_STRUCT;
END_TYPE


// Zeiger auf Struktur - wegen Parameter
TYPE
  PLSL_CONTROLBLOCK : ^LSL_CONTROLBLOCK;
END_TYPE



//
// VARAN PLL Sync Out
//
TYPE
  LSL_VARANPLLSYNCOUT : STRUCT

  // Offset
  aucOffset : array [1..3] of USINT ;

  // Reserved
  ucReserved1 : USINT;

  // Period Multiplier
  ucPeriodMultiplier : USINT;

  // Frame Count Threshold
  ucFrameCountThreshold : USINT;

  // Reserved
  ucSyncOutID : USINT;

  // Control/Status Register
  ucControlStatus : USINT;

  END_STRUCT;
END_TYPE



//
// VARAN PLL
//
TYPE
  LSL_VARANPLL : STRUCT

  // System  Time Period in 10ns units
  aucPeriod : array [1..3] of USINT;

  // Reserved
  aucReserved1 : array [1..5] of USINT;

  // Sync Time Frame Counter
  ucSyncTimeFrameCounter : USINT;

  // IRQ Register
  ucIRQ : USINT;

  // Control/Status Register
  ucControlStatus : USINT;

  // max. Cuunt Missing PLL Input Sync
//  ucMaxMissSync : USINT;

  //new Pll has divider
  ucSystemPeriodDivider : USINT;


  // Device Delay Time
  aucDeviceDelayTime : array [1..3] of USINT;

  // Reserved
  ucReserved : USINT;

  // Sync Out CPU
  sSynOutCPU : LSL_VARANPLLSYNCOUT;

  // Sync Out Peripheral 1
  sSynOutPeripheral1 : LSL_VARANPLLSYNCOUT;

  // Sync Out Peripheral 2
  sSynOutPeripheral2 : LSL_VARANPLLSYNCOUT;

  // Sync Out Peripheral 3
  sSynOutPeripheral3 : LSL_VARANPLLSYNCOUT;

  END_STRUCT;
END_TYPE


// Zeiger auf Struktur - wegen Parameter
TYPE
  PLSL_VARANPLL : ^LSL_VARANPLL;
END_TYPE


#pragma pack(pop)


//
// Interface
//
TYPE
  LSL_VARAN : STRUCT

  //
  // Version
  //
  udVersion : UDINT;

  //
  // Funcs
  //

  // manager online commands
  iManagerCommands : pVoid;

  // initialize App
  iInitApp : pVoid;

  // not for application
  iReserved2 : pVoid;

  // add one DO to DOL
  iAddDOtoDOL : pVoid;

  // clear DOL
  iClearDOL : pVoid;

  // execute DOL DA
  iExecuteDOLDA : pVoid;

  // execute DOL ISO
  iExecuteDOLISO : pVoid;

  // execute DOL ASY
  iExecuteDOLASY : pVoid;

  // trigger wd
  iTriggerWd : pVoid;

  // trigger wd on clients
  iTriggerClientWd : pVoid;

  // Get Node Info
  iGetNodeInfo : pVoid;

  // Set Object Callback
  iSetObjectCallback : pVoid;

  // Get Manager Control Block
  iGetManagerControl : pVoid;

  // get SyncAndWd DO Ptr
  iGetSyncAndWdDO : pVoid;

  // mesaure response time
  iMeasureResponseTime : pVoid;

  // Read Memory DA
  iReadMemoryDA : pVoid;

  // Read Control DA
  iReadControlDA : pVoid;

  // Write Memory DA
  iWriteMemoryDA : pVoid;

  // Write Control DA
  iWriteControlDA : pVoid;

  // not for application
  iReserved4 : pVoid;

  // not for application
  iReserved5 : pVoid;

  // Set Node Enable Status
  iSetNodeEnableStatus : pVoid;

  // SPI Master Set request
  iSPIMasterSetRequest : pVoid;
  
  // SPI Master Clear request
  iSPIMasterClearRequest : pVoid; 

  // SPI Master Status
  iSPIMasterStatus : pVoid;

  // not for application
  iReserved6 : pVoid;

  // SPI Page Read
  iSPIMasterPageRead : pVoid;
  
  // not for application
  iReserved7 : pVoid;

  // SPI Page Read
  iSPIMasterPageReadBuffer : pVoid;
    
  // SPI Page Write buffer
  iSPIMasterPageWriteBuffer : pVoid;

  // not for application
  iReserved9 : pVoid;

  // get Manager client space
  iGetManagerClientAddress : pVoid;

  // not for application
  iReserved10 : pVoid;

  // not for application
  iReserved11 : pVoid;

  // not for application
  iReserved12 : pVoid;

  // not for application
  iReserved13 : pVoid;

  // to set manager error
  iSetManagerError : pVoid;

  // not for application
  iReserved14 : pVoid;

  // not for application
  iReserved15 : pVoid;

  //function to set mask of an IRQ data object
  iSetIRQDOMask : pVoid;

  // execute DOL IRQ
  iExecuteDOLIRQ : pVoid;

  // SPI Master Sector Erase without waiting until ready
  iSPIMasterSectorEraseNoWait : pVoid;

  // SPI Master Page Read without waiting until ready
  iSPIMasterPageReadNoWait : pVoid;

  // SPI Master Page Write without waiting until ready
  iSPIMasterPageWriteNoWait : pVoid;

  // not for application
  iReserved16 : pVoid;

  // Manager Callback bei Connect oder Disconnect aufrufen
  iSetManagerCallbackOnConnect : pVoid;  

  // Ab Version 0x00001106:
  // Manager Callback bei VMC Wechselbuffer DA Interrupt aufrufen
  iSetManagerCallbackOnVmcBufDaInt : pVoid;

  // Ab Version 0x00001107:
  // not for application
  iReserved17 : pVoid;

  // Ab Version 0x00001108:
  // Function called by the HW Classes to let the OS know the HWClasses will use iGetInput/iSetOutputImage for the ISO and ASY list
  iDisableOSGetSetInputImage : pVoid;

  // Transfer all Input data from VARANMgr to local CPU
  iGetInputImage : pVoid;

  // Transfer all Output data from local CPU to VARANMgr
  iSetOutputImage : pVoid;

  END_STRUCT;
END_TYPE


// manager online commands
FUNCTION __CDECL GLOBAL iManagerCommands
VAR_INPUT
  iCmd : DINT;
  pInput : PVOID;
  inLen  : UDINT;
  pOutput : PVOID;
  pOutLen : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iManagerCommands(p1,p2,p3,p4,p5)  pVaran^.iManagerCommands $ iManagerCommands(p1,p2,p3,p4,p5)



// iInitApp
FUNCTION __CDECL GLOBAL iInitApp
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iInitApp(p1)  pVaran^.iInitApp $ iInitApp(p1)



// iAddDOtoDOL
FUNCTION __CDECL GLOBAL iAddDOtoDOL
VAR_INPUT
  uiManager : UDINT;
  pucNode : ^USINT;
  uiDOLType : UDINT;
  puiDOHandle : ^UDINT;
  // Command
  uiCmd : UDINT;
  // read
  uiAddressRead : UDINT;  
  uiLengthRead : UDINT;
  pucRead : ^UDINT;
  // write
  uiAddressWrite : UDINT;  
  uiLengthWrite : UDINT;
  pucWrite : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iAddDOToDOL(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)  pVaran^.iAddDOtoDOL $ iAddDOtoDOL(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)



// iClearDOL
FUNCTION __CDECL GLOBAL iClearDOL
VAR_INPUT
  uiManager : UDINT;
  uiDOLType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iClearDOL(p1,p2)  pVaran^.iClearDOL $ iClearDOL(p1,p2)



// iExecuteDOLDA
FUNCTION __CDECL GLOBAL iExecuteDOLDA
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iExecuteDOLDA(p1)  pVaran^.iExecuteDOLDA $ iExecuteDOLDA(p1)



// iExecuteDOLISO
FUNCTION __CDECL GLOBAL iExecuteDOLISO
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iExecuteDOLISO(p1)  pVaran^.iExecuteDOLISO $ iExecuteDOLISO(p1)



// iExecuteDOLASY
FUNCTION __CDECL GLOBAL iExecuteDOLASY
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iExecuteDOLASY(p1)  pVaran^.iExecuteDOLASY $ iExecuteDOLASY(p1)



// iTriggerWd
FUNCTION __CDECL GLOBAL iTriggerWd
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iTriggerWd(p1)  pVaran^.iTriggerWd $ iTriggerWd(p1)



// iGetNodeInfo
FUNCTION __CDECL GLOBAL iGetNodeInfo
VAR_INPUT
  uiManager : UDINT;
  pucNode : ^USINT;
  pNodeInfo : ^PLSL_VARANNODEINFO;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iGetNodeInfo(p1,p2,p3)  pVaran^.iGetNodeInfo $ iGetNodeInfo(p1,p2,p3)



// iSetObjectCallback
FUNCTION __CDECL GLOBAL iSetObjectCallback
VAR_INPUT
  uiManager : UDINT;
  pucNode : ^USINT;
  uiCallback : UDINT;
  uiThis : UDINT;
  uiRequired : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetObjectCallback(p1,p2,p3,p4,p5)  pVaran^.iSetObjectCallback $ iSetObjectCallback(p1,p2,p3,p4,p5)



// iGetManagerControl
FUNCTION __CDECL GLOBAL iGetManagerControl
VAR_INPUT
  uiManager : UDINT;
  pvCB : ^PLSL_CONTROLBLOCK;
  pvPLL : ^PLSL_VARANPLL;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iGetManagerControl(p1,p2,p3)  pVaran^.iGetManagerControl $ iGetManagerControl(p1,p2,p3)



// iGetSyncAndWdDO
FUNCTION __CDECL GLOBAL iGetSyncAndWdDO
VAR_INPUT
  uiManager : UDINT;
  pvDO : ^PLSL_VARANFRAME;
  pvData : ^PVOID;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iGetSyncAndWdDO(p1,p2,p3)  pVaran^.iGetSyncAndWdDO $ iGetSyncAndWdDO(p1,p2,p3)



// iMeasureResponseTime
FUNCTION __CDECL GLOBAL iMeasureResponseTime
VAR_INPUT
  uiManager : UDINT;
  pucNode : ^USINT;
  puiResponseTime : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iMeasureResponseTime(p1,p2,p3)  pVaran^.iMeasureResponseTime $ iMeasureResponseTime(p1,p2,p3)



// iReadMemoryDA
FUNCTION __CDECL GLOBAL iReadMemoryDA
VAR_INPUT
  uiManager : UDINT;
  uiAddress : UDINT;
  uiLen : UDINT;
  uiRetryTimeout : UDINT;
  pvData : PVOID;
  puiError : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iReadMemoryDA(p1,p2,p3,p4,p5,p6)  pVaran^.iReadMemoryDA $ iReadMemoryDA(p1,p2,p3,p4,p5,p6)



// iReadControlDA
FUNCTION __CDECL GLOBAL iReadControlDA
VAR_INPUT
  uiManager : UDINT;
  uiAddress : UDINT;
  uiLen : UDINT;
  uiRetryTimeout : UDINT;
  pvData : PVOID;
  puiError : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iReadControlDA(p1,p2,p3,p4,p5,p6)  pVaran^.iReadControlDA $ iReadControlDA(p1,p2,p3,p4,p5,p6)



// iWriteMemoryDA
FUNCTION __CDECL GLOBAL iWriteMemoryDA
VAR_INPUT
  uiManager : UDINT;
  uiAddress : UDINT;
  uiLen : UDINT;
  uiRetryTimeout : UDINT;
  pvData : PVOID;
  puiError : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iWriteMemoryDA(p1,p2,p3,p4,p5,p6)  pVaran^.iWriteMemoryDA $ iWriteMemoryDA(p1,p2,p3,p4,p5,p6)



// iWriteControlDA
FUNCTION __CDECL GLOBAL iWriteControlDA
VAR_INPUT
  uiManager : UDINT;
  uiAddress : UDINT;
  uiLen : UDINT;
  uiRetryTimeout : UDINT;
  pvData : PVOID;
  puiError : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iWriteControlDA(p1,p2,p3,p4,p5,p6)  pVaran^.iWriteControlDA $ iWriteControlDA(p1,p2,p3,p4,p5,p6)



// iSetNodeEnableStatus
FUNCTION __CDECL GLOBAL iSetNodeEnableStatus
VAR_INPUT
  uiManager 	: UDINT;
  pucNode 	: ^USINT;
  uiNodeStatus 	: UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetNodeEnableStatus(p1,p2,p3)  pVaran^.iSetNodeEnableStatus $ iSetNodeEnableStatus(p1,p2,p3)



 // SPI Master Set request
FUNCTION __CDECL GLOBAL iSPIMasterSetRequest
VAR_INPUT
  uiManager 	: UDINT;
  pucNode 	: ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterSetRequest(p1,p2)  pVaran^.iSPIMasterSetRequest $ iSPIMasterSetRequest(p1,p2)



 // SPI Master Clear request
FUNCTION __CDECL GLOBAL iSPIMasterClearRequest
VAR_INPUT
  uiManager 	: UDINT;
  pucNode 	: ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterClearRequest(p1,p2)  pVaran^.iSPIMasterClearRequest $ iSPIMasterClearRequest(p1,p2)



 // SPI Master Status
FUNCTION __CDECL GLOBAL iSPIMasterStatus
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  puiStatus	: ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterStatus(p1,p2,p3)  pVaran^.iSPIMasterStatus $ iSPIMasterStatus(p1,p2,p3)



 // SPI Master Page Read
FUNCTION __CDECL GLOBAL iSPIMasterPageRead
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  uiPage	: UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterPageRead(p1,p2,p3)  pVaran^.iSPIMasterPageRead $ iSPIMasterPageRead(p1,p2,p3)



 // SPI Master Page Read Buffer
FUNCTION __CDECL GLOBAL iSPIMasterPageReadBuffer
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  uiOffset	: UDINT;
  uiLen		: UDINT;
  puiPage	: ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterPageReadBuffer(p1,p2,p3,p4,p5)  pVaran^.iSPIMasterPageReadBuffer $ iSPIMasterPageReadBuffer(p1,p2,p3,p4,p5)


 // SPI Master Page Write Buffer
FUNCTION __CDECL GLOBAL iSPIMasterPageWriteBuffer
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  uiOffset	: UDINT;
  uiLen		: UDINT;
  pucData	: ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterPageWriteBuffer(p1,p2,p3,p4,p5)  pVaran^.iSPIMasterPageWriteBuffer $ iSPIMasterPageWriteBuffer(p1,p2,p3,p4,p5)


 // Get Manager Client Space
FUNCTION __CDECL GLOBAL iGetManagerClientAddress
VAR_INPUT
  uiManager   : UDINT;
  uiType 	    : UDINT;
  puiAddress	: ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iGetManagerClientAddress(p1,p2,p3)  pVaran^.iGetManagerClientAddress $ iGetManagerClientAddress(p1,p2,p3)


 // Set Manager Error
FUNCTION __CDECL GLOBAL iSetManagerError
VAR_INPUT
  uiManager   : UDINT;
  uiType 	    : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetManagerError(p1,p2)  pVaran^.iSetManagerError $ iSetManagerError(p1,p2)


 //function to set mask of an IRQ data object
FUNCTION __CDECL GLOBAL iSetIRQDOMask
VAR_INPUT
  uiManager   : UDINT;
  pHnadleDO   : ^LSL_VARANFRAME;
  pucIRQMask  : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetIRQDOMask(p1,p2,p3)  pVaran^.iSetIRQDOMask $ iSetIRQDOMask(p1,p2,p3)


// iExecuteDOLIRQ
FUNCTION __CDECL GLOBAL iExecuteDOLIRQ
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iExecuteDOLIRQ(p1)  pVaran^.iExecuteDOLIRQ $ iExecuteDOLIRQ(p1)


 // SPI Master Sector Erase without waiting until ready
FUNCTION __CDECL GLOBAL iSPIMasterSectorEraseNoWait
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  uiSector	: UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterSectorEraseNoWait(p1,p2,p3)  pVaran^.iSPIMasterSectorEraseNoWait $ iSPIMasterSectorEraseNoWait(p1,p2,p3)


 // SPI Master Page Read without waiting until ready
FUNCTION __CDECL GLOBAL iSPIMasterPageReadNoWait
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  uiPage	: UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterPageReadNoWait(p1,p2,p3)  pVaran^.iSPIMasterPageReadNoWait $ iSPIMasterPageReadNoWait(p1,p2,p3)


 // SPI Master Page Write without waiting until ready
FUNCTION __CDECL GLOBAL iSPIMasterPageWriteNoWait
VAR_INPUT
  uiManager : UDINT;
  pucNode 	: ^USINT;
  uiPage	: UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSPIMasterPageWriteNoWait(p1,p2,p3)  pVaran^.iSPIMasterPageWriteNoWait $ iSPIMasterPageWriteNoWait(p1,p2,p3)

// Get VARAN Diagnostics
FUNCTION __CDECL GLOBAL iGetVaranDiagnostics
VAR_INPUT
    iCmd        : DINT;
    pInput      : pVoid;
    len         : UDINT;
    pOutput     : pVoid;
    poutLen     : ^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;
#define VARAN_iGetVaranDiagnostics(p1,p2,p3,p4,p5)   pVaran^.iManagerCommands $ iGetVaranDiagnostics(p1,p2,p3,p4,p5)


// iTriggerWd
FUNCTION __CDECL GLOBAL iTriggerClientWd
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iTriggerClientWd(p1)  pVaran^.iTriggerClientWd $ iTriggerClientWd(p1)


FUNCTION __CDECL GLOBAL iSetManagerCallbackOnConnect
VAR_INPUT
  uiPage	: CHAR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetManagerCallbackOnConnect(p1)  pVaran^.iSetManagerCallbackOnConnect $ iSetManagerCallbackOnConnect(p1)


FUNCTION __CDECL GLOBAL iSetManagerCallbackOnVmcBufDaInt
VAR_INPUT
  onOff	: CHAR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetManagerCallbackOnVmcBufDaInt(p1)  pVaran^.iSetManagerCallbackOnVmcBufDaInt $ iSetManagerCallbackOnVmcBufDaInt(p1)


// iDisableOSGetSetInputImage
FUNCTION __CDECL GLOBAL iDisableOSGetSetInputImage
VAR_INPUT
  uiManager : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iDisableOSGetSetInputImage(p1)  pVaran^.iDisableOSGetSetInputImage $ iDisableOSGetSetInputImage(p1)


// iGetInputImage
FUNCTION __CDECL GLOBAL iGetInputImage
VAR_INPUT
  uiManager : UDINT;
  uiDOLType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iGetInputImage(p1,p2)  pVaran^.iGetInputImage $ iGetInputImage(p1,p2)


// iSetOutputImage
FUNCTION __CDECL GLOBAL iSetOutputImage
VAR_INPUT
  uiManager : UDINT;
  uiDOLType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define VARAN_iSetOutputImage(p1,p2)  pVaran^.iSetOutputImage $ iSetOutputImage(p1,p2)


//
// Interface IMULTIVARANMANAGER
//

// Property-IDs haben folgende Struktur:
// Byte 3 (Bit 7 bis Bit 4): reserviert
// Byte 3 (Bit 3 bis Bit 0): Kategorie (System = 0, Knoten = 1, DO = 2)
// Byte 2 (Bit 7 bis Bit 4): reserviert
// Byte 2 (Bit 3 bis Bit 0): Unterkategorie (z.B. Allgemein = 0, VARAN-Manager
// = 1 und VARAN-Client Optional = 2 bei den Knoteneigenschaften)
// Byte 1 (Bit 7): 1 = Eigenschaft ist schreibbar / 0 = Eigenschaft ist nicht
// schreibbar
// Byte 1 (Bit 6): 1 = Eigenschaft ist lesbar / 0 = Eigenschaft ist nicht lesbar
// Byte 1 (Bit 5 bis Bit 0) und Byte 0 (gesamt): fortlaufende Nummer 


TYPE
  LSL_PROPERTY_ID :
  (
    // Kategorie "System"

    // IDs von ausschließlich lesbaren Systemeigenschaften haben Werte von
    // 0x00004000 bis einschließlich 0x00007FFF
    SYS_PROP_MANAGER_COUNT := 0x00004000,
    
    // IDs von ausschließlich schreibbaren Systemeigenschaften haben Werte von
    // 0x00008000 bis einschließlich 0x0000BFFF
    SYS_PROP_OPERATIONAL_STATE := 0x00008000,
    
    // IDs von les- und schreibbaren Systemeigenschaften haben Werte von
    // 0x0000C000 bis einschließlich 0x0000FFFF


    // Kategorie "Knoten"

    // Unterkategorie "Allgemein"

    // IDs von ausschließlich lesbaren Knoteneigenschaften, die jeder
    // VARAN-Knoten aufweist, haben Werte von 0x01004000 bis einschließlich
    // 0x01007FFF
    ND_PROP_SPI_MASTER_STATUS := 0x01004000,
    ND_PROP_SPI_MASTER_PAGE_BUFFER,

    // IDs von ausschließlich schreibbaren Knoteneigenschaften, die jeder
    // VARAN-Knoten aufweist, haben Werte von 0x01008000 bis einschließlich
    // 0x0100BFFF
    ND_PROP_CONNECTION_STATE := 0x01008000,
    ND_PROP_SPI_MASTER_REQUEST,

    // IDs von les- und schreibbaren Knoteneigenschaften, die jeder VARAN-Knoten
    // aufweist, haben Werte von 0x0100C000 bis einschließlich 0x0100FFFF


    // Unterkategorie "VARAN-Manager"

    // IDs von ausschließlich lesbaren Knoteneigenschaften, die nur
    // VARAN-Managerknoten aufweisen, haben Werte von 0x01014000 bis
    // einschließlich 0x01017FFF
    VM_PROP_SYNC_COUNTER := 0x01014000,
    VM_PROP_GLOBAL_FAILED_ACCESS_COUNTER,
    VM_PROP_ASY_TIME_UP_COUNTER,
    VM_PROP_TIME_UP_COUNTER_BETWEEN_PLL_TICKS,
    VM_PROP_PLL_SYNC_TIME_FRAME_COUNTER,
    VM_PROP_PLL_STATUS_REGISTER,
    VM_PROP_PAYLOAD_WFE_SUPPORT_AVAILABLE,
    VM_PROP_TASK_STATE_ASY,
    VM_PROP_VARAN_PROTOCOL_VERSION,
    VM_PROP_PLL_SHIFTED_PHASE,
    VM_PROP_CONFIGURABLE_DPRAM_SIZE,
    
    // IDs von ausschließlich schreibbaren Knoteneigenschaften, die nur
    // VARAN-Managerknoten aufweisen, haben Werte von 0x01018000 bis
    // einschließlich 0x0101BFFF
    VM_PROP_TIME_UP_COUNTER_THRESHOLD := 0x01018000,
    VM_PROP_IRQ_SCAN_RATE,
    VM_PROP_IRQ_DURATION,
    VM_PROP_MAX_COMMAND_EXECUTION_TIME,
    VM_PROP_ISO_START_TIME,
    VM_PROP_PLL_SYSTEM_PERIOD_DIVIDER,
    VM_PROP_PLL_CONTROL_REGISTER,
    VM_PROP_REQUIRED_ERROR_ENABLED,
    VM_PROP_CONNECTION_STATE_CHANGE_CALLBACK_ENABLED,
    VM_PROP_PLL_DELTA_PHASE,
    VM_PROP_PAYLOAD_WRITE_DATA_SIZE,
    VM_PROP_PAYLOAD_READ_DATA_SIZE,
    // ab Schnittstellen-Version 0x00001004
    VM_PROP_PAYLOAD_DMA_CHANNEL_ENABLE,
    
    // IDs von les- und schreibbaren Knoteneigenschaften, die nur
    // VARAN-Managerknoten aufweisen, haben Werte von 0x0101C000 bis
    // einschließlich 0x0101FFFF
    VM_PROP_PLL_SYSTEM_PERIOD_TIME := 0x0101C000,
    VM_PROP_TASK_STATE_ISO,
    VM_PROP_MANAGER_ERROR,


    // Unterkategorie "VARAN-Client Optional"

    // IDs von ausschließlich lesbaren Knoteneigenschaften, die VARAN-
    // Clientknoten aufweisen können, haben Werte von 0x01024000 bis
    // einschließlich 0x01027FFF
    VC_OPT_PROP_BUFFER_ADDRESS_ISO := 0x01024000,
    VC_OPT_PROP_BUFFER_ADDRESS_ASY,
    VC_OPT_PROP_BUFFER_ADDRESS_DA,

    // IDs von ausschließlich schreibbaren Knoteneigenschaften, die VARAN-
    // Clientknoten aufweisen können, haben Werte von 0x01028000 bis
    // einschließlich 0x0102BFFF
    VC_OPT_PROP_DA_BUFFER_ACCESS_CALLBACK_ENABLED := 0x01028000,

    // IDs von les- und schreibbaren Knoteneigenschaften, die VARAN-Clientknoten
    // aufweisen können, haben Werte von 0x0102C000 bis einschließlich
    // 0x0102FFFF


    // Kategorie "DO"

    // IDs von ausschließlich lesbaren DO-Eigenschaften haben Werte von
    // 0x02004000 bis einschließlich 0x02007FFF
    DO_PROP_FAILED_ACCESS_COUNTER := 0x02004000,

    // IDs von ausschließlich schreibbaren DO-Eigenschaften haben Werte von
    // 0x02008000 bis einschließlich 0x0200BFFF
    DO_PROP_PRESCALER_COUNTER_THRESHOLD := 0x02008000,
    DO_PROP_PRESCALER_COUNTER_INIT_VALUE,
    DO_PROP_READ_OFFSET,
    DO_PROP_WRITE_OFFSET,
    DO_PROP_READ_LENGTH,
    DO_PROP_WRITE_LENGTH,
    DO_PROP_SOURCE_READ_DO,
    DO_PROP_DESTINATION_WRITE_DO,
    DO_PROP_MOVE_DATA_LENGTH,
    DO_PROP_IRQ_MASK,
    DO_PROP_RETRY_TIMEOUT,
    DO_PROP_SLICES,
    DO_PROP_EXECUTE_UNTIL_FIFO_EMPTY
    
    // IDs von les- und schreibbaren DO-Eigenschaften haben Werte von 0x0200C000
    // bis einschließlich 0x0200FFFF

  )$UDINT;
END_TYPE


// Mögliche Werte für boolsche Eigenschaften
#define VM_TRUE  1
#define VM_FALSE 0


// Mögliche Werte für die Eigenschaft SYS_PROP_OPERATIONAL_STATE
TYPE
  LSL_SYS_PROP_OP_STATE_VALUE :
  (
    OP_STATE_LEGACY_INIT := 2,
    OP_STATE_INIT_1,
    OP_STATE_INIT_2,
    OP_STATE_POST_INIT,
    OP_STATE_PRE_OPERATIONAL,
    OP_STATE_SAFE_OPERATIONAL,
    OP_STATE_OPERATIONAL
  )$UDINT;
END_TYPE


// Mögliche Werte für die Eigenschaften VM_PROP_TASK_STATE_ISO und
// VM_PROP_TASK_STATE_ASY
#define	TK_STATE_FINISHED   0
#define	TK_STATE_EXECUTING  1
#define	TK_STATE_STOPPED    2


// Mögliche Werte für die Eigenschaft ND_PROP_CONNECTION_STATE
#define CN_STATE_DISCONNECTED  0
#define CN_STATE_CONNECTED     1


// Mögliche Werte für die Eigenschaft ND_PROP_SPI_MASTER_STATUS
#define SPI_MASTER_STATUS_BUSY   0
#define SPI_MASTER_STATUS_READY  1


// Mögliche Werte für die Eigenschaft ND_PROP_SPI_MASTER_REQUEST
#define SPI_MASTER_REQ_CLEARED  0
#define SPI_MASTER_REQ_SET      1

// Bedeutung der Bits für die Eigenschaft VM_PROP_PAYLOAD_DMA_CHANNEL_ENABLE
#define PAYLOAD_DMA_ENABLE_ISO_RD (1 shl 0)
#define PAYLOAD_DMA_ENABLE_ISO_WR (1 shl 1)
#define PAYLOAD_DMA_ENABLE_ASY_RD (1 shl 2)
#define PAYLOAD_DMA_ENABLE_ASY_WR (1 shl 3)

TYPE
  LSL_PROPERTY_VALUE_PAIR : STRUCT

  // Name der Eigenschaft
  udPropertyId : LSL_PROPERTY_ID;
  // Wert der Eigenschaft
  udPropertyValue : UDINT;

  END_STRUCT;
END_TYPE

// Watchdog-Typ zur Übergabe an Funktion zum Triggern des bzw. der Watchdogs
#define LSL_WD_TYPE_MANAGER   1
#define LSL_WD_TYPE_CLIENT    2

// Mögliche Werte für den Write-Payload-Typ zur Übergabe an die Funktionen iAddDo
// und iAddIrqDo
TYPE
  LSL_WRITE_PAYLOAD_TYPE:
  (
    WR_PLD_TYPE_STANDARD := 1,
    WR_PLD_TYPE_RD_ACCESS_CONFIGURABLE := 2,
    WR_PLD_TYPE_WR_ACCESS_CONFIGURABLE := 3,
    WR_PLD_TYPE_RW_ACCESS_CONFIGURABLE := 4
  )$UDINT;
END_TYPE


TYPE
  LSL_NODE_HANDLE : UDINT;
END_TYPE

TYPE
  LSL_DO_HANDLE : UDINT;
END_TYPE

TYPE
  LSL_MULTI_VARAN : STRUCT

  //
  // Strukturheader
  //

  // Version
  udVersion : UDINT;

  // Länge der Struktur
  udSize    : UDINT;

  //
  // Funktionen
  //

  // iGetSystemProperty existiert ab Version 01.00.006
  iGetSystemProperty : pVoid;

  iSetSystemProperties : pVoid;

  iGetNodeHandle : pVoid;

  iSetApplicationCallback : pVoid;

  iGetNodeInformation : pVoid;

  iGetNodeProperty : pVoid;

  iSetNodeProperties : pVoid;

  iSetUserDataSize : pVoid;

  iConfigurePllSyncOut : pVoid;

  iGetTimeUpCounter : pVoid;

  iAddDo : pVoid;

  iAddMoveDo : pVoid;

  iAddIrqDo : pVoid;

  iAddWaitForEventDo : pVoid;

  iGetDataPointers : pVoid;

  iEnableDO : pVoid;

  iDisableDO : pVoid;

  iGetDoProperty : pVoid;

  iSetDoProperties : pVoid;

  iIncrementSyncCounter : pVoid;

  iResetWatchdogTimer : pVoid;

  iReportVaranError : pVoid;

  iGetLastVaranErrorInfo : pVoid;

  iCheckIsoState : pVoid;

  iGetIsoDuration : pVoid;

  iExecuteDol : pVoid;

  iExecuteDirectAccess : pVoid;

  iSpiMasterEraseFlashSector : pVoid;

  iSpiMasterReadFlashPage : pVoid;

  iSpiMasterWriteFlashPage : pVoid;

  // ab Version 01.00.003
  iInsertDoIntoDol : pVoid;

  END_STRUCT;
END_TYPE



// iSetSystemProperties
FUNCTION __CDECL GLOBAL iGetSystemProperty
VAR_INPUT
  udPropertyId : LSL_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetSystemProperty(p1,p2) \
  pMultiVaran^.iGetSystemProperty $ iGetSystemProperty(p1,p2)



// iSetSystemProperties
FUNCTION __CDECL GLOBAL iSetSystemProperties
VAR_INPUT
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^LSL_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSetSystemProperties(p1,p2) \
  pMultiVaran^.iSetSystemProperties $ iSetSystemProperties(p1,p2)



// iGetNodeHandle
FUNCTION __CDECL GLOBAL iGetNodeHandle
VAR_INPUT
  udManagerNumber : UDINT;
  pszHardwarePath : ^USINT;
  phNodeHandle : ^LSL_NODE_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetNodeHandle(p1,p2,p3) \
  pMultiVaran^.iGetNodeHandle $ iGetNodeHandle(p1,p2,p3)



// iSetNodeCallback
FUNCTION __CDECL GLOBAL iSetApplicationCallback
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  pfApplicationCallback : pvoid;  
  pvUserData : pvoid;
  udRequired : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSetApplicationCallback(p1,p2,p3,p4) \
  pMultiVaran^.iSetApplicationCallback $ iSetApplicationCallback(p1,p2,p3,p4)



// iGetNodeInformation
FUNCTION __CDECL GLOBAL iGetNodeInformation
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  psNodeInfo : PLSL_VARANNODEINFO;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetNodeInformation(p1,p2) \
  pMultiVaran^.iGetNodeInformation $ iGetNodeInformation(p1,p2)



// iGetNodeProperty
FUNCTION __CDECL GLOBAL iGetNodeProperty
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  udPropertyId : LSL_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetNodeProperty(p1,p2,p3) \
  pMultiVaran^.iGetNodeProperty $ iGetNodeProperty(p1,p2,p3)



// iSetNodeProperties
FUNCTION __CDECL GLOBAL iSetNodeProperties
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^LSL_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSetNodeProperties(p1,p2,p3) \
  pMultiVaran^.iSetNodeProperties $ iSetNodeProperties(p1,p2,p3)



// iSetUserDataSize
FUNCTION __CDECL GLOBAL iSetUserDataSize
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  udWriteDataSizeB : UDINT;
  udReadDataSizeB : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSetUserDataSize(p1,p2,p3) \
  pMultiVaran^.iSetUserDataSize $ iSetUserDataSize(p1,p2,p3)



// iConfigurePllSyncOut
FUNCTION __CDECL GLOBAL iConfigurePllSyncOut
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  udSyncOutId : UDINT;  
  udPeriodMultiplier : UDINT;
  udFrameCountThreshold : UDINT;
  udControlStatus : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iConfigurePllSyncOut(p1,p2,p3,p4,p5) \
  pMultiVaran^.iConfigurePllSyncOut $ iConfigurePllSyncOut(p1,p2,p3,p4,p5)



// iGetTimeUpCounter
FUNCTION __CDECL GLOBAL iGetTimeUpCounter
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  pudTimeUpCounterNs : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetTimeUpCounter(p1,p2) \
  pMultiVaran^.iGetTimeUpCounter $ iGetTimeUpCounter(p1,p2)



// iAddDo
FUNCTION __CDECL GLOBAL iAddDo
VAR_INPUT
  phDoHandle : ^LSL_DO_HANDLE;
  hNodeHandle : LSL_NODE_HANDLE;
  bDoRequired : UDINT;
  udDolType : UDINT;
  udCommand : UDINT;
  udPriority : UDINT;  
  udPrescalerCounterThreshold : UDINT;
  udPrescalerCounterStartValue : UDINT;
  udReadOffset : UDINT;  
  udReadLength : UDINT;
  udWriteOffset : UDINT;
  udWriteLength : UDINT;
  udFilter : UDINT;
  udSlices : UDINT;
  udWritePayloadType : LSL_WRITE_PAYLOAD_TYPE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iAddDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15) \
  pMultiVaran^.iAddDo $ iAddDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15)



// iAddMoveDo
FUNCTION __CDECL GLOBAL iAddMoveDo
VAR_INPUT
  phDoHandle : ^LSL_DO_HANDLE;
  bDoRequired : UDINT;
  udDolType : UDINT;
  udPriority : UDINT;  
  udPrescalerCounterThreshold : UDINT;
  udPrescalerCounterStartValue : UDINT;
  hSourceReadDoHandle : UDINT; 
  udReadOffset : UDINT; 
  hDestinationWriteDoHandle : UDINT;
  udWriteOffset : UDINT;
  udMoveDataLength : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iAddMoveDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11) \
  pMultiVaran^.iAddMoveDo $ iAddMoveDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)



// iAddIrqDo
FUNCTION __CDECL GLOBAL iAddIrqDo
VAR_INPUT
  phDoHandle : ^LSL_DO_HANDLE;
  hNodeHandle : LSL_NODE_HANDLE;
  bDoRequired : UDINT;
  udCommand : UDINT;
  udPriority : UDINT;  
  udPrescalerCounterThreshold : UDINT;
  udPrescalerCounterStartValue : UDINT;
  udReadOffset : UDINT;  
  udReadLength : UDINT;
  pusIrqMask : ^USINT;
  udWritePayloadType : LSL_WRITE_PAYLOAD_TYPE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iAddIrqDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11) \
  pMultiVaran^.iAddIrqDo $ iAddIrqDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)



// iAddWaitForEventDo
FUNCTION __CDECL GLOBAL iAddWaitForEventDo
VAR_INPUT
  phDoHandle : ^LSL_DO_HANDLE;
  hManagerNodeHandle : LSL_NODE_HANDLE;
  bDoRequired : UDINT;
  udDolType : UDINT;
  udPriority : UDINT;  
  udPrescalerCounterThreshold : UDINT;
  udPrescalerCounterStartValue : UDINT;
  udEventMask : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iAddWaitForEventDo(p1,p2,p3,p4,p5,p6,p7,p8) \
  pMultiVaran^.iAddWaitForEventDo $ iAddWaitForEventDo(p1,p2,p3,p4,p5,p6,p7,p8)



// iGetDataPointers
FUNCTION __CDECL GLOBAL iGetDataPointers
VAR_INPUT
  hDoHandle : LSL_DO_HANDLE;
  ppvReadData : ^pvoid;
  ppvWriteData : ^pvoid;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetDataPointers(p1,p2,p3) \
  pMultiVaran^.iGetDataPointers $ iGetDataPointers(p1,p2,p3)



// iEnableDo
FUNCTION __CDECL GLOBAL iEnableDo
VAR_INPUT
  hDoHandle : LSL_DO_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iEnableDo(p)  pMultiVaran^.iEnableDo $ iEnableDo(p)



// iDisableDo
FUNCTION __CDECL GLOBAL iDisableDo
VAR_INPUT
  hDoHandle : LSL_DO_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iDisableDo(p)  pMultiVaran^.iDisableDo $ iDisableDo(p)



// iGetDoProperty
FUNCTION __CDECL GLOBAL iGetDoProperty
VAR_INPUT
  hDoHandle : LSL_DO_HANDLE;
  udPropertyId : LSL_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetDoProperty(p1,p2,p3) \
  pMultiVaran^.iGetDoProperty $ iGetDoProperty(p1,p2,p3)



// iSetDoProperties
FUNCTION __CDECL GLOBAL iSetDoProperties
VAR_INPUT
  hDoHandle : LSL_DO_HANDLE;
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^LSL_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSetDoProperties(p1,p2,p3) \
  pMultiVaran^.iSetDoProperties $ iSetDoProperties(p1,p2,p3)



// iIncrementSyncCounter
FUNCTION __CDECL GLOBAL iIncrementSyncCounter
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iIncrementSyncCounter(p) \
  pMultiVaran^.iIncrementSyncCounter $ iIncrementSyncCounter(p)



// iResetWatchdogTimer
FUNCTION __CDECL GLOBAL iResetWatchdogTimer
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  udWatchdogType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iTriggerWatchdog(p1,p2) \
pMultiVaran^.iResetWatchdogTimer $ iResetWatchdogTimer(p1,p2)



// iReportVaranError
FUNCTION __CDECL GLOBAL iReportVaranError
VAR_INPUT
  diErrorNumber : DINT;
  hErrorNode : LSL_NODE_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iReportVaranError(p1,p2) \
pMultiVaran^.iReportVaranError $ iReportVaranError(p1,p2)



// iGetLastVaranErrorInfo
FUNCTION __CDECL GLOBAL iGetLastVaranErrorInfo
VAR_INPUT
  pdiLastErrorNumber : ^DINT;
  ppsLastErrorNode : ^PLSL_VARANNODEINFO;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetLastVaranErrorInfo(p1,p2) \
pMultiVaran^.iGetLastVaranErrorInfo $ iGetLastVaranErrorInfo(p1,p2)



// iCheckIsoState
FUNCTION __CDECL GLOBAL iCheckIsoState
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  pudIsoState : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iCheckIsoState(p1,p2) \
  pMultiVaran^.iCheckIsoState $ iCheckIsoState(p1,p2)



// iGetIsoDuration
FUNCTION __CDECL GLOBAL iGetIsoDuration
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  pudIsoDurationNs : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iGetIsoDuration(p1,p2) \
  pMultiVaran^.iGetIsoDuration $ iGetIsoDuration(p1,p2)



// iExecuteDol
FUNCTION __CDECL GLOBAL iExecuteDol
VAR_INPUT
  hManagerNodeHandle : LSL_NODE_HANDLE;
  udDolType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iExecuteDol(p1,p2) \
  pMultiVaran^.iExecuteDol $ iExecuteDol(p1,p2)



// iExecuteDirectAccess
FUNCTION __CDECL GLOBAL iExecuteDirectAccess
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  udCommand : UDINT;
  udOffset : UDINT;  
  udLength : UDINT;
  pusData : ^USINT;
  pudErrorInfo : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iExecuteDirectAccess(p1,p2,p3,p4,p5,p6) \
  pMultiVaran^.iExecuteDirectAccess $ iExecuteDirectAccess(p1,p2,p3,p4,p5,p6)



// iSpiMasterEraseFlashSector
FUNCTION __CDECL GLOBAL iSpiMasterEraseFlashSector
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  udFirstPageInSector : UDINT;
  bBlockUntilCompleted : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSpiMasterEraseFlashSector(p1,p2,p3) \
  pMultiVaran^.iSpiMasterEraseFlashSector $ iSpiMasterEraseFlashSector(p1,p2,p3)



// iSpiMasterReadFlashPage
FUNCTION __CDECL GLOBAL iSpiMasterReadFlashPage
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  udPageNumber : UDINT;
  udOffsetInPage : UDINT;
  udReadLength : UDINT;
  bBlockUntilCompleted : UDINT;
  pusData : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSpiMasterReadFlashPage(p1,p2,p3,p4,p5,p6) \
  pMultiVaran^.iSpiMasterReadFlashPage \
  $ iSpiMasterReadFlashPage(p1,p2,p3,p4,p5,p6)



// iSpiMasterWriteFlashPage
FUNCTION __CDECL GLOBAL iSpiMasterWriteFlashPage
VAR_INPUT
  hNodeHandle : LSL_NODE_HANDLE;
  udPageNumber : UDINT;
  udOffsetInPage : UDINT;
  udWriteLength : UDINT;
  bBlockUntilCompleted : UDINT;
  pusData : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iSpiMasterWriteFlashPage(p1,p2,p3,p4,p5,p6) \
  pMultiVaran^.iSpiMasterWriteFlashPage \
  $ iSpiMasterWriteFlashPage(p1,p2,p3,p4,p5,p6)


// iInsertDoIntoDol
FUNCTION __CDECL GLOBAL iInsertDoIntoDol
VAR_INPUT
  hDoHandle : LSL_DO_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define MULTI_VARAN_iInsertDoIntoDol(p1) \
  pMultiVaran^.iInsertDoIntoDol $ iInsertDoIntoDol(p1)

//HFILTER:1
#endif
//HFILTER: