// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 22.09.2018                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// | Usage:                                                                                       |
// |   void *heap = sigclib_heap_CTor(100000);       // create heap with size of 100000 bytes     |
// |   void *puser = sigclib_heap_malloc(heap, 100); // reserve 100 bytes on heap                 |
// |   sigclib_heap_free(heap, puser);               // free reserved bytes                       |
// |   sigclib_heap_check(heap, NULL);               // check heap                                |
// |   sigclib_heap_check(heap, puser);              // check single heapblock                    |
// |   sigclib_heap_DTor(heap);                      // destroy heap                              |
// +----------------------------------------------------------------------------------------------+

#ifndef _CHeap_H
 #define _CHeap_H
 
 #include "DefineCompiler.h" 

 #ifdef cCompile
   
  // create heap 
  cExtern void *sigclib_heap_CTor(unsigned long size);
  
  // destroy already created heap
  cExtern void *sigclib_heap_DTor(void *php0);
  
  // check whole heap or single heapblock
  cExtern unsigned long sigclib_heap_check(void *php0, void *pt);
  
  // free whole data on heap
  cExtern void sigclib_heap_empty(void *php0);
  
  // allocate memory
  cExtern void *sigclib_heap_malloc(void *php0, unsigned long size, unsigned long id);

  // realloc memory
  cExtern void *sigclib_heap_realloc(void *php0, void *pt, unsigned long size);
  
  // free allocated memory
  cExtern void *sigclib_heap_free(void *php0, void *pt);

  // alloc, realloc and free memory  
  cExtern unsigned long sigclib_heap_memory(void *php0, void **pptr, unsigned long size, unsigned long id);

  // get allocated info about heap, do not forget to free info after usage
  cExtern unsigned long *sigclib_heap_info(void *php0);

  // get number and size of used datablocks 
  cExtern unsigned long sigclib_heap_used(void *php0, unsigned long *pno, unsigned long *psize);


 #else
 
  // create heap 
  function global __cdecl sigclib_heap_CTor var_input size:udint; end_var var_output retcode:^void; end_var;
  
  // destroy already created heap
  function global __cdecl sigclib_heap_DTor var_input php0:^void; end_var var_output retcode:^void; end_var;
  
  // check whole heap or single heapblock
  function global __cdecl sigclib_heap_check var_input php0:^void; pt:^void; end_var var_output retcode:udint; end_var;
  
  // free whole data on heap
  function global __cdecl sigclib_heap_empty var_input php0:^void; end_var;
  
  // allocate memory
  function global __cdecl sigclib_heap_malloc var_input php0:^void; size:udint; id:udint; end_var var_output retcode:^void; end_var;
  
  // realloc memory
  function global __cdecl sigclib_heap_realloc var_input php0:^void; pt:^void; size:udint; end_var var_output retcode:^void; end_var;
  
  // free allocated memory
  function global __cdecl sigclib_heap_free var_input php0:^void; pt:^void; end_var var_output retcode:^void; end_var;
  
  // alloc, realloc and free memory  
  function global __cdecl sigclib_heap_memory var_input php0:^void; pptr:^pvoid; size:udint; id:udint; end_var var_output retcode:udint; end_var;
 
  // get allocated info about heap, do not forget to free info after usage
  function global __cdecl sigclib_heap_info var_input php0:^void; end_var var_output retcode:^udint; end_var;
 
  // get number and size of used datablocks 
  function global __cdecl sigclib_heap_used var_input php0:^void; pno:^udint; psize:^udint; end_var var_output retcode:udint; end_var;
 
 #endif
 
#endif 
