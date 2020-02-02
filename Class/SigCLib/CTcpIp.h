// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 12.04.2019                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// | TcpIp Interface                                                                              |
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#ifndef _CTcpIp_H
 #define _CTcpIp_H
 
 #include "DefineCompiler.h" 

 #ifdef cCompile
   
  cExtern long          sigclib_tcp_ping(const char *ipv4, unsigned long bytes, unsigned long ttl, unsigned long wait);
  cExtern long          sigclib_tcp_socket_open(void);
  cExtern long          sigclib_tcp_socket_open_ex(long iface);
  cExtern long          sigclib_tcp_socket_close(long socket, unsigned long soft_close);
  cExtern long          sigclib_tcp_connect(long socket, const char *ipv4, unsigned long port, unsigned long timeout_ms);
  cExtern long          sigclib_tcp_nread_available(long socket);
  cExtern long          sigclib_tcp_recv(long socket, void *buffer, unsigned long buflen, unsigned long timeout_ms);
  cExtern long          sigclib_tcp_send(long socket, void *buffer, unsigned long buflen, unsigned long timeout_ms);
  cExtern long          sigclib_tcp_set_socket_option(long socket, long level, long option_name, unsigned char *option_value, long optionlen);
  cExtern long          sigclib_tcp_ioctlsocket(long socket, unsigned long select_type, unsigned long onoff);
  cExtern long          sigclib_tcp_listen(long socket, unsigned long localport, unsigned long backlogsize);
  cExtern long          sigclib_tcp_accept(long socket, unsigned long timeout_ms);
  cExtern long          sigclib_tcp_ipinfo(long iface, long option, unsigned long *pErg);
  cExtern unsigned long sigclib_tcp_strtoulong(const char *buffer);
  cExtern long          sigclib_tcp_ulongtostr(char *buffer, unsigned long buflen, unsigned long ipaddr);

 #else

  function global __cdecl sigclib_tcp_ping var_input ipv4:^char; bytes:udint; ttl:udint; wait:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_socket_open var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_socket_open_ex var_input iface:dint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_socket_close var_input socket:dint; soft_close:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_connect var_input socket:dint; ipv4:^char; port:udint; timeout_ms:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_nread_available var_input socket:dint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_recv var_input socket:dint; buffer:^void; buflen:udint; timeout_ms:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_send var_input socket:dint; buffer:^void; buflen:udint; timeout_ms:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_set_socket_option var_input socket:dint; level:dint; option_name:dint; option_value:^usint; optionlen:dint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_ioctlsocket var_input socket:dint; select_type:udint; onoff:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_listen var_input socket:dint; localport:udint; backlogsize:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_accept var_input socket:dint; timeout_ms:udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_ipinfo var_input iface:dint; option:dint; pErg:^udint; end_var var_output retcode:dint; end_var;
  function global __cdecl sigclib_tcp_strtoulong var_input buffer:^char; end_var var_output retcode:udint; end_var;
  function global __cdecl sigclib_tcp_ulongtostr var_input buffer:^char; buflen:udint; ipaddr:udint; end_var var_output retcode:dint; end_var;

 #endif
 
#endif 


// ************************************************************************************************
// USAGE
// ************************************************************************************************

