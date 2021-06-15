#include ".\include\writeOnCard.h"
#include ".\include\Cube_Sat_LoRa.h"
#include ".\include\Cube_Sat_BN880.h"
#include ".\include\Cube_Sat_ACS712.h"
#include ".\include\CubeSat_DS18B20.h"
#include ".\include\Cube_Sat_GY86.h"

#define VOLTAGE_SOL_PIN  56  // A2 (Mega)
#define TEMP_THRESH 15 // Граничное значение тепературы батареи 
#define TOGLE_PIN 11 // D11
//#define REFERENCCE_VOLTAGE 2.50 // опорное напряжение аналоговых входов [В]

struct dataForLoRa{
    struct tempData temps;
    struct currentData currents;
    struct gpsData GPS;
};
struct dataForSD{
    struct dataForLoRa dataLoRa;
    double voltage_solar;
};


void getInt();
double getSolarVoltage();
// Методы для формирования двух структур
dataLoRa getLoRaData();
dataSD getSdData();
// Методы для формирования строк из двух структур
String getStrForLoRa();
String getStrForSD();
// Методы для отправки данных на карту памяти и по радиоканалу
void sendToLora(String strLora);
void sendToSD(String strSD);