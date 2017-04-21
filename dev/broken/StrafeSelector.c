#pragma config(Motor,  port2,           frontRight,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorNormal, openLoop, reversed)

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
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Run Forward");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Run Backward");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Autonomous 3");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Autonomous 4");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
	//------------- End of User Interface Code ---------------------

	//------------- Beginning of Robot Movement Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Running Forward");
		displayLCDCenteredString(1, "!!!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move forward at full power for 3 seconds
		motor[frontRight] = 127;			// Motor on port2 is run at full (127) power forward
		motor[backRight]	= 127;
		motor[frontLeft]	= 127;
		motor[backLeft]	= 127;
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Running Backward");
		displayLCDCenteredString(1, "!!!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move reverse at full power for 3 seconds
		motor[frontRight] = -127;
		motor[backRight]	= -127;
		motor[frontLeft]	= -127;
		motor[backLeft]	= -127;
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "Strafing Right");
		displayLCDCenteredString(1, "!!!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn right for 3 seconds
		motor[frontRight] = 127;
		motor[backRight]	= 127;
		motor[frontLeft]	= -127;
		motor[backLeft]	= -127;
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 3:
		//If count = 3, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "Strafing Left");
		displayLCDCenteredString(1, "!!!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn left for 3 seconds
		motor[frontRight] = -127;
		motor[backRight]	= -127;
		motor[frontLeft]	= 127;
		motor[backLeft]	= 127;
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
	//------------- End of Robot Movement Code -----------------------
}
