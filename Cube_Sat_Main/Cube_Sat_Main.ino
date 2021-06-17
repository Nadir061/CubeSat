#include ".\src\cubemain.h"
struct currentData currents;
double press_sea = 175;
long timer = 0;
String a = "Hello world!";
void setup(){
  //getInt();
  initLoRa();
}

void loop(){
  
  
  if(millis() - timer > 1000){
    writeDataLoRa(a);
    timer = millis();
  }
  /*if(millis() - timer > 1000){
    sendToLora(press_sea);
    sendToSD(press_sea);
    timer = millis();
  }*/
}
