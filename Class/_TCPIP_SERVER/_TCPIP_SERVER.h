
// commands for SetConnParameter / SetMainParameter
#define TCPSVR_CMD_SETSOCKOPT         0
#define TCPSVR_CMD_TASKPRIO           1
#define TCPSVR_CMD_CLOSESOCKETTYPE    2
#define TCPSVR_CMD_KEEPALIVEPARA      3

// sub commands for SetConnParameter / SetMainParameter

// sub cmds socket options
#define TCPSVR_SOCKOPT_NAGLE          0
#define TCPSVR_SOCKOPT_KEEPALIVE      1
#define TCPSVR_SOCKOPT_DELAYEDACK     2
#define TCPSVR_SOCKOPT_REUSEADDR      3

// sub cmd task priority
#define TCPSVR_SUB_CMD_TASKPRIO       0

// sub cmds keep alive parameter
#define TCPSVR_KEEPALIVE_KEEPIDLE     0
#define TCPSVR_KEEPALIVE_KEEPINTVL    1
#define TCPSVR_KEEPALIVE_KEEPCNT      2

// sub cmd close socket type
#define TCPSVR_CLOSESOCKETTYPE        0