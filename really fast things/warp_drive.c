#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,             expander_1,    sensorAnalog)
#pragma config(Sensor, in2,             expander_2,    sensorAnalog)
#pragma config(Sensor, I2C_1,           drive_encoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           driveLeftA,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           driveLeftB,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           driveRightA,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           driveRightB,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           steerLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           steerRight,    tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

const bool dev = false;

//task for controlling lcd
task display_battery()
{
	//set variables
	string mainBattery, backupBattery;
	while (true) //do one thing forever
	{
		clearLCDLine(0); //clean LCD
		clearLCDLine(1); //clean it well

		//centre button: hold to view encoder value
		if (nLCDButtons == 2) {
			displayLCDString(0, 0, "Encoder Value: "); //start the line
			displayLCDString(1, 1, " "); //start the line
			displayNextLCDNumber(SensorValue(drive_encoder));

		//default to battery level
		} else {
			displayLCDString(0, 0, "Primary: "); //start the line
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V'); //assemble the string
			displayNextLCDString(mainBattery); //display string

			displayLCDString(1, 0, "L: "); //start new line
			sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2); //launch the nukes
			displayNextLCDString(backupBattery); //display string
		}

		wait1Msec(100); //set refresh rate
	}
}

//calibration run
task calibration()
{
	displayLCDString(0, 0, "Calibration Test");
	while (true){
		while (nLCDButtons != 2){}//wait for button press
		while (nLCDButtons != 0){}//wait for button release
		clearLCDLine(0); //clean LCD

		int init_value = SensorValue(drive_encoder); //record initial value

		motor[driveLeftA]  = 127; //haul ass
		motor[driveLeftB]  = 127;
		motor[driveRightA] = 127;
		motor[driveRightB] = 127;

		wait1Msec(5000); //5 second trial

		int final_value = SensorValue(drive_encoder); //record final value

		motor[driveLeftA]  = 0; //stop
		motor[driveLeftB]  = 0;
		motor[driveRightA] = 0;
		motor[driveRightB] = 0;


		displayLCDString(0, 0, "Revolutions: "); //start the line
		displayNextLCDNumber(abs(final_value - init_value));
	}
}

task drive()
{
	startTask(display_battery); //start battery task

	while (true) //groundhog this shit
	{
		//Gotta go fast!!!!!!!
		motor[driveLeftA]  = (vexRT[Ch3]);//drive
		motor[driveLeftB]  = (vexRT[Ch3]);//drive
		motor[driveRightA] = (vexRT[Ch3]);//drive
		motor[driveRightB] = (vexRT[Ch3]);//drive
		motor[steerLeft]   = (vexRT[Ch1]);//steer
		motor[steerRight]  = (vexRT[Ch1]);//steer
	}
}

//main task
task main()
{
	bLCDBacklight = true;//lcd backlight

	if (dev)
	{
		startTask(calibration);
	} else {
		startTask(drive);
	}

	while (true) {};

}
