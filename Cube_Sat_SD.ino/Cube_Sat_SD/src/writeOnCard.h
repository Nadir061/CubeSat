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

#ifndef __WRITEONCARD_H__
#define __WRITEONCARD_H__

#include <SPI.h>
#include <SD.h>

struct data{
  int temp = -35;
  int pres = 101; 
  int alt = 300;
};

struct headValue{
  String tempVal = " Temp\t";
  String pressVal = "   Press\t";
  String altVal =   "   Alt\t\n";
};

struct headSensors{
  String tempSens =  "(DS18B20)\t";
  String pressSens = "(MS5611)\t";
  String altSens =   "(MS5611)\t\n";
};

// Метод, формирующий заголовок для файла
    String getHeader();
// Метод, формирующий заголовок для файла
    String getStringFromData(struct data);
// Метод, инициализирующий карту памяти 
    bool initCard();
// Метод создаёт файл с заданным именем и записывает в него заголовок    
    bool createFile(String fileName);
// Мтеод записывающий данные в файл
    void writeFile(String fileName);
#endif