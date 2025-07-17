#ifndef STEPPERHOMELIB_H
#define STEPPERHOMELIB_H

#include <Arduino.h>

class StepperHome {
  private:
    int dirPin;
    int stepPin;
    int enPin;
    int homeSensorPin;

  public:
    StepperHome(int dir, int step, int en, int sensor);
    void resetHome();
    void moveSteps(int steps, int dir);
};

#endif