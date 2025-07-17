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

#include "generacion.h"
#include "temporalidades.h"
#include "adquisicion.h"
#include "comunicacion.h"
#include "mapas.h"

#include "config/32mxSom/peripheral/gpio/plib_gpio.h"
#include "config/32mxSom/peripheral/tmr/plib_tmr3.h"

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

//GENERA PULSO DE CKP
void generacionPulsoCkp(void)   //OK CONTROLADO
{
    TMR3 = 0x00;
    TMR3_Start();
    delayPulsoCkp();
}

//ESTA FUNCION PUEDE SERVIR COMO RESPALDO SIN CORRECCION
//DEJANDO COMENTADO sincroDetectado = true
//DE ESA FORMA FUNCIONA SOLAMENTE LA INTERRUPCION DEL CMP
//MODIF 07/10/22 12:39
void cmpGeneracion(int angle)   //OK CONTROLADO
{
    if(!sincroDetectado)
    {
            //Aca activamos el pulso de acuerdo a la cuenta generada en ADQUISICION
        if(ADQ_CMP_Get())
        {
            GEN_CMP_Set();
            INTCONbits.INT2EP = false;
        }
        if(!ADQ_CMP_Get())
        {
            GEN_CMP_Clear();
            INTCONbits.INT2EP = true;
            //sincroDetectado = true;
            sincroDetectado = false;
        }
    }
    
}

void ckpAndCmpGeneracionPrimerVuelta(void)  //OK CONTROLADO
{
    cmpGeneradoTriggerDiente();
    generacionPulsoCkp();
}

//ESTOY ACA PENSAR BIEN
void ckpCorreccion(int angle)   
{
    
    static int i = 0;
    unsigned int ticksAux;
    static unsigned int ticksDesfase;
    ticksAux = ticksCkpAjuste();
    
    ticksDesfase = (angle * ticksPorGrado) + deltaTicksCkpBufferGlobal[0];
    if(angle == 0)  //OK CONTROLADO
    {
        //Sin cambio Situacion Diesel
        dienteGeneradoGlobal = dienteActualGlobal;
        cmpGeneradoTriggerDiente();        
        //ticksCkpAjusteReset();
        TMR3 = 0x00;
        TMR3_Start();
        delayPulsoCkp();
        iniciarCicloCompleto = false;
    }
    
    if(angle > 0)//if(0 < angle && angle < 6)   //Avance
    {
        //convertir angle en ticks de anticipo
        //ticksCkpAjusteReset en diente 58
//        dienteGeneradoGlobal++;

//        TMR3 = 0x00;
//        TMR3_Start();
//        delayPulsoCkp();
//        if(dienteGeneradoGlobal == 58)
//        {
//            dienteGeneradoGlobal = 0;
//        }
        
         
//        if(ticksAux >= ticksDesfase)
//        {
//            iniciarCicloCompleto = true;
//        }
        
    }

    
    if(angle < 0)   //Atraso
    {
        //convertir angle en ticks de retardo
        
        ticksCkpAjusteReset();
        TMR3 = 0x00;
        TMR3_Start();
        delayPulsoCkp();
        
        
        
    }
}

void cmpCorreccion(int angle)
{
    if(angle == 0)  //Sin cambio Situacion Diesel
    {
        cmpGeneracion(0);
    }
    //Cualquier otra situacion
    //set pulso en diente 23 y clear pulso en diente 33 de la vuelta correspondiente
    
    if(angle > 0)   //Avance
    {
        //ciclocompleto(angle);
    }
    if(angle < 0)   //Atraso
    {
        
    }
    
}

void cmpGeneradoTriggerDiente(void) //CONTROLADO OK
{
    if(sincroDetectado && dienteGeneradoGlobal == 23 && vueltaConSincroCmp)//modifique 27/09 ori 23
            {
                GEN_CMP_Set();
            }
    if(sincroDetectado && dienteGeneradoGlobal == 33 && !vueltaConSincroCmp)//modifique 27/09 ori 33
        {
            GEN_CMP_Clear();
        }
}


void ciclocompleto(int angle)   //En principio no uso angle
{
    static unsigned int contadorAux = 0;
    unsigned int ticksDesfase;
    ticksDesfase = (angle * ticksPorGrado);
    
    if(ticksCkpAjuste() == (deltaTicksCkpBufferGlobal[dienteGeneradoGlobal]*2))// * 2)//ver porque es x2
    {
        ticksCkpAjusteReset();
        //contadorAux = ticksCkpAjuste();
        generacionPulsoCkp();
        dienteGeneradoGlobal++;
        cmpGeneradoTriggerDiente();
        if(dienteGeneradoGlobal == 58)
        {
            dienteGeneradoGlobal = 0;
        }
        
    }
//    if(dienteActualGlobal == 0)
//    {
//        TMR3 = 0x00;
//        TMR3_Start();
//        delayPulsoCkp();
//        dienteGeneradoGlobal++;
//    }
//    
//    if((dienteGeneradoGlobal > 0 && dienteGeneradoGlobal <= 58) && (ticksCkpCounter() == deltaTicksCkpBufferGlobal[dienteGeneradoGlobal]))
//    {
//        
//            CkpCounterReset();
//            TMR3 = 0x00;
//            TMR3_Start();
//            delayPulsoCkp();
//            dienteGeneradoGlobal++;
//        
//        if(dienteGeneradoGlobal == 58)
//        {
//            dienteGeneradoGlobal = 0;
//            iniciarCicloCompleto = false;
//        }
//    }
}

//Probar mañana
//ajustar notas en adquisicion
void generarCicloCompleto(int angle)
{
    static int stage = 0;
    static int contadorAux = 0;
    unsigned int retardoInicial;
    unsigned int ticksDesfase;
    
    ticksDesfase = (angle * ticksPorGrado);
    retardoInicial = deltaTicksCkpBufferGlobal[56] + 
                     deltaTicksCkpBufferGlobal[57] +
                     deltaTicksCkpBufferGlobal[0] +
                     ticksDesfase;
                     
    
    switch(stage)
    {
        case 0:
        {
            if(ticksCkpAjuste() == retardoInicial)
            {
                contadorAux = ticksCkpAjuste();
                generacionPulsoCkp();
                dienteGeneradoGlobal++;
                stage++;
            }
            break;
        }
        case 1:
        {
            if((ticksCkpAjuste() == (contadorAux + deltaTicksCkpBufferGlobal[dienteGeneradoGlobal])) 
               && (dienteGeneradoGlobal < 58))
            {
                contadorAux = ticksCkpAjuste();
                generacionPulsoCkp();
                dienteGeneradoGlobal++;
                cmpGeneradoTriggerDiente();
            }
            if(dienteGeneradoGlobal == 57)
            {
                stage++;
            }
            break;
        }
        case 2:
        {
            if((ticksCkpAjuste() == (contadorAux + deltaTicksCkpBufferGlobal[dienteGeneradoGlobal])) 
               && (dienteGeneradoGlobal == 58))
            {
                contadorAux = ticksCkpAjuste();
                generacionPulsoCkp();
                dienteGeneradoGlobal = 0;
                stage = 0;
            }
        }
        default:
            break;
    }
}

//void ciclocompleto(int angle)
//{
//    static bool controlDesfase = false;
//    static unsigned int ticksAux;
//    unsigned int ticksDesfase;
//    ticksAux = ticksCkpAjuste();
//    
//    ticksDesfase = (angle * ticksPorGrado) + (deltaTicksCkpBufferGlobal[dienteGeneradoGlobal]);
//    //ticksDesfase = (angle * ticksPorGrado) + (2 * 50);
//    if(ticksAux == ticksDesfase)
//    {
//        controlDesfase = true;
//    }
//    if(controlDesfase && (ticksAux >= (deltaTicksCkpBufferGlobal[dienteGeneradoGlobal])))
//    {
//        cmpGeneradoTriggerDiente();        
//        ticksCkpAjusteReset();
//        TMR3 = 0x00;
//        TMR3_Start();
//        delayPulsoCkp();
//        dienteGeneradoGlobal++;
//        if(dienteGeneradoGlobal == 58)
//        {
//            dienteGeneradoGlobal = 0;
//            controlDesfase = false;
//        }
//    }
//}

