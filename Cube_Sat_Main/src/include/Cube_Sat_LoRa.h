#ifndef __CUBESATLORA_H__
#define __CUBESATLORA_H__

#include <SPI.h>

#define UART_SPEED 9600

void initLoRa();
void writeDataLoRa(String outString);
#endif