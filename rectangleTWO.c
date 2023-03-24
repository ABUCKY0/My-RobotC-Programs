#pragma config(Sensor, dgtl1,  LEDgreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LEDyellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  LEDred,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  jumperrController, sensorDigitalIn)
#pragma config(Motor,  port1,           motorRight,    tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawControl,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,         motorLeft,     tmotorVex393_HBridge, openLoop, driveLeft)
void turnRight() {
	motor[motorRight] = 50;
	motor[motorLeft] = -1 * 50;
	wait1Msec(960);
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
}
void turnLeft() {
	motor[motorRight] = -1 * 50;
	motor[motorLeft] = 50;
	wait1Msec(960);
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
}

void goForwards() {
	motor[motorRight] = 50;
	motor[motorLeft] = 50;
	wait1Msec(3250);
}



task main()
{

goForwards();
goForwards();
turnLeft();
goForwards();
turnLeft();
goForwards();
goForwards();
turnLeft();
goForwards();
turnLeft();
}
