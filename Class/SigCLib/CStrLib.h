#ifndef _CStrLibH
 #define _CStrLibH

  #include "DefineCompiler.h"

  #ifdef cCompile
  
    #define sigclib_printf(...) { char __tmp[512]; sigclib_sprintf(__tmp, __VA_ARGS__); sigclib_trace(__FILE__, __tmp); }
    #define sigclib_fprintf(__hdl, ...) { char __tmp[512]; sigclib_sprintf(__tmp, __VA_ARGS__); sigclib_fwrite(__hdl, __tmp, sigclib_strlen(__tmp)); }
  
    cExtern char*           sigclib_strcpy(char* dst0, const char* src0);
    cExtern unsigned long   sigclib_strlen(const char* str);
    cExtern char*           sigclib_strcat(char* s1, const char* s2);
    cExtern char*           sigclib_strchr(const char* s1, int i);
    cExtern char*           sigclib_strcpytill(char *dst, char *src, char tillchr);
    cExtern int             sigclib_isdigit(int c);
    cExtern int             sigclib_islower(int c);
    cExtern int             sigclib_isupper(int c);
    cExtern char            sigclib_tolower(int c);
    cExtern char            sigclib_toupper(int c);
    cExtern char*           sigclib_strupr(char *s);
    cExtern char*           sigclib_strlwr(char* s);
    cExtern int             sigclib_strcmp(const char *s1, const char *s2);
    cExtern int             sigclib_strncmp(const char* s1, const char* s2, unsigned long count);
    cExtern char*           sigclib_strncpy(char* dst0, const char* src0, unsigned long count);
    cExtern long            sigclib_strspn(const char* s1, const char* s2);
    cExtern long            sigclib_strcspn(const char* s1, const char* s2);
    cExtern char*           sigclib_strncat(char* s1, const char* s2, unsigned long len);
    cExtern char*           sigclib_strstr(const char* searchee, const char* lookfor);
    cExtern int             sigclib_stricmp(const char *s1, const char *s2);
    cExtern char*           sigclib_strpbrk(const char *s1, const char *s2);
    cExtern char*           sigclib_strrchr(const char *s, int chr);
    cExtern int             sigclib_atoi(const char* s);
    cExtern long            sigclib_atol(const char* s);
    cExtern long long       sigclib_atoll(const char* s);
    cExtern float           sigclib_atof(const char* s);
    cExtern unsigned long   sigclib_atou(const char* s);
    cExtern void            sigclib_atof_ST(float *presult, const char* s);
    cExtern char*           sigclib_itoa(int val, char* s, int base);
     extern char*           sigclib_ftoa(float value, char *result, unsigned long digits);
    cExtern char*           sigclib_ftoa_ST(float *pvalue, char *result, unsigned long digits);
     extern char*           sigclib_ftoa_comma(float value, char *result, unsigned long digits, char comma);
    cExtern char*           sigclib_ftoa_comma_ST(float *pvalue, char *result, unsigned long digits, char comma);
    cExtern char*           sigclib_dtoa(char *dst, double value, unsigned long digits);
    cExtern char*           sigclib_htoa(char *dst, unsigned long value);
    cExtern char*           sigclib_htoa_ex(char *dst, unsigned long value);
    cExtern char*           sigclib_utoa(char *dst, unsigned long value);
    cExtern void*           sigclib_memset(void *dst, long c, unsigned long len);
    cExtern void*           sigclib_memcpy(void* dst0, const void* src0, unsigned long len0);
    cExtern void*           sigclib_memmove(void* dst0, const void* src0, unsigned long len0);
    cExtern int             sigclib_memcmp(const void* m1, const void* m2, unsigned long len);
    cExtern void*           sigclib_memchr(void* src_void, int c, unsigned long length);
    cExtern int             sigclib_memicmp(const void* s1, const void* s2, unsigned long length);
    cExtern long            sigclib_strtol(const char* nptr, char** endptr, int base);
    cExtern unsigned long   sigclib_strtoul(const char* nptr, char** endptr, int base);
    cExtern float           sigclib_strtof(const char* source, char** end);
    cExtern double          sigclib_strtod(const char* source, char** end);
    cExtern int             sigclib_strcasecmp(const char* s1, const char* s2);
    cExtern int             sigclib_strncasecmp(const char* s1, const char* s2, unsigned long count);
    cExtern char*           sigclib_inet_ntoa(char *dst, unsigned long in4);
    cExtern unsigned long   sigclib_inet_addr(char* src);
    cExtern void            sigclib_tracemessage(char *txt);
    cExtern void            sigclib_trace(const char *filename, const char *text);
    cExtern char*           sigclib_mutex_name(char *dst, const char *label, void *pthis);
    cExtern double          sigclib64_atof(const char *txt);

  #else
  
    function global __cdecl sigclib_strcpy var_input dst0 : ^char; src0 : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strlen var_input str : ^char; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_strcat var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strchr var_input ps1 : ^char; i : dint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strcpytill var_input dst:^char; src:^char; chrtill:char; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_isdigit var_input c : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_islower var_input c : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_isupper var_input c : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_tolower var_input c : dint; end_var var_output retcode : char; end_var;
    function global __cdecl sigclib_toupper var_input c : dint; end_var var_output retcode : char; end_var;
    function global __cdecl sigclib_strupr var_input s : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strlwr var_input s : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strcmp var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncmp var_input ps1 : ^char; ps2 : ^char; count : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncpy var_input dst0 : ^char; src0 : ^char; count : udint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strspn var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strcspn var_input ps1:^char; ps2:^char; end_var var_output retcode:dint; end_var;
    function global __cdecl sigclib_strncat var_input ps1 : ^char; ps2 : ^char; len : udint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strstr var_input searchee : ^char; lookfor : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_stricmp var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strpbrk var_input ps1 : ^char; ps2 : ^char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_strrchr var_input ps1 : ^char; chr : dint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_atoi var_input s : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_atou var_input s : ^char; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_itoa var_input val : dint; dst : ^char; base : dint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_ftoa_ST var_input pval : ^real; dst : ^char; digits : udint; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_ftoa_comma_ST var_input pval : ^real; dst : ^char; digits : udint; comma : char; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_atol var_input s : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_atof_ST var_input retval : ^real; s : ^char; end_var;
    function global __cdecl sigclib_dtoa var_input txt:^char; value:lreal; no:udint; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_htoa var_input txt:^char; value:udint; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_htoa_ex var_input txt:^char; value:udint; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_utoa var_input dst:^char; value:udint; end_var var_output retcode:^char; end_var;
    function global __cdecl sigclib_memset var_input dst : ^void; c : dint; len : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memcpy var_input dst0 : ^void; src0 : ^void; len0 : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memmove var_input dst0 : ^void; src0 : ^void; len0 : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memcmp var_input m1 : ^void; m2 : ^void; len : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_memchr var_input src : ^void; c : dint; length : udint; end_var var_output retcode : ^void; end_var;
    function global __cdecl sigclib_memicmp var_input ps1 : ^void; ps2 : ^void; length : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strtol var_input nptr : ^char; endptr : ^pvoid; base : dint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strtoul var_input nptr : ^char; endptr : ^pvoid; base : dint; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_strtod var_input nptr : ^char; endptr : ^pvoid; end_var var_output retcode : lreal; end_var;
    function global __cdecl sigclib_strtof_ST var_input nptr : ^char; endptr : ^pvoid; end_var var_output retcode : real; end_var;
    function global __cdecl sigclib_strcasecmp var_input stest1 : ^char; stest2 : ^char; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_strncasecmp var_input stest1 : ^char; stest2 : ^char; count : udint; end_var var_output retcode : dint; end_var;
    function global __cdecl sigclib_inet_ntoa var_input dst:^char; in4:udint; end_var var_output retcode : ^char; end_var; 
    function global __cdecl sigclib_inet_addr var_input src:^char; end_var var_output retcode : udint; end_var;
    function global __cdecl sigclib_mutex_name var_input dst:^char; label:^char; pthis:^void; end_var var_output retcode : ^char; end_var;
    function global __cdecl sigclib_tracemessage var_input text:^char; end_var;
    function global __cdecl sigclib_trace var_input filename:^char; text:^char; end_var;
    
    function global __cdecl sigclib_sprintfST
      var_input
        pd     : ^char;
        format : ^char;
        p0 : ^void := NIL;
        p1 : ^void := NIL;
        p2 : ^void := NIL;
        p3 : ^void := NIL;
        p4 : ^void := NIL;
        p5 : ^void := NIL;
        p6 : ^void := NIL;
        p7 : ^void := NIL;
        p8 : ^void := NIL;
        p9 : ^void := NIL;
      end_var
      var_output
        retcode : udint;
      end_var;
  
  #endif
 
