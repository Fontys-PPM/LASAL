#ifndef _CStrLibH
 #define _CStrLibH

  #include "DefineCompiler.h"

  #ifdef cCompile
  
    cExtern char*           sigclib_strcpy(char* dst0, const char* src0);
    cExtern unsigned long   sigclib_strlen(const char* str);
    cExtern char*           sigclib_strcat(char* s1, const char* s2);
    cExtern char*           sigclib_strchr(const char* s1, int i);
    cExtern int             sigclib_isdigit(int c);
    cExtern int             sigclib_islower(int c);
    cExtern int             sigclib_isupper(int c);
    cExtern char            sigclib_tolower(int c);
    cExtern char            sigclib_toupper(int c);
    cExtern char*           sigclib_strupr(char *s);
    cExtern char*           sigclib_strlwr(char* s);
    cExtern int             sigclib_strcmp(const char *s1, const char *s2);
    cExtern int             sigclib_strncmp(const char* s1, const char* s2, unsigned long count);
    cExtern char*           sigclib_strncpy(char* dst0, const char* src0, unsigned long count);
    cExtern long            sigclib_strspn(const char* s1, const char* s2);
    cExtern char*           sigclib_strncat(char* s1, const char* s2, unsigned long len);
    cExtern char*           sigclib_strstr(const char* searchee, const char* lookfor);
    cExtern int             sigclib_atoi(const char* s);
    cExtern long            sigclib_atol(const char* s);
    cExtern float           sigclib_atof(const char* s);
    cExtern void            sigclib_atof_ST(float *presult, const char* s);
    cExtern char*           sigclib_itoa(int val, char* s, int base);
     extern char*           sigclib_ftoa(float value, char *result, unsigned long digits);
    cExtern char*           sigclib_ftoa_ST(float *pvalue, char *result, unsigned long digits);
     extern char*           sigclib_ftoa_comma(float value, char *result, unsigned long digits, char comma);
    cExtern char*           sigclib_ftoa_comma_ST(float *pvalue, char *result, unsigned long digits, char comma);
    cExtern char*           sigclib_dtoa(char *dst, double value, unsigned long digits);
    cExtern char*           sigclib_htoa(char *dst, unsigned long value);
    cExtern void*           sigclib_memset(void *dst, long c, unsigned long len);
    cExtern void*           sigclib_memcpy(void* dst0, const void* src0, unsigned long len0);
    cExtern void*           sigclib_memmove(void* dst0, const void* src0, unsigned long len0);
    cExtern int             sigclib_memcmp(const void* m1, const void* m2, unsigned long len);
    cExtern void*           sigclib_memchr(void* src_void, int c, unsigned long length);
    cExtern int             sigclib_memicmp(const void* s1, const void* s2, unsigned long length);
    cExtern long            sigclib_strtol(const char* nptr, char** endptr, int base);
    cExtern unsigned long   sigclib_strtoul(const char* nptr, char** endptr, int base);
    cExtern float           sigclib_strtof(const char* source, char** end);
    cExtern double          sigclib_strtod(const char* source, char** end);
    cExtern int             sigclib_strcasecmp(const char* s1, const char* s2);
    cExtern int             sigclib_strncasecmp(const char* s1, const char* s2, unsigned long count);
    cExtern char*           sigclib_inet_ntoa(char *dst, unsigned long in4);
    cExtern unsigned long   sigclib_inet_addr(char* src);
    cExtern void            sigclib_tracemessage(char *txt);
    cExtern char*           sigclib_mutex_name(char *dst, const char *label, void *pthis);

    
    cExtern double          sigclib64_atof(const char *txt);

  #else
  
    function global __cdecl sigclib_strcpy var_input dst0 : ^char; src0 : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strlen var_input str : ^char; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_strcat var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strchr var_input ps1 : ^char; i : dint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_isdigit var_input c : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_islower var_input c : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_isupper var_input c : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_tolower var_input c : dint; end_var var_output retcode : char; end_var;
    function global __cdecl sigclib_toupper var_input c : dint; end_var var_output retcode : char; end_var;
    function global __cdecl sigclib_strupr var_input s : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strlwr var_input s : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strcmp var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncmp var_input ps1 : ^char; ps2 : ^char; count : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncpy var_input dst0 : ^char; src0 : ^char; count : udint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strspn var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncat var_input ps1 : ^char; ps2 : ^char; len : udint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strstr var_input searchee : ^char; lookfor : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_atoi var_input s : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_itoa var_input val : dint; dst : ^char; base : dint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_ftoa_ST var_input pval : ^real; dst : ^char; digits : udint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_ftoa_comma_ST var_input pval : ^real; dst : ^char; digits : udint; comma : char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_atol var_input s : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_atof_ST var_input retval : ^real; s : ^char; end_var;
    function global __cdecl sigclib_dtoa var_input txt:^char; value:lreal; no:udint; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_htoa var_input txt:^char; value:udint; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_memset var_input dst : ^void; c : dint; len : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memcpy var_input dst0 : ^void; src0 : ^void; len0 : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memmove var_input dst0 : ^void; src0 : ^void; len0 : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memcmp var_input m1 : ^void; m2 : ^void; len : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_memchr var_input src : ^void; c : dint; length : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memicmp var_input ps1 : ^void; ps2 : ^void; length : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strtol var_input nptr : ^char; endptr : ^pvoid; base : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strtoul var_input nptr : ^char; endptr : ^pvoid; base : dint; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_strtod var_input nptr : ^char; endptr : ^pvoid; end_var var_output retcode : lreal; end_var;
    function global __cdecl sigclib_strtof_st var_input nptr : ^char; endptr : ^pvoid; end_var var_output retcode : real; end_var;
    function global __cdecl sigclib_strcasecmp var_input stest1 : ^char; stest2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncasecmp var_input stest1 : ^char; stest2 : ^char; count : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_inet_ntoa var_input dst:^char; in4:udint; end_var var_output retcode : ^char; end_var; 
    function global __cdecl sigclib_inet_addr var_input src:^char; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_mutex_name var_input dst:^char; label:^char; pthis:^void; end_var var_output retcode : ^char; end_var;
  
  #endif
 
#endif