// NOTE: In userspace there is no need to get any interface from operation system or include of h-file
//       Furthermore there is no limitation of usage. User is allowed to use functionality in cTor as well
//
// optional: include <lsl_c_iftcp.h>
// optional: include <lsl_st_tcp_user.h>

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_ping(const char *ipv4, unsigned long bytes, unsigned long ttl, unsigned long wait);
// --> ipv4 ............ ipaddress eg.: "192.168.150.10"
// --> bytes ........... size of PING-packet in bytes
// --> ttl ............. Time to life of PING-Packet in seconds
// --> wait ............ Rounf Trip Time untill arival of answer
// <-- function will return value >=0 on success, on the other hand <0
// example: sigclib_tcpip_ping("192.168.150.10", 32, 500, 2000);

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_socket_open(long retcode);
// Open new socket
// <-- function will return a valid socket on success, on the other hand an negative errorcode

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_socket_open_ex(long iface);
// Open new socket on specific interface
// --> iface ........... number of interface
// <-- function will return a valid socket on success, on the other hand an negative errorcode

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_socket_close(long socket, unsigned long soft_close);
// Close valid socket
// --> socket .......... valid socket to close
// --> soft_close ...... 1=send already detached packets, 0=hard close
// <-- function will return value >=0 on success, on the other hand <0
// example: sigclib_tcpip_socket_close(socket, 1)

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_connect(long socket, const char *ipv4, unsigned long port, unsigned long timeout_ms);
// Create a connection to a specific port.
// --> socket .......... valid socket
// --> ipv4 ............ ipaddress eg.: "192.168.150.10"
// --> port ............ port
// --> timeout_ms ...... timeout in milliseconds
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_nread_available(long socket);
// Returns the number of bytes available for reading.
// --> socket .......... valid socket
// <-- function will return number ot bytes to read or in case of error a negative value

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_recv(long socket, void *buffer, unsigned long buflen, unsigned long timeout_ms);
// Recieve Data
// --> socket .......... valid socket
// --> buffer .......... buffer where data should be filed
// --> buflen .......... number of bytes to read
// --> timeout_ms ...... timeout in milliseconds (0 = non blocking, >0 blocking)
// <-- function will return number of filed bytes on success, on the other hand <0
// NOTE: use sigclib_tcp_nread_available() in front to get number of bytes to read 
// example: sigclib_tcpip_recv(socket, buff, byteno, 0);

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_send(long socket, void *buffer, unsigned long buflen, unsigned long timeout_ms);
// Send Data
// --> socket .......... valid socket
// --> buffer .......... data to send
// --> buflen .......... bytesize of data to send
// --> timeout_ms ...... timeout in milliseconde (0 = non blocking)
// <-- function will return value >=0 on success, on the other hand <0
// example: sigclib_tcpip_send(socket, buff, len, 0);

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_set_socket_option(long socket, long level, long option_name, unsigned char *option_value, long optionlen);
// Set spezific Socket option
// --> socket .......... valid socket
// --> level ........... protocol level (SOL_SOCKET oder IPPROTO_IP)
// --> option_name ..... option to set/change
// --> option_value .... option data to set
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_ioctlsocket(long socket, unsigned long select_type, unsigned long onoff);
// The ioctlsocket function controls the I/O mode of a socket.
// --> socket .......... valid socket
// --> select_type ..... 
// --> onoff ........... 0=off, 1=on
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_listen(long socket, unsigned long localport, unsigned long backlogsize);
// Wait for an incoming connection
// --> socket .......... valid socket
// --> localport ....... local portnumber
// --> backlogsize ..... max.number of valid connections
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_accept(long socket, unsigned long timeout_ms);
// Accept a connection from any remote host.
// --> socket .......... valid socket
// --> timeout_ms ...... timeout in milliseconds
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_ipinfo(long iface, long option, unsigned long *pErg);
// Get Information about tcp-interface
// --> iface ........... number of interface
// --> option .......... option to get (IP_OPT_ADDR, IP_OPT_SUBNETMASK, IP_OPT_GATEWAY)
// --> pErg ............ Address where result should be filed
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// long sigclib_tcp_ulongtostr(char *buffer, unsigned long buflen, unsigned long ipaddr);
// Converts an unsigned long IP address to a point-decimal format address.
// --> buffer .......... destination buffer
// --> buflen .......... size of destinationbuffer
// --> ipaddr .......... U32 formatted ipaddress
// <-- function will return value >=0 on success, on the other hand <0

// ------------------------------------------------------------------------------------------------
// unsigned long sigclib_tcp_strtoulong(const char *buffer);
// Converts a point decimal format IP address to an unsigned long IP address
// --> buffer .......... point decimal format IP address eg.: "192.168.150.10"
// <-- function will return U32 formatted ip-address, on error 0xFFFFFFFF

