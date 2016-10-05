// Sides are defined as if you were looking from the back of the robot
// Compare tmotorVmotor VS tmotorVex393
// Motors on the left and right drive train Vex 269s 
#pragma config(Motor,  port2,           rightDriveMotor,    tmotorVex269, openLoop)
#pragma config(Motor,  port3,           leftDriveMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port4,           middleMotor,        tmotorVex393, openLoop)
#pragma config(Motor,  port5,           rightArmMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port6,           leftArmMotor,       tmotorVex393, openLoop)
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

	while (1 == 1) {

	motor[rightDriveMotor] = (vexRT[Ch2]);
	motor[leftDriveMotor] = (vexRT[Ch4]);
	if(vexRT[Btn5D] == 1) {
			motor[middleMotor] = -127;
	}
	else if(vexRT[Btn6D] == 1)
	{
		motor[middleMotor] = 127;
	}
	else if(vexRT[Btn6U] == 1)
	{
		motor[rightArmMotor] = 127;
		motor[leftArmMotor] = 127;
	}	
	else if(vexRT[Btn5U] == 1)
	{
		motor[rightArmMotor] = -127;
		motor[leftArmMotor] = -127;
	}	
	else
	{
		motor[rightArmMotor] = 0;
		motor[leftArmMotor] = 0;
		motor[middleMotor] = 0;
	}

	}
}
