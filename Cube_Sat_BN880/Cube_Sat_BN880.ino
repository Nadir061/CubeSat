#include "src\Cube_Sat_BN880.h"
struct gpsData GPS;
void setup()
{
  Serial.begin(9600);
  initGPS();
}


void loop()
{
  GPS = readGPS();
  Serial.println(GPS.latitude);
  Serial.println(GPS.longitude);
  Serial.println(GPS.altitude);
  Serial.println(GPS.speed);
  Serial.println(GPS.course);
  Serial.println(GPS.year);
  Serial.println(GPS.month);
  Serial.println(GPS.day);
  Serial.println(GPS.hours);
  Serial.println(GPS.minutes);
  Serial.println(GPS.seconds);
  
  
}
