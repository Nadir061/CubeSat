#include "Cube_Sat_BN880.h"

iarduino_GPS_NMEA gps;


void initGPS(){
    Serial3.begin(UART_SPEED);
    gps.begin(Serial3);
}


gpsData readGPS(){
    struct gpsData dataGPS;
    gps.read();
    if(gps.errPos){
        delay(2000);
        return dataGPS;
    }
    dataGPS.latitude = gps.latitude;
    dataGPS.longitude = gps.longitude;
    dataGPS.course = gps.course;
    dataGPS.altitude = gps.altitude;
    dataGPS.speed = gps.speed;
    dataGPS.year = gps.year;
    dataGPS.month = gps.month;
    dataGPS.day = gps.day;
    dataGPS.hours = gps.hours;
    dataGPS.minutes = gps.minutes;
    dataGPS.seconds = gps.seconds;
    return dataGPS;
}