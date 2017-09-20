#pragma config(Sensor, dgtl1,  sonarSensorFront, sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  sonarSensorLeft, sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  sonarSensorBack, sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  sonarSensorRight, sensorSONAR_cm)


task main()
{

	while(true){
		wait1Msec(100);
		clearLCDLine(0);
  	clearLCDLine(1);

 	 	bLCDBacklight = true;

  	displayLCDPos(0,0);

 		displayNextLCDNumber(SensorValue(sonarSensorFront));
 		displayNextLCDNumber(SensorValue(sonarSensorRight));
 		displayNextLCDNumber(SensorValue(sonarSensorBack));
 		displayNextLCDNumber(SensorValue(sonarSensorLeft));

	}
}
