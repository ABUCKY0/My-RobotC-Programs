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
	writeDebugStreamLine("is bIfiAutonomousMode enabled: %d", bIfiAutonomousMode);
	writeDebugStreamLine("");
	writeDebugStreamLine("Battery Voltage: %f %f", nImmediateBatteryLevel/1000.0, nSysTime);
	writeDebugStreamLine("");
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

	float mla = 1;
	int speedAltering = 2;
	int speed = 100 / speedAltering;
	int tileDistance = 2450 * speedAltering;
	writeDebugStreamLine("Speed is set to %i, tileDistance is set to %i", speed, tileDistance);

		//driving for two tiles
		motor[motorRight] = speed;
		motor[motorLeft] = speed* mla;
		wait1Msec(tileDistance * 2);

		motor[motorRight] = speed;
		motor[motorLeft] = -1 * speed * mla;
		wait1Msec(750 * 1.7);

		//driving for one tile
		motor[motorRight] = speed;
		motor[motorLeft] = speed * mla;
		wait1Msec(tileDistance);

		motor[motorRight] = speed;
		motor[motorLeft] = -1 * speed * mla;
		wait1Msec(750 * 1.7);




	writeDebugStreamLine("Program has Ended");
}
