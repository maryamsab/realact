# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = ARP_02_RPSsmile_Glove_atomicError
TARGET      = sfun
CHART_SRCS   = c1_ARP_02_RPSsmile_Glove_atomicError.c c2_ARP_02_RPSsmile_Glove_atomicError.c c3_ARP_02_RPSsmile_Glove_atomicError.c c10_ARP_02_RPSsmile_Glove_atomicError.c
MACHINE_SRC  = ARP_02_RPSsmile_Glove_atomicError_sfun.c
MACHINE_REG = ARP_02_RPSsmile_Glove_atomicError_sfun_registry.c
MAKEFILE    = ARP_02_RPSsmile_Glove_atomicError_sfun.mak
MATLAB_ROOT  = C:\MATLAB\R2014a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\MATLAB\R2014a\extern\include" \
    /I "C:\MATLAB\R2014a\simulink\include" \
    /I "C:\MATLAB\R2014a\stateflow\c\mex\include" \
    /I "C:\MATLAB\R2014a\rtw\c\src" \
    /I "C:\Users\Maryam\Documents\maryam-research\code\Matlab-M+M\slprj\_sfprj\ARP_02_RPSsmile_Glove_atomicError\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = ARP_02_RPSsmile_Glove_atomicError_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = "C:\Users\Maryam\Documents\maryam-research\code\Matlab-M+M\slprj\_sfprj\ARP_02_RPSsmile_Glove_atomicError\lib_affectiveChar_scenario\sfun\src\lib_affectiveChar_scenario_sfun.lib" 
BLAS_LIBS = "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "C:\MATLAB\R2014a\extern\lib\win32\microsoft\sf_runtime.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmx.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmex.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmat.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libfixedpoint.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libut.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmwmathutil.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libemlrt.lib" "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmwsl_log_load_blocks.lib" "C:\MATLAB\R2014a\lib\win32\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


