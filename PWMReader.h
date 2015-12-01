/*
 * PWMReader.h
 *
 *      Author: evander
 *      
 * Set of functions designed to read PWM signals either from 
 * RX controller or RPi
 */

#ifndef PWMREADER_H_
#define PWMREADER_H_

#include<avr/io.h>

#define byte uint8_t

//TODO
// Experiment with passing pointers in the interrupt function and see how that messes with timing (use cached variables and such)
//1) Make it so that setupPins automatically knows which registers and masks to use given a set of pins


//required global variables
unsigned long throttlePWMWidth, rollPWMWidth, yawPWMWidth, pitchPWMWidth;
unsigned long timerThrottle, timerRoll, timerYaw, timerPitch;
int throttlePinState = 0, rollPinState = 0, yawPinState = 0, pitchPinState = 0;
byte throttlePin = 4, rollPin = 16, pitchPin = 32, yawPin = 64;

void setupRXPins()
{
  /**Pins PCINT18 - PCINT20 read digital
     inputs from the RX receiver. These are
     pulse width modulated from 0 - 2000 ms.

     The atmel requires the PCIE2 bit in the
     PCICR register to be high for setting
     up interrupt monitoring on the required pins.

     Additionally, the PCMSK2 register needs to
     set the appropriate bits high to monitor
     individual pins for interrupts.
   **/
    PCICR |= 1 << PCIE2;
    PCMSK2 |= 1 << PCINT18;
    PCMSK2 |= 1 << PCINT20;
    PCMSK2 |= 1 << PCINT21;
    PCMSK2 |= 1 << PCINT22;
}

void PulseWidthInterrupts(unsigned long timer)
{

  /**For speed of execution, all PWM interrupts
  must be declared like this, cannot modularise
  because cross-module calls takes unnecessary time.

  This means that PWM readers for interrupts on the
  throttle, pitch, roll and yaw channels must be implemented
  individually as shown below.

  Parameters
  ----------
  unsigned long timer : Current time.
  **/

  /* -----------------Throttle handler ------------------*/
  if(throttlePinState == 0 && (PIND & throttlePin))
  {
    /*if the throttle pin's state was 0, but
      the interrupt handler has detected that it
      has changed to 1 in the PIND register*/
    throttlePinState = 1;
    timerThrottle = timer;    //set the PWMWidth to current time
  }

  else if(throttlePinState == 1 && !(PIND & throttlePin))
  {
    /*if the throttle pin's state was 1, but
      the interrupt handler has detected a
      falling edge in the PIND register*/
    throttlePinState = 0;
    throttlePWMWidth = timer - timerThrottle; //measure time from
                                        //leading edge to falling edge
                                        //and store as PWM Width
  }
  /*------------------------------------------------------*/


  /*---------------------Roll handler--------------------*/
  if(rollPinState == 0 && (PIND & rollPin))
  {
    rollPinState = 1;
    timerRoll = timer;
  }

  else if(rollPinState == 1 && !(PIND & rollPin))
  {
    rollPinState = 0;
    rollPWMWidth = timer - timerRoll;
  }
  /*------------------------------------------------------*/


  /*--------------------Pitch Handler---------------------*/
  if(pitchPinState == 0 && (PIND & pitchPin))
  {
    pitchPinState = 1;
    timerPitch = timer;
  }

  else if(pitchPinState == 1 && !(PIND & pitchPin))
  {
    pitchPinState = 0;
    pitchPWMWidth = timer - timerPitch;
  }
  /*-------------------------------------------------------


  /*--------------------yaw handler----------------------*/
  if(yawPinState == 0 && (PIND & yawPin))
  {
    yawPinState = 1;
    timerYaw = timer;
  }

  else if(yawPinState == 1 && !(PIND & yawPin))
  {
    yawPinState = 0;
    yawPWMWidth = timer - timerYaw;
  }
  /*------------------------------------------------------*/
}

#endif /* PWMREADER_H_ */
