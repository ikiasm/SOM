/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */

#include "config/32mxSom/peripheral/gpio/plib_gpio.h"
#include "config/default/../32mxSom/peripheral/tmr/plib_tmr2.h"
#include "config/32mxSom/peripheral/evic/plib_evic.h"
#include "app.h"
#include "globales.h"

#include "config/32mxSom/peripheral/uart/plib_uart5.h"
#include "comunicacion.h"

#include "eeprom.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
//int global_data;
APP_DATA appData;

//static unsigned int tick5us;
//static unsigned int tick10us;
//static unsigned int varTicks100us;
//static unsigned int varTicks1ms;
//static unsigned int varTicks10ms;
//static unsigned int varTicks100ms;


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

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
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
//int ExampleInterfaceFunction(int param1, int param2) {
//    return 0;
//}

char mensaje[] = "Mensaje";
////bool status;

//void app_readCallback(uintptr_t context) {
//    if (UART5_ErrorGet() != UART_ERROR_NONE) {
//        /* ErrorGet clears errors, set error flag to notify console */
//        errorStatus = true;
//    } else {
//        readStatus = true;
//    }
//}
//
//void app_writeCallback(uintptr_t context) {
//    writeStatus = true;
//}



void appInitialize(void) {
    appData.state = APP_STATE_INIT; //status = 0;
    TMR2_Start(); //Periodo 5us
    TMR3_Start(); //Periodo 44us
    TMR4_Start(); //Periodo 100ns


    EVIC_ExternalInterruptEnable(EXTERNAL_INT_0); //Interrupcion CKP
    EVIC_ExternalInterruptEnable(EXTERNAL_INT_2); //Interrupcion CMP

    //Aca van los prototipos de callbacks de comunicacion.h
    // en temporalidades va la lectura de cada byte, o capaz que aca
    
    UART5_callbacks();
    SPI3_callbacks();
    //FORMA MANUAL
//    /* Enable UART5_FAULT Interrupt */
//    IEC2SET = _IEC2_U5EIE_MASK;
//
//    /* Enable UART5_RX Interrupt */
//    IEC2SET = _IEC2_U5RXIE_MASK;
    
    EEPROM_Init();
    
}

void appTask() {
    switch (appData.state) {
        case APP_STATE_INIT:
        {
            appData.state = APP_STATE_SERVICE_TASK;
            
            
            initMapasInyGnc();//CARGAR MAPA SAFE INYECCION GAS Y MAPA EN USO
            initMapasPPAGnc();//CARGAR MAPA SAFE PPA Y MAPA EN USO
            
            //CARGAR RPM LIMITADOR
            //CARGAR CONTACTO MONITOREO
            
        }
            break;

        case APP_STATE_SERVICE_TASK:
        {
            UART5_Task();
            test();
            if(RPM_Global > RPM_Limiter_Global) //Anda. Con histeresis andaria mortal
            {
                inyector1EnabledGlobal = false;
                inyector2EnabledGlobal = false;
                inyector3EnabledGlobal = false;
                inyector4EnabledGlobal = false;
                GEN_INY1_CTRL_Clear();
                GEN_INY2_CTRL_Clear();
                GEN_INY3_CTRL_Clear();
                GEN_INY4_CTRL_Clear();
            }
            else
            {
                inyector1EnabledGlobal = true;
                inyector2EnabledGlobal = true;
                inyector3EnabledGlobal = true;
                inyector4EnabledGlobal = true;
            }
            
            if(estadoConmutador())
            {
                //IMPLEMENTAR FUNCION SITUACION GNC
                inyector1EnabledGlobal = true;
                inyector2EnabledGlobal = true;
                inyector3EnabledGlobal = true;
                inyector4EnabledGlobal = true;
                
                
                llaveEnGasGlobal = true;
                GEN_RLY_INY_Set();
                
            }
            if(!estadoConmutador())
            {
                //REESTABLECER TODO A SITUACION DIESEL
                inyector1EnabledGlobal = false;
                inyector2EnabledGlobal = false;
                inyector3EnabledGlobal = false;
                inyector4EnabledGlobal = false;
                GEN_INY1_CTRL_Clear();
                GEN_INY2_CTRL_Clear();
                GEN_INY3_CTRL_Clear();
                GEN_INY4_CTRL_Clear();
                
                llaveEnGasGlobal = false;
                GEN_RLY_INY_Clear();
                retencionGas = true;
            }            
        }
            break;

        default:
            break;
    }

}

void test(void) {
    //GEN_INY1_CTRL_Toggle();
    //GEN_INY2_CTRL_Toggle();
    //GEN_INY3_CTRL_Toggle();
    //GEN_INY4_CTRL_Toggle();
    //UART5_Write_Mio(&mensaje, sizeof(mensaje));
}




/* *****************************************************************************
 End of File
 */