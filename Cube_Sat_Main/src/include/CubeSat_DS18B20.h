#ifndef __CUBESAT_DS18B20_H__
#define __CUBESAT_DS18B20_H__

#include <DS18B20.h>


struct tempData{
    float temp1;
};

// Получение температуры
    struct tempData getTemp(DS18B20 ds);
#endif