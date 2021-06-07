#include "src\Cube_Sat_LoRa.h"
void setup()
{
  Serial.begin(9600);
  initLoRa();
}


void loop()
{
  writeDataLoRa("Hello world!");
}
