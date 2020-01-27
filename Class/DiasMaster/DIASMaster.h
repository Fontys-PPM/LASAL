//
//	DIASMaster.h
//

#ifndef DIASMASTER_H
#pragma once
#define DIASMASTER_H

//#define DM_Profiler           //For some time measurements in CDIAS HW-Classes
//#define DiasMasterC_Profiler	//For some time measurements in DiasMasterC class

#ifdef DM_Profiler
  #ifndef DiasMasterC_Profiler
    #define DiasMasterC_Profiler  // DM_Profiler needs Types from DiasMasterC_Profiler
  #endif
#endif


// Definitions for installing Update-Calls
#ifndef SCANDEFS_H
#define SCANDEFS_H
  #define CALL_OPTION_RT_PRESCAN  2#0001
  #define CALL_OPTION_RT_POSTSCAN 2#0010
  #define CALL_OPTION_CYCLIC      2#0100
  #define CALL_OPTION_POST_INIT   2#1000
#endif // SCANDEFS_H

// NewInst-commands for Dias- and CDias- Modules

#define DM_CHECK_REQUIRED_ERROR     16#8001

#define DM_ADD_PAYLOAD_DO             16#8280
#define DM_ADD_PAYLOAD_MOVE_DO        16#8281
#define DM_GET_PAYLOAD_RETRY_TIMEOUT  16#8282


//*****************************************
#define CDIAS_MODULE        1
#define DIAS_MODULE         2

#define DEACTIVATED_LSL              16#FFFF
//*****************************************

#define DmControl       16#F002	// control register start/stop RISC 
#define DmState			    16#F003 // state realtime and cyclic on/off
#define DmError			    16#F005 // Read errors (Bus+Risc) 
#define DmCmdBuf1 		  16#F140 // single commandbuffer 1 
#define DmCmdBuf2 		  16#F150 // single commandbuffer 2
#define DmRtStartAdrM0 	16#F100 // start off realtime programm
#define DmRtProgCntrM0	16#F102 // IP of realtime
#define DmCyStartAdrM0	16#F108 // start off cyclic programm
#define DmCyProgCntrM0	16#F10A // IP of Cyclic  
#define DmPllPeriode 	  16#C103 // PLL
#define DmPllSyncAdr 	  16#C102 // " "
#define DmPllTmrAct  	  16#C104 // 50 usec tiks since Pll tik 	
#define DmPllSyncState  16#C105	// status of the PLL
#define DmPllSyncDel 	  16#C110 // Delay RtStart (in 50usec)
#define DmID 			      16#F00E // ID "IM" that we are talking to the right hardware
#define DmXver 			    16#F00D // Xilinx Version 
#define DmHver 			    16#F00C // Hardware version
#define DmCR_ProgMem 	  16#F00B // progsize in 512 byte size (1=512 byte 2=1024 etc.)
#define DmUserData 		  16#F180 // 32 byte for free use  
#define DmErrorCnt      16#F012 // counter for retrys  (this is brandnew)

// #BS 240903
#define DMWDTriggerMode	16#F013 // to set watchdog triggermode 0 = all async access | 1 = Wdregister
#define DMWDRegister	  16#F014 // trigger if DMWDTriggerMode = 1
#define	DMWDTimeBase 	  16#F008 // with 16ms base

// #BS 230903
#define DmConstTimeOut        600 // µs timeout on async dias access // #BS012 old value was 600 // #BS013 old value was 100


#define DmPLLisLock		16#01



#define DbRd8     16#A1
#define DbRd16    16#A2
#define DbRd32    16#A4 

#define DbWr8	    16#B0
#define DbWr16	  16#C0 
#define DbWr32	  16#E0 

#define DbRdKenn  16#99 

#define	DbIRQScan 16#91
#define DbEnd	    16#00
#define DbNop	    16#01
#define DbTmrEve  16#02
#define DbHostIrq 16#10
#define DbDelay   16#11

#define DbMov	    16#41 		   	 

#define DbCall	  16#36
#define DbRet	    16#03
#define DbJMP	    16#25 
#define DbCntrl   16#b8


#define DmTmrResso   25		   // tmr resolution =25 usek


#define Dmsingle 	  2
#define Dmcontinue 	1
#define	DMClearIRQ	2#10000		// #BS 29102003