//ESTA FUNCION PUEDE SERVIR COMO RESPALDO SIN CORRECCION
void write_PPA(void)    //OK CONTROLADO
{
    static int PPA = 1;
    static uint8_t vdd = 5;
    static uint8_t buffer1[3];
    static uint8_t buffer2[3];
    unsigned int dn1;
    unsigned int dn2;
    unsigned int volt_mV;
    uint8_t dn1High;
    uint8_t dn1Low;
    uint8_t dn2High;
    uint8_t dn2Low;

    uint8_t address;
    //DAC de 12 bits (4096 cuentas)
    //Presicion del paso 1000/819 = 1.22mV
    switch(PPA)
    {
        case 1:
        {
            volt_mV = adquirirAnalogico(PP1);
            ppaPercentAdqGlobal = volt_mV / 5;
            dn1Low = volt_mV;
            dn1 = (volt_mV * 819)/1000;
            
            dn1High = (dn1)/0x10;  //Con esto desplazo 4 bits a la derecha
            dn1Low = (dn1 - dn1High * 0x10) * 0x10;
            address = 0x61;     //1100 0010 Device Address con A0 = 1
            buffer1[0] = 0x40;   //0100 0000 Internal Device Address
            buffer1[1] = dn1High;   //dnHigh;
            buffer1[2] = dn1Low;   //dnLow;
            GEN_A0_PP1_Set();
            GEN_A0_PP2_Clear();
            
            if(!I2C2_Write(address, &buffer1[0], 3))
            {
                //Error Handler
            }

            if(I2C2STATbits.P == true)
            {
                PPA = 2;
            }
            
        }
        
        case 2:
        {
            volt_mV = adquirirAnalogico(PP2);
            dn2Low = volt_mV;
            dn2 = (volt_mV * 819)/1000;
            
            dn2High = (dn2)/0x10;  //Con esto desplazo 4 bits a la derecha
            dn2Low = (dn2 - dn2High * 0x10) * 0x10;
            address = 0x60;     //1100 0010 Device Address con A0 = 1
            buffer2[0] = 0x40;   //0100 0000 Internal Device Address
            buffer2[1] = dn2High;   //dnHigh;
            buffer2[2] = dn2Low;   //dnLow;
            GEN_A0_PP1_Set();
            GEN_A0_PP2_Clear();
            
            if(!I2C2_Write(address, &buffer2[0], 3))
            {
                //Error Handler
            }

            if(I2C2STATbits.P == true)
            {
                PPA = 1;
            }
        }
        
        default:
            break;
    }
}

void PPA_SetPercent(uint16_t percent)   //OK CONTROLADO
{
    static int PPA = 1;
    static uint8_t vdd = 5;
    static uint8_t buffer1[3];
    static uint8_t buffer2[3];
    
    
    unsigned int dn1;
    unsigned int dn2;
    unsigned int volt_mV;
    unsigned int porcentaje;
    porcentaje = percent;
    
    uint8_t dn1High;
    uint8_t dn1Low;
    uint8_t dn2High;
    uint8_t dn2Low;

    uint8_t address;
    //Presicion del paso 1000/819 = 1.22mV
    switch(PPA)
    {
        //porcentaje llega multiplicado por 10 para tener precision de 1 decima
        //por eso divido por 1000 en vez de 100 en 
        //volt_mV = (porcentaje * 5000) / 1000; case 1
        //volt_mV = (porcentaje * 2500) / 1000; case 2
        case 1:
        {
            volt_mV = adquirirAnalogico(PP1);   //AGREGUE Por posible retardo en la programacion del i2c
            ppaPercentAdqGlobal = volt_mV / 5;
            
            volt_mV = (porcentaje * 5000) / 1000;//5000 mV recorrido completo PP1
            
            dn1Low = volt_mV;
            dn1 = (volt_mV * 819)/1000;
            
            dn1High = (dn1)/0x10;  //Con esto desplazo 4 bits a la derecha
            dn1Low = (dn1 - dn1High * 0x10) * 0x10;
            address = 0x61;     //1100 0010 Device Address con A0 = 1
            buffer1[0] = 0x40;   //0100 0000 Internal Device Address
            buffer1[1] = dn1High;   //dnHigh;
            buffer1[2] = dn1Low;   //dnLow;
            GEN_A0_PP1_Set();
            GEN_A0_PP2_Clear();
            
            if(!I2C2_Write(address, &buffer1[0], 3))
            {
                //Error Handler
            }

            if(I2C2STATbits.P == true)
            {
                PPA = 2;
            }
            
        }
        
        case 2:
        {
            volt_mV = adquirirAnalogico(PP1);   //AGREGUE Por posible retardo en la programacion del i2c
            ppaPercentAdqGlobal = volt_mV / 5;  //Actualiza ppaPercentGlobal en cada case
            
            volt_mV = (porcentaje * 2500) / 1000;//2500 mV mitad de recorrido PP2
            dn2Low = volt_mV;
            dn2 = (volt_mV * 819)/1000;
            
            dn2High = (dn2)/0x10;  //Con esto desplazo 4 bits a la derecha
            dn2Low = (dn2 - dn2High * 0x10) * 0x10;
            address = 0x60;     //1100 0010 Device Address con A0 = 1
            buffer2[0] = 0x40;   //0100 0000 Internal Device Address
            buffer2[1] = dn2High;   //dnHigh;
            buffer2[2] = dn2Low;   //dnLow;
            GEN_A0_PP1_Set();
            GEN_A0_PP2_Clear();
            
            if(!I2C2_Write(address, &buffer2[0], 3))
            {
                //Error Handler
            }

            if(I2C2STATbits.P == true)
            {
                PPA = 1;
            }
        }
        
        default:
            break;
    }
}

