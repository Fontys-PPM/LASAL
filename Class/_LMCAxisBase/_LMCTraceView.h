
//Trace starten   -  UserGroup 0
//#define _LMCTRACE


//Start- & Stopmarken für Trace
#define _LMCAXIS_TRACE_START     ((TRECGRP_USER0 SHL 16) OR 16#01)
#define _LMCAXIS_TRACE_STOP     (((TRECGRP_USER0 SHL 16) OR 16#01) OR 16#0100)


//-----------
// Kennungen 
//-----------

//Tasks
#define _LMCAXIS_Trace_RT        1
#define _LMCAXIS_Trace_BG        2
#define _LMCAXIS_TraceController     3

//Private Methoden
#define _LMCAXIS_TraceMoveAxis      10
#define _LMCAXIS_TraceFollow        11


//Tasks
#define LMCProfile_TraceRt     100

//Private Methoden
#define LMCProfile_TraceMoveBahn         110
#define LMCProfile_TraceMoveFunction     111
#define LMCProfile_Trace_Circle_Live     112
#define LMCProfile_TraceCal_Cir_Life     112
#define LMCProfile_Trace_Line_Live       113
#define LMCProfile_TraceCal_Lin_Life     113
#define LMCProfile_TraceCal_Lin_Rund     114
#define LMCProfile_Trace_Spline_Kub      115
#define LMCProfile_Trace_Spline_Quint    116
#define LMCProfile_Trace_Fourier         117
#define LMCProfile_Trace_CurveLive        118


//Globale Methoden
#define LMCProfile_TraceLockProfile      130
#define LMCProfile_TraceMoveLinear       131
#define LMCProfile_TraceMoveCircle       132


#define LMCRobot_TraceRtWork    200
#define LMCRobot_TraceRt0       210
#define LMCRobot_TraceRt1       211
#define LMCRobot_TraceRt2       212
#define LMCRobot_TraceRt3       213
#define LMCRobot_TraceRt4       214
#define LMCRobot_TraceRt5       215
#define LMCRobot_TraceRt6       216
#define LMCRobot_TraceRt7       217
#define LMCRobot_TraceRt8       218


