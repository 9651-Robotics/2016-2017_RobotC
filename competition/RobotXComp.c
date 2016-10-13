#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_2,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, I2C_3,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Motor,  port2,           driveRight,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           driveMiddle,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armRight,      tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port6,           armLeft,       tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"

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

			displayLCDString(1, 0, "NoSchemeSelected");

		case 2:

			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0, 0, "R: ");
			displayLCDString(1, 0, "L: ");
			displayLCDNumber(0, 3, nMotorEncoder[armRight], 6);
			displayLCDNumber(1, 3, nMotorEncoder[armLeft], 6);
			bLCDBacklight = true;
  		displayNextLCDString("Sarick");
  		displayLCDNumber(0, 3, nMotorEncoder[armRight], 6);

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
			}//Close else brace

		case 3:

			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0, 0, "R: ");
			displayLCDString(1, 0, "L: ");
			displayLCDNumber(0, 3, nMotorEncoder[armRight], 6);
			displayLCDNumber(1, 3, nMotorEncoder[armLeft], 6);
			bLCDBacklight = true;
  		displayNextLCDString("Boeckh");
 			displayNextLCDNumber(SensorValue(nMotorEncoder[armRight]);

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

			} // Close case swap (switch) brace
	} // Close true loop brace
} // Close user control brace
