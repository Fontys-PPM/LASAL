// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 30.04.2019                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#ifndef _CLimits_H
 #define _CLimits_H
 
 #include "DefineCompiler.h" 

 #ifdef cCompile

   #ifndef sigclib_SHORT_MAX
    #define sigclib_SHORT_MAX     32767
   #endif
   #ifndef sigclib_SHORT_MIN
    #define sigclib_SHORT_MIN     (-sigclib_SHORT_MAX -1)
   #endif

   #ifndef sigclib_USHORT_MAX
    #define sigclib_USHORT_MAX    65535
   #endif
   #ifndef sigclib_USHORT_MIN
    #define sigclib_USHORT_MIN    0
   #endif

   #ifndef sigclib_LONG_MAX
    #define sigclib_LONG_MAX      2147483647L
   #endif
   #ifndef sigclib_LONG_MIN
    #define sigclib_LONG_MIN      (-sigclib_LONG_MAX -1L)
   #endif
   
   #ifndef sigclib_ULONG_MAX
    #define sigclib_ULONG_MAX     4294967295UL
   #endif
   #ifndef sigclib_ULONG_MIN
    #define sigclib_ULONG_MIN     0UL
   #endif
   
   #ifndef sigclib_LONG_LONG_MAX
    #define sigclib_LONG_LONG_MAX 9223372036854775807LL
   #endif
   #ifndef sigclib_LONG_LONG_MIN
    #define sigclib_LONG_LONG_MIN (-sigclib_LONG_LONG_MAX -1)
   #endif

   #ifndef sigclib_FLOAT_MIN
    #define sigclib_FLOAT_MIN -340282346638528859811704183484516925440.0
   #endif 
   #ifndef sigclib_FLOAT_MAX
    #define sigclib_FLOAT_MAX  340282346638528859811704183484516925440.0
   #endif

 #else

 #endif
 
#endif
