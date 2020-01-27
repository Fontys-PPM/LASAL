//<NewSigmatekCFileOptimize/>

#include "SigCLib.h" 

#define PIPE_MASK_CPXG   0x00121314
#define PIPE_MASK_LOCK   0x005A5ABC
#define PIPE_MASK_VALID  0x01234560

// ------------------------------------------------------------------------------------------------
// constructor of cPipe
// --> record_size ....... max.bytesize of single record
// --> recode_no ......... maximum number of records in buffer
// ------------------------------------------------------------------------------------------------
// <-- NULL ... error,  <> NULL pointer to cPipe
// ================================================================================================
cPipe *cPipe_CTor(unsigned long record_size, unsigned long record_no)
{
  cPipe *retcode = (cPipe*)sigclib_malloc(sizeof(cPipe));
  
  if(retcode != NULL)
  {
    cPipe_Init(retcode, record_size, record_no);
  }
  
  return retcode;
}

// ------------------------------------------------------------------------------------------------
// destructor to destroy whole cPipe. NOTE: just use when constructor is in use
// --> p ................. pointer to cPipe
// ------------------------------------------------------------------------------------------------
// <-- always NULL
// ================================================================================================
cPipe *cPipe_DTor(cPipe *p)
{
  if(p != NULL)
  {
    cPipe_Free(p);
    sigclib_free(p);
  }
  
  return NULL;
}

