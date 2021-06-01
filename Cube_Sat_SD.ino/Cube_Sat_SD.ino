#include "writeOnCard.h"
#define SS 53
#define INS 7
void setup() {
  Serial.begin(9600);
  pinMode(pinSS, OUTPUT);
  while(digitalRead(INS)); // Ждём пока вставят карту
  delay(1000);
  // Инициализация модуля SD
  bool isOnCard = initCard();
  if(!isOnCard){
    return;
  }
}

void loop() {

}
