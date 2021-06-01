#include "writeOnCard.h"

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
bool initCard(){
    
    if (!SD.begin())
    {
        return false;
    }else return true;
}

bool createFile(String fileName){
   
    if (!SD.exists(fileName))
    { 
        String header = getHeader();
        File newFile = SD.open(fileName, FILE_WRITE);
        if (newFile)
        {
        newFile.println(header);
        newFile.close();
        return true;
        }else false;
    }else return true;
    

}

void writeFile(String fileName){
    String data = getStringFromData();
    File openFile = SD.open(fileName);
    if (openFile)
    {
        openFile.println(data);
        openFile.close();
    }
}
