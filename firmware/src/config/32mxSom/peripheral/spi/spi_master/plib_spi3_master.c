/*******************************************************************************
  SPI PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_spi3_master.c

  Summary:
    SPI3 Master Source File

  Description:
    This file has implementation of all the interfaces provided for particular
    SPI peripheral.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018-2019 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_spi3_master.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: SPI3 Implementation
// *****************************************************************************
// *****************************************************************************

/* Global object to save SPI Exchange related data */
static volatile SPI_OBJECT spi3Obj;

#define SPI3_CON_MSTEN                      (1UL << _SPI3CON_MSTEN_POSITION)
#define SPI3_CON_CKP                        (0UL << _SPI3CON_CKP_POSITION)
#define SPI3_CON_CKE                        (1UL << _SPI3CON_CKE_POSITION)
#define SPI3_CON_MODE_32_MODE_16            (0UL << _SPI3CON_MODE16_POSITION)
#define SPI3_CON_ENHBUF                     (1UL << _SPI3CON_ENHBUF_POSITION)
#define SPI3_CON_MSSEN                      (0UL << _SPI3CON_MSSEN_POSITION)
#define SPI3_CON_SMP                        (0UL << _SPI3CON_SMP_POSITION)

void SPI3_Initialize ( void )
{
    uint32_t rdata;

    /* Disable SPI3 Interrupts */
    IEC0CLR = 0x4000000;
    IEC0CLR = 0x8000000;
    IEC0CLR = 0x10000000;

    /* STOP and Reset the SPI */
    SPI3CON = 0;

    /* Clear the Receiver buffer */
    rdata = SPI3BUF;
    rdata = rdata;

    /* Clear SPI3 Interrupt flags */
    IFS0CLR = 0x4000000;
    IFS0CLR = 0x8000000;
    IFS0CLR = 0x10000000;

    /* BAUD Rate register Setup */
    SPI3BRG = 39;

    /* CLear the Overflow */
    SPI3STATCLR = _SPI3STAT_SPIROV_MASK;

    /*
    MSTEN = 1
    CKP = 0
    CKE = 1
    MODE<32,16> = 0
    ENHBUF = 1
    MSSEN = 0
    */
    SPI3CONSET = (SPI3_CON_MSSEN | SPI3_CON_ENHBUF | SPI3_CON_MODE_32_MODE_16 | SPI3_CON_CKE | SPI3_CON_CKP | SPI3_CON_MSTEN | SPI3_CON_SMP);

    /* Enable transmit interrupt when transmit buffer is completely empty (STXISEL = '01') */
    /* Enable receive interrupt when the receive buffer is not empty (SRXISEL = '01') */
    SPI3CONSET = 0x00000005;

    /* Initialize global variables */
    spi3Obj.transferIsBusy = false;
    spi3Obj.callback = NULL;

    /* Enable SPI3 */
    SPI3CONSET = _SPI3CON_ON_MASK;
}

bool SPI3_TransferSetup (SPI_TRANSFER_SETUP* setup, uint32_t spiSourceClock )
{
    uint32_t t_brg;
    uint32_t baudHigh;
    uint32_t baudLow;
    uint32_t errorHigh;
    uint32_t errorLow;

    if ((setup == NULL) || (setup->clockFrequency == 0U))
    {
        return false;
    }

    if(spiSourceClock == 0U)
    {
        // Use Master Clock Frequency set in GUI
        spiSourceClock = 80000000;
    }

    t_brg = (((spiSourceClock / (setup->clockFrequency)) / 2u) - 1u);
    baudHigh = spiSourceClock / (2u * (t_brg + 1u));
    baudLow = spiSourceClock / (2u * (t_brg + 2u));
    errorHigh = baudHigh - setup->clockFrequency;
    errorLow = setup->clockFrequency - baudLow;

    if (errorHigh > errorLow)
    {
        t_brg++;
    }

    if(t_brg > 511U)
    {
        return false;
    }

    SPI3BRG = t_brg;
    SPI3CON = (SPI3CON & (~(_SPI3CON_MODE16_MASK | _SPI3CON_MODE32_MASK | _SPI3CON_CKP_MASK | _SPI3CON_CKE_MASK))) |
                            ((uint32_t)setup->clockPolarity | (uint32_t)setup->clockPhase | (uint32_t)setup->dataBits);

    return true;
}

