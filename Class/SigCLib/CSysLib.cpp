//<NewSigmatekCFileOptimize/>
// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 08.07.2016                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#include "SigCLib.h"
#include "RTOS_C_Interfaces.h"

extern "C" void _LookUpEmbed_C(const char *label, void **ppthis, void *pobj);

void *sigclib_get_thisptr(const char *label)
{
  void *pthis = NULL;
  _LookUpEmbed_C(label, &pthis, 0);
  return pthis;
}

void *sigclib_cilget(const char *name)
{
  if(lsl_pOS != NULL)
  {
    if(lsl_pOS->piCIL != NULL)
    {
      void *retcode = NULL;
      if(lsl_pOS->piCIL->CILGet((char*)name, &retcode) == SYS_ERR_NONE)
      {
        return retcode;
      }
    }
  }
  return NULL;
}

void sigclib_reset(void)
{
  sigclib_serviceprovider("exec reset");
}  

void sigclib_restart(void)
{
  sigclib_serviceprovider("exec run");
}  

void *sigclib_virtual_methodpointer(void *pthis, long idx)
{
  if(pthis != NULL)
  {
    unsigned char *pmeth = (unsigned char*)*(void**)pthis;
    return *(void**)(pmeth + ((idx+10) * 4));
  }
  return NULL;
}

static unsigned long name_unique_inc = 0;
char *sigclib_name_unique(char *pd, const char *name)
{
  if(name == NULL)
  {
    name = "Dummy";
  }

  unsigned long actinc = sigclib_atomic_incU32(&name_unique_inc);
  sigclib_sprintf(pd, "%s%u", name, actinc);
  
  return pd;
}

char *sigclib_name_enlarge(char *pd, const char *name, void *ptr)
{
  if(name == NULL)
  {
    name = "Dummy";
  }
  
  sigclib_sprintf(pd, "%s%p", name, ptr);
  return pd;
}
