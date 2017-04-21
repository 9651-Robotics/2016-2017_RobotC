#pragma config(Motor, port2, leftMotor, tmotorVex269, openLoop)
#pragma config(Motor, port3, rightMotor, tmotorVex269, openLoop)

task main()
{

	while(1 == 1)
	{
		motor[leftMotor]  = (vexRT[Ch4] + vexRT[Ch3])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
  }

}
