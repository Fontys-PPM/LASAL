
#ifndef _SigCLibH
 #define _SigCLibH

  #ifndef NULL
   #define NULL 0
  #endif 
  
  #include "CStrLib.h"
  #include "CStrLib16.h"
  #include "CTimeLib.h"
  #include "CMathLib.h"
  #include "CSortLib.h"
  #include "CFileLib.h"
  #include "CMemLib.h"
  #include "CNetworkLib.h"
  #include "CCrcLib.h"
  #include "CPlcOnline.h"
  #include "CSysLib.h"
  #include "CAtomic.h"
  #include "CFiFo.h"
  #include "CRingBuffer.h"
  #include "CPipe.h"
  #include "CHeap.h"
 
#endif


// version 01.23, 13.10.2017 ----------------------------------------------------------------------
// New functions added:
//   * sigclib_atomic_getU32(), sigclib_atomic_setU32(), sigclib_atomic_getS32(), sigclib_atomic_setS32()
// sa38620: Implementation of following functions changed
//   * sigclib64_sin(), sigclib64_cos(), sigclib64_tan(), sigclib64_asin(), sigclib64_acos(), sigclib64_atan()
// Correction:
//   Method RealToString() will work with values greater than 4294967295 and lower than -4294967295
//   Method UnixTimeStampConvert() and function sigclib_gmtime() will work with 1st second of each 1st day in month.


// version 01.22, 20.07.2017 ----------------------------------------------------------------------
// * new functions
//    sigclib_atomic_incU32(), sigclib_atomic_decU32(), sigclib_atomic_addU32(), sigclib_atomic_subU32(), sigclib_atomic_swpU32(), sigclib_atomic_cmpxchgU32()
//    sigclib_atomic_incS32(), sigclib_atomic_decS32(), sigclib_atomic_addS32(), sigclib_atomic_subS32(), sigclib_atomic_swpS32(), sigclib_atomic_cmpxchgS32()
//    sigclib_absday(), sigclib_day_of_week(), sigclib_lasal_to_date(), sigclib_lasal_to_time(),
//    sigclib_time_to_lasal(), sigclib_date_to_lasal(), sigclib_get_days_of_month(), sigclib_make_date()
// * functionality of cPipe added


// version 01.21, 05.07.2017 ----------------------------------------------------------------------
// * new functions
//     sigclib_get_thisptr(), sigclib_htoa(), sigclib_mutex_name()
// * functionality of cFiFo added
// * functionality of cRingBuffer added


// version 01.20, 11.04.2017 ----------------------------------------------------------------------
// * new functions 
//     sigclib_memoryV1(), sigclib_mallocV1(), sigclib_callocV1(), sigclib_reallocV1(), sigclib_freeV1()


// version 01.19, 01.02.2017 ----------------------------------------------------------------------
// * new functions
//     sigclib_str16_to_utf8(), sigclib_utf8_to_str16(), sigclib_serviceprovider(), sigclib_is_salamander()
//     sigclib_u32ipaddress(), sigclib_crc64()
// * new methods
//     ToStr16, ToStr08, StrLen16, StrCpy16, StrCmp16, StrCat16, StrChr16, StrUpr16, StrLwr16, StrStr16, Str16ToUtf8, Utf8ToStr16
// * #ifdef _DefineCompileH bei headerfile DefineCompiler.h eingebaut
// * optimierung für ARM (GNU O3) bei folgenden funktionen eingeschaltet
//   sigclib_memset(), sigclib_memcpy(), sigclib_memcmp(), sigclib_strlen(), sigclib_strcpy(), sigclib_strcmp(), sigclib_memmove(), 
//   sigclib_strupr(), sigclib_strlwr(), sigclib_strchr(), sigclib_hsort()
