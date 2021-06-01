#include "CubeSat_DS18B20.h"

struct tempData temprature;

 DS18B20 init(int pinWire){
     DS18B20 tempSensor = DS18B20(pinWire);
     return tempSensor;
 }

 struct tempData getTemp(DS18B20 ds){
     if (ds.selectNext())
     {
         temprature.temp1 = (int)ds.getTempC()
     }
     
 }