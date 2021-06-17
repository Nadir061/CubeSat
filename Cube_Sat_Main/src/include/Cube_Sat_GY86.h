#ifndef __CUBESATGY86_H__
#define __CUBESATGY86_H__

#include <Wire.h>
#include <MS5x.h>
#include <MPU6050_tockn.h>

#define ADDR_MS 0x77

struct dataMS{
    double temp = 0.00;
    double pressure = 0.00;
    double pressSea = 0.00;
    double alt = 0.00;
    //double azimuth = 0.00;
};

struct dataMPU{
  float accX;
  float accY;
  float accZ;
  float gyroX;
  float gyroY;
  float gyroZ;
  float angleAccX;
  float angleAccY;
  float angleGyroX;
  float angleGyroY;
  float angleGyroZ;
  float angleX;
  float angleY;
  float angleZ;
};

void initMS(int addrMS);
void initMPU();
//void initHMC();
void initGY86();

dataMS getDataMS(double press_sea);
dataMPU getDataMPU();
//dataHMC getDataHMC();


#endif