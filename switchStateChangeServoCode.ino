#include <Servo.h>
const int switchPin = 8;

int switchVal = 0;
int prevSwitchVal = 0;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  myservo.attach(10);
  myservo.write(0);

}

void loop() {
  switchVal = digitalRead(switchPin);

  if (switchVal != prevSwitchVal){
    if (switchVal == HIGH){
      myservo.write(180);
    }
  }

  prevSwitchVal = switchVal;
}
