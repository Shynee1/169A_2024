#pragma once
#include "globals.hpp"

/**
 * Entry point for operator (driver) control
 * Executed in new VEX task (thread)
 * Runs after autonomous during a competition
*/
void opcontrol();
void handle_four_bar();