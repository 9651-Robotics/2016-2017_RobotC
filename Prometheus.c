#pragma config(Motor, port2, upperArmRight,tmotorVex393, openLoop, reversed)
#pragma config(Motor, port3, lowerArmRight,tmotorVex393, openLoop, reversed)
#pragma config(Motor, port4, upperArmLeft, tmotorVex393, openLoop)
#pragma config(Motor, port5, lowerArmLeft, tmotorVex393, openLoop)
#pragma config(Motor, port6, wheelRight, tmotorVex393, openLoop, reversed)
#pragma config(Motor, port7, wheelLeft, tmotorVex393, openLoop)
#pragma config(Motor, port8, grabberRight, tmotorVex393, openLoop)
#pragma config(Motor, port9, grabberLeft, tmotorVex393, openLoop,reversed)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		motor[wheelRight]    = (vexRT[Ch2]);
		motor[wheelLeft]     = (vexRT[Ch3]);

		motor[upperArmLeft]  = (vexRT[Btn7U]) *  70;
		motor[lowerArmLeft]  = (vexRT[Btn7U]) *  70;
		motor[upperArmLeft]  = (vexRT[Btn7D]) * -70;
		motor[lowerArmLeft]  = (vexRT[Btn7D]) * -70;
		motor[upperArmRight] = (vexRT[Btn7U]) *  70;
		motor[lowerArmRight] = (vexRT[Btn7U]) *  70;
		motor[upperArmRight] = (vexRT[Btn7D]) * -70;
		motor[lowerArmRight] = (vexRT[Btn7D]) * -70;

		motor[upperArmLeft]  = (vexRT[Btn7L]) * 127;
		motor[lowerArmLeft]  = (vexRT[Btn7L]) * 127;
		motor[upperArmLeft]  = (vexRT[Btn7R]) * -127;
		motor[lowerArmLeft]  = (vexRT[Btn7R]) * -127;
		motor[upperArmRight] = (vexRT[Btn7L]) * 127;
		motor[lowerArmRight] = (vexRT[Btn7L]) * 127;
		motor[upperArmRight] = (vexRT[Btn7R]) * -127;
		motor[lowerArmRight] = (vexRT[Btn7R]) * -127;

		motor[grabberLeft]   = (vexRT[Btn8U]) *  55;
		motor[grabberRight]  = (vexRT[Btn8U]) *  55;
		motor[grabberLeft]   = (vexRT[Btn8D]) * -55;
		motor[grabberRight]  = (vexRT[Btn8D]) * -55;
	}
}
