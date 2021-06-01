#ifndef __CUBESAT_DS18B20_H__
#define __CUBESAT_DS18B20_H__

#include <DS18B20.h>


struct tempData{
    int temp1;
}
// Инициализация
    DS18B20 init(int pinWire);
// Получение температуры
    struct tempData getTemp(DS18B20 ds);
#endif