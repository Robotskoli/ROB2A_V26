/* ---------------------------------------------------------------------------- */
/*                                                                              */                 
/* 	    Project:        Drivetrain Sensing                                      */
/*      Module:         main.cpp                                                */
/*      Author:         VEX                                                     */
/*      Created:        Fri Aug 05 2022                                         */
/*	    Description:    This example will show all of the available commands    */
/*                      for using the Drivetrain                                */
/*                                                                              */                 
/*      Configuration:  V5 Speedbot (Drivetrain 2-motor, No Gyro)               */      
/*                                                                              */                 
/* ---------------------------------------------------------------------------- */

#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;

// Robot configuration code.
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);

int main() {
  // Begin project code
  Drivetrain.drive(forward);

  // Print all Drivetrain sensing values to the screen in an infinite loop
  while (true) {
    // Clear the screen and set the cursor to top left corner on each loop
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Brain.Screen.print("Velocity: %.2f", Drivetrain.velocity(percent));
    Brain.Screen.newLine();

    Brain.Screen.print("Current: %.2f", Drivetrain.current(amp));
    Brain.Screen.newLine();

    Brain.Screen.print("Power: %.2f", Drivetrain.power(watt));
    Brain.Screen.newLine();

    Brain.Screen.print("Torque: %.2f", Drivetrain.torque(Nm));
    Brain.Screen.newLine();

    Brain.Screen.print("Efficiency: %.2f ", Drivetrain.efficiency(percent));
    Brain.Screen.newLine();

    Brain.Screen.print("Temperature: %.2f", Drivetrain.temperature(percent));
    Brain.Screen.newLine();

    // A brief delay to allow text to be printed without distortion or tearing
    wait(100,msec);
  }
}

