#include ".\cubemain.h"

void getInt(){
    pinMode(11,OUTPUT);
    initGPS();
}

double getSolarVoltage(){
   return (double)(analogRead(VOLTAGE_SOL_PIN)*REFERENCCE_VOLTAGE) / 1024; // Считываем напряжение солнечной батареи
}


dataLoRa getLoRaData(){
    dataForLoRa dataLora;
    dataLora.temps = getTemp();
    if (dataLora.temps.temp1 < TEMP_THRESH)
    {
        analogWrite(TOGLE_PIN, 255);
    }
    dataLora.currents = getCurrents();
    dataLora.GPS = readGPS();
    return dataLora;
}

dataSD getSdData(){
    dataForSD dataSD;
    dataSD.dataLoRa = getLoRaData();
    dataSD.voltage_solar = getSolarVoltage(); // Записываем напряжение солнечной батареи
    return dataSD;
}




String getStrForLoRa(){

}

String getStrForSD(){

}



void sendToLora(String strLora){

}

void sendToSD(String strSD){

}