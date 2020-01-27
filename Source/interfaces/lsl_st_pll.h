(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_pll.h                                                                         *)
(*                                                                                      *)
(* enth�lt die Definitionen f�r das PLL Interface                                       *)
(*                                                                                      *)
(*                                                                                      *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
//HFILTER:1
#ifndef __LSL_ST_PLL
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define __LSL_ST_PLL



//
// Defines
//
#define PLL_TYPE_VERSION	0x00010001

// Interface
#define INTERFACE_PLL                       "IPLL"

// Ergebniscodes
// ok, kein Fehler
#define PLL_OK                            0
// PLL is not available
#define PLL_NOT_AVAIL                     -1
// ung�ltiger Parameter f�r den Daten-Buffer
#define PLL_INVALID_PARAM_DATA_BUFFER     -2
// ung�ltiger Parameter f�r das Modul (Hardwarepfad ung�ltig)
#define PLL_INVALID_PARAM_NODE            -3
// Invalid property for this command.
#define PLL_INVALID_PROPERTY              -4
// The get/set of the property failed
#define PLL_PROPERTY_ERROR                -5


TYPE
  PLL_PROPERTY_ID :
  (
    // PLL
    // Use with i[Get|Set]Propert[y|ies]
    PLL_PROP_SYSTEM_PERIOD_TIME_10NS,   //rw
    PLL_PROP_SYSTEM_PERIOD_MEASURED,    //r
    PLL_PROP_DELTA_SYSTEM_PERIOD_TIME,  //w
    PLL_PROP_DELTA_PHASE,               //w
    PLL_PROP_SYNC_TIME_FRAME_COUNTER,   //r
    PLL_PROP_IRQ_REGISTER,              //r
    PLL_PROP_STATUS_REGISTER,           //r
    PLL_PROP_CONTROL_REGISTER,          //w
    PLL_PROP_SYSTEM_PERIOD_DIVIDER,     //rw
    PLL_PROP_DEVICE_DELAY_TIME,         //w
    PLL_PROP_SHIFTED_PHASE,             //r
    
    // only for SyncOut
    PLL_PROP_SO_OFFSET_10NS,            //rw
    PLL_PROP_SO_PERIOD_MULTIPLIER,      //rw
    PLL_PROP_SO_FRAME_COUNT_THRESHOLD,  //rw
    PLL_PROP_SO_SYNC_OUT_ID,            //r 
    PLL_PROP_SO_CONTROL_STATUS_REGISTER,//rw
	
	// New since version 0x00010001
    PLL_PROP_MAX_SHIFTED_PHASE			//rw

	)$UDINT;
  
END_TYPE


TYPE
  PLL_PROPERTY_VALUE_PAIR : STRUCT

  // Name der Eigenschaft
  udPropertyId : PLL_PROPERTY_ID;
  // Wert der Eigenschaft
  udPropertyValue : UDINT;

  END_STRUCT;
END_TYPE

TYPE
  PLL_NODE_HANDLE : UDINT;
END_TYPE


//
// Interface
//
TYPE
  LSL_PLL : STRUCT

    //
    // Version
    //
    udVersion : UDINT;

    iGetNodeHandle : pVoid;

    iGetPLLProperty : pVoid;
    iSetPLLProperties : pVoid;
    iGetSyncOutProperty : pVoid;
    iSetSyncOutProperties : pVoid;
    iSetClientPllSync : pVoid;
  END_STRUCT;
END_TYPE


// iGetNodeHandle
FUNCTION __CDECL GLOBAL P_PLL_iGetNodeHandle
VAR_INPUT
  pszHardwarePath : ^USINT; // CPU String: String[0] = 1; String[1] = 0;
  phNodeHandle : ^PLL_NODE_HANDLE;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define PLL_iGetNodeHandle(pPLL,p1,p2)  pPLL^.iGetNodeHandle $ P_PLL_iGetNodeHandle(p1,p2)


// iGetPLLProperty
FUNCTION __CDECL GLOBAL P_PLL_iGetPLLProperty
VAR_INPUT
  hNodeHandle : PLL_NODE_HANDLE;
  udPropertyId : PLL_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define PLL_iGetPLLProperty(pPLL,p1,p2,p3)  pPLL^.iGetPLLProperty $ P_PLL_iGetPLLProperty(p1,p2,p3)


// iSetPLLProperties
FUNCTION __CDECL GLOBAL P_PLL_iSetPLLProperties
VAR_INPUT
  hNodeHandle : PLL_NODE_HANDLE;
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^PLL_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define PLL_iSetPLLProperties(pPLL,p1,p2,p3)   pPLL^.iSetPLLProperties $ P_PLL_iSetPLLProperties(p1,p2,p3)


// iGetSyncOutProperty
FUNCTION __CDECL GLOBAL P_PLL_iGetSyncOutProperty
VAR_INPUT
  hNodeHandle : PLL_NODE_HANDLE;
  udIndex : UDINT;
  udPropertyId : PLL_PROPERTY_ID;
  pudPropertyValue : ^UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define PLL_iGetSyncOutProperty(pPLL,p1,p2,p3,p4)  pPLL^.iGetSyncOutProperty $ P_PLL_iGetSyncOutProperty(p1,p2,p3,p4)


// iSetSyncOutProperties
FUNCTION __CDECL GLOBAL P_PLL_iSetSyncOutProperties
VAR_INPUT
  hNodeHandle : PLL_NODE_HANDLE;
  udIndex : UDINT;
  udPropertyCount : UDINT;
  psPropertyValuePairs : ^PLL_PROPERTY_VALUE_PAIR;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define PLL_iSetSyncOutProperties(pPLL,p1,p2,p3,p4)  pPLL^.iSetSyncOutProperties $ P_PLL_iSetSyncOutProperties(p1,p2,p3,p4)

// SetClientPllSync
FUNCTION __CDECL GLOBAL P_PLL_iSetClientPllSync
VAR_INPUT
  hNodeHandle : PLL_NODE_HANDLE;
  udSyncOutIDClient : UDINT;
  udSyncOutIDManager : UDINT;
  udMasterTime : UDINT;
  udClientTime : UDINT;
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define PLL_iSetClientPllSync(pPLL,p1,p2,p3,p4,p5) pPLL^.iSetClientPllSync $ P_PLL_iSetClientPllSync(p1,p2,p3,p4,p5)

//HFILTER:1
#endif
//HFILTER:
