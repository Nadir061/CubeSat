#include "..\include\Cube_Sat_GY86.h"


MS5x barometer(&Wire);
double press_sea = 175; // Высота над уровнем моря для заданной местности запуска [м]; Установить самостоятельно

void initGY86(int addr){
    Wire.begin();
    barometer.setI2Caddr(addr);
    while(barometer.connect()>0) {};
}


dataGY86 getDataGY86(){
    struct dataGY86 dataMS;
    barometer.checkUpdates();
    if (barometer.isReady())
    {
        dataMS.temp = barometer.GetTemp();
        dataMS.pressure = barometer.GetPres();
        if(dataMS.pressSea == 0){
            dataMS.pressSea = barometer.getSeaLevel(press_sea);
        }
        dataMS.alt = barometer.getAltitude(true);
        return dataMS;
    }
    return dataMS;
}