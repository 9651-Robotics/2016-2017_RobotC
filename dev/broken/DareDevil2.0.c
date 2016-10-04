#pragma config(Sensor, dgtl1,  sonarSensorFront, sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  sonarSensorLeft, sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  sonarSensorBack, sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  sonarSensorRight, sensorSONAR_cm)

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

//Wait for Press
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

//Wait for Release
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

task main()
{
	//Declare count variable to keep track of our choice
	int count = 0;

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	//clearLCDLine(0);
	//clearLCDLine(1);
	//Loop while center button is not pressed

	//------------- End of User Interface Code ---------------------

	//------------- Beginning of Robot Movement Code ---------------
	//Clear LCD
	//clearLCDLine(0);
	//clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "TheForwardDistanceIs");
		displayNextLCDNumber(SensorValue(sonarSensorFront));
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move forward at full power for 3 seconds
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "TheBackwardDistanceIs");
		displayNextLCDNumber(SensorValue(sonarSensorBack));
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move reverse at full power for 3 seconds
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "TheLeftDistanceIs");
		displayNextLCDNumber(SensorValue(sonarSensorLeft));
		wait1Msec(2000);						// Robot waits for 2000 milliseconds
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 3:
		//If count = 3, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "TheRightDistanceIs");
		displayNextLCDNumber(SensorValue(sonarSensorRight));
		wait1Msec(2000);
		wait1Msec(3000);
		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
}