#define VARAN_MOVER_DO_NO_RUN     0  // = VARAN_DO_NO_RUN 
#define VARAN_MOVER_DO_CONT_RUN   1  // = VARAN_DO_SINGLE_RUN
#define VARAN_MOVER_DO_SINGLE_RUN 2  // = VARAN_DO_CONT_RUN


// *********************************
// config registers
// *********************************

#define DmCallProg     16#8000
#define DmRealtime     16#0100  // bit 8 = 0 cyclic = 1 realtime
#define DmCyclic       16#0000  // bit 8 = 0  

#define DmRT 1
#define DmCY 0
#define DmCallRes  100   // how many calls are reserved in the Main

//SR 11.01.2005
//Time which need the IM to execute in ns			//Sheet (Taubner)	
#define	C_TimeRd8Bit			 6550				//5969			
#define C_TimeRd16Bit			 7850				//6875			
#define C_TimeRd32Bit			 9800				//approximate value according to dias master data sheet
#define	C_TimeWr8Bit			 5900				//5469			
#define	C_TimeWr16Bit			 7050				//6406			
#define	C_TimeWr32Bit			 8900				//approximate value according to dias master data sheet

#define	C_TimeReadKennung	 6950				//6594			
#define	C_TimeNop			  	  200									
#define	C_TimeMove			 	  600				//531	
#define	C_TimeIRQScan			 4500				//4188		

#define C_TimeCall			 	  375				//375				
#define	C_TimeRet			 	    375				//375				
#define	C_TimeControlWrite 5600				//5469
#define	C_TimeTimerEvent	 	400									
#define	C_TimeJump			 	  400				//313			

//SR 02.11.2006
#define DmMaxSyncs				4	

// For Payload support
// Default priorities for read/write/WaitForevent DOs 
#define DM_PRIORITY_DEFAULT         1000

#define DM_PRIORITY_READ_DO         9000  // Lowest Priority
#define DM_PRIORITY_WAIT_DO         5000
#define DM_PRIORITY_WRITE_DO        1000  // Highest Priority

#define DM_PRIORITY_SAFTY_READ_DO   1000
#define DM_PRIORITY_SAFTY_MOVE_DO   2000
#define DM_PRIORITY_SAFTY_WRITE_DO  3000

#define DM_PRIORITY_INVALID       16#FFFFFFFF // Used to check if no priority was specified

#define DM_CONTROL_ACCESS		0			//control access for installing default data objects
#define DM_MEMORY_ACCESS		1			//memory access for installing default data objects

// Memory Read
#define DM_CMD_MEMORY_READ               0x10

// Memory Write
#define DM_CMD_MEMORY_WRITE              0x20

// Memory Read Write
#define DM_CMD_MEMORY_READ_WRITE         0x30

// Control Read
#define DM_CMD_CONTROL_READ              0x40

// Control Write
#define DM_CMD_CONTROL_WRITE             0x50

// Control Read Write
#define DM_CMD_CONTROL_READ_WRITE        0x60


// Define that activate access exceptions,
// if a method is called that does not support ARM 
//#pragma message("LanSte 27.08.2013 09:08 \ Remove define for release")
//#ifdef _LSL_TARGETARCH_ARM
//#define DM_DEBUG_ARM
//#endif

//WP001
//***********************************Defines for time measurement**********************************
#ifdef DiasMasterC_Profiler

	#define DM_ProfilerDelay 		5000000				//Delay to wait before measurement starts in µs
	#define DM_LSLPOS_SYSTIME		16					//Offset to Pointer to SysTime Functions of OS
	#define DM_LSLSYSTIME_MICROSEC	20					//Offset to Pointer to OS_ReadMicrSec() - Function of OS

	//Time for time measurement code
	#define DM_CPUConstant		0 	//C-IPC with OS 1.1.50
	//#define DM_CPUConstant		1	//CCL911 with OS 1.1.51
	//#define DM_CPUConstant		37 	//CCL721 with OS 1.1.51

  #define  DMTIME_RT          0
  #define  DMTIME_CY          1
  #define  DMTIME_RTPOSTSCAN   2

	TYPE
		s_PROFILER_Time : struct
			_min 	: udint;
			_max 	: udint;
			avg 	: udint;
			run 	: udint;
			sum 	: udint;
			start 	: udint;
			stop 	: udint;
			diff 	: udint;
			init	: udint;
			initfl	: bool;
		end_struct;
	END_TYPE

#else

	TYPE
		s_PROFILER_Time : usint;
	END_TYPE

#endif

  TYPE
    t_DM_CMD_AddDO : STRUCT
      p_ud_DoHandle : ^UDINT;
      ud_ModuleHandle : UDINT;
      ud_b_DoRequired : UDINT;
      ud_DolType : UDINT;
      ud_Command : UDINT;
      ud_Priority : UDINT;
      ud_PreScalerCounterThreshold : UDINT;
      ud_PreScalerCounterStartValue : UDINT;
      p_ud_ReadData : ^UDINT;
      p_ud_WriteData : ^UDINT;
      ud_OffsetRead : UDINT;
      ud_LengthRead : UDINT;
      ud_OffsetWrite : UDINT;
      ud_LengthWrite : UDINT;
      pp_Enable : ^pVoid;
      p_ud_DataAddr_read   : ^HDINT;
      p_ud_DataAddr_write  : ^HDINT;
      ud_WritePayloadType : UDINT;
      p_UserDOHandle  :^UDINT;
    END_STRUCT;
  
  
    t_DM_CMD_AddMovDo : STRUCT
      p_ud_DoHandle : ^UDINT;
      ud_b_DoRequired : UDINT;
      ud_DolType : UDINT;
      ud_Priority : UDINT;
      ud_PreScalerCounterThreshold : UDINT;
      ud_PreScalerCounterStartValue : UDINT;
      ud_SourceReadDoHandle : UDINT;
      ud_SourceReadOffset : UDINT;
      ud_DestinationWriteDoHandle : UDINT;
      ud_DestinationWriteOffset : UDINT;
      ud_LengthMove : UDINT;
    END_STRUCT;
    
  END_TYPE
  
//*************************************************************************************************

#endif