void writePP1(unsigned int volt_mV) //OK CONTROLADO
{
    static uint8_t vdd = 5;
    static uint8_t buffer[3];
    uint8_t aux;
    unsigned int dn;
    unsigned int dn1;
    unsigned int dn2;
    
    uint8_t dnHigh;
    uint8_t dnLow;
    aux = volt_mV;
    dnLow = volt_mV;
    uint8_t address;
    //Presicion del paso 1000/819 = 1.22mV
            
    dn = (volt_mV * 819)/1000;
    dn1 = dn;
    dn2 = dn/2;
        
    dnHigh = (dn1)/0x10;  //Con esto desplazo 4 bits a la derecha
    dnLow = (dn1 - dnHigh * 0x10) * 0x10;
    address = 0x61;     //1100 0010 Device Address con A0 = 1
    buffer[0] = 0x40;   //0100 0000 Internal Device Address
    buffer[1] = dnHigh;   //dnHigh;
    buffer[2] = dnLow;   //dnLow;

    GEN_A0_PP1_Set();
    GEN_A0_PP2_Clear();

//            while(I2C2_IsBusy( ));
    if(!I2C2_Write(address, &buffer[0], 3))
    {
        //Error Handler
    }
    //Este I2C2_IsBUsy() No esta andando erpo puedo filtrar por I2C Address
    if(!I2C2_IsBusy())
    {
        //GEN_A0_PP1_Clear();

    }
        
}

void writePP2(unsigned int volt_mV) //OK CONTROLADO
{
    static uint8_t vdd = 5;
    static uint8_t buffer[3];
    uint8_t aux;
    unsigned int dn;
    unsigned int dn1;
    unsigned int dn2;
    
    uint8_t dnHigh;
    uint8_t dnLow;
    aux = volt_mV;
    dnLow = volt_mV;
    uint8_t address;
    //Presicion del paso 1000/819 = 1.22mV
            
    dn = (volt_mV * 819)/1000;
    dn1 = dn;
    dn2 = dn/2;
        
    dnHigh = (dn1)/0x10;  //Con esto desplazo 4 bits a la derecha
    dnLow = (dn1 - dnHigh * 0x10) * 0x10;
    address = 0x60;     //1100 0010 Device Address con A0 = 0
    buffer[0] = 0x40;   //0100 0000 Internal Device Address
    buffer[1] = dnHigh;   //dnHigh;
    buffer[2] = dnLow;   //dnLow;

    GEN_A0_PP1_Set();
    GEN_A0_PP2_Clear();

//            while(I2C2_IsBusy( ));
    if(!I2C2_Write(address, &buffer[0], 3))
    {
        //Error Handler
    }
    //Este I2C2_IsBUsy() No esta andando erpo puedo filtrar por I2C Address
    if(!I2C2_IsBusy())
    {
        //GEN_A0_PP1_Clear();

    }
}

