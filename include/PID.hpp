#pragma once
#include "main.h"

class PID {
private:
    // Constants
    double kP, kI, kD;
    // Utility variables
    double error, prevError, integral, derivative = 0.0;
public:
    /**
     * Constructor to initialize PID constants
     * @param kP Proportional constant
     * @param kI Integral constant
     * @param kD Derivative constant
    */
    PID (double kP, double kI, double kD);
    /**
     * Calculate motor output using PID control
     * @param target Desired robot position after movement
     * @param current Average of current motor positions
     * @return Voltage value for motor to run at
    */
    double calculate(double target, double current);
    // Helper functions to change constants
    void set_kP(double newkP);
    void set_kD(double newkD);
    void set_kI(double newkI);
};