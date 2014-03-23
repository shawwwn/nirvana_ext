# Microsoft Developer Studio Generated NMAKE File, Based on Nirvana_ext.dsp
!IF $(CFG)" == "
CFG=Nirvana_ext - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Nirvana_ext - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Nirvana_ext - Win32 Release" && "$(CFG)" != "Nirvana_ext - Win32 Debug"
!MESSAGE 指定的配置 "$(CFG)" 无效.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Nirvana_ext.mak" CFG="Nirvana_ext - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Nirvana_ext - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Nirvana_ext - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Nirvana_ext - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# 开始自定义宏
OutDir=.\Release
# 结束自定义宏

ALL : "$(OUTDIR)\Nirvana_ext.dll"


CLEAN :
	-@erase "$(INTDIR)\Nirvana_ext.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Nirvana_ext.dll"
	-@erase "$(OUTDIR)\Nirvana_ext.exp"
	-@erase "$(OUTDIR)\Nirvana_ext.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NIR_EXT_EXPORTS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Nirvana_ext.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\Nirvana_ext.pdb" /machine:I386 /out:"$(OUTDIR)\Nirvana_ext.dll" /implib:"$(OUTDIR)\Nirvana_ext.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Nirvana_ext.obj"

"$(OUTDIR)\Nirvana_ext.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Nirvana_ext - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# 开始自定义宏
OutDir=.\Debug
# 结束自定义宏

ALL : "$(OUTDIR)\Nirvana_ext.dll"


CLEAN :
	-@erase "$(INTDIR)\Nirvana_ext.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Nirvana_ext.dll"
	-@erase "$(OUTDIR)\Nirvana_ext.exp"
	-@erase "$(OUTDIR)\Nirvana_ext.ilk"
	-@erase "$(OUTDIR)\Nirvana_ext.lib"
	-@erase "$(OUTDIR)\Nirvana_ext.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NIRVANA_EXT_EXPORTS" /Fp"$(INTDIR)\Nirvana_ext.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Nirvana_ext.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\Nirvana_ext.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Nirvana_ext.dll" /implib:"$(OUTDIR)\Nirvana_ext.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Nirvana_ext.obj"

"$(OUTDIR)\Nirvana_ext.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Nirvana_ext.dep")
!INCLUDE "Nirvana_ext.dep"
!ELSE 
!MESSAGE Warning: cannot find "Nirvana_ext.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Nirvana_ext - Win32 Release" || "$(CFG)" == "Nirvana_ext - Win32 Debug"
SOURCE=.\Nirvana_ext.cpp

"$(INTDIR)\Nirvana_ext.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

