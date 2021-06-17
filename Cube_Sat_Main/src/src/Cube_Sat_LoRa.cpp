#include "..\include\Cube_Sat_LoRa.h"



void initLoRa(){
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    Serial1.begin(UART_SPEED);

    
}

void writeDataLoRa(String outString){
    Serial1.println(outString);
    //delay(20);
}