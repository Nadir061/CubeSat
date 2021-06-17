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
  String tempBat = "\tTempBat";
  String temp = "\tTemp";
  String currentBat = "\tCurrentBat";
  String currentSol = "\tCurrentSol";
  String gpsLatit = "\tGpsLatit";
  String gpsLongit = "\tGpsLongit";
  String gpsAltit = "\tGpsAltit";
  String gpsSpeed = "\tGpsSpeed";
  String gpsCourse = "\tGpsCourse";
  String MS5611 = "\tMS5611";
  String MPU6050 = "\tMPU6050";
  String voltSol =   "\tVoltSol";
};

struct headSensors{
  String tempSens1 = "\t(DS18B20)\t";
  String tempSens2 = "\t(DS18B20)\t";
  String currentSens1 = "\t(ACS712)\t";
  String currentSens2 = "\t(ACS712)\t";
  String GPS = "\t(BN880)\t";
  String voltSolSens = "\tADC(A2)" ;
};

// Метод, формирующий заголовок для файла
    String getHeaderSens();
    String getHeaderVal();
// Метод, инициализирующий карту памяти 
    bool initCard(int speed);
// Мтеод записывающий данные в файл
    void writeFile(String dataSD);
#endif