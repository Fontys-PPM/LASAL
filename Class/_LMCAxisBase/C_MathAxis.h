#ifndef _C_SPLINE_H_
  #define _C_SPLINE_H_


FUNCTION GLOBAL __cdecl LMC_XT_Spline_5_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	a4        : LREAL;
  	a5        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;
  
 
FUNCTION GLOBAL __cdecl LMC_XT_Spline_4_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	a4        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;
  
  
FUNCTION GLOBAL __cdecl LMC_XT_Spline_3_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;
  
FUNCTION GLOBAL __cdecl LMC_XT_Spline_2_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;  
  

FUNCTION GLOBAL __cdecl LMC_VT_Spline_5_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	a4        : LREAL;
  	a5        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;
  
  
FUNCTION GLOBAL __cdecl LMC_VT_Spline_4_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	a4        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;
  
  
FUNCTION GLOBAL __cdecl LMC_VT_Spline_3_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;
  
FUNCTION GLOBAL __cdecl LMC_VT_Spline_2_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;
  END_VAR;   
  
FUNCTION GLOBAL __cdecl LMC_ACC_Spline_5_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	a4        : LREAL;
  	a5        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;	
  END_VAR; 
  
FUNCTION GLOBAL __cdecl LMC_ACC_Spline_4_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	a4        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;	
  END_VAR;   
  
FUNCTION GLOBAL __cdecl LMC_ACC_Spline_3_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	a3        : LREAL;
  	tu        : LREAL;
  	td        : LREAL;   
  	t         : LREAL;     
    ptr_retXt : ^LREAL;	
  END_VAR; 
  
FUNCTION GLOBAL __cdecl LMC_ACC_Spline_2_Order
  VAR_INPUT
  	a1        : LREAL;
  	a2        : LREAL;
  	t         : LREAL;     
    ptr_retXt : ^LREAL;	
  END_VAR;   
  
  
  

#endif
