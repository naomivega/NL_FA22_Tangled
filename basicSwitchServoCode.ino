#include <Servo.h>

const int switchPin = 8;

Servo servo1; //scene 1
Servo servo2; //scene 2
Servo servo3; //scene 3
Servo servo4; //scene 4
Servo servo5; //scene 5

//scene completion markers
bool scene1Done = false;
bool scene2Started = false;
bool scene2Done = false;
bool scene3Started = false;
bool scene3Done = false;
bool scene4Started = false;
bool scene4Done = false;
bool scene5Started = false;
bool scene5Done = false;

//timestamps
unsigned long scene1FinishTime = 0;
unsigned long scene2StartTime = 0;
unsigned long scene2FinishTime = 0;
unsigned long scene3StartTime = 0;
unsigned long scene3FinishTime = 0;
unsigned long scene4StartTime = 0;
unsigned long scene4FinishTime = 0;

void setup() {
  pinMode(switchPin, INPUT);

  servo1.attach(10);
  servo1.write(0);

  servo2.attach(11);
  servo2.write(90);

  servo3.attach(12);
  servo3.write(0);

  servo4.attach(13);
  servo4.write(40);

  servo5.attach(14);
  servo5.write(180);
}

void loop() {

  // SCENE 1
  if (!scene1Done && digitalRead(switchPin) == HIGH) {
    for (int pos = 0; pos <= 90; pos++) {
      servo1.write(pos);
      delay(15);
    }
    scene1Done = true;
    scene1FinishTime = millis();
  }

  // SCENE 2 (start 10 seconds after scene 1)
  if (scene1Done && !scene2Started && millis() - scene1FinishTime >= 10000UL) {
    scene2Started = true;
    scene2StartTime = millis();
  }

  if (scene2Started && !scene2Done) {

    //back and forth
    for (int pos = 10; pos <= 170; pos++) {
      servo2.write(pos);
      delay(10);
    }
    for (int pos = 170; pos >= 10; pos--) {
      servo2.write(pos);
      delay(10);
    }

    if (millis() - scene2StartTime >= 15000UL) {
      scene2Done = true;
      scene2FinishTime = millis();
    }
  }

  // SCENE 3 (start 10 seconds after scene 2)
  if (scene2Done && !scene3Started && millis() - scene2FinishTime >= 10000UL) {
    scene3Started = true;
    scene3StartTime = millis();
  }

  if (scene3Started && !scene3Done) {

    for (int pos = 0; pos <= 90; pos++) {
      servo3.write(pos);
      delay(20);
    }

    scene3Done = true;
    scene3FinishTime = millis();
  }

  // SCENE 4 (start 5 sec after scene 3)
  if (scene3Done && !scene4Started && millis() - scene3FinishTime >= 5000UL) {
    scene4Started = true;
    scene4StartTime = millis();
  }

  if (scene4Started && !scene4Done) {

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
    scene4FinishTime = millis();
  }

  // SCENE 5 (start 5 sec after scene 4)
  if (scene4Done && !scene5Started && millis() - scene4FinishTime >= 5000UL) {
    scene5Started = true;
  }

  if (scene5Started && !scene5Done) {
    for (int pos = 180; pos >= 0; pos--) {
      servo5.write(pos);
      delay(40);
    }
    scene5Done = true;
  }
}
