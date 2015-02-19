/**
https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/using-dc-motors

**/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

void setup() {
  // put your setup code here, to run once:
  Adafruit_MotorShield AFMS = Adafruit_MotorShield();
  Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
  AFMS.begin();
  myMotor->setSpeed(255);
  myMotor-> run(FORWARD);
}

void loop() {
  // put your main code here, to run repeatedly:

}