void setInyector(void)
{
    //Pruebas offline Controlar el orden de las divisiones 06/07/2022 22:28
    
    //inyectorGralTiempoGlobal = mapaInyeccionGnc[rowMapaInyGlobal][columnMapaInyGlobal] + aproximacion();
    
//    inyectorGralTiempoGlobal = aproximacion3D();  //aproximacion3D() =  tiempoBase + aproxPedal + aproxRpm
    
    //Paso escalonado YA ESTA PROBADO EN LA CHATA CON ADOLFO
    //inyectorGralTiempoGlobal = mapaInyeccionGnc[rowMapaInyGlobal][columnMapaInyGlobal];
//    inyector1TiempoGlobal = inyectorGralTiempoGlobal;
//    inyector2TiempoGlobal = inyectorGralTiempoGlobal;
//    inyector3TiempoGlobal = inyectorGralTiempoGlobal;
//    inyector4TiempoGlobal = inyectorGralTiempoGlobal;
//    
    if(vueltaConSincroCmp == true && inyector1EnabledGlobal == true && inyector1ActivoGlobal == true)
    {
        setInyector1();
    }
    if(vueltaConSincroCmp == false && inyector4EnabledGlobal == true && inyector4ActivoGlobal == true)
    {
        setInyector4();
    }
    if(vueltaConSincroCmp == true && inyector3EnabledGlobal == true && inyector3ActivoGlobal == true)
    {
        setInyector3();
    }
    if(vueltaConSincroCmp == false && inyector2EnabledGlobal == true && inyector2ActivoGlobal == true)
    {
        setInyector2();
    }
}

void setInyector1()
{
    static int stage = 0;
    static int contador = 0;
    static int pwmTime = 0;
    switch(stage)
    {
        case 0:
        {
            if(inyectorGralTiempoGlobal < saturacion_usGlobal)
            {
                contador = 0;
                stage = 0;
                GEN_INY1_CTRL_Clear();
                TMR5_Stop();
                timmerInyectoresActivo = false;
                inyector1ActivoGlobal = false;
                break;
            }
            pwmTime = (inyectorGralTiempoGlobal - saturacion_usGlobal) / 100;
            GEN_INY1_CTRL_Clear();
            TMR5_Stop();
            TMR5_PeriodSet((dutyNegGlobal * 5) - 1);//(699);
            TMR5_Start();
            if(contador == pwmTime)
            {
                contador = 0;
                stage = 2;
                break;
            }
            stage++;
            break;
        }
        case 1:
        {
            GEN_INY1_CTRL_Set();
            TMR5_Stop();
            TMR5_PeriodSet((dutyPosGlobal * 5) - 1);//(299);
            TMR5_Start();
            contador++;
            stage--;
            break;
        }
        case 2:
        {
            contador = 0;
            stage = 0;
            GEN_INY1_CTRL_Clear();
            TMR5_Stop();
            timmerInyectoresActivo = false;
            inyector1ActivoGlobal = false;
            break;
        }
        default:
            break;
    }
}
void setInyector2()
{
static int stage = 0;
    static int contador = 0;
    static int pwmTime = 0;
    switch(stage)
    {
        case 0:
        {
            if(inyectorGralTiempoGlobal < saturacion_usGlobal)
            {
                contador = 0;
                stage = 0;
                GEN_INY2_CTRL_Clear();
                TMR5_Stop();
                timmerInyectoresActivo = false;
                inyector2ActivoGlobal = false;
                break;
            }
            pwmTime = (inyectorGralTiempoGlobal - saturacion_usGlobal) / 100;
            GEN_INY2_CTRL_Clear();
            TMR5_Stop();
            TMR5_PeriodSet((dutyNegGlobal * 5) - 1);//(699);
            TMR5_Start();
            if(contador == pwmTime)
            {
                contador = 0;
                stage = 2;
                break;
            }
            stage++;
            break;
        }
        case 1:
        {
            GEN_INY2_CTRL_Set();
            TMR5_Stop();
            TMR5_PeriodSet((dutyPosGlobal * 5) - 1);//(299);
            TMR5_Start();
            contador++;
            stage--;
            break;
        }
        case 2:
        {
            contador = 0;
            stage = 0;
            GEN_INY2_CTRL_Clear();
            TMR5_Stop();
            timmerInyectoresActivo = false;
            inyector2ActivoGlobal = false;
            break;
        }
        default:
            break;
    }
}
void setInyector3()
{
static int stage = 0;
    static int contador = 0;
    static int pwmTime = 0;
    switch(stage)
    {
        case 0:
        {
            if(inyectorGralTiempoGlobal < saturacion_usGlobal)
            {
                contador = 0;
                stage = 0;
                GEN_INY3_CTRL_Clear();
                TMR5_Stop();
                timmerInyectoresActivo = false;
                inyector3ActivoGlobal = false;
                break;
            }
            pwmTime = (inyectorGralTiempoGlobal - saturacion_usGlobal) / 100;
            GEN_INY3_CTRL_Clear();
            TMR5_Stop();
            TMR5_PeriodSet((dutyNegGlobal * 5) - 1);//(699);
            TMR5_Start();
            if(contador == pwmTime)
            {
                contador = 0;
                stage = 2;
                break;
            }
            stage++;
            break;
        }
        case 1:
        {
            GEN_INY3_CTRL_Set();
            TMR5_Stop();
            TMR5_PeriodSet((dutyPosGlobal * 5) - 1);//(299);
            TMR5_Start();
            contador++;
            stage--;
            break;
        }
        case 2:
        {
            contador = 0;
            stage = 0;
            GEN_INY3_CTRL_Clear();
            TMR5_Stop();
            timmerInyectoresActivo = false;
            inyector3ActivoGlobal = false;
            break;
        }
        default:
            break;
    }
}
void setInyector4()
{
static int stage = 0;
    static int contador = 0;
    static int pwmTime = 0;
    switch(stage)
    {
        case 0:
        {
            if(inyectorGralTiempoGlobal < saturacion_usGlobal)
            {
                contador = 0;
                stage = 0;
                GEN_INY4_CTRL_Clear();
                TMR5_Stop();
                timmerInyectoresActivo = false;
                inyector4ActivoGlobal = false;
                break;
            }
            pwmTime = (inyectorGralTiempoGlobal - saturacion_usGlobal) / 100;
            GEN_INY4_CTRL_Clear();
            TMR5_Stop();
            TMR5_PeriodSet((dutyNegGlobal * 5) - 1);//(699);
            TMR5_Start();
            if(contador == pwmTime)
            {
                contador = 0;
                stage = 2;
                break;
            }
            stage++;
            break;
        }
        case 1:
        {
            GEN_INY4_CTRL_Set();
            TMR5_Stop();
            TMR5_PeriodSet((dutyPosGlobal * 5) - 1);//(299);
            TMR5_Start();
            contador++;
            stage--;
            break;
        }
        case 2:
        {
            contador = 0;
            stage = 0;
            GEN_INY4_CTRL_Clear();
            TMR5_Stop();
            timmerInyectoresActivo = false;
            inyector4ActivoGlobal = false;
            break;
        }
        default:
            break;
    }
}

