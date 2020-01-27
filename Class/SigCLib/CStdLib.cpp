
#include "CStdLib.h" 

#ifdef _MSC_VER
#include "RTOS_C_interfaces.h"
extern "C" long _ftol(float val)
{
  return FTOL(val);
}

extern "C" long _ftol2(float val)
{
  return _ftol(val);
}
#endif
