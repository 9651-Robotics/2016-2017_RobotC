#pragma config(Motor,  port2,           rf1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rf2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           lf1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lf2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rb1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rb2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lb1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lb2,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
		while (true)
		{
			motor[port2] = (vexRT[Ch2])*1;
			motor[port3] = (vexRT[Ch2])*1;
			motor[port4] = (vexRT[Ch3])*1;
			motor[port5] = (vexRT[Ch3])*1;
			motor[port6] = (vexRT[Ch2])*1;
			motor[port7] = (vexRT[Ch2])*1;
			motor[port8] = (vexRT[Ch3])*1;
			motor[port9] = (vexRT[Ch3])*1;
		}

}