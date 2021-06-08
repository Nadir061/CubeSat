#include "Cube_Sat_GY86.h"


MS5x barometer(&Wire);

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
        dataMS.alt = barometer.getAltitude();
        return dataMS;
    }
    return dataMS;
}