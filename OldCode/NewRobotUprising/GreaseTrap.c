#pragma config(Motor,  port2,  Right,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,  Left,    tmotorNormal, openLoop)

task main () {
	while (1 == 1) {
		motor[Right] = vexRT[Ch4];
		motor[Left] = vexRT[Ch2];
	}
}
