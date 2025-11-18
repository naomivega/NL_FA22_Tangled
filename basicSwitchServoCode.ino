#include <Servo.h>
const int switchPin = 8;
Servo myservo;

bool hasMoved = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  myservo.attach(10);
  myservo.write(0);

}

void loop() { //scene 1 banners moving down
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH&& !hasMoved){
    myservo.write(90);
    hasMoved = true;
  }

}
