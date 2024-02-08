#include "globals.hpp"

// VEX definitions (declared in globals.hpp)
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor driveRightFront(DRIVE_RIGHT_FRONT_PORT, true);
pros::Motor driveRightMiddle(DRIVE_RIGHT_MIDDLE_PORT, true);
pros::Motor driveRightBack(DRIVE_RIGHT_BACK_PORT, true);
pros::Motor driveLeftFront(DRIVE_LEFT_FRONT_PORT);
pros::Motor driveLeftMiddle(DRIVE_LEFT_MIDDLE_PORT);
pros::Motor driveLeftBack(DRIVE_LEFT_BACK_PORT);
pros::Motor intake(INTAKE_PORT);
pros::Motor ptoMotorRight(PTO_MOTOR_RIGHT_PORT);
pros::Motor ptoMotorLeft(PTO_MOTOR_LEFT_PORT, true);
pros::Rotation kickerRotation(KICKER_ROTATION_PORT);
pros::IMU imu(IMU_PORT);
pros::Distance distance(DISTANCE_PORT);
pros::ADIDigitalOut ptoPiston(PTO_PISTON_PORT);
pros::ADIDigitalOut verticalWings(VERTICAL_WINGS_PORT);
pros::ADIDigitalOut horizontalWings(HORIZONTAL_WINGS_PORT);

PID drivePID(driveP, driveI, driveD);
PID turnPID(turnP, turnI, turnD);
PID twobarPID(twobarP, twobarI, twobarD);

// LVGL Definitions
std::array<lv_style_t, 2> standardButtonStyle;
std::array<lv_style_t, 2> redButtonStyle;
std::array<lv_style_t, 2> blueButtonStyle;
std::array<lv_obj_t*, 3> pages;
lv_fs_drv_t drive;
lv_obj_t* currentPage;
lv_obj_t* dropdown;
lv_obj_t* awpButton;
lv_obj_t* elimButton;
lv_obj_t* logoImage;
lv_obj_t* mikeFace;
lv_obj_t* debugLabel;

// Runtime variable definitions
double drivePosition, orientation, twobarPosition = 0.0;
double targetDrive, targetAngle, targetTwobar = 0.0;
int driveState = CONTROLLER;
int ptoState = KICKER;
int autoSelectorIndex = 0;

// Utility function defintions
void tare_motors() {
    driveRightFront.tare_position();
    driveRightMiddle.tare_position();
    driveRightBack.tare_position();
    driveLeftBack.tare_position();
    driveLeftMiddle.tare_position();
    driveLeftBack.tare_position();
    ptoMotorRight.tare_position();
    ptoMotorLeft.tare_position();
}

void toggle_pto() {
    bool kicker = (ptoState == KICKER);
    ptoState = TRANSITION;

    ptoMotorRight.move(-127);
    ptoMotorLeft.move(-127);

    ptoPiston.set_value(kicker);
    pros::delay(100);

    ptoMotorRight.move(0);
    ptoMotorLeft.move(0);
    
    ptoState = kicker ? TWOBAR : KICKER;
}