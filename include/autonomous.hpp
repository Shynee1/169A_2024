#pragma once
#include "globals.hpp"

/**
 * Entry point for autonomous code
 * Executed in new VEX task (thread)
 * Runs before opcontrol (during competition)
*/
void autonomous();