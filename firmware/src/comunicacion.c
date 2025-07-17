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
#include <stddef.h>
#include <string.h>
#include "comunicacion.h"
#include "globales.h"
#include "adquisicion.h"
#include "mapas.h"
#include <p32xxxx.h>
#include "config/32mxSom/peripheral/gpio/plib_gpio.h"
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

//int ckpAngleAdjustGlobal = 0;
//int ckpAngleAdjust_Global = 0;
uint8_t txData[4 + EEPROM_DATA_LEN];
uint8_t rxData[4 + EEPROM_DATA_LEN];
volatile bool isTransferDone = false;

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
void encoder(uint8_t ch, uint8_t id, uint8_t status,  uint16_t dato, uint16_t address)
{
    //CMD   CH  ID  STATUS  DH  DL  ADH ADL CSUMH   CSUML
    //checksumGenerator()
    //cargar buffer Tx
    //Write buffer Tx
    uint8_t cmd = 'S';
    uint8_t datoH;
    uint8_t datoL;
    uint8_t addressH;
    uint8_t addressL;
    uint16_t checksum;
    uint8_t checksumH;
    uint8_t checksumL;
    
    datoH = dato / 0x100;
    datoL = dato;
    addressH = address / 0x100;
    addressL = address;
    //UINT16 checksumGenerator(UINT8 cmd, UINT8 ch, UINT8 id, UINT8 b3, UINT16 dato, UINT16 address)
    checksum = checksumGenerator(cmd, ch, id, status, dato, address);
    checksumH = checksum / 0x100;
    checksumL = checksum;
    
    transmitBuffer[0] = cmd;
    transmitBuffer[1] = ch;
    transmitBuffer[2] = id;
    transmitBuffer[3] = status;
    transmitBuffer[4] = datoH;
    transmitBuffer[5] = datoL;
    transmitBuffer[6] = checksumH;
    transmitBuffer[7] = checksumL;
    transmitBuffer[8] = addressH;
    transmitBuffer[9] = addressL;
//    transmitBuffer[6] = addressH;
//    transmitBuffer[7] = addressL;
//    transmitBuffer[8] = checksumH;
//    transmitBuffer[9] = checksumL;
    
}

void decoder(void)
{

    UINT16 aux;
    UINT8 cmd = receiveBuffer[0];
    UINT8 ch = receiveBuffer[1];
    UINT8 id = receiveBuffer[2];    
    UINT8 b3 = receiveBuffer[3];
    uint16_t dato = receiveBuffer[4] * 0x100;
    dato = dato + receiveBuffer[5];
    UINT16 address = receiveBuffer[6] * 0x100;
    address = address + receiveBuffer[7];
    UINT16 checksum = receiveBuffer[8] * 0x100;
    checksum = checksum + receiveBuffer[9];
    
    if(cmd)
        {
        if(checksumValidator(cmd, ch, id, b3, dato, address, checksum))
        {
            switch(cmd)
            {
                case 'S':  //SETEA SET
                {
                    //MENSAJE OK
                    //UART_Write_Byte(5, 'S');
                    //Funcion updater()
                        //aux = checksumGenerator(cmd, ch, id, b3, dato, address);
//                        UART_Write_Byte(5, aux);
//                        UART_Write_Byte(5, (aux/0x100));
                    channelSelector();    
                    //updater();
                    resetReceiveBuffer();
                }
                break;

                case 'G':  //PIDE DATO GET
                {
                    //MENSAJE OK
                    
                    channelSelector_Get();      //101224
                    
                    //UART_Write_Byte(5, 'G');  //101224
                    //Funcion returner()
                    
                    resetReceiveBuffer();
                }
                break;

                default:
                    //UART5_Write(&receiveBuffer, sizeof(receiveBuffer));
                    break;
            }
        }
        else
        {
            //DATO INVALIDO MANDAR DE NUEVO
            //MENSAJE NOT OK
            UART_Write_Byte(5, 0xAA);
            
            aux = checksumGenerator(cmd, ch, id, b3, dato, address);
                        UART_Write_Byte(5, aux);
                        UART_Write_Byte(5, (aux/0x100));
            
            resetReceiveBuffer();
        }
    }

}

