//<NewSigmatekCFileOptimize/>
// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 17.09.2018                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#include "SigCLib.h"
#include "CHeap.h"

typedef struct
{
  unsigned char  *ptr; // pointer auf datenblock
  unsigned long  size; // bytesize vom datenblock
  unsigned short used; // momentan nur 0 oder 1
  unsigned short uid;  // userid
}
_HeapEntry;

typedef struct
{
  void           *crazyval; // crazyval
  unsigned char  *data;     // pointer auf daten
  unsigned long  size;      // anzahl der verfügbaren bytes in daten
  unsigned long  mutex;     // mutex
  unsigned long  size_used; // anzahl der belegten bytes
  unsigned long  no;        // anzahl der blöcke
  unsigned long  no_free;   // anzahl der freien blöcke
  unsigned long  databytes; // anzahl aller bytes der benützten blöcke
}
_Heap;

#define HEAP_CHECK
//#define HEAP_DEFAULT      // wenn heapbubble mit size 0 initialisiert ist, wird standardheap verwendet 

static unsigned long HeapGetFreeSize(_Heap *php)
{
  unsigned long fatsize = php->no * sizeof(_HeapEntry);
  return php->size - fatsize - php->size_used;
}

static _HeapEntry *HeapGetFatEntry(_Heap *php, unsigned long index)
{
  unsigned long offset = php->size + ((index - php->no) * sizeof(_HeapEntry));
  return (_HeapEntry*)(php->data + offset);
}

#ifdef HEAP_CHECK
 static unsigned long HeapCheckVal(_HeapEntry *pf)
 {
   unsigned long value = (unsigned long)pf->ptr; 
   if(pf->used == 1)
   {
     value = value ^ 0xFFFFFFFF;
   }
   return value;
 }

 static void HeapBlockTag(_HeapEntry *pf)
 {
   unsigned long value = HeapCheckVal(pf);
   unsigned long nox = pf->size / 4;
   unsigned long *ph = (unsigned long*)pf->ptr;
   ph[nox-1] = value;
 }
#endif

static unsigned long HeapCheckSub(_Heap *php, _HeapEntry *pf)
{
  if(pf->size & 3)
  {
    return 0; // error
  }
   
  unsigned char *pv = (unsigned char*)php->data;
  unsigned char *pt = (unsigned char*)pf->ptr;
  if(pt < pv)
  {
    return 0; // error
  }
   
  pv += php->size_used;
  if(pt > pv)
  {
    return 0; // error
  }

 #ifdef HEAP_CHECK
  unsigned long *ph = (unsigned long*)pf->ptr;
  unsigned long nox = pf->size / 4;
   
  if(ph[nox-1] != HeapCheckVal(pf))
  {
    return 0;
  }
 #endif
  
  return 1;
}

static unsigned long HeapGetFatIndex(_Heap *php, void *ptr)
{
  unsigned long start = 0;
  unsigned long num = php->no;
  _HeapEntry *pfat = HeapGetFatEntry(php, 0);
  
  ECONOhp_RECURSION :

  if(num > 0)
  {
    unsigned long index = start + (num / 2);
    void *ph = (void*)pfat[index].ptr;
    if(ph < ptr)
    {
      num = num / 2;
      goto ECONOhp_RECURSION;
    }
    else if(ph > ptr)
    {
      start = index + 1;
      num   = ((num - 1) / 2);
      goto ECONOhp_RECURSION;
    }
  
    return index;
  }
  
  return 0xFFFFFFFF;
}

static unsigned long HeapAddFatEntry(_Heap *php, unsigned long size)
{
  // neuen freien fatblock hinzufügen
  if((size + (sizeof(_HeapEntry)) <= HeapGetFreeSize(php)))
  {
    _HeapEntry *pfat = HeapGetFatEntry(php, 0);
    pfat --;
    
    pfat->size = size;
    pfat->ptr  = php->data + php->size_used;
    pfat->used = 0;
    pfat->uid  = 0xFFFF;
    
    php->no ++;
    php->no_free ++;
    php->size_used += size;
    
   #ifdef HEAP_CHECK 
    HeapBlockTag(pfat);
   #endif 
    
    return 0;
  }
  return 0xFFFFFFFF;
}

