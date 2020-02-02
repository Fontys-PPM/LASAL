
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
  
    // write 0-terminated string into file
    cExtern unsigned long sigclib_fputs(long hdl, const char *s);
  
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
      // when use state 'R' or 'W' filedata will be cached in ram for faster sequential read or write
      
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

    // write 0-terminated string into file    
    cExtern unsigned long sigclib_cfputs(void *hdl, const char *s);
    
    // memoryoperation in combination to handle
    cExtern unsigned long sigclib_cfmemory(void *hdl, void **pptr, unsigned long bytesize);

    // ask if handle is ok
    cExtern unsigned long sigclib_cfok(void *hdl);
    
    // set errorcode
    cExtern unsigned long sigclib_cferror_set(void *hdl, unsigned long val);
    
    // get errorcode
    cExtern unsigned long sigclib_cferror_get(void *hdl);
    
    // set version
    cExtern unsigned long sigclib_cfversion_set(void* hdl, unsigned long version);

    // get version
    cExtern unsigned long sigclib_cfversion_get(void* hdl);
    
    // set cookie
    cExtern unsigned long sigclib_cfcookie_set(void* hdl, void *pcookie);

    // get cookie
    cExtern  void *sigclib_cfcookie_get(void* hdl);
    
    // determine all drives that are currently available
    cExtern unsigned long sigclib_drivelist(char *dst);
    
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
  
    // write 0-terminated string into file  
    function global __cdecl sigclib_fputs var_input hdl:dint; s:^char; end_var var_output retcode : udint; end_var;
  
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
  
    // findfirst
    function global __cdecl sigclib_findfirst var_input namepattern:^char; attr0:usint; attrmask:usint; fileinfo:^_DDE_INFO; filename:^char; maxlength:udint; end_var var_output retcode:dint; end_var;
    
    // findnext
    function global __cdecl sigclib_findnext var_input hdl:dint; fileinfo:^_DDE_INFO; filename:^char; maxlength:udint; end_var var_output retcode : dint; end_var;
  
    // findclose
    function global __cdecl sigclib_findclose var_input hdl:dint; end_var var_output retcode : dint; end_var;
    
    //  hdl := sigclib_findfirst("c:\*.*", 0, 0, #dde, #name[0], 128);
    //  repeat
    //    if(dde.Attributes AND ATT_DIR) then
    //    end_if;
    //  until(sigclib_findnext(hdl, #dde, #name[0], 128) <> 0) end_repeat;
    //  sigclib_findclose(hdl);

    // create new directory, return 0 on success or negative errorcode
    function global __cdecl sigclib_mkdir var_input path:^char; end_var var_output retcode : dint; end_var;
    
    // remove existiong directory, return 0 on success or negative errorcode
    function global __cdecl sigclib_rmdir var_input path:^char; end_var var_output retcode : dint; end_var;
  
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
      // when use state 'R' or 'W' filedata will be cached in ram for faster sequential read or write
      
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
    function global __cdecl  sigclib_cftell var_input hdl:^void; end_var var_output retcode:dint; end_var;
    
    // read stream from file till LF or EOF occures, CR will be ignored
    function global __cdecl  sigclib_cfgets var_input hdl:^void; s:^char; size:udint; end_var var_output retcode:^char; end_var;
    
    // write 0-terminated string into file
    function global __cdecl  sigclib_cfputs var_input hdl:^void; s:^char; end_var var_output retcode:udint; end_var;
    
    // memoryoperation in combination to handle
    function global __cdecl  sigclib_cfmemory var_input hdl:^void; pptr:^pvoid; bytesize:udint; end_var var_output retcode:udint; end_var;

    // ask if handle is ok
    function global __cdecl  sigclib_cfok var_input hdl:^void; end_var var_output retcode:udint; end_var;
    
    // set errorcode
    function global __cdecl  sigclib_cferror_set var_input hdl:^void; val:udint; end_var var_output retcode:udint; end_var;
    
    // get errorcode
    function global __cdecl  sigclib_cferror_get var_input hdl:^void; end_var var_output retcode:udint; end_var;
    
    // set version
    function global __cdecl  sigclib_cfversion_set var_input hdl:^void; version:udint; end_var var_output retcode:udint; end_var;

    // get version
    function global __cdecl  sigclib_cfversion_get var_input hdl:^void; end_var var_output retcode:udint; end_var;
    
    // set cookie
    function global __cdecl  sigclib_cfcookie_set var_input hdl:^void; pcookie:^void; end_var var_output retcode:udint; end_var;
    
    // get cookie
    function global __cdecl  sigclib_cfcookie_get var_input hdl:^void; end_var var_output retcode:^void; end_var;
    
    // determine all drives that are currently available
    function global __cdecl sigclib_drivelist var_input dst:^char; end_var var_output retcode:udint; end_var;
    
    
  #endif

#endif


// ************************************************************************************************
// USAGE
// ************************************************************************************************

