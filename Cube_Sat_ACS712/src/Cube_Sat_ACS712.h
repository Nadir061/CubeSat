/* 
    Управление датчиком тока ACS712 - Модуль Troyka
*/
#include <TroykaCurrent.h>

#define CURRENT_PIN 65  // A11 (Mega)

// Метод, получающий значение постоянного тока в Амперах
float getCurrentDC();
