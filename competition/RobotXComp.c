#pragma config(Motor,  port2,           driveRight,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           driveMiddle,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armLeft,       tmotorVex393_MC29, openLoop)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

task autonomous()
{

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.

}

task usercontrol()
{
	int controlscheme = 1;
	while (true)
	{
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



			motor[driveRight] = (vexRT[Ch2]);
			motor[driveLeft] = (vexRT[Ch3]);
			if(vexRT[Btn5D] == 1) {
			motor[driveMiddle] = -127;
			}
			else if(vexRT[Btn6D] == 1)
			{
			motor[driveMiddle] = 127;
			}
			else if(vexRT[Btn6U] == 1)
			{
			motor[armRight] = 127;
			motor[armLeft] = 127;
			}
			else if(vexRT[Btn5U] == 1)
			{
			motor[armRight] = -127;
			motor[armLeft] = -127;
			}
			else
			{
			motor[armRight] = 0;
			motor[armLeft] = 0;
			motor[driveMiddle] = 0;
			}

		case 2:
			motor[driveRight] = (vexRT[Ch2]);
			motor[driveLeft] = (vexRT[Ch3]);
			if(vexRT[Btn5D] == 1) {
				motor[driveMiddle] = -127;
			}
			else if(vexRT[Btn6D] == 1)
			{
				motor[driveMiddle] = 127;
			}
			else if(vexRT[Btn8U] == 1)
			{
				motor[armRight] = 127;
				motor[armLeft] = 127;
			}
			else if(vexRT[Btn8D] == 1)
			{
				motor[armRight] = -127;
				motor[armLeft] = -127;
			}
			else
			{
				motor[armRight] = 0;
				motor[armLeft] = 0;
				motor[driveMiddle] = 0;
			} //Close else brace
		} // Close case swap (switch) brace
	} // Close true loop brace
} // Close user control brace
