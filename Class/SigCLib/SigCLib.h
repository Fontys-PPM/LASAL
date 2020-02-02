
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
  #include "CTcpIp.h"
  #include "CAtomic.h"
  #include "CFiFo.h"
  #include "CRingBuffer.h"
  #include "CPipe.h"
  #include "CHeap.h"
  #include "CDeEncode.h"
 
#endif

// version 0.29, 18.10.2019 ----------------------------------------------------------------------
// new functions added:
//   sigclib_strcrc(), sigclib_strcrc16()
//   sigclib_sort_txtbuffer(), sigclib_sort_txtptr(), sigclib_sortfkt_ASCII(), sigclib_sortfkt_ABC()
//   sigclib_leap_year()
//   sigclib_encode_bin(), sigclib_decode_bin(), sigclib_encode_txt(), sigclib_decode_txt()
//   sigclib_stricmp(), sigclib_strpbrk(), sigclib_strrchr(), sigclib_sprintfST()
//   sigclib_nameof_baseclass()
//   sigclib_fputs(), sigclib_cfputs()
//   sigclib_mkdir() and sigclib_rmdir() are accessible in ST
//   sigclib_strfdatetime(), sigclib_calendar_week()


// version 0.28, 14.08.2019 ----------------------------------------------------------------------
// new functions added:
//   sigclib_cfmemory(), sigclib_cfok(), sigclib_cferror_set(), sigclib_cferror_get(), sigclib_cfversion_set(), sigclib_cfversion_get(), sigclib_cfcookie_set(), sigclib_cfcookie_get()
//   sigclib_ascii_to_utf8(), sigclib_utf8_to_ascii()
//   sigclib_base64_encode(), sigclib_base64_decode(), sigclib_base64_encode_size()
//   sigclib_name_enlarge(), sigclib_name_unique(), sigclib_utoa(), sigclib_htoa_ex()
// new files added:
//   CDeEncode.h, CDeEncode.cpp


// version 0.27, 05.07.2019 ----------------------------------------------------------------------
// new functions added:
//   sigclib_tcp_...()
//   sigclib_drivelist()
//   sigclib_strcspn(), sigclib_atoll()
//   sigclib_thread_create2(), sigclib_thread_get_current_free_stacksize()
// new macro added:
//   sigclib_fprintf()
// new files added:
//   CLimits.h, CTcpIp.h, SigCLib.ico


// version 0.26, 24.04.2019 ----------------------------------------------------------------------
// new functions added:
//   sigclib_buffer_create()
//   sigclib_buffer_destroy()
// st-interface for sigclib_findfirst(), sigclib_findnext(), sigclib_findclose() implemented


// version 0.25, 28.02.2019 ----------------------------------------------------------------------
// correction: SA 43337 SigCLib.RealToStr() (sigclib_ftoa_comma())
// new typ "st_real" is available for c-language to put real/float values into parameter of function
// new macro added:
//   sigclib_min
//   sigclib_printf
// new functions added:
//   sigclib_strcpytill(), 
//   sigclib_lookup_class(), sigclib_lookup_object(), 
//   sigclib_isderived_from(),
//   sigclib_revisionof_class(), sigclib_revisionof_object(), sigclib_revisionof_loader(), sigclib_revisionof_opsys(), 
//   sigclib_nameof_class(), sigclib_nameof_object(),
//   sigclib_reset(), sigclib_restart(),
//   sigclib_virtual_methodpointer(),
//   sigclib_thread_create(), sigclib_thread_destroy(), sigclib_thread_delay(), sigclib_waste(),
// Option HEAPBUBBLE_INUSE added


// version 0.24, 06.07.2018 ----------------------------------------------------------------------
// New define added:   sigclib_arraysize()
// New function added:   sigclib_fileread(), sigclib_cilget()
// New Functionality "Heap" added


// version 0.23, 13.10.2017 ----------------------------------------------------------------------
// New functions added:
//   * sigclib_atomic_getU32(), sigclib_atomic_setU32(), sigclib_atomic_getS32(), sigclib_atomic_setS32()
// sa38620: Implementation of following functions changed
//   * sigclib64_sin(), sigclib64_cos(), sigclib64_tan(), sigclib64_asin(), sigclib64_acos(), sigclib64_atan()
// Correction:
//   Method RealToString() will work with values greater than 4294967295 and lower than -4294967295
//   Method UnixTimeStampConvert() and function sigclib_gmtime() will work with 1st second of each 1st day in month.


// version 0.22, 20.07.2017 ----------------------------------------------------------------------
// * new functions
//    sigclib_atomic_incU32(), sigclib_atomic_decU32(), sigclib_atomic_addU32(), sigclib_atomic_subU32(), sigclib_atomic_swpU32(), sigclib_atomic_cmpxchgU32()
//    sigclib_atomic_incS32(), sigclib_atomic_decS32(), sigclib_atomic_addS32(), sigclib_atomic_subS32(), sigclib_atomic_swpS32(), sigclib_atomic_cmpxchgS32()
//    sigclib_absday(), sigclib_day_of_week(), sigclib_lasal_to_date(), sigclib_lasal_to_time(),
//    sigclib_time_to_lasal(), sigclib_date_to_lasal(), sigclib_get_days_of_month(), sigclib_make_date()
// * functionality of cPipe added


// version 0.21, 05.07.2017 ----------------------------------------------------------------------
// * new functions
//     sigclib_get_thisptr(), sigclib_htoa(), sigclib_mutex_name()
// * functionality of cFiFo added
// * functionality of cRingBuffer added


// version 0.20, 11.04.2017 ----------------------------------------------------------------------
// * new functions 
//     sigclib_memoryV1(), sigclib_mallocV1(), sigclib_callocV1(), sigclib_reallocV1(), sigclib_freeV1()


// version 0.19, 01.02.2017 ----------------------------------------------------------------------
// * new functions
//     sigclib_str16_to_utf8(), sigclib_utf8_to_str16(), sigclib_serviceprovider(), sigclib_is_salamander()
//     sigclib_u32ipaddress(), sigclib_crc64()
// * new methods
//     ToStr16, ToStr08, StrLen16, StrCpy16, StrCmp16, StrCat16, StrChr16, StrUpr16, StrLwr16, StrStr16, Str16ToUtf8, Utf8ToStr16
// * #ifdef _DefineCompileH bei headerfile DefineCompiler.h eingebaut
// * optimierung für ARM (GNU O3) bei folgenden funktionen eingeschaltet
//   sigclib_memset(), sigclib_memcpy(), sigclib_memcmp(), sigclib_strlen(), sigclib_strcpy(), sigclib_strcmp(), sigclib_memmove(), 
//   sigclib_strupr(), sigclib_strlwr(), sigclib_strchr(), sigclib_hsort()
