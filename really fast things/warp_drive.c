#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,             expander_1,     sensorAnalog)
#pragma config(Sensor, in2,             expander_2,     sensorAnalog)
#pragma config(Sensor, I2C_1,           drive_encoder,  sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           driveLeftA,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           driveLeftB,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           driveRightA,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           driveRightB,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           steer,      tmotorVex393_MC29, openLoop, reversed)
//*!!Code manually generated by 'JACK' the programming wizard               !!*//

#pragma platform(VEX)

const bool dev = false; //dev flag

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
			displayLCDString(0, 0, "Encoder Value: "); //start writing
			displayLCDString(1, 1, " "); //start writing
			displayNextLCDNumber(SensorValue(drive_encoder));

		//default to battery level
		} else {
			displayLCDString(0, 0, "Primary: "); //start writing
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V'); //assemble the string
			displayNextLCDString(mainBattery); //display string

			displayLCDString(1, 0, "L: "); //start new line
			sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2); //launch the nukes
			displayNextLCDString(backupBattery); //display string
		}

		wait1Msec(100); //set refresh rate
	}
}

//task for calibration run
task calibration()
{
	displayLCDString(0, 0, "Calibration Test");
	while (true){
		while (nLCDButtons != 2){} //wait for button press
		while (nLCDButtons != 0){} //wait for button release
		clearLCDLine(0); //clean LCD

		int init_value = SensorValue(drive_encoder); //record initial value

		fire_all_cylinders(127); //haul ass

		wait1Msec(5000); //5 second trial

		int final_value = SensorValue(drive_encoder); //record final value

		fire_all_cylinders(0); //stop


		displayLCDString(0, 0, "Revolutions: "); //start writing
		displayNextLCDNumber(abs(final_value - init_value));
	}
}

//set all main motors to an int
void fire_all_cylinders(int power)
{
	motor[driveLeftA]  = power; //drive 'bout yay fast
	motor[driveLeftB]  = power;
	motor[driveRightA] = power;
	motor[driveRightB] = power;
}

//task for driving
task drive()
{
	startTask(display_battery); //start battery task

	while (true) //groundhog day this shit
	{
		//Gotta go fast!!!!!!!
		fire_all_cylinders(vexRT[Ch3]); //drive

		motor[steer]   = (vexRT[Ch1]); //steer
	}
}

//main task
task main()
{
	bLCDBacklight = true; //lcd backlight

	// start a task
	if (dev) {
		startTask(calibration);
	} else {
		startTask(drive);
	}

	while (true) {}; //just let the task run forever

}