static void HeapFatInsert(_Heap *php, unsigned long idx)
{
  _HeapEntry *ps = HeapGetFatEntry(php, 0);
  _HeapEntry *pd = ps - 1;
  sigclib_memmove(pd, ps, (idx + 1) * sizeof(_HeapEntry));
}

static void HeapFatDelete(_Heap *php, unsigned long idx)
{
  _HeapEntry *ps = HeapGetFatEntry(php, 0);
  _HeapEntry *pd = ps + 1;
  sigclib_memmove(pd, ps, idx * sizeof(_HeapEntry));
}

static void HeapFatSplit(_Heap *php, unsigned long idx, unsigned long size)
{
  _HeapEntry *pfat = HeapGetFatEntry(php, idx);

  if(pfat->size >= size) // kontrolle ob block überhaupt splittbar ist
  {
    unsigned long rest = pfat->size - size;
    
    if(rest > 0)
    {
      if(idx == 0)
      {
        pfat->size = size;
        php->size_used -= rest;
      }
      else
      {
        _HeapEntry *ph = pfat - 1;
        if(ph->used == 0) // ist nächster block frei
        {
          //freie blöcke zusammenführen
          ph->size  += rest;
          ph->ptr   -= rest;
          pfat->size = size;
        
         #ifdef HEAP_CHECK
          HeapBlockTag(ph);
         #endif
        }
        else if(rest > sizeof(_HeapEntry)) // ansonsten macht split keinen sinn
        {
          if(HeapGetFreeSize(php) > sizeof(_HeapEntry)) // ist genug freier speicher vorhanden
          {
            HeapFatInsert(php, idx);
            php->no ++;
  
            _HeapEntry *pfnew = pfat - 1;
            pfnew->size = rest;
            pfnew->ptr  = pfat->ptr + size;
            pfnew->used = 0; // neuer block ist unbenützt
            pfnew->uid  = pfat->uid; // id vom alten block
            php->no_free ++; // anzahl freie blöcke erhöhen

            pfat->size  = size;
          
           #ifdef HEAP_CHECK
            HeapBlockTag(pfnew);
           #endif
          }
        }
      }
    }
    
    if(pfat->used == 0)
    {
      pfat->used = 1;
      php->no_free --; // anzahl freier blöcke verringern
    }

   #ifdef HEAP_CHECK
    HeapBlockTag(pfat);
   #endif
  }
}

static unsigned long HeapGetFreeFatEntry(_Heap *php, unsigned long size)
{
  // index auf freien fatblock ermitteln. 
  // ist kein freier block vorhanden wird einer addiert
  unsigned long retcode = 0xFFFFFFFF;

  if(php->no_free > 0)
  {
    unsigned long idx  = 0;
    unsigned long free = 0xFFFFFFFF;
    unsigned long nox  = php->no_free;
    _HeapEntry *pfat = HeapGetFatEntry(php, 0);
    
    while(nox)
    {
      if(pfat->used == 0)
      {
        if(size <= pfat->size)
        {
          unsigned long tmp = pfat->size - size;
          if(tmp < free)
          {
            free    = tmp;
            retcode = idx;
          }
        }
        nox --;
      }
      
      idx ++;
      pfat ++;
    }
  }
  
  if(retcode >= php->no)
  {
    retcode = HeapAddFatEntry(php, size);
  }
  
  return retcode;
}

