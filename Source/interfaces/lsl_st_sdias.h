(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_sdias.h                                                                       *)
(*                                                                                      *)
(* enthält die Definitionen für das SDIAS Interface                                     *)
(*                                                                                      *)
(*                                                                                      *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
//HFILTER:1
#ifndef __LSL_ST_SDIAS
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define __LSL_ST_SDIAS



//
// Defines
//

// Interface
#define INTERFACE_SDIAS                       "ISDIAS"

// Ergebniscodes
// ok, kein Fehler
#define SDIAS_OK                            0
// Es wurde noch keine SDO-Response empfangen.
#define SDIAS_SDO_REQUEST_BUSY              -1
// Die Mailbox für die Kommunikation mit dem SDIAS-Task ist voll.
#define SDIAS_MAILBOX_FULL                  -2
// Es ist bei der Kommunikation mit dem SDIAS-Task ein Timeout aufgetreten.
#define SDIAS_TIMEOUT_TASK                  -3
// Der Buffer für die Daten der SDO-Response ist zu klein.
#define SDIAS_RESPONSE_BUFFER_TOO_SMALL     -4
// Bei der Kommunikation mit dem SDIAS-Master ist ein Timeout aufgetreten (SDO-Response nicht empfangen).
#define SDIAS_TIMEOUT_SDO_RESPONSE          -5
// Es stehen keine freien SDO-Handles mehr zur Verfügung.
#define SDIAS_OUT_OF_HANDLES                -6
// ungültiger Parameter für die Daten-Länge
#define SDIAS_INVALID_PARAM_DATA_LENGTH     -7
// ungültiger Parameter für den Daten-Buffer
#define SDIAS_INVALID_PARAM_DATA_BUFFER     -8
// ungültiger Parameter für das SDO-Handle
#define SDIAS_INVALID_PARAM_SDO_HANDLE      -9
// ungültiger Parameter für das Modul (Hardwarepfad ungültig)
#define SDIAS_INVALID_PARAM_NODE            -10
// SDIAS-Manager meldete globalen Fehler
#define SDIAS_GLOBAL_ERROR                  -11
// SDIAS-Manager nicht vorhanden
#define SDIAS_INVALID_MANAGER               -12
// Beim Senden des SDO-Requests ist ein Fehler aufgetreten.
#define SDIAS_SENDING_SDO_REQUEST_FAILED    -13
// Beim Empfangen der SDO-Response ist ein Fehler aufgetreten.
#define SDIAS_RECEIVING_SDO_RESPONSE_FAILED -14
// Beim SDIAS-Manager ist ein interner Fehler aufgetreten, der zu einem Setzen des Global-Error-Flags führte
// (z.B. Kommunikation mit dem SDIAS-Client ist fehlgeschlagen). */
#define SDIAS_MANAGER_GLOBAL_ERROR          -15
// Es ist ein interner Fehler in der Verarbeitung aufgetreten.
#define SDIAS_INTERNAL_ERROR                -16
// ungültiger Parameter für das Property
#define SDIAS_INVALID_PROPERTY              -17
// Fehler beim Lesen/Setzen des Property
#define SDIAS_PROPERTY_ERROR                -18
// ungültiger Parameter für den DOL Typ
#define SDIAS_INVALID_PARAM_DOL_TYPE        -19


// CIL Version which supports more than just the 3 Interfaces needed for VI021
#define SDIAS_CIL_VERSION_SUPPORTS_LOCAL      16#2000

// CIL Version which supports RAM Type property
#define SDIAS_CIL_VERSION_SUPPORTS_RAM_TYPE   16#2001

// CIL Version which supports also the AddDoDynamic command
#define SDIAS_CIL_VERSION_SUPPORTS_DYNAMIC_DO 16#3000


// DOL Type to pass on methods
#define SDIAS_DOL_TYPE_ISO                  0
// from interface version 0x5001
#define SDIAS_DOL_TYPE_ISO_RD               16#05  // DO is executed in ISO-Read-DOL (only BROADCAST)
#define SDIAS_DOL_TYPE_ISO_WR               16#06  // DO is executed in ISO-Write-DOL (only BROADCAST)

// RAM Type returned by iGetNodeProperty for SDM_PROP_RAM_RAMTYPE
// intern: Shadow RAM aktiv, derzeitige ARM Arch
// extern: PCI, PCIe, ...
#define SDIAS_RAMTYPE_INTERN                0
#define SDIAS_RAMTYPE_EXTERN                1


// defines for the creation of dynamic DOs
#define SDIAS_DO_CMD_MEM_ACCESS           0x01 // SDIAS Memory Access
#define SDIAS_DO_CMD_CTRL_ACCESS          0x02 // SDIAS Control Access
#define SDIAS_DO_CMD_GLOBAL_CMD           0x03 // SDIAS Global Command
#define SDIAS_DO_CMD_LOCAL_COPY           0x04 // Local Command Copy
#define SDIAS_DO_CMD_LOCAL_JUMP           0x05 // Local Command Jump

#define SDIAS_DO_SUBCMD_NONE              0x00 // No global command
#define SDIAS_DO_SUBCMD_GLOBAL_SYNC       0x01 // Global Sync
#define SDIAS_DO_SUBCMD_WATCHDOG_TRIGGER  0x02 // Watchdog trigger
#define SDIAS_DO_SUBCMD_GLOBAL_RESET      0x03 // Global Reset Command
#define SDIAS_DO_SUBCMD_DATA_SAMPLE       0x04 // Data Sample

#define SDIAS_DO_FLAG_SUPPORT_VARIABLE_READ_BYTE_COUNT_AND_MODULE_ADDR    0x01 // Allocates 3 bytes in SENDDO
#define SDIAS_DO_FLAG_SUPPORT_VARIABLE_WRITE_BYTE_COUNT_AND_MODULE_ADDR   0x02 // Allocates 3 bytes in SENDDO
#define SDIAS_DO_FLAG_SUPPORT_DETAILED_ANSWER_DO                          0x04 // Allocates 2 bytes in READDO 
// from interface version 0x5001
#define SDIAS_DO_FLAG_ACCESS_TYPE_READBROADCASTWRITE                      0x08 // read/broadcast write command
#define SDIAS_DO_FLAG_ACCESS_TYPE_READBROADCASTWRITE_ALL                  0x10 // read/broadcast write command for all clients

#define SDIAS_MODULESCAN_ALL              0x00  // Observe all possible SDIAS modules
#define SDIAS_MODULESCAN_AVAILABLE        0x01  // Observe only already known SDIAS modules
#define SDIAS_MODULESCAN_LIST             0x02  // Observe only Devices, that are in the Bitmap that is set with SDM_PROP_MODULE_SCAN_LIST_0_31 | SDM_PROP_MODULE_SCAN_LIST_32_63
#define SDIAS_MODULESCAN_RETRIES_SHFT     0x05  // Bit 5 to 7 define the number of retries made during Scan
#define SDIAS_MODULESCAN_RETRIES_MSK      0x07
// Default behaviour for Module Scan is     all Modules      with  0 retries
#define SDIAS_MODULESCAN_DEFAULT          (SDIAS_MODULESCAN_ALL OR (0 SHL SDIAS_MODULESCAN_RETRIES_SHFT))


TYPE
  SDM_PROPERTY_ID :
  (
    // SDIAS-Manager
    // Use with i[Get|Set]NodePropert[y|ies]

    SDM_PROP_BITMAP_DETECTED_CLIENTS_0_31 := 0x01030000,
    SDM_PROP_BITMAP_DETECTED_CLIENTS_32_63,
    SDM_PROP_SIZE_MIRRORED_HW_INFO,
    SDM_PROP_NUM_MIRRORED_CLIENTS,

    SDM_PROP_BITMAP_APPLICATION_LED_0_15,
    SDM_PROP_BITMAP_APPLICATION_LED_16_31,
    SDM_PROP_BITMAP_APPLICATION_LED_32_47,
    SDM_PROP_BITMAP_APPLICATION_LED_48_63,

    SDM_PROP_SYNC_INJECTION_CONFIG,
	
    SDM_PROP_HANDSHAKE_TO_HWK,
    SDM_PROP_HANDSHAKE_TO_UC,

    // Use with i[Get|Set]NodePropert[y|ies]Index
    // and provide the required Index.
	
    SDM_PROP_TASK_START_EVENT_ID,

    SDM_PROP_TASK_TRIGGER_UNIT_CONTROL,
    SDM_PROP_TASK_TRIGGER_UNIT_START_ADDR_RANGE,

    SDM_PROP_TASK_START_CONFIG_WAIT_EVENTS,
    SDM_PROP_TASK_START_CONFIG_DELAY,

    SDM_PROP_TASK_ERROR_INFO_FAILED_COUNTER,
    SDM_PROP_TASK_ERROR_INFO_DEVICE_ADDR,
    SDM_PROP_TASK_ERROR_INFO_DO_ADDR,
    SDM_PROP_TASK_ERROR_INFO_FLAGS,

    SDM_PROP_TASK_CONTROL_DURATION_TIMEOUT,
    SDM_PROP_TASK_CONTROL_CONFIGURATION,
    SDM_PROP_TASK_CONTROL_HANDSHAKE,

    SDM_PROP_TASK_INFO_DURATION_TIME,
    SDM_PROP_TASK_INFO_EXECUTION_TIME,

    // Use with iGetNodePropertyIndexLen
    // and provide the required Index, buffer and length
    SDM_PROP_TASK_INFO,

    SDM_PROP_PLL_SYSTEM_PERIOD_TIME_10NS,
    SDM_PROP_PLL_SYNC_TIME_FRAME_COUNTER,
    SDM_PROP_PLL_SYSTEM_PERIOD_DIVIDER,
	
    SDM_PROP_RAM_RAMTYPE,

    // Use with iGetNodePropertyIndexLen
    SDM_PROP_MODULE_INFOBLOCK,

    // Use with i[Get|Set]NodePropertyIndexLen
    SDM_PROP_SYNCHR_ALTERNATING_BUF,
    SDM_PROP_ASYNCHR_ALTERNATING_BUF,
    SDM_PROP_DACHR_ALTERNATING_BUF,

    // Use with i[Get|Set]NodePropert[y|ies]
    SDM_PROP_MODULE_SCAN_BEHAVIOUR,
    SDM_PROP_MODULE_SCAN_LIST_0_31,
    SDM_PROP_MODULE_SCAN_LIST_32_63,

    SDM_PROP_FEATURE_BITS,

    // from interface version 0x5001

    // Use with iGetNodePropery
    SDM_PROP_SDIAS_PROTOCOL_VERSION

  )$UDINT;
  
  SDM_EVENT_ID :
  (
  	SDM_EVENT_ERROR_REQUIRED_MODULE := 1
  )$UDINT;
END_TYPE


TYPE
  SDM_PROPERTY_VALUE_PAIR : STRUCT

  // Name der Eigenschaft
  udPropertyId : SDM_PROPERTY_ID;
  // Wert der Eigenschaft
  udPropertyValue : UDINT;

  END_STRUCT;
END_TYPE

TYPE
  SDM_NODE_HANDLE : UDINT;
END_TYPE

TYPE
  SDM_DO_HANDLE : UDINT;
END_TYPE


//
// Interface
//
TYPE
  LSL_SDIAS : STRUCT

  //
  // Version
  //
  udVersion : UDINT;

  //
  // From version 0x00001000
  // Functions (deprecated)
  //
  // Senden eines SDO Requests
  iSendSdoRequest  : pVoid;
  // Lesen einer SDO Response
  iReadSdoResponse : pVoid;
  
  // Lesen der Bitmaps für die am SDIAS-Manager angesteckten Clients
  iGetBitmapOfDevices : pVoid;

  //
  // From version 0x00002000
  // Functions
  //
  SDM_iGetNodeHandle : pVoid;

  SDM_iSendSdoRequestChannel  : pVoid;
  SDM_iReadSdoResponseChannel : pVoid;

  SDM_iGetInfoBlock : pVoid;
  SDM_iGetMappingInfo : pVoid;
  SDM_iGetGeneralInfo : pVoid;

  SDM_iGetNodeProperty : pVoid;
  SDM_iSetNodeProperties : pVoid;
  SDM_iGetNodePropertyIndex : pVoid;
  SDM_iSetNodePropertiesIndex : pVoid;
  SDM_iGetNodePropertyIndexLen : pVoid;

  SDM_iConfigurePllSyncOut : pVoid;

  SDM_iAddDo : pVoid;

  SDM_iGetDataPointers : pVoid;

  SDM_iGetInputImage : pVoid;
  SDM_iSetOutputImage : pVoid;

  SDM_iReportEvent : pVoid;

  // From version 0x00003000
  SDM_iAddDoDynamic : pVoid;

  // From version 0x00005000
  SDM_iSetNodePropertyIndexLen : pVoid;

  END_STRUCT;
END_TYPE


// From version 0x00001000


// iSendSdoRequest
FUNCTION __CDECL GLOBAL iSendSdoRequest
VAR_INPUT
  uiMaster        : UDINT;
  // Hardwarepfad
  pucNode         : ^USINT;
  // Kommando, bestehend aus:
  // - Byte 0 (niederwertigstes Byte): SDO Kommando
  // - Byte 1                        : SDO Sub-Kommando
  // - Bytes 2 und 3                 : reserviert
  udCommand       : UDINT;
  // SDIAS-Adresse
  udSdiasAddress  : UDINT;
  // Länge der übergebenen Daten
  udDataLength    : UDINT;
  // Buffer mit den zu sendenden Daten
  pucData         : ^USINT;
  // Buffer, in dem das Handle für den SDO-Transfer retourniert wird
  pudSdoHandle    : ^UDINT;
END_VAR
VAR_OUTPUT
  retval          : DINT;
END_VAR;
#define SDIAS_iSendSdoRequest(p1,p2,p3,p4,p5,p6,p7)  pSdias^.iSendSdoRequest $ iSendSdoRequest(p1,p2,p3,p4,p5,p6,p7)

// iReadSdoResponse
FUNCTION __CDECL GLOBAL iReadSdoResponse
VAR_INPUT
  uiMaster        : UDINT;
  // Hardwarepfad
  pucNode         : ^USINT;
  // Handle für den SDO-Transfer (wird von iSendSdoRequest retourniert)
  udSdoHandle     : UDINT;
  // Größe des Buffers, in den die Daten der SDO Response kopiert werden
  udBufferLength  : UDINT;
  // Buffer, in den die Daten der SDO Response kopiert werden
  pucData         : ^USINT;
  // Länge der in der SDO Response empfangenen Daten
  pudDataLength   : ^UDINT;
END_VAR
VAR_OUTPUT
  // SDIAS_SDO_REQUEST_BUSY, wenn der SDO Request noch nicht abgearbeitet wurde, ansonsten
  // SDIAS_NO_ERROR oder Fehler
  retval        : DINT;
END_VAR;
#define SDIAS_iReadSdoResponse(p1,p2,p3,p4,p5,p6)  pSdias^.iReadSdoResponse $ iReadSdoResponse(p1,p2,p3,p4,p5,p6)

// iGetBitmapOfDevices
FUNCTION __CDECL GLOBAL iGetBitmapOfDevices
VAR_INPUT
  uiMaster        : UDINT;
  // Hardwarepfad
  pucNode         : ^USINT;
  // Größe des Buffers, in den die Bitmap kopiert werden soll
  udBufferLength  : UDINT;
  // Buffer, in den die Bitmap kopiert werden soll
  pucData         : ^USINT;
END_VAR
VAR_OUTPUT
  retval          : DINT;
END_VAR;
#define SDIAS_iGetBitmapOfDevices(p1,p2,p3,p4)  pSdias^.iGetBitmapOfDevices $ iGetBitmapOfDevices(p1,p2,p3,p4)


// From version 0x00002000

// iGetNodeHandle
FUNCTION __CDECL GLOBAL SDM_iGetNodeHandle
VAR_INPUT
  udManagerNumber : UDINT;
  pszHardwarePath : ^USINT;
  phNodeHandle : ^SDM_NODE_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetNodeHandle(p1,p2,p3)  pSdias^.SDM_iGetNodeHandle $ SDM_iGetNodeHandle(p1,p2,p3)


// iSendSdoRequestChannel
FUNCTION __CDECL GLOBAL SDM_iSendSdoRequestChannel
VAR_INPUT
  hManagerNodeHandle : SDM_NODE_HANDLE;
  // Channel number 0..
  udChannel       : UDINT;
  // Kommando, bestehend aus:
  // - Byte 0 (niederwertigstes Byte): SDO Kommando
  // - Byte 1                        : SDO Sub-Kommando
  // - Bytes 2 und 3                 : reserviert
  udCommand       : UDINT;
  // SDIAS-Adresse
  udSdiasAddress  : UDINT;
  // Länge der übergebenen Daten
  udDataLength    : UDINT;
  // Buffer mit den zu sendenden Daten
  pucData         : ^USINT;
  // Buffer, in dem das Handle f?r den SDO-Transfer retourniert wird
  pudSdoHandle    : ^UDINT;
END_VAR
VAR_OUTPUT
  retval          : DINT;
END_VAR;
#define SDIAS_iSendSdoRequestChannel(p1,p2,p3,p4,p5,p6,p7)  pSdias^.SDM_iSendSdoRequestChannel $ SDM_iSendSdoRequestChannel(p1,p2,p3,p4,p5,p6,p7)


// iReadSdoResponseChannel
FUNCTION __CDECL GLOBAL SDM_iReadSdoResponseChannel
VAR_INPUT
  // Handle für den SDO-Transfer (wird von iSendSdoRequest retourniert)
  udSdoHandle     : UDINT;
  // Größe des Buffers, in den die Daten der SDO Response kopiert werden
  udBufferLength  : UDINT;
  // Buffer, in den die Daten der SDO Response kopiert werden
  pucData         : ^USINT;
  // Länge der in der SDO Response empfangenen Daten
  pudDataLength   : ^UDINT;
END_VAR
VAR_OUTPUT
  // SDIAS_SDO_REQUEST_BUSY, wenn der SDO Request noch nicht abgearbeitet wurde, ansonsten
  // SDIAS_NO_ERROR oder Fehler
  retval        : DINT;
END_VAR;
#define SDIAS_iReadSdoResponseChannel(p1,p2,p3,p4)  pSdias^.SDM_iReadSdoResponseChannel $ SDM_iReadSdoResponseChannel(p1,p2,p3,p4)


// iGetInfoBlock
FUNCTION __CDECL GLOBAL SDM_iGetInfoBlock
VAR_INPUT
  hNodeHandle     : SDM_NODE_HANDLE;
  // Größe des Buffers, in den die Daten der InfoBlock kopiert werden
  udBufferLength  : UDINT;
  // Buffer, in den die Daten der InfoBlock kopiert werden
  pucData         : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetInfoBlock(p1,p2,p3)  pSdias^.SDM_iGetInfoBlock $ SDM_iGetInfoBlock(p1,p2,p3)


// iGetMappingInfo
FUNCTION __CDECL GLOBAL SDM_iGetMappingInfo
VAR_INPUT
  hNodeHandle     : SDM_NODE_HANDLE;
  // Größe des Buffers, in den die Daten der MappingInfo kopiert werden
  udBufferLength  : UDINT;
  // Buffer, in den die Daten der MappingInfo kopiert werden
  pucData         : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetMappingInfo(p1,p2,p3)  pSdias^.SDM_iGetMappingInfo $ SDM_iGetMappingInfo(p1,p2,p3)


// iGetMappingInfo
FUNCTION __CDECL GLOBAL SDM_iGetGeneralInfo
VAR_INPUT
  hNodeHandle     : SDM_NODE_HANDLE;
  // Größe des Buffers, in den die Daten der GeneralInfo kopiert werden
  udBufferLength  : UDINT;
  // Buffer, in den die Daten der GeneralInfo kopiert werden
  pucData         : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetGeneralInfo(p1,p2,p3)  pSdias^.SDM_iGetGeneralInfo $ SDM_iGetGeneralInfo(p1,p2,p3)


// iGetNodeProperty
FUNCTION __CDECL GLOBAL SDM_iGetNodeProperty
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udPropertyId : SDM_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetNodeProperty(p1,p2,p3)  pSdias^.SDM_iGetNodeProperty $ SDM_iGetNodeProperty(p1,p2,p3)


// iSetNodeProperties
FUNCTION __CDECL GLOBAL SDM_iSetNodeProperties
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^SDM_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iSetNodeProperties(p1,p2,p3)   pSdias^.SDM_iSetNodeProperties $ SDM_iSetNodeProperties(p1,p2,p3)


// iGetNodePropertyIndex
FUNCTION __CDECL GLOBAL SDM_iGetNodePropertyIndex
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udIndex : UDINT;
  udPropertyId : SDM_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetNodePropertyIndex(p1,p2,p3,p4)  pSdias^.SDM_iGetNodePropertyIndex $ SDM_iGetNodePropertyIndex(p1,p2,p3,p4)


// iSetNodePropertiesIndex
FUNCTION __CDECL GLOBAL SDM_iSetNodePropertiesIndex
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udIndex : UDINT;
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^SDM_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iSetNodePropertiesIndex(p1,p2,p3,p4)  pSdias^.SDM_iSetNodePropertiesIndex $ SDM_iSetNodePropertiesIndex(p1,p2,p3,p4)


// iGetNodePropertyIndexLen
FUNCTION __CDECL GLOBAL SDM_iGetNodePropertyIndexLen
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udIndex : UDINT;
  udPropertyId : SDM_PROPERTY_ID;
  udBufferLength : UDINT;
  pucBuf : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetNodePropertyIndexLen(p1,p2,p3,p4,p5)  pSdias^.SDM_iGetNodePropertyIndexLen $ SDM_iGetNodePropertyIndexLen(p1,p2,p3,p4,p5)


// iConfigurePllSyncOut
FUNCTION __CDECL GLOBAL SDM_iConfigurePllSyncOut
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udSyncOutId : UDINT;
  udOffset10ns : UDINT;
  udPeriodMultiplier : UDINT;
  udFrameCountThreshold : UDINT;
  udControlStatus : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iConfigurePllSyncOut(p1,p2,p3,p4,p5,p6)  pSdias^.SDM_iConfigurePllSyncOut $ SDM_iConfigurePllSyncOut(p1,p2,p3,p4,p5,p6)


// iAddDo
FUNCTION __CDECL GLOBAL SDM_iAddDo
VAR_INPUT
  hNodeHandle         : SDM_NODE_HANDLE;
  udDolType           : UDINT;
  udCmdType           : UDINT;
  udRetries           : UDINT;
  udIsWriteAcc        : UDINT;
  udModuleAddress     : UDINT;
  udDataLen           : UDINT;
  // Handle of DO to wait for. 0xFFFF for inactive
  hAddrVolatileWait : UDINT;
  phAddrWriteData : ^pvoid;
  phAddrReadData : ^pvoid;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iAddDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)  pSdias^.SDM_iAddDo $ SDM_iAddDo(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)


