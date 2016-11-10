#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1, armAngle, sensorPotentiometer)
#pragma config(Sensor, I2C_2,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, I2C_3,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, dgtl1,  					rightEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  					leftEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           driveRight,    tmotorVex269, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex269, openLoop)
#pragma config(Motor,  port4,           driveMiddle,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           armRight,      tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port6,           armLeft,       tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"

int lightToggle = 1;
int nBatteryAverage = nAvgBatteryLevel;

//const float rotations = 360.0;

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	//SensorValue[rightEncoder] = 0;

}

task autonomous()
{

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.

}

task usercontrol()
{

	while (true) {

		displayLCDPos(0,0);
		displayNextLCDString("Left:");
		displayNextLCDNumber(SensorValue(leftEncoder));
		displayLCDPos(1,0);
		displayNextLCDString("Right:");
		displayNextLCDNumber(SensorValue(rightEncoder));

		motor[driveRight] = (vexRT[Ch3]);
		motor[driveLeft] = (vexRT[Ch2]);
		if(vexRT[Btn7U] == 1)
		{
			lightToggle++;
		}
		if(lightToggle % 2 == 0)
		{
				bLCDBacklight = true;
		}
		if(vexRT[Btn6D] == 1) {
			motor[driveMiddle] = -127;
		}
		else if(vexRT[Btn5D] == 1)
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
		else if(vexRT[Btn8U] == 1)
		{
			SensorValue[rightEncoder] = 0;
			SensorValue[leftEncoder] = 0;
		}
		else
		{
			motor[armRight] = 0;
			motor[armLeft] = 0;
			motor[driveMiddle] = 0;
		} //Close else
	} // Close true loop brace
} // Close user control brace
