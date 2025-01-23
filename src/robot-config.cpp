#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor IntakeMotor = motor(PORT6, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out airFirst = digital_out(Brain.ThreeWirePort.A);
motor stakeMotor = motor(PORT21, ratio18_1, true);
motor leftDriveTMotorA = motor(PORT1, ratio6_1, false);
motor leftDriveTMotorB = motor(PORT2, ratio6_1, false);
motor_group leftDriveT = motor_group(leftDriveTMotorA, leftDriveTMotorB);
motor rightDriveTMotorA = motor(PORT9, ratio6_1, true);
motor rightDriveTMotorB = motor(PORT10, ratio6_1, true);
motor_group rightDriveT = motor_group(rightDriveTMotorA, rightDriveTMotorB);
inertial IneSen = inertial(PORT20);
digital_out airFist = digital_out(Brain.ThreeWirePort.A);

// VEXcode generated functions
bool RemoteControlCodeEnabled = true;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}