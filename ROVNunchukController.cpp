#include "Common.h"
#include "ROVNunchukController.h"


ROVNunchukController::ROVNunchukController(ROVControlAlgorithm &algorithm) : 
  m_rovControlAlgorithm(algorithm), 
  m_arduinoNunchuk() 

{
}

void ROVNunchukController::initialize()

{
  Serial.println("Initializing Nunchuk Controller....");
  m_arduinoNunchuk.init();
}
    
void ROVNunchukController::setControlAlgorithm(ROVControlAlgorithm &algorithm)
{
  m_rovControlAlgorithm = algorithm;
}

ROVMotorSettings ROVNunchukController::motorSettings()

{
  m_arduinoNunchuk.update();
  return m_rovControlAlgorithm.motorSettings(m_arduinoNunchuk);
}
