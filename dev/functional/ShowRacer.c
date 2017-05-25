#pragma config(Motor,  port2,           driveRightFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeftFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           driveRightBack, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           driveLeftBack, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           driveMiddle,   tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void middleRight(){
	motor[driveMiddle] = 50;
}
void middleLeft(){
	motor[driveMiddle] = -50;
}

const int steering_factor = 2;

task main()
{
	while(true) {

		if(vexRT[Btn5U] == 1) {
			middleRight();
		}
		else if(vexRT[Btn6U] == 1) {
			middleLeft();
		}
		else{
			motor[driveMiddle] = 0;
		}

		if(vexRT[Btn5D] || vexRT[Btn6D == 1]) {
			motor[driveRightFront] = (vexRT[Ch2]) / ((vexRT[Btn6D] * steering_factor) + 1);
			motor[driveLeftFront] = (vexRT[Ch3]) / ((vexRT[Btn5D] * steering_factor) + 1);
			motor[driveRightBack] = ((vexRT[Ch2]) / ((vexRT[Btn6D] * steering_factor) + 1);
			motor[driveLeftBack] = (vexRT[Ch3]) / ((vexRT[Btn5D] * steering_factor) + 1);
		}
		else {
			motor[driveRightFront] = (vexRT[Ch2]);
			motor[driveLeftFront] = (vexRT[Ch3]);
			motor[driveRightBack] = (vexRT[Ch2]);
			motor[driveLeftBack] = (vexRT[Ch3]);
		}
	}

}
