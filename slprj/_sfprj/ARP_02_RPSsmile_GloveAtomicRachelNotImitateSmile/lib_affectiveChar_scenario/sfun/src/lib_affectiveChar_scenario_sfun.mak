# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = lib_affectiveChar_scenario
TARGET      = sfun
CHART_SRCS   = c3_lib_affectiveChar_scenario.c
MACHINE_SRC  = lib_affectiveChar_scenario_sfun.c
MACHINE_REG = 
MAKEFILE    = lib_affectiveChar_scenario_sfun.mak
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
    /I "C:\Users\Maryam\Documents\maryam-research\code\Matlab-M+M\slprj\_sfprj\ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile\lib_affectiveChar_scenario\sfun\src" 

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
OBJLIST_FILE = lib_affectiveChar_scenario_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "C:\MATLAB\R2014a\extern\lib\win32\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

$(MACHINE)_$(TARGET).lib : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
	@echo ### Linking ...
	$(LD) -lib /OUT:$(MACHINE)_$(TARGET).lib @$(OBJLIST_FILE) $(USER_LIBS) $(THIRD_PARTY_LIBS)
	@echo ### Created Stateflow library $@
.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


