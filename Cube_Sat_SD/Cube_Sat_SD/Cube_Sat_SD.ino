#include "src\writeOnCard.h"
int count = 0;
int speedS2 = 9600;
void setup() {
  bool initSD = initCard(speedS2);
}

void loop() {
 
  if(count < 5){
    writeFile();
    count++;
  }

}
