#include "writeOnCard.h"

struct headValue head;
struct headSensors headSens;

String getHeader(){
    String header;
    header = head.tempVal + head.pressVal + head.altVal;
    header += headSens.tempSens + headSens.pressSens + headSens.altSens;
    return header;
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

void writeFile(String fileName, String data){
    File openFile = SD.open(fileName);
    if (openFile)
    {
        openFile.println(data);
        openFile.close();
    }
}
