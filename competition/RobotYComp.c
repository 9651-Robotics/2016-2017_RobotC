#pragma config(Sensor, in1, armAngle, sensorPotentiometer)
#pragma config(Sensor, dgtl4,  sonarRight,     sensorSONAR_cm)
#pragma config(Sensor, dgtl6,  sonarLeft,      sensorSONAR_cm)
#pragma config(Sensor, dgtl8,  sonarBack,      sensorSONAR_cm)
#pragma config(Sensor, dgtl10, sonarFront,     sensorSONAR_cm)
#pragma config(Motor,  port2,  frontRight,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,  backRight,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,  frontLeft,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,  backLeft,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,  armRight1,      tmotorNormal, openLoop)
#pragma config(Motor,  port7,  armLeft1,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port8,  armRight2,      tmotorNormal, openLoop)
#pragma config(Motor,  port9,  armLeft2,       tmotorNormal, openLoop, reversed)


#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

int armDegree =SensorValue(armAngle);

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


task autonomous()
{
        //motor[armRight1] = -127;
   	 		//motor[armLeft1] = -127;
   	 		//motor[armRight2] = -127;jjuud
    		//motor[armLeft2] = -127;


    		//motor[armRight1] = 0;
   	 		//motor[armLeft1] = 0;
   	 		//motor[armRight2] = 0;
    		//motor[armLeft2] = 0;

}


task usercontrol(){

	while(true) {


			motor[frontRight] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
    	motor[backRight] =  vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
    	motor[frontLeft] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
    	motor[backLeft] =  vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];

    	if(vexRT[Btn6U] == 1) {
    		motor[armRight1] = 70;
    		motor[armLeft1] = 70;
    		motor[armRight2] = 70;
    		motor[armLeft2] =  70;
   	 	}
   	 	else if(vexRT[Btn6D] == 1) {
   	 		motor[armRight1] = -90;
   	 		motor[armLeft1] = -90;
   	 		motor[armRight2] = -90;
    		motor[armLeft2] = -90;
   		}
   		else {
   			motor[armRight1] = 0;
   			motor[armLeft1] = 0;
   			motor[armRight2] = 0;
    		motor[armLeft2] = 0;
   		}

  		if(vexRT[Btn5U] == 1)
			{
					clearLCDLine(0);
  				clearLCDLine(1);
			}
			else if(vexRT[Btn7U] == 1){
				SensorValue(armAngle) = 0;
				armDegree = 0;
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
		displayNextLCDString("Arm:");
		displayNextLCDNumber(armDegree);

  	//displayLCDPos(0,0);
  	//displayNextLCDString("F:");
 		//displayNextLCDNumber(SensorValue(sonarFront));
 		//displayNextLCDString("CM");

 		//displayLCDPos(0,9);
 		//displayNextLCDString("B:");
 		//displayNextLCDNumber(SensorValue(sonarBack));
 		//displayNextLCDString("CM");

 		//displayLCDPos(1,0);
 		//displayNextLCDString("L:");
 		//displayNextLCDNumber(SensorValue(sonarLeft));
 		//displayNextLCDString("CM");

 		//displayLCDPos(1,9);
 		//displayNextLCDString("R:");
 		//displayNextLCDNumber(SensorValue(sonarRight));
 		//displayNextLCDString("CM");

	}
}
