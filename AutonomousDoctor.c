#pragma config(Sensor, dgtl1,  LEDgreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LEDyellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  LEDred,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  jumperrController, sensorDigitalIn)
#pragma config(Motor,  port1,           motorRight,    tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawControl,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,          motorLeft,     tmotorVex393_HBridge, openLoop, driveLeft)

/*
Project Title:
Team Members:
Date: 2/3/22 - 2/8/22
Section: Robotics I 3RD Period


Task Description:
Write autonomous code that will traverse the provided hospital layout, traveling from the pharmacy to a room and back again, across two stories.

Pseudocode:
Travel from start to pharmacy
Grab Bottle
Wait 5 sec
Pharmacy to room one
Release bottle
Wait 3 sec
Room one to pharmacy
GRAB bottle
Wait 5 sec
Pharmacy to room two
Release bottle
Wait 3 sec
Room Two to Pharmacy
GRAB bottle
Wait 5 sec
Pharmacy to room 3
Release Bottle
Wait 3 sec
Room 3 to Elevator
Wait 5 sec
*/
void open() {
	motor[clawControl] = 127;
	wait1Msec(1000);
	SensorValue[dgtl1] = 1;
}
void close() {
	motor[clawControl] = -127;
	wait1Msec(1000);
	SensorValue[dgtl1] = 0;
}

void turnLeft() {
	motor[motorLeft] = 50;
	motor[motorRight] = -50;
	wait1Msec(960); //1050 if dead
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
	wait(1);
}
void turnRight() {
	motor[motorLeft] = -50;
	motor[motorRight] =  50;
	wait1Msec(960);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
	wait(1);
}
void turnAround() {
	motor[motorLeft] = -1 * 50;
	motor[motorRight] =  50;
	wait1Msec(2250);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
}
void drive(float tiles) {
	motor[motorRight] = 50;
	motor[motorLeft] = 50;
	wait1Msec((1430 * tiles ) * 2);
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
}
void reverse(float tiles) {
	motor[motorRight] = -50;
	motor[motorLeft] = -50;
	wait1Msec((1430 * tiles) * 2);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
	}
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
/*turnRight();
wait(2);
turnLeft();*/
	// traveling from start to pharmacy
	drive(1.7);
	//turning onto main hallway
	turnLeft();
	// traveling down main hallway
	drive(1.0);
	//turning to face pharmacy
	turnRight();
	//driving into pharmacy
	open();
	drive(1);
	wait(5);
	close();
	//from pharmacy to first room
	reverse(1.5);
	turnAround();
	drive(1);
	//dropping bottle
	open();
	wait(5);
	//back to pharmacy
	reverse(1);
	turnAround();
	wait(.5);
	drive(1.5);
	close();

	wait(5);
	//to patient room two
	reverse(1.5);
	turnRight();
	drive(.5);
	turnLeft();
	wait(.5);
	drive(1.5);
	open();
	wait(5);
	//to start
	reverse(1.5);
	turnRight();
	drive(.5);
	turnRight();
	drive(1);
	turnAround();
	/*
	//back to pharmacy
	reverse(1
	);
	turnLeft();
	wait(.5);
	drive(1);
	turnRight();
	wait(.5);
	drive(1);
	close();
	wait(5);
	//to final paitent room
	reverse(1.5);
	turnRight();
	wait(.5);
	drive(1);
	wait(.5);
	turnRight();
	drive(1.5);
	open();
	wait(5);
	reverse(1.5);*/

}
