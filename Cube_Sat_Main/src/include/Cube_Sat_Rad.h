#ifndef __CUBESATRAD_H__
#define __CUBESATRAD_H__

#include <Arduino.h>
#include <Wire.h>
#include ".\radSens1v2.h""


struct dataRad{
    float intensyD = 0.0;
    float intensyS = 0.0;
    int numberPulse = 0;
};

void initRad();

dataRad getRadData();

#endif