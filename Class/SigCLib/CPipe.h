// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 10.07.2017                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// | cPipe entspricht einem FiFo, arbeitet taskübergreifend und funktioniert ohne Semaphor (Mutex)|
// | Es dürfen von verschiedenen Taskprioritäten Records eingetragen und auch ausgelesen werden.  |
// |                                                                                              |
// | NOTE:                                                                                        |
// |   Optimale Anzahl an Records sind: 2, 4, 8, 16, 32, 46, 128, 256...                          |
// |   maximale Anzahl an Records ist: 65536                                                      |
// +----------------------------------------------------------------------------------------------+

#ifndef _cPipeH
 #define _cPipeH
  
 #include "DefineCompiler.h" 
  
 #ifdef cCompile // *******************************************************************************

  #pragma pack(push, 1)
   typedef struct
   {
     unsigned long rd;          // index readposition
     unsigned long wr;          // index writeposition
     unsigned long rd_lock;     // rd_lock
     unsigned long record_no;   // number of record in buffer
     unsigned long record_size; // bytesize of single record in buffer
     unsigned long record_user; // bytesize of userdata in buffer
     unsigned long bitpattern;  // bitpattern used for %
     unsigned char *data;       // pointer to recordbuffer
   }
   cPipe;
  #pragma pack(pop)
  
  // constructor used to construct cPipe
  cExtern cPipe        *cPipe_CTor(unsigned long record_size, unsigned long record_no);
  // destructor of cPipe (use only when constructor is in use)
  cExtern cPipe        *cPipe_DTor(cPipe *p);
  // initialize cPipe (do not use when CTor is in use)
  cExtern unsigned long cPipe_Init(cPipe *p, unsigned long record_size, unsigned long record_no);
  // free cPipe (do not use when CTor is in use)
  cExtern void          cPipe_Free(cPipe *p);
  // function is used to add new record. function will return 1 on success, on the other hand 0
  cExtern unsigned long cPipe_Add(cPipe *p, void *pdata, unsigned long datasize);
  // function is used to get record from Pipe. function will return 1 on success (got valid recorddata) on the other hand 0
  cExtern unsigned long cPipe_Get(void *pd, cPipe *p);
  // get number of used records in buffer
  cExtern unsigned long cPipe_GetUsed(cPipe *p);
  // get number of unused records in buffer
  cExtern unsigned long cPipe_GetUnUsed(cPipe *p);
  
 #else // cCompile ********************************************************************************
 
  // constructor used to construct cPipe
  function global __cdecl cPipe_CTor var_input record_size:udint; record_no:udint; end_var var_output retcode:^void; end_var;
  // destructor of cPipe (use only when constructor is in use)
  function global __cdecl cPipe_DTor var_input p:^void; end_var var_output retcode:^void; end_var;
  
  // function is used to add new record. function will return 1 on success, on the other hand 0
  function global __cdecl cPipe_Add var_input p:^void; pdata:^void; datasize:udint; end_var var_output retcode:udint; end_var;
  // function is used to get record from Pipe. function will return 1 on success (got valid recorddata) on the other hand 0
  function global __cdecl cPipe_Get var_input pd:^void; p:^void; end_var var_output retcode:udint; end_var;
  // get number of used records in buffer
  function global __cdecl cPipe_GetUsed var_input p:^void; end_var var_output retcode:udint; end_var;
  // get number of unused records in buffer
  function global __cdecl cPipe_GetUnUsed var_input p:^void; end_var var_output retcode:udint; end_var;

//  type
//    #pragma pack(push, 1)
//     cPipe : struct
//       rd          : udint; // index readposition
//       wr          : udint; // index writeposition
//       rd_lock     : udint; // rd_lock
//       record_no   : udint; // number of record in buffer
//       record_size : udint; // bytesize of single record in buffer
//       record_user : udint; // bytesize of userdata in buffer
//       bitpattern  : udint; // bitpattern used for %
//       data        : ^void; // pointer to recordbuffer
//     end_struct;
//    #pragma pack(pop)      
//  end_type
//
//  // constructor used to construct cPipe
//  function global __cdecl cPipe_CTor var_input record_size:udint; record_no:udint; end_var var_output retcode:^cPipe; end_var;
//  // destructor of cPipe (use only when constructor is in use)
//  function global __cdecl cPipe_DTor var_input p:^cPipe; end_var var_output retcode:^cPipe; end_var;
//  // initialize cPipe (do not use when CTor is in use)
//  function global __cdecl cPipe_Init var_input p:^cPipe; record_size:udint; record_no:udint; end_var var_output retcode:udint; end_var;
//  // free cPipe (do not use when CTor is in use)
//  function global __cdecl cPipe_Free var_input p:^cPipe; end_var;
//  // function is used to add new record. function will return 1 on success, on the other hand 0
//  function global __cdecl cPipe_Add var_input p:^cPipe; pdata:^void; datasize:udint; end_var var_output retcode:udint; end_var;
//  // function is used to get record from Pipe. function will return 1 on success (got valid recorddata) on the other hand 0
//  function global __cdecl cPipe_Get var_input pd:^void; p:^cPipe; end_var var_output retcode:udint; end_var;
//  // get number of used records in buffer
//  function global __cdecl cPipe_GetUsed var_input p:^cPipe; end_var var_output retcode:udint; end_var;
//  // get number of unused records in buffer
//  function global __cdecl cPipe_GetUnUsed var_input p:^cPipe; end_var var_output retcode:udint; end_var;
  
 #endif // cCompile *******************************************************************************
  
#endif
