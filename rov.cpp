/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Example uses a static library to show off generate_arduino_library().
 
  This example code is in the public domain.
 */
#include "Common.h"
#include <Wire.h>
#include <ArduinoNunchuk.h>

#include "Common.h"

#include "ROVNunchukController.h"
#include "ROVAlgorithms.h"
#include "ROVMotorController.h"


#define BAUDRATE 19200

ROVSimpleControlAlgorithm algorithm = ROVSimpleControlAlgorithm();
ROVNunchukController controller = ROVNunchukController(algorithm);
ROVTB6612FNGMotorController motorController = ROVTB6612FNGMotorController();

void setup() 

{                
  Serial.begin(BAUDRATE);
  Serial.println("Hello World");

  controller.initialize();
}

void loop() 
{
  ROVMotorSettings settings = controller.motorSettings();
  motorController.setMotors(settings);
}
