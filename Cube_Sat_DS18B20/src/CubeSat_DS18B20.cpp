#include "CubeSat_DS18B20.h"

 DS18B20 init(int pinWire){
     DS18B20 tempSensor = DS18B20(pinWire);
     return tempSensor;
 }