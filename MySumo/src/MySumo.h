#ifndef MySumo_h
#define MySumo_h

#include <Arduino.h>

class MySumo {
  public:
    MySumo(int motorA1, int motorA2, int motorB1, int motorB2, int HCSRTrig, int HCSREcho);
    MySumo(int motorA1, int motorA2, int motorB1, int motorB2);
    MySumo();
    void init();
    void setMotors(int v1, int v2);
    float read_distance();

  private:
    int _motorA1;
    int _motorA2;
    int _motorB1;
    int _motorB2;
    int _HCSRTrig;
    int _HCSREcho;
};

#endif