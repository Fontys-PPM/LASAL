(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_pci.h                                                                         *)
(*                                                                                      *)
(* enthält die Definitionen für den PCI Bus und die IPC/CIPC PCI Konfiguration          *)
(*                                                                                      *)
(* HH                                                                                   *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
#ifndef __LSL_ST_SPCIINFO
#pragma once
#define __LSL_ST_SPCIINFO


//
// Interface
//
TYPE
  LSL_SPCIINFO : STRUCT

  //
  // Version
  //
  udVersion : UDINT;

  //
  // PCI Info
  //

  // Hole Bus
  PCIGetBus : pVoid;

  // Hole DeviceFunc
  PCIGetDeviceFunc : pVoid;

  // Hole  Phys Addr.
  PCIGetPhysAddr : pVoid;

  // Hole Virt Addr,
  PCIGetVirtAddr : pVoid;

  // Hole IRQ
  PCIGetIRQ : pVoid;

  //
  // SigmaTek Info Block
  //

  // Anzahl der Geräte
  PCIGetDeviceCount : pVoid;

  // Hole Device n
  PCIGetDeviceByIndex : pVoid;

  // suche Gerät nach namen
  PCIFindDeviceByName : pVoid;

  // suche Gerät
  PCIFindDevice : pVoid;

  // Hole Adresse
  PCIGetAddress : pVoid;

  // Hole Länge
  PCIGetAddressLen : pVoid;
  
  // Xilinx Version
  PCIGetXilinxVersion : pVoid;
  
  // Anzahl der Geräte eines Subdevices
  PCIGetSubDeviceCount : pVoid;
  
  // Hole Subdevice n
  PCIGetSubDeviceByIndex : pVoid;
  
  // suche Subdevice nach Namen
  PCIFindSubDeviceByName : pVoid;

  // suche Subdevice
  PCIFindSubDevice : pVoid;

  // Hole DeviceID
  PCIGetDeviceID : pVoid;

  // ab Version 0x0001001
  
  // Xilinx Product ID
  PCIGetXilinxProductId : pVoid;

  END_STRUCT;
END_TYPE



//
// Konfigurationsdaten - 16 Byte je Device
//

// 1 byte align
#pragma pack( push, 1 )

TYPE
  PCICONFDATA : STRUCT

  // device type
  DeviceType : UINT;

  // device number
  DeviceNumber : USINT;

  // base address
  BaseAddress : UDINT;

  // address range
  AddressRange : USINT;

  // version
  Version : USINT;

  // base address subconfiguration
  BaseAddressSub : UDINT;

  // reserved
  Reserved0 : USINT;
  Reserved1 : USINT;
  Reserved2 : USINT;

  END_STRUCT;
END_TYPE

// default align
#pragma pack( pop )



(*

//
// bekannte Geräte lt. Taubner 
//
PCIDEVICES aPciDevices[] = 
   {
      { 0x0000, 0, "DesignTop" },

      { 0x0100, 0, "16450" },
      { 0x0101, 3, "COM3" },
      { 0x0101, 4, "COM4" },
      { 0x0101, 5, "COM5" },

      { 0x0108, 0, _SN_can_1_STRING },
      { 0x0108, 1, _SN_can_2_STRING },
      { 0x010A, 0, "CANFPGA" },

      { 0x0110, 0, "PS2" },
      { 0x0118, 0, "SSI" },
      { 0x0120, 0, "CFG_REGS" },
      { 0x0120, 1, "CFG_REGS1" },
      { 0x0120, 2, "CFG_REGS2" },
      { 0x0121, 0, "IICMUX" },
      { 0x0128, 0, "JTAGMaster" },
      { 0x0138, 0, "SPIMaster" },

      { 0x0400, 0, "PCIMaster" },
      { 0x0408, 0, "PARPORT0" },
      { 0x0425, 0, "ETHERCATSLAVE" },

      { 0x0500, 0, "CDiasBus" },
      { 0x0501, 0, "CDiasOE" },

      { 0x0700, 0, "XREGS" },
      { 0x0708, 0, "RAM" },

      { 0x0730, 0, "SYSSTATUS" },

      { 0x0800, 0, "SRAM" },
      { 0x0808, 0, "XFLASH" },

      { 0x0900, 0, "SHUTTLE" },
      { 0x0B08, 0, "POTENTIOMETER" },

      { 0x0C00, 0, "CANPS2" },
      { 0x0C40, 0, "KEYPAD" },

      { 0x0D00, 0, "DIASIM" },
      { 0x0D08, 0, "CIPCEWP" },

      { 0x0E00, 0, "INFOBLOCK" },
      { 0x0E08, 0, "PLL" },
      { 0x0E10, 0, "SIGMAIRQ" },
      { 0x0E18, 1, "XTIMER" },
      { 0x0E18, 0, "CDIASWATCHDOG" },
      { 0x0E20, 1, "WISHBONE_INTERCONNECT" },
      { 0x0E27, 0, "PWM_LED" },
      { 0x0E28, 0, "PWM" },

      { 0x0F00, 0, "INITCIPC" },
      { 0x0F08, 0, "PCIPOST" },

      { 0x1220, 0, "DIGIO" }, 
      { 0x122a, 0, "RELED" },
      { 0x1400, 0, "EMAC0" }, 

      // Abschluss
      { 0, 0, NULL }
   };

*)



// Anzahl der Geräte
FUNCTION __CDECL GLOBAL P_PCIGetDeviceCount
VAR_INPUT
END_VAR
VAR_OUTPUT
  retval  : DINT;
END_VAR;
#define SPCIINFO_GETDEVICECOUNT()   pSPCIInfo^.PCIGetDeviceCount $ P_PCIGetDeviceCount()


// Hole Device n
FUNCTION __CDECL GLOBAL P_PCIGetDeviceByIndex
VAR_INPUT
  lI : DINT;
END_VAR
VAR_OUTPUT
    retval      : ^PCICONFDATA;
END_VAR;
#define SPCIINFO_GETDEVICEBYINDEX(p1)   pSPCIInfo^.PCIGetDeviceByIndex $ P_PCIGetDeviceByIndex(p1)



// suche Gerät nach namen
FUNCTION __CDECL GLOBAL P_PCIFindDeviceByName
VAR_INPUT
  Name : ^VOID;
  Nummer : USINT;
END_VAR
VAR_OUTPUT
    retval      : ^PCICONFDATA;
END_VAR;
#define SPCIINFO_FINDDEVICEBYNAME(p1,p2)   pSPCIInfo^.PCIFindDeviceByName $ P_PCIFindDeviceByName(p1,p2)


// suche Gerät
FUNCTION __CDECL GLOBAL P_PCIFindDevice
VAR_INPUT
  Device : UINT;
  Nummer : USINT;
END_VAR
VAR_OUTPUT
    retval      : ^PCICONFDATA;
END_VAR;
#define SPCIINFO_FINDDEVICE(p1,p2)   pSPCIInfo^.PCIFindDevice $ P_PCIFindDevice(p1,p2)


// Hole Adresse
FUNCTION __CDECL GLOBAL P_PCIGetAddress
VAR_INPUT
  Dev : ^PCICONFDATA;
END_VAR
VAR_OUTPUT
    retval      : ^VOID;
END_VAR;
#define SPCIINFO_GETADDRESS(p1)   pSPCIInfo^.PCIGetAddress $ P_PCIGetAddress(p1)


// Hole Länge
FUNCTION __CDECL GLOBAL P_PCIGetAddressLen
VAR_INPUT
  Dev : ^PCICONFDATA;
END_VAR
VAR_OUTPUT
    retval      : UDINT;
END_VAR;
#define SPCIINFO_GETADDRESSLEN(p1)   pSPCIInfo^.PCIGetAddressLen $ P_PCIGetAddressLen(p1)


// Xilinx Version
FUNCTION __CDECL GLOBAL P_PCIGetXilinxVersion
VAR_OUTPUT
    retval      : USINT;
END_VAR;
#define SPCIINFO_GETXILINXVERSION()   pSPCIInfo^.PCIGetXilinxVersion $ P_PCIGetXilinxVersion()


// Anzahl der Geräte eines Subdevices
FUNCTION __CDECL GLOBAL P_PCIGetSubDeviceCount
VAR_INPUT
  Dev : ^PCICONFDATA;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;
#define SPCIINFO_GETSUBDEVICECOUNT(p1)   pSPCIInfo^.PCIGetSubDeviceCount $ P_PCIGetSubDeviceCount(p1)


// hole Subdevice n
FUNCTION __CDECL GLOBAL P_PCIGetSubDeviceByIndex
VAR_INPUT
  Dev   : ^PCICONFDATA;
  Index : DINT;
END_VAR
VAR_OUTPUT
    retval      : ^PCICONFDATA;
END_VAR;
#define SPCIINFO_GETSUBDEVICEBYINDEX(p1,p2)   pSPCIInfo^.PCIGetSubDeviceByIndex $ P_PCIGetSubDeviceByIndex(p1,p2)


// suche Subdevice nach Namen
FUNCTION __CDECL GLOBAL P_PCIFindSubDeviceByName
VAR_INPUT
  Dev    : ^PCICONFDATA;
  Name   : ^VOID;
  Number : USINT;
END_VAR
VAR_OUTPUT
    retval      : ^PCICONFDATA;
END_VAR;
#define SPCIINFO_FINDSUBDEVICEBYNAME(p1,p2,p3)   pSPCIInfo^.PCIFindSubDeviceByName $ P_PCIFindSubDeviceByName(p1,p2,p3)


// suche Subdevice
FUNCTION __CDECL GLOBAL P_PCIFindSubDevice
VAR_INPUT
  Dev    : ^PCICONFDATA;
  Device : UINT;
  Number : USINT;
END_VAR
VAR_OUTPUT
    retval      : ^PCICONFDATA;
END_VAR;
#define SPCIINFO_FINDSUBDEVICE(p1,p2,p3)   pSPCIInfo^.PCIFindSubDevice $ P_PCIFindSubDevice(p1,p2,p3)


// hole Device-ID
FUNCTION __CDECL GLOBAL P_PCIGetDeviceID
VAR_OUTPUT
    retval      : DINT;
END_VAR;
#define SPCIINFO_GETDEVICEID()   pSPCIInfo^.PCIGetDeviceID $ P_PCIGetDeviceID()


// Xilinx Product ID
FUNCTION __CDECL GLOBAL P_PCIGetXilinxProductId
VAR_OUTPUT
    retval      : USINT;
END_VAR;
#define SPCIINFO_GETXILINXPRODUCTID()   pSPCIInfo^.PCIGetXilinxProductId $ P_PCIGetXilinxProductId()

#endif
