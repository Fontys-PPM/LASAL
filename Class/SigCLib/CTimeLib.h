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
        int tm_year;  // years since 1900
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
    cExtern unsigned long sigclib_strftime(char* s, unsigned long maxsize, char* format, sigclib_tm* tm);
  
    // format date and/or time to string
    cExtern unsigned long sigclib_strfdatetime(char* s, unsigned long maxsize, const char* format, SYSDATE *pdat, SYSTIME *ptim);
  
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

    // split given lasal-time into hour, minute and seconds
    // function will return 1 when given timestamp is valid, on the other hand 0
    cExtern unsigned long sigclib_lasal_to_time(unsigned long *phour, unsigned long *pminute, unsigned long *psecond, unsigned long ltime);

    // create lasal-timestamp from given hour, minute and second
    cExtern unsigned long sigclib_time_to_lasal(unsigned long hour, unsigned long minute, unsigned long second);

    // create lasal-datestamp from given year, month and day
    cExtern unsigned long sigclib_date_to_lasal(unsigned long year, unsigned long month, unsigned long day);

    // returns number of days in given month includeing year
    cExtern unsigned long sigclib_get_days_of_month(unsigned long year, unsigned long month);

    // function will compute number of days from 1.januar to given date
    cExtern unsigned long sigclib_days_since_01_jan(unsigned long year, unsigned long month, unsigned long day);

    // function will compute year, month and day from given number of days
    cExtern void sigclib_make_date(unsigned long *pyear, unsigned long *pmonth, unsigned long *pday, unsigned long days);
  
    // function will check if given year is leapyear
    cExtern unsigned long sigclib_leap_year(unsigned long year);

    // function will compute calendarweek of given date (ISO 8601)
    cExtern unsigned long sigclib_calendar_week(unsigned long year, unsigned long month, unsigned long day);
  
    // function will "sleep" for given milliseconds
    cExtern void sigclib_waste(unsigned long millisec);
  
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
    function global __cdecl sigclib_strftime var_input dst0:^char; maxsize:udint; format:^char; tm:^sigclib_tm; end_var var_output retcode:dint; end_var;

    // format date and/or time to string
    function global __cdecl sigclib_strfdatetime var_input dst0:^char; maxsize:udint; format:^char; pdat:^SYSDATE; ptim:^SYSTIME; end_var var_output retcode:udint; end_var;

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

    // split given lasal-time into hour, minute and seconds
    // function will return 1 when given timestamp is valid, on the other hand 0
    function global __cdecl sigclib_lasal_to_time var_input phour:^udint; pminute:^udint; psecond:^udint; ltime:udint; end_var var_output retcode:udint; end_var;

    // create lasal-timestamp from given hour, minute and second
    function global __cdecl sigclib_time_to_lasal var_input hour:udint; minute:udint; second:udint; end_var var_output retcode:udint; end_var;

    // create lasal-datestamp from given year, month and day
    function global __cdecl sigclib_date_to_lasal var_input year:udint; month:udint; day:udint; end_var var_output retcode:udint; end_var;

    // returns number of days in given month includeing year
    function global __cdecl sigclib_get_days_of_month var_input year:udint; month:udint; end_var var_output retcode:udint; end_var;

    // function will compute number of days from 1.januar to given date
    function global __cdecl sigclib_days_since_01_jan var_input year:udint; month:udint; day:udint; end_var var_output retcode:udint; end_var;

    // function will compute year, month and day from given number of days
    function global __cdecl sigclib_make_date var_input pyear:^udint; pmonth:^udint; pday:^udint; days:udint; end_var;

    // function will check if given year is leapyear
    function global __cdecl sigclib_leap_year var_input year:udint; end_var var_output retcode:udint; end_var;

    // function will compute calendarweek of given date (ISO 8601)
    function global __cdecl sigclib_calendar_week var_input year:udint; month:udint; day:udint; end_var var_output retcode:udint; end_var;

    // function will "sleep" for given milliseconds
    function global __cdecl sigclib_waste var_input millisec:udint; end_var;

  #endif
  
#endif


// ************************************************************************************************
// USAGE
// ************************************************************************************************

// ------------------------------------------------------------------------------------------------
// time_t sigclib_time(time_t *source);
// get unixtimestamp (seconds till 1.Jan.1970) of actual sysdate and systime
// --> source .......... address where timestamp should be captured or NULL
// <-- function will return unixtimestamp
  
// ------------------------------------------------------------------------------------------------
// sigclib_tm* sigclib_gmtime(time_t *timet);
// get date and time from given unixtimestamp
// --> timet ........... addrsee of unixtimestamp 
// <-- function will return pointer to struct sigclib_tm where date an time will be captured
  
