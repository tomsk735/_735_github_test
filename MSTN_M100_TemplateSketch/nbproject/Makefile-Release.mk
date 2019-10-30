#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=arm-none-eabi-gcc
CCC=arm-none-eabi-g++
CXX=arm-none-eabi-g++
FC=gfortran
AS=arm-none-eabi-as

# Macros
CND_PLATFORM=MSTN-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Startup/startup_mstn_MDR32F9Qx.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/morze.o \
	${OBJECTDIR}/src/rxtx.o


# C Compiler Flags
CFLAGS=-mcpu=cortex-m3 -mthumb -MD -Wall -O2 -fdata-sections -ffunction-sections

# CC Compiler Flags
CCFLAGS=-mcpu=cortex-m3 -mthumb -MD -Wall -O2 -fdata-sections -ffunction-sections -fno-exceptions
CXXFLAGS=-mcpu=cortex-m3 -mthumb -MD -Wall -O2 -fdata-sections -ffunction-sections -fno-exceptions

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Intec/MSTN/M100/Lib/arm-none-eabi -u _printf_float -mcpu=cortex-m3 -mthumb -lstdc++ -nostartfiles -lm -N -Ttext=0x08003000 -Tdata=0x20000000 --specs=nano.specs -Wl,--start-group -lgcc -lc -lm -lMSTN-M100 -Wl,--end-group -Wl,-gc-sections -ffreestanding

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mstn_m100_templatesketch.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mstn_m100_templatesketch.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mstn_m100_templatesketch ${OBJECTFILES} ${LDLIBSOPTIONS} -TC:/Intec/MSTN/M100/Lib/arm-none-eabi/MSTN_M100_User.ld -Wl,--start-group -lgcc -lc -lm -lMSTN-M100 -Wl,--end-group

${OBJECTDIR}/Startup/startup_mstn_MDR32F9Qx.o: Startup/startup_mstn_MDR32F9Qx.S
	${MKDIR} -p ${OBJECTDIR}/Startup
	${RM} "$@.d"
	$(COMPILE.c) -O2 -s -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__MODE_USER -D__NO_SYSTEM_INIT -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Startup/startup_mstn_MDR32F9Qx.o Startup/startup_mstn_MDR32F9Qx.S

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__MODE_USER -D__NO_SYSTEM_INIT -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -I../../../../../Intec/LIBGit/emdr1986x-std-per-lib-master/MDR32F9Qx_StdPeriph_Driver/inc -I../../../../../Intec/LIBGit/emdr1986x-std-per-lib-master/MDR32F9Qx_StdPeriph_Driver/src -I../../../../../Intec/MSTN/M100/Inc/Core -I../../../../../Intec/MSTN/M100/Inc/Device -I../../../../../Intec/MSTN/M100/Inc/MSTN -I../../../../../Intec/MSTN/M100/Inc/SPL_MDR -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/morze.o: src/morze.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__MODE_USER -D__NO_SYSTEM_INIT -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -I../../../../../Intec/LIBGit/emdr1986x-std-per-lib-master/MDR32F9Qx_StdPeriph_Driver/inc -I../../../../../Intec/LIBGit/emdr1986x-std-per-lib-master/MDR32F9Qx_StdPeriph_Driver/src -I../../../../../Intec/MSTN/M100/Inc/Core -I../../../../../Intec/MSTN/M100/Inc/Device -I../../../../../Intec/MSTN/M100/Inc/MSTN -I../../../../../Intec/MSTN/M100/Inc/SPL_MDR -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/morze.o src/morze.cpp

${OBJECTDIR}/src/rxtx.o: src/rxtx.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__MODE_USER -D__NO_SYSTEM_INIT -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -I../../../../../Intec/LIBGit/emdr1986x-std-per-lib-master/MDR32F9Qx_StdPeriph_Driver/inc -I../../../../../Intec/LIBGit/emdr1986x-std-per-lib-master/MDR32F9Qx_StdPeriph_Driver/src -I../../../../../Intec/MSTN/M100/Inc/Core -I../../../../../Intec/MSTN/M100/Inc/Device -I../../../../../Intec/MSTN/M100/Inc/MSTN -I../../../../../Intec/MSTN/M100/Inc/SPL_MDR -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/rxtx.o src/rxtx.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