void resetReceiveBuffer(void)   //OK CONTROLADO
{
    int i = 0;
    for(i=0; i < RX_BUFFER_SIZE; i++)
    {
        receiveBuffer[i] = 0x00;
    }
}

UINT16 checksumGenerator(UINT8 cmd, UINT8 ch, UINT8 id, UINT8 b3, UINT16 dato, UINT16 address)
{
    UINT16 result;
    UINT16 carry;
    unsigned int parcial;
    unsigned int word0;
    unsigned int word1;
    unsigned int word2;
    unsigned int word3;
    
    word0 = cmd * 0x100;
    word0 = word0 + ch;
    
    word1 = id * 0x100;
    word1 = word1 + b3;
    word2 = dato;
    
    word3 = address;
    
    parcial = word0 + word1 + word2 + word3;
    
    carry = parcial & 0xFFFF0000;
    carry = carry / 0x10000;
    if(carry)
    //if(parcial & 0xFFFF0000)
    {
        parcial &= 0xFFFF;
        //parcial++;
        parcial = parcial + carry;
    }
    
//    result ^= parcial;
//    return result;
    return ~(parcial & 0xFFFF);
}


bool checksumValidator(UINT8 cmd, UINT8 ch, UINT8 id, UINT8 b3, uint16_t dato, uint16_t address, uint16_t checksum)
{
    bool result;
    uint32_t parcial;
    uint32_t carry;
    uint16_t word0 = 0;
    uint16_t word1 = 0;
    uint16_t word2 = 0;
    uint16_t word3 = 0;
    uint16_t word4 = 0;
       
    word0 = receiveBuffer[0] * 0x100;
    word0 = word0 + receiveBuffer[1];
    word1 = receiveBuffer[2] * 0x100;
    word1 = word1 + receiveBuffer[3];
    
    
    word2 = receiveBuffer[4] * 0x100;
    word2 = word2 + receiveBuffer[5];
    
    word3 = receiveBuffer[6] * 0x100;
    word3 = word3 + receiveBuffer[7];
    word4 = receiveBuffer[8] * 0x100;
    word4 = word4 + receiveBuffer[9];
    
    parcial = word0 + word1 + word2 + word3 + word4;
    
    carry = parcial & 0xFFFF0000;
    carry = carry / 0x10000;
    if(carry)
    {
        parcial &= 0xFFFF;
        parcial = parcial + carry;
    }
    
    if(parcial == 0xFFFF)
    {
        result = true;
    }
    if(parcial != 0xFFFF)
    {
        result = false;
    }
//    UART5_Write(&word0, sizeof(word0));
//    UART5_Write(&word1, sizeof(word1));
//    UART5_Write(&word2, sizeof(word2));
//    UART5_Write(&word3, sizeof(word3));
//    UART5_Write(&word4, sizeof(word4));
//    UART5_Write(&parcial, sizeof(parcial));
    return result;
}

void channelSelector(void)
{
    uint8_t ch = receiveBuffer[1];
    
    
    switch(ch)
    {
        case 'F':   //FIJO
        {
            updater();
            break;
        }
        case 'M':   //ESPECIFICO DE MEMORIA
        {
            //uploadFromDevice();
            downloadToDevice();
            //ESTO ES LO QUE TIENE QUE HACER AL MEJORAR EL SOFT
            //eepromDevice();
            break;
        }
        case 'A':   //SUMA VALOR EN TABLA
        {
            addLiteralToTable();
            break;
        }
        case 'R':   //RESTA VALOR EN TABLA
        {
            subLiteralToTable();
            break;
        }
        case 's':   //SUMA PORCENTAJE EN TABLA
        {
            addPercentToTable();
            break;
        }
        case 'r':   //RESTA PORCENTAJE EN TABLA
        {
            subPercentToTable();
            break;
        }
        case 'S':
        {
            mapaActualGlobal = MAPA_SAFE;   //CONMUTA A MAPA SAFE
            //mapaActualSafe();
            break;
        }
        case 'T':
        {
            mapaActualGlobal = MAPA_TUNING; //CONMUTA A MAPA TUNING
            mapaTuningUpdate();
            //mapaActualTuning();
            break;
        }
        case 'D':
        {
            initMapasInyGnc();  //CARGAR MAPA SAFE INYECCION GAS Y MAPA EN USO
            initMapasPPAGnc();  //CARGAR MAPA SAFE PPA Y MAPA EN USO
            
            break;
        }
        case 'L':
        {
            programming = true;
            break;
        }
        
        default:
            break;
    }
}


