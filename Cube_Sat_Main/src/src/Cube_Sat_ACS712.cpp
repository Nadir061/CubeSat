#include "..\include\Cube_Sat_ACS712.h"

double zero_current_voltage = REFERENCCE_VOLTAGE / 2; // Напряжение, соответствующее значению 0 [А]

currentData getCurrents(){
    struct currentData currents;
    double volt_bat = (double)(analogRead(CURRENT_BAT_PIN)*REFERENCCE_VOLTAGE) / 1024;
    double volt_sol = (double)(analogRead(CURRENT_SOL_PIN)*REFERENCCE_VOLTAGE) / 1024;
    currents.currentBat = (volt_bat - zero_current_voltage) * 2 / VOLTS_PER_AMPERE;
    currents.currentSol = (volt_sol - zero_current_voltage) * 2 / VOLTS_PER_AMPERE;
    return currents;
}