#include ".\src\cubemain.h"
struct currentData currents;
void setup(){
  getInt();
}

void loop(){
  sendToLora();
  delay(1000);
}
