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


#include <stdint.h>
#include "config/32mxSom/peripheral/gpio/plib_gpio.h"
#include "config/32mxSom/peripheral/adc/plib_adc.h"
//#include "temporalidades.h"
#include "adquisicion.h"
#include "comunicacion.h"

#include "globales.h"
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
//Globales
//int rpmGlobal;
//int ckpAngleAdjustGlobal;
//int deltaCkpBufferGlobal[59];
//bool dienteReferenciaGlobal = false;




ANALOGICO analogico;
static unsigned int ckpPulsePeriod5us;
static int  ckpRelativeAngleTimeCounter_us; 
static int ckpAdj = 0;

static unsigned int  rpm = 0;


static unsigned int cmpPulsePeriod5us;
static unsigned int ckpRevolutionPeriod5us;
static unsigned int cmpRevolutionPeriod5us;
static bool resultadoListo;
static uint16_t adc_count;

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

bool estadoConmutador()
{
    //return true;
    return ADQ_LLAVE_Get();
}

unsigned int pulsoInyeccion(void)
{
    unsigned int value = 0;
    return value;
}

//El caudalimetro va por interrupcion (medir ancho de pulso)
//pero hay que activar y desactivar la interrupcion en temporalidades::ticks()
unsigned int caudalimetro(void)
{
    unsigned int value = 0;
    return value;
}

void ADC_ResultHandler(uintptr_t context)
{
    adc_count = ADC_ResultGet(ADC_RESULT_BUFFER_0);
    resultadoListo = true;
}

//Los sensores analogicos deben tener un barrido y ser gestionado por temporalidades::ticks()
unsigned int adquirirAnalogico(SENSOR an)
{
    static int status = 0;
    unsigned int value = 0;
    analogico.canal = an;
    
    ADC_CallbackRegister(ADC_ResultHandler, (uintptr_t)NULL);
    
    switch(analogico.canal)
    {
        case AGUA:
        {
            //Leer analogico
            return value;
            break;
        }
        
        case KNOCK:
        {
            return value;
            break;
        }
        
        case MAP:
        {
            return value;
            break;
        }
        
        case PP1:
        {
            AD1CHSbits.CH0SA = analogico.canal;
            ADC_SamplingStart();
            while(!ADC_ResultIsReady());
            
            value = (ADC_ResultGet(0) * 3300) / 1024;
            value = (value * 10) / 6;   //Viene de un divisor resistivo, este ajuste es para tener el valor real a la entrada de la ecu
                return value;                
            break;
        }
        
        case PP2:
        {
            AD1CHSbits.CH0SA = analogico.canal;
            ADC_SamplingStart();
            while(!ADC_ResultIsReady());
            
            value = (ADC_ResultGet(0) * 3300) / 1024;
            value = (value * 10) / 6;   //Viene de un divisor resistivo, este ajuste es para tener el valor real a la entrada de la ecu
            return value;
            break;
        }
        
        case PRESION_GNC:
        {
            return value;
            break;
        }
        
        case TEMP_ESCAPE:
        {
            AD1CHSbits.CH0SA = analogico.canal;
            ADC_SamplingStart();
            while(!ADC_ResultIsReady());
            
            value = (ADC_ResultGet(0) * 3300) / 1024;
            value = (value);// * 10) / 6;   //Envio solo el valor en mV
            return value;
            break;
        }
        default:
            break;
    }
}



void ckpRelativeAngle(int angle)
{
    int value = 0;
    //PONER FUNCION  EN INTERRUPT
    ckpPulsePeriod5us = 0;
    GEN_INY3_CTRL_Toggle();
    GEN_CKP_Clear();
    
/*
 Generar señal baja de 44us
 */
    return value;
}
void cmpRelativeAngle(int angle)
{
    int value = 0;
    return value;
}

