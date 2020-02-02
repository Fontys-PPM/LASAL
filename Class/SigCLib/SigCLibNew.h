
#ifndef _SigCLibNew_H
 #define _SigCLibNew_H

 #include "DefineCompiler.h"

 #ifdef cCompile

  #include "SigCLib.h"

  #define strcpy       sigclib_strcpy
  #define strlen       sigclib_strlen
  #define strcat       sigclib_strcat
  #define strchr       sigclib_strchr
  #define isdigit      sigclib_isdigit
  #define islower      sigclib_islower
  #define isupper      sigclib_isupper
  #define tolower      sigclib_tolower
  #define toupper      sigclib_toupper
  #define strupr       sigclib_strupr
  #define strlwr       sigclib_strlwr
  #define strcmp       sigclib_strcmp
  #define strncmp      sigclib_strncmp
  #define strncpy      sigclib_strncpy
  #define strspn       sigclib_strspn
  #define strcspn      sigclib_strcspn
  #define strncat      sigclib_strncat
  #define strstr       sigclib_strstr
  #define strtol       sigclib_strtol
  #define strtoul      sigclib_strtoul
  #define strtof       sigclib_strtof
  #define strtod       sigclib_strtod
  #define stricmp      sigclib_stricmp
  #define strcasecmp   sigclib_strcasecmp
  #define strncasecmp  sigclib_strncasecmp
  #define strpbrk      sigclib_strpbrk
  #define atoi         sigclib_atoi
  #define itoa         sigclib_itoa
  #define atol         sigclib_atol
  #define atoll        sigclib_atoll
  #define atof         sigclib_atof
  #define memset       sigclib_memset
  #define memcpy       sigclib_memcpy
  #define memmove      sigclib_memmove
  #define memcmp       sigclib_memcmp
  #define memchr       sigclib_memchr
  #define memicmp      sigclib_memicmp
  #define hsort        sigclib_hsort
  #define hfind        sigclib_hfind
  #define printf       sigclib_printf
  #define sprintf      sigclib_sprintf
  #define free         sigclib_free
  #define malloc       sigclib_malloc
  #define calloc       sigclib_calloc
  #define realloc      sigclib_realloc
  
  
    
  
  
  
 #endif
#endif
