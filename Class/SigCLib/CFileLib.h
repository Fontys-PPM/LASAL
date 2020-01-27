
#ifndef _CFileLibH
 #define _CFileLibH
  
  #include "DefineCompiler.h"

  #ifdef cCompile
    
    #include "lsl_c_ifssr.h"
    #include "RTOS_C_interfaces.h"
    #include "file_iotypes.h"

    // file open
    cExtern long sigclib_fopen(char *dpne, unsigned long state);
      // use following state: ATT_READ_WRITE, ATT_READ_ONLY, ATT_OPEN_SHARED, ATT_OPEN_NO_DIR, ATT_OPEN_DIR
      //                      ATT_CREATE, ATT_CREATE_ALWAYS
      // function will return value < 0 in case of error, on the other hand a handle of value >= 0
  
    // file close
    cExtern void sigclib_fclose(long hdl);
  
    // read from file
    cExtern unsigned long sigclib_fread(long hdl, void *dst, unsigned long length);
  
    // read stream from file till LF or EOF occures, CR will be ignored
    cExtern char *sigclib_fgets(long hdl, char *s, unsigned long size);
  
    // write data into file
    cExtern unsigned long sigclib_fwrite(long hdl, void *dst, unsigned long length);
  
    // set position of filepointer
    cExtern unsigned long sigclib_fseek(long hdl, long offset, unsigned long fromwhere);
      // #define FILE_BEGIN   0
      // #define FILE_CURRENT 1
      // #define FILE_END     2
  
    // get position of filepointer
    cExtern long sigclib_ftell(long hdl);
  
    // get length of file
    cExtern long sigclib_flength(long hdl);
  
    // remove file
    cExtern long sigclib_remove(char *dpne);

    // rename file  
    cExtern long sigclib_rename(char* oldname, char* newname);
  
    // findfirst
    cExtern long sigclib_findfirst(char *namepattern, unsigned char attr0, unsigned char attrmask, _DDE_INFO *fileinfo, char *filename, unsigned long maxlength);
  
    // findnext
    cExtern long sigclib_findnext(long hdl, _DDE_INFO *fileinfo, char *filename, unsigned long maxlength);
  
    // findclose
    cExtern long sigclib_findclose(long hdl);
    
    // create new directory, return 0 on success or negative errorcode
    cExtern long sigclib_mkdir(const char *path);

    // remove existiong directory, return 0 on success or negative errorcode
    cExtern long sigclib_rmdir(const char *path);
    
    // create new file 'dpne' with content 'data' of length 'size'. return 1 on success, or 0 if error occured
    cExtern unsigned long sigclib_filecreate(const char *dpne, void *ptr, unsigned long size);

    // get content of already existing file
    cExtern void *sigclib_fileread(unsigned long *psize, const char *dpne);

    // ********************************************************************************************
    // fast fileaccess, using ram-cache ***********************************************************
    // ********************************************************************************************
   
    // open existing or create new file, use cache of fildata when requested
    cExtern void*         sigclib_cfopen(const char *dpne, unsigned long state);
    cExtern void*         sigclib_cfopenex(const char *dpne, unsigned long state, unsigned long writesize);
      // use state 'r', 'R' to open existing file
      // use state 'w', 'W' to create new file, existing file will be overwritten
      // when use state 'R' or 'W' filedate will be cached in ram for faster sequential read or write
      
    // close file opend with function sigclib_cfopen  
    cExtern unsigned long sigclib_cfclose(void *hdl);
      // function will return 1 on success, on the other hand 0
    
    // read data from file
    cExtern unsigned long sigclib_cfread(void *hdl, void *dst, unsigned long bytesize);
    
    // write data into file
    cExtern unsigned long sigclib_cfwrite(void *hdl, const void *src, unsigned long bytesize);
    
    // set position of filepointer
    cExtern unsigned long sigclib_cfseek(void *hdl, long offset, unsigned long fromwhere);
      // #define FILE_BEGIN   0
      // #define FILE_CURRENT 1
      // #define FILE_END     2
    
    // get position of filepointer
    cExtern long          sigclib_cftell(void *hdl);
    
    // read stream from file till LF or EOF occures, CR will be ignored
    cExtern char*         sigclib_cfgets(void *hdl, char *s, unsigned long size);
    
    
  #else
    #include "file_iotypes.h"

    // file open
    function global __cdecl sigclib_fopen var_input dpne:^char; state:udint; end_var var_output retcode : dint; end_var;
  
    // file close
    function global __cdecl sigclib_fclose var_input hdl:dint; end_var;
  
    // read from file
    function global __cdecl sigclib_fread var_input hdl:dint; dst:^void; length:udint; end_var var_output retcode : udint; end_var;
  
    // read stream from file till LF or EOF occures
    function global __cdecl sigclib_fgets var_input hdl:dint; s:^char; size:udint; end_var var_output retcode : ^char; end_var;
  
    // write data into file
    function global __cdecl sigclib_fwrite var_input hdl:dint; dst:^void; length:udint; end_var var_output retcode : udint; end_var;
  
    // set position of filepointer
    function global __cdecl sigclib_fseek var_input hdl:dint; offset:dint; fromwhere:udint; end_var var_output retcode : udint; end_var;
  
    // get position of filepointer
    function global __cdecl sigclib_ftell var_input hdl:dint; end_var var_output retcode : dint; end_var;
  
    // get length of file
    function global __cdecl sigclib_flength var_input hdl:dint; end_var var_output retcode : dint; end_var;
    
    // remove file
    function global __cdecl sigclib_remove var_input dpne:^char; end_var var_output retcode : dint; end_var;
    
    // rename file  
    function global __cdecl sigclib_rename var_input oldname:^char; newname:^char; end_var var_output retcode : dint; end_var;
  
      // create new file 'dpne' with content 'data' of length 'size'. return 1 on success, or 0 if error occured
    function global __cdecl sigclib_filecreate var_input dpne:^char; ptr:^void; size:udint; end_var var_output retcode : udint; end_var;

    // get content of already existing file
    function global __cdecl sigclib_fileread var_input psize:^udint; dpne:^char; end_var var_output retcode:^void; end_var;

    // ********************************************************************************************
    // fast fileaccess, using ram-cache ***********************************************************
    // ********************************************************************************************
   
    // open existing or create new file, use cache of fildata when requested
    function global __cdecl  sigclib_cfopen var_input dpne:^char; state:udint; end_var var_output retcode:^void; end_var;
    function global __cdecl  sigclib_cfopenex var_input dpne:^char; state:udint; writesize:udint; end_var var_output retcode:^void; end_var;
      // use state 'r', 'R' to open existing file
      // use state 'w', 'W' to create new file, existing file will be overwritten
      // when use state 'R' or 'W' filedate will be cached in ram for faster sequential read or write
      
    // close file opend with function sigclib_cfopen
    function global __cdecl  sigclib_cfclose var_input hdl:^void; end_var var_output retcode:udint; end_var;
      // function will return 1 on success, on the other hand 0
    
    // read data from file
    function global __cdecl  sigclib_cfread var_input hdl:^void; dst:^void; bytesize:udint; end_var var_output retcode:udint; end_var;
    
    // write data into file
    function global __cdecl  sigclib_cfwrite var_input hdl:^void; stc:^void; bytesize:udint; end_var var_output retcode:udint; end_var;
    
    // set position of filepointer
    function global __cdecl  sigclib_cfseek var_input hdl:^void; offset:dint; fromwhere:udint; end_var var_output retcode:udint; end_var;
      // #define FILE_BEGIN   0
      // #define FILE_CURRENT 1
      // #define FILE_END     2
    
    // get position of filepointer
    function global __cdecl  xsigclib_cftell var_input hdl:^void; end_var var_output retcode:dint; end_var;
    
    // read stream from file till LF or EOF occures, CR will be ignored
    function global __cdecl  sigclib_cfgets var_input hdl:^void; s:^char; size:udint; end_var var_output retcode:^char; end_var;
    
  #endif

#endif