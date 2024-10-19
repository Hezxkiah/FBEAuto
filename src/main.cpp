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
  rightFrontM.resetPosition();
  rightBackM.resetPosition();

  while(rightDrive.position(degrees) < howFar)
  {
    //Checking distance from wall
    if(DSensor.objectDistance(inches) < 10)
    {
      IneSen.resetRotation();
      if (DSensor2.objectDistance(inches) > 10)
      {
        while(fabs(IneSen.rotation(degrees)) > 0 && fabs(IneSen.rotation(degrees)) < 91)
        {
          leftMotor.spin(reverse,5,velocityUnits::pct);
          rightMotor.spin(fwd,5,velocityUnits::pct);
        }
      }
      else
      {
        while(fabs(IneSen.rotation(degrees)) > 0 && fabs(IneSen.rotation(degrees)) < 91)
        {
          leftMotor.spin(fwd,5,velocityUnits::pct);
          rightMotor.spin(reverse,5,velocityUnits::pct);
        }
      }
      
    }
    
    else if (IneSen.heading(degrees) > 1 && IneSen.heading(degrees)<45)
    {
      leftMotor.spin(fwd,howFast-5,velocityUnits::pct);
      rightMotor.spin(fwd,howFast,velocityUnits::pct);
    }
    else if(IneSen.heading(degrees) < 359 && IneSen.heading(degrees) > 359-45)
    {
      leftMotor.spin(fwd,howFast,velocityUnits::pct);
      rightMotor.spin(fwd,howFast-5,velocityUnits::pct);
    }
    else
    {
      leftMotor.spin(fwd,howFast,velocityUnits::pct);
      rightMotor.spin(fwd,howFast,velocityUnits::pct);
    }
  }
  leftMotor.stop(brake);
  rightMotor.stop(brake);
}

//Moving forward left gear train function



//Turning left function
void turnL(int turnLD,int turnLS)
{
  IneSen.resetRotation();
  while(fabs(IneSen.rotation(degrees)) < -turnLD)
  {
    leftMotor.spin(reverse,turnLS,velocityUnits::pct);
    rightMotor.spin(fwd,turnLS,velocityUnits::pct);
  }
  leftMotor.stop(brake);
  rightMotor.stop(brake);
}

//Turning right function
void turnR(int turnRD, int turnRS)
{
  IneSen.resetRotation();
  while(fabs(IneSen.rotation(degrees)) < turnRD)
  {
    leftMotor.spin(forward,turnRS,velocityUnits::pct);
    rightMotor.spin(reverse,turnRS,velocityUnits::pct);
  }
  leftMotor.stop(brake);
  rightMotor.stop(brake);
}


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
 rightMotor.resetRotation();
 leftMotor.resetRotation();
 //Displays heading information to the screen
 task myTask1 = task(Hinformation);
 //Displays left rotaiton units and Displays left rotation using inertial sensor
 task myTask2 = task(LR_information);
 //Displays right rotation units and Displays right rotaiton using inertial sensor
 task myTask3 = task(RR_information);
 //Distance Information
 task myTask4 = task(dInformation);

 
   //Continues to drive forward
   while (1)
   {
     //Makes sure to not do a full 180...(THIS MIGHT BE THE PROBLEM BUT DON'T CHANGE)
     moveFWD(343*5,15);
   }
   
 
}
