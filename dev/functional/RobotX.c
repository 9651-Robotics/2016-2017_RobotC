#pragma config(Motor,  port2,           rightDrive,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           middleDrive,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftArm,       tmotorVex393_MC29, openLoop)
#define DEADZONE 20
// Sides are defined as if you were looking from the back of the robot
// Compare tmotorVmotor VS tmotorVex393
// Motors on the left and right drive train Vex 269s
// Take care when adding arm motors as this created problems compiling last time
//Remember,
// Ch4 is Y on the left side
// Ch3 is X on the left side
// Ch2 is Y on the right side
// Ch1 is X on the right side
// Left side is 7 BULR
// Right side is 8 BLUR
// Left side is 5U and 5D
// Right side is 6U and 6D

task main()
{

	int controlscheme = 1;


	while (true) {

	if(VexRT[Btn7R] == 1)
		{
			controlscheme = 1;
		}

	if(VexRT[Btn7L] == 1)
		{
			controlscheme = 2;
		}
	if(VexRT[Btn7D] == 1)
	{
		controlscheme = 3;
	}

	switch(controlscheme) {

		case 1:
			motor[rightDrive] = (vexRT[Ch2]);
			motor[leftDrive] = (vexRT[Ch3]);
			if(vexRT[Btn5D] == 1) {
			motor[middleDrive] = -127;
			}
			else if(vexRT[Btn6D] == 1)
			{
			motor[middleDrive] = 127;
			}
			else if(vexRT[Btn6U] == 1)
			{
			motor[rightArm] = 127;
			motor[leftArm] = 127;
			}
			else if(vexRT[Btn5U] == 1)
			{
			motor[rightArm] = -127;
			motor[leftArm] = -127;
			}
			else
			{
			motor[rightArm] = 0;
			motor[leftArm] = 0;
			motor[middleDrive] = 0;
			}

		case 2:
			motor[rightDrive] = (vexRT[Ch2]);
			motor[leftDrive] = (vexRT[Ch3]);
			if(vexRT[Btn5D] == 1) {
				motor[middleDrive] = -127;
			}
			else if(vexRT[Btn6D] == 1)
			{
				motor[middleDrive] = 127;
			}
			else if(vexRT[Btn8U] == 1)
			{
				motor[rightArm] = 127;
				motor[leftArm] = 127;
			}
			else if(vexRT[Btn8D] == 1)
			{
				motor[rightArm] = -127;
				motor[leftArm] = -127;
			}
			else
			{
				motor[rightArm] = 0;
				motor[leftArm] = 0;
				motor[middleDrive] = 0;
			} //Close else brace
		} // Close case swap brace
	} // Close true loop brace
} // Close task main brace
