
//*****************************************************************************
//** NEWINST COMMANDS (Range reserved for SDIAS Clients: 0x8330 - 0x837F)    **
//*****************************************************************************


#define SDIAS_CLT_CMD_LOG_MESSAGE           0x8330
#define SDIAS_CLT_CMD_LOG_VALUE             0x8331
#define SDIAS_CLT_CMD_ADD_DYN_READ          0x8332
#define SDIAS_CLT_CMD_ADD_DYN_WRITE         0x8333
#define SDIAS_CLT_CMD_CHG_DYN_ACCESS        0x8334
#define SDIAS_CLT_CMD_CREATE_MUTEX          0x8335
#define SDIAS_CLT_CMD_IS_VARAN_AVAILABLE    0x8336
#define SDIAS_CLT_CMD_ADD_RD_ACCESS         0x8337
#define SDIAS_CLT_CMD_ADD_WR_ACCESS         0x8338
#define SDIAS_CLT_SDO_CMD_MEM_READ          0x8339
#define SDIAS_CLT_SDO_CMD_MEM_WRITE         0x833A

//-------------------------------------------------------
// commands for library classes to get data
//-------------------------------------------------------

//+++++++++++++++++++++++++++++++++++++
#define SDIAS_CLT_GET_ANALOG_DATA_BUFFER    0x8370

      //aPara[0] = version of command
      //Parameter of Version 1:
      //aPara[1] = Channel Number, 1 = first channel (mandatory)
      //aPara[2] = pointer to buffer where the data should be copied (can be NIL)
      //aPara[3] = size of buffer (value is ignored if aPara[2]=NIL)
      
      //retcode = error => command not supported
      //retcode = ready => result is filled with data
      // result of version 1
      //result.aData[0x0]       = version
      //result.aData[0x1]       = size of one value in byte
      //result.aData[0x2]$UDINT = max avaliable values per cycle 
      //result.aData[0x6]$UDINT = number of values copied to buffer
      //result.aData[0xA]       = datacount avaliable => 0= no counter, 1 = counter avaliable
      //result.aData[0xB]$UDINT = new data counter ( always 0 if not avaliable)
//+++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++
#define SDIAS_CLT_GET_INFO_PLACE       0x8371

      //aPara -> not used
      
      //retcode = ready => result is filled with data
      //result.uiLng = 2
      //result.aData[0x0]$UINT  = value of client place (valid: 0 - 63 or DEACTIVATED_LSL)
//+++++++++++++++++++++++++++++++++++++
