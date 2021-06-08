#ifndef __CUBESATGY86_H__
#define __CUBESATGY86_H__

#include <Wire.h>
#include <MS5x.h>
#include <MPU6050_tockn.h>
#include <HMC5883L.h>
struct dataGY86{
    double temp = 0.00;
    double pressure = 0.00;
    double alt = 0.00;
    //double azimuth = 0.00;
};

void initGY86(int addr);

dataGY86 getDataGY86();


#endif