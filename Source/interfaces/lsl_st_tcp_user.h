//HFILTER:1
#ifndef _LSL_ST_TCP_USER_H
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define _LSL_ST_TCP_USER_H

#define TCP_NOT_READY           -2000
#define TCP_INVALID_SOCKSTATE   -2001
#define TCP_NOMEM_ERROR         -2002
#define TCP_BUFFER_TO_SMALL     -2003
#define TCP_MAXSOCKETS_ERROR    -2004
#define TCP_INVALID_SOCKNUM     -2005
#define TCP_INVALID_NUMBER      -2007
#define TCP_SYSTEM_ERROR        -2008
#define TCP_NOIF_ERROR          -2009


//getlasterror codes
#define TCP_ADDR_NOT_AVAIL      -3000   //endpoint address not available
#define TCP_ADDR_IN_USE         -3001   //address in use
#define TCP_AF_NO_SUPPORT       -3002   //family not supported
#define TCP_ARP_TABLE_FULL      -3003   //arp table full
#define TCP_INVALID_BAUD        -3004   //invalid baud rate 
#define TCP_INVALID_COMM_PORT   -3005   //invalid comm port number
#define TCP_INVALID_DEVICE      -3006   //invalid device type
#define TCP_INVALID_IFACE       -3007   //invalid interface number
#define TCP_INVALID_MASK        -3008   //invalid mask (ether must not be all fs)
#define TCP_INVALID_PING        -3009   //invalid ping response
#define TCP_CONN_REFUSED        -3010   //endpoint refused connection
#define TCP_DEST_ADDR_REQ       -3011   //destination address is required
#define TCP_DEST_UNREACH        -3012   //destination unreachable (ICMP)
#define TCP_INVALID_PARAM       -3013   //invalid parameter (pointer is 0)
#define TCP_IFACE_CLOSED        -3014   //interface closed
#define TCP_IFACE_TABLE_FULL    -3015   //interface table full
#define TCP_IFACE_OPEN_FAIL     -3016   //interface open failed
#define TCP_IN_PROGRESS         -3017   //operation (connect) is in progress
#define TCP_INVALID_FUNC        -3018   //invalid function call (parameter)
#define TCP_SOCKET_CONNECTED    -3019   //socket is already connected
#define TCP_MC_TABLE_FULL       -3020   //multicast table full
#define TCP_MC_ADDR_NOT_FOUND   -3021   //multicast address not found
#define TCP_OUT_OF_PORTS        -3022   //out of ports 
#define TCP_NET_DOWN            -3023   //network is down (send failed)
#define TCP_NET_UNREACH         -3024   //network unreachable (keepalive failed)
#define TCP_OUT_OF_DCUS         -3025   //out of DCUs (packets)
#define TCP_OPTPARAM_INVALID    -3026   //option parameter is invalid
#define TCP_SOCK_NOT_CONNECTED  -3027   //socket is not connected
#define TCP_RTIP_NOT_INST       -3028   //RTIP not initialized (i.e. xn_rtip_init not called)
#define TCP_INVALID_SOCKET      -3029   //invalid socket descriptor
#define TCP_NUM_DEVICE          -3030   //not enough devices (see CFG_NUM_ED,CFG_NUM_SMCX, NUM_3C, NUM_RS232 etc)
#define TCP_OP_NOT_SUPPORT      -3031   //socket type or specified operation not supported for this function
#define TCP_OUTPUT_FULL         -3032   //send failed due to output list being full
#define TCP_PROBE_FAIL          -3033   //could not determine device
#define TCP_RENTRANT            -3034   //non-reentrancy error
#define TCP_ROUTE_NOT_FOUND     -3035   //routing table entry not found
#define TCP_ROUTE_FULL          -3036   //routing table full
#define TCP_RSC_INIT_FAIL       -3037   //resource initialization failed
#define TCP_SHUTDOWN            -3038   //illegal operation due to socket shutdown
#define TCP_TIMEOUT             -3039   //timeout
#define TCP_TYPE_NOT_SUPPORT    -3040   //type not supported (only SOCK_STREAM and SOCK_DGRAM are supported)
#define TCP_WOULD_ARP           -3041   //send needs to ARP but ARP is disabled (see INCLUDE_ARP)
#define TCP_WOULD_BLOCK         -3042   //socket non-blocking but function would block
#define TCP_UNKNOWN_ERROR       -3043


