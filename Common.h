/*
 *  Common include file for ROVControlelr
 */

#ifndef Common_H
#define Common_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define DEBUG true
#define Serial if (DEBUG)Serial

#endif
