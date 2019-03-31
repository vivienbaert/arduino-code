
#include "Keyboard.h"

const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;


void setup() { 
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);

  
  Serial.begin(9600);
}
void loop() 
{
  if (digitalRead(upButton) == HIGH) {
    Keyboard.write('z');
    delay(500);
    Keyboard.release('z');
  }
  if (digitalRead(downButton) == HIGH) {
    Keyboard.write('x');
    delay(500);
    Keyboard.release('x');
  }
  if (digitalRead(leftButton) == HIGH) {
    Keyboard.write('a');
    delay(500);
    Keyboard.release('a');
  }
  if (digitalRead(rightButton) == HIGH) {
    Keyboard.write('d');
    delay(500);
    Keyboard.release('d');
  }

}
