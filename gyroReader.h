/*
 * gyroReader.h
 *
 *      Author: evander
 * 
 * Buggy as shit reader for the gyro on the multiwii.
 * Still needs extensive testing.
 */

#ifndef GYROREADER_H_
#define GYROREADER_H_

#include "utils.h"


// Gyroscope ITG3200
#define GYRO 0x68 //  when AD0 is connected to GND ,gyro address is 0x68.
//#define GYRO 0x69   //when AD0 is connected to VCC ,gyro address is 0x69
#define G_SMPLRT_DIV 0x15
#define G_DLPF_FS 0x16
#define G_INT_CFG 0x17
#define G_PWR_MGM 0x3E
#define G_TO_READ 8 // 2 bytes for each axis x, y, z
// offsets are chip specific.
int g_offx = 20;
int g_offy = 20;
int g_offz = 7;
int hx, hy, hz, turetemp;


//initializes the gyroscope
void setupGyro()
{
 /**
 * ITG 3200
 * power management set to:
 * clock select = internal oscillator
 * no reset, no sleep mode
 * no standby mode
 * sample rate to = 125Hz
 * parameter to +/- 2000 degrees/sec
 * low pass filter = 5Hz
 * no interrupt
 **/
 writeTo(GYRO, G_PWR_MGM, 0x00);
 writeTo(GYRO, G_SMPLRT_DIV, 0x07); // EB, 50, 80, 7F, DE, 23, 20, FF
 writeTo(GYRO, G_DLPF_FS, 0x1E); // +/- 2000 dgrs/sec, 1KHz, 1E, 19
 writeTo(GYRO, G_INT_CFG, 0x00);
}


void getGyroData(int * result)
{
 /**************************************
 Gyro ITG-3200 I2C
 registers:
 temp MSB = 1B, temp LSB = 1C
 x axis MSB = 1D, x axis LSB = 1E
 y axis MSB = 1F, y axis LSB = 20
 z axis MSB = 21, z axis LSB = 22
 *************************************/
 int regAddress = 0x1B;
 int temp, x, y, z;
 byte buff[G_TO_READ];
 readFrom(GYRO, regAddress, G_TO_READ, buff); //read the gyro data from the ITG3200
 result[0] = ((buff[2] << 8) | buff[3]) + g_offx; //x-rate
 result[1] = ((buff[4] << 8) | buff[5]) + g_offy; //y-rate
 result[2] = ((buff[6] << 8) | buff[7]) + g_offz; //z-rate
 result[3] = (buff[0] << 8) | buff[1]; // temperature
 }


#endif /* GYROREADER_H_ */
