#include "src\writeOnCard.h"
int count = 0;
int speedS2 = 9600;
void setup() {
  Serial.begin(9600);
  bool initSD = initCard(speedS2);
  if(initSD){
    Serial.println("SD ready!");
  }
}

void loop() {
 
  if(count < 5){
    writeFile();
    count++;
  }

}
