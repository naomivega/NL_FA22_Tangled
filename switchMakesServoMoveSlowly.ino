#include <Servo.h>
const int switchPin = 8;
Servo myservo;
int servoAngle = 0;
float servoSpeed = 0.5;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  myservo.attach(10);
  myservo.write(servoAngle);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH){
    if (servoAngle < 180){
      servoAngle += servoSpeed;
    }
  } else {
    servoAngle = 0;  
  }
  myservo.write(servoAngle);

}
