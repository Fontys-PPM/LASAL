
//*********************************************************************************************************************
// Global definitions
//*********************************************************************************************************************

//#DEFINE SDDMAXENTRIES      32

// Class Version for communication in Lasal2
#define SDD_L2VERSION     7

// minimal refresh time of the server
#define MINTIMESVRUPDATE	4

// standard name of Lasal2 table
#define STDL2TABLENAME		"DRIVETAB"

// standard file name for export the drive parameter
#define EXPORTFILENAME    "C:\DRIVEPARA.XLS"

// maximal memory for the sdd parameter
#define SDDMAXMEM			5*1024

// max entries for the asynchronous buffer (must be >= 6, otherwise initialisation fails)
#define SDDBUFFERENTRY		100

// timeout for asynchron parameters in us 
#define SDD_ASY_TIMEOUT   3000000

// waiting for refreshing the actual values
#define ACTVALTIMEFAST      50

// size of one entry in the buffer
#define PARAENTRYSIZE  5

// maximal index of the Lasal2 Buffer
#define L2MAXINDEX      30

// error code for timeout (according to the object handling in the sigmatek functionality manual)
#define ERR_OBJ_HANDLING_TIMEOUT  2

//*********************************************************************************************************************
// Error Codes for axis objects
//*********************************************************************************************************************
#DEFINE SDD_NO_HW           1       // no hardware modul available

//*********************************************************************************************************************
// NewInst Commands
//*********************************************************************************************************************

// Commands for NewInst
#define SDD_ASYNC_READY		        0
#define SDD_ASYNC_ERROR           1
#define SDD_REFRESH_SETPARA       2
#define SDD_ASYNC_BUSY            3
#define SDD_GENERAL_ERROR         4
#define SDD_GENERAL_READY         5
#define SDD_GETVERSION            6
#define SDD_ONLINEOK              7
#define SDD_RWPARLASAL2           8
#define SDD_GETAXISINUSE          9
#DEFINE SDD_SETHWSTATE           10
#define SDD_SAVPARAVALUE         11
#define SDD_REFRESHPARA          12
#define SDD_INITAXLE             13
#define SDD_URINITAXLE           14
#define SDD_GETSERIE             15
#define SDD_SETSTATE             16
#define SDD_GET_CHANGE_CNT       17
#define SDD_GET_PARAMS           18
#define SDD_REFRESHPARAOBJECTS   19
#define SDD_GET_AXIS_PTR_LIST    20
#define SDD_GET_DEVICESERIALNO   21  //Get Serial-No of head device (SDD_L2VERSION >= 6)
#define SDD_GET_ANY_AXIS_ENABLED 22
#define SDD_GET_MNG_TRANSPARENT  23  //[SA33753] Get Transparent information (SDD_L2VERSION >= 7)
#define SDD_NEWINSTPDO          100
#define SDD_READPDODATA         101
#define SDD_WRITEPDODATA        102
#define SDD_ISEEPROMAVAILABLE   200
#define SDD_READEEPROMDATA      201
#define SDD_WRITEEPROMDATA      202

// maximal selection number for the synchronous data handling
#define SDD_MAX_AVALRT 7
#define SDD_MAX_AVALTT 19

// values for the standard setting
#define SDD_STD_AVALRT1   16#0205
#define SDD_STD_AVALTT1   16#0A07
#define SDD_STD_PPSCALE   16   


// definition of the group index
#define IDX_MOTOR_PARA    0
#define IDX_DRIVE_PARA    1
#define IDX_CURRENT_PARA  2
#define IDX_VEL_PARA      3
#define IDX_POS_PARA      4
#define IDX_FD_PARA       5
#define IDX_APPLI_PARA    6
#define IDX_ERRORHANDLING 7
//#define IDX_ACT_VALUES    8


// maximal indizes of parameters in the different groups
#define MAX_MOTOR_PARA    027 // 27
#define MAX_DRIVE_PARA    049 // 22
#define MAX_CURRENT_PARA  058 //  9
#define MAX_VEL_PARA      066 //  8
#define MAX_POS_PARA      076 // 10
#define MAX_FD_PARA       082 //  6
#define MAX_APPLI_PARA    122 // 38
#define MAX_ACT_VALUES    208 // 87
#define MAX_ERRORHANDLING 002 //  2


// number of parameters used in the different groups
#define NBR_MOTOR_PARA    25
#define NBR_DRIVE_PARA    18
#define NBR_CURRENT_PARA   9
#define NBR_VEL_PARA       7
#define NBR_POS_PARA       7
#define NBR_FD_PARA        3
#define NBR_APPLI_PARA    32
//#define NBR_ACT_VALUES
#define NBR_ERRORHANDLING  2



// PARAMETER DEFINITION
// motor parameter
#define	SDD_M_NAME1   001
#define	SDD_M_NAME2	  002
#define	SDD_M_NAME3	  003
#define	SDD_M_INULL	  004
#define	SDD_M_IPEAK	  005
#define	SDD_M_NMAX	  006
#define	SDD_M_POL	    007
#define	SDD_M_TORQUE	008
#define	SDD_M_L	      009
#define	SDD_M_R	      010
#define	SDD_M_J	      011
#define	SDD_M_TYPE	  012
#define	SDD_M_RPOL	  013
#define	SDD_M_ROFF	  014
#define	SDD_M_RPULSE	015
#define	SDD_M_RTEMP	  016
#define	SDD_M_SER	    017
#define	SDD_M_BRAKE   018
#define	SDD_M_IFWEAK	021
#define	SDD_M_BRDIS	  022
#define	SDD_M_BREN	  023
#define	SDD_M_UN  	  024
#define	SDD_M_UBOOST  025
#define	SDD_M_IMAG	  026
#define	SDD_M_TROT	  027

