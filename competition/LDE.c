#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
//Configure the left and right motors
#pragma config(Motor,  port2,           driveRight,    tmotorVex269_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex269_MC29, openLoop, driveLeft)
//Middle motor that allows for strafing
#pragma config(Motor,  port4,           driveMiddle,   tmotorVex393_MC29, openLoop)
//The number 1000 used to appear after I2C_1/2 in the two braces below. We're still not sure why
#pragma config(Motor,  port5,           armRight,      tmotorVex393_MC29, openLoop, encoder, encoderPort, I2C_1) 
#pragma config(Motor,  port6,           armLeft,       tmotorVex393_MC29, openLoop, encoder, encoderPort, I2C_2)
//*!!Code generated by 'John Mace' configuration wizard. Use at your own risk   !!*//
//CHECK THIS 
//Joystick Channels: 4 = LX, 3 = LY, 2 = RY, 1 = RX 
//LP is 7 BULR
//RP is 8 BLUR
//LF is 5U and 5D
//RF is 6U and 6D


#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"

//Useless if DEADZONE controls don't work
#define JOYSTICK_DEADZONE 15

void pre_auton()
{
  //Clear encoders, set servo positions or whatever
  bStopTasksBetweenModes = true;
}

task autonomous()
{
	AutonomousCodePlaceholderForTesting();
}

task usercontrol()
{
	while (true)
	{

		//Standard Tank Controls (Left Y controls driveLeft, right Y controls driveRight)
		motor[driveRight] = (vexRT[Ch2]);
		motor[driveLeft] = (vexRT[Ch3]);

		//Joystick Channels: 4 = LY, 3 = LX, 2 = RY, 1 = RX
		//I don't know about this guys...
		//motor[driveRight] = abs(vexRT[Ch2]) > JOYSTICK_DEADZONE ? reversed ? -vexRT[Ch2] : -vexRT[Ch4] : 0;
		//motor[driveLeft] = abs(vexRT[Ch4]) > JOYSTICK_DEADZONE ? reversed ? -vexRT[Ch4] : -vexRT[Ch4] : 0;

	} //Close user control while true brace
} // Close User control brace

//Function to kill all motors on the lift
void haltLift() {
	motor[armRight] = 0;
	motor[armLeft] = 0;
}
// Function to kill all motors on the drive train
void haltDrive() {
	motor[driveRight] = 0;
	motor[driveLeft] = 0;
	motor[driveMiddle] = 0;
}