void ckpAdquisicion(void)
{
    //calcula periodo entre llamados
    //cuenta cantidad de periodos
    //Encuentra la referencia del cigüeñal
    //Actualiza variables globales:
    //- rpm
    //- angulo actual
    //Llama al generador de ckp
    static int  tiempoAnteriorCkp = 0;
    static int  deltaAnteriorCkp;
    static int  contaDientes = 0;
    static int  deltaAuxCkp;
    static bool refDetected = false;
    static unsigned int  periodoRevolucion = 0;
    static float periodoPulsoPromedio = 0;
    static float  rpm = 0;
    int deltaCkp;
    int angle = 0;
    

    static int ticksPeriodoDienteAnterior;
    static int anguloPeriodoDienteAnterior;
    
    static int ticksPeriodoDiente;
    
  
//    deltaCkp = ticksCkpActual() - tiempoAnteriorCkp;
    deltaCkp = ckpActual_us() - tiempoAnteriorCkp;
    deltaAuxCkp = (deltaAnteriorCkp) / 2;
    
    if((deltaCkp < deltaAuxCkp) && (tiempoAnteriorCkp != 0))
    {
        refDetected = true;
        //CkpCounterReset();
        contaDientes = 2;
        periodoPulsoPromedio = periodoRevolucion / 58;
        rpm = 1 / deltaCkp;
        periodoRevolucion = ckpActual_us();
        CkpCounterReset();
        RPM_Global = (uint16_t)periodoPulsoPromedio;
    } 
//Prueba ID dientes    
//    if(refDetected && (contaDientes == 10))
//    {
//        GEN_INY4_CTRL_Set();
//    }
//    
//    if(refDetected && (contaDientes == 15))
//    {
//        GEN_INY4_CTRL_Clear();
//    }
    
    if(refDetected && (contaDientes <= 58))
    {        
        periodoRevolucion = periodoRevolucion + deltaCkp;
        contaDientes++;
    }
    //Probablemente esta funcion tenga que ser llamada con una referencia temporal
    generacionPulsoCkp();
    deltaAnteriorCkp = deltaCkp;

    tiempoAnteriorCkp = ckpActual_us();
    
        
    //Esta funcion se ejecuta 5us con retardo.
    //A 1000RPM es un desvio de .03º
    //A 4000RPM es un desvio de .12º
    //No hace falta crear ajuste de compensacion
    
}
void ckpAdquisicionPrevia(void)
{
    //calcula periodo entre llamados
    //cuenta cantidad de periodos
    //Encuentra la referencia del cigüeñal
    //Actualiza variables globales:
    //- rpm
    //- angulo actual
    //Llama al generador de ckp
    static int  tiempoAnteriorCkp = 0;
    static int  deltaAnteriorCkp;
    static int  contaDientes = 0;
    static int  deltaAuxCkp;
    static bool refDetected = false;
    static unsigned int  periodoRevolucion = 0;
    static unsigned int periodoPulsoPromedio = 0;
    
    int deltaCkp;
    
    static int deltaCkpBuffer[59];
    int i;
    static bool bufferInitialized = false;
    if(bufferInitialized == false)
    {
        for(i=0 ; i<59 ; i++)
            {
                deltaCkpBuffer[i] = 0;
                deltaCkpBufferGlobal[i] = 0;
            }
        bufferInitialized = true;
    }
    
    
    int angle = 0;
    static int ticksPeriodoDienteAnterior;
    static int anguloPeriodoDienteAnterior;
    
    static int ticksPeriodoDiente;

    deltaCkp = ckpActual_us() - tiempoAnteriorCkp;
    deltaAuxCkp = (deltaAnteriorCkp) * 2;
    
    if((deltaCkp > deltaAuxCkp) && (tiempoAnteriorCkp != 0))
    {
        
        refDetected = true;
        vueltaCompleta_Global = false;
        
        contaDientes = 0;
        deltaCkpBuffer[0] = deltaCkp;
        deltaCkpBufferGlobal[0] = deltaCkp;
        
        rpm = 1000000 / deltaAnteriorCkp;
        rpmGlobal = 1000000 / deltaAnteriorCkp;
        periodoRevolucion = ckpActual_us();
        periodoPulsoPromedio = periodoRevolucion / 60;
        
        ckpRelativeAngleTimeCounter_us = periodoRevolucion / 360;
        ticksPorGrado = periodoRevolucion / (360 * 5);
        CkpCounterReset();        
    } 
    
    if(refDetected && (contaDientes <= 58))
    {        
        deltaCkpBuffer[contaDientes] = deltaCkp;
        deltaCkpBufferGlobal[contaDientes] = deltaCkp;
        contaDientes++;
    }
    
    if(contaDientes == 28)  //Punto medio donde deberia estar el CMP
    {
        if(!ADQ_CMP_Get())
        {
            vueltaConSincroCmp = true;
        }
        else
        {
            vueltaConSincroCmp = false;
        }
    }
    
    if(contaDientes == 58)
    {
        vueltaCompleta_Global = true;
        
    }
//    if(refDetected && (contaDientes == 56)) //30º antes del primer pulso
//    {
//        dienteReferenciaGlobal = true;
//        
//        //ACA EVALUO SI HAY QUE AVANZAR O ATRASAR
//        
//        ckpAdj = ((ckpRelativeAngleTimeCounter_us) / 5) * angle;
//    }

    //Corregir porque se puede llegar a cambiar en cualquier diente
    //y necesito que sea despues del diente 58
//    if(ckpAngleAdjust_Global == 0)
//    {
//        ckpCorreccion(ckpAngleAdjust_Global);
//    }

    ckpCorreccion(ckpAngleAdjust_Global);
    ticksCkpAjusteReset();
    
    deltaAnteriorCkp = deltaCkp;
    tiempoAnteriorCkp = ckpActual_us();
    
    
    
}

void ckpAdquisicionVueltaPrevia(void)
{
    static int  ticksAnteriorCkp = 0;
    static int  deltaTicksAnteriorCkp;
    static int  contaDientes = 0;
    static int  deltaTicksAuxCkp;
    static bool refDetected = false;
    static unsigned int periodoRevolucion = 0;
    
    static unsigned int  periodoRevolucionTicks = 0;
    static unsigned int periodoPulsoPromedio = 0;
    
    int deltaTicksCkp;
    int i;
    static bool bufferInitialized = false;
    static bool controlPulsoBuffer = false;
    
    if(bufferInitialized == false)
    {
        for(i=0 ; i<58 ; i++)
            {
                deltaTicksCkpBufferGlobal[i] = 0;
            }
        bufferInitialized = true;
    }
    
    int angle = 0;
    static int ticksPeriodoDienteAnterior;
    static int anguloPeriodoDienteAnterior;
    
    static int ticksPeriodoDiente;

    deltaTicksCkp = ticksCkpActual() - ticksAnteriorCkp;
    deltaTicksAuxCkp = (deltaTicksAnteriorCkp) * 2;
    
    if((deltaTicksCkp > deltaTicksAuxCkp) && (ticksAnteriorCkp != 0))
    {
        
        refDetected = true;
        //vueltaCompleta_Global = false;
//        vueltaCompletaSeguraGlobal = false;
        dienteReferenciaGlobal = true;
        
        contaDientes = 0;       
        dienteActualGlobal = contaDientes;
        
        //deltaTicksCkpBufferGlobal[0] = deltaTicksCkp;
        
//        rpmGlobal = 5000000 / deltaTicksAnteriorCkp;
        //periodoRevolucionTicks = ticksCkpActual();
        periodoRevolucionTicksGlobal = ticksCkpActual();
        rpmGlobal = (60000000/5) / periodoRevolucionTicksGlobal; //bien calculado
        RPM_Global = (uint16_t)rpmGlobal;
        
        //Filtro Calculo RPM => Alguna captura se va de rango
        if(RPM_Global > (RPM_AnteriorGlobal + 500))
        {
            RPM_Global = RPM_AnteriorGlobal;
        }
        RPM_AnteriorGlobal = RPM_Global;
        //Filtro Calculo RPM => Alguna captura se va de rango
        
        periodoRevolucion = ticksCkpActual() * 5;
        periodoPulsoPromedio = periodoRevolucion / 60;
        
        
        ticksPorGrado = periodoRevolucionTicksGlobal / 360;
        CkpCounterReset();
    } 
    
    if(refDetected && (contaDientes <= 58))
    {    
        deltaTicksCkpBufferGlobal[contaDientes] = deltaTicksCkp;
        contaDientes++;
        dienteActualGlobal = contaDientes;
    }
    
    if(contaDientes == 28)  //Punto medio donde deberia estar el CMP
    {
        if(!ADQ_CMP_Get())
        {
            vueltaConSincroCmp = true;
        }
        else
        {
            vueltaConSincroCmp = false;
        }
        
    } 
    
//Unicamente activo cuando este la llave en posicion GNC
//Ahora esta andando siempre por las pruebas    
    if(contaDientes == 28 && vueltaConSincroCmp == true && timmerInyectoresActivo == false && inyector1EnabledGlobal == true)
    {
        inyector1TiempoGlobal = aproximacion3D();
        if(inyector1TiempoGlobal < saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY1_CTRL_Set();
            inyector1ActivoGlobal = true;
            TMR5_PeriodSet((inyector1TiempoGlobal * 5) - 1);
            TMR5_Start();
        }
        if(inyector1TiempoGlobal >= saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY1_CTRL_Set();
            inyector1ActivoGlobal = true;
            TMR5_PeriodSet((saturacion_usGlobal * 5) - 1);
            TMR5_Start();
        }
//        timmerInyectoresActivo = true;
//        GEN_INY1_CTRL_Set();
//        inyector1ActivoGlobal = true;
//        TMR5_PeriodSet((saturacion_usGlobal * 10) - 1);
//        TMR5_Start();
    }
    if(contaDientes == 28 && vueltaConSincroCmp == false && timmerInyectoresActivo == false && inyector4EnabledGlobal == true)
    {
        inyector4TiempoGlobal = aproximacion3D();
        if(inyector4TiempoGlobal < saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY4_CTRL_Set();
            inyector4ActivoGlobal = true;
            TMR5_PeriodSet((inyector4TiempoGlobal * 5) - 1);
            TMR5_Start();
        }
        if(inyector4TiempoGlobal >= saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY4_CTRL_Set();
            inyector4ActivoGlobal = true;
            TMR5_PeriodSet((saturacion_usGlobal * 5) - 1);
            TMR5_Start();
        }
//        timmerInyectoresActivo = true;
//        GEN_INY4_CTRL_Set();
//        inyector4ActivoGlobal = true;
//        TMR5_PeriodSet((saturacion_usGlobal * 10) - 1);
//        TMR5_Start();
    }
    if(contaDientes == 58 && vueltaConSincroCmp == true && timmerInyectoresActivo == false && inyector3EnabledGlobal == true)
    {
        inyector3TiempoGlobal = aproximacion3D();
        if(inyector3TiempoGlobal < saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY3_CTRL_Set();
            inyector3ActivoGlobal = true;
            TMR5_PeriodSet((inyector3TiempoGlobal * 5) - 1);
            TMR5_Start();
        }
        if(inyector3TiempoGlobal >= saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY3_CTRL_Set();
            inyector3ActivoGlobal = true;
            TMR5_PeriodSet((saturacion_usGlobal * 5) - 1);
            TMR5_Start();
        }
//        timmerInyectoresActivo = true;
//        GEN_INY3_CTRL_Set();
//        inyector3ActivoGlobal = true;
//        TMR5_PeriodSet((saturacion_usGlobal * 10) - 1);
//        TMR5_Start();
    }
    if(contaDientes == 58 && vueltaConSincroCmp == false && timmerInyectoresActivo == false && inyector2EnabledGlobal == true)
    {
        inyector2TiempoGlobal = aproximacion3D();
        if(inyector2TiempoGlobal < saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY2_CTRL_Set();
            inyector2ActivoGlobal = true;
            TMR5_PeriodSet((inyector2TiempoGlobal * 5) - 1);
            TMR5_Start();
        }
        if(inyector2TiempoGlobal >= saturacion_usGlobal)
        {
            timmerInyectoresActivo = true;
            GEN_INY2_CTRL_Set();
            inyector2ActivoGlobal = true;
            TMR5_PeriodSet((saturacion_usGlobal * 5) - 1);
            TMR5_Start();
        }
//        timmerInyectoresActivo = true;
//        GEN_INY2_CTRL_Set();
//        inyector2ActivoGlobal = true;
//        TMR5_PeriodSet((saturacion_usGlobal * 10) - 1);
//        TMR5_Start();
    }
    
    
//ACA CONMUTO PARA PRUEBAS
//    ckpCorreccion(ckpAngleAdjust_Global);
//    if(contaDientes == 58)
//    {
//        dienteActualGlobal = contaDientes;
//        vueltaCompleta_Global = true;      
//    }
    
 //Agregado anoche   
    if(contaDientes == 56)
    {
        ticksCkpAjusteReset();
    }
//Agregado anoche
    
    if(contaDientes == 58)
    {
        dienteActualGlobal = contaDientes;
        vueltaCompleta_Global = true;
        
        if(primerasVueltasGlobal < VUELTAS_ESTABLES)    //Estabilizacion rpm
        {
            primerasVueltasGlobal++;
        }
        
    }   
    
    if(!vueltaCompleta_Global || primerasVueltasGlobal < VUELTAS_ESTABLES)
    {
        dienteGeneradoGlobal = dienteActualGlobal;
        ckpAndCmpGeneracionPrimerVuelta();
    }
    
    
    if(vueltaCompleta_Global && primerasVueltasGlobal >= VUELTAS_ESTABLES)// && ckpAngleAdjust_Global == GRADO_INICIAL)  
    {
        //Sin cambio Situacion Diesel
        iniciarCicloCompleto = false;
        dienteGeneradoGlobal = dienteActualGlobal;
        cmpGeneradoTriggerDiente();        
        generacionPulsoCkp();   
        if(dienteGeneradoGlobal == 58 && ckpAngleAdjust_Global != GRADO_INICIAL)
        {
            vueltaCompletaSeguraGlobal = true;
        }
    }
    
    //cambiar dienteActualGlobal por dienteGeneradoGlobal
    //sacar ticksCkpAjusteReset()
    //Probablemente no ande con avance mayor al diente 58
    //if(dienteGeneradoGlobal == 58 && ckpAngleAdjust_Global != GRADO_INICIAL)
    //if(dienteActualGlobal == 58 && ckpAngleAdjust_Global != GRADO_INICIAL)
    if(vueltaCompletaSeguraGlobal && ckpAngleAdjust_Global != GRADO_INICIAL)
    {
        //ticksCkpAjusteReset();
        vueltaCompletaSeguraGlobal = false;
        dienteGeneradoGlobal = 0;
        iniciarCicloCompleto = true;
    }
    
       
    //ACTUALIZACION DE DELTAS
    deltaTicksAnteriorCkp = deltaTicksCkp;
    ticksAnteriorCkp = ticksCkpActual();
}

void cmpAdquisicion(void)
{
    int angle = 0;
    
    if(ADQ_CMP_Get())   
    {
        CmpCounterReset();
    }
    
    //cmpCorreccion(angle);
    
    cmpGeneracion(angle);
}
/* *****************************************************************************
 End of File
 */