#endif

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// interesting information:
// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// char* sigclib_strcpy(char* dst0, char* src0) ---------------------------------------------------
// Copies the ascii-0-terminated string pointed by src0 into the array pointed by dst0, including the terminating 0 character.
// NOTE: To avoid overflows, the size of the dst0 array shall be long enough to contain the same string as src0 and should not 
//       overlap in memory with src0.

// Parameters:
// --> dst0 ..... Pointer to the destination array where the content is to be copied. 
// --> src0 ..... string to be copied. 
// function returns dst0 


// ------------------------------------------------------------------------------------------------
// udint sigclib_strlen(char* str) ----------------------------------------------------------------
// Function returns the length of given ascii-0-terminated string
// The length of a string is determined by the terminating 0-character. 
// A string is as long as the amount of characters between the beginning of the string and the terminating null character.
// NOTE: This should not be confused with the size of the array that holds the string.

// Parameters:
// --> str ...... string. 


// ------------------------------------------------------------------------------------------------
// char* sigclib_strcat(char* s1, char* s2) -------------------------------------------------------
// function will concatenate strings.
// Appends a copy of the s2 string to the s1 string. The terminating 0-character in s1 is overwritten by the first character of s2, 
// and a new null-character is appended at the end of the new string formed by the concatenation of both in destination.

