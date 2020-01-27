#ifndef _CAtomicH
 #define _CAtomicH
  
  #include "DefineCompiler.h"

  // use atomic functions to change value (S32, U32) in memory by using named operator (inc, dec, add, sub, swp, cmpxchg)
  // retcode of each function is the value right before performing operator to memorylocation 

  #ifdef cCompile
    
    // atomic get u32
    cExtern unsigned long sigclib_atomic_getU32(unsigned long *pValue);
    // atomic set u32
    cExtern unsigned long sigclib_atomic_setU32(unsigned long *pValue, unsigned long value);
    // atomic increment of u32bit, return value corresponds to value before operator was executed
    cExtern unsigned long sigclib_atomic_incU32(unsigned long *pValue);
    // atomic decrement of u32bit, return value corresponds to value before operator was executed
    cExtern unsigned long sigclib_atomic_decU32(unsigned long *pValue);
    // atomic add of u32bit, return value corresponds to value before operator was executed
    cExtern unsigned long sigclib_atomic_addU32(unsigned long *pValue, unsigned long addVal);
    // atomic sub of u32bit, return value corresponds to value before operator was executed
    cExtern unsigned long sigclib_atomic_subU32(unsigned long *pValue, unsigned long addVal);
    // atomic swap of u32bit, return value corresponds to value before operator was executed
    cExtern unsigned long sigclib_atomic_swpU32(unsigned long *pValue, unsigned long swpVal);
    // atomic compareXchange u32 bit, return value corresponds to value before operator was executed
    cExtern unsigned long sigclib_atomic_cmpxchgU32(unsigned long *pValue, unsigned long cmpVal, unsigned long newVal);
    
    // atomic get s32
    cExtern long sigclib_atomic_getS32(long *pValue);
    // atomic set s32
    cExtern long sigclib_atomic_setS32(long *pValue, long value);
    // atomic increment of s32bit, return value corresponds to value before operator was executed
    cExtern long sigclib_atomic_incS32(long *pValue);
    // atomic decrement of s32bit, return value corresponds to value before operator was executed
    cExtern long sigclib_atomic_decS32(long *pValue);
    // atomic add of s32bit, return value corresponds to value before operator was executed
    cExtern long sigclib_atomic_addS32(long *pValue, long addVal);
    // atomic sub of s32bit, return value corresponds to value before operator was executed
    cExtern long sigclib_atomic_subS32(long *pValue, long subVal);
    // atomic swap of s32bit, return value corresponds to value before operator was executed
    cExtern long sigclib_atomic_swpS32(long *pValue, long swpVal);
    // atomic compareXchange s32 bit, return value corresponds to value before operator was executed
    cExtern long sigclib_atomic_cmpxchgS32(long *pValue, long cmpVal, long newVal);
    
  #else
  
    // atomic get u32
    function global __cdecl sigclib_atomic_getU32 var_input pValue:^udint; end_var var_output retcode:udint; end_var;
    // atomic set u32
    function global __cdecl sigclib_atomic_setU32 var_input pValue:^udint; value:udint; end_var;
    // atomic increment of u32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_incU32 var_input pValue:^udint; end_var var_output retcode:udint; end_var;
    // atomic decrement of u32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_decU32 var_input pValue:^udint; end_var var_output retcode:udint; end_var;
    // atomic add of u32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_addU32 var_input pValue:^udint; addVal:udint; end_var var_output retcode:udint; end_var;
    // atomic sub of u32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_subU32 var_input pValue:^udint; subVal:udint; end_var var_output retcode:udint; end_var;
    // atomic swap u32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_swpU32 var_input pValue:^udint; swpVal:udint; end_var var_output retcode:udint; end_var;
    // atomic compareXchange u32 bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_cmpxchgU32 var_input pValue:^udint; cmpVal:udint; newVal:udint; end_var var_output retcode:udint; end_var;
    
    // atomic get s32
    function global __cdecl sigclib_atomic_getS32 var_input pValue:^dint; end_var var_output retcode:dint; end_var;
    // atomic set s32
    function global __cdecl sigclib_atomic_setS32 var_input pValue:^dint; value:dint; end_var;
    // atomic increment of s32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_incS32 var_input pValue:^dint; end_var var_output retcode:dint; end_var;
    // atomic decrement of s32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_decS32 var_input pValue:^dint; end_var var_output retcode:dint; end_var;
    // atomic add of s32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_addS32 var_input pValue:^dint; addVal:dint; end_var var_output retcode:dint; end_var;
    // atomic sub of s32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_subS32 var_input pValue:^dint; subVal:dint; end_var var_output retcode:dint; end_var;
    // atomic swap s32bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_swpS32 var_input pValue:^dint; swpVal:dint; end_var var_output retcode:dint; end_var;
    // atomic compareXchange s32 bit, return value corresponds to value before operator was executed
    function global __cdecl sigclib_atomic_cmpxchgS32 var_input pValue:^dint; cmpVal:dint; newVal:dint; end_var var_output retcode:dint; end_var;
    
  #endif
  
#endif

//Atomic Operationen
//type __sync_fetch_and_or (type *ptr, type value, ...)
//type __sync_fetch_and_and (type *ptr, type value, ...)
//type __sync_fetch_and_xor (type *ptr, type value, ...)
//type __sync_fetch_and_nand (type *ptr, type value, ...)
//type __sync_or_and_fetch (type *ptr, type value, ...)
//type __sync_and_and_fetch (type *ptr, type value, ...)
//type __sync_xor_and_fetch (type *ptr, type value, ...)
//type __sync_nand_and_fetch (type *ptr, type value, ...)

