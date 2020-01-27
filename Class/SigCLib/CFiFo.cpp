//<NewSigmatekCFileOptimize/>

#include "SigCLib.h" 

#define RB_ALLOCATED_DATABUFFER  0x00000001
#define RB_MUTEX_ENABLED         0x00000002

// ------------------------------------------------------------------------------------------------
// konstructor für gesamte struktur
// --> record_size ....... grösse eines records in byte
// --> recode_no ......... anzahl der records im datapuffer
// --> mutex_name ........ falls mutexschutz gewünscht ist wird ein gültiger MutexName angegeben, ansonsten NULL
// --> pstatic ........... pointer auf statischen datenpuffer falls notwendig, ansonsten NULL
// ------------------------------------------------------------------------------------------------
// <-- NULL ... fehler,  <> NULL pointer auf erfolgreich angelegtes cFiFo
// ================================================================================================
cFiFo *cFiFo_CTor(unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic)
{
  cFiFo *retcode = (cFiFo*)sigclib_malloc(sizeof(cFiFo));
  
  if(retcode != NULL)
  {
    cFiFo_Init(retcode, record_size, record_no, mutex_name, pstatic);
  }
  
  return retcode;
}

// ------------------------------------------------------------------------------------------------
// destructor für gesamte struktur, nur aufrufen wenn auch Konstruktor verwendet wurde
// --> p ................. pointer auf cFiFo
// ------------------------------------------------------------------------------------------------
// <-- immer NULL
// ================================================================================================
cFiFo *cFiFo_DTor(cFiFo *p)
{
  if(p != NULL)
  {
    cFiFo_Free(p);
    sigclib_free(p);
  }
  
  return NULL;
}

// ------------------------------------------------------------------------------------------------
// initialisieren der gesamten struktur
// --> p ................. pointer auf cFiFo
// --> record_size ....... grösse eines records in byte
// --> recode_no ......... anzahl der records im datapuffer
// --> mutex_name ........ falls mutexschutz gewünscht ist wird ein gültiger MutexName angegeben, ansonsten NULL
// --> pstatic ........... pointer auf statischen datenpuffer falls notwendig, ansonsten NULL
// ------------------------------------------------------------------------------------------------
// <-- 1 ... erfolg, 0 ... fehler
// ================================================================================================
unsigned long cFiFo_Init(cFiFo *p, unsigned long record_size, unsigned long record_no, const char* mutex_name, void *pstatic)
{
  if(p != NULL)
  {
    p->rd          = 0;    // aktuelle leseposition
    p->wr          = 0;    // aktuelle writeposition
    p->count       = 0;    // anzahl gültiger records im puffer
    p->record_no   = 0;    // gesamtanzahl der reords im recordpuffer
    p->record_size = 0;    // grösse eines records in bytes
    p->data        = NULL; // pointer auf datapuffer
    p->statebits   = 0;
    p->mutex       = 0;
  
    if(mutex_name != NULL)
    {
      p->statebits |= RB_MUTEX_ENABLED;
      p->mutex      = sigclib_mutex_create(mutex_name);
    }
  
    if((pstatic == NULL) && (record_size != 0) && (record_no > 1))
    {
      p->statebits |= RB_ALLOCATED_DATABUFFER;
      if(sigclib_memory((void**)&pstatic, record_size*record_no) == 0)
      {
        pstatic = NULL;
      }
    }
  
    if(pstatic != NULL)
    {
      p->data        = (unsigned char*)pstatic;
      p->record_no   = record_no;
      p->record_size = record_size;
      return 1;
    }
  }
  return 0;
}

static void cFiFo_SectionStart(cFiFo *p)
{
  if(p->statebits & RB_MUTEX_ENABLED)
  {
    sigclib_mutex_section_start(p->mutex);
  }
}

static void cFiFo_SectionStop(cFiFo *p)
{
  if(p->statebits & RB_MUTEX_ENABLED)
  {
    sigclib_mutex_section_stop(p->mutex);
  }
}

