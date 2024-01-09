#pragma once
#include "main.h"

// Utility variables
constexpr int TASK_DELAY = 20;

// VEX ports
constexpr int RIGHT_FRONT_PORT = 1;
constexpr int RIGHT_MIDDLE_PORT = 2;
constexpr int RIGHT_BACK_PORT = 3;
constexpr int LEFT_FRONT_PORT = 4;
constexpr int LEFT_MIDDLE_PORT = 5;
constexpr int LEFT_BACK_PORT = 6;

// VEX declarations (defined in globals.cpp)
extern pros::Controller controller;
extern pros::Motor rightMotorFront;
extern pros::Motor rightMotorMiddle;
extern pros::Motor rightMotorBack;
extern pros::Motor leftMotorFront;
extern pros::Motor leftMotorMiddle;
extern pros::Motor leftMotorBack;