#include ".\cubemain.h"

void getInt(){
    pinMode(11,OUTPUT);
    bool card = initCard(9600);
    initGY86();
    initLoRa();
   // initRad();
    initGPS();
}

double getSolarVoltage(){
   return (double)(analogRead(VOLTAGE_SOL_PIN)*REFERENCCE_VOLTAGE) / 1024; // Считываем напряжение солнечной батареи
}


dataForLoRa getLoRaData(double press_sea){
    dataForLoRa dataLora;
    dataLora.temps = getTemp();

    /*if (dataLora.temps.temp1 < TEMP_THRESH)
    {
        analogWrite(TOGLE_PIN, 255);
    }else analogWrite(TOGLE_PIN, 0);
*/
    dataLora.currents = getCurrents();
    dataLora.GPS = readGPS();
    dataLora.data_ms = getDataMS(press_sea);
    return dataLora;
}

dataForSD getSdData(){
    dataForSD dataSD;
    //dataSD.data_rad = getRadData();
    dataSD.data_mpu = getDataMPU();
    dataSD.voltage_solar = getSolarVoltage(); // Записываем напряжение солнечной батареи
    return dataSD;
}




String getStrForLoRa(double press_sea){
    dataForLoRa dataLora = getLoRaData(press_sea);
    String Temp1 = "\t" + (String)dataLora.temps.temp1;
    String Temp2 = "\t" + (String)dataLora.temps.temp2;
    String CurrentBAT = "\t" + (String)dataLora.currents.currentBat;
    String CurrentSOL =  "\t" + (String)dataLora.currents.currentSol;
    String Latitude = "\t" + String(dataLora.GPS.latitude, 5);
    String Longitude = "\t" + String(dataLora.GPS.longitude, 5);
    String altGps = "\t" + (String)dataLora.GPS.altitude;
    String Speed = "\t" + (String)dataLora.GPS.speed;
    String Course = "\t" + (String)dataLora.GPS.course;
    String Press = "\t" + (String)dataLora.data_ms.pressure;
    String altBar = "\t" + (String)dataLora.data_ms.pressure;
    String out = Temp1 + Temp2 + CurrentBAT + CurrentSOL + Latitude + Longitude + altGps + Speed + Course + Press + altBar;
    return out;
}

String getStrForSD(double press_sea){
    dataForSD dataSD = getSdData();
    String strLora = getStrForLoRa(press_sea);
    String  str_accX = "\t" + (String)dataSD.data_mpu.accX;
    String  str_accY = "\t" + (String)dataSD.data_mpu.accY;
    String  str_accZ = "\t" + (String)dataSD.data_mpu.accZ;
    String  str_gyroX = "\t" + (String)dataSD.data_mpu.gyroX;
    String  str_gyroY = "\t" + (String)dataSD.data_mpu.gyroY;
    String  str_gyroZ = "\t" + (String)dataSD.data_mpu.gyroZ;
    String  str_angleAccX = "\t" + (String)dataSD.data_mpu.angleAccX;
    String  str_angleAccY = "\t" + (String)dataSD.data_mpu.angleAccY;
    String  str_angleGyroX = "\t" + (String)dataSD.data_mpu.angleGyroX;
    String  str_angleGyroY = "\t" + (String)dataSD.data_mpu.angleGyroY;
    String  str_angleGyroZ = "\t" + (String)dataSD.data_mpu.angleGyroZ;
    String  str_angleX = "\t" + (String)dataSD.data_mpu.angleX;
    String  str_angleY = "\t" + (String)dataSD.data_mpu.angleY;
    String  str_angleZ = "\t" + (String)dataSD.data_mpu.angleZ; 
    String vSol = "\t" + (String)dataSD.voltage_solar;
    String outStr = strLora +str_accX+str_accY+str_accZ+str_gyroX+str_gyroY+str_gyroZ+str_angleAccX+str_angleAccY+str_angleGyroX+str_angleGyroY+str_angleGyroZ+str_angleX+str_angleY+str_angleZ+vSol;
    return outStr;
}



void sendToLora(double press_sea){
    String outStr = getStrForLoRa(press_sea);
    writeDataLoRa(outStr);
}

void sendToSD(double press_sea){
String strSD = getStrForSD(press_sea);
    writeFile(strSD);
}