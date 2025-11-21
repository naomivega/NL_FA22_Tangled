#include <Servo.h>

// Copper tape trigger pins
const int scene1Pin = 2;
const int scene2Pin = 3;
const int scene3Pin = 4;
const int scene4Pin = 5;
const int scene5Pin = 6;

// Servos
Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 

// Scene completion flags
bool scene1Done = false;
bool scene2Done = false;
bool scene3Done = false;
bool scene4Done = false;
bool scene5Done = false;

void setup() {
  // Input pins
  pinMode(scene1Pin, INPUT);
  pinMode(scene2Pin, INPUT);
  pinMode(scene3Pin, INPUT);
  pinMode(scene4Pin, INPUT);
  pinMode(scene5Pin, INPUT);

  // Attach servos
  servo1.attach(10);  servo1.write(0);
  servo2.attach(11);  servo2.write(90);
  servo3.attach(12);  servo3.write(0);
  servo4.attach(13);  servo4.write(40);
  servo5.attach(14);  servo5.write(180);
}

void loop() {

  // scene 1
  if (!scene1Done && digitalRead(scene1Pin) == HIGH) {
    for (int pos = 0; pos <= 90; pos++) {
      servo1.write(pos);
      delay(15);
    }
    scene1Done = true;
  }

  // scene 2
  if (!scene2Done && digitalRead(scene2Pin) == HIGH) {

    // Back and forth sweep for 15 seconds
    unsigned long start = millis();
    while (millis() - start < 15000) {
      for (int pos = 10; pos <= 170; pos++) {
        servo2.write(pos);
        delay(10);
      }
      for (int pos = 170; pos >= 10; pos--) {
        servo2.write(pos);
        delay(10);
      }
    }

    scene2Done = true;
  }

  // scene 3
  if (!scene3Done && digitalRead(scene3Pin) == HIGH) {

    for (int pos = 0; pos <= 90; pos++) {
      servo3.write(pos);
      delay(20);
    }

    scene3Done = true;
  }

  // scene 4
  if (!scene4Done && digitalRead(scene4Pin) == HIGH) {

    int leftPos  = 40;
    int rightPos = 140;

    for (int i = 0; i < 12; i++) {
      servo4.write(leftPos);
      delay(120);
      servo4.write(rightPos);
      delay(120);
    }

    servo4.write(90);
    scene4Done = true;
  }

  // scene 5
  if (!scene5Done && digitalRead(scene5Pin) == HIGH) {

    for (int pos = 180; pos >= 0; pos--) {
      servo5.write(pos);
      delay(40);
    }

    scene5Done = true;
  }
}