// drive parameter		
#define	SDD_G_MODE	  032
#define	SDD_G_CETIME	033
#define	SDD_G_VMAINS	034
#define	SDD_G_VBUSM	  035
#define	SDD_G_MBAL	  036
#define	SDD_G_MTEMPK	037
#define	SDD_G_MTEMPE	038
#define	SDD_G_PWM	    039
#define	SDD_G_DELAY	  040
#define	SDD_G_FTEMP	  041
#define	SDD_G_EMRAMP	042
#define	SDD_G_MASKE1	043
#define	SDD_G_MASKE2	044
#define	SDD_G_MASKW	  045
#define	SDD_G_MASKD	  046
#define	SDD_G_VRAMP	  047
#define	SDD_G_SRAMP	  048
#define	SDD_G_RBAL	  049

// current control parameter
#define	SDD_C_KPQ	    050
#define	SDD_C_TN	    051
#define	SDD_C_KDREL	  052
#define	SDD_C_KPDREL	053
#define	SDD_C_KPNULL	054
#define	SDD_C_KPPEAK	055
#define	SDD_C_ICONT	  056
#define	SDD_C_IPEAK	  057
#define	SDD_C_IPEAKN	058

// velocity control parameter
#define	SDD_V_KP	    060
#define	SDD_V_TN	    061
#define	SDD_V_T	      062
#define	SDD_V_T2	    063
#define	SDD_V_FILT	  064
#define	SDD_V_NMAX	  065
#define	SDD_V_KPREL	  066
		
// position control parameter		
#define	SDD_P_KV	    070
#define	SDD_P_SFF	    071
#define	SDD_P_PSCALE	072
#define	SDD_P_SSCALE	073
#define	SDD_P_TFF	    074
#define	SDD_P_PEMAX	  075
#define	SDD_P_SMODE	  076

// feedback parameter		
#define	SDD_F_BW	    080
#define	SDD_F_FF	    081
#define	SDD_F_RK	    082

// application parameter
#define	SDD_A_JRATIO	090
#define	SDD_A_VALRT1	091
#define	SDD_A_VALRT2	092
#define	SDD_A_VALTT1	093
#define	SDD_A_VALTT2	094
#define	SDD_A_CTIME	  095
#define	SDD_A_STIME 	096
#define	SDD_A_STYPE	  097
#define	SDD_A_AVSW	  098
#define	SDD_A_I2TERR	099
#define	SDD_A_TEMPDE	100
#define	SDD_A_TEMPMW	101
#define	SDD_A_STRED	  102
#define	SDD_A_STDT	  103
#define SDD_A_POS     104
#define SDD_A_DNAME1  108
#define SDD_A_DNAME2  109
#define SDD_A_DNAME3  110
#define SDD_A_MODE2   111
#define SDD_A_MULTI   112
#define SDD_A_ICOM    105
#define SDD_A_CAPREF  106
#define SDD_A_EDGE    107
#define SDD_A_STTH    113
#define SDD_A_INT1    114
#define SDD_A_INT2    115
#define SDD_A_ICOMP   116
#define SDD_A_CMIN    117
#define SDD_A_BIQCF   118
#define SDD_A_BIQFR   119
#define SDD_A_BIQCD   120
#define SDD_A_BIQDR   121
#define SDD_A_CAPFT   122

// actual values
#define	SDD_I_PCMD	  174
#define	SDD_I_PE	    175
#define	SDD_I_POS	    176
#define	SDD_I_FPOS	  177
#define	SDD_I_IA	    178
#define	SDD_I_IB    	179
#define	SDD_I_MPOS	  180
#define	SDD_I_TEMPM	  181
#define	SDD_I_BCC	    182
#define	SDD_I_TEMPK	  183
#define	SDD_I_TEMPE	  184
#define	SDD_I_IPEAK	  185
#define	SDD_I_ICONT	  186
#define	SDD_I_FW	    187
#define	SDD_I_BUILD	  188
#define	SDD_I_HW	    189
#define	SDD_I_NCMD	  190
#define	SDD_I_IQ	    191
#define	SDD_I_ID	    192
#define	SDD_I_I2T	    193
#define	SDD_I_ICMD	  194
#define	SDD_I_VBUS	  195
#define	SDD_I_PBAL  	196
#define	SDD_I_N	      197
#define	SDD_I_NFILT	  198
#define	SDD_I_STATUS	199
#define	SDD_I_SER	    200
#define	SDD_I_DERROR	201
#define	SDD_I_CAP   	202
#define	SDD_I_CAP4  	203
#define	SDD_I_CAPENC	204
#define	SDD_I_BITS  	205
#define	SDD_I_INT1  	206
#define	SDD_I_INT2  	207
#define	SDD_I_FBB  	  208


// drive commands
#define SDD_K_EN      220
#define SDD_K_CLRF    221
#define SDD_K_BRAKE   222
#define SDD_K_FBRW    223
#define SDD_K_START   224

#define SDD_K_CI      226
#define SDD_K_CINC    227
#define SDD_K_SPEED   228
#define SDD_K_STEP    229
#define SDD_K_PMOVE   230
#define SDD_K_PINC    231