// ------------------------------------------------------------------------------------------------
// long sigclib_fopen(char *dpne, unsigned long state);
// file open
// --> dpne ............ Drive, Path, Name + Extention of file to open (eg. c:\subdir\file.bin)
// --> state ........... ATT_READ_WRITE, ATT_READ_ONLY, ATT_OPEN_SHARED, ATT_OPEN_NO_DIR, ATT_OPEN_DIR, ATT_CREATE, ATT_CREATE_ALWAYS
// function will return value < 0 in case of error, on the other hand a handle of value >= 0
  
// ------------------------------------------------------------------------------------------------
// void sigclib_fclose(long hdl);
// file close
// --> hdl ............. valid filehandle
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_fread(long hdl, void *dst, unsigned long length);
// read content from file
// --> hdl ............. valid filehandle
// --> dst ............. destination memory
// --> length .......... length to read from file in bytes
// <-- function will return number of bytes to read
  
// ------------------------------------------------------------------------------------------------
// char *sigclib_fgets(long hdl, char *s, unsigned long size);
// read stream from file till <LF> or <EOF> occures, <CR> will be ignored
// --> hdl ............. valid filehandle
// --> s ............... destination memory
// --> size ............ bytesize of destination memory
// <-- function will return pointer to destination memory
// NOTE: destination will always be terminated by 0 (ascii-0-string)

// ------------------------------------------------------------------------------------------------
// char *sigclib_fputs(long hdl, const char *s);
// write ascii-0-string into file
// --> hdl ............. valid filehandle
// --> s ............... string to write
// <-- function will return amount of written bytes

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_fwrite(long hdl, void *src, unsigned long length);
// write data into file
// --> hdl ............. valid filehandle
// --> src ............. data to write
// --> length .......... amount of data to write in bytes
// <-- function will return amount of written bytes
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_fseek(long hdl, long offset, unsigned long fromwhere);
// set position of filepointer
// --> hdl ............. valid filehandle
// --> offset .......... offset in bytes
// --> fromwhere ....... FILE_BEGIN 0, FILE_CURRENT 1, FILE_END 2
  
// ------------------------------------------------------------------------------------------------
// long sigclib_ftell(long hdl);
// get position of filepointer
// --> hdl ............. valid filehandle
// <-- function will return offset of filepointer regarding to first byte in file
  
// ------------------------------------------------------------------------------------------------
// long sigclib_flength(long hdl);
// get length of file
// --> hdl ............. valid filehandle
// <-- function will return bytesize of file  
  
// ------------------------------------------------------------------------------------------------
// long sigclib_remove(char *dpne);
// remove file
// --> dpne ............ Drive, Path, Name + Extention of file to open (eg. c:\subdir\file.bin)
// <-- function will return value <0 on error

// ------------------------------------------------------------------------------------------------
// long sigclib_rename(char* oldname, char* newname);
// rename file  
// --> oldname ......... existiong Drive, Path, Name + Extention of file to open (eg. c:\subdir\file.bin)
// --> newname ......... existiong Drive, Path, Name + Extention of file to open (eg. c:\subdir\newfile.bin)
// <-- function will return value <0 on error
  
// ------------------------------------------------------------------------------------------------
// long sigclib_findfirst(char *namepattern, unsigned char attr0, unsigned char attrmask, _DDE_INFO *fileinfo, char *filename, unsigned long maxlength);
// findfirst
// <-- function will return valid handle or <0 on error
  
// ------------------------------------------------------------------------------------------------
// long sigclib_findnext(long hdl, _DDE_INFO *fileinfo, char *filename, unsigned long maxlength);
// findnext
// --> hdl ............. valid handle
// --> fileinfo ........
// --> filename ........
// --> maxlength .......
// <-- 
  
// ------------------------------------------------------------------------------------------------
// long sigclib_findclose(long hdl);
// findclose
// --> hdl ............. valid handle

// Example:
//   hdl := sigclib_findfirst("c:\*.*", 0, 0, #dde, #name[0], 128);
//   repeat
//     if(dde.Attributes AND ATT_DIR) then
//       todo:
//     end_if;
//   until(sigclib_findnext(hdl, #dde, #name[0], 128) <> 0) end_repeat;
//   sigclib_findclose(hdl);

    
// ------------------------------------------------------------------------------------------------
// long sigclib_mkdir(const char *path);
// create new directory
// --> path ............ path with subdir to create
// <-- function will return 0 on success or negative errorcode

// ------------------------------------------------------------------------------------------------
// long sigclib_rmdir(const char *path);
// remove existiong directory
// --> path ............ path with subdir to remove
// <-- function return 0 on success or negative errorcode
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_filecreate(const char *dpne, void *ptr, unsigned long size);
// create new file 'dpne' with content 'data' of length 'size'
// --> dpne ............ Drive, Path, Name + Extention of file to create (eg. c:\subdir\file.bin)
// --> ptr ............. data to Write
// --> size ............ amount of data in bytes
// <-- function will return 1 on success, or 0 if error occured

