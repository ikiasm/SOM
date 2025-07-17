
#include <stdbool.h>
#include <stdint.h>
//DEFINES
#define RX_BUFFER_SIZE  10
#define BUFFER_SIZE 10
#define GRADO_INICIAL 0    //VALOR POSIBLE 30 DESDE LA GENERACION DE CICLO

#define MAPA_SAFE 0
#define MAPA_TUNING 1


//extern bool dienteReferenciaGlobal;
extern int pruebaGlobal;
extern bool dienteReferenciaGlobal;
extern bool vueltaCompleta_Global;
extern bool vueltaCompletaSeguraGlobal;
extern bool vueltaConSincroCmp;
extern bool sincroDetectado;
extern bool primeraVueltaDetectadaGlobal;
extern unsigned int primerasVueltasGlobal;

extern bool iniciarCicloCompleto;

extern int dienteActualGlobal;
extern int dienteGeneradoGlobal;

extern int deltaCkpBufferGlobal[59];

extern int deltaTicksCkpBufferGlobal[58];

extern int ckpAngleAdjust_Global;
extern int ticksPorGrado;
extern int periodoRevolucionTicksGlobal;
extern int rpmGlobal;


extern bool inicioCiclo;


extern unsigned char receiveBuffer[RX_BUFFER_SIZE];
extern unsigned char transmitBuffer[BUFFER_SIZE];
extern char messageError[BUFFER_SIZE];
extern char messageInicio[BUFFER_SIZE];

extern bool errorStatus;
extern bool writeStatus;
extern bool readStatus;


extern uint16_t RPM_Global;
extern uint16_t RPM_AnteriorGlobal;

extern int RPM_Limiter_Global;

extern int varTicks1msInyeccion;
extern int varTicks5usInyeccion;
extern int varTicks5ms;


extern uint16_t ppaPercentGlobal;
extern uint16_t ppaPercentAdqGlobal;

//Parametros Iny GNC

extern bool llaveEnGasGlobal;

extern bool inyector1ActivoGlobal;
extern bool inyector2ActivoGlobal;
extern bool inyector3ActivoGlobal;
extern bool inyector4ActivoGlobal;

extern bool inyector1EnabledGlobal;
extern bool inyector2EnabledGlobal;
extern bool inyector3EnabledGlobal;
extern bool inyector4EnabledGlobal;

extern int inyector1ApmsGlobal;
extern int inyector2ApmsGlobal;
extern int inyector3ApmsGlobal;
extern int inyector4ApmsGlobal;

extern int inyector1TiempoGlobal;
extern int inyector2TiempoGlobal;
extern int inyector3TiempoGlobal;
extern int inyector4TiempoGlobal;

extern int inyectorGralTiempoGlobal;

extern int saturacion_usGlobal;
extern unsigned int dutyPosGlobal;
extern unsigned int dutyNegGlobal;

extern int inyectorDeadTimeGlobal;

extern bool timmerInyectoresActivo;

//parametros mapas

extern int rowMapaInyGlobal;
extern int columnMapaInyGlobal;

extern bool retencionGas;
extern int mapaActualGlobal;

extern bool mapaSafe;

//parametros programacion

extern bool programming;
extern bool uploading;