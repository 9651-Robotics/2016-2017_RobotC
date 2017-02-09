#pragma config(Motor, port2, upperArmRight,tmotorVex393, openLoop)
#pragma config(Motor, port3, lowerArmRight,tmotorVex393, openLoop)
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

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
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

	motor[wheelRight] = (VexRT[Ch2]);
	motor[wheelLeft] = (VexRT[Ch3]);

	if(VexRT[Btn7U] && VexRT[Btn8U] == 1){
		motor[upperArmRight] = 127;
		motor[lowerArmRight] = 127;
		motor[upperArmLeft] = -127;
		motor[lowerArmLeft] = -127;
	}
	else if(VexRT[Btn7D] && VexRT[Btn8D] == 1){
		motor[upperArmRight] = -127;
		motor[lowerArmRight] = -127;
		motor[upperArmLeft] = 127;
		motor[lowerArmLeft] = 127;
	}
	else {
		motor[upperArmRight] = 0;
		motor[lowerArmRight] = 0;
		motor[upperArmLeft] = 0;
		motor[lowerArmLeft] = 0;
	}

	if(VexRT[Btn8R] == 1){
		motor[grabberRight] = -55;
	}
	else if(VexRT[Btn7L] == 1){
		motor[grabberLeft] = -55;
	}
	else {
		motor[grabberRight] = 0;
		motor[grabberLeft] = 0;
	}

	if(VexRT[Btn5U] && VexRT[Btn6U] == 1){
		motor[grabberRight] = 55;
		motor[grabberLeft] = 55;
	}
	else if(VexRT[Btn5D] && VexRT[Btn6D] == 1){
		motor[grabberLeft] = -55;
		motor[grabberRight] = -55;
	}
	else {
		motor[grabberRight] = 0;
		motor[grabberLeft] = 0;
	}

	if(VexRT[Btn7R] == 1){
		motor[grabberRight] = 55;
	}
	else if(VexRT[Btn8L] == 1){
		motor[grabberLeft] = 55;
	}
	else {
		motor[grabberRight] = 0;
		motor[grabberLeft] = 0;
	}

	}
}
