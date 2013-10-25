#include "Common.h"
#include "ROVMotorController.h"


ROVLoggingMotorController::ROVLoggingMotorController()

{
  Serial.println("ROVLoggingMotorController activated...");
}



void ROVLoggingMotorController::setMotors(const ROVMotorSettings &settings)
{
  Serial.print("Port: ");
  Serial.print(settings.portMotor);
  Serial.print(" Starboard: ");
  Serial.print(settings.starboardMotor);
  Serial.print(" Depth: ");
  Serial.println(settings.depthMotor);
}

int STBY = 10; //standby

// Starboard Motor
int PWMA = 3; //Speed control 
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

// Port Motor
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

#define PORT 1
#define STARBOARD 2

ROVTB6612FNGMotorController::ROVTB6612FNGMotorController()

{
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}


void ROVTB6612FNGMotorController::setMotors(const ROVMotorSettings &settings)

{
  Serial.print("Port: ");
  Serial.print(settings.portMotor);
  Serial.print(" Starboard: ");
  Serial.print(settings.starboardMotor);
  Serial.print(" Depth: ");
  Serial.println(settings.depthMotor);

  this->moveMotor(PORT,settings.portMotor);
  this->moveMotor(STARBOARD,settings.starboardMotor);
}


void ROVTB6612FNGMotorController::moveMotor(int motor, float speed)

{
  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (speed < 0.0) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if (motor == PORT) {
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, abs(speed) * 75);
  } else {
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, abs(speed) * 75);
  }
}
