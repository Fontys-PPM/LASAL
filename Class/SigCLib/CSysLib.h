
#ifndef _CSysLibH
 #define _CSysLibH

  #include "DefineCompiler.h"

  #ifdef cCompile
  
    typedef union
    {
      float         fval;
      unsigned long uval;
    }
    st_real;
    #define sigclib_real st_real
  
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

    // get pointer to classdescriptor
    cExtern void* sigclib_lookup_class(const char *classname);

    // get pointer to classdescriptor by using this-pointer
    cExtern void *sigclib_lookup_object(void *pthis);

    // get revisionnumber of class
    cExtern unsigned long sigclib_revisionof_class(const char *classname);

    // get revision of object (classrevision) by using this-pointer
    cExtern unsigned long sigclib_revisionof_object(void *pthis);

    // get name of class by using this-pointer
    cExtern char* sigclib_nameof_class(void *pthis);

    // get name of baseclass by using this-pointer
    cExtern char *sigclib_nameof_baseclass(void *pthis);

    // get objectname by using this-pointer
    cExtern char *sigclib_nameof_object(void *pthis);

    // create unique name by using incremental value
    cExtern char *sigclib_name_unique(char *pd, const char *name);

    // enlarge name by using pointer-extention
    cExtern char *sigclib_name_enlarge(char *pd, const char *name, void *ptr);

    // get revisionnumber of loader
    cExtern unsigned long sigclib_revisionof_loader(void);

    // get revision number of opsys
    cExtern unsigned long sigclib_revisionof_opsys(void);

    // check if class of object is derived from given class
    cExtern unsigned long sigclib_isderived_from(void *pthis, const char *classname);
    
    // reset sps
    cExtern void sigclib_reset(void);

    // restart application
    cExtern void sigclib_restart(void);

    // get address of virtual method
    cExtern void* sigclib_virtual_methodpointer(void *pthis, long idx);

    // create new thread (prio 14=Cy, prio 10=bk, prio 16=rt)  eg.: function global __cdecl MyClass::Thread var_input pthis:^void; end_var;
    cExtern unsigned long sigclib_thread_create(void *pfkt, unsigned long priority, void *pthis, const char *name);

    // create new thread, timebase us, including termination eg.: unsigned long pfkt(void *pcookie)
    cExtern unsigned long sigclib_thread_create2(void* pfkt, unsigned long priority, unsigned long time_us, void *pcookie, const char *name);

    // destroy created thread
    cExtern long sigclib_thread_destroy(unsigned long threadhdl);

    // delay thread
    cExtern void sigclib_thread_delay(unsigned long duration);

    // get current free stacksize
    cExtern unsigned long sigclib_thread_get_current_free_stacksize(void);

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

    // get name of class by using this-pointer
    function global __cdecl sigclib_nameof_class var_input pthis:^void; end_var var_output retcode:^char; end_var;

    // get name of baseclass by using this-pointer
    function global __cdecl sigclib_nameof_baseclass var_input pthis:^void; end_var var_output retcode:^char; end_var;

    // get objectname by using this-pointer
    function global __cdecl sigclib_nameof_object var_input pthis:^void; end_var var_output retcode:^char; end_var;

    // create unique name by using incremental value
    function global __cdecl sigclib_name_unique var_input pd:^char; name:^char; end_var var_output retcode:^char; end_var;

    // enlarge name by using pointer-extention
    function global __cdecl sigclib_name_enlarge var_input pd:^char; name:^char; ptr:^void; end_var var_output retcode:^char; end_var;

    // get pointer to classdescriptor
    function global __cdecl sigclib_lookup_class var_input classname:^char; end_var var_output retcode:^ClsHdr; end_var;

    // get pointer to classdescriptor by using this-pointer
    function global __cdecl sigclib_lookup_object var_input pthis:^void; end_var var_output retcode:^ClsHdr; end_var;

    // get revision of object (classrevision) by using this-pointer
    function global __cdecl sigclib_revisionof_object var_input pthis:^void; end_var var_output retcode:udint; end_var;

    // get revisionnumber of class
    function global __cdecl sigclib_revisionof_class var_input classname:^char; end_var var_output retcode:udint; end_var;

    // get revision number of loader
    function global __cdecl sigclib_revisionof_loader var_output retcode:udint; end_var;

    // get revision number of opsys
    function global __cdecl sigclib_revisionof_opsys var_output retcode:udint; end_var;

    // check if class of object is derived from given class
    function global __cdecl sigclib_isderived_from var_input pthis:^void; classname:^char; end_var var_output retcode : udint; end_var;

    // reset sps
    function global __cdecl sigclib_reset;

    // restart application
    function global __cdecl sigclib_restart;

    // get address of virtual method
    function global __cdecl sigclib_virtual_methodpointer var_input pthis:^void; idx:dint; end_var var_output retcode:^void; end_var;

    // create new thread (prio 14=Cy, prio 10=bk, prio 16=rt) eg.: function global __cdecl MyClass::Thread var_input pthis:^void; end_var;
    function global __cdecl sigclib_thread_create var_input pfkt:^void; priority:udint; pthis:^void; name:^char; end_var var_output retcode:udint; end_var;

    // create new thread, timebase us, including termination eg.: function global __cdecl pfkt var_input pcookie:^void; end_var var_output run:udint; end_var;
    function global __cdecl sigclib_thread_create2 var_input pfkt:^void; priority:udint; time_us:udint; pcookie:^void; name:^char; end_var var_output retcode:udint; end_var;

    // destroy created thread
    function global __cdecl sigclib_thread_destroy var_input threadhdl:udint; end_var var_output retcode:dint; end_var;

    // delay thread
    function global __cdecl sigclib_thread_delay var_input duration:udint; end_var;
    
    // get current free stacksize
    function global __cdecl sigclib_thread_get_current_free_stacksize var_output retcode:udint; end_var;
    
  #endif
 
