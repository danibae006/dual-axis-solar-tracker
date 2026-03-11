// ============================================
// Project  : Dual-Axis Solar Tracker
// Author   : Daniel
// GitHub   : https://github.com/danibae006
// Repo     : https://github.com/danibae006/dual-axis-solar-tracker
//
// For wiring & connections, visit the repo
// above and read the README file.
// It contains full wiring diagrams,
// component list, and setup instructions.
// ============================================

#include <Servo.h>

Servo servoVert;
Servo servoHorz;

int topLDR    = A0;
int rightLDR  = A1;
int bottomLDR = A2;
int leftLDR   = A3;

int vertPos  = 90;
int horzPos  = 90;

int tolerance = 30;

void setup() {
  servoVert.attach(10);
  servoHorz.attach(9);
  servoVert.write(vertPos);
  servoHorz.write(horzPos);
  Serial.begin(9600);
}

void loop() {
  int top    = analogRead(topLDR);
  int right  = analogRead(rightLDR);
  int bottom = analogRead(bottomLDR);
  int left   = analogRead(leftLDR);

  int verticalDiff   = top - bottom;
  int horizontalDiff = left - right;

  Serial.print("T:");
  Serial.print(top);
  Serial.print(" B:");
  Serial.print(bottom);
  Serial.print(" L:");
  Serial.print(left);
  Serial.print(" R:");
  Serial.println(right);

  if (abs(verticalDiff) > tolerance) {
    if (top > bottom) {
      vertPos--;
    } else {
      vertPos++;
    }
    vertPos = constrain(vertPos, 0, 180);
    servoVert.write(vertPos);
  }

  if (abs(horizontalDiff) > tolerance) {
    if (left > right) {
      horzPos++;
    } else {
      horzPos--;
    }
    horzPos = constrain(horzPos, 0, 180);
    servoHorz.write(horzPos);
  }

  delay(100);
}
