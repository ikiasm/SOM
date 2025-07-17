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
int global_data;

CS = 1;

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
static int ExampleLocalFunction(int param1, int param2) {
    return 0;
}


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
int ExampleInterfaceFunction(int param1, int param2) {
    return 0;
}

void EEPROM_Init(void)
{
    SPI3_CS_Set();
}

uint8_t SPI_Transfer(uint8_t data)
{
    SPI3BUF = data;                 //Enviar datos
    while(!SPI3STATbits.SPIRBF);    //Espera a que llegue el dato recibido
    return SPI3BUF;
}

void EEPROM_WriteEnable(void)
{
    SPI3_CS_Clear();                //Chip Select Activo
    SPI_Transfer(0x06);             //Comando WREN
    SPI3_CS_Set();                  //Chip Select Desactivo
}

void EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    varTicks5ms = 0;
    EEPROM_WriteEnable();                   //Habilita la escritura
    SPI3_CS_Clear();                        //Chip Select Activo
    SPI_Transfer(0x02);                     //Comando WRITE
    SPI_Transfer((address >> 8) & 0xFF);    //Byte Alto del address
    SPI_Transfer(address & 0xFF);           //Byte Baj0 del address
    SPI_Transfer(data);                     //Dato
    SPI3_CS_Set();                          //Chip Select Desactivo
    //while(varTicks5ms == 0);//__delay_ms(5);//Mucho tiempo de espera para que termine la escritura
    
}

uint8_t EEPROM_ReadByte(uint16_t address)
{
    uint8_t data;
    SPI3_CS_Clear();                        //Chip Select Activo
    SPI_Transfer(0x03);                     //Comando READ
    SPI_Transfer((address >> 8) & 0xFF);    //Byte Alto del address
    SPI_Transfer(address & 0xFF);           //Byte Baj0 del address
    data = SPI_Transfer(0xFF);              //Leer Dato
    SPI3_CS_Set();                          //Chip Select Desactivo
    return data;
}


void EEPROM_SaveMatrix(uint16_t startAddress)
{
    uint16_t address = startAddress;
    
    for(uint8_t row = 0 ; row < 14 ; row++)
    {
        for(uint8_t col = 0 ; row < 16 ; col++)
        {
            
        }
    }
}

void EEPROM_SaveMatrix_Generic(uint16_t startAddress, uint16_t *matrix, uint8_t rows, uint8_t cols)
{
    uint16_t address = startAddress;
    for(uint8_t row = 0 ; row < rows ; row++)
    {
        for(uint8_t col = 0 ; row < cols ; col++)
        {
            uint8_t data = (matrix[row * cols + col])/100;  //Indice lineal, linealizo el recorrido de una matriz bidimensional
                                                            //Importante si no conozco el tamaño de la matriz que paso por ref
                                                            //Divido por 100 para llevarlo de 1800 ms a 18 y entre en 8 bits
            
            //int8_t data = matriz[row][col];               //Esto andaria solo si matriz estuviera 
                                                            //declarada como static cosa que el compilador 
                                                            //conozca su dimension en tiempo de compilacion
            
            EEPROM_WriteByte(address++, data);
            if((address % PAGE_SIZE == 0))
            {
                //__delay_ms(5);                          //Retaro para cambiar de pag. 
            }
        }
    }
}

void EEPROM_LoadMatrix_Generic(uint16_t startAddress, uint16_t *matrix, uint8_t rows, uint8_t cols)
{
    uint16_t address = startAddress;
    
    for(uint8_t row = 0; row < rows; row++)
    {
        for(uint8_t col = 0; col < cols; col++)
        {
            matrix[row * cols + col] = (EEPROM_ReadByte(address++))*100;    //Multiplico por 100 para llevarlo de 18 a 1800 ms   
        }
    }
}

uint8_t EEPROM_ReadStatus()
{
    uint8_t status;
    SPI3_CS_Clear();                        //Chip Select Activo
    status = SPI_Transfer(0x05);            //Comando RDSR
    SPI3_CS_Set();                          //Chip Select Desactivo
    return status;
}

// Función para verificar si la EEPROM está ocupada
bool EEPROM_IsBusy(void) 
{
    uint8_t status = EEPROM_ReadStatus(); // Lee el registro de estado
    return (status & 0x01); // Devuelve verdadero si el bit WIP está activo
}

// Esperar hasta que la EEPROM esté lista
void EEPROM_WaitForReady(void)
{
    while (EEPROM_IsBusy()) {
        // Puede incluir un pequeño retraso aquí si es necesario
    }
}



/* *****************************************************************************
 End of File
 */
