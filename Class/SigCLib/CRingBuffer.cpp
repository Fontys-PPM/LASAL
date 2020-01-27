//<NewSigmatekCFileOptimize/>

#include "SigCLib.h" 

// ------------------------------------------------------------------------------------------------
// konstructor für gesamte struktur
// --> record_size ....... grösse eines records in byte
// --> recode_no ......... anzahl der records im datapuffer
// --> mutex_name ........ falls mutexschutz gewünscht ist wird ein gültiger MutexName angegeben, ansonsten NULL
// --> pstatic ........... pointer auf statischen datenpuffer falls notwendig, ansonsten NULL
// ------------------------------------------------------------------------------------------------
// <-- NULL ... fehler,  <> NULL pointer auf erfolgreich angelegten cRingBuffer
// ================================================================================================
cRingBuffer *cRingBuffer_CTor(unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic)
{
  cRingBuffer *retcode = (cRingBuffer*)sigclib_malloc(sizeof(cRingBuffer));
  
  if(retcode != NULL)
  {
    cRingBuffer_Init(retcode, record_size, record_no, mutex_name, pstatic);
  }
  
  return retcode;
}

// ------------------------------------------------------------------------------------------------
// destructor für gesamte struktur, nur aufrufen wenn auch Konstruktor verwendet wurde
// --> p ................. pointer auf cRingBuffer
// ------------------------------------------------------------------------------------------------
// <-- immer NULL
// ================================================================================================
cRingBuffer *cRingBuffer_DTor(cRingBuffer *p)
{
  if(p != NULL)
  {
    cRingBuffer_Free(p);
    sigclib_free(p);
  }
  
  return NULL;
}

// ------------------------------------------------------------------------------------------------
// initialisieren der gesamten struktur
// --> p ................. pointer auf cRingBuffer
// --> record_size ....... grösse eines records in byte
// --> recode_no ......... anzahl der records im datapuffer
// --> mutex_name ........ falls mutexschutz gewünscht ist wird ein gültiger MutexName angegeben, ansonsten NULL
// --> pstatic ........... pointer auf statischen datenpuffer falls notwendig, ansonsten NULL
// ------------------------------------------------------------------------------------------------
// <-- 1 ... erfolg, 0 ... fehler
// ================================================================================================
unsigned long cRingBuffer_Init(cRingBuffer *p, unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic)
{
  if(p != NULL)
  {
    p->lost = 0;
    return cFiFo_Init(&p->data, record_size, record_no, mutex_name, pstatic);
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// freigeben der gesamten struktur
// --> p ................. pointer auf cRingBuffer
// ================================================================================================
void cRingBuffer_Free(cRingBuffer *p)
{
  if(p != NULL)
  {
    p->lost = 0;
    cFiFo_Free(&p->data);
  }
}

// ------------------------------------------------------------------------------------------------
// neuen record (kopie) in cRingBuffer eintragen
// --> p ................. pointer auf cRingBuffer
// --> pdata ............. pointer auf record welcher eingetragen werden soll
// --> datasize .......... byteanzahl des einzutragenden records
// ------------------------------------------------------------------------------------------------
// <-- 1 ... erfolg, 0 ... fehler 
// ================================================================================================
unsigned long cRingBuffer_Add(cRingBuffer *p, void *pdata, unsigned long datasize)
{
  if(p != NULL)
  {
    if(cFiFo_Add(&p->data, pdata, datasize) != 0)
    {
      return 1;
    }
  
    if(datasize <= p->data.record_size)
    {
      cFiFo_Get(NULL, &p->data); // dump first record
      sigclib_atomic_incU32(&p->lost); // lost anzahl erhöhen
      return cRingBuffer_Add(p, pdata, datasize); // add new record
    }
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// record aus cRingBuffer holen
// --> pd ................ pointer auf destination wo record abgelegt werden soll
// --> p ................. pointer auf cRingBuffer
// ------------------------------------------------------------------------------------------------
// <-- 1 ... erfolg, 0 ... fehler 
// ================================================================================================
unsigned long cRingBuffer_Get(void *pd, cRingBuffer *p)
{
  if(p != NULL)
  {
    return cFiFo_Get(pd, &p->data);
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------
// anzahl der aktuell benützten recordplätze im cRingBuffer ermitteln
// --> p ................. pointer auf cRingBuffer
// ================================================================================================
unsigned long cRingBuffer_GetUsed(cRingBuffer *p)
{
  if(p != NULL)
  {
    return cFiFo_GetUsed(&p->data);
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------
// anzahl der bereits verlorenen (überschriebenen) records im cRingBuffer ermitteln
// --> p ................. pointer auf cRingBuffer
// ================================================================================================
unsigned long cRingBuffer_GetLost(cRingBuffer *p)
{
  if(p != NULL)
  {
    return p->lost;
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// anzahl der aktuell freien recordplätze im cRingBuffer ermitteln
// --> p ................. pointer auf cRingBuffer
// ================================================================================================
unsigned long cRingBuffer_GetUnUsed(cRingBuffer *p)
{
  if(p != NULL)
  {
    return cFiFo_GetUnUsed(&p->data);
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// cRingBuffer entleeren
// --> p ................. pointer auf cRingBuffer
// ================================================================================================
void cRingBuffer_Empty(cRingBuffer *p)
{
  if(p != NULL)
  {
    cFiFo_Empty(&p->data);
    p->lost = 0;
  }
}