#define IP_OPT_ADDR              1
#define IP_OPT_SUBNETMASK        2
#define IP_OPT_ETHERNET_ADDR     3
#define IP_OPT_GATEWAY           4
#define IP_OPT_PORT              5

// Only available >= version 0x000A
#define IP_OPT_DNS1              6
#define IP_OPT_DNS2              7
#define IP_OPT_DNS3              8
#define IP_OPT_DNS4              9

#define IP_ADDR_ANY              0x00000000
#define IP_ADDR_BROADCAST        0xffffffff

#define SELECT_OPT_READ          1
#define SELECT_OPT_WRITE         2
#define SELECT_OPT_EXCEPTION     3

// defines for TCP_USER_IOCTLSOCKET :
#define READ_AVAILABLE    1   // Get the number of bytes available to read
#define WRITE_AVAILABLE   2   // Get the number of bytes available to write
#define SET_SOCKET_MODE   3   // Set the socket to non-blocking (onoff=1) or blocking (onoff=0) mode

//
// Defines for setsockopt
//

// Level number for (get/set)sockopt() to apply to socket itself.
#define SOL_SOCKET  	   16#7fff     // options for socket level

// Option flags per-socket
#define SO_NAGLE          16#0001     // NAGLE algorithm enabled/disabled
#define SO_REUSEADDR	  16#0004	 // Allow local address reuse
#define SO_DELAYED_ACK    16#0400     // delay sending ACK
#define	IP_MULTICAST_IF   9
#define	IP_MULTICAST_LOOP 11
#define	IP_ADD_MEMBERSHIP 12
#define	SO_BROADCAST      16#10000

// bit masks for getLinkStatus (content of the returned link state)
#define IP_LINK_STATUS    0x01
#define IP_WIRE_SPEED     0x02
#define IP_DUPLEX_MODE    0x04


TYPE
    LSL_TCP_USER    :STRUCT
        udVersion                   : UDINT;
        tcp_user_socket             : pVoid;
        tcp_user_closesocket        : pVoid;
        tcp_user_connect            : pVoid;
        tcp_user_listen             : pVoid;
        tcp_user_accept             : pVoid;
        tcp_user_recv               : pVoid;
        tcp_user_send               : pVoid;
        tcp_user_shutdown           : pVoid;
        tcp_user_getpeerip          : pVoid;
        tcp_user_getpeerport        : pVoid;
        tcp_user_getsockip          : pVoid;
        tcp_user_getsockport        : pVoid;
        tcp_user_toip               : pVoid;
        tcp_user_strtoulong	        : pVoid;
        tcp_user_ulongtostr	        : pVoid;
        tcp_user_getCOMLinkPort     : pVoid;
        tcp_user_geterrorstring     : pVoid;
        tcp_user_netstat            : pVoid;
        tcp_user_nread_available    : pVoid;
        tcp_user_socket_ex          : pVoid;
        tcp_user_getservbyname      : pVoid;
        tcp_user_ipinfo             : pVoid;
        tcp_user_setsockopt         : pVoid;
        tcp_user_ping               : pVoid;
        udp_user_socket             : pVoid;
        udp_user_bind               : pVoid;
        tcp_user_recvfrom           : pVoid;
        tcp_user_sendto             : pVoid;
        tcp_user_ipinfo_reserved    : pVoid;
        tcp_user_select             : pVoid;
        tcp_user_ioctlsocket        : pVoid;
// since LSL_TCP_USER version 0x0B
        tcp_user_initFastInterface  : pVoid;
        tcp_user_sendfast           : pVoid;
        tcp_user_getLinkStatus      : pVoid;
// since LSL_TCP_USER version 0x0C
        tcp_user_strtoulong_asy     : pVoid;

    END_STRUCT;
END_TYPE

FUNCTION GLOBAL __cdecl P_TCP_USER_SOCKET
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_CLOSESOCKET
VAR_INPUT
    socket      : DINT;
    type0       : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_CONNECT
