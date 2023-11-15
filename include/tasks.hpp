#pragma once
#include "globals.hpp"

void trackPosition();
void updateOdometry(void* args);
void moveTo(void* args);
void turnTo(void* args);
void lookAt(void* args);
void stationaryCheck(void* args);