
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

    // compare 2 strings (AaBbCc...-algorithm)
    cExtern long sigclib_sortfkt_ABC(unsigned char **pp0, unsigned char **pp1);
                       
    // compare 2 strings (ABCabc...-algorithm)
    cExtern long sigclib_sortfkt_ASCII(unsigned char **pp0, unsigned char **pp1);

    // sort textbuffer
    cExtern long sigclib_sort_txtptr(char **pptxt, unsigned long no, unsigned long criteria);

    // sort textbuffer
    cExtern long sigclib_sort_txtbuffer(char *buff, unsigned long no, unsigned long criteria);

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

    // compare 2 strings (ABCabc...-algorithm)
    function global __cdecl sigclib_sortfkt_ASCII var_input pp0:^pvoid; pp1:^pvoid; end_var var_output retcode:dint; end_var;
                       
    // compare 2 strings (AaBbCc...-algorithm)
    function global __cdecl sigclib_sortfkt_ABC var_input pp0:^pvoid; pp1:^pvoid; end_var var_output retcode:dint; end_var;

    // sort textbuffer
    function global __cdecl sigclib_sort_txtptr var_input pptxt:^pvoid; no:udint; criteria:udint; end_var var_output retcode:dint; end_var;
    
    // sort textbuffer
    function global __cdecl sigclib_sort_txtbuffer var_input pbuff:^char; no:udint; criteria:udint; end_var var_output retcode:dint; end_var;

  #endif
 
#endif


// ************************************************************************************************
// USAGE
// ************************************************************************************************

// ------------------------------------------------------------------------------------------------
// long sigclib_hsort(void *src0, unsigned long anz, unsigned long size, void *pfunct);
// void sigclib_qsort(const void *base, unsigned long nmemb, unsigned long size, long (*compar)(const void*, const void*))
// sortfunction to sort arbitrary list of entries with constant length
// --> src0, base....... pointer to list
// --> anz, nmemb ...... number of entries in list
// --> size ............ bytesize of single entry in list
// --> pfunct, compar .. pointer to userdefined compare-function eg.: long comparator(void *p0, void *p1) 
// <-- function will return <>0 when list is well sorted, 0...error nothing changed in list
// NOTE: internal used algorithm will work "fast", "inplace", "non recusive" and "not stable"

// Example: 
// long comparator(unsigned long *p0, unsigned long *p1)
// {
//   if(*p0 < *p1) { return -1; }
//   if(*p0 > *p1) { return 1; }
//   return 0; 
// }
// 
// void mymain(void)
// {
//   ...
//   sigclib_hsort(data, 17, sizeof(unsigned long), (void*)sort_criteria);
// }
  
// ------------------------------------------------------------------------------------------------
// cExtern long sigclib_hfind(void *src0, unsigned long anz, unsigned long size, void *pfunct, void *pvgl);
// function is used to find index of element in sorted buffer. 
// --> src0 ............ pointer to sorted list
// --> anz ............. number of entries in list
// --> size ............ bytesize of single entry in list
// --> pfunct .......... pointer to userdefined compare-function eg.: long comparator(void *p0, void *p1) 
// --> pvgl ............ element to compare
// <-- function will return valid index or value smaller than 0 when element is not found
// NOTE: List has to be sorted by same criteria, otherwise function will not work properly

// ------------------------------------------------------------------------------------------------
// void* sigclib_bsearch(const void *key, const void *base, unsigned long nmemb, unsigned long size, long (*compar)(const void*, const void*));
// get pointer to element in sorted buffer
// --> key ............. element to compare
// --> base ............ pointer to sorted list
// --> nmemb ........... number of entries in list
// --> size ............ bytesize of single entry in list
// --> compar .......... pointer to userdefined compare-function eg.: long comparator(void *p0, void *p1) 
// <-- function will return valid pointer when entry was found or NULL
// NOTE: List has to be sorted by same criteria, otherwise function will not work properly

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_bsearch_index(const void *key, const void *base, unsigned long nmemb, unsigned long size, long (*compar)(const void*, const void*));
// get index to element in sorted buffer
// --> key ............. element to compare
// --> base ............ pointer to sorted list
// --> nmemb ........... number of entries in list
// --> size ............ bytesize of single entry in list
// --> compar .......... pointer to userdefined compare-function eg.: long comparator(void *p0, void *p1) 
// <-- function will return valid index or 0xFFFFFFFF
// NOTE: List has to be sorted by same criteria, otherwise function will not work properly

// ------------------------------------------------------------------------------------------------
// long sigclib_sortfkt_ABC(unsigned char **pp0, unsigned char **pp1)
// long sigclib_sortfkt_ASCII(unsigned char **pp0, unsigned char **pp1)
// compare 2 strings by using alphabetical or ASCII algorithm
// --> pp0 ............. adress of pointer to str0 (pointer to pointer) 
// --> pp1 ............. adress of pointer to str1 (pointer to pointer) 
// <-- function will retrurn -1 when str0 is "smaller" than str1, 1 when str0 is "bigger" than str1 and 0 when both strings are equal

// ------------------------------------------------------------------------------------------------
// long sigclib_sort_txtptr(char **pptxt, unsigned long no, unsigned long criteria);
// sort pointerlist of ascii-0-text
// --> pptxt ........... pointerlist of ascii-0-text
// --> no .............. number of pointer in list
// --> criteria ........ 0 = sort ASCII, 1 = sort alphabetical (AaBbCc..)
// <-- function will return <>0 when list is well sorted, 0...error nothing changed in list

// ------------------------------------------------------------------------------------------------
// long sigclib_sort_txtbuffer(char *buff, unsigned long no, unsigned long criteria);
// sort textlist of sequential ascii-0-text
// --> buff ............ startaddress of ascii-0-terminated textlist
// --> no .............. number of text in list
// --> criteria ........ 0 = sort ASCII, 1 = sort alphabetical (AaBbCc..)
// <-- function will return <>0 when list is well sorted, 0...error nothing changed in list

