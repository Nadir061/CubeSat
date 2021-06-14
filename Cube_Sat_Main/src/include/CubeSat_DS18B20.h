#ifndef __CUBESAT_DS18B20_H__
#define __CUBESAT_DS18B20_H__

#include <DS18B20.h>

#define WIRE_PIN 10 // D10 (1Wire)

struct tempData{
    float temp1;
    float temp2;
};

// Получение температуры
 tempData getTemp();
#endif