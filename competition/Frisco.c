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
#pragma config(Motor,  port7,           armFork,       tmotorVex393, openLoop)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int nBatteryAverage = nAvgBatteryLevel;

//const float rotations = 360.0;
//Rotations captured @ 127 motor power
//Ticks per one wheel rotation back left = 362, 352, 379, 369, 360, 364, 363, 355
//Ticks per one wheel roation back right = 373, 343, 371, 377, 363, 350, 369, 359
//11.2 ticks = 1 CM of movement on the back wheels (both sides)
//Wheel diameter = 10.3 CM (32.3584)


void waitForPress() {
	while(nLCDButtons == 0){}
	wait1Msec(3);
}
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(3);
}
void armUp() {
	motor[armRight] = 127;
	motor[armLeft] = 127;
}
void armDown() {
	motor[armRight] = -90;
	motor[armLeft] = -90;
}
void forkDown() {
	motor[armFork] = 25;
}
void forkUp() {
	motor[armFork] = -50;
}
void middleRight() {
	motor[driveMiddle] = -127;
}
void middleLeft() {
	motor[driveMiddle] = 127;
}

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	nMotorEncoder[rightEncoder]=0;
	nMotorEncoder[leftEncoder]=0;
	SensorValue[dgtl1] = 0;
	SensorValue[dgtl3] = 0;

}

task autonomous()
{
	  // If we do end up needing two autonomous modes, check back on (https://www.vexforum.com/index.php/10222-how-to-program-lcd-display-robotc/0)

	  //Stage 1: turn right and left motors forward
	  while(SensorValue[rightEncoder] <= 430 && SensorValue[leftEncoder] <= 430) {
	  	motor[driveLeft] = 67;
	  	motor[driveRight] = 67;
	  }
	  wait1Msec(1000);
	  //Stage 2: turn 180 degrees
	  // ISSUE
	  while(SensorValue[rightEncoder] >= -167 && SensorValue[leftEncoder] <= 1110) {
	  	motor[driveLeft] = 67;
	  	motor[driveRight] = -67;
	  }
	  //Turn arm sometime between stages two and three
	  wait1Msec(1000);
	  //Stage 3: reverse
	  while(SensorValue[rightEncoder] >= -1280 && SensorValue[leftEncoder] >= -20) {
	  	motor[driveLeft] = -67;
	  	motor[driveRight] = -67;
	  }

}

task usercontrol()
{

	string mainBattery, backupBattery;
	int count = 0;

	while (true) {

		//Display information
		// Encoder values
		// Battery potential differance
		// Joystick values

		//Attempt to define closer in the file to the void functions
		int leftForce = vexRT[Ch2];
		int rightForce = vexRT[Ch3];

		//matthew wang more like matthew "WANG"

														// - Carpet Cock
		displayLCDPos(0,0);
		displayNextLCDString("L:");
		displayNextLCDNumber(SensorValue(leftEncoder));
		displayNextLCDString("  ");
		displayNextLCDString("R:");
		displayNextLCDNumber(SensorValue(rightEncoder));
		displayLCDString(1, 0, "Bat: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
		displayNextLCDString(mainBattery);

		motor[driveRight] = (vexRT[Ch3]);
		motor[driveLeft] = (vexRT[Ch2]);

		while(vexRT[Btn8U] == 1)
		{
			bLCDBacklight = true;
		}
		if(vexRT[Btn8D] == 1)
		{
			clearLCDLine(0);
  		clearLCDLine(1);
			SensorValue[rightEncoder] = 0;
			SensorValue[leftEncoder] = 0;
		}
		else {

		}

		//Middle Wheel (Currently immobile due to arm weight)
		if(vexRT[Btn8R] == 1) {
			middleRight();
		}
		else if(vexRT[Btn8L] == 1) {
			middleLeft();
		}
		else{
			motor[driveMiddle] = 0;
		}

		//Fork (arm built onto the end of the main arm)
		if(vexRT[Btn5U] == 1) {
			forkUp();
		}
		else if(vexRT[Btn5D] == 1) {
			forkDown();
		}
		else {
			 motor[armFork] = 0;
		}

		//Arm motors
		if(vexRT[Btn6U] == 1) {
			armUp();
		}
		else if(vexRT[Btn6D] == 1) {
			armDown();
		}
		else {
			motor[armLeft] = 0;
			motor[armRight] = 0;
		}
	}
}
