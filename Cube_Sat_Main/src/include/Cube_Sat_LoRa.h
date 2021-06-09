#ifndef __CUBESATLORA_H__
#define __CUBESATLORA_H__

#define UART_SPEED 9600
#include <SPI.h>
void initLoRa();
void writeDataLoRa(String outString);
#endif