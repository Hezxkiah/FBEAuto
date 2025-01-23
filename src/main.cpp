#include "vex.h"
#include "math.h"


using namespace vex;

int turnS;

//Grabbing information
int information()
{
  //Prints Information
  while(1)
  {
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Rotation: ",IneSen.rotation(degrees));
    Brain.Screen.setCursor(1,2);
    Brain.Screen.print("Heading: ",IneSen.heading(degrees));
  }
}


//Moving forward right gear train function
void moveFWD(int howFar,int howFast)
{
  //Resets the posistion of the right front and back motors
  leftDriveT.resetPosition();
  rightDriveT.resetPosition();

  //Checks to make sure that the robot drives straight
  while(rightDriveT.position(degrees) && leftDriveT.position(degrees) < howFar)
  {
    IneSen.resetRotation();
    //If vere left
    if((IneSen.rotation(degrees)) < 0 && (IneSen.rotation(degrees)) > -91)
    {
      leftDriveT.spin(forward,5,velocityUnits::pct);
      rightDriveT.spin(reverse,5,velocityUnits::pct);
    }
    //If vere right
    else if ((IneSen.rotation(degrees)) > 0 && (IneSen.rotation(degrees)) < 91)
    {
      leftDriveT.spin(reverse,5,velocityUnits::pct);
      rightDriveT.spin(forward,5,velocityUnits::pct);
    }
    //Go Straight
    else
    {
      leftDriveT.spin(forward,howFast,velocityUnits::pct);
      rightDriveT.spin(forward,howFast,velocityUnits::pct);
    }
  }
}

//Turning 
void turnD(int turnD)
{
 IneSen.resetRotation();
 while(fabs(IneSen.rotation(degrees)) < turnD)
 {
   //Grabs rotation for slow down
   int slowMo = IneSen.rotation(degrees);

   //Slows down the robot
   int turnS = (1 - slowMo/turnD)*10;

   //Turn Right
   if(turnD > 0)
   {
     leftDriveT.spin(fwd,turnS,velocityUnits::pct);
     rightDriveT.spin(reverse,turnS,velocityUnits::pct);
   }

   //Turn Left
   else
   {
     leftDriveT.spin(fwd,turnS,velocityUnits::pct);
     rightDriveT.spin(reverse,turnS,velocityUnits::pct);
   }
 }
 leftDriveT.stop(brake);
 rightDriveT.stop(brake);
}


//MAIN PROGRAM
int main()
{
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();

 //Calibrate
 IneSen.calibrate();
 waitUntil(!IneSen.isCalibrating());

 //Sets Inertial Sensor to 0 degrees
 task MyTask1 = task(information);
 IneSen.setHeading(0,degrees);
 
 //Actual Drive Portion
 moveFWD(360,10);
 turnD(90);
}