// Parameters:
// --> s1 ...... Pointer to the destination array, which is large enough to contain the concatenated resulting string.
// --> s2 ...... string to be appended. This should not overlap s1. 
// function will return s1


// ------------------------------------------------------------------------------------------------
// char* sigclib_strchr(const char* s1, dint i) ---------------------------------------------------
// Function will Locate first occurrence of character in string
// Returns a pointer to the first occurrence of character i in the s1 str.
// The terminating 0-character is considered part of the string. Therefore, it can also be located to retrieve a pointer to the end of a string.

// Parameters:
// --> s1 ...... string
// --> i	...... Character to be located 
// function will return a pointer to the first occurrence of character in str.
// NOTE: If the value is not found, the function returns a null pointer.


// ------------------------------------------------------------------------------------------------
// char* sigclib_strcpytill(char* dst, char* src, char tillchr) -----------------------------------
// Copies all characters from src into dst till first occurance of 'tillchr'

// Parameters:
// --> dst ...... Pointer to the destination array where the content is to be copied. 
// --> src ...... string to be performed. 
// --> tillchr .. character to stop at
// function returns pointer to first characeter right after found 'tillchr' or NULL if 'tillchr' was not found
// NOTE: If 'tillchr' was not found whole content of src will be copied into dst;


// ------------------------------------------------------------------------------------------------
// int sigclib_strcmp(char *s1, char *s2) ---------------------------------------------------------
// Compares the string s1 to the string s2.
// This function starts comparing the first character of each string. If they are equal to each other, it continues 
// with the following pairs until the characters differ or until a terminating 0-character is reached.

// Parameters:
// --> s1	....... string to be compared. 
// --> s2	....... string to be compared. 

