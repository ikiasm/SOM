/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <stdbool.h>
#include <stdint.h>
//#include <GenericTypeDefs.h>
#include "config/32mxSom/peripheral/uart/plib_uart_common.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */

#define AJUSTE_PUNTO    0x01
/* EEPROM Commands */
#define EEPROM_CMD_WREN                     0x06
#define EEPROM_CMD_WRITE                    0x02
#define EEPROM_CMD_RDSR                     0x05
#define EEPROM_CMD_READ                     0x03
    
#define EEPROM_ADDRESS                      0x000000    
    
#define EEPROM_DATA                         0xAA55  //Dato de 16 bits
#define EEPROM_DATA_LEN                     sizeof(EEPROM_DATA)    
    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
//#define EXAMPLE_CONSTANT 0
    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Globals                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

//    extern int ckpAngleAdjustGlobal;
//    extern int ckpAngleAdjust_Global;
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
//    typedef struct _example_struct_t {
//        /* Describe structure member. */
//        int some_number;
//
//        /* Describe structure member. */
//        bool some_flag;
//
//    } example_struct_t;

    typedef enum {
        UART4 = 0,
        UART5
    }UART;
    
    typedef enum {
        SETS = 0x31,
        GETS = 0x32        
    }CMD;
    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
//    int ExampleFunction(int param1, int param2);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
//    int ExampleFunction(int param1, int param2);
    // *****************************************************************************
    // *****************************************************************************
    // Protocolo de comunicacion
    // *****************************************************************************
    // *****************************************************************************

    /*  Establecer el handshaking entre dispositivo y monitor
     */

    // *****************************************************************************
    /**
      @Function
     void decode(unsigned int bufferRx)
     * int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
//    int ExampleFunction(int param1, int param2);

    void decoder(void);
    void encoder(uint8_t ch, uint8_t id, uint8_t status,  uint16_t dato, uint16_t address);
    
    void resetReceiveBuffer(void);
    
    void switcher(int id, int datoH, int datoL);
    

    uint16_t checksumGenerator(uint8_t cmd, uint8_t ch, uint8_t id, uint8_t b3, uint16_t dato, uint16_t address);
    bool checksumValidator(uint8_t cmd, uint8_t ch, uint8_t id, uint8_t b3, uint16_t dato, uint16_t address, uint16_t checksum);
    
    void channelSelector(void);
    void channelSelector_Get(void);
    
    
    void updater(void);
    void addLiteralToTable(void);
    void subLiteralToTable(void);
    void addPercentToTable(void);
    void subPercentToTable(void);
    
    void uploadFromDevice(void);
    void downloadToDevice(void);
    void eepromDevice(void);
    
    void inyectorUpdater(uint8_t id, uint8_t status, uint16_t dato, uint16_t apms);
    
    void deadTimeUpdater(uint16_t dato);
    void saturedTimeUpdater(uint16_t dato);
    void dutyUpdater(uint16_t dato);
    void rpmLimiterUpdater(uint16_t dato);
    void mapaActualSafe(void);
    void mapaActualTuning(void);
    void mapaTuningUpdate(void);
    
    void getTableValue(void);
    void setToTableValues(void);
    
    void dataSender(void);
    
    void returner(void);
    
    bool UART5_Write_Mio(void* buffer, const size_t size);
    void UART_Write_Byte(int uart, int byte);
    
//    void APP_WriteCallback(uintptr_t context);
//    void APP_ReadCallback(uintptr_t context);
    
extern void APP_WriteCallback(uintptr_t context);
extern void APP_ReadCallback(uintptr_t context);
    
    void UART5_callbacks(void);
    void UART5_Task();
    
    void SPI3_callbacks(void);
        
    void receivePrueba(void);
    
    extern void SPIEventHandler(uintptr_t context);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
