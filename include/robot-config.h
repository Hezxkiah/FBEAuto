using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor IntakeMotor;
extern controller Controller1;
extern motor leftFrontM;
extern motor leftBackM;
extern motor rightFrontM;
extern motor rightBackM;
extern digital_out airFist;
extern motor_group rightDrive;
extern distance DSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );