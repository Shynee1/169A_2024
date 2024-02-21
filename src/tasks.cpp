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

        previousPosition = drivePosition;
    
        delay(TASK_DELAY);
    }
}

void turn(void* args){
    while (true) {
        // Update robot orientation
        orientation = imu.get_rotation();
        // Wait for IMU to calibrate
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

        previousOrientation = orientation;

        delay(TASK_DELAY);
    }
}

void stationary_check(void* args) {
    double stationaryBound = 0.7;

    while (true) {
        isStationary = 
            abs(orientation - previousOrientation) >= stationaryBound && 
            abs(drivePosition - previousPosition) >= stationaryBound;

        //debug_print(0, "Stationary: " + std::to_string(isStationary));

        delay(TASK_DELAY);
    }
}