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
	clearDebugStream();
	writeDebugStreamLine("Program is Starting");

	SensorValue[dgtl1] = 0;
	SensorValue[dgtl2] = 0;
	SensorValue[dgtl3] = 0;

	writeDebugStreamLine("Reset Lights at %2.2f", nPgmTime);

	SensorValue[dgtl3] = 1;
	wait1Msec(1000);
	SensorValue[dgtl2] = 1;
	wait1Msec(1000);
	SensorValue[dgtl1] = 1;

	//port1 - Right Motor
	//port10 - Left Motor
	int speed = 100;
	int tileDistance = 2500;

	//driving for one tile
	motor[motorRight] = speed;
	motor[motorLeft] = speed;
	wait1Msec(tileDistance);
	//reversing
	motor[motorRight] = speed * -1;
	motor[motorLeft] = speed * -1;
	wait1Msec(tileDistance);

	//driving for two tiles
	motor[motorRight] = speed;
	motor[motorLeft] = speed;
	wait1Msec(tileDistance * 2);
	//reversing
	motor[motorRight] = speed * -1;
	motor[motorLeft] = speed * -1;
	wait1Msec(tileDistance * 2);

	//driving for three tiles
	motor[motorRight] = speed;
	motor[motorLeft] = speed;
	wait1Msec(tileDistance * 4);
	//reversing
	motor[motorRight] = speed * -1;
	motor[motorLeft] = speed * -1;
	wait1Msec(tileDistance * 4);


	SensorValue[dgtl1] = 0;
	SensorValue[dgtl2] = 0;
	SensorValue[dgtl3] = 0;

}