// ------------------------------------------------------------------------------------------------
// time_t sigclib_timegm(sigclib_tm *tm);
// get unixtimestamp from given date and time
// --> tm .............. pointer to date an time
// <-- function will return unixtimestamp from given date/time

// ------------------------------------------------------------------------------------------------
// time_t sigclib_mktime(sigclib_tm *tm);
// check tm and return unixtimestamp (if tm is not correct, tm will be corrected and -1 is returned)
  
// ------------------------------------------------------------------------------------------------
// long sigclib_ftime(sigclib_timeb *tb);
// fill given structure with actual unixtimestamp
  
// ------------------------------------------------------------------------------------------------
// void sigclib_srand(unsigned long seed);
// function to seed sigclib_rand()
  
// ------------------------------------------------------------------------------------------------
// long sigclib_rand(void);
// get pseudorandomvalue (0-32767), use sigclib_srand() to seed random.
// <-- function will return pseudorandomvalue
// NOTE: each time when using same seed you'll get same chronologic pseudorandomvalues
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_random(unsigned long max);
// get randomvalue from (0 to max-1)
// --> max ............. range of random values to create
// <-- function will return Randomvalue from 0 to max-1
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_tabsolute(void);
// <-- function will return tabsolute in milliseconds (same like ops.tAbsolute in ST)
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_getmicrotime(void);
// <-- function will return uptime in microseconds
    
// ------------------------------------------------------------------------------------------------
// void sigclib_getsystime(SYSTIME *ptime);
// get systemtime
// --> ptime ........... pointer to structure to fill

// ------------------------------------------------------------------------------------------------
// void sigclib_getsysdate(SYSDATE *pdate);
// get systemdate
// --> pdate ........... pointer to structure to fill
  
// ------------------------------------------------------------------------------------------------
// void sigclib_setsystime(SYSTIME *ptime);
// set systime
// --> ptime ........... pointer to structure including time to set
    
// ------------------------------------------------------------------------------------------------
// void sigclib_setsysdate(SYSDATE *pdate);
// set sysdate
// --> pdate ........... pointer to structure including date to set
 
// ------------------------------------------------------------------------------------------------
// char *sigclib_string_to_time(unsigned long *time, const char *text);
// format string to time (ascii-0-string)
// following characters are valid separator [SPACE],[:],[.],[-] and caseinsensitive sequences of "am" and "pm"
// --> time ............ adress where timestamp (lasal-time) should be captured
// --> text ............ pointer to string to encode
// <-- function will return pointer to first character which is not used to encode string

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_absday(unsigned long year, unsigned long month, unsigned long day);
// compute absolut number of days from given date
// --> year ............ year (1-2999)
// --> month ........... month (1-12)
// --> day ............. day (1-31)
// <-- function will return absolut number of days

// ------------------------------------------------------------------------------------------------
// void sigclib_make_date(unsigned long *pyear, unsigned long *pmonth, unsigned long *pday, unsigned long days);
// function will compute year, month and day from given absolut number of days
// --> pyear ........... address to capture year
// --> pmonth .......... address to capture month
// --> pday ............ address to capture day
// --> days ............ given absolut number of days

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_day_of_week(unsigned long year, unsigned long month, unsigned long day);
// compute weekday from given date 0..su, 1..mo, 2..tu, 3..we, 4..th, 5..fr, 6..sa
// --> year ............ year (1-2999)
// --> month ........... month (1-12)
// --> day ............. day (1-31)
// <-- function will return indicator of weekday (0..sunday, 1..monday, ...) 

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_lasal_to_date(unsigned long *pyear, unsigned long *pmonth, unsigned long *pday, unsigned long ldate);
// split given lasal-date into year, month and day
// --> pyear ........... address to capture year
// --> pmonth .......... address to capture month
// --> pday ............ address to capture day
// --> ldate ........... lasal-datestamp
// <-- function will return 1 when given datestamp is valid, on the other hand 0

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_lasal_to_time(unsigned long *phour, unsigned long *pminute, unsigned long *psecond, unsigned long ltime);
// split given lasal-time into hour, minute and seconds
// --> phour ........... address to capture hour
// --> pminute ......... address to capture minute
// --> psecond ......... address to capture second
// --> ltime ........... lasal-timestamp
// function will return 1 when given timestamp is valid, on the other hand 0

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_time_to_lasal(unsigned long hour, unsigned long minute, unsigned long second);
// create lasal-timestamp from given hour, minute and second
// --> hour ............ hour (0-23)
// --> minute .......... minute (0-59)
// --> second .......... second (0-59)
// <-- function will return lasal-timestamp

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_date_to_lasal(unsigned long year, unsigned long month, unsigned long day);
// create lasal-datestamp from given year, month and day
// --> year ............ year (1-2999)
// --> month ........... month (1-12)
// --> day ............. day (1-31)
// <-- function will return lasal-datestamp from given year, month and day

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_get_days_of_month(unsigned long year, unsigned long month);
// returns number of days in given month including year
// --> year ............ year (1-2999)
// --> month ........... month (1-12)
// <-- function will return number of days regarding to month and year
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_leap_year(unsigned long year);
// function will check if given year is leap year
// --> year ............ given year to check
// <-- function will return 1 in case of leap year, on the other hand 0
  