VAR_INPUT
    socket      : DINT;
    localport   : UDINT;
    IPAddress   : ^CHAR;
    port        : UDINT;
    timeout_ms  : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_LISTEN
VAR_INPUT
    socket      : DINT;
    localport   : UDINT;
    backlogsize : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_ACCEPT
VAR_INPUT
    socket      : DINT;
    timeout_ms  : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_RECV
VAR_INPUT
    socket      : DINT;
    buffer      :^CHAR;
    buflen      : UDINT;
    flags       : UDINT;
    timeout_ms  : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_SEND
VAR_INPUT
    socket      : DINT;
    buffer      :^CHAR;
    buflen      : UDINT;
    flags       : UDINT;
    timeout_ms  : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_SHUTDOWN
VAR_INPUT
    socket      : DINT;
    how         : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETPEERIP
VAR_INPUT
    socket      : DINT;
    sin_addr    : ^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETPEERPORT
VAR_INPUT
    socket      : DINT;
    sin_port    : ^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETSOCKIP
VAR_INPUT
    socket      : DINT;
    sin_addr    : ^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETSOCKPORT
VAR_INPUT
    socket      : DINT;
    sin_port    : ^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_TOIP
VAR_INPUT
    buffer      : ^CHAR;
    buflen      : UDINT;
    ID1         : UDINT;
    ID2         : UDINT;
    ID3         : UDINT;
    ID4         : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_STRTOULONG
VAR_INPUT
    buffer      : ^CHAR;
END_VAR
VAR_OUTPUT
    retval      : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_ULONGTOSTR
VAR_INPUT
    buffer      : ^CHAR;
    buflen      : UDINT;
    IPAddr      : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETCOMLINKPORT
VAR_OUTPUT
    port        : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETERRORSTRING
VAR_INPUT
    buffer      :^CHAR;
    buflen      : UDINT;
    errvalue    : DINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_NREAD_AVAILABLE
VAR_INPUT
    socket      : DINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;


FUNCTION GLOBAL __cdecl P_TCP_USER_SOCKET_EX
VAR_INPUT
    iface       : DINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETSERVBYNAME
VAR_INPUT
    name        :^CHAR;
    proto       :^CHAR;
END_VAR
VAR_OUTPUT
    retval      : UDINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_IPINFO
VAR_INPUT
    iface       : DINT;
    option      : DINT;
    pErg        :^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

// since LSL_TCP_USER version 5
FUNCTION GLOBAL __cdecl P_TCP_USER_SETSOCKOPT
VAR_INPUT
    socket      : DINT;
    level       : DINT;
    option_name : DINT;
    option_value: ^CHAR;
    optionlen   : DINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

// since LSL_TCP_USER version 6
FUNCTION GLOBAL __cdecl P_TCP_USER_PING
VAR_INPUT
    ipaddr      : ^CHAR;
    bytes       : UDINT;
    ttl         : UDINT;
    wait        : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

// since LSL_TCP_USER version 7
FUNCTION GLOBAL __cdecl P_UDP_USER_SOCKET
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_UDP_USER_BIND
VAR_INPUT
    socket      : DINT;
    ipaddr      : UDINT;
    port        : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_RECVFROM
VAR_INPUT
    socket      : DINT;
    buffer      :^CHAR;
    buflen      : UDINT;
    flags       : UDINT;
    timeout_ms  : UDINT;
    pIPAddr     :^UDINT;
    pPort       :^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_SENDTO
VAR_INPUT
    socket      : DINT;
    buffer      :^CHAR;
    buflen      : UDINT;
    flags       : UDINT;
    timeout_ms  : UDINT;
    ipaddr      : UDINT;
    port        : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_SELECT
VAR_INPUT
    count       : DINT;
    sockets     :^DINT;
    select_type : UDINT;
    flags       : UDINT;
    timeout_ms  : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_IOCTLSOCKET
VAR_INPUT
    socket      : DINT;
    select_type : UDINT;
    onoff       : UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

// since LSL_TCP_USER version 0x0B

