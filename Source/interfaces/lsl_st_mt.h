
#ifndef  __LSL_ST_MT_H
#pragma once
#define  __LSL_ST_MT_H

#define MT_MIN_PRIORITY 1       // Taskpriority
#define MT_MAX_PRIORITY 14


TYPE 
   MT_TASKHANDLE : pVoid;
   MT_SEMAHANDLE : pVoid;
   MT_MAILBOX    : pVoid;

(* Task states *)
   LSL_MT_TASKSTATE : (
               MTASKSTATE_READY,
               MTASKSTATE_CURRENT,
               MTASKSTATE_SUSPENDED,
               MTASKSTATE_DELAYING,
               MTASKSTATE_BLOCKED_WAIT,
               MTASKSTATE_TIMED_WAIT,
               MTASKSTATE_BLOCKED_PUT,
               MTASKSTATE_BLOCKED_GET,
               MTASKSTATE_TIMED_PUT,
               MTASKSTATE_TIMED_GET,
               MTASKSTATE_BLOCKED_SEND,
               MTASKSTATE_BLOCKED_RECEIVE,
               MTASKSTATE_TIMED_SEND,
               MTASKSTATE_TIMED_RECEIVE,
               MTASKSTATE_DEADLOCKED,
               MTASKSTATE_ILLEGAL,
               MTASKSTATE_TERMINATED,
			   MTASKSTATE_RUNNING			// 17: new state for Multi-Core CPUs: task on other core is running
			   );
               
(* Semaphore types *)
   LSL_MT_SEMATYPE : (
               MTSEMATYPE_COUNTING,
               MTSEMATYPE_RESOURCE,
               MTSEMATYPE_BINARY,
               MTSEMATYPE_EVENT,
               MTSEMATYPE_MUTEX);
   
   LSL_MT_TYPE : STRUCT
                    version:              UDINT;
		(* Advanced Function *)
   		    MT_GetLastError:      pVoid;
   		    MT_GetTime:           pVoid; // Aktuelle Scheduler Zeit in msec

		(* TASK Functions: Creation, Termination, Intertask Communication, Blocking,...*)
                    MT_CreateThread :     pVoid;
                    MT_TerminateTask:     pVoid;
                    MT_Suspend:           pVoid;
                    MT_Resume:            pVoid;
                    MT_CurrentTaskHandle: pVoid;
                    MT_GetTaskState:      pVoid;
                    MT_SetPriority:       pVoid;
                    MT_GetTaskPrio:       pVoid;
                    MT_GetTaskStack:      pVoid;
                    MT_GetMinStack:       pVoid;
                    MT_Delay:             pVoid;
                    MT_DelayUntil:        pVoid;
                    MT_Send:              pVoid;
                    MT_SendCond:          pVoid;
                    MT_SendTimed:         pVoid;
                    MT_Receive:           pVoid;
                    MT_ReceiveCond:       pVoid;
                    MT_ReceiveTimed:      pVoid;
		
		(* Semaphore Functions: Creation, Termination, Signaling, Blocking,...*)
                    MT_CreateSemaphore:   pVoid;
                    MT_DeleteSemaphore:   pVoid;
                    MT_SemaValue:         pVoid;
                    MT_ResourceOwner:     pVoid;
                    MT_Signal:            pVoid;
                    MT_Pulse:             pVoid;
                    MT_Wait:              pVoid;
                    MT_WaitCond:          pVoid;
                    MT_WaitTimed:         pVoid;
                    MT_ResetEvent:        pVoid;
		    
		(* Mailbox Functions: Creation, Termination, Message Passing, Blocking,...*)
                    MT_CreateMailbox:     pVoid;
                    MT_DeleteMailbox:     pVoid;
                    MT_ClearMailbox:      pVoid;
                    MT_Messages:          pVoid;
                    MT_Put:               pVoid;
                    MT_PutFront:          pVoid;
                    MT_Get:               pVoid;
                    MT_PutCond:           pVoid;
                    MT_PutFrontCond:      pVoid;
                    MT_GetCond:           pVoid;
                    MT_NextCond:          pVoid;
                    MT_PutTimed:          pVoid;
                    MT_PutFrontTimed:     pVoid;
                    MT_GetTimed:          pVoid;

                    // version >= 0x00010002
                    MT_GetTaskPrioByID:   pVoid;

                    // version >= 0x00010004
                    MT_DelayUS:           pVoid;
                 END_STRUCT;
