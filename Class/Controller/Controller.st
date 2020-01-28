//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "Controller"
	Revision           = "1.42"
	GUID               = "{2EE15EB7-1F89-11D5-90C4-006063018AE8}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "true"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)"
	Comment            = "Base class for the different types of the controller">
	<Channels>
		<Server Name="Signal_Input" GUID="{2EE15EB8-1F89-11D5-90C4-006063018AE8}" Visualized="true" Initialize="false" WriteProtected="false" Retentive="false" Comment="This server shows the actual internal control variable and is &#13;&#10;connected to the CNC class."/>
	</Channels>
	<RevDoku>
		<Owner Company="Sigmatek"/>
		<Dokumentation Revision="1.42" Date="2018-06-26" Author="SatChr" Company="Sigmatek" Description="Bugfix: All virtual methods, which should be overridden, do not return an uninitialzed return value."/>
		<Dokumentation Revision="1.41" Date="2015-03-06" Author="SatChr" Company="Sigmatek" Description="Improvement: New methodes: ControlLongReal, CheckHwReady, ReadActPosition, ReadPDO, IsReadyToSwitchOn (for future use)"/>
		<Dokumentation Revision="1.40" Date="2013-07-18" Author="SliMic" Company="Sigmatek" Description="1. Add some comments to the methodes and variables"/>
		<Dokumentation Revision="1.30" Date="2012-09-27" Author="RauAnd" Company="Sigmatek" Description="Modified for use with the _LMCAxis class."/>
		<Dokumentation Revision="1.20" Date="2011-05-02" Author="FuchsH" Company="Sigmatek" Description="Comments newly formatted."/>
		<Dokumentation Revision="1.10" Date="08.04.2010" Author="RauAnd" Company="Sigmatek" Description="Updating of the clients, server and methods documentation"/>
		<Dokumentation Revision="1.2" Date="22.01.2010" Author="RauAnd" Company="Sigmatek" Description="Updating of the clients, server and methods documentation"/>
		<Dokumentation Revision="1.1" Date="05.05.2008" Author="Rauand" Company="Sigmatek" Description="Improvement to use the position control in the drive"/>
		<Dokumentation Revision="1.0" Company="Sigmatek" Description="Creation"/>
	</RevDoku>
</Class>
*)
Controller : CLASS
	TYPE
	  _AXISCLASS :
	  (
	    _AXIS_CNC,
	    _AXIS_LMCAXIS,
	    _AXIS_CNC_NO_HW,
	    _AXIS_LMCAXIS_NO_HW,
	    _AXIS_CNC_OPT_HWCLASS_v1,
	    _AXIS_LMCAXIS_OPT_HWCLASS_v1
	  )$UDINT;
	END_TYPE
  //Servers:
	Signal_Input 	: SvrChCmd_DINT;
  //Clients:
  //Variables:
		AxisType 	: _AXISCLASS;
  //Functions:
				//! <Function Comment="Receives as input from the CNC/_LMCAxis, the Actual Position and the Internal Position." Name="control"/>
	FUNCTION VIRTUAL GLOBAL control
		VAR_INPUT
			ActPos 	: DINT;
			IntPos 	: DINT;
		END_VAR
		VAR_OUTPUT
			Result 	: DINT;
		END_VAR;
	
	FUNCTION VIRTUAL GLOBAL ControlLongReal
		VAR_INPUT
			ActPos 	: LREAL;
			IntPos 	: LREAL;
			IntSpeed 	: LREAL;
		END_VAR;
				//! <Function Comment="Updates the CNC StateFlags and the CNC ControlFlags" Name="StatePtr"/>
	FUNCTION VIRTUAL GLOBAL StatePtr
		VAR_INPUT
			StatePtr 	: ^CncFlags;
			CncstatePtr 	: ^CntrFlgs;
		END_VAR
		VAR_OUTPUT
			Result 	: DINT;
		END_VAR;
				//! <Function Comment="Adopts the addresses of the Servers: AxisStatus, AxisError and the Bitfield:AxisControl&#13;&#10;around this for reading and updating" Name="SetAxisFlgs"/>
	FUNCTION VIRTUAL GLOBAL SetAxisFlgs
		VAR_INPUT
			pAxisStatus 	: ^_LMCAXIS_STATUS;
			pAxisError 	: ^_LMCAXIS_ERROR;
			pAxisControl 	: ^_LMCAXIS_CONTROLBITS;
		END_VAR
		VAR_OUTPUT
			Result 	: _LMCCONTROLLERTYPE;
		END_VAR;
				//! <Function Comment="Function to test if we have a controller connected to the CNC/_LMCAxis" Name="WriteConstant"/>
	FUNCTION VIRTUAL GLOBAL WriteConstant
		VAR_INPUT
			Resolution 	: DINT;
			Timebase 	: DINT;
			Accel 	: DINT;
			ptrCNCIntStruct 	: ^CNCInternalStruct;
		END_VAR
		VAR_OUTPUT
			StartSpeed 	: DINT;
		END_VAR;
				//! <Function Comment="Function used for transmitting the Speed value from the CNC/_LMCAxis to the controller" Name="Speed"/>
	FUNCTION VIRTUAL GLOBAL Speed
		VAR_INPUT
			ActSpeed 	: DINT;
		END_VAR;
				//! <Function Comment="set Client values" Name="SetClients"/>
	FUNCTION VIRTUAL GLOBAL SetClients
		VAR_INPUT
			No 	: DINT;			//! <Variable Comment="The parameter number of the client that should be changed." Name="SetClients.No"/>
			Value 	: DINT;			//! <Variable Comment="The value to which the client should be changed." Name="SetClients.Value"/>
		END_VAR
		VAR_OUTPUT
			State 	: DINT;			//! <Variable Comment="0 =&gt; Error : The number entered was invalid or controller is active&#13;&#10;1 =&gt; Ok" Name="SetClients.State"/>
		END_VAR;
				//! <Function Comment="checks if the drive is enabled or not" Name="PowerIsOn"/>
	FUNCTION VIRTUAL GLOBAL PowerIsOn
		VAR_OUTPUT
			RetCode 	: BOOL;			//! <Variable Comment="true ... Drive is enabled" Name="PowerIsOn.RetCode"/>
		END_VAR;
				//! <Function Comment="checks if a Hardware Error is activ" Name="CheckHWError"/>
	FUNCTION VIRTUAL GLOBAL CheckHWError
		VAR_OUTPUT
			Retcode 	: BOOL;
		END_VAR;
				//! <Function Comment="Check wether the hardware is ready for communication." Name="CheckHwReady"/>
	FUNCTION VIRTUAL GLOBAL CheckHwReady
		VAR_OUTPUT
			IsReady 	: BOOL;
		END_VAR;
				//! <Function Comment="Read Controller specific parameters" Name="ReadParameter"/>
	FUNCTION VIRTUAL GLOBAL ReadParameter
		VAR_INPUT
			No 	: DINT;			//! <Variable Comment="Parameter number" Name="ReadParameter.No"/>
		END_VAR
		VAR_OUTPUT
			Value 	: DINT;
		END_VAR;
				//! <Function Comment="Read the actual encoder position from the drive&#13;&#10;for DrivePosControl and _LMCSigControl only." Name="ReadActPosition"/>
	FUNCTION VIRTUAL GLOBAL ReadActPosition
		VAR_OUTPUT
			BinPos 	: DINT;			//! <Variable Comment="actual position in external units" Name="ReadActPosition.BinPos"/>
		END_VAR;
				//! <Function Comment="This methode is called at the beginig of each realtime cycle by the _LMCAxis object. DrivePosControl and _LMCSigControl use this interface to get all information from the hardware class _DriveAxis" Name="ReadPDO"/>
	FUNCTION VIRTUAL GLOBAL ReadPDO;
				//! <Function Comment="function to quit a hardware error" Name="QuitHWError"/>
	FUNCTION VIRTUAL GLOBAL QuitHWError;
				//! <Function Comment="Check whether the hardware is ready for switch on." Name="IsReadyToSwitchOn"/>
	FUNCTION VIRTUAL GLOBAL IsReadyToSwitchOn
		VAR_OUTPUT
			IsReady 	: DINT;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB Controller::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_CONTROLLER
