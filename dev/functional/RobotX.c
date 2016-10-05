#pragma config(Motor,  port2,           rightMotor,    tmotorVmotor, openLoop)
#pragma config(Motor,  port3,           middleMotor,   tmotorVex393, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorVex393, openLoop)
// Take care when adding arm motors as this created problems compiling last time

task main()
{

	while (1 == 1) {

	motor[rightMotor] = (vexRT[Ch2]);
	motor[leftMotor] = (vexRT[Ch3]);
		if(vexRT[Btn5U] == 1) {
				motor[middleMotor] = -127;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[middleMotor] = 127;
		}
		else
		{
			motor[middleMotor] = 0;
		}
	}
}
