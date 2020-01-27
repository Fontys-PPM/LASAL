#ifndef HW_CONTROL_LOGGING_H
#pragma once
#define HW_CONTROL_LOGGING_H


//*****************************************************************************
//** SPAM PROTECTION SETTINGS                                                **
//*****************************************************************************

// if this is active, the logging methods only trace the strings
//#define HWC_DISABLE_FILE_LOGGING

// if this is active, the logging methods are monitored for spam (logging too frequently)
#define HWC_ENABLE_SPAM_PROTECTION

// log spam detection to prevent flooding of file or damaging of the media (value 0 disables this spam protection; default value 10)
// as soon as X logs arrive within 1 second (can be adjusted via HWC_SPAM_PROTECTION_TIME), writing into the logfile is disabled
// if there is a pause of 1 second (can be adjusted via HWC_SPAM_PROTECTION_TIME) the spam counter gets reset (it's possible to have X-1 logs per second to not disable the logging)
#define HWC_SPAM_DETECTION_LIMIT        10

// time span in ms to watch for flooding (default: 100)
#define HWC_SPAM_DETECTION_TIME        100

// time span in ms to reset the internal counter (disable log block) if there have not been any logs (default: 1000)
#define HWC_SPAM_BLOCK_RELEASE_TIME   1000



//*****************************************************************************
//** GLOBAL FUNCTIONS                                                        **
//*****************************************************************************

FUNCTION GLOBAL _HwcLogInit;
FUNCTION GLOBAL _HwcLogError
	VAR_INPUT
    pThis   : pVirtualBase;
		e_msg 	: ^CHAR;
	END_VAR;

FUNCTION GLOBAL _HwcLogValue
	VAR_INPUT
    pThis   : pVirtualBase;
		pString : ^CHAR;
		Value 	: UDINT;
		Value2 	: UDINT;(* := 16#FFFFFFFF *)
		Value3 	: UDINT;(* := 16#FFFFFFFF *)
	END_VAR;

FUNCTION GLOBAL _HwcLimitObjName
	VAR_INPUT
		pObjName : ^CHAR;
	END_VAR;


// LogInit has to be called before logging if there is no HwControl object or logging takes place in the constructor (if there is a HwControl object it calls the LogInit in it's constructor => SDIAS and VARAN need HwControl and can therefore skip this call!)
#define HWC_LogInit()                             _HwcLogInit()

// logs the object name of the passed this pointer or <unknown> if NIL and the passed message
#define HWC_LogError(pThis, pMsg)                 _HwcLogError(pThis, pMsg)

// logvalue additionally allows to use numbers in the message as {0} {1} {2} which are then being replaced by the values passed via v1 v2 v3
#define HWC_LogValue1(pThis, pMsg, v1)            _HwcLogValue(pThis, pMsg, v1, 16#FFFFFFFF, 16#FFFFFFFF)
#define HWC_LogValue2(pThis, pMsg, v1, v2)        _HwcLogValue(pThis, pMsg, v1, v2, 16#FFFFFFFF)
#define HWC_LogValue3(pThis, pMsg, v1, v2, v3)    _HwcLogValue(pThis, pMsg, v1, v2, v3)
    
// limits the string length according to the constants HWC_MAX_OBJECT_NAME_SIZE (maximal length of string) and HWC_OBJECT_NAME_END_CHARS (how many characters to take from the end)
#define HWC_LimitObjName(pMsg)                    _HwcLimitObjName(pMsg)


//*****************************************************************************
//** TYPES                                                                   **
//*****************************************************************************

	TYPE
    t_HWCSpamFlags : BDINT
	    [
	    1 FilterActive,
      2 Initialized,
	    ];

#ifdef HWC_ENABLE_SPAM_PROTECTION
    t_HWCSpamFilter : STRUCT
      aLogTimes         : ARRAY [0..HWC_SPAM_DETECTION_LIMIT-1] OF UDINT; // timestamps of last logs
      ud_NextTimeIndex  : UDINT;  // index of next timestamp to overwrite
      SkippedMessages   : UDINT;  // number of messages skipped due to spamming (is printed as first message after the spam block)
      bd_SpamFlags      : t_HWCSpamFlags;
      ud_LastLog        : UDINT;  // time of last log try
    END_STRUCT;
#endif
  END_TYPE


#endif // HW_CONTROL_LOGGING_H