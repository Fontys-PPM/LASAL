#ifndef __OSI_BASE__
#define __OSI_BASE__


VAR_EXTERNAL
   pOsiMeths : ^void;
END_VAR

#define InitOsiMeths(osi) InitOsiM(_lsl_pOS^.pi##osi, USER_CNT_##osi)

FUNCTION GLOBAL InitOsiM_new
VAR_INPUT
	pMeths		: ^void;
	nMeths		: UINT;
END_VAR
VAR_OUTPUT
	ret_code	: ConfStates;
END_VAR;

#endif // __OSI_BASE__