static unsigned long HeapFreeIndex(_Heap *php, unsigned long idx)
{
  unsigned long retcode = 0;
  _HeapEntry *pfat, *pfh;

  if(idx < php->no)
  {
    pfat = HeapGetFatEntry(php, idx);
    if(pfat->used == 1) // nur wenn block noch nicht frei
    {
      retcode = 1;
      php->databytes -= pfat->size; // anzahl benützter databytes korrigieren
      
      if(idx == 0)
      {
        php->no --;
        php->size_used -= pfat->size;
      
        if(php->no > 0) // nachfolgenden block überprüfen ob dieser frei ist, wenn ja diesen ebenfalls killen
        {
          pfat = HeapGetFatEntry(php, 0);
          if(pfat->used == 0)
          {
            php->size_used -= pfat->size;
            php->no --;
            php->no_free --;
          }
        }
      }
      else
      {
        php->no_free ++;
        pfat->used = 0;

       #ifdef HEAP_CHECK
        HeapBlockTag(pfat);
       #endif
    
        pfh = HeapGetFatEntry(php, idx-1); 
        if(pfh->used == 0) // ist nachfolgender block frei
        {
          // idx und idx-1 zusammenfassen
          pfat->size += pfh->size;
          HeapFatDelete(php, idx-1);
          php->no --;
          php->no_free --;
          idx --;
          
         #ifdef HEAP_CHECK
          HeapBlockTag(pfat);
         #endif
        }
      
        if((idx + 1) < (php->no))
        {
          pfh = HeapGetFatEntry(php, idx+1);
          if(pfh->used == 0)
          {
            // zusammenfassen (idx und idx+1)
            pfh->size += pfat->size;
              
            HeapFatDelete(php, idx);
            php->no --;
            php->no_free --;
            
           #ifdef HEAP_CHECK
            HeapBlockTag(pfh);
           #endif
          }
        }
      }
    }
  }
 
  return retcode;
}

static _HeapEntry *HeapAllocIntern(_Heap *php, unsigned long size, unsigned short id)
{
  _HeapEntry *pfat = NULL;

  if(size > 0)
  {
    unsigned long idx = HeapGetFreeFatEntry(php, size);
    if(idx < php->no)
    {
      pfat = HeapGetFatEntry(php, idx);
      if(pfat != NULL)
      {
        HeapFatSplit(php, idx, size);
        pfat->uid = id;
        php->databytes += pfat->size;
      }
    }
  }

  return pfat;
}

static void *HeapFreeIntern(_Heap *php, void *pt)
{
  void *retcode = pt;
  
  if(HeapFreeIndex(php, HeapGetFatIndex(php, pt)) != 0)
  {
    retcode = NULL;
  }
  
  return retcode;
}

#define HeapLock(__php)   sigclib_mutex_section_start((__php)->mutex)
#define HeapUnLock(__php) sigclib_mutex_section_stop((__php)->mutex)

static void HeapInitIntern(_Heap *php, void *ptr, unsigned long size)
{
  char name[32];
  unsigned char *pt = (unsigned char*)ptr;
  while(((unsigned long)pt) & 3)
  {
    pt ++;
    size--;
  }

  sigclib_sprintf(name, "Heap%08X", (unsigned long)ptr);
  php->mutex = sigclib_mutex_create(name);
  php->data      = pt;
  php->no        = 0;
  php->no_free   = 0;
  php->size      = size & ~3;
  php->size_used = 0;
  php->crazyval  = (void*)php;
  php->databytes = 0; // anzahl benützter databytes initialisieren
}

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************