bool SPI3_Write(void* pTransmitData, size_t txSize)
{
    return(SPI3_WriteRead(pTransmitData, txSize, NULL, 0));
}

bool SPI3_Read(void* pReceiveData, size_t rxSize)
{
    return(SPI3_WriteRead(NULL, 0, pReceiveData, rxSize));
}

bool SPI3_IsTransmitterBusy (void)
{
    return ((SPI3STAT & _SPI3STAT_SRMT_MASK) == 0U)? true : false;
}

bool SPI3_WriteRead (void* pTransmitData, size_t txSize, void* pReceiveData, size_t rxSize)
{
    bool isRequestAccepted = false;

    /* Verify the request */
    if((spi3Obj.transferIsBusy == false) && (((txSize > 0U) && (pTransmitData != NULL)) || ((rxSize > 0U) && (pReceiveData != NULL))))
    {
        isRequestAccepted = true;
        spi3Obj.txBuffer = pTransmitData;
        spi3Obj.rxBuffer = pReceiveData;
        spi3Obj.rxCount = 0;
        spi3Obj.txCount = 0;
        spi3Obj.dummySize = 0;

        if (pTransmitData != NULL)
        {
            spi3Obj.txSize = txSize;
        }
        else
        {
            spi3Obj.txSize = 0;
        }

        if (pReceiveData != NULL)
        {
            spi3Obj.rxSize = rxSize;
        }
        else
        {
            spi3Obj.rxSize = 0;
        }

        spi3Obj.transferIsBusy = true;

        size_t txSz = spi3Obj.txSize;
        if (spi3Obj.rxSize > txSz)
        {
            spi3Obj.dummySize = spi3Obj.rxSize - txSz;
        }

        /* Clear the receive overflow error if any */
        SPI3STATCLR = _SPI3STAT_SPIROV_MASK;

        /* Make sure there is no data pending in the RX FIFO */
        /* Depending on 8/16/32 bit mode, there may be 16/8/4 bytes in the FIFO */
        while ((SPI3STAT & _SPI3STAT_SPIRBE_MASK) == 0U)
        {
            (void)SPI3BUF;
        }

        /* Configure SPI to generate receive interrupt when receive buffer is empty (SRXISEL = '01') */
        SPI3CONCLR = _SPI3CON_SRXISEL_MASK;
        SPI3CONSET = 0x00000001;

        /* Configure SPI to generate transmit interrupt when the transmit shift register is empty (STXISEL = '00')*/
        SPI3CONCLR = _SPI3CON_STXISEL_MASK;

        /* Disable the receive interrupt */
        IEC0CLR = 0x8000000;

        /* Disable the transmit interrupt */
        IEC0CLR = 0x10000000;

        /* Clear the receive interrupt flag */
        IFS0CLR = 0x8000000;

        /* Clear the transmit interrupt flag */
        IFS0CLR = 0x10000000;

        /* Start the first write here itself, rest will happen in ISR context */
        if((_SPI3CON_MODE32_MASK) == (SPI3CON & (_SPI3CON_MODE32_MASK)))
        {
            spi3Obj.txSize >>= 2;
            spi3Obj.dummySize >>= 2;
            spi3Obj.rxSize >>= 2;

            txSz = spi3Obj.txSize;
            if(spi3Obj.txCount < txSz)
            {
                SPI3BUF = *((uint32_t*)spi3Obj.txBuffer);
                spi3Obj.txCount++;
            }
            else if (spi3Obj.dummySize > 0U)
            {
                SPI3BUF = (uint32_t)(0xffU);
                spi3Obj.dummySize--;
            }
            else
            {
                /* Nothing to process */
            }
        }
        else if((_SPI3CON_MODE16_MASK) == (SPI3CON & (_SPI3CON_MODE16_MASK)))
        {
            spi3Obj.txSize >>= 1;
            spi3Obj.dummySize >>= 1;
            spi3Obj.rxSize >>= 1;

            txSz = spi3Obj.txSize;
            if (spi3Obj.txCount < txSz)
            {
                SPI3BUF = *((uint16_t*)spi3Obj.txBuffer);
                spi3Obj.txCount++;
            }
            else if (spi3Obj.dummySize > 0U)
            {
                SPI3BUF = (uint16_t)(0xffU);
                spi3Obj.dummySize--;
            }
            else
            {
                /* Nothing to process */
            }
        }
        else
        {
            if (spi3Obj.txCount < txSz)
            {
                SPI3BUF = *((uint8_t*)spi3Obj.txBuffer);
                spi3Obj.txCount++;
            }
            else if (spi3Obj.dummySize > 0U)
            {
                SPI3BUF = (uint8_t)(0xffU);
                spi3Obj.dummySize--;
            }
            else
            {
                /* Nothing to process */
            }
        }

        if (rxSize > 0U)
        {
            /* Enable receive interrupt to complete the transfer in ISR context.
             * Keep the transmit interrupt disabled. Transmit interrupt will be
             * enabled later if txCount < txSize, when rxCount = rxSize.
             */
            IEC0SET = 0x8000000;
        }
        else
        {
            if (spi3Obj.txCount != txSz)
            {
                /* Configure SPI to generate transmit buffer empty interrupt only if more than
                 * data is pending (STXISEL = '01')  */
                SPI3CONSET = 0x00000004;
            }
            /* Enable transmit interrupt to complete the transfer in ISR context */
            IEC0SET = 0x10000000;
        }
    }

    return isRequestAccepted;
}

