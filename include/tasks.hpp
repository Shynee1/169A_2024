#pragma once
#include "globals.hpp"
#include "autonomous.hpp"
#include "PID.hpp"

/**
 * Task dedicated to moving the robot during autonomous.
 * Constantly updates position, calculates output, moves motors
 * AutoDriveState of DRIVE needed to run
 * @param args Any arguments to be passed to the task
 * @return
*/
void move(void* args);
/**
 * Task dedicated to turning the robot during autonomous.
 * Constantly updates orientation, calculates output, turns motors
 * AutoDriveState of TURN needed to run
 * @param args Any arguments to be passed to the task
 * @return
*/
void turn(void* args);
/**
 * Checks if the robot is stationary
 * Delta position and delta orientation need to be less than threshold
 * @param args Any arguments to be passed to the task
 * @return
*/
void stationary_check(void* args);