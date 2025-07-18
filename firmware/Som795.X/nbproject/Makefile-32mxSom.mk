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
FINAL_IMAGE=${DISTDIR}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/adquisicion.c ../src/comunicacion.c ../src/generacion.c ../src/app.c ../src/mapas.c ../src/temporalidades.c ../src/globales.c ../src/eeprom.c ../src/config/32mxSom/peripheral/adc/plib_adc.c ../src/config/32mxSom/peripheral/clk/plib_clk.c ../src/config/32mxSom/peripheral/evic/plib_evic.c ../src/config/32mxSom/peripheral/gpio/plib_gpio.c ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c ../src/config/32mxSom/peripheral/i2c/plib_i2c_smbus_common.c ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c ../src/config/32mxSom/peripheral/uart/plib_uart2.c ../src/config/32mxSom/peripheral/uart/plib_uart5.c ../src/config/32mxSom/stdio/xc32_monitor.c ../src/config/32mxSom/initialization.c ../src/config/32mxSom/interrupts.c ../src/config/32mxSom/exceptions.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/adquisicion.o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ${OBJECTDIR}/_ext/1360937237/generacion.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/mapas.o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ${OBJECTDIR}/_ext/1360937237/globales.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ${OBJECTDIR}/_ext/819485868/initialization.o ${OBJECTDIR}/_ext/819485868/interrupts.o ${OBJECTDIR}/_ext/819485868/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/adquisicion.o.d ${OBJECTDIR}/_ext/1360937237/comunicacion.o.d ${OBJECTDIR}/_ext/1360937237/generacion.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/mapas.o.d ${OBJECTDIR}/_ext/1360937237/temporalidades.o.d ${OBJECTDIR}/_ext/1360937237/globales.o.d ${OBJECTDIR}/_ext/1360937237/eeprom.o.d ${OBJECTDIR}/_ext/1021348264/plib_adc.o.d ${OBJECTDIR}/_ext/1021350442/plib_clk.o.d ${OBJECTDIR}/_ext/1597161859/plib_evic.o.d ${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o.d ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d ${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d ${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d ${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d ${OBJECTDIR}/_ext/819485868/initialization.o.d ${OBJECTDIR}/_ext/819485868/interrupts.o.d ${OBJECTDIR}/_ext/819485868/exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/adquisicion.o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ${OBJECTDIR}/_ext/1360937237/generacion.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/mapas.o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ${OBJECTDIR}/_ext/1360937237/globales.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ${OBJECTDIR}/_ext/819485868/initialization.o ${OBJECTDIR}/_ext/819485868/interrupts.o ${OBJECTDIR}/_ext/819485868/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/adquisicion.c ../src/comunicacion.c ../src/generacion.c ../src/app.c ../src/mapas.c ../src/temporalidades.c ../src/globales.c ../src/eeprom.c ../src/config/32mxSom/peripheral/adc/plib_adc.c ../src/config/32mxSom/peripheral/clk/plib_clk.c ../src/config/32mxSom/peripheral/evic/plib_evic.c ../src/config/32mxSom/peripheral/gpio/plib_gpio.c ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c ../src/config/32mxSom/peripheral/i2c/plib_i2c_smbus_common.c ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c ../src/config/32mxSom/peripheral/uart/plib_uart2.c ../src/config/32mxSom/peripheral/uart/plib_uart5.c ../src/config/32mxSom/stdio/xc32_monitor.c ../src/config/32mxSom/initialization.c ../src/config/32mxSom/interrupts.c ../src/config/32mxSom/exceptions.c ../src/main.c



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
	${MAKE}  -f nbproject/Makefile-32mxSom.mk ${DISTDIR}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1360937237/adquisicion.o: ../src/adquisicion.c  .generated_files/flags/32mxSom/7764a7c72b62a888d8fce53df5c607b6392e9411 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/adquisicion.o.d" -o ${OBJECTDIR}/_ext/1360937237/adquisicion.o ../src/adquisicion.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/comunicacion.o: ../src/comunicacion.c  .generated_files/flags/32mxSom/21d7b33d0fe96d8444501eb8b05664b5183bc3d1 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/comunicacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ../src/comunicacion.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/generacion.o: ../src/generacion.c  .generated_files/flags/32mxSom/a37e792cc8a7390608f94684068791056887c697 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/generacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/generacion.o ../src/generacion.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/32mxSom/54cee1315b4a33025a20c700e5e639a5ef6add2d .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/mapas.o: ../src/mapas.c  .generated_files/flags/32mxSom/b2d1d9634c04ac8f1221f71e88133638e6a84854 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mapas.o.d" -o ${OBJECTDIR}/_ext/1360937237/mapas.o ../src/mapas.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/temporalidades.o: ../src/temporalidades.c  .generated_files/flags/32mxSom/70882179c94a3196c9b88b2b80f8459ae4032235 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/temporalidades.o.d" -o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ../src/temporalidades.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/globales.o: ../src/globales.c  .generated_files/flags/32mxSom/448b354428979cc90b63ae48cb9eba2845230541 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/globales.o.d" -o ${OBJECTDIR}/_ext/1360937237/globales.o ../src/globales.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/flags/32mxSom/6f62c6c4343c42e3271e5eda7f461b86f38498a4 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021348264/plib_adc.o: ../src/config/32mxSom/peripheral/adc/plib_adc.c  .generated_files/flags/32mxSom/f3dc05ea5a4ef33ed460a9a523dff4f0d354c125 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021348264" 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021348264/plib_adc.o.d" -o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ../src/config/32mxSom/peripheral/adc/plib_adc.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021350442/plib_clk.o: ../src/config/32mxSom/peripheral/clk/plib_clk.c  .generated_files/flags/32mxSom/7f8791a2d426ca034d79e55db3af0f5353139549 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021350442" 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021350442/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ../src/config/32mxSom/peripheral/clk/plib_clk.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597161859/plib_evic.o: ../src/config/32mxSom/peripheral/evic/plib_evic.c  .generated_files/flags/32mxSom/7ad8b925f92b001baca8cb5088a5e9cec8a2c83e .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597161859" 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597161859/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ../src/config/32mxSom/peripheral/evic/plib_evic.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597215687/plib_gpio.o: ../src/config/32mxSom/peripheral/gpio/plib_gpio.c  .generated_files/flags/32mxSom/d99aee8b02f31ec6fb2c02c3ff651b4b7bb68522 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597215687" 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ../src/config/32mxSom/peripheral/gpio/plib_gpio.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o: ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c  .generated_files/flags/32mxSom/d32a745f5bdd433744ebab531a4d3c1d592b30b9 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1453895535" 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d" -o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o: ../src/config/32mxSom/peripheral/i2c/plib_i2c_smbus_common.c  .generated_files/flags/32mxSom/bee6a982c46a68d3cccafe9d083ece987ea55d30 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021354402" 
	@${RM} ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o.d" -o ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o ../src/config/32mxSom/peripheral/i2c/plib_i2c_smbus_common.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o: ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c  .generated_files/flags/32mxSom/d0b26ac6ff95b05163edf3e4ddda23bf9ecf29e2 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1079933584" 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d" -o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr2.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c  .generated_files/flags/32mxSom/82b4f2be34affeea9361b0ea494da089005ec070 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr4.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c  .generated_files/flags/32mxSom/2b88db6ac7c379b0cda479845c6fc1c91f246e0a .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr5.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c  .generated_files/flags/32mxSom/c26f785ee297b466bc7857aa1eb44f616b68ecc3 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr3.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c  .generated_files/flags/32mxSom/ef7a8e1558dae85884eaf5aa0393a8e187b621ec .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart2.o: ../src/config/32mxSom/peripheral/uart/plib_uart2.c  .generated_files/flags/32mxSom/be32c1e75ac23deac9a98300005259a523a5d488 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ../src/config/32mxSom/peripheral/uart/plib_uart2.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart5.o: ../src/config/32mxSom/peripheral/uart/plib_uart5.c  .generated_files/flags/32mxSom/a9c029398030943b4f1e37a3bcadb43f7592fb63 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ../src/config/32mxSom/peripheral/uart/plib_uart5.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/538220530/xc32_monitor.o: ../src/config/32mxSom/stdio/xc32_monitor.c  .generated_files/flags/32mxSom/d812114f823ad4e0ce47cefcb4f629addd2c85ce .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/538220530" 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ../src/config/32mxSom/stdio/xc32_monitor.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/initialization.o: ../src/config/32mxSom/initialization.c  .generated_files/flags/32mxSom/9eb165cf43dab66a9661d0d6972edfad15d132a4 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/initialization.o.d" -o ${OBJECTDIR}/_ext/819485868/initialization.o ../src/config/32mxSom/initialization.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/interrupts.o: ../src/config/32mxSom/interrupts.c  .generated_files/flags/32mxSom/fd635cfe2e20f99e8db61935183118f094eed79e .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/interrupts.o.d" -o ${OBJECTDIR}/_ext/819485868/interrupts.o ../src/config/32mxSom/interrupts.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/exceptions.o: ../src/config/32mxSom/exceptions.c  .generated_files/flags/32mxSom/5424b835b9347a27c780423c4d65da41e43de163 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/exceptions.o.d" -o ${OBJECTDIR}/_ext/819485868/exceptions.o ../src/config/32mxSom/exceptions.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/32mxSom/f7848f79b239009fef4f39def380a0477b5bf7f2 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1360937237/adquisicion.o: ../src/adquisicion.c  .generated_files/flags/32mxSom/157540717765ad8305784b1849d3054f6fa2c264 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adquisicion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/adquisicion.o.d" -o ${OBJECTDIR}/_ext/1360937237/adquisicion.o ../src/adquisicion.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/comunicacion.o: ../src/comunicacion.c  .generated_files/flags/32mxSom/5b38e17088a860b6933af47b61204111bd64562b .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/comunicacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/comunicacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/comunicacion.o ../src/comunicacion.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/generacion.o: ../src/generacion.c  .generated_files/flags/32mxSom/701915714d2312f59dc47529ae2bc10f97cb3375 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/generacion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/generacion.o.d" -o ${OBJECTDIR}/_ext/1360937237/generacion.o ../src/generacion.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/32mxSom/79951859e9f82a2e4ab531d992ea3263fe228077 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/mapas.o: ../src/mapas.c  .generated_files/flags/32mxSom/79b611c73eb4cae92c045ec08320d03177a93c2d .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mapas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mapas.o.d" -o ${OBJECTDIR}/_ext/1360937237/mapas.o ../src/mapas.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/temporalidades.o: ../src/temporalidades.c  .generated_files/flags/32mxSom/93ea26afe5bfd922393ca6beec636191097294c3 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/temporalidades.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/temporalidades.o.d" -o ${OBJECTDIR}/_ext/1360937237/temporalidades.o ../src/temporalidades.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/globales.o: ../src/globales.c  .generated_files/flags/32mxSom/5f9871b9c2bf5f2b3f80d15d0018315c684cd3c2 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/globales.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/globales.o.d" -o ${OBJECTDIR}/_ext/1360937237/globales.o ../src/globales.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/flags/32mxSom/6c1427144ba4ec1a2b572078ac66dcef623c4021 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021348264/plib_adc.o: ../src/config/32mxSom/peripheral/adc/plib_adc.c  .generated_files/flags/32mxSom/63d2f7b27a8d47b8976b13fc2fe71311e6bfc021 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021348264" 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021348264/plib_adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021348264/plib_adc.o.d" -o ${OBJECTDIR}/_ext/1021348264/plib_adc.o ../src/config/32mxSom/peripheral/adc/plib_adc.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021350442/plib_clk.o: ../src/config/32mxSom/peripheral/clk/plib_clk.c  .generated_files/flags/32mxSom/ebc2f56712d08e661adcff72096bb7f6bcabf1ba .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021350442" 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021350442/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021350442/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1021350442/plib_clk.o ../src/config/32mxSom/peripheral/clk/plib_clk.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597161859/plib_evic.o: ../src/config/32mxSom/peripheral/evic/plib_evic.c  .generated_files/flags/32mxSom/6d94f3b49b6e121c0e46e76dec7162d1fc299ffe .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597161859" 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597161859/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597161859/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1597161859/plib_evic.o ../src/config/32mxSom/peripheral/evic/plib_evic.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597215687/plib_gpio.o: ../src/config/32mxSom/peripheral/gpio/plib_gpio.c  .generated_files/flags/32mxSom/4548a3a537f82986b37f20d4df6b5b026e55dd04 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597215687" 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597215687/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597215687/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1597215687/plib_gpio.o ../src/config/32mxSom/peripheral/gpio/plib_gpio.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o: ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c  .generated_files/flags/32mxSom/f754ca5552648634011a76d1aa97e6995ce6a83e .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1453895535" 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o.d" -o ${OBJECTDIR}/_ext/1453895535/plib_i2c2_master.o ../src/config/32mxSom/peripheral/i2c/master/plib_i2c2_master.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o: ../src/config/32mxSom/peripheral/i2c/plib_i2c_smbus_common.c  .generated_files/flags/32mxSom/485bf39cd782c61c99a0647ad6218b4de70c009d .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021354402" 
	@${RM} ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o.d" -o ${OBJECTDIR}/_ext/1021354402/plib_i2c_smbus_common.o ../src/config/32mxSom/peripheral/i2c/plib_i2c_smbus_common.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o: ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c  .generated_files/flags/32mxSom/c4b9d8d75eaa2c3b999a1c74aa96550198f377d1 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1079933584" 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o.d" -o ${OBJECTDIR}/_ext/1079933584/plib_spi3_master.o ../src/config/32mxSom/peripheral/spi/spi_master/plib_spi3_master.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr2.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c  .generated_files/flags/32mxSom/d5048968ecc1e817f54cc4c25fd21e50b6f5090d .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr2.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr2.o ../src/config/32mxSom/peripheral/tmr/plib_tmr2.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr4.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c  .generated_files/flags/32mxSom/13b63fe39911550a64fc926f138992c7953dc3d9 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr4.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr4.o ../src/config/32mxSom/peripheral/tmr/plib_tmr4.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr5.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c  .generated_files/flags/32mxSom/316c5f4d2fabe2eb6b88708ccee08c97d8dec08d .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr5.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr5.o ../src/config/32mxSom/peripheral/tmr/plib_tmr5.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1021366817/plib_tmr3.o: ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c  .generated_files/flags/32mxSom/ae4c0efa278d17ea22c27782d9feceaefffad5b5 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1021366817" 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1021366817/plib_tmr3.o.d" -o ${OBJECTDIR}/_ext/1021366817/plib_tmr3.o ../src/config/32mxSom/peripheral/tmr/plib_tmr3.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart2.o: ../src/config/32mxSom/peripheral/uart/plib_uart2.c  .generated_files/flags/32mxSom/24790ea3b38cb3ba1d1cce649f356484ed493b75 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart2.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart2.o ../src/config/32mxSom/peripheral/uart/plib_uart2.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1597618630/plib_uart5.o: ../src/config/32mxSom/peripheral/uart/plib_uart5.c  .generated_files/flags/32mxSom/3988949d98145a6e8919da31fb306052244404d1 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1597618630" 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1597618630/plib_uart5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1597618630/plib_uart5.o.d" -o ${OBJECTDIR}/_ext/1597618630/plib_uart5.o ../src/config/32mxSom/peripheral/uart/plib_uart5.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/538220530/xc32_monitor.o: ../src/config/32mxSom/stdio/xc32_monitor.c  .generated_files/flags/32mxSom/80e42c179ab5251d0b8f3ccdc3c022cda6e37791 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/538220530" 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/538220530/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/538220530/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/538220530/xc32_monitor.o ../src/config/32mxSom/stdio/xc32_monitor.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/initialization.o: ../src/config/32mxSom/initialization.c  .generated_files/flags/32mxSom/6b1b3125629281d787fa8d86f272276ea9bf68b9 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/initialization.o.d" -o ${OBJECTDIR}/_ext/819485868/initialization.o ../src/config/32mxSom/initialization.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/interrupts.o: ../src/config/32mxSom/interrupts.c  .generated_files/flags/32mxSom/65247f81c45cfaf309b6d7609f5ee71fe510f3af .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/interrupts.o.d" -o ${OBJECTDIR}/_ext/819485868/interrupts.o ../src/config/32mxSom/interrupts.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/819485868/exceptions.o: ../src/config/32mxSom/exceptions.c  .generated_files/flags/32mxSom/1de0253825019d721917b3fc0cd12728e1bd45b4 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/819485868" 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/819485868/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/819485868/exceptions.o.d" -o ${OBJECTDIR}/_ext/819485868/exceptions.o ../src/config/32mxSom/exceptions.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/32mxSom/577749e1d01e89fb3e3600ec06cc21b0661ecd0 .generated_files/flags/32mxSom/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/32mxSom" -I"../src/packs/PIC32MX795F512L_DFP" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/32mxSom/p32MX795F512L.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Som795.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/32mxSom/p32MX795F512L.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Som795.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_32mxSom=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/Som795.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
