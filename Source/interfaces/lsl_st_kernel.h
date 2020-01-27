//****************************************************************************/
//*                                                                          */
//*  File: LSL_ST_KERNEL.H                                                   */
//*  Date: SEP 17, 2001                                                      */
//*  By:                                                                     */
//*  Description:                                                            */
//*	KERNEL Information                                                   */
//*  Revision History:                                                       */
//*      Rev     By      Date        Description                             */
//*      ---     --      ----        -----------                             */
//*      1.00    MENK    17/09/01    Initial Version                         */
//*                                                                          */
//****************************************************************************/
#ifndef LSL_KERNEL_H
#pragma once
#define LSL_KERNEL_H

#pragma pack(push, 1)


TYPE
  SYSTEMKERNEL_APPLID		 : STRUCT
     WorkspaceID      : ARRAY[0..15] of CHAR;
     ProjectName      : ARRAY[0..8] of CHAR;
     ProjectDirectory :^CHAR;
     ActiveDATFile    :^CHAR;
     SystemDirectory  :^CHAR;
     status           : UDINT;
     LongProjectName  : ^USINT;
  END_STRUCT;

  SYSTEMKERNEL_APPEXCEPT	 : STRUCT
    // Exception Processing Data
    LastExceptionCode : UDINT;  // code of last exception
    ExpectionCount    : UDINT;  // count of exceptions
    SPMax             : UDINT;  // SPMax points to the address immediately following the stack area of the task
    SPMin             : UDINT;  // 
    MinStack          : UDINT;  // least number of bytes that has been free on a task's stack since it was created
    taskname          : ARRAY[0..15] of CHAR;  // Name of thread at exception
  END_STRUCT;

  SYSTEMKERNEL_APPLINK           : STRUCT
    projecttype       : UDINT;
    app_entrypoint    : UDINT;
    app_puser         : UDINT;
    top_modul         : pVoid;
    data_address      : UDINT;
    LinkTask          : pVoid;
    TopLinkerError    : pVoid;
    ActLinkerError    : pVoid;
    errormsg_counter  : UDINT;
    linkererror_mastercounter : UDINT;
    linkererror       : UDINT;
    CallBack          : pVoid;   // Call this after Linking
    modrefptr         : pVoid;   
    TaskName          : ARRAY[0..31] of CHAR;
  END_STRUCT;

  SYS_USERMEMORY                 : STRUCT
    usrCodeStart      : UDINT;  // Start address of User Code area
    usrCodeLength     : UDINT;  // Length of User Code area
    usrDataStart      : UDINT;  // Start address of User Data area
    usrDataLength     : UDINT;  // Length of User Data area
    codeprotected     : UDINT;  
    dataprotected     : UDINT;  
  END_STRUCT;

  LSLAPPLI_OSDATA               : STRUCT
    // Kernel Layer Data
    piCIL     : pVoid;      // a pointer to the CIL interface from the kernel
    // DIAS Device Data
    piDias     : pVoid;      // pointer to the main DIAS Bus master device interface
    // DLED Device Interface
    piDLed     : pVoid;      // LED device
    // User Memory Area Definition
    pUser     : pVoid;      // pointer to user mem def struct interface
    // Pointer to System Time Interface
    piSysTime     : pVoid;  // System Time interface
    // Pointer to System Queue Interface
    piSysQueue     : pVoid;  // System Queue interface
    // Pointer to LASAL Task Interface
    piTask     : pVoid;
    // Pointer to C Runtime Tinterface
    piCRT     : pVoid;
    // Pointer to LASAL System Service Interface  // by CGCS
    piSSR     : pVoid;
    // LASAL Diagnostic Interface Information
    piDiag     : pVoid;      // diagnostic Interface information
    // LASAL Linker Information 
    piLinker     : pVoid;
    // LASAL File Interface (V3.18)
    piLslFile     : pVoid;    // interface is OPTIONAL and may not exist!
    // LASALCOM Interface Pointer (V3.23)
    piLASALCOM     : pVoid;          // LASALCOM interface pointer
    // MAE interface pointer
    piLSE     : pVoid;
    // OS File I/O interface pointer
    piFILE     : pVoid;
    // OS-Terminal interface pointer (v4)
    piTerminal     : pVoid;
    // Printer API interface pointer (v4)
    piPrinter     : pVoid;
    // V24 API interface pointer (v4)
    piSerial     : pVoid;
    // FTP API interface pointer (v5)
    piFTP     : pVoid;
    // TCP API interface pointer (v5)
    piTCP     : pVoid;
  END_STRUCT;

  SYSTEMKERNEL_AWLINFO               : STRUCT
    debugbp  : pVoid;
  END_STRUCT;

  SYSTEMKERNEL_APP               : STRUCT
    pMain         : pVoid;         // pointer to main application function
    uiConfState   : UINT;
    runtime_activ : USINT;
    runtime       : USINT;
    runtimeinctstart  : USINT;
    loaderok      : UDINT;
    actualcywork  : UDINT;
    diaserrorenabled : UDINT;
    LSLTSK_Main   : pVoid;
    LSLTSK_MainTask : pVoid;
    executingmain : UDINT;
    ApplTask      : pVoid;
    RAMSaveFileEnabled : UDINT;
    status        : UDINT;
    ext_status    : UDINT;
    isrunrom      : UDINT;
    DebugStatus   : UDINT;
    HeapMAT       : pVoid;
    HeapLock      : pVoid;
    HeapLockName  : ARRAY[0..31] of CHAR;
    HeapInit      : DINT;
    lRTPeriod     : UDINT;
    RT_UpdateActive : UDINT;
    RT_Debugged     : UDINT;
    LSLTSK_RTTask   : pVoid;
    awl             : SYSTEMKERNEL_AWLINFO;

    RTRuntime       : USINT;
    RTRuntimeActive : USINT;
    RealtimeActive  : USINT;
    RTRuntimeDebug  : USINT;

    BTRuntime       : UDINT;
    BTRuntimeActive : USINT;

    LSLTSK_MainDebugIp   : pVoid;
  END_STRUCT;

