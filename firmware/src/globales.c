#include "globales.h"
#include <stdbool.h>


//bool dienteReferenciaGlobal = false;
int pruebaGlobal = 12;
bool dienteReferenciaGlobal = false;
bool vueltaCompleta_Global = false;
bool vueltaCompletaSeguraGlobal = false;
bool vueltaConSincroCmp = false;
bool sincroDetectado = false;
bool primeraVueltaDetectadaGlobal = false;
unsigned int primerasVueltasGlobal = 0;

bool iniciarCicloCompleto = false;

int deltaCkpBufferGlobal[59];
int deltaTicksCkpBufferGlobal[58];

int ckpAngleAdjust_Global = GRADO_INICIAL;
int dienteActualGlobal = 0;
int dienteGeneradoGlobal = 0;

int ticksPorGrado = 0;
int periodoRevolucionTicksGlobal = 0;
int rpmGlobal = 0;


bool inicioCiclo = false;

//Globales de comunicacion
unsigned char receiveBuffer[RX_BUFFER_SIZE];
unsigned char transmitBuffer[BUFFER_SIZE];
char messageError[] = "UART error";
char messageInicio[] = "UART ON";

bool errorStatus = false;
bool writeStatus = false;
bool readStatus = false;

uint16_t RPM_Global = 0;
uint16_t RPM_AnteriorGlobal = 0;
int RPM_Limiter_Global = 4000;//4500;//4000;

int varTicks1msInyeccion = 0;
int varTicks5usInyeccion = 0;
int varTicks5ms = 0;
uint16_t ppaPercentGlobal = 243;//235;//221;//232;
//unsigned int ppaPercentGlobal = 235;//221;//232;
uint16_t ppaPercentAdqGlobal = 0;

//Parametros Iny GNC

bool llaveEnGasGlobal = false;

bool inyector1ActivoGlobal = false;
bool inyector2ActivoGlobal = false;
bool inyector3ActivoGlobal = false;
bool inyector4ActivoGlobal = false;

bool inyector1EnabledGlobal = true;//false;
bool inyector2EnabledGlobal = true;//false;
bool inyector3EnabledGlobal = true;//false;
bool inyector4EnabledGlobal = true;//false;

int inyector1ApmsGlobal = 30;
int inyector2ApmsGlobal = 210;
int inyector3ApmsGlobal = 390;
int inyector4ApmsGlobal = 570;

int inyector1TiempoGlobal = 2500;//3200;
int inyector2TiempoGlobal = 2500;//3200;
int inyector3TiempoGlobal = 2500;//3200;
int inyector4TiempoGlobal = 2500;//3200;

int inyectorGralTiempoGlobal = 2600;

int saturacion_usGlobal = 15000;//10000;//4800; //060924
unsigned int dutyPosGlobal = 40;
unsigned int dutyNegGlobal = 60;

int inyectorDeadTimeGlobal = 1800;

bool timmerInyectoresActivo = false;

//Parametros Mapas


int rowMapaInyGlobal = 0;
int columnMapaInyGlobal = 0;

bool retencionGas = false;
int mapaActualGlobal = MAPA_SAFE;

bool mapaSafe = true;

//Parametros programacion

bool programming = false;
bool uploading = false;