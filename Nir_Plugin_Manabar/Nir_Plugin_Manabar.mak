# Microsoft Developer Studio Generated NMAKE File, Based on Nir_Plugin_Manabar.dsp
!IF $(CFG)" == "
CFG=Nir_Plugin_Manabar - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Nir_Plugin_Manabar - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Nir_Plugin_Manabar - Win32 Release" && "$(CFG)" != "Nir_Plugin_Manabar - Win32 Debug"
!MESSAGE 指定的配置 "$(CFG)" 无效.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Nir_Plugin_Manabar.mak" CFG="Nir_Plugin_Manabar - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Nir_Plugin_Manabar - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Nir_Plugin_Manabar - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF $(OS)" == "Windows_NT
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Nir_Plugin_Manabar - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# 开始自定义宏
OutDir=.\Release
# 结束自定义宏

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Nir_Plugin_Manabar.dll"

!ELSE 

ALL : "Nirvana_ext - Win32 Release" "$(OUTDIR)\Nir_Plugin_Manabar.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"Nirvana_ext - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\Nir_Plugin_Manabar.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.dll"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.exp"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NIR_PLUGIN_MANABAR_EXPORTS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Nir_Plugin_Manabar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\Nir_Plugin_Manabar.pdb" /machine:I386 /out:"$(OUTDIR)\Nir_Plugin_Manabar.dll" /implib:"$(OUTDIR)\Nir_Plugin_Manabar.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Nir_Plugin_Manabar.obj" \
	"..\Release\Nirvana_ext.lib"

"$(OUTDIR)\Nir_Plugin_Manabar.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Nir_Plugin_Manabar - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# 开始自定义宏
OutDir=.\Debug
# 结束自定义宏

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Nir_Plugin_Manabar.dll"

!ELSE 

ALL : "Nirvana_ext - Win32 Debug" "$(OUTDIR)\Nir_Plugin_Manabar.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"Nirvana_ext - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\Nir_Plugin_Manabar.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.dll"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.exp"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.ilk"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.lib"
	-@erase "$(OUTDIR)\Nir_Plugin_Manabar.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NIR_PLUGIN_MANABAR_EXPORTS" /Fp"$(INTDIR)\Nir_Plugin_Manabar.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Nir_Plugin_Manabar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\Nir_Plugin_Manabar.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Nir_Plugin_Manabar.dll" /implib:"$(OUTDIR)\Nir_Plugin_Manabar.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Nir_Plugin_Manabar.obj" \
	"..\Debug\Nirvana_ext.lib"

"$(OUTDIR)\Nir_Plugin_Manabar.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Nir_Plugin_Manabar.dep")
!INCLUDE "Nir_Plugin_Manabar.dep"
!ELSE 
!MESSAGE Warning: cannot find "Nir_Plugin_Manabar.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Nir_Plugin_Manabar - Win32 Release" || "$(CFG)" == "Nir_Plugin_Manabar - Win32 Debug"
SOURCE=.\Nir_Plugin_Manabar.cpp

"$(INTDIR)\Nir_Plugin_Manabar.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "Nir_Plugin_Manabar - Win32 Release"

"Nirvana_ext - Win32 Release" : 
   cd "\Program Files\VC6cn\MyProjects\Nirvana_ext"
   $(MAKE) /$(MAKEFLAGS) /F ".\Nirvana_ext.mak" CFG="Nirvana_ext - Win32 Release" 
   cd ".\Nir_Plugin_Manabar"

"Nirvana_ext - Win32 ReleaseCLEAN" : 
   cd "\Program Files\VC6cn\MyProjects\Nirvana_ext"
   $(MAKE) /$(MAKEFLAGS) /F ".\Nirvana_ext.mak" CFG="Nirvana_ext - Win32 Release" RECURSE=1 CLEAN 
   cd ".\Nir_Plugin_Manabar"

!ELSEIF  "$(CFG)" == "Nir_Plugin_Manabar - Win32 Debug"

"Nirvana_ext - Win32 Debug" : 
   cd "\Program Files\VC6cn\MyProjects\Nirvana_ext"
   $(MAKE) /$(MAKEFLAGS) /F ".\Nirvana_ext.mak" CFG="Nirvana_ext - Win32 Debug" 
   cd ".\Nir_Plugin_Manabar"

"Nirvana_ext - Win32 DebugCLEAN" : 
   cd "\Program Files\VC6cn\MyProjects\Nirvana_ext"
   $(MAKE) /$(MAKEFLAGS) /F ".\Nirvana_ext.mak" CFG="Nirvana_ext - Win32 Debug" RECURSE=1 CLEAN 
   cd ".\Nir_Plugin_Manabar"

!ENDIF 


!ENDIF 