(* example of a correct declaration of the callback function which is set by tcp_user_initFastInterface
FUNCTION GLOBAL __CDECL FastCallback
VAR_INPUT
  pUserPara   : pVoid;
  pData       : pVoid;
  udLength    : UDINT;
END_VAR
VAR_OUTPUT
  dRetval     : DINT;
END_VAR
*)  
FUNCTION GLOBAL __cdecl P_TCP_USER_INITFASTINTERFACE
VAR_INPUT
    iFace       : DINT;
    pUserFct    : ^VOID;
    pUserParam  : ^VOID;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_SENDFAST
VAR_INPUT
    interface_handle  : DINT;
    buffer            :^CHAR;
    buflen            : UDINT;
END_VAR
VAR_OUTPUT
    retval            : DINT;
END_VAR;

FUNCTION GLOBAL __cdecl P_TCP_USER_GETLINKSTATUS
VAR_INPUT
    iFace       : DINT;
    pLinkStatus : ^UDINT;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

// since LSL_TCP_USER version 0x0C

(* example of a correct declaration of the callback function which is set by tcp_user_strtoulong_asy
FUNCTION GLOBAL __CDECL StrToUlongCallback
VAR_INPUT
  pUserPara   : pVoid;
  IPAddress   : UDINT;
  retCode     : DINT;
END_VAR
*)  

FUNCTION GLOBAL __cdecl P_TCP_USER_STRTOULONG_ASY
VAR_INPUT
    buffer      : ^CHAR;
    pUserFct    : ^VOID;
    pUserParam  : ^VOID;
END_VAR
VAR_OUTPUT
    retval      : DINT;
END_VAR;

#define OS_TCP_USER_VERSION lsl_tcp_user^.udVersion

