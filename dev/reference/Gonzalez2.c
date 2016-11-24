#pragma config(Motor, port2, backLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor, port3, backRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor, port4, frontLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor, port5, frontRightMotor, tmotorVex393, openLoop, reversed)

task main()
{
	while (1 == 1) {

		if (vexRT[Btn5U] == 1)
		{
			motor[frontLeftMotor] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[backLeftMotor] = 127;
		}
		else if (vexRT[Btn6U] == 1)
		{
			motor[frontRightMotor] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[backRightMotor] = 127;
		}
		else {
			motor[frontLeftMotor] = 0;
			motor[backLeftMotor] = 0;
			motor[frontRightMotor] = 0;
			motor[backRightMotor] = 0;
		}
	}
}
