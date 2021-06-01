#include "src\writeOnCard.h"
#define SS 10
#define INS 7
String fileName = "TestCubeSat.txt";
String dataString = "Hello world";
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  while(digitalRead(INS)); // Ждём пока вставят карту
  delay(1000);
  // Инициализация модуля SD
  bool isOnCard = initCard();
  if(!isOnCard){
    return;
  }
  bool file = createFile(fileName);
  if(file){
    Serial.println("File: " + fileName + " created");
  }else Serial.println("File: " + fileName + " not created!");
}

void loop() {
 
  if(count < 5){
    writeFile(fileName, dataString);
    count++;
  }

}
