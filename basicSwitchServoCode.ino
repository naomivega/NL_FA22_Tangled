#include <Servo.h>
const int switchPin = 8;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  myservo.attach(10);
  myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH){
    myservo.write(180);
  } else {
    myservo.write(0);
  }

}