// Return Value:
// A zero value indicates that both strings are equal.
// A value greater than zero indicates that the first character that does not match has a greater value in s1 than in s2.
// A value less than zero indicates the opposite.


// ------------------------------------------------------------------------------------------------
// int sigclib_strcasecmp(char *s1, char *s2) -----------------------------------------------------
// int sigclib_stricmp(char *s1, char *s2) --------------------------------------------------------
// Case insensitive compare of string s1 and string s2.
// This function starts casinsensitive comparing the first character of each string. If they are equal to each other, it continues 
// with the following pairs until the characters differ or until a terminating 0-character is reached.

// Parameters:
// --> s1	....... string to be compared.
// --> s2	....... string to be compared.

// Return Value:
// A zero value indicates that both strings are caseinsensitive equal.
// A value greater than zero indicates that the first character that does not match has a greater value in s1 than in s2.
// A value less than zero indicates the opposite.


// ------------------------------------------------------------------------------------------------
// dint sigclib_strncmp(char* s1, char* s2, udint count) ------------------------------------------
// Compare characters of two strings
// Compares up to count characters of the string s1 to those of the string s2.
// This function starts comparing the first character of each string. If they are equal to each other, it continues with the 
// following pairs until the characters differ, until a terminating 0-character is reached, or until num characters match in both strings,
// whichever happens first.

// Parameters:
// --> s1	....... string to be compared. 
// --> s2	....... string to be compared. 
// count	Maximum number of characters to compare. 

// Return Value:
// A zero value indicates that both strings are equal.
// A value greater than zero indicates that the first character that does not match has a greater value in s1 than in s2. A value less than 
// zero indicates the opposite.


// ------------------------------------------------------------------------------------------------
// char* sigclib_strncpy(char* dst0, char* src0, udint count) -------------------------------------
// Copy characters from string
// Copies the first count characters of src0 to dst0. If the end of the src0 string (which is signaled by a null-character) is found 
// before count characters have been copied, destination is padded 
// with zeros until a total of num characters have been written to it.

// No 0-character is implicitly appended to the end of dst0, so dst0 will only be null-terminated if the length of the string in src0 is 
// less than count.

// Parameters:
// --> dst0 ..... Pointer to the destination array where the content is to be copied. 
// --> src0 ..... string to be copied. 
// --> count .... Maximum number of characters to be copied from source. 

// Return Value:
// dst0


// ------------------------------------------------------------------------------------------------
// dint sigclib_strspn(char* s1, char* s2) --------------------------------------------------------
// Get span of character set in string
// Returns the length of the initial portion of s1 which consists only of characters that are part of s2.

// Parameters:
// --> s1 ....... string to be scanned. 
// --> s2 ....... string containing the characters to match. 

// Return Value:
// The length of the initial portion of s1 containing only characters that appear in s2.
// Therefore, if all of the characters in s1 are in s2, the function returns the length of the entire s1 string, and if the first
// character in s1 is not in s2, the function returns zero.

// ------------------------------------------------------------------------------------------------
// long sigclib_strcspn(char* s1, char* s2) -------------------------------------------------------
// Scans s1 for the first occurrence of any of the characters that are part of s2, returning the number of characters of s1 read before this first occurrence.
// Returns index of first occurance of any character in s2.

// Parameters:
// --> s1 ....... string to be scanned. 
// --> s2 ....... string containing the characters to match. 

// Return Value:
// The length of the initial part of str1 not containing any of the characters that are part of str2.
// This is the length of str1 if none of the characters in str2 are found in str1.

// ------------------------------------------------------------------------------------------------
// char* sigclib_strncat(char* s1, char* s2, udint len) -------------------------------------------
// Append characters from string
// Appends the first len characters of s2 to s1, plus a terminating null-character. If the length of the string in s2 is less than len,
// only the content up to the terminating null-character is copied.

// Parameters
// --> s1 ....... Pointer to the destination array which has to be large enough to contain the concatenated resulting string, including the additional null-character. 
// --> s2	....... string to be appended. 
// --> len ...... Maximum number of characters to be appended. 

