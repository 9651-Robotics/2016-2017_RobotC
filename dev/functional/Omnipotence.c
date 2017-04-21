#pragma config(Sensor, dgtl4,  sonarRight,     sensorSONAR_cm)
#pragma config(Sensor, dgtl6,  sonarLeft,      sensorSONAR_cm)
#pragma config(Sensor, dgtl8,  sonarBack,      sensorSONAR_cm)
#pragma config(Sensor, dgtl10, sonarFront,     sensorSONAR_cm)
#pragma config(Motor,  port2,  frontRight,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,  backRight,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,  frontLeft,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,  backLeft,      tmotorNormal, openLoop, reversed)

task main()
{

	while(true) {

		//Mechanum driving controls
		motor[frontRight] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
    	motor[backRight] =  vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
    	motor[frontLeft] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
    	motor[backLeft] =  vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];

  		if(vexRT[Btn6U] == 1)
			{
				clearLCDLine(0);
  				clearLCDLine(1);
			}
			else if(vexRT[Btn5D] == 1)
			{
				bLCDBacklight = true;
			}
			else
			{
				bLCDBacklight = false;
			}

  		displayLCDPos(0,0);
  		displayNextLCDString("F:");
 		displayNextLCDNumber(SensorValue(sonarFront));
 		displayNextLCDString("CM");

 		displayLCDPos(0,9);
 		displayNextLCDString("B:");
 		displayNextLCDNumber(SensorValue(sonarBack));
 		displayNextLCDString("CM");

 		displayLCDPos(1,0);
 		displayNextLCDString("L:");
 		displayNextLCDNumber(SensorValue(sonarLeft));
 		displayNextLCDString("CM");

 		displayLCDPos(1,9);
 		displayNextLCDString("R:");
 		displayNextLCDNumber(SensorValue(sonarRight));
 		displayNextLCDString("CM");
	}
}
