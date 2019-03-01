#pragma config(Sensor, dgtl1,  leftDrive,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightDrive,     sensorQuadEncoder)
#pragma config(Motor,  port1,           mongoLeft,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftDrive1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftDrive3,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           hDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive3,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          mongoRight,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	SensorValue[rightDrive] = 0;
	SensorValue[leftDrive] = 0;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// Declaring functions for auton
void moveForward()
{
	motor[leftDrive1] = 127;
	motor[leftDrive2] = 127;
	motor[leftDrive3] = 127;
	motor[rightDrive3] = 127;
	motor[rightDrive2] = 127;
	motor[rightDrive1] = 127;
}

// Stop all drive motors
void stopDrive()
{
	motor[leftDrive1] = 0;
	motor[leftDrive2] = 0;
	motor[leftDrive3] = 0;
	motor[rightDrive3] = 0;
	motor[rightDrive2] = 0;
	motor[rightDrive1] = 0;
}

void stopAllMotors()
{
	motor[leftDrive1] = 0;
	motor[leftDrive2] = 0;
	motor[leftDrive3] = 0;
	motor[rightDrive3] = 0;
	motor[rightDrive2] = 0;
	motor[rightDrive1] = 0;
	motor[mongoLeft] = 0;
	motor[mongoRight] = 0;
	motor[lift] = 0;
	motor[hDrive] = 0;
}

void rotateLeft()
{
	motor[leftDrive1] = -127;
	motor[leftDrive2] = -127;
	motor[leftDrive3] = -127;
	motor[rightDrive3] = 127;
	motor[rightDrive2] = 127;
	motor[rightDrive1] = 127;
}

void rotateRight()
{
	motor[leftDrive1] = 127;
	motor[leftDrive2] = 127;
	motor[leftDrive3] = 127;
	motor[rightDrive3] = -127;
	motor[rightDrive2] = -127;
	motor[rightDrive1] = -127;
}

void moveBackward()
{
	motor[leftDrive1] = -127;
	motor[leftDrive2] = -127;
	motor[leftDrive3] = -127;
	motor[rightDrive3] = -127;
	motor[rightDrive2] = -127;
	motor[rightDrive1] = -127;
}

void liftUp()
{
	motor[lift] = 127;
}

void liftDown()
{
	motor[lift] = -127;
}

void mongoUp()
{
	motor[mongoRight] = 127;
	motor[mongoLeft] = 127;
}

void mongoDown()
{
	motor[mongoRight] = -127;
	motor[mongoLeft] = -127;
}

void hardstopUp()
{
	motor[hDrive] = 127;
}

void hardstopDown()
{
	motor[hDrive] = -127;
}

// Placeholder platform toggle system
// Auton = 1 Blue Flag Side
// Auton = 2 Red Flag Side
// Auton = 3 Blue Far Side
// Auton = 4 Red Far Side
bool platform = true;
int auton = 1;

void blueFlagSide()
{

		while (SensorValue[rightDrive] >= -1300)
		{
			moveBackward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 630)
		{
			moveForward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] >= -60)
		{
			rotateRight();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		moveBackward();
		wait1Msec(500);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive]  <= 100)
		{
			moveForward();
			mongoDown();
		}

		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoUp();
		wait1Msec(1000);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoDown();
		wait1Msec(1000);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		/*
		moveBackward();
		rotateLeft();
		moveForward();
		rotateRight();
		moveBackward();
		moveForward();
		mongoUp();
		rotateRight();
		mongoDown();
		moveBackward();
		*/


}

void redFlagSide()
{

		while (SensorValue[rightDrive] >= -1300)
		{
			moveBackward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 680)
		{
			moveForward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 220)
		{
			rotateLeft();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		moveBackward();
		wait1Msec(500);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive]  <= 100)
		{
			moveForward();
			mongoDown();
		}
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoUp();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;


		if (platform == true)
		{
			//Platform
		}
		/*
		rotateLeft();
		moveBackward();
		moveForward();
		mongoUp();
		mongoDown();
		moveBackward();
		rotateRight();
		moveForward();
		rotateLeft();
		moveBackward();
		moveForward();
		mongoUp();
		rotateLeft();
		mongoDown();
		moveBackward();
		*/


}

void blueFarSide()
{

		moveForward();
		wait1Msec(500);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		moveBackward();
		wait1Msec(1000);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 850)
		{
			moveForward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoUp();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= -250)
		{
			motor[leftDrive1] = -80;
			motor[leftDrive2] = -80;
			motor[leftDrive3] = -80;
			motor[rightDrive3] = 80;
			motor[rightDrive2] = 80;
			motor[rightDrive1] = 80;
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoDown();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] >= 70)
		{
			rotateRight();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 80)
		{
			moveForward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoUp();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoDown();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		if (platform == true)
		{
			//Platform
		}

		/*
		moveForward();
		mongoUp();
		rotateLeft(); // 180 degrees
		moveForward();
		// Stack cap
		liftUp();
		mongoUp();
		hardstopDown();
		moveForward();
		liftDown();
		moveBackward();
		liftDown();
		mongoDown();
		hardstopUp();
		// End stack cap
		rotateLeft();
		moveBackward();
		moveForward();
		rotateLeft();
		moveForward();
		mongoUp();
		rotateLeft();
		moveBackward();
		*/

}

void redFarSide()
{

		moveForward();
		wait1Msec(500);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		moveBackward();
		wait1Msec(1000);
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 850)
		{
			moveForward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoUp();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] >= -250)
		{
			motor[leftDrive1] = 80;
			motor[leftDrive2] = 80;
			motor[leftDrive3] = 80;
			motor[rightDrive3] = -80;
			motor[rightDrive2] = -80;
			motor[rightDrive1] = -80;
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoDown();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 70)
		{
			rotateLeft();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		while (SensorValue[rightDrive] <= 80)
		{
			moveForward();
		}
		stopDrive();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		mongoUp();
		wait1Msec(1000);
		stopAllMotors();
		SensorValue[rightDrive] = 0;
		SensorValue[leftDrive] = 0;

		if (platform == true)
		{
			//Platform
		}

		/*
		mongoUp();
		rotateRight(); // 180 degrees
		moveForward();
		// Stack cap
		liftUp();
		mongoUp();
		hardstopDown();
		moveForward();
		liftDown();
		moveBackward();
		liftDown();
		mongoDown();
		hardstopUp();
		// End stack cap
		rotateRight();
		moveBackward();
		moveForward();
		rotateRight();
		moveForward();
		mongoUp();
		rotateRight();
		moveBackward();
		*/

}


task autonomous()
{
	SensorValue[rightDrive] = 0;
	SensorValue[leftDrive] = 0;

	// Chooses which auton to run based on where jumper clips/potentiometers are placed
	if (auton == 1)
	{
		blueFlagSide();
	}
	else if (auton == 2)
	{
		redFlagSide();
	}
	else if (auton == 3)
	{
		blueFarSide();
	}
	else if (auton == 4)
	{
		redFarSide();
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	/*
	// Declaring Variables
	int KpR = 0;
	int errorR = 0;
	int targetLocationR = 0;
	int drivePowerR = 0;
	int KpL = 0;
	int errorL = 0;
	int targetLocationL = 0;
	int drivePowerL = 0;
	bool brakes = false;
	*/

	while (true)
	{
		// Drive controls
		if (vexRT(Ch2) > 10 || vexRT(Ch2) < -10 || vexRT(Ch3) > 10 || vexRT(Ch3) < -10)
		{
			motor[rightDrive1] = vexRT[Ch2];
			motor[rightDrive2] = vexRT[Ch2];
			motor[rightDrive3] = vexRT[Ch2];
			motor[leftDrive1] = vexRT[Ch3];
			motor[leftDrive2] = vexRT[Ch3];
			motor[leftDrive3] = vexRT[Ch3];
		}
		else
		{
			motor[rightDrive1] = 0;
			motor[rightDrive2] = 0;
			motor[rightDrive3] = 0;
			motor[leftDrive1] = 0;
			motor[leftDrive2] = 0;
			motor[leftDrive3] = 0;
		}

		// Crash Bar Controls
		if (vexRT(Btn8D) == 1)
		{
			motor[hDrive] = 60;
		}
		else if (vexRT(Btn7D) == 1)
		{
			motor[hDrive] = -60;
		}
		else
		{
			motor[hDrive] = 0;
		}

		// Six bar controls
		if (vexRT[Btn6U] == 1)
		{
			motor[lift] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[lift] = -127;
		}
		else
		{
			motor[lift] = 0;
		}

		// Four bar controls
		if (vexRT[Btn5U] == 1)
		{
			motor[mongoRight] = 127;
			motor[mongoLeft] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[mongoRight] = -127;
			motor[mongoLeft] = -127;
		}
		else
		{
			motor[mongoRight] = 0;
			motor[mongoLeft] = 0;
		}

		/*
		// PID Parking Brake
		if (vexRT[Btn8D] == 1)
		{
		brakes = !brakes;
		targetLocationR = SensorValue[rightDrive];
		targetLocationL = SensorValue[leftDrive];
		}

		while (brakes == true)
		{
		if (vexRT[Btn8R] == 1)
		{
		brakes = !brakes;
		}

		// Find error and integrate P into it
		errorR = SensorValue[rightDrive] - targetLocationR;  // Currently just P, we can add on in the future
		drivePowerR = (int)(KpR*errorR);
		errorL = SensorValue[leftDrive] - targetLocationL;
		drivePowerL = (int)(KpL*errorL);


		// Change drive power accoring to sensor value
		while (SensorValue[rightDrive] != targetLocationR || SensorValue[leftDrive] != targetLocationL)
		{
		if (vexRT[Btn8R] == 1)
		{
		brakes = !brakes;
		}
		motor[rightDrive1] = drivePowerR;
		motor[rightDrive2] = drivePowerR;
		motor[rightDrive3] = drivePowerR;
		motor[leftDrive1] = drivePowerL;
		motor[leftDrive2] = drivePowerL;
		motor[leftDrive3] = drivePowerL;
		}
		}*/
	}
}
