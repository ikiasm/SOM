/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2025 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "interrupts.h"
#include "definitions.h"



// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************


/* All the handlers are defined here.  Each will call its PLIB-specific function. */
// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector declarations
// *****************************************************************************
// *****************************************************************************
void EXTERNAL_0_Handler (void);
void TIMER_2_Handler (void);
void EXTERNAL_2_Handler (void);
void TIMER_3_Handler (void);
void TIMER_4_Handler (void);
void TIMER_5_Handler (void);
void SPI_3_Handler (void);
void ADC_Handler (void);
void UART_2_Handler (void);
void I2C_2_Handler (void);
void UART_5_Handler (void);


// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector definitions
// *****************************************************************************
// *****************************************************************************
void __attribute__((used)) __ISR(_EXTERNAL_0_VECTOR, ipl5SOFT) EXTERNAL_0_Handler (void)
{
    //ckpRelativeAngle(0);
    //ckpAdquisicion(); //SAFE Function
    //ckpAdquisicionPrevia();//Saque para hacer la prueba de Adolfo
    ckpAdquisicionVueltaPrevia();
    EXTERNAL_0_InterruptHandler();
}

void __attribute__((used)) __ISR(_TIMER_2_VECTOR, ipl1SOFT) TIMER_2_Handler (void)
{
    //Timer period unit= 5us
    ticks();
    TIMER_2_InterruptHandler();
}

void __attribute__((used)) __ISR(_EXTERNAL_2_VECTOR, ipl5SOFT) EXTERNAL_2_Handler (void)
{
    //CMP
    cmpAdquisicion();   //SAFE Function
    EXTERNAL_2_InterruptHandler();
}

void __attribute__((used)) __ISR(_TIMER_3_VECTOR, ipl1SOFT) TIMER_3_Handler (void)
{
    //Timer period unit= 44us
    delayPulsoCkp();
    TIMER_3_InterruptHandler();
}

void __attribute__((used)) __ISR(_TIMER_4_VECTOR, ipl6SOFT) TIMER_4_Handler (void)
{
    //Timer period unit= 5us
    //Destinado como contador de tiempo de pulsos RPM
    //Probablemente no se use como interrupcion
    ticks5UsCounterTimmer4();
    TIMER_4_InterruptHandler();
}

void __attribute__((used)) __ISR(_TIMER_5_VECTOR, ipl1SOFT) TIMER_5_Handler (void)
{
    //Timer periodo variable
    //Destinado para PWM de los Inyectores
    setInyector();
    TIMER_5_InterruptHandler();
}

void __attribute__((used)) __ISR(_SPI_3_VECTOR, ipl1SOFT) SPI_3_Handler (void)
{
    SPI_3_InterruptHandler();
}

void __attribute__((used)) __ISR(_ADC_VECTOR, ipl1SOFT) ADC_Handler (void)
{
    ADC_InterruptHandler();
}

void __attribute__((used)) __ISR(_UART_2_VECTOR, ipl1SOFT) UART_2_Handler (void)
{
    UART_2_InterruptHandler();
}

void __attribute__((used)) __ISR(_I2C_2_VECTOR, ipl1SOFT) I2C_2_Handler (void)
{
    I2C_2_InterruptHandler();
}

void __attribute__((used)) __ISR(_UART_5_VECTOR, ipl1SOFT) UART_5_Handler (void)
{
    UART_5_InterruptHandler();
}




/*******************************************************************************
 End of File
*/
