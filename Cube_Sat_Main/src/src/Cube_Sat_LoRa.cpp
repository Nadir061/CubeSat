#include "..\include\Cube_Sat_LoRa.h"



void initLoRa(){
    Serial1.begin(UART_SPEED);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    
}

void writeDataLoRa(String outString){
    Serial1.println(outString);
    //delay(20);
}