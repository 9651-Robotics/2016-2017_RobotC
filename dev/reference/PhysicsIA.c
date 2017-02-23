// This code is for John's Physics IA

// Materials required
//	Vex cortex, controller, battery (and possibly back-up battery) and USB-USB cable
//  Air pump, reserve and piston
//  Solenoid valve connected to port "Digital 7" on Vex Cortex
//	Possibly a speaker module
// 	Force sensor and a metal plate mounted to the pneumatic piston

#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, dgtl7,  solenoid,            sensorDigitalOut)

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int nBatteryAverage = nAvgBatteryLevel;

task main() {

	string mainBattery, backupBattery;

	while (true) {

	bLCDBacklight = true;

	displayLCDString(0, 0, "Bat: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
	displayNextLCDString(mainBattery);

	if(vexRT[Btn8U] == 1) {
		PlayTone(  784,   27); wait1Msec( 150);
		PlayTone(    0,   27); wait1Msec( 150);
		PlayTone(  988,   27); wait1Msec( 150); 
		PlayTone(    0,   27); wait1Msec( 150);
		PlayTone( 1175,   27); wait1Msec( 150);
		displayLCDCenteredString(0, "ACTIVE");
    	SensorValue[solenoid] = 1; 
    }
    else {
    	displayLCDCenteredString(0, "INACTIVE");
    	SensorValue[solenoid] = 0;  
    }

	}

}