#endif


// ************************************************************************************************
// USAGE
// ************************************************************************************************

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_mutex_create(const char *mutexname);
// is used to create a semaphore
// --> mutexname ....... name of semaphore
// <-- function will return valid id to handle semaphore, or 0 on error
// NOTE: As of version 0.30 of class SigCLib, NULL may also be used as a valid mutexname-parameter. 
// In that case a unique defaultname, begining with "Mux" will be created.

// ------------------------------------------------------------------------------------------------
// void sigclib_mutex_destroy(unsigned long mutexhdl);
// delete already created semaphore
// --> mutexhdl ........ id of semaphore to destroy
    
// ------------------------------------------------------------------------------------------------
// void sigclib_mutex_section_start(unsigned long mutexhdl);
// start critical section
// --> mutexhdl ........ id of semaphore to destroy
// NOTE: do not forget to stop critical sectipon afterwards
    
// ------------------------------------------------------------------------------------------------
// void sigclib_mutex_section_stop(unsigned long mutexhdl);
// stop critical section
// --> mutexhdl ........ id of semaphore to destroy
// NOTE: do not stop critical sectipon without previous start

// ------------------------------------------------------------------------------------------------
// void sigclib_serviceprovider(const char*txt);
// send command to serviceprovider
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_is_salamander(void);
// check if opsys is salamander
// function will return <>0 when salamander-opsys is in use, on the other hand 0 (rtk-opsys, lars)
   
// ------------------------------------------------------------------------------------------------
// void *sigclib_get_thisptr(const char *label);
// get this-pointer of lasal-object
// --> label ........... name of lasal-object
// <-- function will return valid this-pointer when named object is existion, on the other hand NULL

// ------------------------------------------------------------------------------------------------
// void *sigclib_cilget(const char *name);    
// get arbitrary pointer to os-interface (os-api)
// --> name ............ name of Interface
// <-- function will return valid pointer when named iterface is found, on the other hand NULL

// ------------------------------------------------------------------------------------------------
// void* sigclib_lookup_class(const char *classname);
// get pointer to classdescriptor
// --> classname ....... name of Lasal-Class
// <-- function will return valid pointer when named class is found, on the other hand NULL

// ------------------------------------------------------------------------------------------------
// void *sigclib_lookup_object(void *pthis);
// get pointer to classdescriptor by using this-pointer
// --> pthis ........... valid this-pointer of Lasal-Object to get classdescriptor
// <-- function will return valid pointer to classdescriptor, on the other hand NULL

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_revisionof_class(const char *classname);
// get revisionnumber of class
// --> classname ....... name of Lasal-Class to get information about revision
// <-- revisionnumber of named Lasal-Class

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_revisionof_object(void *pthis);
// get revision of object (classrevision) by using this-pointer
// --> pthis ........... valid this-pointer of Lasal-Object to get class-revisionnumber
// <-- revisionnumber of according class