END_TYPE

(* Flags for RTKOpenSemaphore *)
#define MTSEMACREATE_SEARCH          1             // Search for Semaphore and create it if not available
#define MTSEMACREATE_FAIL_NOT_FOUND  2             


(* Task flags for RTKCreateThread *)
#define MT_TASK_SUSPENDED            16#00000001   // create task in suspended state
#define MT_TASK_MATH_CONTEXT         16#00000002   // maintain math context
#define MT_TASK_NO_MATH_CONTEXT      16#00000004   // no math context
#define MT_TASK_SAVETHIS             16#00000008   // input parmaeter is LASAL - thispointer

(* Task ID´s for MT_GetTaskPrioByID *)
#define MT_TASKID_RT         1
#define MT_TASKID_CT         2
#define MT_TASKID_BT         3

(* Possible Return Values of LASAL USER MT Functions *)
#define MTERROR_NONE         0                     // No Error
#define MTERROR_NOMEM       -1                     // No more memory to run this function, e.g. internal alloc failed
#define MTERROR_NOFCT       -2                     // CreateTask needs a valid taskfunction
#define MTERROR_FCTNOTINMEM -3                     // CreateTask needs a taskfunction placed in LASAL Code Memory
#define MTERROR_WRONGPRIOR  -4                     // CreateTask only supports priors from 1 .. 14
#define MTERROR_STACK       -5                     // CreateTask only support stacksize lower than 0x4000
#define MTERROR_NAME        -6                     // CreateTask, Mailbox or Semaphore needs a valid name
#define MTERROR_NAMEUSED    -7                     // CreateTask, Mailbox or Semaphore name already in use
#define MTERROR_HANDLE      -8                     // Handle not found in OS-List => not valid
#define MTERROR_NOTALLOWED  -9                     // MT-Function not allowed in this TaskContext
#define MTERROR_MESSAGESIZE -10                    // Mailbox need a valid messagesize
#define MTERROR_DATA        -11                    // Pointer to Data is not valid
#define MTERROR_PTR         -12                    // Invalid pointer, parameter or internal
#define MTERROR_TASKID      -13                    // Invalid task id, id not found
#define MTERROR_NOTASK      -14                    // Task does not exist
#define MTERROR_NOIFFNC     -15                    // Interface function is not available







////////////////////////////////////////////////////////////////////////////////
// LASAL PROTOTYPES
////////////////////////////////////////////////////////////////////////////////
// TASK Functions: Creation, Termination, Intertask Communication, Blocking,...
//------------------------------------------------------------------------------
FUNCTION GLOBAL __cdecl P_MT_CREATETHREAD
VAR_INPUT
   taskfunction0 : pVoid;
   priority0     : UDINT;
   stackSize0    : UDINT;
   flags0        : UDINT;
   parameter0    : pVoid;
   name0         : ^char;
END_VAR
VAR_OUTPUT 
	ret0          : MT_TASKHANDLE;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_TERMINATETASK
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SUSPEND
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_RESUME
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_CURRENTTASKHANDLE
VAR_OUTPUT 
	ret0 : MT_TASKHANDLE;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETTASKSTATE
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0 : LSL_MT_TASKSTATE;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SETPRIORITY
VAR_INPUT
	handle0 : MT_TASKHANDLE;
  priority0 : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETTASKPRIO
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETTASKSTACK
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETMINSTACK
VAR_INPUT
	handle0 : MT_TASKHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_DELAY
VAR_INPUT
	timeout0 : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_DELAYUS
VAR_INPUT
	timeout0 : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_DELAYUNTIL
VAR_INPUT
	timeout0 : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SEND
VAR_INPUT
	handle0 : MT_TASKHANDLE;
  data0 : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SENDCOND
VAR_INPUT
	handle0 : MT_TASKHANDLE;
  data0 : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SENDTIMED
VAR_INPUT
	handle0 : MT_TASKHANDLE;
  data0 : pVoid;
  timeout0: UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_RECEIVE
VAR_INPUT
  data0 : pVoid;
  datalengt0 : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_RECEIVECOND
VAR_INPUT
  data0 : pVoid;
  datalengt0 : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_RECEIVETIMED
VAR_INPUT
  data0 : pVoid;
  datalengt0 : UDINT;
  timeout0: UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;






