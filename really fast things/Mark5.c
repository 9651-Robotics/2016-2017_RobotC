#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1, armAngle, sensorPotentiometer)
#pragma config(Sensor, I2C_2,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, I2C_3,  , sensorQuadEncoderOnI2CPort, ,AutoAssign)
#pragma config(Sensor, in1,    					expander_1,    sensorAnalog)
#pragma config(Sensor, in2,    					expander_2,    sensorAnalog)
#pragma config(Sensor, dgtl1,  			FrontRightEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  			FrontLeftEncoder,   sensorQuadEncoder)
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
int frontRightShaft = SensorValue[FrontRightEncoder];
int frontLeftShaft = SensorValue[FrontLeftEncoder];
int backRightShaft = SensorValue[BackRightEncoder];
int backLeftShaft = SensorValue[BackLeftEncoder];

//const float rotations = 360.0;
//Wheel diameter = 10.3 CM (32.3584)

//Adaprive Steering Blueprint
// Run all motors for 5 seconds and record encoder ticks
// Sort from hightst to lowest
// Reduce motor power accordingly

string mainBattery, backupBattery;

int count = 1;

task main() {

	while (true) {


		bLCDBacklight = true;

		if (count % 2 == 0)
		{

			clearLCDLine(0);
		    clearLCDLine(1); 

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

		}
			
		else

		{

			clearLCDLine(0);
		    clearLCDLine(1); 

			displayLCDString(0, 0, "Main: "); 
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V'); 
			displayNextLCDString(mainBattery);

			displayLCDString(1, 0, "L: ");
			sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2); 
			displayNextLCDString(backupBattery); 

			wait1Msec(100);

		}	

		motor[driveRightFront] = (vexRT[Ch3]);
		motor[driveLeftFront]  = (vexRT[Ch2]);
		motor[driveRightBack1] = (vexRT[Ch3]);
		motor[driveRightBack2] = (vexRT[Ch3]);
		motor[driveLeftBack1]  = (vexRT[Ch2]);
		motor[driveLeftBack2]  = (vexRT[Ch2]);

	}
}
