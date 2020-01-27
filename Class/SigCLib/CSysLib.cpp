//<NewSigmatekCFileOptimize/>
// +-------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                          |
// +-[      author ] kolott                                                        |
// +-[        date ] 08.07.2016                                                    |
// +-[ description ]---------------------------------------------------------------+
// |                                                                               |
// |                                                                               |
// +-------------------------------------------------------------------------------+


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
