#include "autonomous.hpp"

void autonomous() {
    driveState = DRIVE;
    tare_motors();
    /*
    debug_print("auto working");

    switch (autoSelectorIndex){
        case PROG_BUTTON_ID:
            prog();
            debug_print(0, "Prog");
            break;
        case (NEAR_BUTTON_ID * AWP_BUTTON_ID):
            close_awp();
            break;
        case (NEAR_BUTTON_ID * ELIM_BUTTON_ID):
            close_elim();
            break;
        case (FAR_BUTTON_ID * AWP_BUTTON_ID):
            far_awp();
            break;
        case (FAR_BUTTON_ID * ELIM_BUTTON_ID):
            far_elim();
            break;
        default:
            debug_print(0, "uh oh!");
            break;
    }*/
    prog();
}

void prog() {
    horizontalWings.set_value(true);
    pros::delay(500);
    horizontalWings.set_value(false);
    pros::delay(500);
    setAngleTargetAbsolute(19);
    pros::delay(1000);
    setDriveTarget(1465);
    intake.move(127);
    pros::delay(2000);
    setDriveTarget(-1490);
    pros::delay(2000);
    intake.move(0);
    verticalWings.set_value(true);
    pros::delay(100);
    setAngleTargetAbsolute(-100);
    pros::delay(1000);
    verticalWings.set_value(false);
    turnPID.set_kP(2.0);
    turnPID.set_kD(1.0);
    setAngleTargetAbsolute(-250);
}

void close_awp() {

}
void close_elim() {

}
void far_awp() {

}
void far_elim() {
    
}

void setDriveTarget(int encoderUnits) {
    targetDrive = drivePosition + encoderUnits;
    driveState = DRIVE;
}

void setAngleTargetRelative(double degrees) {
    targetAngle += degrees;
    driveState = TURN;
}

void setAngleTargetAbsolute(double degrees) {
    targetAngle = degrees;
    driveState = TURN;
}

void setTwobarTargetRelative(int encoderUnits) {
    targetTwobar = twobarPosition + encoderUnits;
}

void setTwobarTargetAbsolute(int encoderUnits) {
    targetTwobar = encoderUnits;
}

