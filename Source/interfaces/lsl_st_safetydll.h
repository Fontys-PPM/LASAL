(****************************************************************************************)
(*                                                                                      *)
(* lsl_st_safetydll.h                                                                   *)
(*                                                                                      *)
(* enthält die Definitionen für das Safety DLL Interface                                *)
(*                                                                                      *)
(*                                                                                      *)
(****************************************************************************************)
(*
  Die Funktionen des 'Safety DLL Interface' werden verwendet, um von einer Stanard-SPS 
  aus eine Kommunikationsverbindung zu einer Safe-CPU aufzubauen und folgende 
  Abläufe auszuführen:
  - Download einer Konfiguration
  - Setzen des Verified Flags
  - Ändern des Passworts
  - Starten der Safe-CPU (verlassen des Service-Modes)
  - Stoppen der Safe-CPU (herstellen des Service-Modes)
  - Statusabfrage
  - Neustart der Safety-Applikation
  
  Hinweis:
  Die Funktionen dürfen nicht dafür verwendet werden, um vollautomatisch einen Ablauf 
  durchzuführen. Es muss vom Programmersteller sichergestellt werden dass die Eingabedaten 
  vom Benutzer stammen und nicht im Programm hardcodiert werden.
*)
//HFILTER:1
#ifndef __LSL_ST_SAFETY_DLL
//HFILTER:
//HFILTER:2
#pragma once
//HFILTER:
#define __LSL_ST_SAFETY_DLL

// Interfacename
#define INTERFACE_SAFETY_DLL            "ISAFETY_DLL"

//
//Fehlercodes
//
(* Es konnte kein Safety-State angelegt werden (mit SAFETY_NEW_STATE), 
   weil bereits einer existiert.
*)
#define SAFETY_E_IN_USE                   9001

(* Beim Öffnen des für den Download vorgesehenen Files ist ein 
   Fehler aufgetreten.
*)
#define SAFETY_E_OPEN                     9002

(* Beim Lesen des für den Download vorgesehenen Files ist ein 
   Fehler aufgetreten.
*)
#define SAFETY_E_IO                       9003

(* Beim Lesen des für den Download vorgesehenen Files wurden 
   ungültige Daten erkannt.
*)
#define SAFETY_E_FILEDATA                 9004      

(* Ein Funktionsaufruf, der innerhalb einer gewissen Zeitspanne seit dem 
   Aufruf von SAFETY_SET_USERPROMPT_TIME stattfinden muss, ist ausserhalb 
   der Zeitspanne durchgeführt worden.
*)
#define SAFETY_E_INVALID_USERPROMPT_TIME  9005

(* Die Safety-DLL konnte nicht geladen werden, weil die erforderliche 
   Schnittstelle im Lasal-Betriebssystem nicht existiert oder eine 
   falsche Version aufweist-
*)
#define SAFETY_E_INVALID_CIL_VERSION      9006

(* Bei einem internen Funktionsaufruf wurden zu wendig Daten zurückgegeben.
*)
#define SAFETY_E_BUFFER_UNDERFLOW         9007

(* Ein als Funktionsparameter übergegener Buffer ist zu klein.
*)
#define SAFETY_E_BUF_TOO_SMALL            9008

(* Es steht zu wenig Speicher zur Verfügung (Heap).
*)
#define SAFETY_E_OUT_OF_MEM               9009

(* Beim Verbindungsaufbau wurde festgestellt, dass die vom Benutzer eingegebene 
   Sicherheitsnummer nicht mit der Sicherheitsnummer der Ziel-Safe-CPU 
   übereinstimmt.
*)
#define SAFETY_E_INVALID_SAFETY_NBR       9010

(* Beim internen Aufruf einer Hardwaretree-Funktion ist ein Fehler aufgetreten.
*)
#define SAFETY_E_HWT_CMD                  9011

(* Es wurde ein ungültiger Wert eines Funktionsparameters angegeben.
*)
#define SAFETY_E_INVALID_PARAM            9012

(* Beim Versuch, die Verbindung aufzubauen, wurde das Ziel-Modul nicht gefunden.
*)
#define SAFETY_E_MODULE_NOT_FOUND         9013

(* Bei der Antwort, die von der Safe-CPU empfangen wurde, ist eine ungültige 
   Sequenznummer erkannt worden.
*)
#define SAFETY_E_INVALID_SN_RSP           9100

(* Bei der Antwort, die von der Safe-CPU empfangen wurde, ist eine ungültige 
   Länge erkannt worden.
*)
#define SAFETY_E_INVALID_LEN_RSP          9101

(* In der Antwort, die von der Safe-CPU empfangen wurde, sind zu wenig Daten 
   vorhanden.
*)
#define SAFETY_E_TOO_LESS_DATA_RSP        9102

(* Bei der Antwort, die von der Safe-CPU empfangen wurde, ist eine ungültige 
   CRC erkannt worden.
*)
#define SAFETY_E_INVALID_CRC_RSP          9103

(* Bei der Antwort, die von der Safe-CPU empfangen wurde, ist ein ungültiger 
   Frametyp erkannt worden.
*)
#define SAFETY_E_INVALID_FRAMETYPE_RSP    9104

(* Bei der Antwort, die von der Safe-CPU empfangen wurde, ist eine ungültige 
   Adresse erkannt worden.
*)
#define SAFETY_E_INVALID_ADDR_RSP         9105

(* Die Antwort, die von der Safe-CPU erwartet wird, ist innerhalb einer 
   gewissen Zeit nicht empfangen worden.
*)
#define SAFETY_E_TIMEOUT_RSP              9106

(* Bei der Antwort, die von der Safe-CPU empfangen wurde, ist eine ungültige 
   Session-ID erkannt worden.
*)
#define SAFETY_E_INVALID_SESSID_RSP       9107

(* Ein Funktionsaufruf ist in einem ungültigen Zustand durchgeführt worden.
   Die Funktion SAFETY_FILE_GET_PRJNAME muss beispielsweise nach der 
   Funktion SAFETY_SET_FILE aufgerufen werden.
*)
#define SAFETY_E_INVALID_STATE            9200
#define SAFETY_E_INVALID_STATE_1          9201
#define SAFETY_E_INVALID_STATE_2          9202
#define SAFETY_E_INVALID_STATE_3          9203
#define SAFETY_E_INVALID_STATE_4          9204

(* In der Antwort, die von der Safe-CPU empfangen wurde, wird im Feld Returncode 
   ein Fehler angezeigt. Die Fehlernummer ist der Offset zur Basis 10000.
   Z.b. 10123 bedeutet Fehler 123 wurde von der Safe-CPU zurückgeschickt.
   Bsp. Safe-CPU-Error (SCP111):
   - 230: Invalid LogIn-Level
   - 234: Invalid Runstate
   
*)
#define SAFETY_E_SSDO_RESULT             10000

//
// Interface
//

(*
  Erstellt eine neuen Safety-State, der für den Aufruf der folgenden Funktionen 
  erforderlich ist. Muss am Anfang einmal aufgerufen werden.
  Im Safety-State werden folgende Elemente gespeichert:
    File-State: Zustand des Download-Files
      FS_IDLE        .. wenn noch kein Download-File angegeben wurde
      FS_FILE        .. wenn ein Download-File angegeben wurde und gelesen werden konnte
      FS_DOWNLOAD    .. wenn ein Download-File zur Safe-CPU übertragen wurde
    Connection-State: Zustand der Kommunikationsverbindung zur Safe-CPU
      CS_IDLE        .. wenn noch keine Sicherheitsnummer angegeben wurde
      CS_SAFETY_NBR  .. wenn eine Sicherheitsnummer angegeben wurde
      CS_CONNECTION  .. wenn eine Verbindung aufgebaut wurde
      CS_LOGGED_IN   .. wenn ein Login durchgeführt wurde (Developer-Login)
    UserPromptTime: Zeitpunkt des Aufrufs von SetUserPromptTime
    Prj-Name: Name des im Download-File angegebenen Projekts
    Rev-Nbr: Revisions-Nummer des im Download-File angegebenen Projekts
    Scpu-Name: Name der im Download-File angegebenen Ziel Safe-CPU
    HW-Path: Hardware-Pfad zur Ziel Safe-CPU

  Setzt den File-State auf FS_IDLE und den Connection-State auf CS_IDLE.

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_NewState
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_NEW_STATE(pCil)                pCil^.NewState $ P_Safety_NewState()

(*
  Entfernt den Safety-State.
  Muss am Ende aufgerufen werden. Eine aufrechte Kommunikationsverbindung zur Safe-CPU 
  wird geschlossen.

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_DeleteState
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_DELETE_STATE(pCil)             pCil^.DeleteState $ P_Safety_DeleteState()

(*
  Gibt das File an, das vom Safety-Designer für den Download erstellt wurde.

  Setzt den File-State auf FS_FILE wenn das File geöffnet und gelesen werden kann.

  Voraussetzung: File-State == FS_IDLE

  \param Name des Files (0-terminierter String)
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetFile
VAR_INPUT
  filename : ^CHAR;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_FILE(pCil,p1)              pCil^.SetFile $ P_Safety_SetFile(p1)

(*
  Liefert den im Download-File gespeicherten Projektnamen.

  Voraussetzung: File-State >= FS_FILE

  \param prjName Buffer in den der Projektname als 0-terminierter String geschrieben wird
  \param bufSize_prjName Größe des Buffers
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_FileGetPrjName
VAR_INPUT
  prjName : ^CHAR;
  bufsizePrjName : UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_FILE_GET_PRJNAME(pCil,p1,p2)   pCil^.FileGetPrjName $ P_Safety_FileGetPrjName(p1,p2)

(*
  Liefert die im Download-File gespeicherte Revisionsnummer.

  Voraussetzung: File-State >= FS_FILE

  \param revNbr Buffer in den die Revisionsnummer als 0-terminierter String geschrieben wird
  \param bufSize_revNbr Größe des Buffers
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_FileGetRevNbr
VAR_INPUT
  revNbr : ^CHAR;
  bufsizeRevNbr : UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_FILE_GET_REVNBR(pCil,p1,p2)    pCil^.FileGetRevNbr $ P_Safety_FileGetRevNbr(p1,p2)

(*
  Liefert den im Download-File gespeicherten SCPU-Namen.

  Voraussetzung: File-State >= FS_FILE

  \param scpuName Buffer in den der SCPU-Name als 0-terminierter String geschrieben wird
  \param bufSize_scpuName Größe des Buffers
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_FileGetScpuName
VAR_INPUT
  scpuName : ^CHAR;
  bufsizeScpuName : UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_FILE_GET_SCPUNAME(pCil,p1,p2)  pCil^.FileGetScpuName $ P_Safety_FileGetScpuName(p1,p2)

(*
  Muss aufgerufen werden, wenn vom Benutzer eine Eingabe angefordert wird. 
  Der Zeitpunkt dieses Aufrufs wird gemerkt und wird dann später für eine 
  Überprüfung der Plausibilität der Eingabe verwendet (es darf z.B. SetSafetyNbr 
  nicht unmittelbar nach SetUserPromptTime aufgerufen werden).

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetUserPromptTime
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_USERPROMPT_TIME(pCil)      pCil^.SetUserPromptTime $ P_Safety_SetUserPromptTime()

(*
  Deaktiviert die Prüfung der Aufrufzeitpunkte der Funktionen für die 
  Benutzereingaben. Wird verwendet, um einen Ablauf ohne Benutzereingabe 
  auszuführen. Darf nur für dafür vorgesehene Abläufe verwendet werden.

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_DisableUserPromptCheck
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_DISABLE_USERPROMPT_CHECK(pCil)      pCil^.DisableUserPromptCheck $ P_Safety_DisableUserPromptCheck()

(*
  Übernimmt die vom Anwender eingegebene Sicherheitsnummer der Ziel-Safe-CPU.
  Beim Verbindungsaufbau zur Safe-CPU wird geprüft, ob diese Sicherheitsnummer 
  mit der Sicherheitsnummer in der Safe-CPU übereinstimmt.

  Vor dem Aufruf dieser Funktion muss SetUserPromptTime aufgerufen werden und die 
  Sicherheitsnummer muss vom Benutzer angeforder werdem. Nach dem Aufruf von 
  SetUserPromptTime muss der Aufruf dieser Funktion innerhalb von 1 bis 60 Sekunden 
  stattfinden.
  
  Setzt Connection-State auf SAFETY_NBR

  Voraussetzung: Connection-State == IDLE

  \param safetyNbr die Sicherheitsnummer
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetSafetyNbr
VAR_INPUT
  safetyNbr : UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_SAFETY_NBR(pCil,p1)        pCil^.SetSafetyNbr $ P_Safety_SetSafetyNbr(p1)

(*
  Stellt eine Kommunikationsverbindung zur Ziel Safe-CPU mit der zuvor angegebenen 
  Sicherheitsnummer her.
  Wenn ein Download-File angegeben worden ist, dann wird für die nicht sichere 
  Netzwerkadresse der Hardware-Pfad aus dem Download-File verwendet, andernfalls 
  werden alle angeschlossenen Safe-CPUs aufgelistet und diejenige mit der 
  passenden Sicherheitsnummer herausgesucht.

  Zu beachten ist, dass bei einer aufrechten Kommunikationsverbindung regelmäßig 
  eine Kommunikation stattfinden muss, sonst wird diese nach einer Timeoutzeit 
  von 10 Sekunden von der Safe-CPU geschlossen.

  Setzt Connection-State auf CONNECTION

  Voraussetzung: Connection-State == SAFETY_NBR

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_OpenConnection
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_OPEN_CONNECTION(pCil)          pCil^.OpenConnection $ P_Safety_OpenConnection()

(*
  Stellt eine Kommunikationsverbindung zu der im File gespeicherten Safe-CPU 
  her und fragt die Sicherheitsnummer ab.

  Voraussetzung: File-State >= FS_FILE

  \param pSafetyNbr Zeiger auf die Variable, in der die abgefragte Sicherheitsnummer 
      geschrieben wird
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_GetSafetyNbr
VAR_INPUT
  pSafetyNbr : ^UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_GET_SAFETY_NBR(pCil,p1)        pCil^.GetSafetyNbr $ P_Safety_GetSafetyNbr(p1)

(*
  Ein- oder Ausloggen auf der Ziel Safe-CPU.

  Vor dem Aufruf dieser Funktion muss SetUserPromptTime aufgerufen werden und das  
  Passwort muss vom Benutzer angeforder werdem. Nach dem Aufruf von 
  SetUserPromptTime muss der Aufruf dieser Funktion innerhalb von 1 bis 60 Sekunden 
  stattfinden.
  
  Setzt Connection-State auf CS_LOGGED_IN

  Voraussetzung: Connection-State == CS_CONNECTION

  \param level der Login-Level (0=ausloggen, 1=Debug-Level, 2=Configuration-Level)
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_Login
VAR_INPUT
  level : USINT;
  password : ^CHAR;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_LOGIN(pCil,p1,p2)              pCil^.Login $ P_Safety_Login(p1,p2)

(*
  Weist die Safe-CPU an, in den Run-Status 'SERVICE' zu wechseln.

  Voraussetzung: Connection-State == CS_LOGGED_IN

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetServiceMode
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_SERVICE_MODE(pCil)         pCil^.SetServiceMode $ P_Safety_SetServiceMode()

(*
  Weist die Safe-CPU an, vorübergehend in den Run-Status 'SERVICE' zu wechseln. 
  Die Applikation wird dadurch neu gestartet.

  Voraussetzung: Connection-State >= CS_CONNECTION

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetTempServiceMode
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_TEMP_SERVICE_MODE(pCil)    pCil^.SetTempServiceMode $ P_Safety_SetTempServiceMode()

(*
  Weist die Safe-CPU an, den Run-Status 'SERVICE' zu verlassen.

  Voraussetzung: Connection-State == CS_LOGGED_IN

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_LeaveServiceMode
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_LEAVE_SERVICE_MODE(pCil)       pCil^.LeaveServiceMode $ P_Safety_LeaveServiceMode()

(*
  Überträgt einen Teil des zuvor angegebenen Download-File zur Safe-CPU.
  Vor dem ersten Aufruf muss die Anzahl der bereits übertragenen Bytes 
  (pBytesTransferred) auf 0 gesetzt werden. Die Übertragung ist beendet, 
  sobald die Anzahl der bereits übertragenen Bytes der Anzahl der insgesamt 
  zu übertragenden Bytes (pTransferSize) entspricht.

  Voraussetzung: Connection-State == CS_LOGGED_IN und File-State == FS_FILE

  \param pBytesTransferred [in,out] Zeiger auf die Variable in der die bereits 
      übertragenen Bytes gespeichert sind. Der Wert dieser Variablen muss 
      vor dem ersten Aufruf auf 0 gesetzt werden. Nach dem Aufruf dieser Funktion 
      ist in dieser Variablen die Anzahl der bisher übertragenen Bytes 
      gespeichert.
  \param pBytesTransferred [out] Zeiger auf die Variable in die die Anzahl 
      der insgesamt zu übertragenden Bytes geschrieben wird.
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_DownloadFile
VAR_INPUT
  pBytesTransferred : ^UDINT;
  pTransferSize : ^UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_DOWNLOAD_FILE(pCil,p1,p2)      pCil^.DownloadFile $ P_Safety_DownloadFile(p1,p2)

(*
  Bestätigt eine erfolgreiche Übertragung des Download-Files indem der Konfigurations-Status 
  in der Safe-CPU auf 'konfiguriert + nicht-verifiziert + nicht-verteilt' gesetzt wird.

  Vor dem Aufruf dieser Funktion muss SetUserPromptTime aufgerufen werden und vom 
  Benutzer muss eine Bestätigung über die erfolgreiche Übertragung angefordert werden. 
  Dabei muss der Projektname, die Revisionsnummer und der Safe-CPU-Name angezeigt werden.
  Nach dem Aufruf von SetUserPromptTime muss der Aufruf dieser Funktion innerhalb von 
  1 bis 60 Sekunden stattfinden.
  
  Voraussetzung: Connection-State == CS_LOGGED_IN und File-State == FS_DOWNLOAD

  \param prjName der Name des Projekts, der im Downloadfile gespeichert ist
  \param revNbr die Revisionsnummer des Projekts, die im Downloadfile gespeichert ist
  \param scpuName der Name des Safe-CPU, der im Downloadfile gespeichert ist
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetConfigured
VAR_INPUT
  prjName : ^CHAR;
  revNbr : ^CHAR;
  scpuName : ^CHAR;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_CONFIGURED(pCil,p1,p2,p3)  pCil^.SetConfigured $ P_Safety_SetConfigured(p1,p2,p3)

(*
  Setzt den Konfigurations-Status in der Safe-CPU auf 'verifiziert'.

  Vor dem Aufruf dieser Funktion muss SetUserPromptTime aufgerufen werden und vom 
  Benutzer muss eine Bestätigung über den Verifiziervorgang angefordert werden. 
  Dabei muss der Projektname, die Revisionsnummer und der Safe-CPU-Name angezeigt werden.
  Nach dem Aufruf von SetUserPromptTime muss der Aufruf dieser Funktion innerhalb von 
  1 bis 60 Sekunden stattfinden.
  
  Voraussetzung: Connection-State == CS_LOGGED_IN und File-State == FS_FILE

  \param prjName der Name des Projekts, der im Downloadfile gespeichert ist
  \param revNbr die Revisionsnummer des Projekts, die im Downloadfile gespeichert ist
  \param scpuName der Name des Safe-CPU, der im Downloadfile gespeichert ist
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_SetVerified
VAR_INPUT
  prjName : ^CHAR;
  revNbr : ^CHAR;
  scpuName : ^CHAR;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_VERIFIED(pCil,p1,p2,p3)    pCil^.SetVerified $ P_Safety_SetVerified(p1,p2,p3)

(*
  Ändert das Passwort auf der Ziel Safe-CPU.

  Vor dem Aufruf dieser Funktion muss SetUserPromptTime aufgerufen werden und vom 
  Benutzer muss der Login-Level, das alte und das neue Passwort angefordert werden. 
  Nach dem Aufruf von SetUserPromptTime muss der Aufruf dieser Funktion innerhalb von 
  1 bis 60 Sekunden stattfinden.
  
  Voraussetzung: Connection-State >= CS_CONNECTION und File-State >= FS_FILE

  \param level der Login-Level (1=Debug-Level, 2=Configuration-Level)
  \param oldPassword das alte Passwort. Größe 8 Bytes. Wenn das Passwort kleiner 
      als 8 Zeichen ist, muss der Rest mit Leerzeichn aufgefüllt werden
  \param newPassword das neue Passwort. Größe 8 Bytes. Wenn das Passwort kleiner 
      als 8 Zeichen ist, muss der Rest mit Leerzeichn aufgefüllt werden
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_ChangePassword
VAR_INPUT
  level : USINT;
  oldPassword : ^CHAR;
  newPassword : ^CHAR;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_CHANGE_PASSWORD(pCil,p1,p2,p3) pCil^.ChangePassword $ P_Safety_ChangePassword(p1,p2,p3)

(*
  Liefert den Run-Status der Safe-CPU.

  Voraussetzung: Connection-State >= CS_CONNECTION

  \param pRunState Zeiger auf eine Variable, in die der Run-Status geschrieben wird.
    Werte:
       1 = POST
       2 = SERVICE
       4 = ERROR
       8 = IDLE
      16 = CHK_CFG
      32 = OP_TEMP
      64 = OP
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_GetRunState
VAR_INPUT
  pRunState : ^USINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_GET_RUNSTATE(pCil,p1)          pCil^.GetRunState $ P_Safety_GetRunState(p1)

(*
  Liefert den Konfigurations-Status der Safe-CPU.

  Voraussetzung: Connection-State >= CS_CONNECTION

  \param pCfgState Zeiger auf eine Variable, in die der Konfigurations-Status geschrieben wird.
    Werte:
       1 = INVALID
       2 = NOT_CONFIGURED
       4 = CONFIGURED_NOT_DEPLOYED_NOT_VERIFIED
       8 = CONFIGURED_AND_VERIFIED
      16 = CONFIGURED_DEPLOYED_NOT_VERIFIED
      36 = CONFIGURED_NOT_DEPLOYED_NOT_VERIFIED_DEV
      48 = CONFIGURED_DEPLOYED_NOT_VERIFIED_DEV
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_GetCfgState
VAR_INPUT
  pCfgState : ^USINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_GET_CFGSTATE(pCil,p1)          pCil^.GetCfgState $ P_Safety_GetCfgState(p1)

(*
  Schickt einen Quit-Error Befehl an die Safe-CPU.

  Voraussetzung: Connection-State >= CS_CONNECTION

  \param quitRemoteModules 
      0=es wird nur der Fehler im angesprochenen Modul quittiert
    <>0=die Safe-CPU schickt zusätzlich an die entfernten Module einen Quit-Error Befehl
      Anm.: Dieser Parameter wird in der Safe-CPU erst ab Version 337 berücksichtigt
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_QuitError
VAR_INPUT
  quitRemoteModules : USINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_QUIT_ERROR(pCil,p1)    pCil^.QuitError $ P_Safety_QuitError(p1)


(*
 * Setzt den Pfad für das Image.
 * \param imagepath Dateipfad des Images
 * \ return 0 wenn kein Fehler, sonst Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Set_Image_Fw
VAR_INPUT
  pImagePath : ^CHAR;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_SET_IMAGE_FW(pCil,p1)    pCil^.SetImageFw $ P_Set_Image_Fw(p1)

(*
  Prüft, ob eine SCPU mit Dongle im System enthalten ist.
  \param  safeyNbr Sicherheitsnummer des Moduls mit dem Dongle
  \return 0 wenn kein Fehler und Dongle gefunden, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Check_Dongle_FW
VAR_INPUT
  safetyNbr : UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_CHECK_DONGLE_FW(pCil,p1)    pCil^.CheckDongleFW $ P_Check_Dongle_FW(p1)

(*
  Firmware Download.
  Überträgt einen Teil des zuvor angegebenen FW-Image zur Safe-CPU.
  Vor dem ersten Aufruf muss die Anzahl der bereits übertragenen Bytes 
  (pBytesTransferred) auf 0 gesetzt werden. Die Übertragung ist beendet, 
  sobald die Anzahl der bereits übertragenen Bytes der Anzahl der insgesamt 
  zu übertragenden Bytes (pTransferSize) entspricht.

  Voraussetzung: Connection-State == CS_LOGGED_IN und File-State == FW_FILE

  \param pBytesTransferred [in,out] Zeiger auf die Variable in der die bereits 
      übertragenen Bytes gespeichert sind. Der Wert dieser Variablen muss 
      vor dem ersten Aufruf auf 0 gesetzt werden. Nach dem Aufruf dieser Funktion 
      ist in dieser Variablen die Anzahl der bisher übertragenen Bytes 
      gespeichert.
  \param pTransferSize [out] Zeiger auf die Variable in die die Anzahl 
      der insgesamt zu übertragenden Bytes geschrieben wird.
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Download_FW
VAR_INPUT
  pBytesTransferred : ^UDINT;
  pTransferSize : ^UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_DOWNLOAD_FW(pCil,p1,p2)    pCil^.DownloadFW $ P_Download_FW(p1,p2)

(*
  Liefert die im Image-File gespeicherte Modul-ID

  Voraussetzung: File-State >= FW_FILE

  \param pModID [out] Buffer in den die Modul-ID geschrieben wird
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Get_Image_Modul_ID_Fw
VAR_INPUT
  pModID : ^UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_GET_IMAGE_MOD_ID_FW(pCil,p1)    pCil^.GetImageModulIdFW $ P_Get_Image_Modul_ID_Fw(p1)

(*
  Liefert die im Image-File gespeicherte Minor Version

  Voraussetzung: File-State >= FW_FILE

  \param pVersion [out] Buffer in den die Minor Version geschrieben wird
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Get_Image_Version_Fw
VAR_INPUT
  pVersion : ^UDINT;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_GET_IMAGE_VERSION_FW(pCil,p1)    pCil^.GetImageVersionFW $ P_Get_Image_Version_Fw(p1)

#pragma pack (push, 1)
TYPE
  SAFETY_MODUL_VERSION : STRUCT
    minorVersion : UDINT;
    majorVersion : UINT;
    modType      : UINT;
    bcVersion    : UDINT;
  END_STRUCT;
END_TYPE
#pragma pack (pop)

(*
  Liefert die Version des Safety-Moduls

  Voraussetzung: File-State >= FW_FILE

  \param pVersion [out] Buffer in den die Minor Version geschrieben wird
  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Get_Modul_Version_Fw
VAR_INPUT
  pVersion : ^SAFETY_MODUL_VERSION;
END_VAR
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_GET_MODUL_VERSION_FW(pCil,p1)    pCil^.GetModulVersionFW $ P_Get_Modul_Version_Fw(p1)

(*
  Löscht die Konfiguration von einem Safety-Modul.

  Man muss mindestens mit dem it dem Konfig-Level eingeloggt sein.

  \return 0 wenn kein Fehler, sonst der Fehlercode
*)
FUNCTION __CDECL GLOBAL P_Safety_ClearConfig
VAR_OUTPUT
  retval : DINT;
END_VAR;
#define SAFETY_CLEAR_CONFIG(pCil)    pCil^.ClearConfig $ P_Safety_ClearConfig()


#pragma pack (push, 1)
TYPE
  OS_SAFETY_DLL : STRUCT
    version : UDINT;
    NewState : pVoid;
    DeleteState : pVoid;
    SetFile : pVoid;
    FileGetPrjName : pVoid;
    FileGetRevNbr : pVoid;
    FileGetScpuName : pVoid;
    SetUserPromptTime : pVoid;
    SetSafetyNbr : pVoid;
    OpenConnection : pVoid;
    Login : pVoid;
    SetServiceMode : pVoid;
    LeaveServiceMode : pVoid;
    DownloadFile : pVoid;
    SetConfigured : pVoid;
    SetVerified : pVoid;
    ChangePassword : pVoid;
    GetRunState : pVoid;
    GetCfgState : pVoid;
    // since version 2:
    GetSafetyNbr : pVoid;
    // since version 3:
    SetTempServiceMode : pVoid;
    // since version 4:
    QuitError : pVoid;
    // since version 5:
    DisableUserPromptCheck : pVoid;
    // since version 7
    SetImageFw : pVoid;
    CheckDongleFW : pVoid;
    DownloadFW : pVoid;
    GetImageModulIdFW : pVoid;
    GetImageVersionFW : pVoid;
    GetModulVersionFW : pVoid;
    // since version 8
    ClearConfig : pVoid;
  END_STRUCT;
END_TYPE
#pragma pack (pop)

//HFILTER:1
#endif
//HFILTER:
