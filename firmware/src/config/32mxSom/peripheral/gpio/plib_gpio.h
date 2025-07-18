/*******************************************************************************
  GPIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_gpio.h

  Summary:
    GPIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (GPIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_GPIO_H
#define PLIB_GPIO_H

#include <device.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for GEN_INY2_CTRL pin ***/
#define GEN_INY2_CTRL_Set()               (LATESET = (1<<7))
#define GEN_INY2_CTRL_Clear()             (LATECLR = (1<<7))
#define GEN_INY2_CTRL_Toggle()            (LATEINV= (1<<7))
#define GEN_INY2_CTRL_OutputEnable()      (TRISECLR = (1<<7))
#define GEN_INY2_CTRL_InputEnable()       (TRISESET = (1<<7))
#define GEN_INY2_CTRL_Get()               ((PORTE >> 7) & 0x1)
#define GEN_INY2_CTRL_GetLatch()          ((LATE >> 7) & 0x1)
#define GEN_INY2_CTRL_PIN                  GPIO_PIN_RE7

/*** Macros for GEN_INY1_CTRL pin ***/
#define GEN_INY1_CTRL_Set()               (LATGSET = (1<<9))
#define GEN_INY1_CTRL_Clear()             (LATGCLR = (1<<9))
#define GEN_INY1_CTRL_Toggle()            (LATGINV= (1<<9))
#define GEN_INY1_CTRL_OutputEnable()      (TRISGCLR = (1<<9))
#define GEN_INY1_CTRL_InputEnable()       (TRISGSET = (1<<9))
#define GEN_INY1_CTRL_Get()               ((PORTG >> 9) & 0x1)
#define GEN_INY1_CTRL_GetLatch()          ((LATG >> 9) & 0x1)
#define GEN_INY1_CTRL_PIN                  GPIO_PIN_RG9

/*** Macros for ADQ_MAF pin ***/
#define ADQ_MAF_Get()               ((PORTE >> 8) & 0x1)
#define ADQ_MAF_GetLatch()          ((LATE >> 8) & 0x1)
#define ADQ_MAF_PIN                  GPIO_PIN_RE8

/*** Macros for ADQ_CMP pin ***/
#define ADQ_CMP_Get()               ((PORTE >> 9) & 0x1)
#define ADQ_CMP_GetLatch()          ((LATE >> 9) & 0x1)
#define ADQ_CMP_PIN                  GPIO_PIN_RE9

/*** Macros for ADQ_INY1_SH pin ***/
#define ADQ_INY1_SH_Get()               ((PORTB >> 4) & 0x1)
#define ADQ_INY1_SH_GetLatch()          ((LATB >> 4) & 0x1)
#define ADQ_INY1_SH_PIN                  GPIO_PIN_RB4

/*** Macros for ADQ_INY2_SH pin ***/
#define ADQ_INY2_SH_Get()               ((PORTB >> 3) & 0x1)
#define ADQ_INY2_SH_GetLatch()          ((LATB >> 3) & 0x1)
#define ADQ_INY2_SH_PIN                  GPIO_PIN_RB3

/*** Macros for ADQ_INY3_SH pin ***/
#define ADQ_INY3_SH_Get()               ((PORTB >> 2) & 0x1)
#define ADQ_INY3_SH_GetLatch()          ((LATB >> 2) & 0x1)
#define ADQ_INY3_SH_PIN                  GPIO_PIN_RB2

/*** Macros for ADQ_INY4_SH pin ***/
#define ADQ_INY4_SH_Get()               ((PORTB >> 6) & 0x1)
#define ADQ_INY4_SH_GetLatch()          ((LATB >> 6) & 0x1)
#define ADQ_INY4_SH_PIN                  GPIO_PIN_RB6

/*** Macros for ADQ_AN3 pin ***/
#define ADQ_AN3_Get()               ((PORTB >> 9) & 0x1)
#define ADQ_AN3_GetLatch()          ((LATB >> 9) & 0x1)
#define ADQ_AN3_PIN                  GPIO_PIN_RB9

/*** Macros for ADQ_AN1 pin ***/
#define ADQ_AN1_Get()               ((PORTB >> 10) & 0x1)
#define ADQ_AN1_GetLatch()          ((LATB >> 10) & 0x1)
#define ADQ_AN1_PIN                  GPIO_PIN_RB10

/*** Macros for ADQ_AN2 pin ***/
#define ADQ_AN2_Get()               ((PORTB >> 11) & 0x1)
#define ADQ_AN2_GetLatch()          ((LATB >> 11) & 0x1)
#define ADQ_AN2_PIN                  GPIO_PIN_RB11

/*** Macros for RN42_RX pin ***/
#define RN42_RX_Get()               ((PORTF >> 13) & 0x1)
#define RN42_RX_GetLatch()          ((LATF >> 13) & 0x1)
#define RN42_RX_PIN                  GPIO_PIN_RF13

/*** Macros for RN42_TX pin ***/
#define RN42_TX_Get()               ((PORTF >> 12) & 0x1)
#define RN42_TX_GetLatch()          ((LATF >> 12) & 0x1)
#define RN42_TX_PIN                  GPIO_PIN_RF12

/*** Macros for ADQ_MAP pin ***/
#define ADQ_MAP_Get()               ((PORTB >> 12) & 0x1)
#define ADQ_MAP_GetLatch()          ((LATB >> 12) & 0x1)
#define ADQ_MAP_PIN                  GPIO_PIN_RB12

/*** Macros for ADQ_T_ESC pin ***/
#define ADQ_T_ESC_Get()               ((PORTB >> 13) & 0x1)
#define ADQ_T_ESC_GetLatch()          ((LATB >> 13) & 0x1)
#define ADQ_T_ESC_PIN                  GPIO_PIN_RB13

/*** Macros for ADQ_PP2 pin ***/
#define ADQ_PP2_Get()               ((PORTB >> 14) & 0x1)
#define ADQ_PP2_GetLatch()          ((LATB >> 14) & 0x1)
#define ADQ_PP2_PIN                  GPIO_PIN_RB14

/*** Macros for ADQ_PP1 pin ***/
#define ADQ_PP1_Get()               ((PORTB >> 15) & 0x1)
#define ADQ_PP1_GetLatch()          ((LATB >> 15) & 0x1)
#define ADQ_PP1_PIN                  GPIO_PIN_RB15

/*** Macros for SPI3_CS pin ***/
#define SPI3_CS_Set()               (LATDSET = (1<<14))
#define SPI3_CS_Clear()             (LATDCLR = (1<<14))
#define SPI3_CS_Toggle()            (LATDINV= (1<<14))
#define SPI3_CS_OutputEnable()      (TRISDCLR = (1<<14))
#define SPI3_CS_InputEnable()       (TRISDSET = (1<<14))
#define SPI3_CS_Get()               ((PORTD >> 14) & 0x1)
#define SPI3_CS_GetLatch()          ((LATD >> 14) & 0x1)
#define SPI3_CS_PIN                  GPIO_PIN_RD14

/*** Macros for SPI3_SCK pin ***/
#define SPI3_SCK_Get()               ((PORTD >> 15) & 0x1)
#define SPI3_SCK_GetLatch()          ((LATD >> 15) & 0x1)
#define SPI3_SCK_PIN                  GPIO_PIN_RD15

/*** Macros for SIM800_TX pin ***/
#define SIM800_TX_Get()               ((PORTF >> 4) & 0x1)
#define SIM800_TX_GetLatch()          ((LATF >> 4) & 0x1)
#define SIM800_TX_PIN                  GPIO_PIN_RF4

/*** Macros for SIM800_RX pin ***/
#define SIM800_RX_Get()               ((PORTF >> 5) & 0x1)
#define SIM800_RX_GetLatch()          ((LATF >> 5) & 0x1)
#define SIM800_RX_PIN                  GPIO_PIN_RF5

/*** Macros for SIM800_RST pin ***/
#define SIM800_RST_Set()               (LATFSET = (1<<3))
#define SIM800_RST_Clear()             (LATFCLR = (1<<3))
#define SIM800_RST_Toggle()            (LATFINV= (1<<3))
#define SIM800_RST_OutputEnable()      (TRISFCLR = (1<<3))
#define SIM800_RST_InputEnable()       (TRISFSET = (1<<3))
#define SIM800_RST_Get()               ((PORTF >> 3) & 0x1)
#define SIM800_RST_GetLatch()          ((LATF >> 3) & 0x1)
#define SIM800_RST_PIN                  GPIO_PIN_RF3

/*** Macros for SPI3_SDI pin ***/
#define SPI3_SDI_Get()               ((PORTF >> 2) & 0x1)
#define SPI3_SDI_GetLatch()          ((LATF >> 2) & 0x1)
#define SPI3_SDI_PIN                  GPIO_PIN_RF2

/*** Macros for SPI3_SDO pin ***/
#define SPI3_SDO_Get()               ((PORTF >> 8) & 0x1)
#define SPI3_SDO_GetLatch()          ((LATF >> 8) & 0x1)
#define SPI3_SDO_PIN                  GPIO_PIN_RF8

/*** Macros for GEN_SCL_PPA pin ***/
#define GEN_SCL_PPA_Get()               ((PORTA >> 2) & 0x1)
#define GEN_SCL_PPA_GetLatch()          ((LATA >> 2) & 0x1)
#define GEN_SCL_PPA_PIN                  GPIO_PIN_RA2

/*** Macros for GEN_SDA_PPA pin ***/
#define GEN_SDA_PPA_Get()               ((PORTA >> 3) & 0x1)
#define GEN_SDA_PPA_GetLatch()          ((LATA >> 3) & 0x1)
#define GEN_SDA_PPA_PIN                  GPIO_PIN_RA3

/*** Macros for GEN_A0_PP2 pin ***/
#define GEN_A0_PP2_Set()               (LATASET = (1<<4))
#define GEN_A0_PP2_Clear()             (LATACLR = (1<<4))
#define GEN_A0_PP2_Toggle()            (LATAINV= (1<<4))
#define GEN_A0_PP2_OutputEnable()      (TRISACLR = (1<<4))
#define GEN_A0_PP2_InputEnable()       (TRISASET = (1<<4))
#define GEN_A0_PP2_Get()               ((PORTA >> 4) & 0x1)
#define GEN_A0_PP2_GetLatch()          ((LATA >> 4) & 0x1)
#define GEN_A0_PP2_PIN                  GPIO_PIN_RA4

/*** Macros for GEN_A0_PP1 pin ***/
#define GEN_A0_PP1_Set()               (LATASET = (1<<5))
#define GEN_A0_PP1_Clear()             (LATACLR = (1<<5))
#define GEN_A0_PP1_Toggle()            (LATAINV= (1<<5))
#define GEN_A0_PP1_OutputEnable()      (TRISACLR = (1<<5))
#define GEN_A0_PP1_InputEnable()       (TRISASET = (1<<5))
#define GEN_A0_PP1_Get()               ((PORTA >> 5) & 0x1)
#define GEN_A0_PP1_GetLatch()          ((LATA >> 5) & 0x1)
#define GEN_A0_PP1_PIN                  GPIO_PIN_RA5

/*** Macros for ADQ_LLAVE pin ***/
#define ADQ_LLAVE_Set()               (LATCSET = (1<<15))
#define ADQ_LLAVE_Clear()             (LATCCLR = (1<<15))
#define ADQ_LLAVE_Toggle()            (LATCINV= (1<<15))
#define ADQ_LLAVE_OutputEnable()      (TRISCCLR = (1<<15))
#define ADQ_LLAVE_InputEnable()       (TRISCSET = (1<<15))
#define ADQ_LLAVE_Get()               ((PORTC >> 15) & 0x1)
#define ADQ_LLAVE_GetLatch()          ((LATC >> 15) & 0x1)
#define ADQ_LLAVE_PIN                  GPIO_PIN_RC15

/*** Macros for ADQ_INY_REF pin ***/
#define ADQ_INY_REF_Get()               ((PORTA >> 14) & 0x1)
#define ADQ_INY_REF_GetLatch()          ((LATA >> 14) & 0x1)
#define ADQ_INY_REF_PIN                  GPIO_PIN_RA14

/*** Macros for GEN_CKP pin ***/
#define GEN_CKP_Set()               (LATASET = (1<<15))
#define GEN_CKP_Clear()             (LATACLR = (1<<15))
#define GEN_CKP_Toggle()            (LATAINV= (1<<15))
#define GEN_CKP_OutputEnable()      (TRISACLR = (1<<15))
#define GEN_CKP_InputEnable()       (TRISASET = (1<<15))
#define GEN_CKP_Get()               ((PORTA >> 15) & 0x1)
#define GEN_CKP_GetLatch()          ((LATA >> 15) & 0x1)
#define GEN_CKP_PIN                  GPIO_PIN_RA15

/*** Macros for ADQ_CKP pin ***/
#define ADQ_CKP_Get()               ((PORTD >> 0) & 0x1)
#define ADQ_CKP_GetLatch()          ((LATD >> 0) & 0x1)
#define ADQ_CKP_PIN                  GPIO_PIN_RD0

/*** Macros for GEN_CMP pin ***/
#define GEN_CMP_Set()               (LATDSET = (1<<1))
#define GEN_CMP_Clear()             (LATDCLR = (1<<1))
#define GEN_CMP_Toggle()            (LATDINV= (1<<1))
#define GEN_CMP_OutputEnable()      (TRISDCLR = (1<<1))
#define GEN_CMP_InputEnable()       (TRISDSET = (1<<1))
#define GEN_CMP_Get()               ((PORTD >> 1) & 0x1)
#define GEN_CMP_GetLatch()          ((LATD >> 1) & 0x1)
#define GEN_CMP_PIN                  GPIO_PIN_RD1

/*** Macros for GEN_INY3_CTRL pin ***/
#define GEN_INY3_CTRL_Set()               (LATGSET = (1<<1))
#define GEN_INY3_CTRL_Clear()             (LATGCLR = (1<<1))
#define GEN_INY3_CTRL_Toggle()            (LATGINV= (1<<1))
#define GEN_INY3_CTRL_OutputEnable()      (TRISGCLR = (1<<1))
#define GEN_INY3_CTRL_InputEnable()       (TRISGSET = (1<<1))
#define GEN_INY3_CTRL_Get()               ((PORTG >> 1) & 0x1)
#define GEN_INY3_CTRL_GetLatch()          ((LATG >> 1) & 0x1)
#define GEN_INY3_CTRL_PIN                  GPIO_PIN_RG1

/*** Macros for GEN_INY4_CTRL pin ***/
#define GEN_INY4_CTRL_Set()               (LATGSET = (1<<0))
#define GEN_INY4_CTRL_Clear()             (LATGCLR = (1<<0))
#define GEN_INY4_CTRL_Toggle()            (LATGINV= (1<<0))
#define GEN_INY4_CTRL_OutputEnable()      (TRISGCLR = (1<<0))
#define GEN_INY4_CTRL_InputEnable()       (TRISGSET = (1<<0))
#define GEN_INY4_CTRL_Get()               ((PORTG >> 0) & 0x1)
#define GEN_INY4_CTRL_GetLatch()          ((LATG >> 0) & 0x1)
#define GEN_INY4_CTRL_PIN                  GPIO_PIN_RG0

/*** Macros for GEN_RLY_INY pin ***/
#define GEN_RLY_INY_Set()               (LATASET = (1<<7))
#define GEN_RLY_INY_Clear()             (LATACLR = (1<<7))
#define GEN_RLY_INY_Toggle()            (LATAINV= (1<<7))
#define GEN_RLY_INY_OutputEnable()      (TRISACLR = (1<<7))
#define GEN_RLY_INY_InputEnable()       (TRISASET = (1<<7))
#define GEN_RLY_INY_Get()               ((PORTA >> 7) & 0x1)
#define GEN_RLY_INY_GetLatch()          ((LATA >> 7) & 0x1)
#define GEN_RLY_INY_PIN                  GPIO_PIN_RA7


// *****************************************************************************
/* GPIO Port

  Summary:
    Identifies the available GPIO Ports.

  Description:
    This enumeration identifies the available GPIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


#define    GPIO_PORT_A   (0)
#define    GPIO_PORT_B   (1)
#define    GPIO_PORT_C   (2)
#define    GPIO_PORT_D   (3)
#define    GPIO_PORT_E   (4)
#define    GPIO_PORT_F   (5)
#define    GPIO_PORT_G   (6)
typedef uint32_t GPIO_PORT;

// *****************************************************************************
/* GPIO Port Pins

  Summary:
    Identifies the available GPIO port pins.

  Description:
    This enumeration identifies the available GPIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/
#define    GPIO_PIN_RA0   (0)
#define    GPIO_PIN_RA1   (1)
#define    GPIO_PIN_RA2   (2)
#define    GPIO_PIN_RA3   (3)
#define    GPIO_PIN_RA4   (4)
#define    GPIO_PIN_RA5   (5)
#define    GPIO_PIN_RA6   (6)
#define    GPIO_PIN_RA7   (7)
#define    GPIO_PIN_RA9   (9)
#define    GPIO_PIN_RA10   (10)
#define    GPIO_PIN_RA14   (14)
#define    GPIO_PIN_RA15   (15)
#define    GPIO_PIN_RB0   (16)
#define    GPIO_PIN_RB1   (17)
#define    GPIO_PIN_RB2   (18)
#define    GPIO_PIN_RB3   (19)
#define    GPIO_PIN_RB4   (20)
#define    GPIO_PIN_RB5   (21)
#define    GPIO_PIN_RB6   (22)
#define    GPIO_PIN_RB7   (23)
#define    GPIO_PIN_RB8   (24)
#define    GPIO_PIN_RB9   (25)
#define    GPIO_PIN_RB10   (26)
#define    GPIO_PIN_RB11   (27)
#define    GPIO_PIN_RB12   (28)
#define    GPIO_PIN_RB13   (29)
#define    GPIO_PIN_RB14   (30)
#define    GPIO_PIN_RB15   (31)
#define    GPIO_PIN_RC1   (33)
#define    GPIO_PIN_RC2   (34)
#define    GPIO_PIN_RC3   (35)
#define    GPIO_PIN_RC4   (36)
#define    GPIO_PIN_RC12   (44)
#define    GPIO_PIN_RC13   (45)
#define    GPIO_PIN_RC14   (46)
#define    GPIO_PIN_RC15   (47)
#define    GPIO_PIN_RD0   (48)
#define    GPIO_PIN_RD1   (49)
#define    GPIO_PIN_RD2   (50)
#define    GPIO_PIN_RD3   (51)
#define    GPIO_PIN_RD4   (52)
#define    GPIO_PIN_RD5   (53)
#define    GPIO_PIN_RD6   (54)
#define    GPIO_PIN_RD7   (55)
#define    GPIO_PIN_RD8   (56)
#define    GPIO_PIN_RD9   (57)
#define    GPIO_PIN_RD10   (58)
#define    GPIO_PIN_RD11   (59)
#define    GPIO_PIN_RD12   (60)
#define    GPIO_PIN_RD13   (61)
#define    GPIO_PIN_RD14   (62)
#define    GPIO_PIN_RD15   (63)
#define    GPIO_PIN_RE0   (64)
#define    GPIO_PIN_RE1   (65)
#define    GPIO_PIN_RE2   (66)
#define    GPIO_PIN_RE3   (67)
#define    GPIO_PIN_RE4   (68)
#define    GPIO_PIN_RE5   (69)
#define    GPIO_PIN_RE6   (70)
#define    GPIO_PIN_RE7   (71)
#define    GPIO_PIN_RE8   (72)
#define    GPIO_PIN_RE9   (73)
#define    GPIO_PIN_RF0   (80)
#define    GPIO_PIN_RF1   (81)
#define    GPIO_PIN_RF2   (82)
#define    GPIO_PIN_RF3   (83)
#define    GPIO_PIN_RF4   (84)
#define    GPIO_PIN_RF5   (85)
#define    GPIO_PIN_RF8   (88)
#define    GPIO_PIN_RF12   (92)
#define    GPIO_PIN_RF13   (93)
#define    GPIO_PIN_RG0   (96)
#define    GPIO_PIN_RG1   (97)
#define    GPIO_PIN_RG2   (98)
#define    GPIO_PIN_RG3   (99)
#define    GPIO_PIN_RG6   (102)
#define    GPIO_PIN_RG7   (103)
#define    GPIO_PIN_RG8   (104)
#define    GPIO_PIN_RG9   (105)
#define    GPIO_PIN_RG12   (108)
#define    GPIO_PIN_RG13   (109)
#define    GPIO_PIN_RG14   (110)
#define    GPIO_PIN_RG15   (111)

    /* This element should not be used in any of the GPIO APIs.
       It will be used by other modules or application to denote that none of the GPIO Pin is used */
#define    GPIO_PIN_NONE     (-1)

typedef uint32_t GPIO_PIN;

typedef enum
{
  CN0_PIN = 1 << 0,
  CN1_PIN = 1 << 1,
  CN2_PIN = 1 << 2,
  CN3_PIN = 1 << 3,
  CN4_PIN = 1 << 4,
  CN5_PIN = 1 << 5,
  CN6_PIN = 1 << 6,
  CN7_PIN = 1 << 7,
  CN8_PIN = 1 << 8,
  CN9_PIN = 1 << 9,
  CN10_PIN = 1 << 10,
  CN11_PIN = 1 << 11,
  CN12_PIN = 1 << 12,
  CN13_PIN = 1 << 13,
  CN14_PIN = 1 << 14,
  CN15_PIN = 1 << 15,
  CN16_PIN = 1 << 16,
  CN17_PIN = 1 << 17,
  CN18_PIN = 1 << 18,
  CN19_PIN = 1 << 19,
  CN20_PIN = 1 << 20,
  CN21_PIN = 1 << 21,
}CN_PIN;


void GPIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t GPIO_PortRead(GPIO_PORT port);

void GPIO_PortWrite(GPIO_PORT port, uint32_t mask, uint32_t value);

uint32_t GPIO_PortLatchRead ( GPIO_PORT port );

void GPIO_PortSet(GPIO_PORT port, uint32_t mask);

void GPIO_PortClear(GPIO_PORT port, uint32_t mask);

void GPIO_PortToggle(GPIO_PORT port, uint32_t mask);

void GPIO_PortInputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortOutputEnable(GPIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void GPIO_PinWrite(GPIO_PIN pin, bool value)
{
    GPIO_PortWrite((GPIO_PORT)(pin>>4), (uint32_t)(0x1UL) << (pin & 0xFU), (uint32_t)(value) << (pin & 0xFU));
}

static inline bool GPIO_PinRead(GPIO_PIN pin)
{
    return (bool)(((GPIO_PortRead((GPIO_PORT)(pin>>4U))) >> (pin & 0xFU)) & 0x1U);
}

static inline bool GPIO_PinLatchRead(GPIO_PIN pin)
{
    return (bool)((GPIO_PortLatchRead((GPIO_PORT)(pin>>4U)) >> (pin & 0xFU)) & 0x1U);
}

static inline void GPIO_PinToggle(GPIO_PIN pin)
{
    GPIO_PortToggle((GPIO_PORT)(pin>>4U), 0x1UL << (pin & 0xFU));
}

static inline void GPIO_PinSet(GPIO_PIN pin)
{
    GPIO_PortSet((GPIO_PORT)(pin>>4U), 0x1UL << (pin & 0xFU));
}

static inline void GPIO_PinClear(GPIO_PIN pin)
{
    GPIO_PortClear((GPIO_PORT)(pin>>4U), 0x1UL << (pin & 0xFU));
}

static inline void GPIO_PinInputEnable(GPIO_PIN pin)
{
    GPIO_PortInputEnable((GPIO_PORT)(pin>>4U), 0x1UL << (pin & 0xFU));
}

static inline void GPIO_PinOutputEnable(GPIO_PIN pin)
{
    GPIO_PortOutputEnable((GPIO_PORT)(pin>>4U), 0x1UL << (pin & 0xFU));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_GPIO_H
