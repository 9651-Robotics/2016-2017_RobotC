#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1, armAngle, sensorPotentiometer)
#pragma config(Sensor, I2C_2,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, I2C_3,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, dgtl1,  					FrontRightEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  					FrontLeftEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,           BackRightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,           BackLeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           driveRightFront,    tmotorVex269, openLoop)
#pragma config(Motor,  port3,           driveLeftFront,     tmotorVex269, openLoop)
#pragma config(Motor,  port4,           driveRightBack1,    tmotorVex393, openLoop)
#pragma config(Motor,  port5,           driveRightBack2,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           driveLeftBack1,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           driveLeftBack2,     tmotorVex393, openLoop)

#pragma platform(VEX)

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


	string mainBattery, backupBattery;
	int count = 0;

task main() {

	while (true) {

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

		motor[driveRightFront] = (vexRT[Ch3]);
		motor[driveLeftFront] = (vexRT[Ch2]);
		motor[driveRightBack1] = (vexRT[Ch3]);
		motor[driveRightBack2] = (vexRT[Ch3]);
		motor[driveLeftBack1] = (vexRT[Ch2]);
		motor[driveLeftBack2] = (vexRT[Ch2]);
	}
}