// ------------------------------------------------------------------------------------------------
// void *sigclib_fileread(unsigned long *psize, const char *dpne);
// get content of already existing file
// --> psize ........... address of variable where size of adressed file should be captured
// --> dpne ............ Drive, Path, Name + Extention of file to read (eg. c:\subdir\file.bin)
// <-- function will return pointer to allocated memory including filecontent, or NULL on error
// NOTE: Do not forget to use sigclib_free() to free allocated memory after usage

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_drivelist(char *dst);
// determine all drives that are currently available
// --> dst ............. array with minimum 27 cells of char
// <-- function will return number of currently available drives, each driveletter will be stored in given array.

// ------------------------------------------------------------------------------------------------
// void *sigclib_cfopen(const char *dpne, unsigned long state);
// void *sigclib_cfopenex(const char *dpne, unsigned long state, unsigned long writesize);
// open existing or create new file, use ram-cache of fildata when requested
// --> dpne ............ drive + path + name + extention of file to open
// --> state ........... attribute
//                       use state 'r', 'R' to open existing file
//                       use state 'w', 'W' to create new file, existing file will be dumped
//                       when use state 'R' or 'W' filedata will be cached in ram for faster sequential read or write
// --> writesize ....... estimated size of ram-cache (just when using function sigclib_cfopenex)
// <-- function will return a valid handle or NULL in case of error
      
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfclose(void *hdl);
// close file opend with function sigclib_cfopen  
// --> hdl ............. handle or NULL
// <-- function will return 1 on success, on the other hand 0
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfread(void *hdl, void *dst, unsigned long bytesize);
// read data from file
// --> hdl ............. handle or NULL
// --> dst ............. destination memory
// --> bytesize ........ number of bytes to read
// <-- function will return number of bytes to read or 0 in case of error
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfwrite(void *hdl, const void *src, unsigned long bytesize);
// write data into file
// --> hdl ............. handle or NULL
// --> src ............. data to write
// --> bytesize ........ amount of data to write in bytes
// <-- function will return amount of written bytes or 0 in case of error
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfseek(void *hdl, long offset, unsigned long fromwhere);
// set position of filepointer
// --> hdl ............. valid filehandle
// --> offset .......... offset in bytes
// --> fromwhere ....... FILE_BEGIN 0, FILE_CURRENT 1, FILE_END 2
// <-- function will return 1 or 0 in case of error
    
// ------------------------------------------------------------------------------------------------
// long sigclib_cftell(void *hdl);
// get position of filepointer
// --> hdl ............. valid filehandle
// <-- function will return offset of filepointer regarding to first byte in file or a negative value on error
    
// ------------------------------------------------------------------------------------------------
// char *sigclib_cfgets(void *hdl, char *s, unsigned long size);
// read stream from file till LF or EOF occures, CR will be ignored
// --> hdl ............. handle or NULL
// --> s ............... memorylocation where stream should be stored
// --> size ............ bytesize of memorylocation
// <-- function will return pointer to given memorilocation or NULL on error
   
// ------------------------------------------------------------------------------------------------
// char *sigclib_cfputs(void *hdl, const char *s);
// write ascii-0-string into file
// --> hdl ............. valid filehandle
// --> s ............... string to write
// <-- function will return amount of written bytes
   
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfmemory(void *hdl, void **pptr, unsigned long bytesize);
// memoryoperation in combination to handle
// --> hdl ............. handle or NULL
// --> pptr ............ pointer to pointer
// --> bytesize ........ bytesize to alloc, realloc free
// <-- function will return <>0 on success, on the other hand 0

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfok(void *hdl);
// ask if handle is ok
// --> hdl ............. handle or NULL
// <-- function will return <>0 when handle is ok, on the other hand 0 
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cferror_set(void *hdl, unsigned long val);
// set errorcode in internal structure
// --> hdl ............. handle or NULL
// --> val ............. errornumber to set
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cferror_get(void *hdl);
// get errorcode
// --> hdl ............. handle or NULL
// <-- function will return errorcode, 0=everything is ok    
    
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfversion_set(void* hdl, unsigned long version);
// set userspecific versionnumber in internal datastructure
// --> hdl ............. handle or NULL
// --> version ......... versionnumber to set
// <-- function will return <>0 when version is set to internal data, on the other hand 0 

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfversion_get(void* hdl);
// get userspecific version from internal datastructure
// --> hdl ............. handle or NULL
// <-- function will return userspecific versionnumber, set by function sigclib_cfversion_set()

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_cfcookie_set(void* hdl, void *pcookie);
// set userspecific cookie in internal datastructure
// --> hdl ............. handle or NULL
// --> pcookie ......... cookie to set
// <-- function will return <>0 when cookie is set to internal data, on the other hand 0 

// ------------------------------------------------------------------------------------------------
// void *sigclib_cfcookie_get(void* hdl);
// get userspecific cookie from internal datastructure
// --> hdl ............. handle or NULL
// <-- function will return userspecific cookie, set by function sigclib_cfcookie_set()

