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
    close_awp();
}

void prog() {
    


}

void close_awp() {
    horizontalWings.set_value(true);
    pros::delay(500);
    horizontalWings.set_value(false);
    pros::delay(500);
    setAngleTargetAbsolute(19);
    pros::delay(500);
    setDriveTargetUnits(1465);
    intake.move(127);
    pros::delay(2000);
    setDriveTargetUnits(-1525);
    pros::delay(2000);
    intake.move(0);
    verticalWings.set_value(true);
    pros::delay(100);
    turnPID.set_kP(1.0);
    turnPID.set_kD(1.0);
    setAngleTargetAbsolute(-100);
    pros::delay(750);
    verticalWings.set_value(false);
    setAngleTargetAbsolute(100);
    pros::delay(1000);
    intake.move(-127);
    pros::delay(500);
    intake.move(0);
    setAngleTargetAbsolute(-70);
    pros::delay(1000);
    setDriveTargetUnits(-1000);
    pros::delay(1000);
    turnPID.set_kP(3.0);
    setAngleTargetAbsolute(-92.5);
    pros::delay(750);
    setDriveTargetUnits(-325);
}
void close_elim() {

}
void far_awp() {
    
}
void far_elim() {
    
}

void setDriveTargetUnits(int encoderUnits) {
    targetDrive = drivePosition + encoderUnits;
    driveState = DRIVE;
}

void setDriveTargetInches(double distance){
    double encoderUnits = ((360.0 * distance) / (WHEEL_DIAMETER * PI)) * (5.0/6.0);
    targetDrive += encoderUnits;
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


