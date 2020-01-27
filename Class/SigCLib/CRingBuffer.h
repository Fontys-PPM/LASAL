// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 10.11.2016                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// | NOTE:                                                                                        |
// | Wird Ringpuffer von nur einem Task befüllt und von gleicher taskpriorität wieder ausgelesen  |
// | so ist kein Mutex notwendig.                                                                 |
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#ifndef _cRingBufferH
 #define _cRingBufferH
  
 #include "CFiFo.h"
  
 #ifdef cCompile // *******************************************************************************
  
  #pragma pack(push, 1)
   typedef struct
   {
     cFiFo         data; // data
     unsigned long lost; // lost records
   }
   cRingBuffer;
  #pragma pack(pop)
  
  cExtern cRingBuffer  *cRingBuffer_CTor(unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic);
  cExtern cRingBuffer  *cRingBuffer_DTor(cRingBuffer *p);
  
  cExtern unsigned long cRingBuffer_Init(cRingBuffer *p, unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic);
  cExtern void          cRingBuffer_Free(cRingBuffer *p);
  cExtern unsigned long cRingBuffer_Add(cRingBuffer *p, void *pdata, unsigned long datasize);
  cExtern unsigned long cRingBuffer_Get(void *pd, cRingBuffer *p);
  cExtern void          cRingBuffer_Empty(cRingBuffer *p);
  cExtern unsigned long cRingBuffer_GetUsed(cRingBuffer *p);
  cExtern unsigned long cRingBuffer_GetUnUsed(cRingBuffer *p);
  cExtern unsigned long cRingBuffer_GetLost(cRingBuffer *p);
  
 #else // cCompile ********************************************************************************

//  type
//    #pragma pack(push, 1)
//     cRingBuffer : struct
//      data        : cFiFo;  // data
//      lost        : udint; // lost records
//     end_struct;
//    #pragma pack(pop)      
//  end_type
//  
//  function global __cdecl cRingBuffer_CTor var_input record_size:udint; record_no:udint; mutex_name:^char; pstatic:^void; end_var var_output retcode:^cRingBuffer; end_var;
//  function global __cdecl cRingBuffer_DTor var_input p:^cRingBuffer; end_var var_output retcode:^cRingBuffer; end_var;
//  
//  function global __cdecl cRingBuffer_Init var_input p:^cRingBuffer; record_size:udint; record_no:udint; mutex_name:^char; pstatic:^void; end_var var_output retcode:udint; end_var;
//  function global __cdecl cRingBuffer_Free var_input p:^cRingBuffer; end_var;
//  function global __cdecl cRingBuffer_Add var_input p:^cRingBuffer; pdata:^void; datasize:udint; end_var var_output retcode:udint; end_var;
//  function global __cdecl cRingBuffer_Get var_input pd:^void; p:^cRingBuffer; end_var var_output retcode:udint; end_var;
//  function global __cdecl cRingBuffer_Empty var_input p:^cRingBuffer; end_var;
//  function global __cdecl cRingBuffer_GetUsed var_input p:^cRingBuffer; end_var var_output retcode:udint; end_var;
//  function global __cdecl cRingBuffer_GetUnused var_input p:^cRingBuffer; end_var var_output retcode:udint; end_var;
//  function global __cdecl cRingBuffer_GetLost var_input p:^cRingBuffer; end_var var_output retcode:udint; end_var;


  function global __cdecl cRingBuffer_CTor var_input record_size:udint; record_no:udint; mutex_name:^char; pstatic:^void; end_var var_output retcode:^void; end_var;
  function global __cdecl cRingBuffer_DTor var_input p:^void; end_var var_output retcode:^void; end_var;
  
  function global __cdecl cRingBuffer_Add var_input p:^void; pdata:^void; datasize:udint; end_var var_output retcode:udint; end_var;
  function global __cdecl cRingBuffer_Get var_input pd:^void; p:^void; end_var var_output retcode:udint; end_var;
  function global __cdecl cRingBuffer_Empty var_input p:^void; end_var;
  function global __cdecl cRingBuffer_GetUsed var_input p:^void; end_var var_output retcode:udint; end_var;
  function global __cdecl cRingBuffer_GetUnused var_input p:^void; end_var var_output retcode:udint; end_var;
  function global __cdecl cRingBuffer_GetLost var_input p:^void; end_var var_output retcode:udint; end_var;

  
 #endif // cCompile *******************************************************************************
  
#endif
