/*
 * Classes for motor controller code
 */

#ifndef ROVMotorController_H
#define ROVMotorController_H

/*
 * Class to encapsulate derivied motor settings.  Values are floats between -1.0 and 1.0. Sign  indicates
 * direction.
 */
class ROVMotorSettings
{
  public:
    const float portMotor;
    const float starboardMotor;
    const float depthMotor;
  
    ROVMotorSettings(float port, float starboard, float depth) :
      portMotor(port), starboardMotor(starboard),depthMotor(depth) {}
};


/*
 * Base class for all Motor Controllers
 */
class ROVMotorController {
  public:
    ROVMotorController() {};
    virtual void setMotors(const ROVMotorSettings &settings) = 0;
};


/*
 * Simple controller class that simply logs it's settings
 */

class ROVLoggingMotorController : public ROVMotorController {
  public:
    ROVLoggingMotorController();
    virtual void setMotors(const ROVMotorSettings &settings);
};

/*
 *  Motor controller that uses a TB6612FNG Breakout board
 */

class ROVTB6612FNGMotorController : public ROVMotorController {
  public:
    ROVTB6612FNGMotorController();
    virtual void setMotors(const ROVMotorSettings &settings);
  private:
    void moveMotor(int motor, float speed);
};


#endif
