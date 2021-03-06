//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "_documentation"
	Revision           = "0.0"
	GUID               = "{FE4DDA44-E383-4BF9-8BA8-8F60FD0871C6}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "false"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)">
	<Channels>
		<Server Name="ClassSvr" GUID="{8D9C7DCB-D483-4FB0-B6A3-24C636998043}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
	</Channels>
</Class>
*)
_documentation : CLASS
  //Servers:
	ClassSvr 	: SvrChCmd_DINT;
  //Clients:
  //Variables:
  //Functions:
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB _documentation::@CT_
0$UINT,
2#0100000000000010$UINT, //TY__DOCUMENTATION
0$UINT, 0$UINT, (SIZEOF(::_documentation))$UINT, 
1$UINT, 0$UINT, 0$UINT, 
TO_UDINT(4207537136), "_documentation", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::_documentation.ClassSvr.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(619352855), "ClassSvr", 
//Clients:
END_FUNCTION


#define USER_CNT__documentation 0

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT__documentation] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION _documentation::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR

	ret_code := C_OK;

END_FUNCTION

//{{LSL_IMPLEMENTATION
