/* 
    Управление датчиком тока ACS712 - Модуль Troyka
*/
#ifndef __CUBESATACS712_H__
#define __CUBESATACS712_H__

#include <SPI.h>
#define CURRENT_BAT_PIN    65  // A11 (Mega)
#define CURRENT_SOL_PIN    64  // A10 (Mega)
#define REFERENCCE_VOLTAGE 2.50 // опорное напряжение аналоговых входов [В]
#define VOLTS_PER_AMPERE   0.185 // Вольт на 1 [A]

struct currentData{
    double currentBat;
    double currentSol;
};
// Метод, получающий значение постоянного тока в Амперах
currentData getCurrents();
#endif