cExtern unsigned long sigclib_heap_check(void *php0, void *pt)
{
  // funktion dient zum check des gesamten heap (pt=NULL) oder eines einzelnen heap-block (pt=userpointer)
  // wird 0 retouniert so ist ein fehler aufgetreten
  unsigned long retcode = 0;

  if(php0 != NULL)
  {
    _Heap *php = (_Heap*)php0;

    HeapLock(php); // ********************************************************** [CRITICAL SECTION]
    
    if(php->crazyval == php0)
    {
      if(pt == NULL)
      {
        retcode = 1;
        // gesamten heap (alle blöcke) testen
        unsigned long nox = php->no;
        _HeapEntry *pfat = HeapGetFatEntry(php, 0);
        unsigned long size = 0;
        
        while(nox--)
        {
          _HeapEntry *pfh = &pfat[nox];
          size += pfh->size;
          if(HeapCheckSub(php, pfh) == 0)
          {
            retcode = 0; // error
            nox = 0;
          }
        }
        
        if(size != php->size_used)
        {
          retcode = 0; // error
        }
        
      }
      else
      {
        // einzelnen block testen
        unsigned long idx = HeapGetFatIndex(php, pt);
        if(idx < php->no)
        {
          _HeapEntry *pfat = HeapGetFatEntry(php, idx);
          retcode = HeapCheckSub(php, pfat);
        }
      }
    }
    HeapUnLock(php); // ******************************************************** [CRITICAL SECTION]
  }
 #ifdef HEAP_DEFAULT
  else
  {
    retcode = 1;
  }
 #endif

  return retcode;
}

cExtern void *sigclib_heap_CTor(unsigned long size)
{
  // constructor
  if(size != 0)
  {
    size += sizeof(_HeapEntry); // somit kann ein maximaler block von [size] allokiert werden
   #ifdef HEAP_CHECK
    size += 4;
   #endif
    
   #ifdef HEAPBUBBLE_INUSE
    unsigned char *pt = (unsigned char*)OS_SSR_Malloc(size + sizeof(_Heap));
   #else    
    unsigned char *pt = (unsigned char*)sigclib_malloc(size + sizeof(_Heap));
   #endif
   
    if(pt != NULL)
    {
      HeapInitIntern((_Heap*)pt, (void*)(pt+sizeof(_Heap)), size);
      return (void*)pt;
    }
  }
  
  return NULL;
}

cExtern void *sigclib_heap_DTor(void *php0)
{
  // destructor
  if(php0 != NULL)
  {
    _Heap *php = (_Heap*)php0;
    HeapLock(php); // ********************************************************** [CRITICAL SECTION]
    php->crazyval = NULL;
    HeapUnLock(php); // ******************************************************** [CRITICAL SECTION]
    
    sigclib_mutex_destroy(php->mutex);

   #ifdef HEAPBUBBLE_INUSE
    OS_SSR_Free(php0);
   #else    
    sigclib_free(php0);
   #endif
  }
  
  return NULL;
}

cExtern void sigclib_heap_empty(void *php0)
{
  // alle datenblöcke im heap löschen
  if(php0 != NULL)
  {
    _Heap *php = (_Heap*)php0;
    HeapLock(php); // ********************************************************** [CRITICAL SECTION]
    
    if(php->crazyval == php0)
    {
      php->no        = 0;
      php->no_free   = 0;
      php->size_used = 0;
      php->databytes = 0;
    }
    
    HeapUnLock(php); // ******************************************************** [CRITICAL SECTION]
  }
}

cExtern void *sigclib_heap_malloc(void *php0, unsigned long size, unsigned long id)
{
  // datenblock allokieren
  void *retcode = NULL;
  
  if(size > 0)
  {
    if(php0 != NULL)
    {
      while(size & 3)
      {
        size ++;
      }

     #ifdef HEAP_CHECK
      size += 4;
     #endif
  
      _Heap *php = (_Heap*)php0;
  
      HeapLock(php); // ******************************************************** [CRITICAL SECTION]
    
      if(php->crazyval == php0)
      {
        _HeapEntry *pfat = HeapAllocIntern(php, size, (unsigned short)id);
        if(pfat != NULL)
        {
          retcode = (void*)pfat->ptr;
        }
      }
    
      HeapUnLock(php); // ****************************************************** [CRITICAL SECTION]
    }
   #ifdef HEAP_DEFAULT
    else
    {
      retcode = sigclib_malloc(size);
    }
   #endif
  }
  
  return retcode;
}