// iGetDataPointers
FUNCTION __CDECL GLOBAL SDM_iGetDataPointers
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udDolType : UDINT;
  ppvSendData : ^pvoid;
  ppvReceiveData : ^pvoid;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetDataPointers(p1,p2,p3,p4)  pSdias^.SDM_iGetDataPointers $ SDM_iGetDataPointers(p1,p2,p3,p4)


// iGetInputImage
FUNCTION __CDECL GLOBAL SDM_iGetInputImage
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udDolType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iGetInputImage(p1,p2)  pSdias^.SDM_iGetInputImage $ SDM_iGetInputImage(p1,p2)


// iSetOutputImage
FUNCTION __CDECL GLOBAL SDM_iSetOutputImage
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udDolType : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iSetOutputImage(p1,p2)  pSdias^.SDM_iSetOutputImage $ SDM_iSetOutputImage(p1,p2)


// iReportEvent
FUNCTION __CDECL GLOBAL SDM_iReportEvent
VAR_INPUT
  uiEvent : UDINT;
  pucEvntMsg : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iReportEvent(p1,p2)  pSdias^.SDM_iReportEvent $ SDM_iReportEvent(p1,p2)


// iAddDoDynamic
FUNCTION __CDECL GLOBAL SDM_iAddDoDynamic
VAR_INPUT
  hNodeHandle         : SDM_NODE_HANDLE;
  udDolType           : UDINT;
  udCmdType           : UDINT;
  udSubCmdType        : UDINT; 
  udRetries           : UDINT;
  udReadAddress       : UDINT;
  udReadDataLen       : UDINT;
  udWriteAddress      : UDINT;
  udWriteDataLen      : UDINT;
  // Handle of DO to wait for. 0xFFFF for inactive
  udAddrVolatileWait  : UDINT;
  hJumpDoHandle       : SDM_DO_HANDLE;
  udDoFlags           : UDINT;
  phDoHandle          : ^SDM_DO_HANDLE;
  phAddrWriteData     : ^pvoid;
  phAddrReadData      : ^pvoid;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iAddDoDynamic(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15)  pSdias^.SDM_iAddDoDynamic $ SDM_iAddDoDynamic(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15)


// iSetNodePropertyIndexLen
FUNCTION __CDECL GLOBAL SDM_iSetNodePropertyIndexLen
VAR_INPUT
  hNodeHandle : SDM_NODE_HANDLE;
  udIndex : UDINT;
  udPropertyId : SDM_PROPERTY_ID;
  udBufferLength : UDINT;
  pucBuf : ^USINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SDIAS_iSetNodePropertyIndexLen(p1,p2,p3,p4,p5)  pSdias^.SDM_iSetNodePropertyIndexLen $ SDM_iSetNodePropertyIndexLen(p1,p2,p3,p4,p5)


//HFILTER:1
#endif
//HFILTER:
