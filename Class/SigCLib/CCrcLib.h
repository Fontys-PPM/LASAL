#ifndef _CCrcLibH
 #define _CCrcLibH
  
  #include "DefineCompiler.h"

  #ifdef cCompile
    // compute crc32 of given data
    cExtern unsigned long sigclib_crc32(unsigned long initval, void *psrc, unsigned long length);
    cExtern unsigned long long sigclib_crc64(unsigned long long initval, void *psrc, unsigned long length);
  #else
    // compute crc32 of given data
    function global __cdecl sigclib_crc32 var_input initval:udint; psrc:^void; length:udint; end_var var_output retcode:udint; end_var;
  #endif
  
#endif
