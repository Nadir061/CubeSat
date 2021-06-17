#include ".\src\cubemain.h"
struct currentData currents;
double press_sea = 175;
long timer = 0;
void setup(){
  getInt();
}

void loop(){
  if(millis() - timer > 1000){
    sendToLora(press_sea);
    sendToSD(press_sea);
    timer = millis();
  }
}
