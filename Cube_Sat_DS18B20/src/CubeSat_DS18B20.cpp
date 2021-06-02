#include "CubeSat_DS18B20.h"



 struct tempData getTemp(DS18B20 ds){
     struct tempData temprature;
     if (ds.selectNext())
     {
         temprature.temp1 = ds.getTempC();
     }
     
 }