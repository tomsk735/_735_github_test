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
CND_PLATFORM=MSTN_Toolchain-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
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
	${OBJECTDIR}/src/sketch.o


# C Compiler Flags
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2 -MD -Wall -O0 -fdata-sections -ffunction-sections

# CC Compiler Flags
CCFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2 -MD -Wall -O0 -fdata-sections -ffunction-sections -fno-exceptions
CXXFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2 -MD -Wall -O0 -fdata-sections -ffunction-sections -fno-exceptions

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Intec/MSTN/M100/Lib/arm-none-eabi -u _printf_float -mcpu=cortex-m3 -mthumb -lstdc++ -lm -N -Ttext=0x08003000 -Tdata=0x20000000 --specs=nano.specs -Wl,--start-group -lgcc -lc -lm -lMSTN-M100 -Wl,--end-group -Wl,-gc-sections -nostartfiles -ffreestanding

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mstn_templateproject.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mstn_templateproject.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	arm-none-eabi-g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mstn_templateproject ${OBJECTFILES} ${LDLIBSOPTIONS} -TC:/Intec/MSTN/M100/Lib/arm-none-eabi/MSTN_M100_User.ld -Wl,--start-group -lgcc -lc -lm -lMSTN-M100 -Wl,--end-group

${OBJECTDIR}/Startup/startup_mstn_MDR32F9Qx.o: Startup/startup_mstn_MDR32F9Qx.S
	${MKDIR} -p ${OBJECTDIR}/Startup
	${RM} "$@.d"
	$(COMPILE.c) -g -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__DEBUG -D__MODE_USER -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -I/C/Intec/MSTN/M100/Inc/MSTN -I/C/Intec/MSTN/M100/Inc/SPL_MDR -I/C/Intec/MSTN/M100/Inc/Cpp -I/C/Intec/MSTN/M100/Inc/Core -I/C/Intec/MSTN/M100/Inc/Device -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Startup/startup_mstn_MDR32F9Qx.o Startup/startup_mstn_MDR32F9Qx.S

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__DEBUG -D__MODE_USER -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -I/C/Intec/MSTN/M100/Inc/MSTN -I/C/Intec/MSTN/M100/Inc/SPL_MDR -I/C/Intec/MSTN/M100/Inc/Cpp -I/C/Intec/MSTN/M100/Inc/Core -I/C/Intec/MSTN/M100/Inc/Device -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/sketch.o: src/sketch.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DF_CPU=80000000 -DMSTN=100 -DUSE_MDR1986VE9x -D__DEBUG -D__MODE_USER -D__STARTUP_CLEAR_BSS -D_start=mstn_main -I./Startup -I./src -I/C/Intec/MSTN/M100/Inc/MSTN -I/C/Intec/MSTN/M100/Inc/SPL_MDR -I/C/Intec/MSTN/M100/Inc/Cpp -I/C/Intec/MSTN/M100/Inc/Core -I/C/Intec/MSTN/M100/Inc/Device -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sketch.o src/sketch.cpp

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
