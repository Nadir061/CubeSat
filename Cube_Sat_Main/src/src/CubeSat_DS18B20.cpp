#include "..\include\CubeSat_DS18B20.h"
DS18B20 ds(WIRE_PIN);


  tempData getTemp(){
     struct tempData temprature;
     float temps[2];
     int i = 0;
     while (ds.selectNext())
     {
         temps[i] = ds.getTempC(); 
         i++;
     }
    temprature.temp1 = temps[0];
    temprature.temp2 = temps[1];
    return temprature;
 }