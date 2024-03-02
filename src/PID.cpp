#include "PID.hpp"

PID::PID(double kP, double kI, double kD) {\
    // Set global PID constants
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
}

double PID::calculate(double target, double current) {
    // Update error, derivative, integral
    error = target - current;
    derivative = error - prevError;
    integral += error;

    prevError = error;
    
    // Calculate motor output using PID
    return (error * kP) + (derivative * kD) + (integral * kI);
}

void PID::set_kP(double newkP) {
    this->kP = newkP;
}
void PID::set_kD(double newkD) {
    this->kD = newkD;
}
void PID::set_kI(double newkI) {
    this->kI = newkI;
}