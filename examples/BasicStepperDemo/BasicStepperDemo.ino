#include <StepperHomeLib.h>

StepperHome motor(2, 5, 8, 7);

void setup() {
  motor.resetHome();
  delay(1000);
}

void loop() {
  motor.moveSteps(20000, HIGH);
  delay(1000);
  motor.moveSteps(20000, LOW);
  delay(1000);
}