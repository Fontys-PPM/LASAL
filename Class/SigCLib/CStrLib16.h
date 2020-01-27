#ifndef _CStrLib16H
 #define _CStrLib16H

  #include "DefineCompiler.h"

  #ifdef cCompile
  
    // convert ascii-0-string into uni-0-string. function will return parameter 'dst0'
    cExtern unsigned short* sigclib_tostr16(unsigned short *dst0, const char *src0);
    
    // convert uni-0-string into ascii-0-string. each character >255 will be converted to [SPACE]. function will return parameter 'dst0'
    cExtern char*           sigclib_tostr08(char *dst0, const unsigned short *src0);
    
    // get number of characters in uni-0-string.
    cExtern unsigned long   sigclib_strlen16(const unsigned short* str0);
    
    // copy uni-0-string to destination. function will return parameter 'dst0'
    cExtern unsigned short* sigclib_strcpy16(unsigned short* dst0, const unsigned short* src0);
    
    // copies up to 'count' characters from src0 to dst0. in a case where the length of src0 is less than 'count', the remainder of dst will be padded with 0.
    cExtern unsigned short* sigclib_strncpy16(unsigned short* dst0, const unsigned short* src0, unsigned long count);
    
    // compare uni-0-strings. function will return 0 when strings are equal, otherwiese <> 0
    cExtern long            sigclib_strcmp16(const unsigned short *src1, const unsigned short *src2);
    
    // add 'ps2' at the end of 'ps1'. function will return parameter 'src1'
    cExtern unsigned short* sigclib_strcat16(unsigned short *src1, const unsigned short *src2);
    
    // seek address of given character 'i' in uni-0-string. function will return valid pointer or NULL 
    cExtern unsigned short* sigclib_strchr16(const unsigned short *src1, unsigned long i);
    
    // convert all characters to uppercase in given uni-0-string. function will return parameter 'src'.
    cExtern unsigned short* sigclib_strupr16(unsigned short *src);
    
    // convert all characters to lowercase in given uni-0-string. function will return parameter 'src'.
    cExtern unsigned short* sigclib_strlwr16(unsigned short *src);
    
    // seek address of uni-0-string 'lookfor' in uni-0-string 'searchee'. function will return valid pointer or NULL if 'lookfor' is not found in 'searchee'.
    cExtern unsigned short* sigclib_strstr16(const unsigned short* searchee, const unsigned short* lookfor);
    
    // convert unicode-0-string to utf8-0-string, function will return number of characters in destination
    cExtern unsigned long   sigclib_str16_to_utf8(void *dst, const void *src);
    
    // convert utf8-0-string to unicode-0-string, function will return number of characters in destination
    cExtern unsigned long   sigclib_utf8_to_str16(void *dst, const void *src);
    
  #else
  
    // convert ascii-0-string into uni-0-string. function will return parameter 'dst0'
    function global __cdecl sigclib_tostr16 var_input dst0:^uint; src0:^char; end_var var_output retcode:^uint; end_var;
    
    // convert uni-0-string into ascii-0-string. each character >255 will be converted to [SPACE]. function will return parameter 'dst0'
    function global __cdecl sigclib_tostr08 var_input dst0:^char; src0:^uint; end_var var_output retcode:^char; end_var;
    
    // get number of characters in uni-0-string.
    function global __cdecl sigclib_strlen16 var_input str0:^uint; end_var var_output retcode : udint; end_var;
    
    // copy uni-0-string to destination. function will return parameter 'dst0'
    function global __cdecl sigclib_strcpy16 var_input dst0:^uint; src0:^uint; end_var var_output retcode:^uint; end_var;
    
    // copies up to 'count' characters from src0 to dst0. in a case where the length of src0 is less than 'count', the remainder of dst will be padded with 0.
    function global __cdecl sigclib_strncpy16 var_input dst0:^uint; src0:^uint; count:udint; end_var var_output retcode:^uint; end_var;
    
    // compare uni-0-strings. function will return 0 when strings are equal, otherwiese <> 0
    function global __cdecl sigclib_strcmp16 var_input src1:^uint; src2:^uint; end_var var_output retcode:dint; end_var;
    
    // add 'ps2' at the end of 'ps1'. function will return parameter 'src1'
    function global __cdecl sigclib_strcat16 var_input ps1:^uint; ps2:^uint; end_var var_output retcode:^uint; end_var;
    
    // seek address of given character 'i' in uni-0-string. function will return valid pointer or NULL 
    function global __cdecl sigclib_strchr16 var_input ps1:^uint; i:udint; end_var var_output retcode:^uint; end_var;
    
    // convert all characters to uppercase in given uni-0-string. function will return parameter 'src'.
    function global __cdecl sigclib_strupr16 var_input src:^uint; end_var var_output retcode:^uint; end_var;
    
    // convert all characters to lowercase in given uni-0-string. function will return parameter 'src'.
    function global __cdecl sigclib_strlwr16 var_input src:^uint; end_var var_output retcode:^uint; end_var;
    
    // seek address of uni-0-string 'lookfor' in uni-0-string 'searchee'. function will return valid pointer or NULL if 'lookfor' is not found in 'searchee'.
    function global __cdecl sigclib_strstr16 var_input searchee:^uint; lookfor:^uint; end_var var_output retcode:^uint; end_var;

    // convert unicode-0-string to utf8-0-string, function will return number of characters in destination
    function global __cdecl sigclib_str16_to_utf8 var_input dst:^void; src:^void; end_var var_output retcode:udint; end_var;
    
    // convert utf8-0-string to unicode-0-string, function will return number of characters in destination
    function global __cdecl sigclib_utf8_to_str16 var_input dst:^void; src:^void; end_var var_output retcode:udint; end_var;
    
  #endif
#endif  