//Respaldo ok Controlado Antes del viaje de Adolfo
//void setInyector1()
//{
//    static int stage = 0;
//    static int contador = 0;
//    static int pwmTime = 0;
//    switch(stage)
//    {
//        case 0:
//        {
//            if(inyector1TiempoGlobal < saturacion_usGlobal)
//            {
//                contador = 0;
//                stage = 0;
//                GEN_INY1_CTRL_Clear();
//                TMR5_Stop();
//                timmerInyectoresActivo = false;
//                inyector1ActivoGlobal = false;
//                break;
//            }
//            pwmTime = (inyector1TiempoGlobal - saturacion_usGlobal) / 100;
//            GEN_INY1_CTRL_Clear();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyNegGlobal * 10) - 1);//(699);
//            TMR5_Start();
//            if(contador == pwmTime)
//            {
//                contador = 0;
//                stage = 2;
//                break;
//            }
//            stage++;
//            break;
//        }
//        case 1:
//        {
//            GEN_INY1_CTRL_Set();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyPosGlobal * 10) - 1);//(299);
//            TMR5_Start();
//            contador++;
//            stage--;
//            break;
//        }
//        case 2:
//        {
//            contador = 0;
//            stage = 0;
//            GEN_INY1_CTRL_Clear();
//            TMR5_Stop();
//            timmerInyectoresActivo = false;
//            inyector1ActivoGlobal = false;
//            break;
//        }
//        default:
//            break;
//    }
//}
//void setInyector2()
//{
//static int stage = 0;
//    static int contador = 0;
//    static int pwmTime = 0;
//    switch(stage)
//    {
//        case 0:
//        {
//            if(inyector2TiempoGlobal < saturacion_usGlobal)
//            {
//                contador = 0;
//                stage = 0;
//                GEN_INY2_CTRL_Clear();
//                TMR5_Stop();
//                timmerInyectoresActivo = false;
//                inyector2ActivoGlobal = false;
//                break;
//            }
//            pwmTime = (inyector2TiempoGlobal - saturacion_usGlobal) / 100;
//            GEN_INY2_CTRL_Clear();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyNegGlobal * 10) - 1);//(699);
//            TMR5_Start();
//            if(contador == pwmTime)
//            {
//                contador = 0;
//                stage = 2;
//                break;
//            }
//            stage++;
//            break;
//        }
//        case 1:
//        {
//            GEN_INY2_CTRL_Set();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyPosGlobal * 10) - 1);//(299);
//            TMR5_Start();
//            contador++;
//            stage--;
//            break;
//        }
//        case 2:
//        {
//            contador = 0;
//            stage = 0;
//            GEN_INY2_CTRL_Clear();
//            TMR5_Stop();
//            timmerInyectoresActivo = false;
//            inyector2ActivoGlobal = false;
//            break;
//        }
//        default:
//            break;
//    }
//}
//void setInyector3()
//{
//static int stage = 0;
//    static int contador = 0;
//    static int pwmTime = 0;
//    switch(stage)
//    {
//        case 0:
//        {
//            if(inyector3TiempoGlobal < saturacion_usGlobal)
//            {
//                contador = 0;
//                stage = 0;
//                GEN_INY3_CTRL_Clear();
//                TMR5_Stop();
//                timmerInyectoresActivo = false;
//                inyector3ActivoGlobal = false;
//                break;
//            }
//            pwmTime = (inyector3TiempoGlobal - saturacion_usGlobal) / 100;
//            GEN_INY3_CTRL_Clear();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyNegGlobal * 10) - 1);//(699);
//            TMR5_Start();
//            if(contador == pwmTime)
//            {
//                contador = 0;
//                stage = 2;
//                break;
//            }
//            stage++;
//            break;
//        }
//        case 1:
//        {
//            GEN_INY3_CTRL_Set();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyPosGlobal * 10) - 1);//(299);
//            TMR5_Start();
//            contador++;
//            stage--;
//            break;
//        }
//        case 2:
//        {
//            contador = 0;
//            stage = 0;
//            GEN_INY3_CTRL_Clear();
//            TMR5_Stop();
//            timmerInyectoresActivo = false;
//            inyector3ActivoGlobal = false;
//            break;
//        }
//        default:
//            break;
//    }
//}
//void setInyector4()
//{
//static int stage = 0;
//    static int contador = 0;
//    static int pwmTime = 0;
//    switch(stage)
//    {
//        case 0:
//        {
//            if(inyector4TiempoGlobal < saturacion_usGlobal)
//            {
//                contador = 0;
//                stage = 0;
//                GEN_INY4_CTRL_Clear();
//                TMR5_Stop();
//                timmerInyectoresActivo = false;
//                inyector4ActivoGlobal = false;
//                break;
//            }
//            pwmTime = (inyector4TiempoGlobal - saturacion_usGlobal) / 100;
//            GEN_INY4_CTRL_Clear();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyNegGlobal * 10) - 1);//(699);
//            TMR5_Start();
//            if(contador == pwmTime)
//            {
//                contador = 0;
//                stage = 2;
//                break;
//            }
//            stage++;
//            break;
//        }
//        case 1:
//        {
//            GEN_INY4_CTRL_Set();
//            TMR5_Stop();
//            TMR5_PeriodSet((dutyPosGlobal * 10) - 1);//(299);
//            TMR5_Start();
//            contador++;
//            stage--;
//            break;
//        }
//        case 2:
//        {
//            contador = 0;
//            stage = 0;
//            GEN_INY4_CTRL_Clear();
//            TMR5_Stop();
//            timmerInyectoresActivo = false;
//            inyector4ActivoGlobal = false;
//            break;
//        }
//        default:
//            break;
//    }
//}


