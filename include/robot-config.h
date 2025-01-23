using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor IntakeMotor;
extern controller Controller1;
extern digital_out airFirst;
extern motor stakeMotor;
extern motor_group leftDriveT;
extern motor_group rightDriveT;
extern inertial IneSen;
extern digital_out airFist;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );