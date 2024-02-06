#pragma once
#include "main.h"

class PID {
private:
    double kP, kI, kD;
    double error, prevError, integral, derivative = 0.0;
public:
    PID (double kP, double kI, double kD);
    double calculate(double target, double current);
    void set_kP(double newkP);
    void set_kD(double newkD);
    void set_kI(double newkI);
};