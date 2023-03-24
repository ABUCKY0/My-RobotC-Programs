#pragma config(Sensor, dgtl1,  LEDgreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LEDyellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  LEDred,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  jumperrController, sensorDigitalIn)
#pragma config(Motor,  port1,           motorRight,    tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawControl,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,          motorLeft,     tmotorVex393_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void Go(int distance) {
	if (distance > 0) {
		motor[motorLeft] = 127;
		motor[motorRight] = 127;
		wait(distance * 2);
	}
	else {
		if (distance > 0) {
		motor[motorLeft] = -127;
		motor[motorRight] = -127;
		wait(distance * 2);
	}
	}
}
task main()
{


Go(1);
}
