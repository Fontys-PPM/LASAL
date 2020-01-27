
#ifndef _CSortLibH
 #define _CSortLibH

  #include "DefineCompiler.h"

  #ifdef cCompile

    typedef long (*_sigclib_SFKT) (void*, void*); // return -1(a<b), 0(a=b) oder 1(a>b)

    // sortfunction, return <>0...list is well sorted, 0...error, nothing changed in list 
    cExtern long sigclib_hsort(void *src0, unsigned long anz, unsigned long size, void *pfunct);
  
    // find index of element in sorted buffer. function will return valid index or value smaller than 0
    cExtern long sigclib_hfind(void *src0, unsigned long anz, unsigned long size, void *pfunct, void *pvgl);
  
    // sortfunction
    cExtern void sigclib_qsort(const void *base, unsigned long nmemb, unsigned long size, long (*compar)(const void*, const void*));
  
    // get pointer to element in sorted buffer, function will return valid pointer or NIL
    cExtern void* sigclib_bsearch(const void *key, const void *base, unsigned long nmemb, unsigned long size, long (*compar)(const void*, const void*));

    // get index to element in sorted buffer, function will return valid index or 0xFFFFFFFF
    cExtern unsigned long sigclib_bsearch_index(const void *key, const void *base, unsigned long nmemb, unsigned long size, long (*compar)(const void*, const void*));

  #else

    // sortfunction, return <>0...list is well sorted, 0...error, nothing changed in list
    function global __cdecl sigclib_hsort var_input src0 : ^void; anz : udint; size : udint; pfunct : ^void; end_var var_output retcode : dint; end_var;
    
    // find index of element in sorted buffer. function will return valid index or value smaller than 0
    function global __cdecl sigclib_hfind var_input src0 : ^void; anz : udint; size : udint; pfunct : ^void; pvgl : ^void; end_var var_output retcode : dint; end_var;

    // sortfunction
    function global __cdecl sigclib_qsort var_input base : ^void; nmemb : udint; size : udint; pfunct : ^void; end_var;
  
    // get pointer to element in sorted buffer, function will return valid pointer or NIL
    function global __cdecl sigclib_bsearch var_input key : ^void; base : ^void; nmemb : udint; size : udint; ffunct : ^void; end_var var_output retcode : ^void; end_var;

    // get index to element in sorted buffer, function will return valid index or 0xFFFFFFFF
    function global __cdecl sigclib_bsearch_index var_input key : ^void; base : ^void; nmemb : udint; size : udint; ffunct : ^void; end_var var_output retcode : ^udint; end_var;

  #endif
 
#endif
