#ifndef SALAMANDERDELAY_H
#define SALAMANDERDELAY_H

#pragma once

#pragma pack (push, 1)
TYPE
    OS_SALAMANDERDEBUG : STRUCT
        udVersion         : UDINT;
        SwitchToXenomai   : pVoid;
        SwitchToLinux     : pVoid;
        Delay             : pVoid;
        Backtrace         : pVoid;
        GenerateAccess    : pVoid;
        // Version 3
        CallExit          : pVoid;
        CallExitWithOsError : pVoid;
        // Version 4
        HangTask          : pVoid;
        CrashTask         : pVoid;
        // Version 5
        GetDomain         : pVoid;
        GetRTThreadState  : pVoid;
        // Version 6
        MutexLock         : pVoid;
        MutexUnlock       : pVoid;
        // Version 7
        CallbackMethS     : pVoid;
        CallbackMethSS    : pVoid;
        CallbackMethSSS   : pVoid;
        CallbackMethSSSS  : pVoid;
        // Version 8
        PciLockerSetOffset : pVoid;
    END_STRUCT;
END_TYPE
#pragma pack (pop)

FUNCTION __CDECL GLOBAL P_Delay
VAR_INPUT
    us : UDINT;
END_VAR;


#define OSSD_Delay(itf,us)                IF itf THEN itf^.Delay $ P_Delay(us); END_IF

#endif