#define OS_TCP_USER_SOCKET() lsl_tcp_user^.tcp_user_socket $ P_TCP_USER_SOCKET()
#define OS_TCP_USER_CLOSESOCKET(p1,p2) lsl_tcp_user^.tcp_user_closesocket $ P_TCP_USER_CLOSESOCKET(p1,p2)
#define OS_TCP_USER_CONNECT(p1, p2, p3, p4, p5) lsl_tcp_user^.tcp_user_connect $ P_TCP_USER_CONNECT(p1, p2, p3, p4, p5)
#define OS_TCP_USER_LISTEN(p1, p2, p3) lsl_tcp_user^.tcp_user_listen $ P_TCP_USER_LISTEN(p1, p2, p3)
#define OS_TCP_USER_ACCEPT(p1, p2) lsl_tcp_user^.tcp_user_accept $ P_TCP_USER_ACCEPT(p1, p2)
#define OS_TCP_USER_RECV(p1, p2, p3, p4, p5) lsl_tcp_user^.tcp_user_recv $ P_TCP_USER_RECV(p1, p2, p3, p4, p5)
#define OS_TCP_USER_SEND(p1, p2, p3, p4, p5) lsl_tcp_user^.tcp_user_send $ P_TCP_USER_SEND(p1, p2, p3, p4, p5)
#define OS_TCP_USER_SHUTDOWN(p1, p2) lsl_tcp_user^.tcp_user_shutdown $ P_TCP_USER_SHUTDOWN(p1, p2)
#define OS_TCP_USER_GETPEERIP(p1,p2) lsl_tcp_user^.tcp_user_getpeerip $ P_TCP_USER_GETPEERIP(p1,p2)
#define OS_TCP_USER_GETPEERPORT(p1,p2) lsl_tcp_user^.tcp_user_getpeerport $ P_TCP_USER_GETPEERPORT(p1,p2)
#define OS_TCP_USER_GETSOCKIP(p1,p2) lsl_tcp_user^.tcp_user_getsockip $ P_TCP_USER_GETSOCKIP(p1,p2)
#define OS_TCP_USER_GETSOCKPORT(p1,p2) lsl_tcp_user^.tcp_user_getsockport $ P_TCP_USER_GETSOCKPORT(p1,p2)
#define OS_TCP_USER_TOIP(p1, p2, p3, p4, p5, p6) lsl_tcp_user^.tcp_user_toip $ P_TCP_USER_TOIP(p1, p2, p3, p4, p5, p6)
#define OS_TCP_USER_STRTOULONG(p1) lsl_tcp_user^.tcp_user_strtoulong $ P_TCP_USER_STRTOULONG(p1)
#define OS_TCP_USER_ULONGTOSTR(p1, p2, p3) lsl_tcp_user^.tcp_user_ulongtostr $ P_TCP_USER_ULONGTOSTR(p1, p2, p3)
#define OS_TCP_USER_GETCOMLINKPORT() lsl_tcp_user^.tcp_user_getCOMLinkPort $ P_TCP_USER_GETCOMLINKPORT()
#define OS_TCP_USER_GETERRORSTRING(p1, p2, p3) lsl_tcp_user^.tcp_user_geterrorstring $ P_TCP_USER_GETERRORSTRING(p1, p2, p3)
#define OS_TCP_USER_NREAD_AVAILABLE(p1) lsl_tcp_user^.tcp_user_nread_available $ P_TCP_USER_NREAD_AVAILABLE(p1)
#define OS_TCP_USER_SOCKET_EX(p1) lsl_tcp_user^.tcp_user_socket_ex $ P_TCP_USER_SOCKET_EX(p1)
#define OS_TCP_USER_GETSERVBYNAME(p1,p2) lsl_tcp_user^.tcp_user_getservbyname $ P_TCP_USER_GETSERVBYNAME(p1,p2)
#define OS_TCP_USER_IPINFO(p1,p2,p3) lsl_tcp_user^.tcp_user_ipinfo $ P_TCP_USER_IPINFO(p1,p2,p3)
#define OS_TCP_USER_SETSOCKOPT(p1,p2,p3,p4,p5) lsl_tcp_user^.tcp_user_setsockopt $ P_TCP_USER_SETSOCKOPT(p1,p2,p3,p4,p5)
#define OS_TCP_USER_PING(p1,p2,p3,p4) lsl_tcp_user^.tcp_user_ping $ P_TCP_USER_PING(p1,p2,p3,p4)
#define OS_UDP_USER_SOCKET() lsl_tcp_user^.udp_user_socket $ P_UDP_USER_SOCKET()
#define OS_UDP_USER_BIND(p1,p2,p3) lsl_tcp_user^.udp_user_bind $ P_UDP_USER_BIND(p1,p2,p3)
#define OS_TCP_USER_RECVFROM(p1,p2,p3,p4,p5,p6,p7) lsl_tcp_user^.tcp_user_recvfrom $ P_TCP_USER_RECVFROM(p1,p2,p3,p4,p5,p6,p7)
#define OS_TCP_USER_SENDTO(p1,p2,p3,p4,p5,p6,p7) lsl_tcp_user^.tcp_user_sendto $ P_TCP_USER_SENDTO(p1,p2,p3,p4,p5,p6,p7)
#define OS_TCP_USER_SELECT(p1,p2,p3,p4,p5) lsl_tcp_user^.tcp_user_select $ P_TCP_USER_SELECT(p1,p2,p3,p4,p5)
#define OS_TCP_USER_IOCTLSOCKET(p1,p2,p3) lsl_tcp_user^.tcp_user_ioctlsocket $ P_TCP_USER_IOCTLSOCKET(p1,p2,p3)
#define OS_TCP_USER_INITFASTINTERFACE(p1, p2, p3) lsl_tcp_user^.tcp_user_initFastInterface $ P_TCP_USER_INITFASTINTERFACE(p1, p2, p3)
#define OS_TCP_USER_SENDFAST(p1, p2, p3) lsl_tcp_user^.tcp_user_sendfast $ P_TCP_USER_SENDFAST(p1, p2, p3)
#define OS_TCP_USER_GETLINKSTATUS(p1, p2) lsl_tcp_user^.tcp_user_getLinkStatus $ P_TCP_USER_GETLINKSTATUS(p1, p2)
#define OS_TCP_USER_STRTOULONG_ASY(p1,p2,p3) lsl_tcp_user^.tcp_user_strtoulong_asy $ P_TCP_USER_STRTOULONG_ASY(p1,p2,p3)

//HFILTER:1
#endif //ifndef _LSL_ST_TCP_USER_H
//HFILTER:
