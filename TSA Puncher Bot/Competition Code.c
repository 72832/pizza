#pragma config(Sensor, in6,    adjusterPot,    sensorPotentiometer)
#pragma config(Motor,  port1,           intake,        tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           puncherLeft,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           midRight,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           backRight,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           adjuster,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           midLeft,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           puncherRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393HighSpeed_HBridge, openLoop, reversed)
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

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
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

void moveForward()
{
	motor[frontRight] = 127;
	motor[midRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = 127;
	motor[midLeft] = 127;
	motor[backLeft] = 127;
}

void moveBack()
{
	motor[frontRight] = -127;
	motor[midRight] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = -127;
	motor[midLeft] = -127;
	motor[backLeft] = -127;
}

void rotateRight()
{
	motor[frontRight] = -127;
	motor[midRight] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = 127;
	motor[midLeft] = 127;
	motor[backLeft] = 127;
}

void rotateLeft()
{
	motor[frontRight] = 127;
	motor[midRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = -127;
	motor[midLeft] = -127;
	motor[backLeft] = -127;
}

// Pitches puncher up
void pUp()
{
	motor[adjuster] = 127;
}

// Pitches puncher down
void pDown()
{
	motor[adjuster] = -127;
}

void stopDrive()
{
	motor[frontRight] = 0;
	motor[midRight] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[midLeft] = 0;
	motor[backLeft] = 0;
}

void stopAllMotors()
{
	motor[frontRight] = 0;
	motor[midRight] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[midLeft] = 0;
	motor[backLeft] = 0;
	motor[intake] = 0;
	motor[puncherRight] = 0;
	motor[puncherLeft] = 0;
}

// Auton Functions
void blueNorth()
{

}

void blueSouth()
{

}

void redNorth()
{

}

void redSouth()
{

}

// Just in case no auton is selected
void failSafe()
{
	// Keep this function blank
}

task autonomous()
{
	// Choose Auton
	if (true)
	{
		blueNorth();
	}
	else if (false)
	{
		blueSouth();
	}
	else if (false)
	{
		redNorth();
	}
	else if (false)
	{
		redSouth();
	}
	else
	{
		failSafe();
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

#include "TSA Bot Task Library";

task usercontrol()
{
	while (true)
	{

		// Drive controls
		if (vexRT(Ch2) > 10 || vexRT(Ch2) < -10 || vexRT(Ch3) > 10 || vexRT(Ch3) < -10)
		{
			motor[frontRight] = vexRT[Ch2];
			motor[midRight] = vexRT[Ch2];
			motor[backRight] = vexRT[Ch2];
			motor[frontLeft] = vexRT[Ch3];
			motor[midLeft] = vexRT[Ch3];
			motor[backLeft] = vexRT[Ch3];
		}
		else
		{
			motor[frontRight] = 0;
			motor[midRight] = 0;
			motor[backRight] = 0;
			motor[frontLeft] = 0;
			motor[midLeft] = 0;
			motor[backLeft] = 0;
		}

		if (vexRT(Btn5U) == 1)
		{
			motor[intake] = 127;
		}
		else if (vexRT(Btn5D) == 1)
		{
			motor[intake] = -127;
		}
		else
		{
			motor[intake] = 0;
		}

		if (vexRT(Btn6U) == 1)
		{
			motor[puncherRight] = 127;
			motor[puncherLeft] = 127;
		}
		else
		{
			motor[puncherRight] = 0;
			motor[puncherLeft] = 0;
		}

		if (vexRT(Btn8U) == 1)
		{
			motor[adjuster] = 60;
		}
		else if (vexRT(Btn8D) == 1)
		{
			motor[adjuster] = -60;
		}
		else
		{
			motor[adjuster] = 0;
		}
	}
}