bool SPI3_IsBusy (void)
{
    bool transferIsBusy = spi3Obj.transferIsBusy;

    return (((SPI3STAT & _SPI3STAT_SRMT_MASK) == 0) || (transferIsBusy));
}

void SPI3_CallbackRegister (SPI_CALLBACK callback, uintptr_t context)
{
    spi3Obj.callback = callback;

    spi3Obj.context = context;
}

static void __attribute__((used)) SPI3_RX_InterruptHandler (void)
{
    uint32_t receivedData = 0;

    /* Check if the receive buffer is empty or not */
    if ((SPI3STAT & _SPI3STAT_SPIRBE_MASK) == 0U)
    {
        /* Receive buffer is not empty. Read the received data. */
        receivedData = SPI3BUF;

        size_t rxCount = spi3Obj.rxCount;
        size_t txCount = spi3Obj.txCount;

        if (rxCount < spi3Obj.rxSize)
        {
            /* Copy the received data to the user buffer */
            if((_SPI3CON_MODE32_MASK) == (SPI3CON & (_SPI3CON_MODE32_MASK)))
            {
                ((uint32_t*)spi3Obj.rxBuffer)[rxCount] = receivedData;
                rxCount++;
            }
            else if((_SPI3CON_MODE16_MASK) == (SPI3CON & (_SPI3CON_MODE16_MASK)))
            {
                ((uint16_t*)spi3Obj.rxBuffer)[rxCount] = (uint16_t)receivedData;
                rxCount++;
            }
            else
            {
                ((uint8_t*)spi3Obj.rxBuffer)[rxCount] = (uint8_t)receivedData;
                rxCount++;
            }

            spi3Obj.rxCount = rxCount;

            if (rxCount == spi3Obj.rxSize)
            {
                if (txCount < spi3Obj.txSize)
                {
                    /* Reception of all bytes is complete. However, there are few more
                     * bytes to be transmitted as txCount != txSize. Finish the
                     * transmission of the remaining bytes from the transmit interrupt. */

                    /* Disable the receive interrupt */
                    IEC0CLR = 0x8000000;

                    /* Generate TX interrupt when buffer is completely empty (STXISEL = '00') */
                    SPI3CONCLR = _SPI3CON_STXISEL_MASK;
                    SPI3CONSET = 0x00000004;

                    /* Enable the transmit interrupt. Callback will be given from the
                     * transmit interrupt, when all bytes are shifted out. */
                    IEC0SET = 0x10000000;
                }
            }
        }
        if (rxCount < spi3Obj.rxSize)
        {
            /* More bytes pending to be received .. */
            if((_SPI3CON_MODE32_MASK) == (SPI3CON & (_SPI3CON_MODE32_MASK)))
            {
                if (txCount < spi3Obj.txSize)
                {
                    SPI3BUF = ((uint32_t*)spi3Obj.txBuffer)[txCount];
                    txCount++;
                }
                else if (spi3Obj.dummySize > 0U)
                {
                    SPI3BUF = (uint32_t)(0xffU);
                    spi3Obj.dummySize--;
                }
               else
                {
                   /* Do Nothing */
                }
            }
            else if((_SPI3CON_MODE16_MASK) == (SPI3CON & (_SPI3CON_MODE16_MASK)))
            {
                if (txCount < spi3Obj.txSize)
                {
                    SPI3BUF = ((uint16_t*)spi3Obj.txBuffer)[txCount];
                    txCount++;
                }
                else if (spi3Obj.dummySize > 0U)
                {
                    SPI3BUF = (uint16_t)(0xffU);
                    spi3Obj.dummySize--;
                }
               else
                {
                      /* Do Nothing */
                }
            }
            else
            {
                if (txCount < spi3Obj.txSize)
                {
                    SPI3BUF = ((uint8_t*)spi3Obj.txBuffer)[txCount];
                    txCount++;
                }
                else if (spi3Obj.dummySize > 0U)
                {
                    SPI3BUF = (uint8_t)(0xffU);
                    spi3Obj.dummySize--;
                }
               else
                {
                    /* Do Nothing */
                }
            }

            spi3Obj.txCount = txCount;
        }
        else
        {
            if(rxCount == spi3Obj.rxSize)
            {
                if (txCount == spi3Obj.txSize)
                {
                    /* Clear receiver overflow error if any */
                    SPI3STATCLR = _SPI3STAT_SPIROV_MASK;

                    /* Disable receive interrupt */
                    IEC0CLR = 0x8000000;

                    /* Transfer complete. Give a callback */
                    spi3Obj.transferIsBusy = false;

                    if(spi3Obj.callback != NULL)
                    {
                        uintptr_t context = spi3Obj.context;

                        spi3Obj.callback(context);
                    }
                }
            }
        }
    }

    /* Clear SPI3 RX Interrupt flag */
    /* This flag should cleared only after reading buffer */
    IFS0CLR = 0x8000000;
}

