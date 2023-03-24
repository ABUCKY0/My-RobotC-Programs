#pragma config(Sensor, dgtl1,  LEDgreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LEDyellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  LEDred,         sensorLEDtoVCC)
#pragma config(Motor,  port1,           motorRight,    tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawControl,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,          motorLeft,     tmotorVex393_HBridge, openLoop, driveLeft)

task main()
{
	while (true) {
		motor[motorLeft] = vexRT[Ch3]/2 - vexRT[Ch4]/2;
		motor[motorRight] = vexRT[Ch3]/2 + vexRT[Ch4]/2;
	}


}
