#ifndef _CTimeLibH
  #define _CTimeLibH

  #include "DefineCompiler.h"

  #ifdef cCompile
    #include "lsl_c_ifssr.h"
//    #include "RTOS_C_interfaces.h"
//    #include "file_iotypes.h"

    #pragma pack (push, 1) 
      typedef long time_t;
      typedef struct
      {
        int tm_sec;   // 0-59
        int tm_min;   // 0-59
        int tm_hour;  // 0-23
        int tm_mday;  // 1-31
        int tm_mon;   // 0-11
        int tm_year;  // years since 1970
        int tm_wday;  // days since sunday, 0..sunday, 1..monday
        int tm_yday;  // 0-366
        int tm_isdst; // daylight saving flag
      }
      sigclib_tm;
  
      typedef struct
      {
        time_t         time;
        unsigned short millitm;
        short          timezone;
        short          dstflag;
      }
      sigclib_timeb;
    #pragma pack (pop)

    extern const unsigned long sigclib_crc32table[];

    // get unixtimestamp (seconds till 1.Jan.1970) of actual sysdate and systime
    cExtern time_t sigclib_time(time_t *source);
  
    // get date and time from given unixtimestamp
    cExtern sigclib_tm* sigclib_gmtime(time_t *timet);
  
    // get unixtimestamp from given date and time
    cExtern time_t sigclib_timegm(sigclib_tm *tm);

    // check tm and return unixtimestamp (if tm is not correct, tm will be corrected and -1 is returned)
    cExtern time_t sigclib_mktime(sigclib_tm *tm);
  
    // fill given structure with actual unixtimestamp
    cExtern long sigclib_ftime(sigclib_timeb *tb);
  
    // function to seed sigclib_rand()
    cExtern void sigclib_srand(unsigned long seed);
  
    // get pseudorandomvalue (0-32767), use sigclib_srand() to seed random.
    // each time when using same seed you'll get same chronologic pseudorandomvalues
    cExtern long sigclib_rand(void);
  
    // get randomvalue from (0 to max-1)
    cExtern unsigned long sigclib_random(unsigned long max);
  
    // get tabsolute in milliseconds
    cExtern unsigned long sigclib_tabsolute(void);
  
    // get uptime in microseconds
    cExtern unsigned long sigclib_getmicrotime(void);
    
    // get systemtime
    cExtern void sigclib_getsystime(SYSTIME *ptime);

    // get systemdate
    cExtern void sigclib_getsysdate(SYSDATE *pdate);
  
    // set systime
    cExtern void sigclib_setsystime(SYSTIME *ptime);
    
    // set sysdate
    cExtern void sigclib_setsysdate(SYSDATE *pdate);
  
    // format time to string
    cExtern unsigned long   sigclib_strftime(char* s, unsigned long maxsize, char* format, sigclib_tm* tm);
  
    // format string to time, 
    // function will return pointer to first character which is not used to encode string
    // following characters are valid separator [SPACE],[:],[.],[-] and caseinsensitive sequenzes of "am" and "pm"
    cExtern char *sigclib_string_to_time(unsigned long *time, const char *text);

    // compute number of days since 01.01.0001 from given date
    cExtern unsigned long sigclib_absday(unsigned long year, unsigned long month, unsigned long day);

    // compute weekday from given date 0..su, 1..mo, 2..tu, 3..we, 4..th, 5..fr, 6..sa
    cExtern unsigned long sigclib_day_of_week(unsigned long year, unsigned long month, unsigned long day);

    // split given lasal-date into year, month and day
    // function will return 1 when given datestamp is valid, on the other hand 0
    cExtern unsigned long sigclib_lasal_to_date(unsigned long *pyear, unsigned long *pmonth, unsigned long *pday, unsigned long ldate);

    // split given lasal-time into hout, minute and seconds
    // function will return 1 when given timestamp is valid, on the other hand 0
    cExtern unsigned long sigclib_lasal_to_time(unsigned long *phour, unsigned long *pminute, unsigned long *psecond, unsigned long ltime);

    // create lasal-timestamp from given hour, minute and second
    cExtern unsigned long sigclib_time_to_lasal(unsigned long hour, unsigned long minute, unsigned long second);

    // create lasal-datestamp from given year, month and day
    cExtern unsigned long sigclib_date_to_lasal(unsigned long year, unsigned long month, unsigned long day);

    // returns number of days in given month includeing year
    cExtern unsigned long sigclib_get_days_of_month(unsigned long year, unsigned long month);

    // function will compute year, month and day from given number of days
    cExtern void sigclib_make_date(unsigned long *pyear, unsigned long *pmonth, unsigned long *pday, unsigned long days);
  
  #else

    #include "lsl_st_ifssr.h"

    type
        time_t : dint;
      #pragma pack(push, 1)
        sigclib_tm : struct
          tm_sec   : dint;
          tm_min   : dint;
          tm_hour  : dint;
          tm_mday  : dint;
          tm_mon   : dint;
          tm_year  : dint; 
          tm_wday  : dint;
          tm_yday  : dint;
          tm_isdst : dint;
        end_struct;
        
        sigclib_timeb : struct
          b_time     : time_t;
          b_millitm  : uint;
          b_timezone : int;
          b_dstflag  : int;
        end_struct;
      #pragma pack(pop)      
    end_type


    // get unixtimestamp (seconds till 1.Jan.1970) of actual sysdate and systime
    function global __cdecl sigclib_time var_input pdst : ^time_t; end_var var_output retcode : time_t; end_var;
  
    // get date and time from given unixtimestamp
    function global __cdecl sigclib_gmtime var_input timet : ^time_t; end_var var_output retcode : ^sigclib_tm; end_var;
  
    // get unixtimestamp from given date and time
    function global __cdecl sigclib_timegm var_input tm : ^sigclib_tm; end_var var_output retcode : time_t; end_var;
  
    // check tm and return unixtimestamp (if tm is not correct, tm will be corrected and -1 is returned)
    function global __cdecl sigclib_mktime var_input tm : ^sigclib_tm; end_var var_output retcode : time_t; end_var;
  
    // fill given structure with actual unixtimestamp
    function global __cdecl sigclib_ftime var_input tb : ^sigclib_timeb; end_var var_output retcode : dint; end_var;
  
    // function to seed sigclib_rand()
    function global __cdecl sigclib_srand var_input seed : udint; end_var;
  
    // get pseudorandomvalue (0-32767), use sigclib_srand() to seed random.
    // each time when using same seed you'll get same chronologic pseudorandomvalues
    function global __cdecl sigclib_rand var_output retcode : dint; end_var;
  
    // get randomvalue from (0 to max-1)
    function global __cdecl sigclib_random var_input max : udint; end_var var_output retcode : udint; end_var;
  
    // get tabsolute in milliseconds
    function global __cdecl sigclib_tabsolute var_output retcode : udint; end_var;
  
    // get uptime in microseconds
    function global __cdecl sigclib_getmicrotime var_output retcode : udint; end_var;
    
    // get systemtime
    function global __cdecl sigclib_getsystime var_input ptime : ^SYSTIME; end_var;

    // get systemdate
    function global __cdecl sigclib_getsysdate var_input pdate : ^SYSDATE; end_var;

    // set systime
    function global __cdecl sigclib_setsystime var_input ptime : ^SYSTIME; end_var;
    
    // set sysdate
    function global __cdecl sigclib_setsysdate var_input pdate : ^SYSDATE; end_var;

    // format time to string
    function global __cdecl sigclib_strftime var_input dst0 : ^char; maxsize : udint; format : ^char; tm : ^void; end_var var_output retcode : dint; end_var;

    // format string to time, 
    // function will return pointer to first character which is not used to encode string
    // following characters are valid separator [SPACE],[:],[.],[-] and caseinsensitive sequenzes of "am" and "pm"
    function global __cdecl sigclib_string_to_time var_input ptime:^udint; text:^char; end_var var_output retcode:^char; end_var;

    // compute number of days since 01.01.0001 from given date
    function global __cdecl sigclib_absday var_input year:udint; month:udint; day:udint; end_var var_output retcode:udint; end_var;

    // compute weekday from given date 0..su, 1..mo, 2..tu, 3..we, 4..th, 5..fr, 6..sa
    function global __cdecl sigclib_day_of_week var_input year:udint; month:udint; day:udint; end_var var_output retcode:udint; end_var;

    // split given lasal-date into year, month and day
    // function will return 1 when given datestamp is valid, on the other hand 0
    function global __cdecl sigclib_lasal_to_date var_input pyear:^udint; pmonth:^udint; pday:^udint; ldate:udint; end_var var_output retcode:udint; end_var;

    // split given lasal-time into hout, minute and seconds
    // function will return 1 when given timestamp is valid, on the other hand 0
    function global __cdecl sigclib_lasal_to_time var_input phour:^udint; pminute:^udint; psecond:^udint; ltime:udint; end_var var_output retcode:udint; end_var;

    // create lasal-timestamp from given hour, minute and second
    function global __cdecl sigclib_time_to_lasal var_input hour:udint; minute:udint; second:udint; end_var var_output retcode:udint; end_var;

    // create lasal-datestamp from given year, month and day
    function global __cdecl sigclib_date_to_lasal var_input year:udint; month:udint; day:udint; end_var var_output retcode:udint; end_var;

    // returns number of days in given month includeing year
    function global __cdecl sigclib_get_days_of_month var_input year:udint; month:udint; end_var var_output retcode:udint; end_var;

    // function will compute year, month and day from given number of days
    function global __cdecl sigclib_make_date var_input pyear:^udint; pmonth:^udint; pday:^udint; days:udint; end_var;

  #endif

  
#endif
