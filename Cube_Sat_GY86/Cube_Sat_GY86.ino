#include "src\Cube_Sat_GY86.h"

struct dataGY86 dataS;

void setup()
{
  Serial.begin(9600);
  initGY86(0x76);
}

void loop()
{
  dataS = getDataGY86();
  String out = String(dataS.temp) + " | " + String(dataS.alt) +  " | " + String(dataS.pressure);
  Serial.println(out);
}
