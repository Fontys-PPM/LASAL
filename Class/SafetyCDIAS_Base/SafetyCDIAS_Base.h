//defines for safety C-DIAS modules

#ifndef SAFETYCDIAS_BASE_H
#pragma once
#define SAFETYCDIAS_BASE_H

#ifndef SAFETY_PROTOCOL_ANALYZER_ACTIVATED
//  #define SAFETY_PROTOCOL_ANALYZER_ACTIVATED
  #ifdef SAFETY_PROTOCOL_ANALYZER_ACTIVATED
    #pragma message("Safety Protocol Analyzer activated! Needs more CPU ressources!")
  #endif
#endif

// maximum number of input PDOs (modules from which this module gets PDOs)
#define PDO_MAX_NUMBER  100

// maximum number of routing elements for one object
#define MAX_NUMBER_ROUT_ELEMENTS  100

//#define SAFETY_OVER_DIAS

//define safety IDs for modules
#define CSCP01x_ID      100
#define CSDI16x_ID      101
#define CSTO08x_ID      102

// we need this for compatibility reasons
   #define CSCP011_ID    100
   #define CSDI161_ID    101
   #define CSTO081_ID    102



//define safety VARIANTs for modules
#define CSCP011_Preliminary   1
#define CSCP011_Series      129
#define CSCP012_Series      130  
#define CSDI161_Preliminary   1
#define CSDI161_Series      129  
#define CSDI162_Series      130  
#define CSTO081_Preliminary   1  
#define CSTO081_Series      129  
#define CSTO082_Series      130  


// define input filter in cycles (waits 5 cycles before status 0 is overtaken from firmware)
#define SAFETY_INPUT_FILTER     5 // put this line under comment if you don't want a filter in software

// sync delay times in µs (the cdias sync will be delayed for some safety modules to start working at a time where data are consistent) should work fine for all cycle times
// 125µs has to be added to get to the cdias sync (according to FPGA department)
#define SYNC_OFFSET_NO_DELAY          125
#define SYNC_OFFSET_DELAY_OUTPUTS     625

//define offsets for address mapping of CDIAS register
#define OFFSET_SPDO_DATA          16#00
#define OFFSET_SSDO_DATA          16#80
#define OFFSET_STDO_DATA          16#C8
#define OFFSET_LED                16#E0
#define OFFSET_STDO_STATUS        16#E6
#define OFFSET_SPDO_LENGTH        16#E7
#define OFFSET_STDO_STATUS_WRITE  16#E9

#define OFFSET_SYNC_IRQ_DELAY     16#EA
#define OFFSET_UNSAFE_VAR         16#EC

