#include "Cube_Sat_LoRa.h"



void initLoRa(){
    Serial1.begin(UART_SPEED);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    //digitalWrite(M0, LOW);
    //digitalWrite(M1, LOW);
}

void writeDataLoRa(String outString){
    Serial1.print(outString);
    delay(20);
}