#include "tasks.hpp"
using namespace pros;

void move(void* args){
    while (true) {
        // Get average position for all drive-train wheels
        double motorRightPos = (driveRightFront.get_position() + driveRightMiddle.get_position() + driveRightBack.get_position()) / 3.0;
        double motorLeftPos = (driveLeftFront.get_position() + driveLeftMiddle.get_position() + driveLeftBack.get_position()) / 3.0;
        drivePosition = (motorRightPos - motorLeftPos) / 2.0;
        
        // Calculate motor output with PID
        double output = drivePID.calculate(targetDrive, drivePosition);

        if (driveState == DRIVE) {
            driveLeftFront.move(output);
            driveLeftMiddle.move(output);
            driveLeftBack.move(output);
            driveRightFront.move(output);
            driveRightMiddle.move(output);
            driveRightBack.move(output);
        }
    
        delay(TASK_DELAY);
    }
}

void turn(void* args){
    int imuCalibrationThreshold = 100;
    int timerTime = 0;

    while (true) {
        // Wait for IMUs to calibrate
        if (timerTime <= imuCalibrationThreshold){ 
            timerTime++; 
            continue; 
        }

        // Update robot orientation
        orientation = imu.get_rotation();
        
        controller.print(1, 0, "IMU: %f", orientation);

        // Calcuate turn PID
        double output = turnPID.calculate(targetAngle, orientation);

        if (driveState == TURN) {
            driveLeftFront.move(output);
            driveLeftMiddle.move(output);
            driveLeftBack.move(output);
            driveRightFront.move(-output);
            driveRightMiddle.move(-output);
            driveRightBack.move(-output);
        }

        delay(TASK_DELAY);
    }
}

void twobar(void* args) {
    while(true){

        twobarPosition = (ptoMotorRight.get_position() + ptoMotorLeft.get_position()) / 2.0;
        double output = twobarPID.calculate(targetTwobar, twobarPosition);
        
        if (ptoState == TWOBAR){
            ptoMotorRight.move(output);
            ptoMotorLeft.move(output);
        }

        delay(TASK_DELAY);
    }
}

/*
void kicker(void* args) {
    while (true) {
        targetKicker = (distance.get() <= TRIBALL_BOUND) ? KICKER_FIRE : KICKER_DRAWBACK;

        double position = kickerRotation.get_position() / 100.0;
        double output = -kickerPID.calculate(targetKicker, position);

        kickerLeft.move(output);
        kickerRight.move(output);
    }   
}
*/