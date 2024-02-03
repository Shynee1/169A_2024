#include "globals.hpp"

// VEX definitions (declared in globals.hpp)
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor driveRightFront(DRIVE_RIGHT_FRONT_PORT, true);
pros::Motor driveRightMiddle(DRIVE_RIGHT_MIDDLE_PORT, true);
pros::Motor driveRightBack(DRIVE_RIGHT_BACK_PORT, true);
pros::Motor driveLeftFront(DRIVE_LEFT_FRONT_PORT);
pros::Motor driveLeftMiddle(DRIVE_LEFT_MIDDLE_PORT);
pros::Motor driveLeftBack(DRIVE_LEFT_BACK_PORT);
pros::Motor fourBarRight(FOURBAR_RIGHT_PORT);
pros::Motor fourBarLeft(FOURBAR_LEFT_PORT, true);
pros::Motor kickerRight(KICKER_RIGHT_PORT);
pros::Motor kickerLeft(KICKER_LEFT_PORT, true);
pros::Rotation kickerRotation(KICKER_ROTATION_PORT);
pros::IMU imu(IMU_PORT);
pros::Distance distance(DISTANCE_PORT);

PID movePID(1, 0, 3, 0);
PID turnPID(2, 0.0, 1.5, 0);
PID kickerPID(40, 0, 0, 0);

// LVGL Definitions
std::array<lv_style_t, 2> standardButtonStyle;
std::array<lv_style_t, 2> redButtonStyle;
std::array<lv_style_t, 2> blueButtonStyle;
lv_obj_t* dropdown;
lv_obj_t* currentPage;
lv_obj_t* autoSelector;
lv_obj_t* logoDisplay;

// Runtime variable definitions
bool autonomousDriveControl = false;
double orientation, previousOrientation, position, previousPosition = 0.0;
double targetMove, targetAngle = 0.0;
int autoDriveState = 0;