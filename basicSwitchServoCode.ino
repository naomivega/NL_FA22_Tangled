#include <Servo.h>

const int scene1Pin = A0;
const int scene2Pin = A1;
const int scene3Pin = A2;
const int scene4Pin = A3;
const int scene5Pin = A4;  // LED trigger

const int ledPin = 9;      // controls all 3 LEDs

Servo servo1;  // scene 1
Servo servo2;  // scene 2
Servo servo3;  // scene 3
Servo servo4;  // scene 4 360 servo

bool scene1Done = false;
bool scene2Done = false;
bool scene3Done = false;
bool scene4Done = false;
bool scene5Done = false;

void setup() {

  pinMode(scene1Pin, INPUT);
  pinMode(scene2Pin, INPUT);
  pinMode(scene3Pin, INPUT);
  pinMode(scene4Pin, INPUT);
  pinMode(scene5Pin, INPUT);

  // servos
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(10);

  // LEDs
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {

  // scene1: snappy movement for banners
  if (!scene1Done && digitalRead(scene1Pin) == HIGH) {
    for (int pos = 0; pos <= 90; pos++) {
      servo1.write(pos);
      delay(5); //speed
    }
    scene1Done = true;
  }

  // scene2: girls move back and forth
  if (!scene2Done && digitalRead(scene2Pin) == HIGH) {
    for (int pos = 40; pos <= 140; pos++) {
      servo2.write(pos);
      delay(10);
      if (digitalRead(scene2Pin) == LOW) break; 
    }
    if (digitalRead(scene2Pin) == HIGH) {
      for (int pos = 140; pos >= 40; pos --) {
        servo2.write(pos);
        delay(10);
        if (digitalRead(scene2Pin) == LOW) break;
      }
    }
  } else if (!scene2Done && digitalRead(scene2Pin) ==LOW) {
    servo2.write(90);
    scene2Done = true;
  }

  // scene3: guards slowly move towards rapunzel and flynn
  if (!scene3Done && digitalRead(scene3Pin) == HIGH) {
    for (int pos =0; pos <=90; pos++) {
      servo3.write(pos);
      delay(30);
    }
    scene3Done = true;
  }

  // scene4: crowd continuously rotates, dancing
  if (!scene4Done) {
    if (digitalRead(scene4Pin) == HIGH) {
      servo4.write(180);
    } else if (scene4Done == false) {
      servo4.write(90);
      scene4Done = true;
    }
  }

  // scene5; lanterns turn on
  if (!scene5Done && digitalRead(scene5Pin) == HIGH) {
    digitalWrite(ledPin, HIGH);   // turns on all LEDs
    scene5Done = true;            // stay on forever
  }
}
