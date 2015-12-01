/*
 * utils.h
 *
 *      Author: evander
 *      
 * This library is meant to hold general utility functions..
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <Wire.h>


void writeTo(int DEVICE, byte address, byte val) 
{
  /*
   * Custom I2C function to write data to a certain device.
   */
  Wire.beginTransmission(DEVICE); //start transmission to ACC
  Wire.write(address);        // send register address
  Wire.write(val);        // send value to write
  Wire.endTransmission(); //end transmission
}



 void readFrom(int DEVICE, byte address, int num, byte buff[]) 
 {
  /*
   * Custom I2C function to read data from a certain device.
   * Reads 'num' bytes starting from 'address' register in to the 'buff' array
   */
   Wire.beginTransmission(DEVICE); //start transmission to ACC
   Wire.write(address);        //sends address to read from
   Wire.endTransmission(); //end transmission
  
   Wire.beginTransmission(DEVICE); //start transmission to ACC
   Wire.requestFrom(DEVICE, num);    // request 6 bytes from ACC
  
   int i = 0;
   while(Wire.available())    //ACC may send less than requested (abnormal)
   {
     buff[i] = Wire.read(); // receive a byte
     i++;
   }
   Wire.endTransmission(); //end transmission
}

#endif /* UTILS_H_ */