// ------------------------------------------------------------------------------------------------
// initialize cPipe
// --> p ................. pointer to cPipe
// --> record_size ....... max.bytesize of single record
// --> recode_no ......... maximum number of records in buffer
// ------------------------------------------------------------------------------------------------
// <-- 1 ... success, 0 ... error
// ================================================================================================
unsigned long cPipe_Init(cPipe *p, unsigned long record_size, unsigned long record_no)
{
  p->rd          = 0;    // aktuelle leseposition
  p->wr          = 0;    // aktuelle writeposition
  p->record_no   = 0;    // gesamtanzahl der reords im recordpuffer
  p->record_size = 0;    // grösse eines records in bytes
  p->record_user = 0;    // grösse der userdaten im record
  p->data        = NULL; // pointer auf datapuffer
  p->rd_lock     = 0;    // rd_lock
  p->bitpattern  = 0;
  
  if((record_size != 0) && (record_no > 0) && ((((unsigned long)p) & 3) == 0))
  {
    unsigned long fullsize = record_size + 8; // userdaten + 2*4byte
    fullsize = ((fullsize + 3) / 4) * 4; // recordsize muss 4 byte aligned sein
    
    // folgende grössen einhalten, ansonsten funktioniert 32bit-wrap von rd- und wr-index nicht
    if     (record_no > 0x8000) record_no = 0x10000;
    else if(record_no > 0x4000) record_no = 0x08000;
    else if(record_no > 0x2000) record_no = 0x04000;
    else if(record_no > 0x1000) record_no = 0x02000;
    else if(record_no > 0x0800) record_no = 0x01000;
    else if(record_no > 0x0400) record_no = 0x00800;
    else if(record_no > 0x0200) record_no = 0x00400;
    else if(record_no > 0x0100) record_no = 0x00200;
    else if(record_no > 0x0080) record_no = 0x00100;
    else if(record_no > 0x0040) record_no = 0x00080;
    else if(record_no > 0x0020) record_no = 0x00040;
    else if(record_no > 0x0010) record_no = 0x00020;
    else if(record_no > 0x0008) record_no = 0x00010;
    else if(record_no > 0x0004) record_no = 0x00008;
    else if(record_no > 0x0002) record_no = 0x00004;
    
    unsigned long bytesize = fullsize * record_no; // gesamtgrösse des puffers in bytes
    if(sigclib_memory((void**)&p->data, bytesize) != 0)
    {
      sigclib_memset(p->data, 0, bytesize);
      p->record_no   = record_no;
      p->bitpattern  = record_no - 1;
      p->record_size = fullsize;
      p->record_user = record_size;
      return 1;
    }
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// free whole cPipe
// --> p ................. pointer to cPipe
// ================================================================================================
void cPipe_Free(cPipe *p)
{
  if(p != NULL)
  {
    unsigned char *tmp = p->data;
    cPipe_Init(p, 0, 0);
    sigclib_memory((void**)&tmp, 0);
  }
}

// ------------------------------------------------------------------------------------------------
// put copy of recorddata into cPipe
// --> p ................. pointer to cPipe
// --> pdata ............. pointer to recorddata
// --> datasize .......... bytenumber of new recorddata
// ------------------------------------------------------------------------------------------------
// <-- 1 ... success, 0 ... error (cPipe is full, recorddata too big)
// ================================================================================================
unsigned long cPipe_Add(cPipe *p, void *pdata, unsigned long datasize)
{
  if(p != NULL) 
  {
    if(datasize <= p->record_user)
    {
      unsigned long nox = (p->record_no > 10)? 10 : p->record_no; // incl.bremse, 10 versuche sollten reichen
      unsigned long idx = sigclib_atomic_getU32(&p->wr);
      
      while(nox--)
      {
        unsigned long *pu32 = (unsigned long*)&p->data[(idx & p->bitpattern) * p->record_size];
        if(sigclib_atomic_cmpxchgU32(&pu32[0], 0, PIPE_MASK_CPXG) == 0) // ist record aktuell unbenützt --> diesen benützen
        {
          sigclib_memcpy(&pu32[2], pdata, datasize); // recorddaten kopieren
          sigclib_atomic_swpU32(&pu32[1], PIPE_MASK_VALID); // recorddaten auf gültig setzen
          sigclib_atomic_incU32(&p->wr); // inc wr-index
          return 1; // finito
        }
        idx++;
      }
    }
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------
// get record from cPipe
// --> pd ................ pointer to destination where data of record will be copied
// --> p ................. pointer to cPipe
// ------------------------------------------------------------------------------------------------
// <-- 1 ... recorddata sucessfull copied, 0 ... no recorddata available 
// ================================================================================================
unsigned long cPipe_Get(void *pdata, cPipe *p)
{
  unsigned long retcode = 0;
  
  if(p != NULL)
  {
    if(p->wr != p->rd) // sind records vorhanden
    {
      if(sigclib_atomic_cmpxchgU32(&p->rd_lock, 0, PIPE_MASK_LOCK) == 0) // wenn kein lock --> lock
      {
        if(p->wr != p->rd) // nochmalige prüfung während rd-lock
        {
          unsigned long idx = sigclib_atomic_getU32(&p->rd) & p->bitpattern;
          unsigned long *pu32 = (unsigned long*)&p->data[idx * p->record_size];
      
          if(pu32[1] == PIPE_MASK_VALID) // ist record aktuell gültig --> diesen auslesen
          {
            if(pdata != NULL)
            {
              sigclib_memcpy(pdata, &pu32[2], p->record_user); // recorddaten kopieren
            }
            sigclib_atomic_swpU32(&pu32[1], 0); // recorddaten auf ungültig setzen
            sigclib_atomic_swpU32(&pu32[0], 0); // record auf unbenützt setzen
            sigclib_atomic_incU32(&p->rd); // inc rd-index
            retcode = 1;
          }
        }
      
        sigclib_atomic_swpU32(&p->rd_lock, 0); // unlock
      }
    }
  }
  return retcode;
}

// ------------------------------------------------------------------------------------------------
// get number of used recordplaces in cPipe
// --> p ................. pointer at cPipe
// ------------------------------------------------------------------------------------------------
// <-- number of records in cPipe 
// ================================================================================================
unsigned long cPipe_GetUsed(cPipe *p)
{
  if(p != NULL)
  {
    return (sigclib_atomic_getU32(&p->wr) - sigclib_atomic_getU32(&p->rd));
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------
// get number of unused records in buffer
// --> p ................. pointer auf cPipe
// ------------------------------------------------------------------------------------------------
// <-- number of unused records in cPipe 
// ================================================================================================
unsigned long cPipe_GetUnUsed(cPipe *p)
{
  if(p != NULL)
  {
    return p->record_no - (sigclib_atomic_getU32(&p->wr) - sigclib_atomic_getU32(&p->rd));
  }
  return 0;
}


/*
// liefert immer die letzte gültige zelle
unsigned long cLiFo_Add(cPipe *p, void *pdata, unsigned long datasize)
{
  if(p != NULL) 
  {
    if(datasize <= p->record_user)
    {
      unsigned long nox = (p->record_no > 5)? 5 : p->record_no; // incl.bremse, 5 versuche sollten reichen
      unsigned long idx = sigclib_atomic_getU32(&p->wr);
      
      while(nox--)
      {
        unsigned long *pu32 = (unsigned long*)&p->data[(idx & p->bitpattern) * p->record_size];
        if(sigclib_atomic_cmpxchgU32(&pu32[0], 0, PIPE_MASK_LOCK) == 0) // wenn kein lock --> lock
        {
          sigclib_atomic_swpU32(&pu32[1], 0); // recorddaten auf ungültig setzen
          sigclib_memcpy(&pu32[2], pdata, datasize); // recorddaten kopieren
          sigclib_atomic_swpU32(&pu32[1], PIPE_MASK_VALID); // recorddaten auf gültig setzen
          sigclib_atomic_incU32(&p->wr); // inc wr-index
          sigclib_atomic_swpU32(&pu32[0], 0); // unlock
          return 1; // finito
        }
        idx++;
      }
    }
  }
  return 0;
}

unsigned long cLiFo_Get(void *pdata, cPipe *p)
{
  if(p != NULL)
  {
    unsigned long nox = (p->record_no > 5)? 5 : p->record_no; // incl.bremse, 5 versuche sollten reichen
    unsigned long idx = sigclib_atomic_getU32(&p->wr); 
    
    while(nox--)
    {
      idx--;
      unsigned long *pu32 = (unsigned long*)&p->data[(idx & p->bitpattern) * p->record_size];
  
      if(pu32[1] == PIPE_MASK_VALID) // ist record aktuell gültig --> diesen auslesen
      {
        if(sigclib_atomic_cmpxchgU32(&pu32[0], 0, PIPE_MASK_LOCK) == 0) // wenn kein lock --> lock
        {
          if(pdata != NULL)
          {
            sigclib_memcpy(pdata, &pu32[2], p->record_user); // recorddaten kopieren
          }
          sigclib_atomic_swpU32(&pu32[0], 0); // unlock
          return 1;
        }
      }
    }
  }
  
  return 0;
}
*/