#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-32mxSom.mk)" "nbproject/Makefile-local-32mxSom.mk"
include nbproject/Makefile-local-32mxSom.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=32mxSom
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/adquisicion.c ../src/comunicacion.c ../src/generacion.c ../src/app.c ../src/mapas.c ../src/temporalidades.c ../src/globales.c ../src/eeprom.c ../src/config/32mxSom/peripheral/adc/plib_adc.c ../src/config/32mxSom/peripheral/clk/plib_clk.c ../src/config/32mxSom/peripheral/evic/plib_evic.c ../src/config/32mxSom/peripheral/gpio/plib_gpio.c ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c ../src/config/32mxSom/peripheral/uart/plib_uart2.c ../src/config/32mxSom/peripheral/uart/plib_uart5.c ../src/config/32mxSom/stdio/xc32_monitor.c ../src/config/32mxSom/initialization.c ../src/config/32mxSom/interrupts.c ../src/config/32mxSom/exceptions.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/adquisicion.o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ${OBJECTDIR}/_ext/1360937237/generacion.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/mapas.o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ${OBJECTDIR}/_ext/1360937237/globales.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ${OBJECTDIR}/_ext/819485868/initialization.o ${OBJECTDIR}/_ext/819485868/interrupts.o ${OBJECTDIR}/_ext/819485868/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/adquisicion.o.d ${OBJECTDIR}/_ext/1360937237/comunicacion.o.d ${OBJECTDIR}/_ext/1360937237/generacion.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/mapas.o.d ${OBJECTDIR}/_ext/1360937237/temporalidades.o.d ${OBJECTDIR}/_ext/1360937237/globales.o.d ${OBJECTDIR}/_ext/1360937237/eeprom.o.d ${OBJECTDIR}/_ext/1021348264/plib_adc.o.d ${OBJECTDIR}/_ext/1021350442/plib_clk.o.d ${OBJECTDIR}/_ext/1597161859/plib_evic.o.d ${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d ${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d ${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d ${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d ${OBJECTDIR}/_ext/819485868/initialization.o.d ${OBJECTDIR}/_ext/819485868/interrupts.o.d ${OBJECTDIR}/_ext/819485868/exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/adquisicion.o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ${OBJECTDIR}/_ext/1360937237/generacion.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/mapas.o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ${OBJECTDIR}/_ext/1360937237/globales.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ${OBJECTDIR}/_ext/819485868/initialization.o ${OBJECTDIR}/_ext/819485868/interrupts.o ${OBJECTDIR}/_ext/819485868/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/adquisicion.c ../src/comunicacion.c ../src/generacion.c ../src/app.c ../src/mapas.c ../src/temporalidades.c ../src/globales.c ../src/eeprom.c ../src/config/32mxSom/peripheral/adc/plib_adc.c ../src/config/32mxSom/peripheral/clk/plib_clk.c ../src/config/32mxSom/peripheral/evic/plib_evic.c ../src/config/32mxSom/peripheral/gpio/plib_gpio.c ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c ../src/config/32mxSom/peripheral/uart/plib_uart2.c ../src/config/32mxSom/peripheral/uart/plib_uart5.c ../src/config/32mxSom/stdio/xc32_monitor.c ../src/config/32mxSom/initialization.c ../src/config/32mxSom/interrupts.c ../src/config/32mxSom/exceptions.c ../src/main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-32mxSom.mk dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=,--script="../src/config/32mxSom/p32MX795F512L.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/adquisicion.o: ../src/adquisicion.c  .generated_files/flags/32mxSom/4e5fe8be2a150e606ae325570797b2177fa9e9ab .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/adquisicion.o.d" -o ${OBJECTDIR}/_ext/1360937237/adquisicion.o ../src/adquisicion.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/comunicacion.o: ../src/comunicacion.c  .generated_files/flags/32mxSom/da47894d4c5dbeea706d8d736d04ecc74cc9ae57 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/comunicacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ../src/comunicacion.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/generacion.o: ../src/generacion.c  .generated_files/flags/32mxSom/a778e3b0956c76a615eedceb76b59c940211d5ce .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/generacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/generacion.o ../src/generacion.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/32mxSom/2c1c934f6f98565626675a1adc6dd181ed3f6d57 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/mapas.o: ../src/mapas.c  .generated_files/flags/32mxSom/bc0038b795bf40a1c021c418094a53644cd41526 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mapas.o.d" -o ${OBJECTDIR}/_ext/1360937237/mapas.o ../src/mapas.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/temporalidades.o: ../src/temporalidades.c  .generated_files/flags/32mxSom/b598d2c29c2b15d5014ac6909c94dcfb1de17b9f .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/temporalidades.o.d" -o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ../src/temporalidades.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/globales.o: ../src/globales.c  .generated_files/flags/32mxSom/4a164f5604db3648e1eda38db149fbb08fd43213 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/globales.o.d" -o ${OBJECTDIR}/_ext/1360937237/globales.o ../src/globales.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/flags/32mxSom/4569c7ce029797f8ca524b1bc43b4f80615d922b .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021348264/plib_adc.o: ../src/config/32mxSom/peripheral/adc/plib_adc.c  .generated_files/flags/32mxSom/ada0fe214870864b98736e2575a2806eaa6cd19 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021348264" 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021348264/plib_adc.o.d" -o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ../src/config/32mxSom/peripheral/adc/plib_adc.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021350442/plib_clk.o: ../src/config/32mxSom/peripheral/clk/plib_clk.c  .generated_files/flags/32mxSom/94d606bc7615f7af40942f4f690c91e93cf519c5 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021350442" 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021350442/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ../src/config/32mxSom/peripheral/clk/plib_clk.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597161859/plib_evic.o: ../src/config/32mxSom/peripheral/evic/plib_evic.c  .generated_files/flags/32mxSom/5184ee719bf62537db792c0957db95b174ffa09c .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597161859" 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597161859/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ../src/config/32mxSom/peripheral/evic/plib_evic.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597215687/plib_gpio.o: ../src/config/32mxSom/peripheral/gpio/plib_gpio.c  .generated_files/flags/32mxSom/d693f5fa830373a008721e81e69b6230f041de69 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597215687" 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ../src/config/32mxSom/peripheral/gpio/plib_gpio.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o: ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c  .generated_files/flags/32mxSom/6fe29edbf9c259bc3eb8ab82cf377c7ba82cac81 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1453895535" 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d" -o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o: ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c  .generated_files/flags/32mxSom/9bdf1785022ea403f1dc9d09448e7c19d6bf098f .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1079933584" 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d" -o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr2.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c  .generated_files/flags/32mxSom/eac8f29f728dd239374e66e885053a60d57947a7 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr4.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c  .generated_files/flags/32mxSom/2313f8dd77b77ff7b342f8bf9269094f8dda4e6e .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr5.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c  .generated_files/flags/32mxSom/7ab92fe35b00b88fce866218466d51918b3078fc .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr3.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c  .generated_files/flags/32mxSom/f8b8e0e82558777eeff08e6b5d8d4bb7b80c5155 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart2.o: ../src/config/32mxSom/peripheral/uart/plib_uart2.c  .generated_files/flags/32mxSom/e419ed3a09b1f274d011d26144804c3bb9bfbc7e .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ../src/config/32mxSom/peripheral/uart/plib_uart2.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart5.o: ../src/config/32mxSom/peripheral/uart/plib_uart5.c  .generated_files/flags/32mxSom/65c14fa13122010313889e9917064d2319cb0b8 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ../src/config/32mxSom/peripheral/uart/plib_uart5.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/538220530/xc32_monitor.o: ../src/config/32mxSom/stdio/xc32_monitor.c  .generated_files/flags/32mxSom/97558e3a4d71a97d9e7d72c22a2bc5b33fb73be1 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/538220530" 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ../src/config/32mxSom/stdio/xc32_monitor.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/initialization.o: ../src/config/32mxSom/initialization.c  .generated_files/flags/32mxSom/476bad1848d5965406bd6d710fa9f4f0efac3cca .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/initialization.o.d" -o ${OBJECTDIR}/_ext/819485868/initialization.o ../src/config/32mxSom/initialization.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/interrupts.o: ../src/config/32mxSom/interrupts.c  .generated_files/flags/32mxSom/d22ad93db88fee82962b6563a01e7a87caeaaa19 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/interrupts.o.d" -o ${OBJECTDIR}/_ext/819485868/interrupts.o ../src/config/32mxSom/interrupts.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/exceptions.o: ../src/config/32mxSom/exceptions.c  .generated_files/flags/32mxSom/96c7762db9cea1e3862a91f4ec40ce1b0acf8cb7 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/exceptions.o.d" -o ${OBJECTDIR}/_ext/819485868/exceptions.o ../src/config/32mxSom/exceptions.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/32mxSom/ae6e19d7f818b1d3466a9e9d1303128cfa2f3c8c .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1360937237/adquisicion.o: ../src/adquisicion.c  .generated_files/flags/32mxSom/1f9ec3f33829f9bed53474003698ae6a9d33da76 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/adquisicion.o.d" -o ${OBJECTDIR}/_ext/1360937237/adquisicion.o ../src/adquisicion.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/comunicacion.o: ../src/comunicacion.c  .generated_files/flags/32mxSom/f7a12c5055c99e55170c9784b594195f532025ec .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/comunicacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ../src/comunicacion.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/generacion.o: ../src/generacion.c  .generated_files/flags/32mxSom/f96b4421b115d2ee222e5db29757a27027d64440 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/generacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/generacion.o ../src/generacion.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/32mxSom/b64573e0cc6b8ca2d60ee2aabaf428bff78957c8 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/mapas.o: ../src/mapas.c  .generated_files/flags/32mxSom/9a89c3e315a096c4e552459728d2d1d067a5fe5b .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mapas.o.d" -o ${OBJECTDIR}/_ext/1360937237/mapas.o ../src/mapas.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/temporalidades.o: ../src/temporalidades.c  .generated_files/flags/32mxSom/8f0aebbfc97c424fc496c8af597fe08ab7cf13c6 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/temporalidades.o.d" -o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ../src/temporalidades.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/globales.o: ../src/globales.c  .generated_files/flags/32mxSom/efa2f5d821b7abfe8078122182da92fdeabd1b47 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/globales.o.d" -o ${OBJECTDIR}/_ext/1360937237/globales.o ../src/globales.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/flags/32mxSom/91d05897b93f1c1cc1f5b1bfcb32a87a21de303b .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021348264/plib_adc.o: ../src/config/32mxSom/peripheral/adc/plib_adc.c  .generated_files/flags/32mxSom/889c75414900f790432f61339e564843598ecb57 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021348264" 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021348264/plib_adc.o.d" -o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ../src/config/32mxSom/peripheral/adc/plib_adc.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021350442/plib_clk.o: ../src/config/32mxSom/peripheral/clk/plib_clk.c  .generated_files/flags/32mxSom/a586220fe65c723c71579005b06eedb9f6dca41e .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021350442" 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021350442/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ../src/config/32mxSom/peripheral/clk/plib_clk.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597161859/plib_evic.o: ../src/config/32mxSom/peripheral/evic/plib_evic.c  .generated_files/flags/32mxSom/f945d1e6e92e1d52d3d27c8d448132e63396e0e9 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597161859" 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597161859/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ../src/config/32mxSom/peripheral/evic/plib_evic.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597215687/plib_gpio.o: ../src/config/32mxSom/peripheral/gpio/plib_gpio.c  .generated_files/flags/32mxSom/130b61c561316cbc98806b57342d66141afdb143 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597215687" 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ../src/config/32mxSom/peripheral/gpio/plib_gpio.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o: ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c  .generated_files/flags/32mxSom/6c3897ffca245463114999f67830dde8d78f154e .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1453895535" 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d" -o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o: ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c  .generated_files/flags/32mxSom/5f7b2d78e45d4a1fcc91120358c099b44fdc5a0e .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1079933584" 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d" -o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr2.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c  .generated_files/flags/32mxSom/175f57372456e3a74588f2318c0d4a9ef29afd22 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr4.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c  .generated_files/flags/32mxSom/c78520e26c050a977ebf50e425aa5c347d2f8bbc .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr5.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c  .generated_files/flags/32mxSom/ba614d856b818817b652520ce384291a5e24399d .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr3.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c  .generated_files/flags/32mxSom/8eb9b702106442fbab44854032c62f0783ce7381 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart2.o: ../src/config/32mxSom/peripheral/uart/plib_uart2.c  .generated_files/flags/32mxSom/888d335f4fc6aec6d86af3cd4812969664058ea4 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ../src/config/32mxSom/peripheral/uart/plib_uart2.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart5.o: ../src/config/32mxSom/peripheral/uart/plib_uart5.c  .generated_files/flags/32mxSom/ad8dedd6b832e7dc9f29f91e5861fa6560aff7d8 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ../src/config/32mxSom/peripheral/uart/plib_uart5.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/538220530/xc32_monitor.o: ../src/config/32mxSom/stdio/xc32_monitor.c  .generated_files/flags/32mxSom/d2d893bfc6d461d6e86f864c2604df62786e5881 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/538220530" 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ../src/config/32mxSom/stdio/xc32_monitor.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/initialization.o: ../src/config/32mxSom/initialization.c  .generated_files/flags/32mxSom/e6b9a928ba560624227153c7f1baacbbddf3dec1 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/initialization.o.d" -o ${OBJECTDIR}/_ext/819485868/initialization.o ../src/config/32mxSom/initialization.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/interrupts.o: ../src/config/32mxSom/interrupts.c  .generated_files/flags/32mxSom/2a84d1aa728ea35ce8594fa4b1fa31ef8396053f .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/interrupts.o.d" -o ${OBJECTDIR}/_ext/819485868/interrupts.o ../src/config/32mxSom/interrupts.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/exceptions.o: ../src/config/32mxSom/exceptions.c  .generated_files/flags/32mxSom/c1c48ce82cb5b2642025e01bb6a43ae029c14162 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/exceptions.o.d" -o ${OBJECTDIR}/_ext/819485868/exceptions.o ../src/config/32mxSom/exceptions.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/32mxSom/9e8866ba25d309ebf8220e658188ca8979bcd940 .generated_files/flags/32mxSom/ce8440239263f282dd1cbb8e6549de143abd74
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/32mxSom/p32MX795F512L.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/32mxSom/p32MX795F512L.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_32mxSom=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Som795.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/32mxSom
	${RM} -r dist/32mxSom

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