////////////////////////////////////////////////////////////////////////////////
// Semaphore Functions: Creation, Termination, Signaling, Blocking,...
//------------------------------------------------------------------------------
FUNCTION GLOBAL __cdecl P_MT_CREATESEMAPHORE
VAR_INPUT
   type0 : LSL_MT_SEMATYPE;
   init0 : UDINT;
   flags0: UDINT;
   name0 : ^char;
END_VAR
VAR_OUTPUT 
	ret0          : MT_SEMAHANDLE;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_DELETESEMAPHORE
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SEMAVALUE
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_RESOURCEOWNER
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0   : MT_TASKHANDLE;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_SIGNAL
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PULSE
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_WAIT
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_WAITCOND
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_WAITTIMED
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
  timeout0:UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_RESETEVENT
VAR_INPUT
	handle0 : MT_SEMAHANDLE;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;



////////////////////////////////////////////////////////////////////////////////
// Mailbox Functions: Creation, Termination, Message Passing, Blocking,...
//------------------------------------------------------------------------------
FUNCTION GLOBAL __cdecl P_MT_CREATEMAILBOX
VAR_INPUT
   messagelen0 : UDINT;
   messageslots0 : UDINT;
   name0 : ^char;
END_VAR
VAR_OUTPUT 
	ret0          : MT_MAILBOX;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_DELETEMAILBOX
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_CLEARMAILBOX
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_MESSAGES
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
END_VAR
VAR_OUTPUT 
	ret0          : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PUT
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PUTFRONT
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GET
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PUTCOND
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PUTFRONTCOND
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETCOND
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_NEXTCOND
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PUTTIMED
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
   timeout0   : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_PUTFRONTTIMED
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
   timeout0   : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETTIMED
VAR_INPUT
	 mbhandle0  : MT_MAILBOX;
   data0      : pVoid;
   timeout0   : UDINT;
END_VAR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;







////////////////////////////////////////////////////////////////////////////////
// Advanced Functions
//------------------------------------------------------------------------------
FUNCTION GLOBAL __cdecl P_MT_GETLASTERROR
VAR_OUTPUT 
	ret0          : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_MT_GETTIME
VAR_OUTPUT 
	ret0          : UDINT;
END_VAR;

















////////////////////////////////////////////////////////////////////////////////
// LASAL MACROS
////////////////////////////////////////////////////////////////////////////////
// TASK Functions: Creation, Termination, Intertask Communication, Blocking,...
//------------------------------------------------------------------------------
#define OS_MT_CreateThread(p1, p2, p3, p4, p5, p6) MT_API^.MT_CreateThread $ P_MT_CreateThread(p1,p2,p3,p4,p5,p6)
#define OS_MT_TerminateTask(p1) MT_API^.MT_TerminateTask $ P_MT_TerminateTask(p1)
#define OS_MT_Suspend(p1) MT_API^.MT_Suspend $ P_MT_Suspend(p1)
#define OS_MT_Resume(p1) MT_API^.MT_Resume $ P_MT_Resume(p1)
#define OS_MT_CurrentTaskHandle MT_API^.MT_CurrentTaskHandle $ P_MT_CurrentTaskHandle
#define OS_MT_GetTaskState(p1) MT_API^.MT_GetTaskState $ P_MT_GetTaskState(p1)
#define OS_MT_SetPriority(p1,p2) MT_API^.MT_SetPriority $ P_MT_SetPriority(p1,p2)
#define OS_MT_GetTaskPrio(p1) MT_API^.MT_GetTaskPrio $ P_MT_GetTaskPrio(p1)
#define OS_MT_GetTaskStack(p1) MT_API^.MT_GetTaskStack $ P_MT_GetTaskStack(p1)
#define OS_MT_GetMinStack(p1) MT_API^.MT_GetMinStack $ P_MT_GetMinStack(p1)
#define OS_MT_Delay(p1) MT_API^.MT_Delay $ P_MT_Delay(p1)
#define OS_MT_DelayUS(p1) MT_API^.MT_DelayUS $ P_MT_DelayUS(p1)
#define OS_MT_DelayUntil(p1) MT_API^.MT_DelayUntil $ P_MT_DelayUntil(p1)
#define OS_MT_Send(p1,p2) MT_API^.MT_Send $ P_MT_Send(p1,p2)
#define OS_MT_SendCond(p1,p2) MT_API^.MT_SendCond $ P_MT_SendCond(p1,p2)
#define OS_MT_SendTimed(p1,p2,p3) MT_API^.MT_SendTimed $ P_MT_SendTimed(p1,p2,p3)
#define OS_MT_Receive(p1,p2) MT_API^.MT_Receive $ P_MT_Receive(p1,p2)
#define OS_MT_ReceiveCond(p1,p2) MT_API^.MT_ReceiveCond $ P_MT_ReceiveCond(p1,p2)
#define OS_MT_ReceiveTimed(p1,p2,p3) MT_API^.MT_ReceiveTimed $ P_MT_ReceiveTimed(p1,p2,p3)


