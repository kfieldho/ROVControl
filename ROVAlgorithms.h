/* 
 * File to hold different Nunchuk-->Motor Algorithms
 */

#ifndef ROVAlgorithms_H
#define ROVAlgorithms_H

#include "ROVNunchukController.h"

class ROVSimpleControlAlgorithm : public ROVControlAlgorithm {
  public:
    ROVSimpleControlAlgorithm();
    virtual ROVMotorSettings motorSettings(ArduinoNunchuk &nunchuk);
};

#endif
