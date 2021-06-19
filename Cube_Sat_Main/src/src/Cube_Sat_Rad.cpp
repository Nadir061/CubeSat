#include "..\include\Cube_Sat_Rad.h"


ClimateGuard_RadSens1v2 radSens(0x66);

void initRad(){
     radSens.radSens_init(); 
     radSens.setSensitivity(55);
     radSens.setHVGeneratorState(false);
}


dataRad getRadData(){
    dataRad data_rad;
    radSens.setHVGeneratorState(true);
    data_rad.intensyD = radSens.getRadIntensyDyanmic();
    data_rad.intensyS = radSens.getRadIntensyStatic();
    data_rad.numberPulse = radSens.getNumberOfPulses();
    radSens.setHVGeneratorState(false);
    return data_rad;

}