////////////////////////////////////////////////////////////////////////////////
// Semaphore Functions: Creation, Termination, Signaling, Blocking,...
//------------------------------------------------------------------------------
#define OS_MT_CreateSemaphore(p1, p2, p3, p4) MT_API^.MT_CreateSemaphore $ P_MT_CreateSemaphore(p1,p2,p3,p4)
#define OS_MT_DeleteSemaphore(p1) MT_API^.MT_DeleteSemaphore $ P_MT_DeleteSemaphore(p1)
#define OS_MT_SemaValue(p1) MT_API^.MT_SemaValue $ P_MT_SemaValue(p1)  
#define OS_MT_ResourceOwner(p1) MT_API^.MT_ResourceOwner $ P_MT_ResourceOwner(p1)  
#define OS_MT_Signal(p1) MT_API^.MT_Signal $ P_MT_Signal(p1)
#define OS_MT_Pulse(p1) MT_API^.MT_Pulse $ P_MT_Pulse(p1)
#define OS_MT_Wait(p1) MT_API^.MT_Wait $ P_MT_Wait(p1)
#define OS_MT_WaitCond(p1) MT_API^.MT_WaitCond $ P_MT_WaitCond(p1)
#define OS_MT_WaitTimed(p1, p2) MT_API^.MT_WaitTimed $ P_MT_WaitTimed(p1, p2)
#define OS_MT_ResetEvent(p1) MT_API^.MT_ResetEvent $ P_MT_ResetEvent(p1)


////////////////////////////////////////////////////////////////////////////////
// Mailbox Functions: Creation, Termination, Message Passing, Blocking,...
//------------------------------------------------------------------------------
#define OS_MT_CreateMailbox(p1, p2, p3) MT_API^.MT_CreateMailbox $ P_MT_CreateMailbox(p1,p2,p3)
#define OS_MT_DeleteMailbox(p1) MT_API^.MT_DeleteMailbox $ P_MT_DeleteMailbox(p1)
#define OS_MT_ClearMailbox(p1) MT_API^.MT_ClearMailbox $ P_MT_ClearMailbox(p1)
#define OS_MT_Messages(p1) MT_API^.MT_Messages $ P_MT_Messages(p1)
#define OS_MT_Put(p1,p2) MT_API^.MT_Put $ P_MT_Put(p1,p2)
#define OS_MT_PutFront(p1,p2) MT_API^.MT_PutFront $ P_MT_PutFront(p1,p2)
#define OS_MT_Get(p1,p2) MT_API^.MT_Get $ P_MT_Get(p1,p2)
#define OS_MT_PutCond(p1,p2) MT_API^.MT_PutCond $ P_MT_PutCond(p1,p2)
#define OS_MT_PutFrontCond(p1,p2) MT_API^.MT_PutFrontCond $ P_MT_PutFrontCond(p1,p2)
#define OS_MT_GetCond(p1,p2) MT_API^.MT_GetCond $ P_MT_GetCond(p1,p2)
#define OS_MT_NextCond(p1,p2) MT_API^.MT_NextCond $ P_MT_NextCond(p1,p2)
#define OS_MT_PutTimed(p1,p2,p3) MT_API^.MT_PutTimed $ P_MT_PutTimed(p1,p2,p3)
#define OS_MT_PutFrontTimed(p1,p2,p3) MT_API^.MT_PutFrontTimed $ P_MT_PutFrontTimed(p1,p2,p3)
#define OS_MT_GetTimed(p1,p2,p3) MT_API^.MT_GetTimed $ P_MT_GetTimed(p1,p2,p3)


////////////////////////////////////////////////////////////////////////////////
// Advanced Functions
//------------------------------------------------------------------------------
#define OS_MT_GetLastError MT_API^.MT_GetLastError $ P_MT_GetLastError
#define OS_MT_GetTime MT_API^.MT_GetTime $ P_MT_GetTime

#endif
