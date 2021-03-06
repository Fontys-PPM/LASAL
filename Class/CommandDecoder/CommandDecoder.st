//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "CommandDecoder"
	Revision           = "0.0"
	GUID               = "{C4AB9C85-B542-4AA2-8936-0000CC389E3B}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "false"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(450,120)">
	<Channels>
		<Server Name="ClassSvr" GUID="{37AE3DE5-D610-41B1-89BA-5BB80B9E9EB8}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Server Name="PhiVal" GUID="{F72EC31B-F5E4-4AF6-8E20-A4BD396A5974}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Server Name="XVal" GUID="{661862AB-C0E7-4D73-822B-031490DD87C9}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Server Name="YVal" GUID="{28E528C4-CE59-46A0-94E8-17C151AD649D}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Server Name="ZVal" GUID="{8B799287-235F-4E4C-B6AF-D170C32E92A9}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Client Name="cLib" Required="false" Internal="false"/>
	</Channels>
</Class>
*)
CommandDecoder : CLASS
  //Servers:
	ClassSvr 	: SvrChCmd_DINT;
	XVal 	: SvrCh_DINT;
	YVal 	: SvrCh_DINT;
	ZVal 	: SvrCh_DINT;
	PhiVal 	: SvrCh_DINT;
  //Clients:
	cLib 	: CltChCmd_SigCLib;
  //Variables:
		Command : ARRAY [0..4] OF CHAR;

		X : ARRAY [0..5] OF CHAR;

		Y : ARRAY [0..5] OF CHAR;

		Z : ARRAY [0..5] OF CHAR;

		Phi : ARRAY [0..5] OF CHAR;

  //Functions:
	
	FUNCTION GLOBAL DecodeCommand
		VAR_INPUT
			pString 	: ^CHAR;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

#pragma usingLtd SigCLib


//}}LSL_DECLARATION


FUNCTION GLOBAL TAB CommandDecoder::@CT_
0$UINT,
2#0100000000000010$UINT, //TY_COMMANDDECODER
0$UINT, 0$UINT, (SIZEOF(::CommandDecoder))$UINT, 
5$UINT, 1$UINT, 0$UINT, 
TO_UDINT(1132231514), "CommandDecoder", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::CommandDecoder.ClassSvr.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(619352855), "ClassSvr", 
(::CommandDecoder.XVal.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3519338924), "XVal", 
(::CommandDecoder.YVal.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(1769520841), "YVal", 
(::CommandDecoder.ZVal.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(2077036839), "ZVal", 
(::CommandDecoder.PhiVal.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3454700694), "PhiVal", 
//Clients:
(::CommandDecoder.cLib.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000000$UINT, TO_UDINT(1745651867), "cLib", TO_UDINT(77440046), "SigCLib", 0$UINT, 24$UINT, 
END_FUNCTION


#define USER_CNT_CommandDecoder 0

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_CommandDecoder] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION CommandDecoder::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR

	ret_code := C_OK;

END_FUNCTION

//{{LSL_IMPLEMENTATION


FUNCTION GLOBAL CommandDecoder::DecodeCommand
	VAR_INPUT
		pString 	: ^CHAR;
	END_VAR
  VAR
  	counter : DINT;
    commandSize : DINT;
    parameterSize : DINT;
  END_VAR

  parameterSize := 6 + 1;

  // get first 5 values (this represents the command)
  FOR counter := 0 TO 4 BY 1 DO
    Command[counter] := (pString+counter)^;
  END_FOR;
  
  // get the other values depending
  // on the command (these represent the command parameters)
  if Command = "CMOVE" then
    FOR counter := 0 TO 5 BY 1 DO
      X[counter] := (pString+counter+parameterSize-1)^; //6
    END_FOR;
    
    FOR counter := 0 TO 5 BY 1 DO
      Y[counter] := (pString+counter+parameterSize*2-1)^; //13
    END_FOR;
    
    FOR counter := 0 TO 5 BY 1 DO
      Z[counter] := (pString+counter+parameterSize*3-1)^; //20
    END_FOR;

    FOR counter := 0 TO 5 BY 1 DO
      Phi[counter] := (pString+counter+parameterSize*4-1)^; //27
    END_FOR;
    
    XVal := cLib.AToI(ps1:=#X[0]);
    YVal := cLib.AToI(ps1:=#Y[0]);
    ZVal := cLib.AToI(ps1:=#Y[0]);
    PhiVal := cLib.AToI(ps1:=#Phi[0]);
  end_if;

  


END_FUNCTION
