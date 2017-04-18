#pragma config(Motor,  port2,           frontRight,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           backRight,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeft,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorServoContinuousRotation, openLoop)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

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

	// We can say we tried...

}

void the_moon()
{
  //        145 = Tempo
  //          5 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone( 1046,    9); wait1Msec( 103);  // Note(C7, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone(  784,    5); wait1Msec(  52);  // Note(C6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone(  784,    5); wait1Msec(  52);  // Note(C6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1174,    5); wait1Msec(  52);  // Note(D7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1174,    5); wait1Msec(  52);  // Note(D7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1046,    5); wait1Msec(  52);  // Note(C7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1174,    5); wait1Msec(  52);  // Note(D7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1174,    5); wait1Msec(  52);  // Note(D7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1396,    5); wait1Msec(  52);  // Note(F7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1396,    5); wait1Msec(  52);  // Note(F7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1396,    5); wait1Msec(  52);  // Note(F7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1396,    5); wait1Msec(  52);  // Note(F7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1318,    5); wait1Msec(  52);  // Note(E7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1318,    5); wait1Msec(  52);  // Note(E7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1175,    5); wait1Msec(  52);  // Note(G6, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  PlayTone( 1318,    5); wait1Msec(  52);  // Note(E7, Duration(32th))
  PlayTone(    0,    5); wait1Msec(  52);  // Note(Rest, Duration(32th))
  PlayTone(    0,    9); wait1Msec( 103);  // Note(Rest, Duration(16th))
  return;
}

void PlayA() {
PlayTone(  932,   14); wait1Msec( 150);  // Note(A#5, Duration(16th))
return;
}
void PlayC() {
	 PlayTone(  831,  14); wait1Msec(150);  // Note(C#, Duration(Half))
}
void PlayG() {
	  PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
}

task usercontrol(){

	while(true) {

	motor[frontLeft] = (vexRT[Ch2] / 1.5);
	motor[backLeft] = (vexRT[Ch2] / 1.5 );
	motor[frontRight] = (vexRT[Ch3] / 1.5 );
	motor[backRight] = (vexRT[Ch3] / 1.5);
	clearLCDLine(0);
  clearLCDLine(1);
	displayLCDPos(0,0);
	displayNextLCDString("CanYouHear");
	displayLCDPos(1,0);
	displayNextLCDString("MeNow?");
  if(vexRT[Btn6D] == 1) {
  	the_moon();
	}
	while(vexRT[Btn8L] == 1){
		PlayA();
	}
	while(vexRT[Btn7L] == 1){
		PlayC();
	}
	while(vexRT[Btn7R] == 1) {
		PlayG();
	}
	}
}
