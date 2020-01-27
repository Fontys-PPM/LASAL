// ------------------------------------------------------------
// Sigmatek GmbH & CoKG
//   Version  Date      Author    Comment
//   1.0      23092005  pr        initial version
// ------------------------------------------------------------

#ifndef __LSL_ST_SYSTRACE
#pragma once
#define __LSL_ST_SYSTRACE

FUNCTION __CDECL GLOBAL P_Systrace_MakeTraceEntry
VAR_INPUT
    recType : UDINT;
    key : UDINT;
    data : UDINT;
END_VAR;

FUNCTION __CDECL GLOBAL P_Systrace_ReportTraceEvent
VAR_INPUT
    event : UDINT;
END_VAR;

FUNCTION __CDECL GLOBAL P_Systrace_AddTraceKeyVal
VAR_INPUT
    typeGroup : UDINT;
    key : UDINT;
    text : ^USINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION __CDECL GLOBAL P_Systrace_SetTraceBufSize
VAR_INPUT
    size : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION __CDECL GLOBAL P_Systrace_GetTraceBufSize
VAR_INPUT
    pSize : ^UDINT;
    pMaxSize : ^UDINT;
END_VAR;

#define OS_MakeTraceEntry(itf,type_,key,data)  IF itf THEN itf^.MakeTraceEntry $ P_Systrace_MakeTraceEntry(type_,key,data); END_IF
#define OS_ReportTraceEvent(itf,event)         IF itf THEN itf^.ReportTraceEvent $ P_Systrace_ReportTraceEvent(event); END_IF
#define OS_AddTraceKeyVal(itf,group,key,text)  IF itf THEN itf^.AddTraceKeyVal $ P_Systrace_AddTraceKeyVal(group,key,text); END_IF
#define OS_SetTraceBufSize(itf,size)           IF itf THEN itf^.SetTraceBufSize $ P_Systrace_SetTraceBufSize(size); END_IF
#define OS_GetTraceBufSize(itf,pSize,pMaxSize) IF itf THEN itf^.GetTraceBufSize $ P_Systrace_GetTraceBufSize(pSize,pMaxSize); END_IF

#pragma pack (push, 1)
TYPE
    OS_SYSTRACE : STRUCT
        udVersion           : UDINT;
        size                : UDINT;
        MakeTraceEntry      : pVoid;
        ReportTraceEvent    : pVoid;
        AddTraceKeyVal      : pVoid;
        SetTraceBufSize     : pVoid;
        GetTraceBufSize     : pVoid;
    END_STRUCT;
END_TYPE
#pragma pack (pop)

//
// Trace-Record type-groups
// 
#define TRECGRP_LSE0        16#0080
#define TRECGRP_LSE1        16#0100
#define TRECGRP_USER0       16#0200
#define TRECGRP_USER1       16#0400

//
// Trace-Events
// 
#define TEVENT_LSE0         16#00000040
#define TEVENT_LSE1         16#00000080
#define TEVENT_USER0        16#00000100
#define TEVENT_USER1        16#00000200

#endif
