#pragma config(Motor,  port7,           motorLeft,     tmotorVex269_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           motorRight,    tmotorVex393_MC29, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true){
			motor[port7] = vexRT[Ch3];
			motor[port8] = vexRT[Ch2];
	}
}