// ------------------------------------------------------------------------------------------------
// freigeben der gesamten struktur
// --> p ................. pointer auf cFiFo
// ================================================================================================
void cFiFo_Free(cFiFo *p)
{
  if(p != NULL)
  {
    cFiFo_SectionStart(p);
  
    p->count = 0; // somit alle einträge gelöscht
  
    if(p->statebits & RB_ALLOCATED_DATABUFFER)
    {
      sigclib_memory((void**)&p->data, 0);
    }
    cFiFo_SectionStop(p);
  
    if(p->mutex != 0)
    {
      sigclib_mutex_destroy(p->mutex);
    }
  
    cFiFo_Init(p, 0, 0, NULL, NULL);
  }
}

// ------------------------------------------------------------------------------------------------
// neuen record (kopie) in cFiFo eintragen
// --> p ................. pointer auf cFiFo
// --> pdata ............. pointer auf record welcher eingetragen werden soll
// --> datasize .......... byteanzahl des einzutragenden records
// ------------------------------------------------------------------------------------------------
// <-- 1 ... erfolg, 0 ... fehler 
// ================================================================================================
unsigned long cFiFo_Add(cFiFo *p, void *pdata, unsigned long datasize)
{
  unsigned long retcode = 0;

  if(p != NULL)
  {
    if(datasize <= p->record_size)
    {
      if(p->count < p->record_no) // wenn noch platz im puffer ist
      {
        cFiFo_SectionStart(p);
        if(p->count < p->record_no) // nochmalige prüfung während mutexschutz
        {
          sigclib_memcpy(&p->data[p->wr * p->record_size], pdata, datasize); // record kopieren
          p->wr = (p->wr + 1) % p->record_no; // writeposition erhöhen
          sigclib_atomic_incU32(&p->count); // anzahl der records erhöhen
          retcode = 1;
        }
        cFiFo_SectionStop(p);
      }
    }
  }
  
  return retcode;
}

// ------------------------------------------------------------------------------------------------
// record aus cFiFo holen
// --> pd ................ pointer auf destination wo record abgelegt werden soll
// --> p ................. pointer auf cFiFo
// ------------------------------------------------------------------------------------------------
// <-- 1 ... erfolg, 0 ... fehler 
// ================================================================================================
unsigned long cFiFo_Get(void *pd, cFiFo *p)
{
  unsigned long retcode = 0;
  
  if(p != NULL)
  {
    if(p->count != 0) // ist gültiger record vorhanden
    {
      cFiFo_SectionStart(p);
      if(p->count != 0) // nochmals während mutexschutz kontrollieren
      {
        if(pd != NULL)
        {
          sigclib_memcpy(pd, &p->data[p->rd * p->record_size], p->record_size);
        }
        p->rd = (p->rd + 1) % p->record_no; // readposition erhöhen
        sigclib_atomic_decU32(&p->count); // anzahl der records verringern
        retcode = 1;
      }
      cFiFo_SectionStop(p);
    }
  }
  
  return retcode;
}

// ------------------------------------------------------------------------------------------------
// anzahl der aktuell benützten recordplätze im cFiFo ermitteln
// --> p ................. pointer auf cFiFo
// ================================================================================================
unsigned long cFiFo_GetUsed(cFiFo *p)
{
  if(p != NULL)
  {
    return p->count;
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// anzahl der aktuell freien recordplätze im cFiFo ermitteln
// --> p ................. pointer auf cFiFo
// ================================================================================================
unsigned long cFiFo_GetUnUsed(cFiFo *p)
{
  if(p != NULL)
  {
    return p->record_no - p->count;
  }
  
  return 0;
}

// ------------------------------------------------------------------------------------------------
// cFiFo entleeren
// --> p ................. pointer auf cFiFo
// ================================================================================================
void cFiFo_Empty(cFiFo *p)
{
  if(p != NULL)
  {
    cFiFo_SectionStart(p);
    p->count = 0;
    p->rd    = 0;
    p->wr    = 0;
    cFiFo_SectionStop(p);
  }
}

