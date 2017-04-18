#pragma config(Sensor, in1,    					expander_1,    sensorAnalog)
#pragma config(Sensor, in2,    					expander_2,    sensorAnalog)
#pragma config(Motor,  port2,           driveLeftA,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           driveLeftB,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           driveRightA,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           driveRightB,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           steerLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           steerRight,    tmotorVex393_MC29, openLoop, reversed)

#pragma platform(VEX)

//task for controlling lcd
task display_battery()
{
	//set variables
	string mainBattery, backupBattery;
	while (true) //do one thing forever
	{
		clearLCDLine(0); //clean LCD
		clearLCDLine(1); //clean it well

		displayLCDString(0, 0, "Primary: "); //start the line
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0, 'V'); //assemble the string
		displayNextLCDString(mainBattery); //display string

		displayLCDString(1, 0, "L: "); //start new line
		sprintf(backupBattery, "%1.2f R: %1.2f", SensorValue(expander_1)/283.2, SensorValue(expander_2)/283.2); //launch the nukes
		displayNextLCDString(backupBattery); //display string

		wait1Msec(100); //set refresh rate
	}
}

//main task
task main()
{
	bLCDBacklight = true;//lcd backlight
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
