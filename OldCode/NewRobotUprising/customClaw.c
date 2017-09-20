#pragma config(Motor,  port2,           rightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor, tmotorVex393, openLoop)

task main()
{
  while(1 == 1)
  {

		motor[leftMotor]  = (vexRT[Ch4] + vexRT[Ch3])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch6] - vexRT[Ch1])/2;  // (y - x)/2

  }
}
