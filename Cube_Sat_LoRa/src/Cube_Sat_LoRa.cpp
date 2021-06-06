#include "Cube_Sat_LoRa.h"

void initLoRa(){
    Serial1.begin(UART_SPEED)
    pinMode(M0, OUTPUT);
    pinMode(M1, OUTPUT);
    digitalWrite(M0, LOW);
    digitalWrite(M1, LOW);
}