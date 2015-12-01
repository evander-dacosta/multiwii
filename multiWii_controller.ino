#include "Arduino.h"
#include "PWMReader.h"
#include "motorControl.h"


//TODO: IMPLEMENT PID! from throttle inputs -> pitch, roll, yaw


void setup()
{
    setupMotorPins();
    setupRXPins();
    zeroTimer = micros();
}



void loop()
{
  while(zeroTimer + 4000 > micros());                       //Start the pulse after 4000 micro seconds.
  pulseMotors(throttlePWMWidth, throttlePWMWidth,throttlePWMWidth,throttlePWMWidth);

}


ISR(PCINT2_vect)
{
   PulseWidthInterrupts(micros());
}
