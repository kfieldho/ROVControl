/*
 * Class to manage a Wii Nunchuk as an ROV Control head
 */

#ifndef ROVNunchukContoller_H
#define ROVNunchukContoller_H

#include <ArduinoNunchuk.h>
#include "ROVMotorController.h"

/*
 * Base class to encapsulate the algorithm that converts current Nunchuk settigns
 * to ROVMotorSettings.
 */
class ROVControlAlgorithm {
  public:
    ROVControlAlgorithm() {};
    virtual ROVMotorSettings motorSettings(ArduinoNunchuk &nunchuk) = 0;
};

/*
 * Class to manage the conversion of the current Nunchuk state into ROVMotorSettings using the 
 * current ROVControlAlgorithm.
 */
class ROVNunchukController
{
  public:
    ROVNunchukController(ROVControlAlgorithm &algorithm);

    /* Should be called once when the Nunchuk is at rest to get the center states */
    void initialize();

    /* Set the current Control Algorithm */
    void setControlAlgorithm(ROVControlAlgorithm &algorithm);

    /* Should be called in loop().  Returns the correct ROVMotorSettings for the current state of the 
     * Nunchuk and the current ROVControlAlgorithm
     */
    ROVMotorSettings motorSettings();

  private:
    ArduinoNunchuk m_arduinoNunchuk;
    ROVControlAlgorithm &m_rovControlAlgorithm;

};

#endif
