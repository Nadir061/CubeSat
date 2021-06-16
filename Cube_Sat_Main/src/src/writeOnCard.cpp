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
    headerVal = headVal.tempBat + 
}
bool initCard(int speed){
    String header = getHeader();
    Serial2.begin(speed);
    Serial2.println(header);
    return true;
}

void writeFile(String dataSD){
    Serial2.println(dataSD);
}