void channelSelector_Get(void)
{
    uint8_t ch = receiveBuffer[1];
    
    switch(ch)
    {
        case 'M':
        {
            uploadFromDevice();     //101224
            break;
        }
        default:
            break;
    }
    
}
void updater(void)
{
    uint8_t id = receiveBuffer[2];
    uint8_t status = receiveBuffer[3];
    uint8_t datoHigh = receiveBuffer[4];
    uint8_t datoLow = receiveBuffer[5];
    uint8_t addressHigh = receiveBuffer[6];
    uint8_t addressLow = receiveBuffer[7];
    
    
                        
    //Aca primero habria que hacer un switch por el byte CH
    //Despues evaluar byte ID
    
    
    switch(receiveBuffer[2])
    {
        case 'K':
        {
            ckpAngleAdjust_Global = receiveBuffer[5] - 30;  //Ajustado para no usar valores negativos
            break;
        }
        case 'A':
        {
            ppaPercentGlobal = receiveBuffer[5];
            break;
        }
        case '1':
        {
            uint16_t dato;
            uint16_t apms;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            apms = addressHigh * 0x100;
            apms = apms + addressLow;
            inyectorUpdater(id, status, dato, apms);
            break;
        }
        case '2':
        {
            uint16_t dato;
            uint16_t apms;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            apms = addressHigh * 0x100;
            apms = apms + addressLow;
            inyectorUpdater(id, status, dato, apms);
            break;
        }case '3':
        {
            uint16_t dato;
            uint16_t apms;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            apms = addressHigh * 0x100;
            apms = apms + addressLow;
            inyectorUpdater(id, status, dato, apms);
            break;
        }
        case '4':
        {
            uint16_t dato;
            uint16_t apms;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            apms = addressHigh * 0x100;
            apms = apms + addressLow;
            inyectorUpdater(id, status, dato, apms);
            break;
        }
        case 't':
        {
            uint16_t dato;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            deadTimeUpdater(dato);
            break;
        }
        case 'S':
        {
            uint16_t dato;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            saturedTimeUpdater(dato);
            break;
        }
        case 'D':
        {
            uint16_t dato;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            dutyUpdater(dato);
            break;
        }
        case 'L':
        {
            uint16_t dato;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            rpmLimiterUpdater(dato);
            break;
        }
        
        default:
            break;
    }
    
}

void addLiteralToTable(void)
{
    uint8_t id = receiveBuffer[2];
    
    switch(id)
    {
        case 'p':   //TABLA PUNTO
        {
            
            break;
        }
        case 'i':   //TABLA INYECCION GAS
        {
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r <= rf ; r++)
                {
                    mapaInyeccionGnc[r][c] = mapaInyeccionGnc[r][c] + dato;
                }
            }
            
            break;
        }
        case 'd':   //TABLA DIESEL
        {
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r <= rf ; r++)
                {
                    mapaPosPedalGenGnc[r][c] = mapaPosPedalGenGnc[r][c] + dato;
                }
            }
            
            break;
        }
        default:
            break;
    }
    
}