(*
OFFSET_TIMESYNC_HANDSHAKE
Bit0: 1 = HWK start the time synchronisation (is 0 if any of the modules doesn't support this feature, which can be detected via FPGA & FW Version)
Bit1: 1 = HWK wants the module to start it's synchronisation (the module resets this bit after the synchronisation is finished)
*)
#define OFFSET_TIMESYNC_HANDSHAKE 16#EE
#define OFFSET_FAST_UNSAFE_IOS    16#EF

#define OFFSET_PLL_CONFIG_STATUS  16#F8
#define OFFSET_PLL_CONFIG2        16#F9
#define OFFSET_FPGA_VERSION       16#FB


// if an interface frame has to be written to all possible targets, this will be it's destination path
#define INTERFACE_FRAME_BROADCAST 16#FFFF0002


//define order / priority of update tasks
//lowest priority = 3, highest priority = 1
#define PRIORITY_SAFE_IN             1
#define PRIORITY_SAFE_CPU            2
#define PRIORITY_SAFE_OUT            3

//modultype of safety modules (none-safety modules have type 0)
#define TYPE_SAFETY_MODULE           1

//errornumber of communication timeout
#define COMM_TIMEOUT_ERROR         199

//bit to set for single execution over mover
#define VM_SINGLE_ID			16#8000_0000

//max. unsafe write packages in one message
#define MAX_UNSAFE_WRITE_PACKAGES    6

//max. unsafe BDINT write values per write values access (to ensure constant firmware load)
#define MAX_UNSAFE_BDINTS_PER_WRITE  3

//max. length of SDO
#define SDO_MAX_LENGTH              72

//max. length of PDOs
#define SPDO_MAX_LENGTH            128

#define SPDO_MAX_LENGTH_READ_FROM_CPU     SPDO_MAX_LENGTH
#define SPDO_MAX_LENGTH_WRITE_TO_CPU      SPDO_MAX_LENGTH
#define SPDO_MAX_LENGTH_READ_FROM_INPUT   SPDO_MAX_LENGTH  // we need at least 1 byte reserve, which can be removed if we communicate over mover
#define SPDO_MAX_LENGTH_WRITE_TO_INPUT    SPDO_MAX_LENGTH  // makes no sense so far
#define SPDO_MAX_LENGTH_READ_FROM_OUTPUT  SPDO_MAX_LENGTH  // we need at least 1 byte reserve, which can be removed if we communicate over mover
#define SPDO_MAX_LENGTH_WRITE_TO_OUTPUT   SPDO_MAX_LENGTH

// length of TDO
#define STDO_LENGTH                 24

// length of unsafe output access
#define UNSAFE_OUT_LENGTH            2

// blocksize for getting log data
#define LOG_DATA_BLOCK_SIZE         16

// size of config to send to the manager (the same amount well be added every time the memory wouldn't last out)
#define CONFIG_MEMORY_BLOCK_SIZE   512


//SDO specific data

// Type definitions: Bit0 = communication for configuration
//                   Bit1 = communication over topology path
//                   Bit2 = Standard frame
//                   Bit3 = PDO
//                   Bit4 = TDO
//                   Bit5 = reserved
//                   Bit6 = reserved
//                   Bit7 = is the frame a Response
//#define SDO_TYPE_CFG             2#001 = 16#01
//#define SDO_TYPE_CFG_TP          2#011 = 16#03
//#define SDO_TYPE_MOD             2#000 = 16#00
//#define SDO_TYPE_MOD_TP          2#010 = 16#02
//#define SDO_TYPE_STD             2#101 = 16#05

(* Frame Typen sind im Frame folgendermassen codiert:
 0     0     0     0     1     0     0     0      SPDO Frame - 1ms Zeiteinheit
 0     0     1     0     0     0     0     0      SPDO Interace-Frame - 1ms Zeiteinheit
 x     0     0     1     0     0     0     0      STDO Frame - 1ms Zeiteinheit
 0     1     0     0     1     0     0     0      SPDO Frame - 1/16ms Zeiteinheit
 0     1     1     0     0     0     0     0      SPDO Interace-Frame - 1/16ms Zeiteinheit
 x     1     0     1     0     0     0     0      STDO Frame - 1/16ms Zeiteinheit
 x     0     0     0     0     0     0     1      SSDO-Cfg Frame
 0     0     0     0     0     0     1     1      SSDO-Cfg Frame - Topology-Pfad als Ziel
 x     0     0     0     0     0     0     0      SSDO-Mod Frame
 0     0     0     0     0     0     1     0      SSDO-Mod Frame - Topology-Pfad als Ziel
 x     0     0     0     0     1     0     1      Standard-Frame
*)
// SSDO-Cfg-Type (mit Safety-Nummer als Zieladresse)
#define FRM_TYPECODE_SSDO_CFG         0x01  // Resp = 0x81
// SSDO-Cfg-Type (mit Topology-Pfad als Zieladresse)
#define FRM_TYPECODE_SSDO_CFG_TP      0x03
// SSDO-Mod-Type (mit Safety-Nummer als Zieladresse)
#define FRM_TYPECODE_SSDO_MOD         0x00  // Resp = 0x80
// SSDO-Mod-Type (mit Topology-Pfad als Zieladresse)
#define FRM_TYPECODE_SSDO_MOD_TP      0x02
// SSDO Frame mit Geräteadressen statt Sicherheitsnummern 
#define FRM_TYPECODE_DEVADDR          0x04
// Standard Frame
#define FRM_TYPECODE_STD              0x05  // Resp = 0x85
// STDO Frame - 1ms Zeiteinheit
#define FRM_TYPECODE_STDO_LORES       0x10  // Resp = 0x90
// STDO Frame - 1/16ms Zeiteinheit
#define FRM_TYPECODE_STDO_HIRES       0x50  // Resp = 0xD0
// ID für SPDO Frame - 1ms Zeiteinheit
#define FRM_ID_SPDO_LORES             0x08
// ID für SPDO Frame - 1/16ms Zeiteinheit
#define FRM_ID_SPDO_HIRES             0x48
// ID für SPDO Interfaace-Frame - 1ms Zeiteinheit
#define FRM_ID_SPDO_INTERFACE_LORES   0x20
// ID für SPDO Interfaace-Frame (- 1/16ms Zeiteinheit
#define FRM_ID_SPDO_INTERFACE_HIRES   0x60
// Wert zum Ausmaskieren des Typs
#define SSDO_MASK_TYPE                0x7F
// Wert zum Ausmaskieren des Response Bits
#define SSDO_MASK_RESPONSE            0x80

//! Bitmaske für Geräteadressen, die nur fürs Routen des Requests verwendet werden
// und bei denen der Empfänge die Zieladresse im Request nicht mit seiner eigenen
// Adresse vergleichen muss. Beispiele dafür sind 'Adresse des Adressvergabeservices'
#define DEVADDR_MASK_NO_ADDR_COMPARE  0xF0000000
//! Geräteadresse für das Ziel Kopfstation
#define DEVADDR_ADDR_HEAD             0x10000000
//! Geräteadresse für das Ziel Masterkufe
#define DEVADDR_ADDR_IRMASTER         0x20000000 


//returncodes of SDO response
#define SDO_RETCODE_OK              0   // everything is fine
#define SDO_MICROCTRL_DIFFER      219   // The content of a SSDO response is different between the two controllers. Happens most likely when we try to read out the configuration while the safety designer is writing it

//end-command of interpreter list
#define SDO_CONFIG_END_CMD          2

//commands

//command to read data from module
#define SDO_COMMAND_READ            0
//command to read data from module
#define SDO_COMMAND_WRITE           1
//command to get state of a module
#define SDO_COMMAND_GET_STATE       4
//command to get the diag info of a module
#define SDO_COMMAND_GET_DIAG_INFO   6
//command to get the log header of a module
#define SDO_COMMAND_GET_LOG_HDR     8
//command to quit all errors in a safety module
#define SDO_COMMAND_QUIT_ERROR     14
//command to get safety number of module
#define SDO_COMMAND_GET_SAFENBR    15
//command to get firmware version of module
#define SDO_COMMAND_GET_FW_VERSION 17
//command to read values from different addresses (to update multiple unsafe variables from different memory areas) => write the addresses in the read_values command
#define SDO_COMMAND_READ_VALUES    28
//command to set bus ready for this module
#define SDO_COMMAND_SET_BUS_READY  29
//command to write addresses and values (to update multiple unsafe variables)
#define SDO_COMMAND_WRITE_VALUES   30


// possible config states of cpu
#define CFG_STATE_UNKNOWN                                   0   // FW answers this, e.g. if FW-download is running
#define CFG_STATE_INVALID                                   1
#define CFG_STATE_NOT_CONFIGURED                            2
#define CFG_STATE_CONFIGURED_NOT_DEPLOYED_NOT_VERIFIED      4
#define CFG_STATE_CONFIGURED_AND_VERIFIED                   8
#define CFG_STATE_CONFIGURED_DEPLOYED_NOT_VERIFIED         16
#define CFG_STATE_CONFIGURED_NOT_DEPLOYED_NOT_VERIFIED_DEV 36
#define CFG_STATE_CONFIGURED_DEPLOYED_NOT_VERIFIED_DEV     48



// block type constants

// Bitmasken für Flags in den Blocktyp-Konstanten
#define SLAVE_FLAG      0x80000000
#define OPTIONAL_FLAG   0x40000000

// Blocktyp eines Safe CPU Headers = Blocktyp der Gesamtkonfiguration (enthält Modulkonfigurationen)
#define BLKTYPE_CFG_CONTAINER  		               0
// Blocktyp einer Modulkonfiguration
#define BLKTYPE_CFG_MODULE                        1
// Blocktyp Bootsektor
#define BLKTYPE_BOOTSECTOR                        2
// Blocktyp Betriebssystem Image
#define BLKTYPE_OSIMAGE                           3
// Blocktyp Konfigurationszustand
#define BLKTYPE_INFO                              4
// Blocktyp Log-Sektor
#define BLKTYPE_LOG_SECTOR                        5
// Blocktyp SD-Karten Zusatzinfo
#define BLKTYPE_SD_INFO                           6
// Blocktyp einer externen CPU, an die nichts verteilt wird (enthält nur die
// IO-Liste aber keine FUBs und keinen Interpretercode)
#define BLKTYPE_CFG_CPU                           7 
// Blocktyp einer Modulkonfiguration - optionales Modul
#define BLKTYPE_CFG_MODULE_OPTIONAL               8
// Blocktyp einer externen CPU, an die nichts verteilt wird (enthält nur die
// IO-Liste aber keine FUBs und keinen Interpretercode) - optionales Mdol
#define BLKTYPE_CFG_CPU_OPTIONAL                  9
// Blocktyp einer Modulkonfiguration (inkl. Interface-CRC im Listenheader)
#define BLKTYPE_CFG_MODULE_V2                    10
// Blocktyp eines externen Interfaces
#define BLKTYPE_CFG_INTERFACE                    11
// Blocktyp eines externen optionalen Interfaces
#define BLKTYPE_CFG_INTERFACE_OPTIONAL           12
// Blocktyp der Gesamtkonfiguration einer Slave-CPU (enthält Modulkonfigurationen)
#define BLKTYPE_CFG_CONTAINER_SLAVE              13
// Blocktyp der Gesamtkonfiguration einer optionalen Slave-CPU (enthält Modulkonfigurationen) 
#define BLKTYPE_CFG_CONTAINER_SLAVE_OPTIONAL     14
// Blocktyp einer Master-CPU
#define BLKTYPE_CFG_MASTER_CPU                   15
// Blocktyp der über die komprimierte Gesamtkonfiguration einer Slave-CPU gegeben wird
#define BLKTYPE_CFG_SLAVE_COMPR                  16
// Blocktyp der über die komprimierte Gesamtkonfiguration einer Slave-CPU gegeben wird - optional
#define BLKTYPE_CFG_SLAVE_COMPR_OPTIONAL         17
// Blocktyp der als Flag verwendet wird um anzuzeigen, dass der alte Modus (1ms Zeiteinheit) verwendet werden muss
#define BLKTYPE_OLD_MODE_FLAG                    18

// Blocktyp der Gesamtkonfiguration (enthält Modulkonfigurationen)
#define BLKTYPE_CFG_CONTAINER_V3                 19
// Blocktyp der Gesamtkonfiguration einer Slave-CPU (enthält Modulkonfigurationen)
#define BLKTYPE_CFG_CONTAINER_V3_SLAVE          (19 OR SLAVE_FLAG)
// Blocktyp der Gesamtkonfiguration einer optionalen Slave-CPU (enthält Modulkonfigurationen)
#define BLKTYPE_CFG_CONTAINER_V3_SLAVE_OPTIONAL (19 OR SLAVE_FLAG OR OPTIONAL_FLAG)

// * =========================
// * Die Nummern 20-39 sind für den Safety-Designer reserviert
// * =========================
// xml description: configuration for uploading the project to the safetydesigner (network placement information, names of bits,...)
#define BLKTYPE_CFG_XML    	                    20
// revision information (safety designer project name and revision number string)
#define BLKTYPE_CFG_REV    	                    21

// Blocktyp einer Modulkonfiguration V3
#define BLKTYPE_CFG_MODULE_V3                    40
// Blocktyp einer Modulkonfiguration V3 - optionales Modul
#define BLKTYPE_CFG_MODULE_V3_OPTIONAL          (40 OR OPTIONAL_FLAG)




//virtual addresses of safety controller 

//base address of log memory of µC1
#define SDO_ADDRESS_LOG_UC1         16#1000_0000

//base address of log memory of µC2
#define SDO_ADDRESS_LOG_UC2         16#1800_0000

//base address config data
#define SDO_ADDRESS_CONFIG_DATA     16#2000_0000

//base address application data        
#define SDO_ADDRESS_APP_DATA        16#3000_0000

//base address unsafe BDINT variables
#define SDO_ADDRESS_UNSAFE_BDINT    16#3400_0000

//base address error memory
#define SDO_ADDRESS_ERROR_MEM       16#8000_0000


#define SDO_LENGTH_ERROR_MESSAGE    61

//offsets of config data

//offset crc of whole config data
#define SDO_OFFSET_CONFIG_CRC_ALL   16#0
//offset length of whole config data
#define SDO_OFFSET_CONFIG_LEN_ALL   16#4
//offset header blocktype
#define SDO_OFFSET_CONFIG_BLOCKTYPE 16#8
//offset length of additional header data
#define SDO_OFFSET_CONFIG_LEN_HEAD  16#C
//offset of time info depends on blocktype (it's 16#C on an old block type and 16#10 on a new block type)


#endif // SAFETYCDIAS_BASE_H
