#include <Servo.h>

const int switchPin = 8;
Servo servo1; //scene 1
Servo servo2; //scene 2
Servo servo3; //scene 3

bool hasMoved = false;
bool secondStarted = false;
bool thirdStarted = false;

unsigned long servo1FinishTime = 0;
unsigned long servo2StartTime = 0;

void setup() {
  pinMode(switchPin, INPUT);
  
  servo1.attach(10); //first scene servo
  servo1.write(0);

  servo2.attach(11); //second scene servo
  servo2.write(90);

  servo3.attach(12); //third scene servo
  servo3.write(0);
}

void loop() { 
  //scene 1 banners moving down
  if (digitalRead(switchPin) == HIGH&& !hasMoved){

    for (int pos = 0; pos <= 90; pos++) {
      servo1.write(90);
      delay(15);
    }
    
    hasMoved = true;
    servo1FinishTime = millis(); //marking when scene 1 is over
  }
  //prep for scene 2 to start 10 seconds after scene 1
  if (hasMoved && !secondStarted) {
    if (millis() - servo1FinishTime >= 10000) {
      secondStarted = true;
      servo2StartTime = millis(); //mark when scene 2 starts
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

  if (secondStarted && !thirdStarted) {
    if (millis() - servo2StartTime >= 15000) {
      thirdStarted = true;
    }
  }

 if (thirdStarted) {
    for (int pos = 0; pos <= 90; pos++) {
      servo3.write(pos);
      delay(20);
    }
    thirdStarted = false;
  }
}

//Scene 4
// dancing scene, moving left to right, repeating
  if (scene2Done && !scene3Done && (millis() - scene2FinishTime >= 5000UL)) {
    int leftPos  = 40;   // tweak these angles for your setup
    int rightPos = 140;

    // wiggle back and forth 12 times
    for (int i = 0; i < 12; i++) {
      servo3.write(leftPos);
      delay(120);       // smaller delay = faster
      servo3.write(rightPos);
      delay(120);
    }

    // park in the middle
    servo3.write(90);

    scene3Done = true;
    scene3FinishTime = millis();
  }
//Scene 5
// Lantern Scene, one slow sweep from right to left, and then stop
  if (scene3Done && !scene4Done && (millis() - scene3FinishTime >= 5000UL)) {
    // assume right = 180°, left = 0°
    for (int pos = 180; pos >= 0; pos--) {
      servo4.write(pos);
      delay(40);        // bigger delay = slower movement
    }

    // stays at 0° (left) and does NOT move again
    scene4Done = true;
  }
}
