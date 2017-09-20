#pragma config(Motor,  port2,           rightMotor,    tmotorVmotor, openLoop)
#pragma config(Motor,  port3,           middleMotor,   tmotorVex393, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           armRight, tmotorVex393, openloop)
#pragma config(Motor,  port6,           armLeft, tmotorVex393, openloop)

task main()
{

	while (1 == 1) {

	motor[rightMotor] = (vexRT[Ch2]);
	motor[leftMotor] = (vexRT[Ch3]);
		if (vexRT[Btn6U == 1) {
			motor[armLeft] = 127;
			motor[armRight] = 127;
		}
		else if (vexRT[Btn6D == 1) {
			motor[armLeft] = -127;
			motor[armRight] = -127;
		}
		else {
			motor[armLeft] = 0;
			motor[armRight] = 0;
		}
		if (vexRT[Btn5U] == 1) {
				motor[middleMotor] = -127;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[middleMotor] = 127;
		}
		else
		{
			motor[middleMotor] = 0;
		}
	}
}
