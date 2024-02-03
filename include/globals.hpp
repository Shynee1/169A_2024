#pragma once
#include "main.h"
#include "PID.hpp"

// Utility variables
constexpr int SCREEN_WIDTH = 485;
constexpr int SCREEN_HEIGHT = 260;
constexpr int TASK_DELAY = 20;
constexpr int KICKER_DRAWBACK = 40;
constexpr int KICKER_FIRE = KICKER_DRAWBACK + 20;
constexpr int TRIBALL_BOUND = 50;
constexpr char* PAGES = "Auto Selector\nPlaceholder";

// Controller bindings
constexpr auto FOUR_BAR_MANUAL_UP = pros::E_CONTROLLER_DIGITAL_L1;
constexpr auto FOUR_BAR_MANUAL_DOWN = pros::E_CONTROLLER_DIGITAL_L2;

// VEX ports
constexpr int DRIVE_RIGHT_FRONT_PORT = 1;
constexpr int DRIVE_RIGHT_MIDDLE_PORT = 6;
constexpr int DRIVE_RIGHT_BACK_PORT = 10;
constexpr int DRIVE_LEFT_FRONT_PORT = 12;
constexpr int DRIVE_LEFT_MIDDLE_PORT = 13;
constexpr int DRIVE_LEFT_BACK_PORT = 14;
constexpr int FOURBAR_RIGHT_PORT = 20;
constexpr int FOURBAR_LEFT_PORT = 8;
constexpr int KICKER_RIGHT_PORT = 0;
constexpr int KICKER_LEFT_PORT = 0;
constexpr int KICKER_ROTATION_PORT = 19;
constexpr int IMU_PORT = 17;
constexpr int DISTANCE_PORT = 0;

// VEX declarations (defined in globals.cpp)
extern pros::Controller controller;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightMiddle;
extern pros::Motor driveRightBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftMiddle;
extern pros::Motor driveLeftBack;
extern pros::Motor fourBarRight;
extern pros::Motor fourBarLeft;
extern pros::Motor kickerRight;
extern pros::Motor kickerLeft;
extern pros::Rotation kickerRotation;
extern pros::IMU imu;
extern pros::Distance distance;

extern PID movePID;
extern PID turnPID;
extern PID kickerPID;

// LVGL Declarations
extern std::array<lv_style_t, 2> standardButtonStyle;
extern std::array<lv_style_t, 2> redButtonStyle;
extern std::array<lv_style_t, 2> blueButtonStyle;
extern lv_obj_t* dropdown;
extern lv_obj_t* currentPage;
extern lv_obj_t* autoSelector;
extern lv_obj_t* displayPage;
LV_IMG_DECLARE(logo);


// Runtime variable declarations
extern double orientation, previousOrientation, position, previousPosition; 
extern double targetMove, targetAngle, targetKicker;
extern int autoDriveState;