// Return Value:
// s1


// ------------------------------------------------------------------------------------------------
// char* sigclib_strstr(char* searchee, char* lookfor) --------------------------------------------
// Locate substring
// Returns a pointer to the first occurrence of lookfor in serchee, or a null pointer if lookfor is not part of serchee.
// The matching process does not include the terminating null-characters.

// Parameters:
// --> serchee .. string to be scanned. 
// --> lookfor .. string containing the sequence of characters to match

// Return Value:
// A pointer to the first occurrence in serchee of any of the entire sequence of characters specified in lookfor, or a null pointer if the sequence is not present.


// ------------------------------------------------------------------------------------------------
// void* sigclib_memset(void *dst, dint c, udint len) ---------------------------------------------
// Fill block of memory
// Sets the first len bytes of the block of memory pointed by dst to the specified value c.

// Parameters:
// --> dst ...... pointer to the block of memory to fill. 
// --> c ........ Value to be set
// --> len ...... Number of bytes to be set 

// Return Value:
// dst

// ------------------------------------------------------------------------------------------------
// void* sigclib_memmove(void* dst0, void *src0, udint len0) --------------------------------------
// Move block of memory
// Copies the values of len0 bytes from the location pointed by src0 to the memory block pointed by dst0. Copying takes place as if an intermediate buffer were used, allowing the destination and 
// source to overlap. The function does not check for any terminating null character in source, it always copies exactly num bytes.

// Parameters:
// --> dst0 ..... Pointer to the destination array where the content is to be copied 
// --> src0 ..... Pointer to the source of data to be copied
// --> len0 ..... Number of bytes to copy. 

// Return Value:
// dst0

// ------------------------------------------------------------------------------------------------
// void* sigclib_memcpy(void* dst0, void* src0, udint len0) ---------------------------------------
// Copy block of memory
// Copies the values of len0 bytes from the location pointed by src0 directly to the memory block pointed by dst0.
// The function does not check for any terminating null character in src0, it always copies exactly len0 bytes.

// Parameters:
// --> dst0 ..... Pointer to the destination array where the content is to be copied. 
// --> src0 ..... Pointer to the source of data to be copied. 
// --> len0 ..... Number of bytes to copy. 

// Return Value:
// dst0

// ------------------------------------------------------------------------------------------------
// int sigclib_memcmp(void* m1, void* m2, udint len) ----------------------------------------------
// Compare two blocks of memory
// Compares the first len bytes of the block of memory pointed by m1 to the first len bytes pointed by m2, returning zero if they all match or a value different from zero representing which is greater 
// if they do not.

// Parameters:
// --> m1 ....... Pointer to block of memory. 
// --> m2 ....... Pointer to block of memory. 
// --> len ...... Number of bytes to compare. 

// Return Value:
// A zero value indicates that the contents of both memory blocks are equal.
// A value greater than zero indicates that the first byte that does not match in both memory blocks has a greater value in m1 than in m2. A value less than zero indicates the opposite.


// ------------------------------------------------------------------------------------------------
// int   sigclib_atoi(char* s) --------------------------------------------------------------------
// long  sigclib_atol(char* s) --------------------------------------------------------------------
// Convert string to value
// Parses the string s interpreting its content as a number, which is returned as value.
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus 
// sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either s is empty or it contains only whitespace characters, no 
// conversion is performed.

// Parameters:
// --> s ......... string containing the representation of a number. 

// Return Value:
// On success, the function returns the converted value.
// If no valid conversion could be performed, a zero value is returned.


// ------------------------------------------------------------------------------------------------
// char* sigclib_itoa(dint val, char* s, dint base) -----------------------------------------------
// Convert value to string
// Converts a value val into a null-terminated string using the specified base and stores the result in the array given by s parameter.
// If base is 10 and val is negative, the resulting string is preceded with a minus sign. With any other base, value is always considered unsigned.
// s should be an array long enough to contain any possible value

