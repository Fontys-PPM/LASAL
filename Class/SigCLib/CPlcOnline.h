#ifndef _CPlcOnlineH
  #define _CPlcOnlineH

  #include "DefineCompiler.h"

  #ifdef cCompile
    // login at plc. function will return valid pointer (handle) on success, on the other hand NULL
    // interface 10 ... tcpip, 0x15740A0A .. 10.10.116.22
    cExtern void*         sigclib_plc_Login(unsigned long interface, unsigned long address);
    // logout at plc
    cExtern void          sigclib_plc_Logout(void *hdl);
    // TxCommand
    cExtern unsigned long sigclib_plc_TxCommand(void *hdl, void**presult, unsigned long command, const unsigned char *pdata, unsigned long datalength);
    // get lasalid of given server
    cExtern unsigned long sigclib_plc_GetLasalIdSvr(void *hdl, const char *label);
    // get multi lasalid of given object+server1+server2...
    cExtern unsigned long sigclib_plc_GetLasalIdSvrEx(void *hdl, unsigned long *pid, unsigned char *pdata, unsigned long datasize, unsigned long no);
    // get lasalid of given global variable
    cExtern unsigned long sigclib_plc_GetLasalIdVar(void *hdl, const char *label);
    // call read-method of given server by using lasalid
    cExtern unsigned long sigclib_plc_CallReadMethod(void *hdl, unsigned long *pdst, unsigned long lasalid);
    // call write-method of given server by using lasalid
    cExtern unsigned long sigclib_plc_CallWriteMethod(void *hdl, unsigned long lasalid, unsigned long value);
    
    // get descriptor-crc from plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_GetDscCrc(void *hdl, unsigned long *pcrc);
    // keep connection to plc alive. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_KeepAlive(void *hdl);
    // function will return loaderversion from plc, in case of error function will return 0
    cExtern unsigned long sigclib_plc_GetLoaderVersion(void *hdl);
    
    // add server to refreshlist. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_ReflistAddSvr(void *hdl, unsigned long lasalid, unsigned long userid, unsigned long time_ms, unsigned long channel);
    // add variable to refreshlist. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_ReflistAddVar(void *hdl, unsigned long lasalid, unsigned long userid, unsigned long time_ms, unsigned long channel);
    // add string-server to refreshlist. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_ReflistAddStr(void *hdl, unsigned long lasalid, unsigned long userid, unsigned long time_ms, unsigned long channel);
    // start refreshlist at plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_ReflistStart(void *hdl, unsigned long channel);
    // stop refreshlist at plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_ReflistStop(void *hdl, unsigned long channel);
    // install callback at refreshlist. callback has to be of prototype extern "C" void CallBack(unsigned long userid, unsigned long value);
    cExtern void          sigclib_plc_ReflistInstallCallback(void *callback);
    
    // get string from plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_GetString(void *hdl, void *dst, unsigned long *pchrsize, unsigned long lasalid, unsigned long maxbytesize);
    // set string at plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_SetString(void *hdl, const void *src, unsigned long chrsize, unsigned long lasalid);
    
    // get data from address in plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_GetDataAt(void *hdl, void *dst, unsigned long address, unsigned long bytelength);
    // set data at address in plc. function will return 1 in case of success, otherwise 0
    cExtern unsigned long sigclib_plc_SetDataAt(void *hdl, void *src, unsigned long address, unsigned long bytelength);
    
  #else
    // login at plc. function will return valid pointer (handle) on success, on the other hand NULL
    function global __cdecl sigclib_plc_Login var_input interface:udint; address:udint; end_var var_output retcode:^void; end_var;
    // logout at plc
    function global __cdecl sigclib_plc_Logout var_input hdl:^void; end_var;
    // TxCommand
    function global __cdecl sigclib_plc_TxCommand var_input hdl:^void; presult:^pvoid; command:udint; pdata:^usint; datalength:udint; end_var var_output retcode:udint; end_var;
    // get lasalid of given server
    function global __cdecl sigclib_plc_GetLasalIdSvr var_input hdl:^void; label:^char; end_var var_output retcode:udint; end_var;
    // get multi lasalid of given object+server1+server2...
    function global __cdecl sigclib_plc_GetLasalIdSvrEx var_input hdl:^void; pid:^udint; pdata:^usint; datasize:udint; no:udint; end_var var_output retcode:udint; end_var;
    // get lasalid of given global variable
    function global __cdecl sigclib_plc_GetLasalIdVar var_input hdl:^void; label:^char; end_var var_output retcode:udint; end_var;
    // call read-method of given server by using lasalid
    function global __cdecl sigclib_plc_CallReadMethod var_input hdl:^void; pdst:^udint; lasalid:udint; end_var var_output retcode:udint; end_var;
    // call write-method of given server by using lasalid
    function global __cdecl sigclib_plc_CallWriteMethod var_input hdl:^void; lasalid:udint; value:udint; end_var var_output retcode:udint; end_var;
    
    // get descriptor-crc from plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_GetDscCrc var_input hdl:^void; pcrc:^udint; end_var var_output retcode:udint; end_var;
    // keep connection to plc alive. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_KeepAlive var_input hdl:^void; end_var var_output retcode:udint; end_var;
    // function will return loaderversion from plc, in case of error function will return 0
    function global __cdecl sigclib_plc_GetLoaderVersion var_input hdl:^void; end_var var_output retcode:udint; end_var;
    
    // add server to refreshlist. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_ReflistAddSvr var_input hdl:^void; lasalid:udint; userid:udint; time_ms:udint; channel:udint; end_var var_output retcode:udint; end_var;
    // add variable to refreshlist. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_ReflistAddVar var_input hdl:^void; lasalid:udint; userid:udint; time_ms:udint; channel:udint; end_var var_output retcode:udint; end_var;
    // add string-server to refreshlist. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_ReflistAddStr var_input hdl:^void; lasalid:udint; userid:udint; time_ms:udint; channel:udint; end_var var_output retcode:udint; end_var;
    // start refreshlist at plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_ReflistStart var_input hdl:^void; channel:udint; end_var var_output retcode:udint; end_var;
    // stop refreshlist at plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_ReflistStop var_input hdl:^void; channel:udint; end_var var_output retcode:udint; end_var;
    // install callback at refreshlist. callback has to be of prototype extern "C" void CallBack(unsigned long userid, unsigned long value);
    function global __cdecl sigclib_plc_ReflistInstallCallback var_input callback:^void; end_var;
    
    // get string from plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_GetString var_input hdl:^void; dst:^void; pchrsize:^udint; lasalid:udint; maxbytesize:udint; end_var var_output retcode:udint; end_var;
    // set string at plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_SetString var_input hdl:^void; src:^void; chrsize:udint; lasalid:udint; end_var var_output retcode:udint; end_var;
    
    // get data from address in plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_GetDataAt var_input hdl:^void; dst:^void; address:udint; bytelenght:udint; end_var var_output retcode:udint; end_var;
    // set data at address in plc. function will return 1 in case of success, otherwise 0
    function global __cdecl sigclib_plc_SetDataAt var_input hdl:^void; src:^void; address:udint; bytelength:udint; end_var var_output retcode:udint; end_var;

  #endif

  
#endif
