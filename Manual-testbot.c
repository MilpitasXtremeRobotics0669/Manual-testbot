#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     frontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backLeft,      tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma debuggerWindows("joystickSimple")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an Tetrix robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  //waitForStart();

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////


  while (true)
  {
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Conveyorbot - Remote Control
- NOTE: Conveyorbot can be used to pick up 4 of the game objects with its intake and score them
anywhere on the field.
- This program allows you to remotely control your robot using the USB Logitech Joysticks.
- This program also ignores low values that would cause your robot to move when the joysticks fail to
return back to exact center.  You may need to adjust the 'threshold' value to get it just right.

Robot Model(s): TETRIX Conveyorbot (Virtual Worlds)
[I/O Port]          [Name]              [Type]                [Description]
Motor Port D        rightMotor          TETRIX Motor          Right side motor
Motor Port E                leftMotor                       TETRIX Motor                    Left side motor
Motor Port F                armMotor                        TETRIX Motor                    Arm motor
Motor Port G                intakeMotor                 TETRIX Motor                    Intake motor

Sensor Port 2               gyro                                HiTechnic Gyro              HiTechnic Gyro
Sensor Port 3               light                           Light Sensor                    NXT Light Sensor (Active)
Sensor Port 4               sonar                           Sonar Sensor                    NXT Sonar Sensor

*** Competition Information ***
Name:
Competition:
Average FPS (displayed on the Virtual World):

*** Program Information ***
Name of Program:
Type of Robot:
Any other relevant information:
----------------------------------------------------------------------------------------------------*/
    //Integer variable that allows you to specify a "deadzone" where values (both positive or negative)
    //less than the threshold will be ignored.
    int threshold = 10;
while (1==1) //Loop Forever
    {
        //Get the Latest joystick values
        getJoystickSettings(joystick);

        //Driving Control
        if(abs(joystick.joy1_y1) > threshold)     // If the right analog stick's Y-axis readings are either above or below the threshold...
        {
            motor[frontLeft] = joystick.joy1_y1;             // ...move the right side of the robot.
        }
        else                                      // Else the readings are within the threshold, so...
        {
            motor[frontLeft] = 0;                                            // ...stop the right side of the robot.
        }
        if(abs(joystick.joy1_y2) > threshold)     // If the left analog stick's Y-axis readings are either above or below the threshold...
        {
            motor[frontRight] = joystick.joy1_y2;                // ...move the left side of the robot.
        }
        else                                      // Else the readings are within the threshold, so...
        {
            motor[frontRight] = 0;                                           // ...stop the left side of the robot.
        }
        if(abs(joystick.joy1_y1) > threshold)
        {
            motor[backLeft] = joystick.joy1_y1;
        }
        else
        {
            motor[backLeft] = 0;
        }
        if(abs(joystick.joy1_y2) > threshold)
        {
            motor[backRight] = joystick.joy1_y2;
        }
        else
        {
            motor[backRight] = 0;
        }
       }
    }
}
