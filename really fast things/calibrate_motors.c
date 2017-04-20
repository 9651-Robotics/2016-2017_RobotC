#pragma config(Sensor, dgtl5,  encoder, sensorQuadEncoder)
#pragma config(Motor,  port2,  drive_motor, tmotorVex269_MC29, openLoop)

#pragma platform(VEX)

//single calibration run
int calibration_run()
{
	int init_value = SensorValue(encoder);//start value
	motor[drive_motor] = 127;//run motor for..
	wait1Msec(5000);//...5 seconds
	int final_value = SensorValue(encoder);//final value
	motor[drive_motor] = 0;//kill motor

	return abs(final_value - init_value);//return diff
}

task main()
{
	bLCDBacklight = true;
	clearLCDLine(0);
	clearLCDLine(1);

	displayLCDPos(0,0);
	displayNextLCDString("Calibration start");

	while (true){

		while (nLCDButtons != 2){}//wait for button press
		while (nLCDButtons != 0){}//wait for button release

		int counter = 0;

		for (int i = 1; i < 6; i++){//5 calibration runs
			clearLCDLine(0);
			displayLCDPos(0,0);
			displayNextLCDString("Trial: ");
			displayNextLCDNumber(i);
			counter += calibration_run();
		}

		clearLCDLine(0);
		displayLCDPos(0,0);
		displayNextLCDString("Avg: ");
		displayNextLCDNumber(counter/5);//print average
	}
}
