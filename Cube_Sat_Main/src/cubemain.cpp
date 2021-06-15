#include ".\cubemain.h"

void getInt(){
    
}

double getSolarVoltage(){
   return (double)(analogRead(VOLTAGE_SOL_PIN)*REFERENCCE_VOLTAGE) / 1024; // Считываем напряжение солнечной батареи
}


gpsData getGpsData(){
    
}
dataLoRa getLoRaData(){
    dataForLoRa dataLora;

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



void sendToLora(){

}

void sendToSD(){

}