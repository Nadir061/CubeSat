#ifndef __CUBESATBN880_H__
#define __CUBESATBN880_H__
/*
    Управление модулем GPS BN880; Проктокол NMEA 0183
*/
#include <iarduino_GPS_NMEA.h>
#define UART_SPEED 9600
struct gpsData{
    float latitude = 0.0; // Широта +/- 90.0 
    float longitude = 0.0; // Долгота +/- 180;  Е-восточная "+", W - западная "-" 
    int altitude = 0; // высота над уровнем моря +/-32767
    int speed = 0; // Скорость 0-255 км/ч
    float course = 0.0; // +/- 180.0
    /*uint8_t year = 0;
    uint8_t month = 0;
    uint8_t day = 0;
    uint8_t hours = 0;
    uint8_t minutes = 0;
    uint8_t seconds = 0; 
    */
};
/*
*   Метод инициализации GPS
*   serialSpeed - Скорость обмена по UART
*/
void initGPS();
/*
*   Метод, получающий данные с GPS
*/
gpsData readGPS();
#endif