void subLiteralToTable(void)
{
    uint8_t id = receiveBuffer[2];
    
    switch(id)
    {
        case 'p':
        {
            break;
        }
        case 'i':
        {
            int aux;
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r<= rf ; r++)
                {
                    aux = mapaInyeccionGnc[r][c] - dato;
                    //Elimino valores negativos
                    if(aux <= 0)
                    {
                        mapaInyeccionGnc[r][c] = inyectorDeadTimeGlobal;
                    }
                    //Resto valor actual - valor nuevo
                    if(aux > 0)
                    {
                        mapaInyeccionGnc[r][c] = mapaInyeccionGnc[r][c] - dato;
                    }
                    //Si el valor es menor que el deadTime, el valor nuevo es el del deadTime
                    if(mapaInyeccionGnc[r][c] < inyectorDeadTimeGlobal)
                    {
                        mapaInyeccionGnc[r][c] = inyectorDeadTimeGlobal;
                    }
                }
            }
            break;
        }
        case 'd':
        {
            int aux;
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r<= rf ; r++)
                {
                    aux = mapaPosPedalGenGnc[r][c] - dato;
                    //Elimino valores negativos
                    if(aux <= 0)
                    {
                        mapaPosPedalGenGnc[r][c] = 210;
                    }
                    //Resto valor actual - valor nuevo
                    if(aux > 0)
                    {
                        mapaPosPedalGenGnc[r][c] = mapaPosPedalGenGnc[r][c] - dato;
                    }
                    //Si el valor  positivo pero menor que 210, el valor nuevo es 210
                    if(mapaPosPedalGenGnc[r][c] < 210)
                    {
                        mapaPosPedalGenGnc[r][c] = 210;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
}

void addPercentToTable(void)
{
     uint8_t id = receiveBuffer[2];
    
    switch(id)
    {
        case 'p':   //TABLA PUNTO
        {
            
            break;
        }
        case 'i':   //TABLA INYECCION GAS
        {
            uint16_t porcentajeDeadTime;
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            uint16_t porcentaje;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r <= rf ; r++)
                {
                    
                    porcentajeDeadTime = (inyectorDeadTimeGlobal * dato) / 100;
                    porcentaje = (mapaInyeccionGnc[r][c] * dato) / 100;
                    mapaInyeccionGnc[r][c] = mapaInyeccionGnc[r][c] + porcentaje;
                    mapaInyeccionGnc[r][c] = mapaInyeccionGnc[r][c] - porcentajeDeadTime;
                }
            }
            
            break;
        }
        case 'd':   //TABLA DIESEL
        {   //ACA NO DISCRIMINO EL LIMITE DEL PEDAL PARA INCREMENTAR COMO LO HAGO CON DEADTIME            
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            uint16_t porcentaje;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r <= rf ; r++)
                {
                    porcentaje = (mapaPosPedalGenGnc[r][c] * dato) / 100;
                    mapaPosPedalGenGnc[r][c] = mapaPosPedalGenGnc[r][c] + porcentaje;
                }
            }
            
            break;
        }
        default:
            break;
    }
 
}

