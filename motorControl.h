/*
 * motorControl.h
 *
 *      Author: evander
 * 
 * A set of functions to help setup and use the quad's motors.
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_



/**
 * TODO
 * 1) How to hardcode motor pins? Simply use global functions and make the pulseMotor function parameterless in terms of pins?
 */

unsigned long zeroTimer, timerThrottleOut, escLoopTimer;
unsigned long motorTimerOne, motorTimerTwo, motorTimerThree, motorTimerFour;

//Pin map
uint8_t pinOne = B00000010, pinTwo = B00001000, pinThree = B00001000, pinFour = B00000100;


void setupMotorPins(uint8_t pin)
{
  /*
   * sets up the data direction registers for motor pins 1, 2, 3, and 4
   * pin 1 = digital pin 9 = PB1
   * pin 2 = digital pin 3 = PD3
   * pin 3 = digital pin 10 = PB2
   * pin 4 = digital pin 11 = PB3
   * The confusing nature of pin numbering is because of the weird way
   * multiwii has chosen to layout its PWM pins.
   */
    DDRB |= (pinOne | pinThree | pinFour);
    DDRD |= pinTwo;
}


void pulseMotors(unsigned long durOne, unsigned long durTwo, unsigned long durThree, unsigned long durFour)
{

  /*
   * pulses each motor on pins One - Four with relevant duration 'dur*'
   * For example, this will pulse pinOne with durOne simultaneously with all other pins 
   * and their durations.
   */
  bool oneOn = 1, twoOn = 1, threeOn = 1, fourOn = 1;  
  zeroTimer = micros();
  PORTB |= (pinOne | pinThree | pinFour); //turn on D9, D11, and D10 pins which are on portB
  PORTD |= pinTwo; // turn on D3 pin which is on portD
  motorTimerOne = zeroTimer + durOne;
  motorTimerTwo = zeroTimer + durTwo;
  motorTimerThree = zeroTimer + durThree;
  motorTimerFour = zeroTimer + durFour;

  while(oneOn || twoOn || threeOn || fourOn)
  {
    escLoopTimer = micros();
    if(escLoopTimer >= motorTimerOne)
    {
      PORTB &= !pinOne;
      oneOn = 0;
    }
    if(escLoopTimer >= motorTimerTwo)
    {
      PORTD &= !pinTwo;
      twoOn = 0;
    }
    if(escLoopTimer >= motorTimerThree)
    {
      PORTB &= !pinThree;
      threeOn = 0;
    }
    if(escLoopTimer >= motorTimerFour)
    {
      PORTB &= !pinFour;
      fourOn = 0;
    }
  }
}

#endif /* MOTORCONTROL_H_ */
