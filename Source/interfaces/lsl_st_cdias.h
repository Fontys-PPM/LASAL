#ifndef _LSL_ST_CDIAS_IRQ_H
#pragma once
#define _LSL_ST_CDIAS_IRQ_H



#define CDIAS_IRQ_LIST_FULL     -2500
#define CDIAS_IRQ_INSTALLED     -2501
#define CDIAS_IRQ_NO_MEM        -2502
#define CDIAS_IRQ_PTR_NIL       -2503
#define CDIAS_IRQ_NR_INVALID    -2504


TYPE
  LSL_CDIAS_IRQ   :STRUCT
    Install_CDIAS_IRQ     : pVoid;
    Watchdog_Trigger      : pVoid;
Delete_All_CDIAS_IRQs     : pVoid;
  END_STRUCT;
END_TYPE



FUNCTION GLOBAL __cdecl P_INSTALL_CDIAS_IRQ
VAR_INPUT
  irqnr     : UINT;
  actionptr : pVoid;
  thisptr   : pVoid;
END_VAR
VAR_OUTPUT
  retval    : DINT;
END_VAR;
#define OS_INSTALL_CDIAS_IRQ(p1, p2, p3) lsl_cdias_irq^.Install_CDIAS_IRQ $ P_INSTALL_CDIAS_IRQ(p1, p2, p3)

FUNCTION GLOBAL __cdecl P_WATCHDOG_TRIGGER;
#define OS_WATCHDOG_TRIGGER() lsl_cdias_irq^.Watchdog_Trigger $ P_WATCHDOG_TRIGGER()


#endif  //_LSL_ST_CDIAS_IRQ_H