// ------------------------------------------------------------------------------------------------
// void sigclib_waste(unsigned long millisec);
// function will "sleep" for given milliseconds
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_days_since_01_jan(unsigned long year, unsigned long month, unsigned long day);
// function will compute number of days from 1.januar to given date
// --> year ............ year (2-2999)
// --> month ........... month (1-12)
// --> day ............. day (1-31)
// <-- function will return days since 1.1 in same year
// NOTE: if you will feed function with 1st Jan   2016 you will get 0
//                                      1st Feb   2016 you will get 31
//                                      1st March 2016 you will get 60 (leap year, 31+29)
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_calendar_week(unsigned long year, unsigned long month, unsigned long day);
// function will compute calendar week of given date (ISO 8601)
// --> year ............ year (2-2999)
// --> month ........... month (1-12)
// --> day ............. day (1-31)
// <-- function will return calendarweek (1-53)  
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_strftime(char* s, unsigned long maxsize, char* format, sigclib_tm* tm);
// format sigclib_tm to string
// NOTE: do not use because of "Year 2038 problem" of unixtimestamp
// for details see function sigclib_strfdatetime()
  
// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_strfdatetime(char* s, unsigned long maxsize, const char* format, SYSDATE *pdat, SYSTIME *ptim);
// format date and/or time to string
// --> s ............... destination
// --> maxsize ......... bytesize of destination
// --> format .......... format of destination or NULL (in case of NULL, default "%@" will be of use)
// --> pdat ............ date or NULL (in case of NULL, actual date will be of use)
// --> ptim ............ time or NULL (in case of NULL, actual time will be of use)
// <-- function will return total number of characters in destination, excluding termination null-character. (same like sigclib_strlen() will give)
// use function sigclib_getsysdate() and sigclib_getsystime() to get actual date and time
// following format is valid (eg. format of "%F %T" will lead to "2014-04-02 02:50:06")
//     %% .......... insert %  
//     %y .......... Year, last two digits (00-99) (01, ...)
//     %Y .......... Year full (2012)
//     %C .......... Year divided by 100 (Century) and truncated to integer (19, 20, ...)
//     %B .......... Month name full (March, ...)
//     %b, %h ...... Month name abbreviated (Mar, ...)
//     %m .......... Month as a decimal number (01-12) (08, ...)
//     %d .......... Day of month, zero padded representation (01-31) (01,02,19, ...)
//     %e .......... Day of month, space padded representation ( 1-31) ( 1, 2,19, ...)
//     %j .......... Day of the year (001-366) (231, ...)
//     %@ .......... Date and Time representation (2014-08-31 17:25:33), equivalent to "%Y-%m-%d %H:%M:%S"
//     %c .......... Date and Time representation (Sun Aug 19 02:56:02 2012)
//     %x, %D ...... Date representation (08/19/12)
//     %F .......... Date representation (2014-04-02), equivalent to "%Y-%m-%d"
//     %V .......... Calendar week number (ISO 8601) (01-53) (34, ...)
//     %a .......... Weekday name abbreviated (Sun, Mon, Thu...)
//     %A .......... Weekday name full (Sunday, ...)
//     %u .......... Weekday as a decimal number with Monday as 1, Sunday as 7 (1-7) (4, ...)
//     %w .......... Weekday as a decimal number with Sunday as 0, Monday as 1, ... (0-6) (4, ...)
//     %H .......... Hour in 24h format (00-23) (14, ...)
//     %I .......... Hour in 12h format (01-12) (05, ...)
//     %M .......... Minute (00-59) (55, ...)
//     %S .......... Second (00-59) (02, ...)
//     %R .......... Time: 24-hour HH:MM time, equivalent to "%H:%M"
//     %r .......... Time: 12-hour clock (10:55:32 pm)
//     %T, %X ...... Time representation (02:50:06), equivalent to "%H:%M:%S"
//     %p .......... AM or PM designation (PM, AM)
//     %Z .......... Timezone name or abbreviation (CDT)
//     %n .......... new-line character '\n'
//     %t .......... Horizontal-tab character '\t'
//     NOTE: some zeros inbetween any format (eg. %00A, %02A) will give number of digits (eg. "%A"="Sunday", "%00A"="Su", "%04A"="Sund")
           

