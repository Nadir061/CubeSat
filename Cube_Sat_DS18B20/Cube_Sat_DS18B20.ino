#include "src\CubeSat_DS18B20.h"

int wirePin = 52; // A0 Arduino Mega
struct tempData temp;
DS18B20 ds(wirePin);
void setup() {
  Serial.begin(9600);
}


void loop() {
  temp = getTemp(ds);
  Serial.println(temp.temp1);
}
