#include "tasks.hpp"
using namespace pros;

void move(void* args){
    while (true) {
        // Get average position for all drive-train wheels
        double motorRightPos = (driveRightFront.get_position() + driveRightMiddle.get_position() + driveRightBack.get_position()) / 3.0;
        double motorLeftPos = (driveLeftFront.get_position() + driveLeftMiddle.get_position() + driveLeftBack.get_position()) / 3.0;
        drivePosition = (motorRightPos + motorLeftPos) / 2.0;

        debug_print(1, "Drive Pos: " + std::to_string(drivePosition));
        debug_print(2, "Drive target: " + std::to_string(targetDrive));
        
        // Calculate motor output with PID
        double output = drivePID.calculate(targetDrive, drivePosition);

        debug_print(3, "Drive Output: " + std::to_string(output));
        
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
        if (std::isinf(orientation))
           continue;  
        
        controller.print(1, 0, "IMU: %f", orientation);

        // Calcuate turn PID
        double output = turnPID.calculate(targetAngle, orientation);

        debug_print(4, "Angle Target: " + std::to_string(targetAngle));
        debug_print(5, "Angle Output: " + std::to_string(output));
        debug_print(6, "Angle Value: "  + std::to_string(orientation));

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
        debug_print(0, "Twobar Position: " + std::to_string(twobarPosition));
        double output = twobarPID.calculate(targetTwobar, twobarPosition);
        debug_print(2, "Twobar Output: " + std::to_string(twobarPosition));
        switch (ptoState){
            case TRANSITION:
                debug_print(3, "PTO State: Transition");
                break;
            case TWOBAR:
                debug_print(3, "PTO State: Twobar");
                break;
            case KICKER:
                debug_print(3, "PTO State: Kicker");
                break;
            default:
                debug_print(3, "Uh oh!");
                break;

        }

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