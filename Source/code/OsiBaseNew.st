#include "OsiBaseNew.h"
#include <RTOS_MemIntern.h>

//[#ENGLISH]
// This function copies the global interface pointers into
// a new CmdMeth - structure to enable users to call all the
// standard methods for a OSI-channel, too.
//[>pMeths] pointer to an array of function pointers
//[>nMeths] number of function pointers in pMeths
//[<ret_code] C_OK if successful
FUNCTION GLOBAL InitOsiM_new
VAR_INPUT
	pMeths		: ^void;
	nMeths		: UINT;
END_VAR
VAR_OUTPUT
	ret_code	: ConfStates;
END_VAR
VAR
	pTemp		: ^CmdMeth;
END_VAR

	IF pMeths = NIL THEN
	// The required interface is not installed on this PLC. Either
	// the online settings for project download were wrong, or the
	// operating system has to be updated.
	// This can happen with the Grafix or FileIO - classes on a x386.
		TRACE("This interface is not available with the installed version of the OS");
		pOsiMeths	:= NIL;
		ret_code	:= C_UNKNOWN_CONSTR;
		RETURN;
	END_IF;

	pTemp	:= _alloc(sizeof(CmdMeth) + nMeths*sizeof(pVoid))$^CmdMeth;
	IF pTemp = NIL THEN
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

	InitCmdTable(nMeths, pTemp);	// insert standard method pointers
									// add interface pointers
	_memcpy(#pTemp^.GetState + sizeof(pVoid), pMeths, nMeths*sizeof(pVoid));

	pOsiMeths	:= pTemp;			// pointer to complete method table

	ret_code	:= C_OK;

END_FUNCTION
