#include "..\include\writeOnCard.h"

struct headValue headVal;
struct headSensors headSens;

String getHeaderSens(){
    String headerSens;
    headerSens = headSens.tempSens1 + headSens.tempSens2 + headSens.currentSens1 + headSens.currentSens2 + headSens.GPS + headSens.voltSolSens;
    return headerSens;
}

String getHeaderVal(){
    String headerVal;
  headerVal = headVal.tempBat + headVal.temp + headVal.currentBat + headVal.currentSol +headVal.gpsLatit + headVal.gpsLongit +headVal.gpsAltit +headVal.gpsSpeed +headVal.gpsCourse +headVal.MS5611 +headVal.MPU6050 +headVal.voltSol;
}
bool initCard(int speed){
    String sens = getHeaderSens();
    String val = getHeaderVal();
    Serial2.begin(speed);
    Serial2.println(sens);
    Serial2.println(val);
    return true;
}

void writeFile(String dataSD){
    Serial2.println(dataSD);
}
