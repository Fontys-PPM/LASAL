(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_safety.h                                                                      *)
(*                                                                                      *)
(* enthält die Definitionen für das Safety Interface                                    *)
(*                                                                                      *)
(* Schnittstellenversion 0x1001:                                                        *)
(* - Funktion iPushSafetyTask hinzugefügt                                               *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
//HFILTER:1
#ifndef __LSL_ST_SAFETY
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define __LSL_ST_SAFETY

//
// Defines
//

// Interface
#define INTERFACE_SAFETY                "ISAFETY"

//Stati für Safety-SDO-Kommunikation
//Daten ungültig, Kopiervorgang noch nicht abgeschlossen
#define SAFETY_SDO_NO_DATA              0
//Daten gültig
#define SAFETY_SDO_DATA_VALID           1

// Ergebniscodes siehe lsl_st_hardwaretree.h

//
// Interface
//
TYPE
  LSL_SAFETY : STRUCT

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

  // hinzufügen des Moduls zum Safety-Task
  iAddModuleToSafetyTask : pVoid;

  // senden eines Safety-Kommandos (SDO) und retournieren der Antwort
  iSendRequest           : pVoid;

  // Wiederanstossen des Safety-Tasks
  iPushSafetyTask        : pVoid;

  // ab Version 0x00001002

  // Deaktivierung der Safety-Kommunikation, welche von den Safety-Modulen   
  // angestossen wird
  iDisableNonClassCommunication : pVoid;

  END_STRUCT;

END_TYPE


// iAddModuleToSafetyTask
FUNCTION __CDECL GLOBAL iAddModuleToSafetyTask
VAR_INPUT
  uiMaster  : UDINT;
  pucNode   : ^USINT;
  pucRdSDO  : ^UDINT;
  pucWrSDO  : ^UDINT;
END_VAR
VAR_OUTPUT
  retval    : DINT;
END_VAR;
#define SAFETY_iAddModuleToSafetyTask(p1,p2,p3,p4)  pISafety^.iAddModuleToSafetyTask $ iAddModuleToSafetyTask(p1,p2,p3,p4)

// iSendRequest
FUNCTION __CDECL GLOBAL iSendRequest
VAR_INPUT
  uiMaster     : UDINT;
  pucNode      : ^USINT;
  uiInLength   : UDINT;
  pucInput     : ^USINT;
  uiOutLength  : UDINT;
  pucOutput    : ^USINT;
END_VAR
VAR_OUTPUT
  retval       : DINT;
END_VAR;
#define SAFETY_iSendRequest(p1,p2,p3,p4,p5,p6)  pISafety^.iSendRequest $ iSendRequest(p1,p2,p3,p4,p5,p6)

// iPushSafetyTask
FUNCTION __CDECL GLOBAL iPushSafetyTask
VAR_INPUT
END_VAR
VAR_OUTPUT
  retval       : DINT;
END_VAR;
#define SAFETY_iPushSafetyTask()  pISafety^.iPushSafetyTask $ iPushSafetyTask()

// iDisableNonClassCommunication
FUNCTION __CDECL GLOBAL iDisableNonClassCommunication
VAR_INPUT
  uiMaster     : UDINT;
  pucNode      : ^USINT;
  uiDisable    : UDINT;
END_VAR
VAR_OUTPUT
  retval       : DINT;
END_VAR;
#define SAFETY_iDisableNonClassCommunication(p1,p2,p3)  pISafety^.iDisableNonClassCommunication $ iDisableNonClassCommunication(p1,p2,p3)

//HFILTER:1
#endif
//HFILTER:
