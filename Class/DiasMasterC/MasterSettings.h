//************************************************************************************ 
//***                                                                             **** 
//***       These are some settings to configurate the Hardware                   **** 
//***                                                                             **** 
//************************************************************************************ 

// ws001: do not use #define TEMPMAX anymore! Use the respectives clients at the modules instead!
//#define TEMPMAX 	 			// if you define this value every temp channel give for max 16#80000010 (disconnected) 
//#define OldDiasXilinx			// if you define this the dias bus also work with older Xilinx modules
								// of type: DAM123, DBI011, DBI014, DTS152, SEW011
#define NumberLocalSyncs	10	// only possible with #define OldDiasXilinx cause old moduls don't work with global syncs
								// this number defines how many local syncs can be (only IM)
								// have to be activated for compiler !!!
//#define Dias_Master_PCI		// for PCI412 and PCI402 on normal PC and with IM (bypassing the port accesses)
#define CICXXX_Compress			// Support compressed adresses on CIC (for digital CDias-Modules)
#define MaxSyncModules		40	// Maximum Modules witch want to synchronize
//#define MaxWatchdog			// switch on to set the watchdog to a maximum (Fa. TIG)

// define this constant to trigger watchdog for 386 CPUs in cyclic not in realtime task (was default like this with versions < 1.50)
//#define TRIGGER_WD_386_IN_CYCLIC  