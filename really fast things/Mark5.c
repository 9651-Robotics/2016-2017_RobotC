#pragma config(Sensor, in1,    expander_1,     sensorAnalog)
#pragma config(Sensor, in2,    expander_2,     sensorAnalog)
#pragma config(Sensor, dgtl1,  FrontRightEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  FrontLeftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  BackRightEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  BackLeftEncoder, sensorQuadEncoder)
// Wire Motors by reversing Encoder <-> Motor connection Wires.
#pragma config(Motor,  port2,           driveRightFrontRight, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           driveRightFrontLeft, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           driveLeftFrontRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           driveLeftFrontLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           driveRightBackRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           driveRightBackLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           driveLeftBackRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           driveLeftBackLeft, tmotorVex393_MC29, openLoop)

	// -----------------------------------
 	//    	                             |
	//  NUMEBR CORSPONDS TO MOTOR PORT   |
	//    EN INDICATES ENCODER PORT      |
	//   _________________________       |
	//     |   |           |   |         |
	//   W | G |           | G | W       |
	//     | G | EN.3 EN.1 | G |         |
	//   5 | G | 4       3 | G | 2       |
	//     |   |           |   |         |
	//   	   |           |             |
	//      ===================          |
	//     |   |           |   |         |
	//   9 | G | 8       7 | G | 6       |
	//     | G | EN.7  EN.5| G |         |
	//   W | G |   CORTEX  | G | W       |
	//     |   |           |   |         |
	//   __|___|___________|___|___      |
	//                                   |
	// -----------------------------------

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

		    displayLCDString(0, 0, "Primary: "); //start writing
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V'); //assemble the string
			displayNextLCDString(mainBattery); //display string

			displayLCDString(1, 0, "L: "); //start new line
			sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2); //launch the nukes
			displayNextLCDString(backupBattery); //display string

			// displayLCDPos(0,0);
			// displayNextLCDString("L:");
			// displayNextLCDNumber(SensorValue(FrontLeftEncoder));
			// displayNextLCDString("  ");
			// displayNextLCDString("R:");
			// displayNextLCDNumber(SensorValue(FrontRightEncoder));
			// displayLCDPos(1,0);
			// displayNextLCDString("BL:");
			// displayNextLCDNumber(SensorValue(BackLeftEncoder));
			// displayNextLCDString("  ");
			// displayNextLCDString("BR:");
			// displayNextLCDNumber(SensorValue(BackRightEncoder));

		}

		else

		{

		 //clearLCDLine(0);
		 // clearLCDLine(1);

		displayLCDString(0, 0, "Primary: "); //start writing
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V'); //assemble the string
		displayNextLCDString(mainBattery); //display string

		displayLCDString(1, 0, "L: "); //start new line
		sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2); //launch the nukes
		displayNextLCDString(backupBattery); //display string

		 //  displayLCDPos(0,0);
			// displayNextLCDString("L:");
			// displayNextLCDNumber(SensorValue(FrontLeftEncoder));
			// displayNextLCDString("  ");
			// displayNextLCDString("R:");
			// displayNextLCDNumber(SensorValue(FrontRightEncoder));
			// displayLCDPos(1,0);
			// displayNextLCDString("BL:");
			// displayNextLCDNumber(SensorValue(BackLeftEncoder));
			// displayNextLCDString("  ");
			// displayNextLCDString("BR:");
			// displayNextLCDNumber(SensorValue(BackRightEncoder));


			//displayLCDString(0, 0, "Main: ");
			//sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V');
			//displayNextLCDString(mainBattery);

			//displayLCDString(1, 0, "L: ");
			//sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2);
			//displayNextLCDString(backupBattery);

			wait1Msec(100);

		}

		motor[driveRightFrontRight] = (vexRT[Ch3]);
		motor[driveRightFrontLeft]  = (vexRT[Ch3]);

		motor[driveLeftFrontRight]  = (vexRT[Ch2]);
		motor[driveLeftFrontLeft]   = (vexRT[Ch2]);

		motor[driveRightBackRight]  = (vexRT[Ch3]);
		motor[driveRightBackLeft]   = (vexRT[Ch3]);

		motor[driveLeftBackRight]   = (vexRT[Ch2]);
		motor[driveLeftBackLeft]    = (vexRT[Ch2]);

	}
}
