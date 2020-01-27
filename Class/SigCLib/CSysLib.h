
#ifndef _CSysLibH
 #define _CSysLibH

  #include "DefineCompiler.h"

  #ifdef cCompile
    // create semaphor
    cExtern unsigned long sigclib_mutex_create(const char *mutexname);

    // delete already created semaphor
    cExtern void sigclib_mutex_destroy(unsigned long mutexhdl);
    
    // start critical section
    cExtern void sigclib_mutex_section_start(unsigned long mutexhdl);
    
    // stop critical section
    cExtern void sigclib_mutex_section_stop(unsigned long mutexhdl);
    
    // send command to serviceprovider
    cExtern void sigclib_serviceprovider(const char*txt);
    
    // check if opsys is salamander
    cExtern unsigned long sigclib_is_salamander(void);
   
    // get this-pointer of lasal-object
    cExtern void *sigclib_get_thisptr(const char *label);

    // get arbitrary os-interface (os-api)
    cExtern void *sigclib_cilget(const char *name);    

  #else
    // create semaphor
    function global __cdecl sigclib_mutex_create var_input mutexname : ^char; end_var var_output retcode : udint; end_var;
    
    // delete already created semaphor
    function global __cdecl sigclib_mutex_destroy var_input mutexhdl : udint; end_var;
    
    // start critical section
    function global __cdecl sigclib_mutex_section_start var_input mutexhdl : udint; end_var;
    
    // stop critical section
    function global __cdecl sigclib_mutex_section_stop var_input mutexhdl : udint; end_var;
    
    // send command to serviceprovider
    function global __cdecl sigclib_serviceprovider var_input txt:^char; end_var;  
    
    // check if opsys is salamander
    function global __cdecl sigclib_is_salamander var_output retcode:udint; end_var;

    // get this-pointer of lasal-object
    function global __cdecl sigclib_get_thisptr var_input label:^char; end_var var_output retcode:^void; end_var;
    
    // get arbitrary os-interface (os-api)
    function global __cdecl sigclib_cilget var_input name:^char; end_var var_output retcode:^void; end_var;

  #endif
 
#endif




