/* 
    Управление датчиком тока ACS712 - Модуль Troyka
*/
#ifndef __CUBESATACS712_H__
#define __CUBESATACS712_H__


#include <TroykaCurrent.h>

#define CURRENT_PIN 65  // A11 (Mega)

// Метод, получающий значение постоянного тока в Амперах
float getCurrentDC();
#endif