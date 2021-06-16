#include ".\cubemain.h"

void getInt(){
    pinMode(11,OUTPUT);
    initLoRa();
    initGPS();
}

double getSolarVoltage(){
   return (double)(analogRead(VOLTAGE_SOL_PIN)*REFERENCCE_VOLTAGE) / 1024; // Считываем напряжение солнечной батареи
}


dataForLoRa getLoRaData(){
    dataForLoRa dataLora;
    dataLora.temps = getTemp();

    if (dataLora.temps.temp1 < TEMP_THRESH)
    {
        analogWrite(TOGLE_PIN, 255);
    }else analogWrite(TOGLE_PIN, 0);

    dataLora.currents = getCurrents();
    dataLora.GPS = readGPS();
    return dataLora;
}

dataForSD getSdData(){
    dataForSD dataSD;
    dataSD.dataLoRa = getLoRaData();
    dataSD.voltage_solar = getSolarVoltage(); // Записываем напряжение солнечной батареи
    return dataSD;
}




String getStrForLoRa(){
    dataForLoRa dataLora = getLoRaData();
    String Temp1 = (String)dataLora.temps.temp1 + "\t";
    String Temp2 = (String)dataLora.temps.temp2 + "\t";
    String CurrentBAT = (String)dataLora.currents.currentBat + "\t";
    String CurrentSOL =  (String)dataLora.currents.currentSol + "\t";
    String latitude = String(dataLora.GPS.latitude, 5) + "\t";
    String longitude = String(dataLora.GPS.longitude, 5) + "\t";
    String speed = (String)dataLora.GPS.speed + "\t";
    String course = (String)dataLora.GPS.course;
    String out = Temp1 + Temp2 + CurrentBAT + CurrentSOL + latitude + longitude + speed + course;
    return out;
}

String getStrForSD(){

}



void sendToLora(){
    String outStr = getStrForLoRa();
    writeDataLoRa(outStr);
}

void sendToSD(String strSD){

}