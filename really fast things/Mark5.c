#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1, armAngle, sensorPotentiometer)
#pragma config(Sensor, I2C_2,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, I2C_3,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, dgtl1,  					FrontRightEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  					FrontLeftEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,           BackRightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,           BackLeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           driveRight,    tmotorVex269, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex269, openLoop)
#pragma config(Motor,  port4,           driveMiddle,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           armRight,      tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port6,           armLeft,       tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           armFork,       tmotorVex393, openLoop)

#pragma platform(VEX)

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int nBatteryAverage = nAvgBatteryLevel;
int FrontleftShaft = SensorValue[FrontLeftEncoder];
int FrontrightShaft = SensorValue[FrontRightEncoder];
int shaftAvg = (SensorValue[FrontRightEncoder] + SensorValue[FrontLeftEncoder])/2;

//const float rotations = 360.0;
//Rotations captured @ 127 motor power
//Ticks per one wheel rotation back left = 362, 352, 379, 369, 360, 364, 363, 355
//Ticks per one wheel roation back right = 373, 343, 371, 377, 363, 350, 369, 359
//11.2 ticks = 1 CM of movement on the back wheels (both sides)
//Wheel diameter = 10.3 CM (32.3584)

task usercontrol() {

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

		displayLCDPos(0,0);
		displayNextLCDString("L:");
		displayNextLCDNumber(SensorValue(FrontLeftEncoder));
		displayNextLCDString("  ");
		displayNextLCDString("R:");
		displayNextLCDNumber(SensorValue(FrontRightEncoder));
		displayLCDPos(1,0);
		displayNextLCDString("BL:");
		displayNextLCDNumber(SensorValue(BackLeftEncoder));
		displayNextLCDString("  ");
		displayNextLCDString("BR:");
		displayNextLCDNumber(SensorValue(BackRightEncoder));
		//displayLCDString(1, 0, "Bat: ");
		//sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
		//displayNextLCDString(mainBattery);

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
			SensorValue[FrontRightEncoder] = 0;
			SensorValue[FrontLeftEncoder] = 0;
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
