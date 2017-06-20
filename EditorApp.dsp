# Microsoft Developer Studio Project File - Name="EditorApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=EditorApp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "EditorApp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "EditorApp.mak" CFG="EditorApp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "EditorApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "EditorApp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "EditorApp - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../controllib/package/include" /I "../mathlib" /I "./Engine" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib opengl32.lib glu32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /out:"bin/EditorApp.exe"

!ELSEIF  "$(CFG)" == "EditorApp - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "../controllib/package/include" /I "../mathlib" /I "./Engine" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib opengl32.lib glu32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"EditorApp_dbg.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "EditorApp - Win32 Release"
# Name "EditorApp - Win32 Debug"
# Begin Group "Main"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Document.cpp
# End Source File
# Begin Source File

SOURCE=.\Document.h
# End Source File
# Begin Source File

SOURCE=.\MainForm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainForm.h
# End Source File
# Begin Source File

SOURCE=.\MainToolBox.cpp
# End Source File
# Begin Source File

SOURCE=.\MainToolBox.h
# End Source File
# Begin Source File

SOURCE=.\RenderWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\RenderWindow.h
# End Source File
# Begin Source File

SOURCE=.\WorkspaceToolBox.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkspaceToolBox.h
# End Source File
# End Group
# Begin Group "Objects"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Engine\AnimationObject.h
# End Source File
# Begin Source File

SOURCE=.\Engine\RenderArgs.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\RenderArgs.h
# End Source File
# Begin Source File

SOURCE=.\Engine\RenderObject.h
# End Source File
# Begin Source File

SOURCE=.\Engine\SelectionArgs.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\SelectionArgs.h
# End Source File
# Begin Source File

SOURCE=.\Engine\SelectionHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\SelectionHandler.h
# End Source File
# Begin Source File

SOURCE=.\Engine\SelectionObject.h
# End Source File
# End Group
# Begin Group "Tools"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CameraPropertieBox.cpp
# End Source File
# Begin Source File

SOURCE=.\CameraPropertieBox.h
# End Source File
# Begin Source File

SOURCE=.\CameraTool.cpp
# End Source File
# Begin Source File

SOURCE=.\CameraTool.h
# End Source File
# Begin Source File

SOURCE=.\SelectionPropertieBox.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectionPropertieBox.h
# End Source File
# Begin Source File

SOURCE=.\SelectionTool.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectionTool.h
# End Source File
# Begin Source File

SOURCE=.\Tool.h
# End Source File
# Begin Source File

SOURCE=.\ToolArgs.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolArgs.h
# End Source File
# Begin Source File

SOURCE=.\ToolFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolFactory.h
# End Source File
# Begin Source File

SOURCE=.\ToolManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolManager.h
# End Source File
# End Group
# Begin Group "Engine"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Engine\Camera.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\Camera.h
# End Source File
# Begin Source File

SOURCE=.\Engine\Camera2D.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\Camera2D.h
# End Source File
# Begin Source File

SOURCE=.\Engine\Camera3D.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\Camera3D.h
# End Source File
# Begin Source File

SOURCE=.\Engine\Engine.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\Engine.h
# End Source File
# Begin Source File

SOURCE=.\Engine\Keys.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine\Keys.h
# End Source File
# End Group
# Begin Group "Common"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Collection.h
# End Source File
# Begin Source File

SOURCE=..\ControlLib\package\include\controls.h
# End Source File
# Begin Source File

SOURCE=..\MathLib\mathlib.h
# End Source File
# End Group
# Begin Group "Workspace"

# PROP Default_Filter ""
# Begin Group "Interfaces"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\IMesh.h
# End Source File
# Begin Source File

SOURCE=.\IMeshGroup.h
# End Source File
# Begin Source File

SOURCE=.\IModel.h
# End Source File
# Begin Source File

SOURCE=.\ISequence.h
# End Source File
# Begin Source File

SOURCE=.\ISkeleton.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Joint.h
# End Source File
# Begin Source File

SOURCE=.\KeyFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyFrame.h
# End Source File
# Begin Source File

SOURCE=.\Material.cpp
# End Source File
# Begin Source File

SOURCE=.\Material.h
# End Source File
# Begin Source File

SOURCE=.\Mesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Mesh.h
# End Source File
# Begin Source File

SOURCE=.\MeshGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\MeshGroup.h
# End Source File
# Begin Source File

SOURCE=.\Model.cpp
# End Source File
# Begin Source File

SOURCE=.\Model.h
# End Source File
# Begin Source File

SOURCE=.\Motion.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion.h
# End Source File
# Begin Source File

SOURCE=.\Point.cpp
# End Source File
# Begin Source File

SOURCE=.\Point.h
# End Source File
# Begin Source File

SOURCE=.\Sequence.cpp
# End Source File
# Begin Source File

SOURCE=.\Sequence.h
# End Source File
# Begin Source File

SOURCE=.\Skeleton.cpp
# End Source File
# Begin Source File

SOURCE=.\Skeleton.h
# End Source File
# Begin Source File

SOURCE=.\Triangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Triangle.h
# End Source File
# Begin Source File

SOURCE=.\Vertex.cpp
# End Source File
# Begin Source File

SOURCE=.\Vertex.h
# End Source File
# Begin Source File

SOURCE=.\Workspace.cpp
# End Source File
# Begin Source File

SOURCE=.\Workspace.h
# End Source File
# End Group
# Begin Group "Reference"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ControlLib\package\lib\Controls.lib
# End Source File
# Begin Source File

SOURCE=..\MathLib\Debug\MathLib.lib
# End Source File
# End Group
# Begin Group "Resource"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# Begin Source File

SOURCE=.\snowflake.ico
# End Source File
# End Group
# Begin Group "FileLoaders"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\IFileLoader.h
# End Source File
# Begin Source File

SOURCE=.\MS3DLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\MS3DLoader.h
# End Source File
# End Group
# End Target
# End Project
