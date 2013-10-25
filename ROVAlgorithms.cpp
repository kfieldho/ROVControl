#include "ROVAlgorithms.h"

#define DEFAULT_CENTRE_JOY_X 124
#define DEFAULT_CENTRE_JOY_Y 132
#define DEFAULT_MIN_JOY_X 24
#define DEFAULT_MAX_JOY_X 230
#define DEFAULT_MIN_JOY_Y 24
#define DEFAULT_MAX_JOY_Y 230
#define ACCEL_ZEROX 490
#define ACCEL_ZEROY 500
#define ACCEL_ZEROZ 525

#define THRESHOLD 35

#define direction(x) (x < 0.0 ? -1 : 1)

ROVSimpleControlAlgorithm::ROVSimpleControlAlgorithm()

{  

}

ROVMotorSettings ROVSimpleControlAlgorithm::motorSettings(ArduinoNunchuk &nunchuk)

{
  float port = 0.0;
  float starboard = 0.0;
  float z = 0.0;

  // Get Direction and Magnitude off center
  int x = nunchuk.analogX - DEFAULT_CENTRE_JOY_X;
  int y = nunchuk.analogY - DEFAULT_CENTRE_JOY_Y;

  // Full ahead or reverse, both motors working together
  if ((abs(x) > THRESHOLD) && (abs(y) < THRESHOLD)) {
    port = starboard = (1.0 * direction(y));
  // Spin hard, reverse 1 motor, forward on the other
  } else if ((abs(x) < THRESHOLD) && abs(y) > THRESHOLD) {
    port = 1.0 * direction(y);
    starboard = -1.0 * direction(y);
  }
  // Slow turn with only engine in forward or reverse. 
  // Right turn (Quad I) is full port engine, a reverse left 
  // turn (Quad III) is full reverse on the port engine etc.
  else if ((abs(x) > THRESHOLD) && abs(y) > THRESHOLD) {
    // Quadrant I or III, manipulate the port motor
    if (direction(y) == direction(x)) {
      starboard = 0.0;
      port = 1.0 * direction(x);
    } else {
    // Quad II or IV, manipulate starboard motor
      starboard = 1.0 * direction(y);
      port = 1.0;
    }
  }

  ROVMotorSettings settings(port,starboard,z);
  return settings;
}
