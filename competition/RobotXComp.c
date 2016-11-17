#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
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
#pragma config(Motor,  port7,           armFork,   tmotorVex393, openLoop)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"

int nBatteryAverage = nAvgBatteryLevel;

//const float rotations = 360.0;
//Rotations captured @ 127 motor power
//Ticks per one wheel rotation back left = 362, 352, 379, 369, 360, 364, 363, 355
//Ticks per one wheel roation back right = 373, 343, 371, 377, 363, 350, 369, 359
//11.2 ticks = 1 CM of movement on the back wheels (both sides)
//Wheel diameter = 10.3 CM


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

	string mainBattery, backupBattery;

	while (true) {

		displayLCDPos(0,0);
		displayNextLCDString("Left:");
		displayLCDNumber(SensorValue(leftEncoder));
		displayLDCString("_")
		displayLCDString("Right:");
		displayNextLCDNumber(SensorValue(rightEncoder));
		displayLCDString(0, 0, "Battery: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');


		motor[driveRight] = (vexRT[Ch3]);
		motor[driveLeft] = (vexRT[Ch2]);

		while(vexRT[Btn8U] == 1)
		{
				bLCDBacklight = true;
		}
		if(vexRT[Btn8R] == 1) {
			motor[driveMiddle] = -127;
		}
		else if(vexRT[Btn8L] == 1)
		{
			motor[driveMiddle] = 127;
		}
		else if(vexRT[Btn5U] == 1)
		{
			motor[armFork] = -127;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[armFork] = 127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[armRight] = -127;
			motor[armLeft] = -127;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[armRight] = 127;
			motor[armLeft] = 127;
		}
		else if(vexRT[Btn8D] == 1)
		{
			clearLCDLine(0);
  		clearLCDLine(1);
			SensorValue[rightEncoder] = 0;
			SensorValue[leftEncoder] = 0;
		}
		else
		{
			motor[armRight] = 0;
			motor[armLeft] = 0;
			motor[driveMiddle] = 0;
			motor[armFork] = 0;
			bLCDBacklight = false;
		} //Close else
	} // Close true loop brace
} // Close user control brace