// ------------------------------------------------------------------------------------------------
// char* sigclib_nameof_class(void *pthis);
// get name of class by using this-pointer
// --> pthis ........... valid this-pointer of Lasal-Object to get class-name
// <-- Pointer to classname or NULL when given invalid pthis

// ------------------------------------------------------------------------------------------------
// char *sigclib_nameof_baseclass(void *pthis);
// get name of baseclass (immediate below) by using this-pointer of object
// --> pthis ........... valid this-pointer of Lasal-Object to get baseclass-name
// <-- Pointer to baseclassname or NULL when given invalid pthis, or class of object is not derived

// ------------------------------------------------------------------------------------------------
// char *sigclib_nameof_object(void *pthis);
// get objectname by using this-pointer
// --> pthis ........... valid this-pointer of Lasal-Object
// <-- Pointer to objectname or NULL when given invalid pthis

// ------------------------------------------------------------------------------------------------
// char *sigclib_name_unique(char *pd, const char *name);
// create unique name by adding internal incremental value (32bit) to given name
// --> pd .............. destination array
// --> name ............ first token of name to create
// <-- function will return pointer to newly created name, corresponds to given destination array

// ------------------------------------------------------------------------------------------------
// char *sigclib_name_enlarge(char *pd, const char *name, void *ptr);
// create enlarged name by connecting name and pointer (address)
// --> pd .............. destination array
// --> name ............ first token of name to create
// --> ptr ............. address to extend
// <-- function will return pointer to newly created name, corresponds to given destination array

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_revisionof_loader(void);
// get revisionnumber of Loader
// <-- Revisionnumber of Loader

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_revisionof_opsys(void);
// get revision number of Opsys
// <-- Revisionnumber of Opsys

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_isderived_from(void *pthis, const char *classname);
// check if class of object is derived from given class
// --> pthis ........... valid this-pointer of Lasal-Object
// --> classname ....... name of class to lookup
// <-- function will return <>0 on sucsess, on the other hand 0

// ------------------------------------------------------------------------------------------------
// void sigclib_reset(void);
// reset sps
// NOTE: SPS will not automatically restart afterwards

// ------------------------------------------------------------------------------------------------
// void sigclib_restart(void);
// restart application

// ------------------------------------------------------------------------------------------------
// void* sigclib_virtual_methodpointer(void *pthis, long idx);
// get address of virtual method
// --> pthis ........... valid this-pointer of Lasal-Object
// --> idx ............. index of virtual method (only insider will know)
// <-- address of virtual method

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_thread_create(void *pfkt, unsigned long priority, void *pthis, const char *name);
// create new thread  
// --> pfkt ............ adress of method or function eg.: function global __cdecl MyClass::Thread var_input pthis:^void; end_var;
// --> priority ........ prio 10=bk , prio 14=Cy, prio 16=rt
// --> pthis ........... this-pointer of object
// --> name ............ name of thread
// <-- valid thread-handle, or 0 on error

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_thread_create2(void* pfkt, unsigned long priority, unsigned long time_us, void *pcookie, const char *name);
// create new thread with us(!) timebase, task will be automatically finished when given function will return 0
// --> pfkt ............ adress of global function to handle, eg.: function global __cdecl MyClass::Thread var_input pcookie:^void; end_var var_output run:udint; end_var;
// --> priority ........ prio 10=bk , prio 14=Cy, prio 16=rt
// --> time_us ......... delaytime in us (see NOTE below)
// --> pcookie ......... cookie
// --> name ............ name of thread
// <-- valid thread-handle, or 0 on error
// NOTE: some Sigmatek-OpSys will not support us-timebase, functionality will switch over to rounded milliseconds (ms)
//       If pcookie is used as this-pointer to any lasal-object, make sure that first line in given method is "this := pcookie$^MyClass;"
//       Do not forget about keyword __cdecl at given ST-function/ST-method.

// ------------------------------------------------------------------------------------------------
// long sigclib_thread_destroy(unsigned long threadhdl);
// destroy already created thread
// --> threadhdl ....... valid threadhandle

// ------------------------------------------------------------------------------------------------
// void sigclib_thread_delay(unsigned long duration);
// delay thread
// --> duration ........ delaytime in milliseconds (ms)

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_thread_get_current_free_stacksize(void);
// get current free (unused) stacksize
// <-- unused stacksize in bytes of current thread (Default: 0xFFFFFFFF, eg.LARS)



