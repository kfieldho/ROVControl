/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Example uses a static library to show off generate_arduino_library().
 
  This example code is in the public domain.
 */
#include <Wire.h>
#include <ArduinoNunchuk.h>

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {                
  Serial.begin(BAUDRATE);
  nunchuk.init();
}

void loop() {
  nunchuk.update();

  Serial.print("X ");
  Serial.print(nunchuk.analogX, DEC);
  Serial.print(" Y ");
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(" aX ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(" aY ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(" aZ ");
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(" zB ");
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(" cB ");
  Serial.println(nunchuk.cButton, DEC);
  delay(2000);
}
