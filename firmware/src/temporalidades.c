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

#include "temporalidades.h"
#include "app.h"
#include "adquisicion.h"
#include "comunicacion.h"
#include "globales.h"

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
//int ticksCorreccionCkpGlobal;
//int deltaCkpBufferGlobal[59];

//Sacar static
//static type var hace que la variable global sea solo vista por este .c
unsigned int tick5usTimmer4;
unsigned int tick5us;
unsigned int tick10us;
unsigned int varTicks100us;
unsigned int varTicks1ms;
unsigned int varTicks10ms;
unsigned int varTicks100ms;
unsigned int tickActualCkp5us;
unsigned int tickActualCmp5us;
unsigned int varCkpActual_us;
unsigned int varCmpActual_us;
unsigned int valor = 0;

unsigned int varTicksCkpAjuste;



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
//


void ticks(void)
{
    tick5us++;
//    ticksCkpCounter();
//    ticksCmpCounter();
//    ticksCkpAjuste();
    
//    if(primeraVueltaDetectadaGlobal)
//    {
//        ciclocompleto(ckpAngleAdjust_Global);
//    }
    //ciclocompleto(ckpAngleAdjust_Global);
    //ckpAdjust(ckpAngleAdjust_Global);
    
    //ckpCorreccion(ckpAngleAdjust_Global);
    
//    if(inyector1ActivoGlobal == true && inyector1EnabledGlobal == true && timmer5Estado == false)
//    {
//        //setInyector1(4,40);
//        //setInyector();        
//       GEN_INY1_CTRL_Set();
//       timmer5Estado = true;
//       TMR5_PeriodSet(39999);   //TMR5_PeriodSet((saturacion_us * 10) - 1)
//       TMR5_Start();
//    }
    static int stage = 0;
    varTicks5usInyeccion++;
    if((tick5us%20)==0)
    {
        //Funciones no bloqueantes cada 100us
        varTicks100us++;
    }
    if((tick5us%200)==0)
    {
        //Funciones no bloqueantes cada 1ms
        
        
        
        varTicks1msInyeccion++;
        varTicks1ms++;
    }
    if((tick5us%1000)==0)   //Adquisicion mas rapida del pedal Valor original 2000
    {
        //Funciones no bloqueantes cada 5ms
        varTicks5ms++;
        if(uploading)
        {
            setToTableValues();
        }
        
        //Actualiza las coordenadas mas rapido
        rowMapaInyGlobal = (ppaPercentAdqGlobal / 70) - 1;
        if(rowMapaInyGlobal  <= 0) rowMapaInyGlobal = 0;
        columnMapaInyGlobal = (RPM_Global / 300) - 1;
        if(columnMapaInyGlobal  <= 0) columnMapaInyGlobal = 0;
        
        if(!estadoConmutador())
        {
            write_PPA();    //FUNCION DE EMERGENCIA, BRIDGE ADQ-GEN
        }
        if(estadoConmutador())
        {
            //PPA_SetPercent(ppaPercentGlobal);
            switch(stage)
            {
                case 0:
                {
                    if(mapaActualGlobal == MAPA_SAFE)
                    {
                        PPA_SetPercent(mapaPPAGncSafe[rowMapaInyGlobal][columnMapaInyGlobal]);
                    }
                    if(mapaActualGlobal == MAPA_TUNING)
                    {
                        PPA_SetPercent(mapaPosPedalGenGnc[rowMapaInyGlobal][columnMapaInyGlobal]);
                    }
                    
                    if(retencionGas)
                    {
                        retencionGas = false;
                        //stage++;
                    }
                    break;
                }
                case 1:
                {
                    PPA_SetPercent(mapaPosPedalGen1[rowMapaInyGlobal][columnMapaInyGlobal]);
                    if(retencionGas)
                    {
                        retencionGas = false;
                        stage++;
                    }
                    break;
                }
                case 2:
                {
                    PPA_SetPercent(mapaPosPedalGen2[rowMapaInyGlobal][columnMapaInyGlobal]);
                    if(retencionGas)
                    {
                        retencionGas = false;
                        stage++;
                    }
                    break;
                }
                case 3:
                {
                    PPA_SetPercent(mapaPosPedalGen3[rowMapaInyGlobal][columnMapaInyGlobal]);
                    if(retencionGas)
                    {
                        retencionGas = false;
                        stage++;
                    }
                    break;
                }
                case 4:
                {
                    PPA_SetPercent(mapaPosPedalGen4[rowMapaInyGlobal][columnMapaInyGlobal]);
                    if(retencionGas)
                    {
                        retencionGas = false;
                        stage = 0;
                    }
                    break;
                }
                case 5:
                {
                    PPA_SetPercent(mapaPosPedalGen5[rowMapaInyGlobal][columnMapaInyGlobal]);
                    if(retencionGas)
                    {
                        retencionGas = false;
                        stage = 0;
                    }
                    break;
                }
                
                default:
                    //PPA_SetPercent(mapaPosPedalGenGnc[rowMapaInyGlobal][columnMapaInyGlobal]);
                    break;
            }
            
            
        }
        
        
        varTicks10ms++;
    }
    
    if((tick5us%10000)==0)
    {
        //Funciones no bloqueantes cada 50ms
//        if(programming)
//        {
//            getTableValue();
//        }
//        if(uploading)
//        {
//            setToTableValues();
//        }
    }
    
    if((tick5us%20000)==0)
    {
        //Funciones no bloqueantes cada 100ms
        
//        valor = rpmGlobal;
        //inyector4ActivoGlobal = true;
        //UART5_Write(&rpmGlobal, sizeof(rpmGlobal));

//        if(programming)
//        {
//            getTableValue();
//        }
        if(programming)
        {
            //getTableValue();
            //programming = false;
        }
        if(!programming)
        {
            dataSender();
        }
        if(!uploading)
        {
            dataSender();
        }
        
        varTicks100ms++;
    }
}

void delayPulsoCkp(void)    //OK CONTROLADO
{
    static int stage = 0;
    
    switch(stage)
    {
        case 0:
        {
            GEN_CKP_Set();
            stage++;
        }
        break;
        
        case 1:
        {
            GEN_CKP_Clear();
            TMR3_Stop();
            
            stage--;
        }
        break;
        
        default:
            break;
    }
}
//Funciones Ticks CKP
unsigned int ticksCkpCounter(void)
{
        tickActualCkp5us++;
        return tickActualCkp5us;
}

unsigned int ticksCkpActual()
{
    return tickActualCkp5us;
}

unsigned int ticksCkpAjuste(void)
{
    varTicksCkpAjuste++;
    return varTicksCkpAjuste;
}

void ticksCkpAjusteReset(void)
{
    varTicksCkpAjuste = 0;
}
void CkpCounterReset()
{
    tickActualCkp5us = 0;
    varCkpActual_us = 0;
}

unsigned int ckpActual_us()
{
    varCkpActual_us = tickActualCkp5us * 5;
    return varCkpActual_us;
}



//Funciones Ticks CMP

unsigned int ticksCmpCounter(void)
{
    tickActualCmp5us++;
    return tickActualCmp5us;
}

unsigned int ticksCmpActual()
{
    return tickActualCmp5us;
}

void CmpCounterReset()
{
    tickActualCmp5us = 0;
    varCmpActual_us = 0;
}

unsigned int cmpActual_us()
{
    varCmpActual_us = tickActualCmp5us * 5;
    return varCmpActual_us;
}

void inicioCicloCalculador(int angle)
{
    int aux;
    
    aux = ticksPorGrado * (210 + angle); //210 son los grados hasta el diente 58
    if(ticksCmpCounter() == aux)
    {
        inicioCiclo = true;
    }
    
    
}

void ticks5UsCounterTimmer4(void)
{
    tick5usTimmer4++;
    
    ticksCkpCounter();
    ticksCmpCounter();
    ticksCkpAjuste();
    
    if(iniciarCicloCompleto)
    {
        //ciclocompleto(ckpAngleAdjust_Global);
        generarCicloCompleto(ckpAngleAdjust_Global);
    }
}
void ticks5UsCounterTimmer4Reset(void)
{
    tick5usTimmer4 = 0;
}

/* *****************************************************************************
 End of File
 */
