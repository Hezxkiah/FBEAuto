/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\hezek                                            */
/*    Created:      Mon Jan 29 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftMotor            motor         3               
// rightMotor           motor         2               
// IneSen               inertial      1               
// DSensor              distance      10              
// DSensor2             distance      20              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"
#include "math.h"


using namespace vex;


//Moving forward right gear train function
void moveFWD_Right(int howFar,int howFast)
{
  //Resets the posistion of the right front and back motors
  rightFrontM.resetPosition();
  rightBackM.resetPosition();

  //Checks to make sure that the robot drives straight
  while(rightDrive.position(degrees) && leftDrive.position(degrees) < howFar)
  {
    IneSen.resetRotation();
    //If vere left
    if((IneSen.rotation(degrees)) < 0 && (IneSen.rotation(degrees)) > -91)
    {
      leftFrontM.spin(forward,5,velocityUnits::pct);
      leftBackM.spin(forward,5,velocityUnits::pct);
      rightFrontM.spin(reverse,5,velocityUnits::pct);
      rightBackM.spin(reverse,5,velocityUnits::pct);
    }
    //If vere right
    else if ((IneSen.rotation(degrees)) > 0 && (IneSen.rotation(degrees)) < 91)
    {
      leftFrontM.spin(reverse,5,velocityUnits::pct);
      leftBackM.spin(reverse,5,velocityUnits::pct);
      rightFrontM.spin(forward,5,velocityUnits::pct);
      rightBackM.spin(forward,5,velocityUnits::pct);
    }
    else
    {
      leftFrontM.spin(fwd,howFast,velocityUnits::pct);
      leftBackM.spin(fwd,howFast,velocityUnits::pct);
      rightFrontM.spin(fwd,howFast,velocityUnits::pct);
      rightBackM.spin(fwd,howFast,velocityUnits::pct);
    }
  }
}

//Moving forward left gear train function



// //Turning left function
// void turnL(int turnLD,int turnLS)
// {
//   IneSen.resetRotation();
//   while(fabs(IneSen.rotation(degrees)) < -turnLD)
//   {
//     leftMotor.spin(reverse,turnLS,velocityUnits::pct);
//     rightMotor.spin(fwd,turnLS,velocityUnits::pct);
//   }
//   leftMotor.stop(brake);
//   rightMotor.stop(brake);
// }

// //Turning right function
// void turnR(int turnRD, int turnRS)
// {
//   IneSen.resetRotation();
//   while(fabs(IneSen.rotation(degrees)) < turnRD)
//   {
//     leftMotor.spin(forward,turnRS,velocityUnits::pct);
//     rightMotor.spin(reverse,turnRS,velocityUnits::pct);
//   }
//   leftMotor.stop(brake);
//   rightMotor.stop(brake);
// }


//MAIN PROGRAM
int main()
{
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 //Calibrate
 while (IneSen.isCalibrating())
 {
   wait (50,msec);
 }
 //Sets Inertial Sensor to 0 degrees
 IneSen.setHeading(0,degrees);
 //Rests left and right rotation
 rightDrive.resetPosition();
 leftDrive.resetPosition();
 //Continues to drive forward
 while (1)
 {
   //Makes sure to not do a full 180...(THIS MIGHT BE THE PROBLEM BUT DON'T CHANGE)
   moveFWD_Right(343*5,15);
 }
}
