#include "StepperHomeLib.h"

StepperHome::StepperHome(int dir, int step, int en, int sensor) {
  dirPin = dir;
  stepPin = step;
  enPin = en;
  homeSensorPin = sensor;

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(homeSensorPin, INPUT_PULLUP);

  digitalWrite(enPin, LOW); // Enable motor driver
  Serial.begin(9600);
}

void StepperHome::resetHome() {
  Serial.println("Homing...");
  digitalWrite(dirPin, LOW);

  while (digitalRead(homeSensorPin) == HIGH) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(50);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(50);
  }

  Serial.println("Home position reached.");
}

void StepperHome::moveSteps(int steps, int dir) {
  digitalWrite(dirPin, dir);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(50);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(50);
  }
}