// Parameters:
// --> val ...... Value to be converted to a string. 
// --> s ........ Array in memory where to store the resulting null-terminated string. 
// --> base ..... Numerical base used to represent the value as a string, between 2 and 36, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.

// Return Value:
// s

// ------------------------------------------------------------------------------------------------
// dint sigclib_islower(dint c) -------------------------------------------------------------------
// Check if character is lowercase letter
// Checks if parameter c is a lowercase alphabetic letter.

// Parameters:
// --> c ........ Character to be checked 

// Return Value:
// A value different from zero if indeed c is a lowercase alphabetic letter, Zero otherwise.


// ------------------------------------------------------------------------------------------------
// dint   sigclib_isupper(dint c) -----------------------------------------------------------------
// Check if character is uppercase letter
// Checks if parameter c is a uppercase alphabetic letter.

// Parameters:
// --> c ........ Character to be checked 

// Return Value:
// A value different from zero if indeed c is a uppercase alphabetic letter, Zero otherwise.

// ------------------------------------------------------------------------------------------------
// char sigclib_tolower(dint c) -------------------------------------------------------------------
// Converts the given character c into lower case
// translates the alphabetic characters c into lower case

// Parameters:
// --> c ........ character to be converted

// Return Value:
// converted character


// ------------------------------------------------------------------------------------------------
// char sigclib_toupper(dint c) -------------------------------------------------------------------
// Converts the given character c into upper case
// translates the alphabetic characters c into upper case

// Parameters:
// --> c ........ character to be converted

// Return Value:
// converted character


// ------------------------------------------------------------------------------------------------
// char* sigclib_strupr(char *s) ------------------------------------------------------------------
// Converts a string into upper case
// translates the alphabetic characters in s into upper case

// Parameters:
// --> s ........ string to be converted

// Return Value:
// s

// ------------------------------------------------------------------------------------------------
// char* sigclib_strlwr(char* s) ------------------------------------------------------------------
// Converts a string into lower case
// translates the alphabetic characters in s into lewer case

// Parameters:
// --> s ........ string to be converted

// Return Value:
// s


// ------------------------------------------------------------------------------------------------
// dint sigclib_isdigit(dint c) -------------------------------------------------------------------
// Check if character is decimal digit
// Checks if parameter c is a decimal digit character.
// Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9 

// Parameters:
// --> c ........ Character to be checked 

// Return Value:
// A value different from zero if indeed c is a decimal digit, zero otherwise.


// ------------------------------------------------------------------------------------------------
// void* sigclib_memchr(void* src_void, dint c, udint length) -------------------------------------
// Locate character in block of memory
// Searches within the first length bytes of the block of memory pointed by src_void for the first occurrence of c (interpreted as an unsigned char), and returns a pointer to it.

// Parameters:
// --> src_void .. Pointer to the block of memory where the search is performed. 
// --> c ......... Value to be located
// --> length .... Number of bytes to be analyzed. 

// Return Value:
// A pointer to the first occurrence of c in the block of memory pointed by src_void. If the value is not found, the function returns NULL.


// ------------------------------------------------------------------------------------------------
// dint sigclib_memicmp(void* s1, void* s2, udint length) -----------------------------------------
// Case insensitive compare of two blocks of memory
// Compares the first length bytes of the block of memory pointed by s1 to the first length bytes pointed by s2, returning zero if they all match or a value different from zero representing which is greater 
// if they do not.

// Parameters:
// --> s1 ....... Pointer to block of memory. 
// --> s2 ....... Pointer to block of memory. 
// --> length.... Number of bytes to compare. 

// Return Value:
// A zero value indicates that the case insensitive contents of both memory blocks are equal.
// A value greater than zero indicates that the first byte that does not match in both memory blocks has a greater value in m1 than in m2. A value less than zero indicates the opposite.


// ------------------------------------------------------------------------------------------------
// char *sigclib_htoa(char *dst, unsigned long value);
// function will convert given value into an alphanumeric hexadecimal formatted string with 8 digits

