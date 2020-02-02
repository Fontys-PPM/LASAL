#ifndef _CMathLibH
 #define _CMathLibH
  
  #include "DefineCompiler.h"

  #define sigclib_pi 3.14159265358979323846264338327
  #define sigclib_rad_to_grad(p) (((p)*180) / (sigclib_pi))
  #define sigclib_grad_to_rad(p) (((p)*(sigclib_pi)) / 180)
  #define sigclib_arraysize(_P) (sizeof(_P) / sizeof(_P[0]))

  #ifdef cCompile
    #define sigclib_sprintf LSL_POS->piCRT->sprintf

    #define sigclib_abs(A)    (((A) < 0)? -(A) : (A))
    #define sigclib_min(A, B) (((A) < (B))? (A) : (B))
    #define sigclib_max(A, B) (((A) > (B))? (A) : (B))
    #define sigclib_isQNAN(A) ((A) != (A))
    #define sigclib_round(A)  (((A) >= 0)? ((A) + 0.5) : ((A) - 0.5))
    
    cExtern float sigclib_sin(float alpha);
    cExtern float sigclib_cos(float alpha);
    cExtern float sigclib_tan(float alpha);
    cExtern float sigclib_asin(float alpha);
    cExtern float sigclib_acos(float alpha);
    cExtern float sigclib_atan(float alpha);
    cExtern float sigclib_atan2(float y, float x);
    cExtern float sigclib_sqrt(float value);
    cExtern float sigclib_pow(float value, float exponent);
    cExtern float sigclib_exp(float exponent);
    cExtern float sigclib_floor(float exponent);
    cExtern float sigclib_ceil(float exponent);
    cExtern float sigclib_fmod(float value, float divisor);
    cExtern float sigclib_hypot(float a, float b); // sqrt(a*a+b*b)
    cExtern float sigclib_log(float value);
    cExtern float sigclib_log10(float value);
    cExtern long  sigclib_ftol(float value);
    
    cExtern double sigclib64_sin(double alpha);
    cExtern double sigclib64_cos(double alpha);
    cExtern double sigclib64_tan(double alpha);
    cExtern double sigclib64_asin(double alpha);
    cExtern double sigclib64_acos(double alpha);
    cExtern double sigclib64_atan(double alpha);
    cExtern double sigclib64_sqrt(double value);
    cExtern double sigclib64_pow(double value, double exponent);
    cExtern double sigclib64_exp(double exponent);
    cExtern double sigclib64_floor(double value);
    cExtern double sigclib64_ceil(double value);
    cExtern double sigclib64_atan2(double y, double x);
    cExtern double sigclib64_fmod(double value, double divisor);
    cExtern double sigclib64_hypot(double a, double b);
    cExtern double sigclib64_log(double value);
    cExtern double sigclib64_log10(double value);
    cExtern double sigclib64_abs(double value);

  #else
  
    #define sigclib_sin(p)    sin(p)
    #define sigclib_cos(p)    cos(p)
    #define sigclib_tan(p)    tan(p)
    #define sigclib_asin(p)   asin(p)
    #define sigclib_acos(p)   acos(p)
    #define sigclib_atan(p)   atan(p)
    #define sigclib_sqrt(p)   sqrt(p)
    
    function global __cdecl sigclib64_sin var_input alpha:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_cos var_input alpha:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_tan var_input alpha:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_asin var_input alpha:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_acos var_input alpha:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_atan var_input alpha:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_sqrt var_input value:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_pow var_input value:lreal; exponent:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_exp var_input exponent:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_floor var_input value:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_ceil var_input value:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_atan2 var_input y:lreal; x:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_log var_input value:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_log10 var_input value:lreal; end_var var_output retcode:lreal; end_var;
    function global __cdecl sigclib64_abs var_input value:lreal; end_var var_output retcode:lreal; end_var;
    
  #endif

#endif