(*
---------------------------------- CDIAS - Belegung -----------------------------------------------

1A------/MS					1B------/PERRES				1C------CLK32MHZ
2A------MOD-A2				2B------SCLK				2C------SDATA
3A------MOD-A1				3B------SYNC				3C------IRQ
4A------MOD-A0				4B------RDY					4C------/DEN
5A							5B------/RD					5C------/WR
6A							6B------A6					6C------A7
7A							7B------A4					7C------A5
8A							8B------A2					8C------A3
9A------GP3					9B------A0					9C------A1
10A-----GP2					10B-----D6					10C-----D7
11A-----GP1					11B-----D4					11C-----D5
12A-----GP0					12B-----D2					12C-----D3
13A-----+24V				13B-----D0					13C-----D1
14A-----+5V					14B-----+5V					14C-----+5V
15A-----GND					15B-----GND					15C-----GND
16A-----GND					16B-----GND					16C-----GND

---------------------------------- Befehle für den intelligenten Master ---------------------------

Kommando				OP-code		Byte 0		Byte 1		Byte 2		Byte 3
--------				-------		------		------		------		------

Read 8-bit				16#A1		Addr		Modul Addr	Result1
Read 16-bit				16#A2		Addr		Modul Addr	Result1		Result 2
Write 8-bit				16#B0		Addr		Modul Addr	Data 1
Write 16-bit			16#C0		Addr		Modul Addr	Data 1		Data 2
Read Kennung			16#99		Modul Addr	Result 1
Control Write			16#B8		Addr		Modul Addr	Data1
IRQ Scan				16#91		Modul Addr	Result 1

End Program				16#00
No Operation			16#01
Timer Event				16#02
Generate Host interrupt	16#10		number
Wait					16#11		Time/µs

Move					16#41			Source Address			Destination Address

Return					16#03
Call Subroutine			16#36			Address				Status
Jump Absolute			26#25			Jump Address

Call Status:
-----------
Bit0: 	Continue
Bit1:	Single
Bit2-3: Reserved
Bit4:	Clock Execution
Bit5:	Error

---------------------------------- Register Mapping für intelligenten Master ----------------------

IO Addr.	internal Addr.	Size	Description										Reset Value
--------	--------------	----	-----------										-----------

Ram:
-			0000 - 7FFF		7FFF	RAM												0

External Flash code page:
-			8000 - BFFF		3FFF	FLASH

Dias Master:
-			C000			1		Command - master nr. 0							00
-			C001			1		res. - master nr. 0								00
-			C002			1		Modul Addr. - master nr. 0						00
-			C003			1		Adrress - master nr. 0							00
-			C004			4		Data in - master nr. 0							00000000
-			C008			4		Data out - master nr. 0							00000000
-			C00C			4		reserved										00
-			C010 - C01C		16		master nr. 1									0
-			C020 - C02C		16		master nr. 2									0
-			C030 - C03C		16		master nr. 3									0

Pll-Timer:
-			C100			1		Manual Trigger									00
-			C101			1		reserved										0
-			C102			1		PLL sync in										0
-			C103			1		Pll periode										0
-			C104			1		Timer out (inc. 25µs)							0
-			C105			1		Pll status: Bit0: pll_lock, Bit1: pll_online	0
-			C106			10		reserved										0
-			C110			8		timer value (4Byte realtime, 4Byte cyclic)		0
-			C118			8		timer delay (4Byte realtime, 4Byte cyclic)		0

Smart media card:
350			C200			16		smart media card

Configuration register:
210			F000			2		Base Address									D000
212			F002			1		Dias Master Status:								04
										Bit0: Chip on/off
										Bit1: RISC runs/stop
										Bit2: halt on error
213			F003			1		Dias Master Status								00
										Bit0..3: Realtime on/off
										Bit4..7: Cyclic on/off
214			F004			1		Dias module nr with error						00
215			F005			1		Error number -> clear error flag				00
										00: no error
										01: dias error
										02:	illegal instruction
										03: illegaö user command
216			F006			1		User IRQ nr: -> clear user int					00
217			F007			1		IRQ error ISA interrupt number					00
										Bit0..3: error IRQ
										Bit4..7: user IRQ
										-0: no Interrupt
										-1: IRQ5
										-2:	IRQ7
										-3: IRQ10
										-4: IRQ11
										-5: IRQ12
										-6: IRQ15
218			F008			1		Watchdog Time(x 16ms)							0
219			F009			1		Flash page										0
21A			F00A			1		Flash config									0
21B			F00B			1		Programm Memory in 0,5 kByte					8
21C			F00C			1		Hardware Type: 01: Van Dorn Operator Panel		akt. Version
21D			F00D			1		Xilinx Version									akt. Version
21E			F00E			2		intelligent dias master - ID, ASCII "IM"		494D

Dias Master Register:
-			F010			1		Nr. of allowed Retries							3
-			F011			1		Timeout value/µs								6
-			F012			1		Retry counter all modules
-			F013			1		Watchdog mode
-			F014			1		Wathdogregister

RISC:
-			F100			2		realtime program start addr. - master 0			0000
-			F102			2		realtime program counter - master 0				0000
-			F104			2		realtime call stack - master 0					0000
-			F106			2		realtime reserved - master 0					0000
-			F108			2		cyclic program start addr. - master 0 			0000
-			F10A			2		cyclic program counter - master 0				0000
-			F10C			2		cyclic call stack - master 0					0000
-			F10E			2		cyclic reserved - master 0						0000
-			F110 - F11E		16		master 1										0
-			F120 - F12E		16		master 2										0
-			F130 - F13E		16		master 2										0

Dias Master single instruction:
-			F140			1		Status - single instr. 0						00
										Bit0: ready
										Bit1: error
										status byte must be cleared by user
-			F141			7		Command buffer - single instr. 0				00
-			F148			8		reserved - single instr. 0						00
-			F150 - F158		16		single instr. 1									0

User Data Area:
-			F180			32		user data										00

Dias Master Retry Counter
-			F200			64		Retry Counter - master 0						00
-			F240			64		Retry Counter - master 1						00
-			F280			64		Retry Counter - master 2						00
-			F2C0			64		Retry Counter - master 3						00

# External Flash:
-			F400			3		Adress Register									000000
-			F403			1		Data Register									00
-			F404			1		Config: Bit0 = auto increment					0
-			F405			1		Page register



*)
