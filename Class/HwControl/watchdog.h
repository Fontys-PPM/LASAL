#ifndef  __WATCHDOG_H
#pragma once
#define  __WATCHDOG_H

// Interface
#define INTERFACE_WATCHDOG                 "IWATCHDOG"

// defines for possible Error Codes
#define WD_ERR_NO                 0
#define WD_ERR_NO_WATCHDOG       -1
#define WD_ERR_WRONG_PROP        -2
#define WD_ERR_TASK_RUNNING      -3
#define WD_ERR_TASK_STOPMODE     -4
#define WD_ERR_TASK_START        -5
#define WD_ERR_WRONG_PARAM       -6


#define WD_PROP_APPL_WD           1        // the application take the wd trigger  param = 1 = disable auto trigger
#define WD_PROP_PRELOAD_VALUE     2        // set/get:
#define WD_PROP_TASK_START       10        // set: start auto trigger with param as delay im ticks
#define WD_PROP_TASK_STOP        11        // set stop auto trigger
#define WD_PROP_TASK_DELAY       12        // set/get: change delay param
#define WD_PROP_TASK_STATE       13        // get:


TYPE
  LSLAPI_IWATCHDOG : STRUCT
    udVersion		    : UDINT;    
    WD_Trigger		  : pVoid;
    WD_SetProperty	: pVoid;
    WD_GetProperty	: pVoid;
  END_STRUCT;
END_TYPE

////////////////////////////////////////////////////////////////////////////////
// LASAL Function Prototypes
////////////////////////////////////////////////////////////////////////////////
// Callback Prototype
FUNCTION __CDECL GLOBAL P_WD_SETPROPERTY
  VAR_INPUT
    Property  : UDINT;
    value  : UDINT;
  END_VAR
  VAR_OUTPUT
    retval  : DINT;
  END_VAR;

FUNCTION __CDECL GLOBAL P_WD_GETPROPERTY
  VAR_INPUT
    Property  : UDINT;
    value  : ^UDINT;
  END_VAR
  VAR_OUTPUT
    retval   : DINT;
  END_VAR;

FUNCTION __CDECL GLOBAL P_WD_TRIGGER
  VAR_OUTPUT
    retval   : DINT;
  END_VAR;

////////////////////////////////////////////////////////////////////////////////
// LASAL MACROS
////////////////////////////////////////////////////////////////////////////////
#define OS_WD_SETPROPERTY(pWATCHDOG,p1,p2) pWATCHDOG^.WD_SetProperty $ P_WD_SETPROPERTY(p1, p2)
#define OS_WD_GETPROPERTY(pWATCHDOG,p1,p2) pWATCHDOG^.WD_GetProperty $ P_WD_GETPROPERTY(p1, p2)
#define OS_WD_TRIGGER(pWATCHDOG) pWATCHDOG^.WD_Trigger $ P_WD_TRIGGER()

#endif
