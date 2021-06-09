#include "..\include\writeOnCard.h"

struct data myData;
struct headValue head;
struct headSensors headSens;

String getHeader(){
    String header;
    header = head.tempVal + head.pressVal + head.altVal;
    header += headSens.tempSens + headSens.pressSens + headSens.altSens;
    return header;
}

String getStringFromData(){
    String outString = " " + String(myData.temp) + "\t";
    outString +=       "    " + String(myData.pres) + "\t";
    outString +=       "    " + String(myData.alt) + "\t";
    return outString;

}
bool initCard(int speed){
    String header = getHeader();
    Serial2.begin(speed);
    Serial2.println(header);
    return true;
}

void writeFile(){
    String data = getStringFromData();
    Serial2.println(data);
}
