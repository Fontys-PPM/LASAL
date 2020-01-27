(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_hardwaretree.h                                                                *)
(*                                                                                      *)
(* enthält die Definitionen für das Hardware-Tree Interface                             *)
(*                                                                                      *)
(*                                                                                      *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
//HFILTER:1
#ifndef __LSL_ST_HARDWARETREE
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define __LSL_ST_HARDWARETREE

//
// Defines
//

// Interface
#define INTERFACE_HARDWARETREE                "IHARDWARETREE"

// Escape-Sequenzen
#define HWT_ESCAPE_SEQU                       0x80
#define HWT_ESCAPE_VARAN                      0x81
#define HWT_ESCAPE_CDIAS                      0x82
#define HWT_ESCAPE_DIAS                       0x83
#define HWT_ESCAPE_MASTER                     0x84
#define HWT_ESCAPE_LVDS                       0x85
#define HWT_ESCAPE_LVDS_SUB                   0x86
#define HWT_ESCAPE_CANBUS                     0x87
#define HWT_ESCAPE_SDIAS                      0x88
#define HWT_ESCAPE_SMSR                       0x89
#define HWT_ESCAPE_DOMAIN                     0x90
#define HWT_ESCAPE_INTERNALBUS                0x91
#define HWT_ESCAPE_INTERNALBUS_SDIAS_SAFETY   0x92
#define HWT_ESCAPE_RTNET                      0x95
#define HWT_ESCAPE_MULTIVARAN                 0x96
#define HWT_ESCAPE_DRIVE                      0x97
#define HWT_ESCAPE_AXIS                       0x98
#define HWT_ESCAPE_VARAN_S2                   0x99

// Rückgabewerte
#define HARDWARETREE_OK                       0
#define HARDWARETREE_NOT_FOUND               -1
#define HARDWARETREE_NO_MUTEX                -2
#define HARDWARETREE_UNKNOWN_COMMAND         -3
#define HARDWARETREE_UNKNOWN_MASTERTYPE      -4
#define HARDWARETREE_MANAGER_NOT_EXISTS      -5
#define HARDWARETREE_PATH_INVALID            -6
#define HARDWARETREE_LENGTH_INVALID          -7
#define HARDWARETREE_MODULETYPE_INVALID      -8
#define HARDWARETREE_MASTERTYPE_NOT_EXISTS   -9
#define HARDWARETREE_BUFFER_TOO_SMALL        -10
#define HARDWARETREE_NO_TASK                 -11
#define HARDWARETREE_NO_MAILBOX              -12
#define HARDWARETREE_MAILBOX_FULL            -13
#define HARDWARETREE_TIMEOUT                 -14
#define HARDWARETREE_STATE_INVALID           -15
#define HARDWARETREE_DATA_NOT_RECEIVED       -16
#define HARDWARETREE_DISCONNECTED            -17
#define HARDWARETREE_BUFFER_FULL             -18
#define HARDWARETREE_TIMEOUT_RESPONSE        -19
#define HARDWARETREE_NO_MEMORY_ACCESS        -20
#define HARDWARETREE_CONTROL_INVALID         -21
#define HARDWARETREE_DPRAM_TOO_SMALL         -22
#define HARDWARETREE_MODULE_NOT_FOUND        -23
#define HARDWARETREE_NO_EVENT_SEMA           -24
#define HARDWARETREE_NO_SAFETY_MODULE        -25
#define HARDWARETREE_INVALID_PARAM           -26
#define HARDWARETREE_DM_ACTIVE               -27

//
// Interface
//
TYPE
  LSL_HARDWARETREE : STRUCT

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

  // setzen (speichern) This-Pointer
  iSetObjectThisp  : pVoid;

  // lesen This-Pointer
  iGetObjectThisp  : pVoid;

  // nicht für Applikation
  iReserved1       : pVoid;

  // Zugriffe via Data-Mover sperren
  iDataMoverDisable     : pVoid;
  
  // Zugriffe via Data-Mover aktivieren
  iDataMoverEnable      : pVoid;

  // Data-Mover als vollständig konfiguriert kennzeichnen
  iDataMoverConfigured  : pVoid;

  // Domainnummer holen
  ucGetMyDomain  : pVoid;
  
  // ab Version 0x00001004

  // Modulinfo laden über Adresse
  iHWTGetModuleInfo : pVoid;
  
  // Hardwarepfad laden
  iHWTGetPath   : pVoid;

  // ab Version 0x00001005
  // #iDataMoverConfigured gibt -27 zurück, wenn das Control-Register 
  // des Datamovers vom OS über Admin-Access gesetzt wird

  
  END_STRUCT;

END_TYPE

// iSetObjectThisp
FUNCTION __CDECL GLOBAL iSetObjectThisp
VAR_INPUT
  uiMaster  : UDINT;
  pucNode   : ^USINT;
  uiThis    : UDINT;
END_VAR
VAR_OUTPUT
  retval    : DINT;
END_VAR;
#define HWT_iSetObjectThisp(p1,p2,p3)  pHardwareTree^.iSetObjectThisp $ iSetObjectThisp(p1,p2,p3)


// iGetObjectThisp
FUNCTION __CDECL GLOBAL iGetObjectThisp
VAR_INPUT
  uiMaster  : UDINT;
  pucNode   : ^USINT;
END_VAR
VAR_OUTPUT
  uiThis    : UDINT;
END_VAR;
#define HWT_iGetObjectThisp(p1,p2)  pHardwareTree^.iGetObjectThisp $ iGetObjectThisp(p1,p2)


// iDataMoverDisable
FUNCTION __CDECL GLOBAL iDataMoverDisable
VAR_INPUT
  uiMaster      : UDINT;
  pucNode       : ^USINT;
END_VAR
VAR_OUTPUT
  retval        : DINT;
END_VAR;
#define HWT_iDataMoverDisable(p1,p2)  pHardwareTree^.iDataMoverDisable $ iDataMoverDisable(p1,p2)


// iDataMoverEnable
FUNCTION __CDECL GLOBAL iDataMoverEnable
VAR_INPUT
  uiMaster      : UDINT;
  pucNode       : ^USINT;
  pucControlWr  : ^USINT;
  pucControlRd  : ^USINT;
  uiActive      : UDINT;
  puiAdminCnt   : ^UDINT;
END_VAR
VAR_OUTPUT
  retval        : DINT;
END_VAR;
#define HWT_iDataMoverEnable(p1,p2,p3,p4,p5,p6)  pHardwareTree^.iDataMoverEnable $ iDataMoverEnable(p1,p2,p3,p4,p5,p6)


// iDataMoverConfigured
FUNCTION __CDECL GLOBAL iDataMoverConfigured
VAR_INPUT
  uiMaster        : UDINT;
  pucNode         : ^USINT;
  uiDPRamDataUsed : UDINT;
END_VAR
VAR_OUTPUT
  retval        : DINT;
END_VAR;
#define HWT_iDataMoverConfigured(p1,p2,p3)  pHardwareTree^.iDataMoverConfigured $ iDataMoverConfigured(p1,p2,p3)


// iGetMyDomain
FUNCTION __CDECL GLOBAL ucGetMyDomain
VAR_OUTPUT
  usDomain        : USINT;
END_VAR;
#define HWT_ucGetMyDomain()  pHardwareTree^.ucGetMyDomain $ ucGetMyDomain()


FUNCTION __CDECL GLOBAL iHWTGetModuleInfo
VAR_INPUT
  uiMaster  : UDINT;
  uiAdress  : UDINT;
  pOutData  : ^CHAR;
  pOutLen   : ^UDINT;
END_VAR
VAR_OUTPUT
  retval    : DINT;
END_VAR;
#define HWT_IGETMODULEINFO(uiMaster, uiAdress, pOutData, pOutLen) pHardwareTree^.iHWTGetModuleInfo $ iHWTGetModuleInfo(uiMaster, uiAdress, pOutData, pOutLen)


FUNCTION __CDECL GLOBAL iHWTGetPath
VAR_INPUT
  uiMaster  : UDINT;
  uiAddress : UDINT;
  pOutData  : ^CHAR;
  pOutLen   : ^UDINT;
END_VAR
VAR_OUTPUT
  retval    : DINT;
END_VAR;
#define HWT_IGETPATH(uiMaster, uiAdress, pOutData, pOutLen) pHardwareTree^.iHWTGetPath $ iHWTGetPath(uiMaster, uiAdress, pOutData, pOutLen)

//HFILTER:1
#endif
//HFILTER: