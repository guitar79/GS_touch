; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "GS_touch"
#define MyAppVersion "1.2"
#define MyAppPublisher "Kiehyun Park"
#define MyAppExeName "Setup.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)

AppId={{0F5BC3A2-6B4E-4A66-9FD1-FE5A97F8E628}
AppName=ASCOM GS_touch Focuser Driver (2022-02-01)
AppVersion=1.2
AppVerName=ASCOM GS_touch Focuser Driver 1.0.2 (2022-02-01)
AppPublisher=jiseong Gwak
VersionInfoVersion= 1.2
DefaultDirName="{cf}\ASCOM\Focuser"
DisableDirPage=yes
DisableProgramGroupPage=yes
OutputDir=C:\Users\Kiehyun\Documents\GS_touch\release
;OutputBaseFilename=JSFoucser 1.0.1(64bit) setup
OutputBaseFilename=Setup GS_touch 1.2(64bit) setup (2022-02-01)
Compression=lzma
SolidCompression=yes

WizardImageFile="C:\Program Files (x86)\ASCOM\Platform 6 Developer Components\Installer Generator\Resources\WizardImage.bmp"
LicenseFile="C:\Program Files (x86)\ASCOM\Platform 6 Developer Components\Installer Generator\Resources\CreativeCommons.txt"

UninstallFilesDir="{cf}\ASCOM\Uninstall\Focuser\GS_touch"

;ArchitecturesAllowed=x64
;ArchitecturesInstallIn64BitMode=x64

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Dirs]
Name: "{cf}\ASCOM\Uninstall\Focuser\GS_touch"

[Files]
Source: "C:\Users\Kiehyun\Documents\GS_touch\ASCOM Driver\GS_touch\GS_touch\bin\x64\Release\ASCOM.GS_touch.Focuser.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Kiehyun\Documents\GS_touch\release\ReadMe.htm"; DestDir: "{app}"; Flags: isreadme

[Run]
Filename: "{dotnet4032}\regasm.exe"; Parameters: "/codebase ""{app}\ASCOM.GS_touch.Focuser.dll"""; Flags: runhidden 32bit
Filename: "{dotnet4064}\regasm.exe"; Parameters: "/codebase ""{app}\ASCOM.GS_touch.Focuser.dll"""; Flags: runhidden 64bit; Check: IsWin64

; Only if driver is .NET
[UninstallRun]
; Only for .NET assembly/in-proc drivers
Filename: "{dotnet4032}\regasm.exe"; Parameters: "-u ""{app}\ASCOM.GS_touch.Focuser.dll"""; Flags: runhidden 32bit
; This helps to give a clean uninstall
Filename: "{dotnet4064}\regasm.exe"; Parameters: "/codebase ""{app}\ASCOM.GS_touch.Focuser.dll"""; Flags: runhidden 64bit; Check: IsWin64
Filename: "{dotnet4064}\regasm.exe"; Parameters: "-u ""{app}\ASCOM.GS_touch.Focuser.dll"""; Flags: runhidden 64bit; Check: IsWin64


[CODE]

// Code to enable the installer to uninstall previous versions of itself when a new version is installed
procedure CurStepChanged(CurStep: TSetupStep);
var
  ResultCode: Integer;
  UninstallExe: String;
  UninstallRegistry: String;
begin
  if (CurStep = ssInstall) then // Install step has started
	begin
      // Create the correct registry location name, which is based on the AppId
      UninstallRegistry := ExpandConstant('Software\Microsoft\Windows\CurrentVersion\Uninstall\{#SetupSetting("AppId")}' + '_is1');
      // Check whether an extry exists
      if RegQueryStringValue(HKLM, UninstallRegistry, 'UninstallString', UninstallExe) then
        begin // Entry exists and previous version is installed so run its uninstaller quietly after informing the user
          MsgBox('Setup will now remove the previous version.', mbInformation, MB_OK);
          Exec(RemoveQuotes(UninstallExe), ' /SILENT', '', SW_SHOWNORMAL, ewWaitUntilTerminated, ResultCode);
          sleep(1000);    //Give enough time for the install screen to be repainted before continuing
        end
  end;
end;