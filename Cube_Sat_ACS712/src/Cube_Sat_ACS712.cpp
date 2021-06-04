#include "Cube_Sat_ACS712.h"

ACS712 sensorCurrent(CURRENT_PIN);

float getCurrentDC(){
    return sensorCurrent.readCurrentDC(); 
}