int aproximacion()
{
    //SUAVIZADOR DE TIEMPO DE INYECCION POR TABLA
    int value;
    int tiempoBase;
    int tiempoProx;
    int prescisionIny;
    int pasoPedal;
    int pasoPedalDenominador;
    int deltaPPA;
    int ppaBase;
    int ajuste;
    int aux = 1;
    
    prescisionIny = 100;
    value = 0;
    
    ppaBase = (rowMapaInyGlobal + 1) * 70;
    deltaPPA = (ppaPercentAdqGlobal - ppaBase);
    ajuste = deltaPPA * 10;
    
    
    tiempoBase = mapaInyeccionGnc[rowMapaInyGlobal][columnMapaInyGlobal];
    tiempoProx = mapaInyeccionGnc[rowMapaInyGlobal + 1][columnMapaInyGlobal];
    
//    
    pasoPedalDenominador = (tiempoProx - tiempoBase);
    aux = pasoPedalDenominador / prescisionIny;
    pasoPedalDenominador = aux * 200;
    pasoPedal = 7000 / aux;
   
//    //pasoPedal = 70 / ((tiempoProx - tiempoBase) / prescisionIny);   //Aca 70 es el paso del pedal en la tabla
//    
//    ppaBase = (rowMapaInyGlobal + 1) * 70; //Aca 70 es el paso del pedal en la tabla
//    
//    ajuste = ppaPercentAdqGlobal - ppaBase;
//    ajuste = ajuste * prescisionIny;
//    ajuste = ajuste / pasoPedal;
//    ajuste = pasoPedalDenominador;
//    //value = tiempoBase + ajuste;// + ((prescisionIny * (ppaPercentAdqGlobal - ppaBase)) / pasoPedal);
//    value = pasoPedalDenominador;
////    value = value / 100;  //elimino dos ultimos digitos
////    value = value * 100;  //lo hago multiplo de 100 por el paso de tiempo de inyeccion
//
    
    value = ajuste;
    //value = 0;
    
    return value;
}

