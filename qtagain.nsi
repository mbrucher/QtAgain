
# define name of installer
OutFile "QtAgain installer.exe"
Caption "QtAgain"
# define installation directory
InstallDir $PROGRAMFILES\Steinberg\VstPlugins\QtAgain

DirText "VST installation folder"

Page directory
Page instfiles
UninstPage uninstConfirm
UninstPage instfiles

Function .onInit
    MessageBox MB_YESNO "Beware, you'll need Microsoft Visual C++ 2008 Redistributable Package (x86) to use this plugin. Do you wish to continue?" IDYES gogogo
    Abort
  gogogo:
FunctionEnd

# start default section
Section "QtAgain VST Plugin"
SectionIn 1 1
    # set the installation directory as the destination for the following actions
    SetOutPath $INSTDIR
 
    # create the uninstaller
    WriteUninstaller "$INSTDIR\uninstall.exe"
 
    # define what to install and place it in the output path
    File "QtAgain.dll"
    File "$%QTDIR%\bin\QtCore4.dll"
    File "$%QTDIR%\bin\QtGui4.dll"
    File "$%QTDIR%\bin\QtSolutions_MFCMigrationFramework-2.8.dll"
SectionEnd

# uninstaller section start
Section "Uninstall"
 
    # first, delete the uninstaller
    Delete "$INSTDIR\uninstall.exe"
    Delete "$INSTDIR\QtAgain.dll"
    Delete "$INSTDIR\QtCore4.dll"
    Delete "$INSTDIR\QtGui4.dll"
    Delete "$INSTDIR\QtSolutions_MFCMigrationFramework-2.8.dll"
    RMDir $INSTDIR 
    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\QtAgain"

# uninstaller section end
SectionEnd

Section -PostInstall
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\QtAgain" "DisplayName" "QtAgain (uninstall)"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\QtAgain" "UninstallString" '"$INSTDIR\uninstall.exe"'
SectionEnd
