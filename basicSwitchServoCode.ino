#include <Servo.h>
const int switchPin = 8;
Servo servo1;
Servo servo2;

bool hasMoved = false;
bool secondStarted = false;

unsigned long servo1FinishTime = 0;

void setup() {
  pinMode(switchPin, INPUT);
  
  servo1.attach(10); //first scene servo
  servo1.write(0);

  servo2.attach(11); //second scene servo
  servo2.write(90);
}

void loop() { 
  //scene 1 banners moving down
  if (digitalRead(switchPin) == HIGH&& !hasMoved){

    for (int pos = 0; pos <= 990; pos++) {
      myservo.write(90);
      delay(15);
    }
    
    hasMoved = true;
    servo1FinishTime = millis(); //marking when scene 1 is over

  //prep for scene 2 to start 10 seconds after scene 1
  if (hasMoved && !secondStarted) {
    if (millis() - servo1FinishTime >= 10000) {
      secondStarted = true;
  }
}

//scene 2 hair braiding scene, girls move back and forth
if (secondStarted) {
  for (int pos = 10; pos <= 170; pos++) {
    servo2.write(pos);
    delay(10);
    }
  
  for (int pos = 170; pos >= 10; pos--) {
    servo2.write(pos);
    delay(10);
    }
  }
}