// Parameters:
// --> dst ............. destination array
// --> value ........... unsigned 32bit-value to convert
// <-- function will return pointer to newly created string, corresponds to given destination array


// ------------------------------------------------------------------------------------------------
// char *sigclib_htoa_ex(char *dst, unsigned long value);
// function will convert given value into an alphanumeric hexadecimal formatted string with 2, 4 or 8 digits, depends on given value

// Parameters:
// --> dst ............. destination array
// --> value ........... unsigned 32bit-value to convert
// <-- function will return pointer to newly created string, corresponds to given destination array


// ------------------------------------------------------------------------------------------------
// char *sigclib_utoa(char *dst, unsigned long value);
// function will convert given unsigned 32bit value into string

// Parameters:
// --> dst ............. destination array
// --> value ........... unsigned 32bit-value to convert
// <-- function will return pointer to newly created string, corresponds to given destination array


// ------------------------------------------------------------------------------------------------
// char *sigclib_strpbrk(const char *s1, const char *s2);
// This function finds the first character in the string s1 that matches any character specified in s2.
// This does not include the terminating 0-characters.

// Parameters:
// --> s1	....... string to be scanned. 
// --> s2	....... string containing the characters to match 

// Return Value:
// This function returns a pointer to the character in s1 that matches one of the characters in s2, or NULL if no such character is found.


// ------------------------------------------------------------------------------------------------
// This function finds the last occurence of chr in the string pointed to by s including the 0-termination
// char *sigclib_strrchr(const char *s, int chr);

// Parameters:
// --> s ........ string to be scanned. 
// --> chr ...... searchee

// Return Value:
// Returns a pointer to the located character, or a null pointer


// ------------------------------------------------------------------------------------------------
// Function is able to compose a ascii-0-string with userdefined parameters.
// function global __cdecl sigclib_sprintfST var_input pd:^char; format:^char; p0:^void; ... end_var var_output retcode:udint; end_var;
// Note: Function is just available in ST-Code, use sigclib_sprintf() in C.
//       Do not feed function with wrong format or parameter. This could possibly lead to a wrong result or a crash.
// Parameters:
// --> pd ....... destination string where resulting string is stored. Buffer has to be large enough to contain resulting string.
// --> format ... C string that contains a format string, see detailed description below.
// --> p0 - p9 .. adresses of userspecific parameter (variables)

// format:
//   Syntax: %[flags][width][.precision][length]specifier
//   specifier:  d, i ....... signed decimal 4-byte value (dint)
//               v .......... signed decimal value v1=1byte(sint), v2=2byte(int), v4=4byte(dint)
//               V .......... unsigned decimal value V1=1byte(usint), V2=2byte(uint), V4=4byte(udint)
//               r .......... decimal notation of floating point Value r4=4byte(real), r8=8byte(lreal)
//               R .......... scientific decimal notation of floating point Value r4=4byte(real), r8=8byte(lreal)
//               u .......... unsigned decimal 4-byte value (udint)
//               o .......... unsigned octal 4-byte value (udint)
//               x .......... unsigned hexadecimal integer 4-byte value (udint)
//               X .......... unsigned hexadecimal integer (uppercase) 4-byte value (udint)
//               f,F ........ Decimal floating point (real)
//               e,E ........ Scientific notation (real) (mantissa/exponent) 3.9265e+002
//               c .......... ASCII-character 1-byte (char)
//               s .......... ASCII-0-String of characters
//               p .......... Pointer address
//
//       flags:  - .......... Left-justify within the given field width; Right justification is the default
//               + .......... Forces to preceed the result with a plus or minus sign
//               [SPACE] .... If no sign is going to be written, a blank space is inserted before the value.
//               0 .......... Left-pads the number with zeroes (0) instead of spaces when padding is specified
//
//       width:  (number) ... Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces.
//
//  .precision:  (.number) .. precision specifies the minimum number of digits to be written. 
//
// Return Value:
// Returns the number of characters in composed destination string without terminating 0.