cExtern void *sigclib_heap_free(void *php0, void *pt)
{
  // allokierten datenblock freigeben
  void *retcode = pt;

  if(pt != NULL)
  {
    if(php0 != NULL)
    {
      _Heap *php = (_Heap*)php0;
  
      HeapLock(php); // ******************************************************** [CRITICAL SECTION]
    
      if(php->crazyval == php0)
      {
        retcode = HeapFreeIntern(php, pt);
      }
    
      HeapUnLock(php); // ****************************************************** [CRITICAL SECTION]
    }
   #ifdef HEAP_DEFAULT
    else
    {
      sigclib_free(pt);
      retcode = NULL;
    }
   #endif 
  }
  
  return retcode;
}

cExtern void *sigclib_heap_realloc(void *php0, void *pt, unsigned long size)
{
  // grösse eines bereits allokierten datenblocks ändern
  void *retcode = NULL;
  unsigned long oldsize = 0;
  
  if(php0 != NULL)
  {
    if(pt != NULL)
    {
      if(size == 0)
      {
        return sigclib_heap_free(php0, pt);
      }
  
      while(size & 3)
      {
        size++;
      }

      _Heap *php = (_Heap*)php0;

     #ifdef HEAP_CHECK
      size += 4;
     #endif

      HeapLock(php); // ******************************************************** [CRITICAL SECTION]
   
      if(php->crazyval == php0)
      {
        unsigned long idx = HeapGetFatIndex(php, pt);
        if(idx < php->no)
        {
          _HeapEntry *pfat = HeapGetFatEntry(php, idx);
      
          if(pfat->used == 1) // nur wenn block auch wirklich benützt
          {
            if(size == pfat->size) // alles bleibt gleich
            {
              retcode = pt;
            }
            else if(size < pfat->size) // verkleinern
            {
              php->databytes -= pfat->size;
              HeapFatSplit(php, idx, size);
              php->databytes += pfat->size;
              retcode = pt;
            }
            else if(size > pfat->size) // vergrössern
            {
              oldsize = pfat->size;
              php->databytes -= pfat->size;
            
              unsigned long add = size - pfat->size;
              if(idx == 0)
              {
                if(add <= HeapGetFreeSize(php)) // ist noch genug speicher frei
                {
                  php->size_used += add; // usedsize korrigieren
                  pfat->size = size; // blocksize korrigieren
              
                 #ifdef HEAP_CHECK
                  HeapBlockTag(pfat);
                 #endif
             
                  retcode = pt;
                }
              }
              else
              {
                _HeapEntry *pnext = HeapGetFatEntry(php, idx-1);
                if(pnext->used == 0) // ist anchfolgender block frei
                {
                  if(add <= pnext->size) // passt die grösse
                  {
                    unsigned long rest = pnext->size - add;
                    if(rest < 16)
                    {
                      // idx und idx-1 zusammenfassen
                      pfat->size += pnext->size;
                      HeapFatDelete(php, idx-1);
                      php->no_free --;
                      php->no --;

                     #ifdef HEAP_CHECK
                      HeapBlockTag(pfat);
                     #endif
                 
                      retcode = pt;
                    }
                    else
                    {
                      pfat->size  += add;
                      pnext->size -= add;
                      pnext->ptr  += add;
                
                    #ifdef HEAP_CHECK
                      HeapBlockTag(pfat);
                      HeapBlockTag(pnext);
                     #endif
                 
                      retcode = pt;
                    }
                  }
                }
              }
            
              php->databytes += pfat->size;
            }
          }

         if(retcode == NULL)
         {
            if(oldsize > 0)
            {
              _HeapEntry *pnew = HeapAllocIntern(php, size, pfat->uid);
              if(pnew != NULL)
              {
                retcode = (void*)pnew->ptr;
               #ifdef HEAP_CHECK
                HeapBlockTag(pnew);
               #endif
                HeapUnLock(php); // ******************************************** [CRITICAL SECTION]
                sigclib_memcpy(retcode, pt, oldsize);
                HeapLock(php); // ********************************************** [CRITICAL SECTION]
                HeapFreeIntern(php, pt);
              }
            }
          }
        }
      }
    
      HeapUnLock(php); // ****************************************************** [CRITICAL SECTION]
    }
  }
 #ifdef HEAP_DEFAULT
  else
  {
    retcode = sigclib_realloc(pt, size);
  }
 #endif
 
  return retcode;
}