1$UINT, 42$UINT, (SIZEOF(::Controller))$UINT, 
1$UINT, 0$UINT, 0$UINT, 
TO_UDINT(1198357413), "Controller", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::Controller.Signal_Input.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(2233060755), "Signal_Input", 
//Clients:
END_FUNCTION


#define USER_CNT_Controller 15

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_Controller] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION Controller::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT_Controller, pCmd := #vmt.CmdTable);
	vmt.CmdTable.Write		:= #M_WR_DIRECT();
#pragma warning (disable : 74)
	vmt.UserFcts[0]		:= #control();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[1]		:= #ControlLongReal();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[2]		:= #StatePtr();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[3]		:= #SetAxisFlgs();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[4]		:= #WriteConstant();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[5]		:= #Speed();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[6]		:= #SetClients();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[7]		:= #PowerIsOn();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[8]		:= #CheckHWError();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[9]		:= #CheckHwReady();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[10]		:= #ReadParameter();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[11]		:= #ReadActPosition();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[12]		:= #ReadPDO();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[13]		:= #QuitHWError();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[14]		:= #IsReadyToSwitchOn();

#pragma warning (default : 74)
	Signal_Input.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Signal_Input.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION
//{{LSL_ENCRYPTION 16#800
BD505579F342212FF2412A957A14F995A721CB04F2D5336718571EE770B4CC2D6069EBA8C085400822ACDA35AB59366B926AED79729535F130722D03EEE7D2B0AB693A964F21F44060905AF62B588B64FE3B2979ED7B42BF9F3B70C7F7D8CC245DCA45BF
8F3CCE6744B12218E9C9A2D40BE75B7FE18420286BBEEE54EB0D7F006A7CFDDCAA806A7F387E746B4F97D69F028D9212778C27105A965240047A5611EF034D748AF08644ADB505C5AD6A488162A1300D82712AFD441FC8E570BF42F418E35B3D196CF28F
93C8A4D7E94665D75DB823E46F561632A2A779613646A2C3854AB0EF5DDAB2E601E63FE95F496B1BA7DF35168A18C358E639E3F25B5023D3F94FC152D69B66209D92A88770CB19B1A4781B4EBB11B9A1D83553981CFF873E6970C9F0C27819823232E678
5071296A5332AF8D3A53AD3862CEA908317FA22961204B592A70A9D749935062A83E74CCE927D9374532B48847F7C967B1FFF9716360394D5BF8B71A0B5546BEF3EE6092A246C51A762BFEAA46511DB19081650B3201AF35B1FFB168D8858132697030A2
F7C70A8CBA6AE6E277F0A016D2DF4765DCCDCBF081E0F82E7FA293CCB0506FF9027E717DA7D8362A91F373001A6616BE3A63BE12BDC34CD7CD6D7178FBD2DDEFC990616422752D8B8E9A3D71742AD586BC7572122CEAD47C0A96089BB86FAECF5E9C9056
5E938C80626583D59BCBE7320991DF092916B05C38FBD250EB55EDCE3C2EF9D66ACCB18D43054246BCB74E4B20479BA82E57F7ED2CAF4C50F6007D51291EB89AF702243C8FECAC56C86B3CBC168D3ED894F329B10430B43F1DF11540F676D44C0B342BF8
EB6537CC0CD3B7EBEC5EED244C20767F8DE7B74523B7EB6AD52F47354B621248D32127265547A26A7BAC59A457F415C4890CE14A3890FEA829EA9CA8048816573BAD16E478AF89DAC80960044D12DB42F376F68FDF3B7D8A9BE89945F687F9D29DD7C747
F3024ADC26872A7DCE129965320CFAE3CFE36A781E1CC651F01197F1F1D28558B40016D760433DB50879BD36C5FF7C6651AE01864F14831CD23425EC8A7E7868057079447CF43E3BD978D8A9FA52F7CD044E875A7C808276EF1400A804DF291245664E2B
235496C50CE14F831D1CAA4DD6BD9AD3BBB979C2F73648E692776E14D4E513BEE5CEB2FFADD29385C0E6B9ABE247AFC1355CC99E78648490A15FD52584438A4ECA1C2B985D7F5BB0DDCD8733622B33AAAA4151390D4D79E4A2848E2541D34CFFCDF51D8F
74802D151DE8123BE8FA70AE2DAC0A8BD2D56BE890CB6647E49FFD3099CD6A796280CACA4BA21F8786F839599624603CBD03B3ADBEF0388FCA21A805CAAC5D598CD0175A5D9ED45AA5102F37D78A4FC3B543F4AE1D0899D104C81AC24E6E480581DE40E8
1E3F7B284B23ACF5FF28EAB2342B8693E27F227BE3669A762EF643DE76F6636DDD631F6691BCE61C773B25EDBFC8C2612A9B671655400D479EA8B64183913C53A20FC0A971109D48DF7E08A8DFD07F8BF4C531EE03AC29437102C0D60778B50F270688EF
F96942EB0D0C0B02F1F70626E8D0AA457831643F09D61CA899C9D4CCBD05D3CADBA38A97C20C95FBB51383A3D7B1EFA8414BD1C7C164B72BD6B05ED9E99AFEABD1F4954080C433F63C170C975FF2C5984C8A98CB1E66795743002FEDE0FEB7049F9B4A8E
F2FCCB8CA16BDEAFBB37B55CDB1EC5EE1AE92BD891D576AF3BF7CA2BD3A32EF6D69FC4B98842CB5258925F5D63A73A3D69B8B1199173E4B4DC40428881990132E75A44F6DE704A4213E47964D3EAC867D43B655322EED4CEFD9198970F9C39772E4D05E0
8F5D9250AC7B089A744EA986B6F46075F88355448D81B5530992C0EBE41506098743DF659C802B007010F339798149C148FE44E88959DB713D1829EA5ED1CE2C5FA804E15A193D13B1C3AAEC92D0D1C1A7A9812CC69B35EEC25F4D38DB53F6B9CCA9A478
8F2A4754AF155DA85CFF05AAAE5322E5467974A64872421497161D9AE06575A65298AAA75878F2C41FE8233F4E192ED9072B30D07166988E72263A971CB99C852EB88E94F0046736E0E117CABF32CBB58988822786C47AF6CB47EB2017D8DBDA61D7D3AE
795ED5FBD1BE2DD5CD79EB2B41EF5440D6003DE5330782BF256AB06DA70F9D867F459C82AED1867E9448CDB84FD3BA14786B621030924C782673E82E9667676A64FB0D10BC91A7DE3C6DE20817D8BCC7863581328841E1CA76003759EEBDF00118BB015C
9121A375FA41E2DD4CF368587F7B5BCE6CB3134D8FAD0A017AC56CADB4298F428EF4A5C55F281BE7C96D5F7596CCBD874459896F125B20922B1750CE061237224840E65AF3E1C11FC0F2EB1B1D28134A8D3E774B34128ECA3699750156BD523CCD2073BA
85B70DDA3D06816855B79D269170C5CA2AEDA1B369B9F2DBEDF4E1DE5065EC4E5614F4FDE40343E9396C1EAD8FFC2475262ED7028FB398A760CD2869B6597CF81CE26E7BFA823D261B7B80906675D61F1901983DE1FF745421FC17684DD8D7573739E9FE
9CD9EA02F08CFCE4D8FB9DF3F6C561287995EEDE604102650DEF82BA187027A38C7375728F7C0A39A86120A6B67916FE5B06231FE9874BD20B9CD934F8D8ED0CFEEA483491B59151BC028DE0CA880553DC75268413CBFDA6BA2A29E30088E23757D799A8
9EC3D9D00C21C1D95CF301505FC59FE5F5BF39D6985AA6DB0827CECAE7674E2244496B580A3E551965B84F7DD9FDDBF5AFF499FCEE4BAAA7D4C2C18C61CBE4A5E95EE06A61DB84E11A990D077F772FD93E6472940D101C7E11822125AB2A3BA3CF927238
F057550B56E074EF9188D13E98509F7A141378DC8A43FC20E64C84B57199157AA3BD6DBE5F9B88444176FE73F77F1B1789CEB15EE4245F02BFE32DB5A7ACB821C6B063C98CB2716F9D7FCEFC29065E45E3AA5D21A2AE1D1834622B5395683A09FD796369
0B1E5EE9013AFFCD01703A14B38648BEB71041945198A1F681A9C8CA2BAAE70689E7E57A922599B2E16FDDC2EA4AE09E03258172436C3FF311EFEE3830C012A4036B9D7919631D713F11458D01E3C9C780C1FD4B184BEB3DD2488E0B477C484066D09987
587DB17F26CC215BC99358E3C976A823EB0273C467AFF11BB6CEDF0E2AC8D966B54E50DD660AA0FBD4E744B53CE9985264A88D5761A10BD2248FC899721DD95432C5488D2ED4EB67232FEBD9B6E0BD12245C727E31D12E5826762755A47288DAFAF1F1AD
2981D647354F7E05F6817649A2A78CE87DD3FE95D7A22D41D849934E408F239949B74D59EA459AFB8B2E9641903732B0F7BABD3081D3B85EE505BFEFA9ECC570BEA22BA4B7E282581749371EC30500DC6B7CDFCA5D68DCFD5D76B89869753B436A7C0A94
5FD32A1546CD3CB2F1507F4477C18EB83669D50E0993E178864AB52F83D2CFA690EE0A4F5EED8B4FF81C0A37962767AE68FE9DDD8D8D0A348C46BB55A9C31540A0636B232311EA06D5621FE42A4F749C56C9E8DBE2630FEA2AB6056C8F3F4F8A6FA801F1
4477F190971EA3C38EC0B0216C50D30872AEFD466817AA82B9286AE979C4807F5DBF8A4391F315DC84C355E18601BF7508871D24A0A93DFFCEA8A057DF16D647E196D9A0CBAAE839C0150F20AA4A4D776802B92E938CCD9293B85610AA12168FDBCEB6C6
ED9DF7A50E958980578A6D880831BD005C347BF6EDD63D722C1610114E2E586AED2352CEF71627AFA5C3E80366192E6BE421785BF8F0BDE4744D191E03F3A890A3F22D15DDB16C910615CB9ED5B7A185859BAD8E1BB9D5AC2AD92D841B9AA6CA314ABA6F
40169D1EB94060FA33F3DA803C4A8DFB67EB02C00CAE7712F9875BAC841FA818A45DA45139E76A02C46F2B419EB103981A64326386A86C95DE3A285BCA82427FB4372D0A3830CA7E1474EBB14C5879D64D014B9E6FA99FF6476D6FC8AE4442461D4ADCFF
8707DF927A1B8B533DC1E5975D0933A9EDCA7707C8C97BAF786E44E5E8C6BC00D2424EAA2D42F7C35D96014722AF1F2CA7EAA80B0DEFCF33D34838287B02F30231F9E7696E19015777297B17F6CEDE338D89B9BDBBC623C26AD8ECE3975498612BF9DF63
1B6DBB68349625052303D14C