static void __attribute__((used)) SPI3_TX_InterruptHandler (void)
{
    /* If there are more words to be transmitted, then transmit them here and keep track of the count */
    if((SPI3STAT & _SPI3STAT_SPITBE_MASK) == _SPI3STAT_SPITBE_MASK)
    {
        size_t txCount = spi3Obj.txCount;

        if (txCount < spi3Obj.txSize)
        {
            if((_SPI3CON_MODE32_MASK) == (SPI3CON & (_SPI3CON_MODE32_MASK)))
            {
                SPI3BUF = ((uint32_t*)spi3Obj.txBuffer)[txCount];
                txCount++;
            }
            else if((_SPI3CON_MODE16_MASK) == (SPI3CON & (_SPI3CON_MODE16_MASK)))
            {
                SPI3BUF = ((uint16_t*)spi3Obj.txBuffer)[txCount];
                txCount++;
            }
            else
            {
                SPI3BUF = ((uint8_t*)spi3Obj.txBuffer)[txCount];
                txCount++;
            }

            spi3Obj.txCount = txCount;

            if (txCount == spi3Obj.txSize)
            {
                /* All bytes are submitted to the SPI module. Now, enable transmit
                 * interrupt when the shift register is empty (STXISEL = '00')*/
                SPI3CONCLR = _SPI3CON_STXISEL_MASK;
            }
        }
        else if (txCount == spi3Obj.txSize)
        {
            if ((SPI3STAT & _SPI3STAT_SRMT_MASK) != 0U)
            {
                /* This part of code is executed when the shift register is empty. */

                /* Clear receiver overflow error if any */
                SPI3STATCLR = _SPI3STAT_SPIROV_MASK;

                /* Disable transmit interrupt */
                IEC0CLR = 0x10000000;

                /* Transfer complete. Give a callback */
                spi3Obj.transferIsBusy = false;

                if(spi3Obj.callback != NULL)
                {
                    uintptr_t context = spi3Obj.context;

                    spi3Obj.callback(context);
                }
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* Clear the transmit interrupt flag */
    IFS0CLR = 0x10000000;
}

void __attribute__((used)) SPI_3_InterruptHandler (void)
{
    uint32_t iec_reg_read = IEC0;
    if (((IFS0 & _IFS0_SPI3RXIF_MASK) != 0U) && (( iec_reg_read & _IEC0_SPI3RXIE_MASK)!= 0U))
    {
        /* RX interrupt is enabled and RX buffer is not empty */
        SPI3_RX_InterruptHandler();
    }
    iec_reg_read = IEC0;
    if (((IFS0 & _IFS0_SPI3TXIF_MASK) != 0U) && ((iec_reg_read & _IEC0_SPI3TXIE_MASK) != 0U))
    {
        /* TX interrupt is enabled and TX buffer is empty */
        SPI3_TX_InterruptHandler();
    }
}
