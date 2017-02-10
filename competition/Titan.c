#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Motor, port2, upperArmRight,tmotorVex393, openLoop)
#pragma config(Motor, port3, lowerArmRight,tmotorVex393, openLoop)
#pragma config(Motor, port4, upperArmLeft, tmotorVex393, openLoop)
#pragma config(Motor, port5, lowerArmLeft, tmotorVex393, openLoop)
#pragma config(Motor, port6, wheelRight, tmotorVex393, openLoop, reversed)
#pragma config(Motor, port7, wheelLeft, tmotorVex393, openLoop)
#pragma config(Motor, port8, grabberRight, tmotorVex393, openLoop)
#pragma config(Motor, port9, grabberLeft, tmotorVex393, openLoop,reversed)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

// TO-DO LIST
//	1. Make sure motors are ported correctly
//	2. Add functions for partial/full control of arm
//		2a. Set up motors "functionally" with speed caps
//		2b. Add functions for lifting and grabbing
//		2c. Add option to unlock speed caps
//	3. Sensor setup
//		3a. Ultrasonics and autonomous programming
//		3b. Arm potentiometer/encoder? (???)


#include "Vex_Competition_Includes.c"   

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int nBatteryAverage = nAvgBatteryLevel;

void LowerAndOpen() {
	//Arm Motors down
	//Grabber Open
}

void UpAndClose() {
	//Arm Motors up
	//Close grabber
}

void pre_auton()
{

  bStopTasksBetweenModes = true;

  	displayLCDPos(0,0);
	displayNextLCDString("IWasNotBuilt");
	displayLCDPos(1,0);
	displayNextLCDString("ToFeelRemorse");

}

task autonomous()
{
	//AutonomousCodePlaceholderForTesting();  
}


task usercontrol()
{

	string mainBattery, backupBattery;

	while (true)
	{

	int leftForce = vexRT[Ch2];
	int rightForce = vexRT[Ch3];
	motor[wheelRight] = (VexRT[Ch2]);
	motor[wheelLeft] = (VexRT[Ch3]);

	// Remember to find sarick's 'Functional Programming' way of doing this 
	// Wasen't it like "motor[wheelRight] = VexRT[Btn8D] * CapValue" or something like that?

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
