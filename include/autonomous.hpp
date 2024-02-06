#pragma once
#include "globals.hpp"
#include "brainutility.hpp"

/**
 * Entry point for autonomous code
 * Executed in new VEX task (thread)
 * Runs before opcontrol (during competition)
*/
void autonomous();
void prog();
void close_awp();
void close_elim();
void far_awp();
void far_elim();
void setDriveTarget(int encoderUnits);
void setAngleTargetRelative(double degrees);
void setAngleTargetAbsolute(double degrees);
void setTwobarTargetRelative(int encoderUnits);
void setTwobarTargetAbsolute(int encoderUnits);