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

//#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
//#define _EXAMPLE_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdbool.h>

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

#define VUELTAS_ESTABLES    3 //100
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

    typedef enum
    {
        AN0 = 0,
        AN1,
        SHUNT_INY3,
        SHUNT_INY2,
        SHUNT_INY1,
        AN5,
        SHUNT_INY4,
        AN7,
        AN8,
        PRESION_GNC,    //GENERICO_AN3,
        AGUA,           //GENERICO_AN1,
        KNOCK,          //GENERICO_AN2,
        MAP,
        TEMP_ESCAPE,
        PP2,
        PP1,
    }SENSOR;
    
    typedef struct
    {
        SENSOR canal;
    }ANALOGICO;
    //SENSORES LENTOS
    //CONMUTADOR            DIGITAL INPUT
    //PULSO DE INYECCION    INT3
    //TEMP DE ESCAPE        AN
    //MAP                   AN
    //CAUDALIMETRO          INT1
    //ANALOGICO1            AN  ALGUNO DE ESTOS ES PARA KNOCK
    //ANALOGICO2            AN
    //ANALOGICO3            AN
    
    //SENSORES CRITICOS
    //CKP                   INT0
    //CMP                   INT2
    //POSICION PEDAL 1      AN
    //POSICION PEDAL 2      AN
    
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
    
    
    extern int rpmGlobal;
//    extern int deltaCkpBufferGlobal[59];
//    extern bool dienteReferenciaGlobal;
    
    
    bool estadoConmutador(void);
    unsigned int pulsoInyeccion(void);
    unsigned int caudalimetro(void);
    unsigned int adquirirAnalogico(SENSOR an);
    void ckpAdquisicion(void);
    void cmpAdquisicion(void);
    /**
      @Function
        void ckpAdquisicion(void) 

      @Summary
        Llamado desde la interrupcion de INT0

      @Description
        Procesa el periodo entre pulsos para promediar RPM y detectar el espacio
        de referencia del cig�e�al.
        <p>
        
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
    void cmpAdquisicion(void);
    void ckpAdquisicionPrevia(void);
    void ckpAdquisicionVueltaPrevia(void);
    
    
    void ckpRelativeAngle(int angle);
    void cmpRelativeAngle(int angle);
    
    //armar con puntero
    void ckpBufferReset(void);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

//#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