cExtern unsigned long sigclib_heap_memory(void *php0, void **pptr, unsigned long size, unsigned long id)
{
  // alloc, realloc und free in einer funktion
  void *ph;
  
  if(size == 0)
  {
    if(*pptr != 0)
    {
      sigclib_heap_free(php0, *pptr);
    }
    
    *pptr = NULL;
    return 1;
  }
  
  if(*pptr != 0)
  {
    ph = sigclib_heap_realloc(php0, *pptr, size);
    if(ph != NULL)
    {
      *pptr = ph;
      return 1;
    }
    
    return 0;
  }
  
  ph = sigclib_heap_malloc(php0, size, id);
  if(ph != NULL)
  {
    *pptr = ph;
    return 1;
  }
  
  return 0;
}

cExtern unsigned long *sigclib_heap_info(void *php0)
{
  // info (heapwalk) vom heap erzeugen
  // NOTE: erzeugte info muss wieder freigegeben (sigclib_heap_free()) werden
  unsigned long *retcode = NULL;

  if(php0 != NULL)
  {
    _Heap *php = (_Heap*)php0;
  
    HeapLock(php); // ********************************************************** [CRITICAL SECTION]
    
    if(php->crazyval == php0)
    {
      unsigned long no = php->no - php->no_free;
      
      _HeapEntry *pfat = HeapAllocIntern(php, 4 + 4 + (no + 1) * 12, 0xFFFF); // allocintern verwenden weil bereits lock
      if(pfat != NULL)
      {
        retcode = (unsigned long*)pfat->ptr;
      
        if(retcode != NULL)
        {
          unsigned long *pi = retcode;
          unsigned long anz = 0;
          *pi++ = anz; // anzahl initialisieren
          *pi++ = php->size; // gesamtgrösse in bytes
      
          unsigned long nox = php->no;
          pfat = HeapGetFatEntry(php, 0);
          while(nox--)
          {
            if(pfat->used == 1)
            {
              anz ++;
              *pi++ = pfat->ptr - php->data;
              *pi++ = pfat->size;
              *pi++ = pfat->uid;
            }
            pfat ++;
          }
        
          *retcode = anz; // tatsächliche anzahl eintragen
        }
      }
    }
    
    HeapUnLock(php); // ******************************************************** [CRITICAL SECTION]
  }
  
  // [4] ..... anzahl
  // [4] ..... gesamtgrösse
  // * [4] ... start
  // * [4] ... size
  // * [4] ... info
  
  return retcode;
}

cExtern unsigned long sigclib_heap_used(void *php0, unsigned long *pno, unsigned long *psize)
{
  // information über anzahl der belegten heapblöcke und deren gesamtbyteanzahl ermitteln
  unsigned long retcode = 0;

  *pno   = 0;
  *psize = 0;

  if(php0 != NULL)
  {
    _Heap *php = (_Heap*)php0;
  
    HeapLock(php); // ********************************************************** [CRITICAL SECTION]
    
    if(php->crazyval == php0)
    {
      if(pno != NULL)
      {
        *pno = php->no - php->no_free;
      }
      if(psize != NULL)
      {
        *psize = php->databytes;
      }
      
      retcode = 1;
    }
    
    HeapUnLock(php); // ******************************************************** [CRITICAL SECTION]
  }
  
  return retcode;
}
