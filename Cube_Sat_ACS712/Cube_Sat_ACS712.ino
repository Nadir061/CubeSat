#include "src\Cube_Sat_ACS712.h"
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Ток ");
  Serial.print(getCurrentDC());
  Serial.println(" A");
  delay(100);
}
