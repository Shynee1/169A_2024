#pragma once
#include "globals.hpp"
#include "autonomous.hpp"

/**
 * Entry point for operator (driver) control
 * Executed in new VEX task (thread)
 * Runs after autonomous during a competition
*/
void opcontrol();
void handle_two_bar();
void handle_pto();