int aproximacion3D()
{
    int value;
    int valueDecimaMicro;
    int tiempoBase;
    int tiempoProxPedal;
    int tiempoProxRpm;
    int tiempoProxDiag;
    
    int ppaBase;
    int deltaPPA;
    
    int rpmBase;
    int deltaRPM;
    
    int deltaRpmCelda;
    int deltaPedalCelda;
    
    int interpolacionPedal;
    int interpolacionRpm;
    
    int incrementalPedal;
    int incrementalRpm;
    
    int multiplicadorPedal;
    int multiplicadorRpm;
    
    if(mapaActualGlobal == MAPA_SAFE)
    {    
        tiempoBase = mapaInyGncSafe[rowMapaInyGlobal][columnMapaInyGlobal];                           //3600 D2

        tiempoProxPedal = mapaInyGncSafe[rowMapaInyGlobal + 1][columnMapaInyGlobal];                  //4100 D9
        tiempoProxRpm = mapaInyGncSafe[rowMapaInyGlobal][columnMapaInyGlobal + 1];                    //3400 G2
        tiempoProxDiag = mapaInyGncSafe[rowMapaInyGlobal + 1][columnMapaInyGlobal + 1];               //3900 G9
    }
    
    if(mapaActualGlobal == MAPA_TUNING)
    {
        tiempoBase = mapaInyeccionGnc[rowMapaInyGlobal][columnMapaInyGlobal];                           //3600 D2

        tiempoProxPedal = mapaInyeccionGnc[rowMapaInyGlobal + 1][columnMapaInyGlobal];                  //4100 D9
        tiempoProxRpm = mapaInyeccionGnc[rowMapaInyGlobal][columnMapaInyGlobal + 1];                    //3400 G2
        tiempoProxDiag = mapaInyeccionGnc[rowMapaInyGlobal + 1][columnMapaInyGlobal + 1];               //3900 G9
    }
    
    deltaRpmCelda = columnMapaInyGnc[columnMapaInyGlobal + 1] - columnMapaInyGnc[columnMapaInyGlobal];  //300
    deltaPedalCelda = rowMapaInyGnc[rowMapaInyGlobal + 1] - rowMapaInyGnc[rowMapaInyGlobal];            //70

    incrementalPedal = ((tiempoProxPedal - tiempoBase) * 10) / deltaPedalCelda;                         //71
    incrementalRpm = ((tiempoProxRpm - tiempoBase) * 100) / deltaRpmCelda;                              //-66
    
    //ppaBase = (rowMapaInyGlobal + 1) * 70;
    ppaBase = rowMapaInyGnc[rowMapaInyGlobal];                                                          //350
    deltaPPA = (ppaPercentAdqGlobal - ppaBase);                                                             //15
    multiplicadorPedal = deltaPPA / 10;                                                                     //1
    interpolacionPedal = incrementalPedal * multiplicadorPedal;                                                 //71

    
    deltaRPM = (RPM_Global - columnMapaInyGnc[columnMapaInyGlobal]);                                        //210
    multiplicadorRpm = deltaRPM / 100;                                                                      //2
    interpolacionRpm = incrementalRpm * multiplicadorRpm;                                                       //-132
    
    value = tiempoBase + interpolacionPedal + interpolacionRpm; //5400+510+132                                  //-61
    valueDecimaMicro = value / 100;                                                                             //-6
    valueDecimaMicro = valueDecimaMicro * 100;                                                                  //-600
    
    return valueDecimaMicro;
}
/* *****************************************************************************
 End of File
 */
