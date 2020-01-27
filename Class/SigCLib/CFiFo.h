// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 10.11.2016                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// | NOTE:                                                                                        |
// | Wird Fifo von nur einem Task befüllt und von selbigen oder anderem ausgelesen                |
// | ist kein Mutex zwingend notwendig.                                                           |
// | Erst wenn mehrere unterschiedliche Tasks befüllen und/oder mehrere Tasks auslesen            |
// | ist ein Mutex zwingend notwendig.                                                            |
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#ifndef _cFiFoH
 #define _cFiFoH
  
 #include "DefineCompiler.h" 
  
 #ifdef cCompile // *******************************************************************************

  #pragma pack(push, 1)
   typedef struct
   {
     unsigned long rd;          // index readposition
     unsigned long wr;          // index writeposition
     unsigned long count;       // number of valid records in buffer
     unsigned long record_no;   // number of record in buffer
     unsigned long record_size; // bytesize of single record in buffer
     unsigned char *data;       // pointer to recordbuffer
     unsigned long statebits;   // statusbits
     unsigned long mutex;       // mutexhandle
   }
   cFiFo;
  #pragma pack(pop)
  
  cExtern cFiFo        *cFiFo_CTor(unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic);
  cExtern cFiFo        *cFiFo_DTor(cFiFo *p);
  
  cExtern unsigned long cFiFo_Init(cFiFo *p, unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic);
  cExtern void          cFiFo_Free(cFiFo *p);
  cExtern unsigned long cFiFo_Add(cFiFo *p, void *pdata, unsigned long datasize);
  cExtern unsigned long cFiFo_Get(void *pd, cFiFo *p);
  cExtern void          cFiFo_Empty(cFiFo *p);
  cExtern unsigned long cFiFo_GetUsed(cFiFo *p);
  cExtern unsigned long cFiFo_GetUnUsed(cFiFo *p);
  
 #else // cCompile ********************************************************************************
  
//  type
//    #pragma pack(push, 1)
//     cFiFo : struct
//      rd          : udint; // index readposition
//      wr          : udint; // index writeposition
//      count       : udint; // number of valid records in buffer
//      record_no   : udint; // number of record in buffer
//      record_size : udint; // bytesize of single record in buffer
//      data        : ^void; // pointer to recordbuffer
//      statebits   : udint; // statusbits
//      mutex       : udint; // mutexhandle
//     end_struct;
//    #pragma pack(pop)      
//  end_type
//
//  function global __cdecl cFiFo_CTor var_input record_size:udint; record_no:udint; mutex_name:^char; pstatic:^void; end_var var_output retcode:^cFiFo; end_var;
//  function global __cdecl cFiFo_DTor var_input p:^cFiFo; end_var var_output retcode:^cFiFo; end_var;
//
//  function global __cdecl cFiFo_Init var_input p:^cFiFo; record_size:udint; record_no:udint; mutex_name:^char; pstatic:^void; end_var var_output retcode:udint; end_var;
//  function global __cdecl cFiFo_Free var_input p:^cFiFo; end_var;
//  function global __cdecl cFiFo_Add var_input p:^cFiFo; pdata:^void; datasize:udint; end_var var_output retcode:udint; end_var;
//  function global __cdecl cFiFo_Get var_input pd:^void; p:^cFiFo; end_var var_output retcode:udint; end_var;
//  function global __cdecl cFiFo_Empty var_input p:^cFiFo; end_var;
//  function global __cdecl cFiFo_GetUsed var_input p:^cFiFo; end_var var_output retcode:udint; end_var;
//  function global __cdecl cFiFo_GetUnused var_input p:^cFiFo; end_var var_output retcode:udint; end_var;

  function global __cdecl cFiFo_CTor var_input record_size:udint; record_no:udint; mutex_name:^char; pstatic:^void; end_var var_output retcode:^void; end_var;
  function global __cdecl cFiFo_DTor var_input p:^void; end_var var_output retcode:^void; end_var;

  function global __cdecl cFiFo_Add var_input p:^void; pdata:^void; datasize:udint; end_var var_output retcode:udint; end_var;
  function global __cdecl cFiFo_Get var_input pd:^void; p:^void; end_var var_output retcode:udint; end_var;
  function global __cdecl cFiFo_Empty var_input p:^void; end_var;
  function global __cdecl cFiFo_GetUsed var_input p:^void; end_var var_output retcode:udint; end_var;
  function global __cdecl cFiFo_GetUnused var_input p:^void; end_var var_output retcode:udint; end_var;

  
 #endif // cCompile *******************************************************************************
  
#endif
