#include "vex.h"
#include "math.h"


using namespace vex;


//Moving forward right gear train function
void moveFWD(int howFar,int howFast)
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
      leftFrontM.spin(forward,howFast,velocityUnits::pct);
      leftBackM.spin(forward,howFast,velocityUnits::pct);
      rightFrontM.spin(forward,howFast,velocityUnits::pct);
      rightBackM.spin(forward,howFast,velocityUnits::pct);
    }
  }
}

//Turning left function
void turnL(int turnLD,int turnLS)
{
  IneSen.resetRotation();
  while(fabs(IneSen.rotation(degrees)) < -turnLD)
  {
    rightDrive.spin(reverse,turnLS,velocityUnits::pct);
    leftDrive.spin(forward,turnLS,velocityUnits::pct);
  }
  rightDrive.stop(brake);
  leftDrive.stop(brake);
}

//Turning right function
void turnR(int turnLD,int turnLS)
{
  IneSen.resetRotation();
  while(fabs(IneSen.rotation(degrees)) < -turnLD)
  {
    rightDrive.spin(forward,turnLS,velocityUnits::pct);
    leftDrive.spin(reverse,turnLS,velocityUnits::pct);
  }
  rightDrive.stop(brake);
  leftDrive.stop(brake);
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
 rightDrive.resetPosition();
 leftDrive.resetPosition();
 
 //Actual Drive Portion
 while (1)
 {
   moveFWD(343*5,15);
 }
}
