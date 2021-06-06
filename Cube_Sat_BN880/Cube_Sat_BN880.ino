#include "src\Cube_Sat_BN880.h"
struct gpsData GPS;
void setup()
{
  initGPS();
}


void loop()
{
  GPS = readGPS();
}
