#pragma config(Sensor, dgtl1,  LEDgreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LEDyellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  LEDred,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  jumperrController, sensorDigitalIn)
#pragma config(Motor,  port1,           motorRight,    tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawControl,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,         motorLeft,     tmotorVex393_HBridge, openLoop, driveLeft)





task main()
{
	float mla = 1;
	int speedAltering = 2;
	int speed = 100 / speedAltering;
	int tileDistance = 2450 * speedAltering;

	motor[motorRight] = speed;
	motor[motorLeft] = -1 * speed * mla;
	wait1Msec(637.5);
}
