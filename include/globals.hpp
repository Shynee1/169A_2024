#pragma once
#include "main.h"
#include "PID.hpp"

// Utility variables
constexpr int TASK_DELAY = 20;
constexpr int KICKER_DRAWBACK = 40;
constexpr int KICKER_FIRE = KICKER_DRAWBACK + 20;
constexpr int TRIBALL_BOUND = 50;
constexpr double PI = 3.14159265358979323846;
constexpr double WHEEL_DIAMETER = 2.75;

// PID constants
constexpr double driveP = 1.0;
constexpr double driveI = 0.0;
constexpr double driveD = 3.0;

constexpr double turnP = 3.0;
constexpr double turnI = 0.0;
constexpr double turnD = 2.0;

constexpr double twobarP = 2.0;
constexpr double twobarI = 0.0;
constexpr double twobarD = 0.0;

// Controller bindings
constexpr auto FOUR_BAR_MANUAL_UP = pros::E_CONTROLLER_DIGITAL_L1;
constexpr auto FOUR_BAR_MANUAL_DOWN = pros::E_CONTROLLER_DIGITAL_L2;
constexpr auto PTO_TOGGLE = pros::E_CONTROLLER_DIGITAL_A;
constexpr auto VERTICAL_WING_TOGGLE = pros::E_CONTROLLER_DIGITAL_X;
constexpr auto HORIZONTAL_WING_TOGGLE = pros::E_CONTROLLER_DIGITAL_Y;
constexpr auto INTAKE_FOWARD_MANUAL = pros::E_CONTROLLER_DIGITAL_R1;
constexpr auto INTAKE_BACKWARD_MANUAL = pros::E_CONTROLLER_DIGITAL_R2;

// VEX ports
constexpr int DRIVE_RIGHT_FRONT_PORT = 6;
constexpr int DRIVE_RIGHT_MIDDLE_PORT = 15;
constexpr int DRIVE_RIGHT_BACK_PORT = 19;
constexpr int DRIVE_LEFT_FRONT_PORT = 1;
constexpr int DRIVE_LEFT_MIDDLE_PORT = 13;
constexpr int DRIVE_LEFT_BACK_PORT = 11;
constexpr int PTO_MOTOR_RIGHT_PORT = 20;
constexpr int PTO_MOTOR_LEFT_PORT = 12;  
constexpr int KICKER_ROTATION_PORT = 19;
constexpr int INTAKE_PORT = 5;
constexpr int IMU_PORT = 4;
constexpr int DISTANCE_PORT = 0;
constexpr char PTO_PISTON_PORT = 'H';
constexpr char VERTICAL_WINGS_PORT = 'B';
constexpr char HORIZONTAL_WINGS_PORT = 'C';

// VEX declarations (defined in globals.cpp)
extern pros::Controller controller;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightMiddle;
extern pros::Motor driveRightBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftMiddle;
extern pros::Motor driveLeftBack;
extern pros::Motor ptoMotorRight;
extern pros::Motor ptoMotorLeft;
extern pros::Motor intake;
extern pros::Rotation kickerRotation;
extern pros::IMU imu;
extern pros::Distance distance;
extern pros::ADIDigitalOut ptoPiston;
extern pros::ADIDigitalOut verticalWings;
extern pros::ADIDigitalOut horizontalWings;

extern PID drivePID;
extern PID turnPID;
extern PID twobarPID;

// LVGL Declarations
extern std::array<lv_style_t, 2> standardButtonStyle;
extern std::array<lv_style_t, 2> redButtonStyle;
extern std::array<lv_style_t, 2> blueButtonStyle;
extern std::array<lv_obj_t*, 3> pages;
extern lv_fs_drv_t drive;
extern lv_obj_t* currentPage;
extern lv_obj_t* dropdown;
extern lv_obj_t* awpButton;
extern lv_obj_t* elimButton;
extern lv_obj_t* logoImage;
extern lv_obj_t* mikeFace;
extern lv_obj_t* debugLabel;

// Runtime variable declarations
extern double drivePosition, orientation, twobarPosition; 
extern double targetDrive, targetAngle, targetTwobar;
extern int driveState, ptoState;
extern int autoSelectorIndex;

// Utility function declarations
void tare_motors();
void toggle_pto();

// State definitions
enum DriveState {
    CONTROLLER, 
    DRIVE,
    TURN
};

enum PtoState {
    TRANSITION,
    TWOBAR, 
    KICKER
};