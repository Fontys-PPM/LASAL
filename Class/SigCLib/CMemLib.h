#ifndef _CMemLibH
 #define _CMemLibH

  #include "DefineCompiler.h"

  //#define HEAPBUBBLE_INUSE 20000000 // todo: nur test, immer ausschalten

  #ifdef cCompile

    // alloc memory
    cExtern void* sigclib_malloc(unsigned long size);
    cExtern void* sigclib_mallocV1(unsigned long size, unsigned long id);

    // calloc memory (alloc + memset(0))
    cExtern void* sigclib_calloc(unsigned long num, unsigned long size);
    cExtern void* sigclib_callocV1(unsigned long num, unsigned long size, unsigned long id);
  
    // realloc memory
    cExtern void* sigclib_realloc(void* ptr, unsigned long size);
    cExtern void* sigclib_reallocV1(void* ptr, unsigned long size, unsigned long id);
  
    // free memory
    cExtern void  sigclib_free(void* ptr);
    cExtern void  sigclib_freeV1(void* ptr);
  
    // alloc, realloc and free memory
    cExtern unsigned long sigclib_memory(void **pptr, unsigned long size);
    cExtern unsigned long sigclib_memoryV1(void **pptr, unsigned long size, unsigned long id);

    // get temporary membuffer
    cExtern void *sigclib_buffer_create(void *statbuff, unsigned long statbuff_size, unsigned long expected_size);
    
    // free temporary membuffer
    cExtern void *sigclib_buffer_destroy(void *statbuff, void *buffer);

  #else
  
    // alloc memory
    function global __cdecl sigclib_malloc var_input size : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_mallocV1 var_input size : udint; id : udint; end_var var_output retcode : ^void; end_var;
  
    // calloc memory (alloc + memset(0))
    function global __cdecl sigclib_calloc var_input num : udint; size : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_callocV1 var_input num : udint; size : udint; id : udint; end_var var_output retcode : ^void; end_var;
  
    // realloc memory
    function global __cdecl sigclib_realloc var_input ptr : ^void; size : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_reallocV1 var_input ptr : ^void; size : udint; id : udint; end_var var_output retcode : ^void; end_var;
  
    // free memory
    function global __cdecl sigclib_free var_input ptr : ^void; end_var;
    function global __cdecl sigclib_freeV1 var_input ptr : ^void; end_var;
  
    // alloc, realloc and free memory
    function global __cdecl sigclib_memory var_input pptr : ^pvoid; size : udint; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_memoryV1 var_input pptr : ^pvoid; size : udint; id : udint; end_var var_output retcode : udint; end_var;
  
    // get temporary membuffer
    function global __cdecl sigclib_buffer_create var_input statbuff:^void; statbuff_size:udint; expected_size:udint; end_var var_output retcode:^void; end_var;
    
    // free temporary membuffer
    function global __cdecl sigclib_buffer_destroy var_input statbuff:^void; buffer:^void; end_var var_output retcode:^void; end_var;
  
  #endif
 
#endif


// ************************************************************************************************
// USAGE
// ************************************************************************************************

// ------------------------------------------------------------------------------------------------
// void* sigclib_malloc(unsigned long size);
// void* sigclib_mallocV1(unsigned long size, unsigned long id);
// allocate memory
// --> size ............ bytesize of memory to allocate
// --> id (optional) ... any arbitrary number 0-15
// <-- function will return valid pointer to allocated memory or NULL when not enough memory is left

// ------------------------------------------------------------------------------------------------
// void* sigclib_calloc(unsigned long num, unsigned long size);
// void* sigclib_callocV1(unsigned long num, unsigned long size, unsigned long id);
// allocate memory and set whole content to to 0 (malloc + memset(0))
// --> num ............. number of memoryblocks to allocate
// --> size ............ size of single memoryblock to allocate
// --> id (optional) ... any arbitrary number 0-15
// <-- function will return valid pointer to allocated memory of bytesize (num * size) or NULL when not enough memory is left
  
// ------------------------------------------------------------------------------------------------
// void* sigclib_realloc(void* ptr, unsigned long size);
// void* sigclib_reallocV1(void* ptr, unsigned long size, unsigned long id);
// resize already allocated memory (keep memory-content)
// --> ptr ............. valid pointer to already allocated memory to resize
// --> size ............ new bytesize to expect
// --> id (optional) ... any arbitrary number 0-15
// <-- function will return valid pointer to reallocated memory or NULL when not enough memory is left
  
// ------------------------------------------------------------------------------------------------
// void  sigclib_free(void* ptr);
// void  sigclib_freeV1(void* ptr);
// free already allocated memory
// --> ptr ............. valid pointer to already allocated memory to free
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_memory(void **pptr, unsigned long size);
// unsigned long sigclib_memoryV1(void **pptr, unsigned long size, unsigned long id);
// alloc, realloc and free memory
// --> pptr ............ address of pointer to alloc, realloc or free
// --> size ............ bytesize to expect
// <-- function will return <> 0 on success, on the other hand 0
// NOTE: Pointer has to be initialized by NULL before first usage

// ------------------------------------------------------------------------------------------------
// void *sigclib_buffer_create(void *statbuff, unsigned long statbuff_size, unsigned long expected_size);
// function is able to manage temporary memorybuffer of arbitrary size.
// --> statbuff ........ pointer to static memory
// --> statbuff_size ... size of static memory in bytes
// --> expected_size ... expected size of membuffer to use
// <-- function will return valid pointer to membuffer on success, on the other hand NULL
// NOTE: Do not forget usage of function sigclib_buffer_destroy() afterwards to avoid possibly memleak.
//       When size fits into given static buffer, function will return pointer to static buffer, on the other hand pointer to newly allocated memory.
    
// ------------------------------------------------------------------------------------------------
// void *sigclib_buffer_destroy(void *statbuff, void *buffer);
// free temporary membuffer
// --> statbuff ........ pointer to static memory
// --> buffer .......... pointer to memory in used created by function sigclib_buffer_create()
// <-- function will always return NULL
