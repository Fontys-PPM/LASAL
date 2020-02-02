#ifndef _CStrLibInternH
 #define _CStrLibInternH
 
  #define c_PRINT  0x0001
  #define c_GRAPH  0x0002
  #define c_PUNCT  0x0004 
  #define c_ALNUM  0x0008
  #define c_XDIGIT 0x0010 
  #define c_DIGIT  0x0020 
  #define c_ALPHA  0x0040
  #define c_LOWER  0x0080 
  #define c_UPPER  0x0100 
  #define c_SPACE  0x0200 
  #define c_CNTRL  0x0400 

  extern const unsigned short sigclib_TypeOfC[256];
  extern const unsigned char  sigclib_DezHex[16];

  #define _ISLOWER(A) (sigclib_TypeOfC[(unsigned char)(A)] & c_LOWER)
  #define _ISUPPER(A) (sigclib_TypeOfC[(unsigned char)(A)] & c_UPPER)
  #define _ISDIGIT(A) (sigclib_TypeOfC[(unsigned char)(A)] & c_DIGIT)
  #define _ISSPACE(A) (sigclib_TypeOfC[(unsigned char)(A)] & c_SPACE)
  #define _ISALPHA(A) (sigclib_TypeOfC[(unsigned char)(A)] & c_ALPHA)

  #define _TOUPPER(A) (_ISLOWER(A)? ((A) - 'a' + 'A') : (A))
  #define _TOLOWER(A) (_ISUPPER(A)? ((A) - 'A' + 'a') : (A))
  
#endif