#pragma once
#include "globals.hpp"

/**
 * Entry point for operator (driver) control
 * Runs as a PROS task (new thread)
 * Will execute after autonomous during a competition
*/
void opcontrol();