#pragma config(Sensor, in6,    adjusterPot,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEnc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEnc,        sensorQuadEncoder)
#pragma config(Sensor, dgtl10, enc1,           sensorQuadEncoder)
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
// PIDExample.c
//
// Author: Justin Marple with Team BNS
// Contact: jmarple@umass.edu
// Date: 01/07/2015
//
// This example file shows how to use
// the PID Controller built into the
// BNS Library
//
// Dependencies:
//   BNSLib.h in previous directory
//
// ------------------------------------------------------------------------
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// The author can be contacted by email at jmarple@umass.edu
//
// ------------------------------------------------------------------------
#include "pid.c"

void moveStraight(int reqDistance)
{
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	SensorValue[rightEnc] = 0;

	// The PID controller that will be used
	// The basic usage of this PID controller is as following:
	//
	// PID pid1;
	// PIDInit(&pid1, PConstant, IConstant, DConstant);
	// float feedback = PIDCompute(&pid1, your_error);
	//
	PID pid1;
	PIDInit(&pid1, 0.4, 0.03, 0.1); // Set P, I, and D constants

	// We start at 0 units and want to reach 100 units
	int targetDistance = reqDistance * (360/12.56);
	int currentDistance;

	// Output instructions to view the PID response
	writeDebugStreamLine("*** Copy/paste all the results in the debug window to Excel and graph what the PID response looks like! ***");

	// Loop through many times so we can graph
	//  the PID loop
	for(int i = 0; i < 1000; i++)
	{
		currentDistance = SensorValue[rightEnc];
		// This calculates how far off we are from the true value
		//  The PID will return a response that will hopefully minimize this error over time
		float pidResult = PIDCompute(&pid1, targetDistance - currentDistance);

		// Add pid to motor value
		motor[frontLeft]   = pidResult;
		motor[midLeft]     = pidResult;
		motor[backLeft]    = pidResult;
		motor[frontRight]  = pidResult;
		motor[midRight]    = pidResult;
		motor[backRight]   = pidResult;

		// There is a bug in RobotC where if you print too fast,
		//   you might get weird characters at random
		delay( reqDistance / 360 );
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
}

void moveTurn(int reqDistance)
{
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	SensorValue[rightEnc] = 0;

	// The PID controller that will be used
	// The basic usage of this PID controller is as following:
	//
	// PID pid1;
	// PIDInit(&pid1, PConstant, IConstant, DConstant);
	// float feedback = PIDCompute(&pid1, your_error);
	//
	// We start at 0 units and want to reach 100 units

	int currentDistance;

	PID pid1;
	PIDInit(&pid1, 0.4, 0.03, 0.1); // Set P, I, and D constants


	// Loop through many times so we can graph
	//  the PID loop
	for(int i = 0; i < 1000; i++)
	{
		currentDistance = SensorValue[rightEnc];
		// This calculates how far off we are from the true value
		//  The PID will return a response that will hopefully minimize this error over time
		float pidResult = PIDCompute(&pid1, reqDistance - currentDistance);

		// Add pid to motor value
		motor[frontLeft]   = pidResult;
		motor[midLeft]     = pidResult;
		motor[backLeft]    = pidResult;
		motor[frontRight]  = pidResult;
		motor[midRight]    = pidResult;
		motor[backRight]   = pidResult;

		// There is a bug in RobotC where if you print too fast,
		//   you might get weird characters at random
		delay(abs(reqDistance)/360 );
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

}