void subPercentToTable(void)
{
    uint8_t id = receiveBuffer[2];
    
    switch(id)
    {
        case 'p':
        {
            break;
        }
        case 'i':
        {
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            uint16_t porcentaje;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r<= rf ; r++)
                {
                    porcentaje = (mapaInyeccionGnc[r][c] * dato) / 100;
                    mapaInyeccionGnc[r][c] = mapaInyeccionGnc[r][c] - porcentaje;
                    if(mapaInyeccionGnc[r][c] < inyectorDeadTimeGlobal)
                    {
                        mapaInyeccionGnc[r][c] = inyectorDeadTimeGlobal;
                    }
                }
            }
            break;
        }
        case 'd':
        {
            uint16_t dato;
            uint8_t status = receiveBuffer[3];
            uint8_t datoHigh = receiveBuffer[4];
            uint8_t datoLow = receiveBuffer[5];
            uint8_t addressHigh = receiveBuffer[6];
            uint8_t addressLow = receiveBuffer[7];
            uint16_t porcentaje;
            dato = datoHigh * 0x100;
            dato = dato + datoLow;
            
            int c = 0;
            int r = 0;
            int rf = addressLow / 0x10;
            int ri = addressHigh / 0x10;
            int cf = addressLow - (rf * 0x10);
            int ci = addressHigh - (ri * 0x10);
            
            for(c = ci ; c <= cf ; c++)
            {
                for(r = ri ; r<= rf ; r++)
                {
                    porcentaje = (mapaPosPedalGenGnc[r][c] * dato) / 100;
                    mapaPosPedalGenGnc[r][c] = mapaPosPedalGenGnc[r][c] - porcentaje;
                    if(mapaPosPedalGenGnc[r][c] < 145)
                    {
                        mapaPosPedalGenGnc[r][c] = 145;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
}


void mapaTuningUpdate()
{
    switch(receiveBuffer[2])
    {
        case 'i':
        {
            if(receiveBuffer[6]!=0xFF && receiveBuffer[7 != 0xFF])  //Si address = 0xFFFF es unicamente cambio de mapa sin actualizar valores
            {
                uint16_t dato;
                uint8_t status = receiveBuffer[3];
                uint8_t datoHigh = receiveBuffer[4];
                uint8_t datoLow = receiveBuffer[5];
                uint8_t addressHigh = receiveBuffer[6];
                uint8_t addressLow = receiveBuffer[7];
                
                dato = datoHigh * 0x100;
                dato = dato + datoLow;
            
                int r = addressLow / 0x10;
                int c = addressLow * 0x01;
                
                mapaInyeccionGnc[r][c] = dato;
                
                
                
            }
            break;
        }
        case 'p':
        {
            break;
        }
        case 'd':
        {
            
            break;           
        }
    }
}

void uploadFromDevice()
{
    
    uploading = true;
}

void downloadToDevice()
{
    //encoder(uint8_t ch, uint8_t id, uint8_t status,  uint16_t dato, uint16_t address)
            //Uso address 0x55AA para deteccion de fin de trama
    uint16_t dato = 0x4F4B;
    uint8_t dato8b;
    programming = true;
    uint16_t startAddressMapaGnc = 0x0000;
    //EEPROM_SaveMatrix_Generic(startAddressMapaGnc, *mapaInyeccionGnc, 14, 16);

    dato8b = EEPROM_ReadByte(startAddressMapaGnc);
    programming = false;
}


void eepromDevice()
{
    uint8_t ch = receiveBuffer[0];
    
    uint32_t eepromAddr = EEPROM_ADDRESS;
    switch(ch)
    {
        case 'S':
        {
//            SPI3_CallbackRegister(SPIEventHandler, (uintptr_t) 0);
            SPI3_CS_Clear();
            SPI3BUF = 0x06;
//            SPI3_Write(EEPROM_CMD_WREN, 1);
            txData[0] = EEPROM_CMD_WRITE;
            txData[1] = (uint8_t)(eepromAddr>>16);
            txData[2] = (uint8_t)(eepromAddr>>8);
            txData[3] = (uint8_t)(eepromAddr);
            
            memcpy(&txData[4], EEPROM_DATA, EEPROM_DATA_LEN);   //Agrego dato a copiar
            SPI3_Write(txData, (4 + EEPROM_DATA_LEN));
            break;
        }
        case 'G':
        {
            
            break;
        }
    }
    
}

void inyectorUpdater(uint8_t id, uint8_t status, uint16_t dato, uint16_t apms)
{
    switch(id)
    {
        case '1':
        {
            if(status == 'E')
            {
                inyector1EnabledGlobal = true;
                inyector2EnabledGlobal = true;
                inyector3EnabledGlobal = true;
                inyector4EnabledGlobal = true;
                inyector1TiempoGlobal = dato;
                inyector2TiempoGlobal = dato;
                inyector3TiempoGlobal = dato;
                inyector4TiempoGlobal = dato;
                
            }
            if(status == 'D')
            {
                inyector1EnabledGlobal = false;
                inyector2EnabledGlobal = false;
                inyector3EnabledGlobal = false;
                inyector4EnabledGlobal = false;
            }
            break;
        }
//        case '1':
//        {
//            if(status == 'E')
//            {
//                inyector1EnabledGlobal = true;
//                inyector1TiempoGlobal = dato;
//                inyector1ApmsGlobal = apms;
//                
//            }
//            if(status == 'D')
//            {
//                inyector1EnabledGlobal = false;
//            }
//            
//            break;
//        }
        case '2':
        {
            if(status == 'E')
            {
                inyector2EnabledGlobal = true;
                inyector2TiempoGlobal = dato;
                inyector2ApmsGlobal = apms;
            }
            if(status == 'D')
            {
                inyector2EnabledGlobal = false;
            }
            
            break;
        }
        case '3':
        {
            if(status == 'E')
            {
                inyector3EnabledGlobal = true;
                inyector3TiempoGlobal = dato;
                inyector3ApmsGlobal = apms;
            }
            if(status == 'D')
            {
                inyector3EnabledGlobal = false;
            }
            break;
        }
        case '4':
        {
            if(status == 'E')
            {
                inyector4EnabledGlobal = true;
                inyector4TiempoGlobal = dato;
                inyector4ApmsGlobal = apms;
            }
            if(status == 'D')
            {
                inyector4EnabledGlobal = false;
            }
            break;
        }
    }
}

void deadTimeUpdater(uint16_t dato)
{
    inyectorDeadTimeGlobal = dato;
}

void saturedTimeUpdater(uint16_t dato)
{
    saturacion_usGlobal = dato;
}

void dutyUpdater(uint16_t dato)
{
    dutyPosGlobal = dato;
    dutyNegGlobal = 100 - dato;
}

void rpmLimiterUpdater(uint16_t dato)
{
    RPM_Limiter_Global = dato;
}

void mapaActualSafe()
{
    mapaSafe = true;
}

void mapaActualTuning()
{
    mapaSafe = false;
}

void dataSender()
{
    static int prioridadDato = 0;
    static int subprioridadDato = 0;
    
    switch(prioridadDato)
    {
        case 0: //Rpm
        {
            //encoder(uint8_t ch, uint8_t id, uint8_t status,  uint16_t dato, uint16_t address)
            //Uso address 0x55AA para deteccion de fin de trama
            encoder('F', 'R', 'E', RPM_Global, 0xAA55);
            UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
            prioridadDato++;
            if(programming)
            {
                //prioridadDato = 9;
            }
            
            break;
        }
        case 1: //Acelerador Porcentaje
        {
            if(subprioridadDato == 0)
            {
                //posicion de pedal
                encoder('F', 'A', 'E', adquirirAnalogico(PP1), 0xAA55);
                UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
                subprioridadDato++;
                prioridadDato++;
                break;
            }
            if(subprioridadDato == 1)
            {
                //temperatura de escape
                encoder('F', 'e', 'E', adquirirAnalogico(TEMP_ESCAPE), 0xAA55);
                UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
                subprioridadDato = 0;
                prioridadDato++;
                break;
            }
            //Aca voy agregando subprioridades de analogicos
            
        }
        case 2: //Coordenadas Tabla 14x16
        {
            
            uint16_t addressTabla;
            
            //rowMapaInyGlobal = (ppaPercentAdqGlobal / 70) - 1;
            //columnMapaInyGlobal = (RPM_Global / 300) - 1;
            
            addressTabla = rowMapaInyGlobal * 0x10;
            addressTabla = addressTabla + columnMapaInyGlobal;
            
            encoder('F', 'T', 'E', addressTabla, 0xAA55);
            UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
            prioridadDato = 0;
            break;
        }
        
        case 9:
        {
            //getTableValue();
            if(!programming)
            {
                prioridadDato = 0;
            }
            
        }
        default:
            break;
    }
}

void getTableValue()
{
    static int cuentas = 0;
    static int r = 0;
    static int c = 0;
    static uint8_t ad8bit = 0;
    //El byte de Status Lo uso para address de 8 bit del id previo y fin de trama 0xAA55 ej:
    //CMD   CH  ID  AD8bit  DH  DL  CSUMH   CSUML   0xAA55
    
    if(r < 14)
    {
        if(c < 16)
        {
            ad8bit = (uint8_t)r * 0x10;
            ad8bit = ad8bit + (uint8_t)c;
            
//            encoder('T', 't', ad8bit, mapaInyeccionGnc[r][c], 0xAA55);
//            UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
            encoder('T', 't', ad8bit, mapaInyeccionGnc[r][c], 0xAA55);
            UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
            c++;
            cuentas++;
        }
        if(c == 16)
        {
            c = 0;
            r++;
        }
    }
    if(r == 14)
    {
        r = 0;
        c = 0;
    }
    
    if(cuentas == 223)
    {
        cuentas = 0;
        
    }
//    cuentas++;
}

void setToTableValues()
{
    static uint16_t cuentas = 0;
    static uint8_t r = 0;
    static uint8_t c = 0;
    static uint8_t ad8bit = 0;
    //El byte de Status Lo uso para address de 8 bit del id previo y fin de trama 0xAA55 ej:
    //CMD   CH  ID  AD8bit  DH  DL  CSUMH   CSUML   0xAA55
    
    if(r < 14)
    {
        if(c < 16)
        {
            ad8bit = r * 0x10;//(uint8_t)r * 0x10;
            ad8bit = ad8bit + c;//ad8bit + (uint8_t)c;
            
            
            encoder('K', 'T', ad8bit, mapaInyeccionGnc[r][c], 0xAA55);
            UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
            encoder('K', 'T', ad8bit, mapaInyeccionGnc[r][c], 0xAA55);
            UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
            c++;
            cuentas++;
        }
        if(c == 16)
        {
            c = 0;
            r++;
        }
    }
    if(r == 14)
    {
        r = 0;
        c = 0;
    }
    
    if(cuentas == (223)*5)  //*5 para hacer este proceso 5 veces y que cargue todos los valores
    {
        cuentas = 0;
        uploading = false;
    }
//    cuentas++;
}

bool UART5_Write_Mio(void* buffer, const size_t size)
{
    bool status = false;
    uint8_t* lBuffer = (uint8_t*)buffer;
    size_t processedSize = 0;
    
    if(lBuffer != NULL)
    {
        while(size > processedSize)
        {
            while(U5STA & _U5STA_UTXBF_MASK);
            
            U5TXREG = *lBuffer++;
            processedSize++;
        }
        
        status = true;
    }
    return status;
}

void UART_Write_Byte(int uart, int byte)    //OK CONTROLADO ARMAR TIPO UART
{
    switch (uart)
    {
        case 4:
        {
            while(U4STA & _U4STA_UTXBF_MASK);
            U4TXREG = byte;
        }
        break;
        
        case 5:
        {
            while(U5STA & _U5STA_UTXBF_MASK);
            U5TXREG = byte;
        }
        break;
        
        default:
            break;
    }
}

void APP_WriteCallback(uintptr_t context)
{
    writeStatus = true;
}

void APP_ReadCallback(uintptr_t context)
{
    if(UART5_ErrorGet() != UART_ERROR_NONE)
    {
        errorStatus = true;
    }
    else
    {
        readStatus = true;
    }
}

void UART5_callbacks(void)
{
    UART5_WriteCallbackRegister(APP_WriteCallback, 0);
    UART5_ReadCallbackRegister(APP_ReadCallback, 0);
    
    UART5_Write(&messageInicio, sizeof(messageInicio));
}

void UART5_Task(void)
{
    if(errorStatus == true)
    {
        errorStatus = false;
        UART5_Write(&messageError, sizeof(messageError));
    }
    else if(readStatus == true)
    {
        readStatus = false;
        memcpy(transmitBuffer, receiveBuffer,sizeof(receiveBuffer));
        
        decoder();
        
//        UART5_Write(&transmitBuffer, sizeof(transmitBuffer));
//        UART5_Write(&receiveBuffer, sizeof(receiveBuffer));
    }
    else if(writeStatus == true)
    {
        writeStatus = false;
        
        UART5_Read(&receiveBuffer, sizeof(receiveBuffer));      //OJO ACA CREO QUE VA UART5_Write()) ó NO VA EL else if
    }
}

void SPI3_callbacks(void)
{
    SPI3_CallbackRegister(SPIEventHandler, (uintptr_t) 0);
}

void receivePrueba()
{
    UART5_Read(&receiveBuffer, sizeof(receiveBuffer));
    decoder();
}

void SPIEventHandler(uintptr_t context)
{
    //Aca hay que desactivar Chip select Logica negativa
    SPI3_CS_Set();
    isTransferDone = true;
}

/* *****************************************************************************
 End of File
 */