// ... type for module-header-transmition
  SYSTEMKERNEL_APPTEMPHEADER		 : STRUCT
    CodeLength : UDINT;
    VersionMajor : UDINT;
    VersionMinor : UDINT;
    Kennung      : UDINT;
    ModuleId     : UDINT;
    reserve1     : UDINT;                  // must be divideable by 6 (for can-transmition)
  END_STRUCT;

  SYSTEMKERNEL_APPLOAD                   : STRUCT
    loadingpointer : pVoid;
    ModuleType     : UDINT;
    newmodul       : UDINT;
    dbgstatusbackup : UDINT;
    applstatusbackup : UDINT;
    tempheader      : SYSTEMKERNEL_APPTEMPHEADER;
  END_STRUCT;

  SYSTEMKERNEL_RTD		 : STRUCT
    loadingpointer   : pVoid;
    rtdaction : UDINT;
    totallength : UDINT;
    modid : UDINT;
    modulestart : pVoid;
    modulelen : UDINT;
    prevmodul : pVoid;
  END_STRUCT;

  LSLAPPHEAPINFO_TYPE		 : STRUCT
    startaddr : UDINT;
    totalsize : UDINT;
    usedmem   : UDINT;
    freemem   : UDINT;
  END_STRUCT;
  
  KERNELERRMSG_STR   : STRUCT
        index               : UDINT;
        msg                 : ARRAY [0..7,0..29] of CHAR;
  END_STRUCT;

  LSL_SYSVAR		 : STRUCT
        maxtime_rt 			: UDINT;
        avetime_rt 			: UDINT;
		maxtime_ct 			: UDINT;
		avetime_ct 			: UDINT;
        maxtime_bt 			: UDINT;
        avetime_bt 			: UDINT; 	  
        watch_rt   			: UDINT;
        avetime_dummy 		: UDINT; 	  
        applmeminfo   		: LSLAPPHEAPINFO_TYPE;
        appl          		: ^USINT;
        memwatcherenable	: UDINT;
        memheapmemory    	: UDINT;
        kernelsysteminfo 	: ARRAY [0..16#BF] of CHAR;
		TaskList      		: pVoid;
  		m0100         		: ARRAY [0..16#FF] of CHAR;
  		reg          		: ARRAY [0..16#47] of CHAR;
  		m0248         		: ARRAY [0..16#93] of CHAR;
        spmsgptr            : ^KERNELERRMSG_STR;
        kernelerrmsgptr     : ^KERNELERRMSG_STR;
  		rtosPatchVersion    : CHAR;
        m02e5               : CHAR;
  		AppHeapControl		: CHAR;
  		m02e7           	: CHAR;
  		cpuVersion			: UDINT;
  		rtosVersion			: UDINT;
  		userProgPointer		: UDINT;
  		userProgSize		: UDINT;
  		userDataPointer		: UDINT;
  		userDataSize		: UDINT;
  		m0300				: ARRAY [0..16#B8B] of CHAR;
  		LEDs				: CHAR;
  		vt01				: CHAR;
  		vt1					: CHAR;
  		vt10				: CHAR;
  		controlReg			: UDINT;
  		errorCntDias		: CHAR;
  		errorStationDias	: CHAR;
  		OnlineMap			: ARRAY [0..3] of CHAR;
  		VersionTime			: ^CHAR;
  END_STRUCT;

  SYSTEMKERNEL_APPLPOOL		 : STRUCT
     APP_ID              : SYSTEMKERNEL_APPLID;
     Startup             : pVOID; // Startup: while PLC is booting
     Reset               : pVoid; // RESET-Command
     Stop                : pVoid; // STOP-Command
     Init                : pVoid; // Prev Run Init-Command
     Run                 : pVoid; // RUNRAM
     Cont                : pVoid; // Continue Tasks
     Close               : pVoid; // ?????
     Error               : pVoid; // ?????
     APP_exception       : SYSTEMKERNEL_APPEXCEPT;
     APP_linker          : SYSTEMKERNEL_APPLINK;
     APP_load            : SYSTEMKERNEL_APPLOAD;
     Application         : SYSTEMKERNEL_APP;
     memory              : SYS_USERMEMORY;  // pointer to user mem def struct interface
     sysvar              : ^LSL_SYSVAR;
     osdata              : ^LSLAPPLI_OSDATA;
     CMDMailbox          : pVoid;
//  RTKTime                CMDMailboxTimer;
  END_STRUCT;

// Interface Struktur "HEAPMAT"
  HEAP_TYPE_		 : STRUCT
    HEAP_MAT            : pVoid;
    applmeminfo         : ^LSLAPPHEAPINFO_TYPE;
    CheckHeapList       : pVoid;
  END_STRUCT;

  BLOCKHEADER	 : STRUCT
    Next                : ^BLOCKHEADER;
    BlockSize           : UDINT;
  END_STRUCT;

  MAT_TYPE	     : STRUCT
    UsedList            : ^BLOCKHEADER;
    FreeList            : ^BLOCKHEADER;
  END_STRUCT;

  MAT_TYPE_V2    : STRUCT
    UsedList            : ^BLOCKHEADER;
    FreeList            : ^BLOCKHEADER;
    ctrlFlags           : UDINT;
    sizeofDbgHeapHdr    : UDINT;
    sizeofDbgHeapInfo   : UDINT;
  END_STRUCT;


END_TYPE
#pragma pack(pop)





TYPE
  SYS_SETTINGS               : STRUCT
#define DESTPLC_IPC_TEXT    0x0000001
#define DESTPLC_IPC_800     0x0000002
#define DESTPLC_IPC_1024    0x0000003
#define DESTPLC_PCD         0x0000004
#define DESTPLC_DSE         0x0000005
#define DESTPLC_DCP         0x0000006
#define DESTPLC_DCC080      0x0000007
#define DESTPLC_DCP645      0x0000008
#define DESTPLC_AK500       0x0000009
#define DESTPLC_TSTROM      0x000000A
#define DESTPLC_ELAN        0x0000010
//#define DESTPLC_ELAN800   0x0000011
#define DESTPLC_WINPC       0x0000012
#define DESTPLC_TERMINAL    0x0000013
#define DESTPLC_DTC281      0x0000014
//#define DESTPLC_ELAN_TEXT 0x0000015
//#define DESTPLC_ELAN_800  0x0000016
#define DESTPLC_ETT321      0x0000017
#define DESTPLC_HERZ        0x0000018
#define DESTPLC_ETT261      0x0000019
#define DESTPLC_ETT431      0x000001A
#define DESTPLC_WINPC_98    0x000001B // LARS, Standard PC, Win98/ME
#define DESTPLC_WINPC_NT    0x000001C // LARS, Standard PC, WinNT/Win2000/WinXP
#define DESTPLC_WINIPC_98   0x000001D // LARS, IPC, Win98/ME
#define DESTPLC_WINIPC_NT   0x000001E // LARS, IPC, WinNT/Win2000/WinXP
#define DESTPLC_IPC_320     0x000001F
#define DESTPLC_C_IPC       0x0000020 // C-IPC
#define DESTPLC_RK500       0x0000022
#define DESTPLC_CCL721      0x0000023
#define DESTPLC_VEMAGTE     0x0000024
#define DESTPLC_BDF2000     0x0000025
#define DESTPLC_STANDARDPC  0x0000026
#define DESTPLC_CCL081CET   0x0000027
#define DESTPLC_CCL081      0x0000028
#define DESTPLC_CCL722      0x0000029
#define DESTPLC_DCL642      0x000002A
#define DESTPLC_TEACHBOX    0x000002B
#define DESTPLC_DTC081      0x000002C
#define DESTPLC_DTC081_IP   0x000002D
#define DESTPLC_ETV         0x000002E
#define DESTPLC_HZS511      0x000002F
#define DESTPLC_AUW11X      0x0000030
#define DESTPLC_BDF2000_USB 0x0000031
#define DESTPLC_DTC101      0x0000032
#define DESTPLC_HZS515      0x0000033
#define DESTPLC_CCP511      0x0000034
#define DESTPLC_ETVEDGE     0x0000035
#define DESTPLC_IMX6        0x00010001 // IMX6: ARM-HW (ETV1035-H, HZS731, HGT1035, HGT0835 )

    // Type Of Destination PLC
    WHOAMI   : UDINT;
    // Task Stacks
    RT_Stack   : UDINT;
    CT_Stack   : UDINT;
    HP_Stack   : UDINT; // THR RTOS V5.06: High Priority User task object
    BG_Stack   : UDINT;
    Id_Stack   : UDINT;
    EXE_Stack   : UDINT;
    // Settings
    LNK_StartAddress   : UDINT;
    configstatus   : UDINT;
    stdDelay_cyclic : UINT;
    stdDelay_hpuser : UINT;
    stdDelay_bgvisu : UINT;
    stdMinperiod_bg : UINT;
    Background_Visu : USINT;
  END_STRUCT;


  SYS_USER_             : STRUCT
     memory : SYS_USERMEMORY;
     settings : SYS_SETTINGS;
     usrVersion : UDINT;     // Platform version code
     lClockTicks : UDINT;    // Clock interrupt ticks (uSecs)
     lRTPeriod : UDINT;      // Real time task period (mSecs)
     pDbgComPort : ARRAY[0..19] of CHAR;    // Pointer to Debug com port string
     lDbgComBaud : UDINT;    // Baud rate index
  END_STRUCT;
END_TYPE








#ifndef DUMMY_LOADER
VAR_EXTERNAL
   kernel (*AT % M0030*) :^SYSTEMKERNEL_APPLPOOL;
END_VAR
#endif
#endif
