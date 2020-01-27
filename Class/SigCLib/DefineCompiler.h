#ifndef _DefineCompilerH
  #define _DefineCompilerH
  
  #ifndef cCompile
  
    #define cOptimize

    #ifdef _MSC_VER
      #define cCompile
    #endif
    #ifdef _GNUC
      #define cCompile
      
      #if (__GNUC > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 4))
       // ab gnu version 4.4 funktioniert setup 03 zum code-optimieren
       #undef cOptimize
       #define cOptimize __attribute__ ((optimize (3)))
      #endif
    #endif
  
  #endif

  #ifdef cCompile

    #ifndef cExtern
      #ifdef __cplusplus
        #define cExtern extern "C"
      #else
        #define cExtern extern 
      #endif
    #endif
  
  #endif
  
#endif

 
 
 