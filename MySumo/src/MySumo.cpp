#include "MySumo.h"

MySumo::MySumo(int motorA1, int motorA2, int motorB1, int motorB2, int HCSRTrig, int HCSREcho) {
  _motorA1 = motorA1;
  _motorA2 = motorA2;
  _motorB1 = motorB1;
  _motorB2 = motorB2;
  _HCSRTrig = HCSRTrig;
  _HCSREcho = HCSREcho;
}

MySumo::MySumo(int motorA1, int motorA2, int motorB1, int motorB2) {
  _motorA1 = motorA1;
  _motorA2 = motorA2;
  _motorB1 = motorB1;
  _motorB2 = motorB2;
  _HCSRTrig = 14;
  _HCSREcho = 12;
}

MySumo::MySumo() {
  _motorA1 = 4;
  _motorA2 = 5;
  _motorB1 = 0;
  _motorB2 = 2;
  _HCSRTrig = 14;
  _HCSREcho = 12;
}

void MySumo::init() {
  pinMode(_motorA1, OUTPUT);
  pinMode(_motorA2, OUTPUT);
  pinMode(_motorB1, OUTPUT);
  pinMode(_motorB2, OUTPUT);
  pinMode(_HCSRTrig, OUTPUT);
  pinMode(_HCSREcho, INPUT);
}

float MySumo::read_distance(){
  long duracion;
  float distancia;
  digitalWrite(_HCSRTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(_HCSRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_HCSRTrig, LOW);
  duracion = pulseIn(_HCSREcho, HIGH, 26000);
  distancia = (duracion / 2.0) / 29.1;
  if(distancia == 0) distancia = 450;
  return distancia;
}

void MySumo::setMotors(int v1, int v2) {
  if (v1 != 0) {
    int s1 = v1 / abs(v1);
    if (abs(v1) > 100) v1 = 100 * s1;
    v1 = map(v1 * s1, 0, 100, 0, 255);
    if (s1 > 0) {
      analogWrite(_motorA1, v1);
      digitalWrite(_motorA2, LOW);
    } else {
      analogWrite(_motorA2, v1);
      digitalWrite(_motorA1, LOW);
    }
  } else {
    digitalWrite(_motorA1, LOW);
    digitalWrite(_motorA2, LOW);
  }

  if (v2 != 0) {
    int s2 = v2 / abs(v2);
    if (abs(v2) > 100) v2 = 100 * s2;
    v2 = map(v2 * s2, 0, 100, 0, 255);
    if (s2 > 0) {
      analogWrite(_motorB1, v2);
      digitalWrite(_motorB2, LOW);
    } else {
      analogWrite(_motorB2, v2);
      digitalWrite(_motorB1, LOW);
    }
  } else {
    digitalWrite(_motorB1, LOW);
    digitalWrite(_motorB2, LOW);
  }
}
