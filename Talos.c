#pragma config(Motor, port2, upperArmRight,tmotorVex393, openLoop, reversed)
#pragma config(Motor, port3, lowerArmRight,tmotorVex393, openLoop, reversed)
#pragma config(Motor, port4, upperArmLeft, tmotorVex393, openLoop)
#pragma config(Motor, port5, lowerArmLeft, tmotorVex393, openLoop)
#pragma config(Motor, port6, wheelRight, tmotorVex393, openLoop, reversed)
#pragma config(Motor, port7, wheelLeft, tmotorVex393, openLoop)
#pragma config(Motor, port8, grabberJaw, tmotorVex393, openLoop)
#pragma config(Motor, port9, grabberFlipper, tmotorVex393, openLoop, reversed)

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
		motor[wheelRight]     = (vexRT[Ch2]);
		motor[wheelLeft]      = (vexRT[Ch3]);

		motor[upperArmLeft]   = (vexRT[Btn5D]) *  127;
		motor[lowerArmLeft]   = (vexRT[Btn5D]) *  127;
		motor[upperArmRight]  = (vexRT[Btn5D]) *  127;
		motor[lowerArmRight]  = (vexRT[Btn5D]) *  127;

		motor[upperArmLeft]   = ((vexRT[Btn5U]) * 127) * (-1);
		motor[lowerArmLeft]   = ((vexRT[Btn5U]) * 127) * (-1);
		motor[upperArmRight]  = ((vexRT[Btn5U]) * 127) * (-1);
		motor[lowerArmRight]  = ((vexRT[Btn5U]) * 127) * (-1);

		motor[grabberJaw]     =  (vexRT[Btn6D]) *  95;
		motor[grabberJaw]     = ~(95 * vexRT[Btn6U]);

		motor[grabberFlipper] = (vexRT[Btn8D]) *   55;
		motor[grabberFlipper] = ((vexRT[Btn8U]) *  55) * (-1);
	}
}
