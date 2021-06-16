/*

Определены функции для создания файла
 и записи данных, полученных от рахличных датчиков.
 Данные сохраняются в формате:
 <Измеряемая величина_1>    <Измеряемая величина_2>     <Измеряемая величина_3>
 <(Название датчика_1)>     <(Название датчика_2)>      <(Название датчика_3)>
       Данные_1                   Данные_2                     Данные_3
       Данные_1                   Данные_2                     Данные_3
       Данные_1                   Данные_2                     Данные_3
       Данные_1                   Данные_2                     Данные_3

Структура может меняться по усмотрению пользователя. 
Для этого необходимо заменить или дополнить структуры

*/
#include <SD.h>
#ifndef __WRITEONCARD_H__
#define __WRITEONCARD_H__

struct headValue{
  String tempBat = "TempBat\t";
  String temp = "Temp\t";
  String currentBat = "CurrentBat\t";
  String currentSol = "CurrentSol\t";
  String gpsLatit = "GpsLatit\t";
  String gpsLongit = "GpsLongit\t";
  String gpsAltit = "GpsAltit\t";
  String gpsSpeed = "GpsSpeed\t";
  String gpsCourse = "GpsCourse\t";
  String voltSol =   "VoltSol\t";
};

struct headSensors{
  String tempSens1 = "(DS18B20)\t";
  String tempSens2 = "(DS18B20)\t";
  String currentSens1 = "(ACS712)\t";
  String currentSens2 = "(ACS712)\t";
  String GPS = "(BN880)\t";
  String voltSolSens = "ADC(A2)" 
};

// Метод, формирующий заголовок для файла
    String getHeaderSens();
    String getHeaderVal();
// Метод, инициализирующий карту памяти 
    bool initCard(int speed);
// Мтеод записывающий данные в файл
    void writeFile(String dataSD);
#endif