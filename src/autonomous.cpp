#include "autonomous.hpp"

void autonomous() {
    driveState = DRIVE;
    tare_motors();
    /*
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
    } */
    close_awp();
}

void prog() {
    setDriveTargetUnits(500);
    wait(95);
    intake.move(127);
    turnPID.set_kP(0);
    turnPID.set_kP(turnP);
    verticalWings.set_value(true);
    setDriveTargetUnits(-300);
    verticalWings.set_value(true);
    wait(95);
    setDriveTargetUnits(500);
    wait(95);
    setAngleTargetAbsolute(90);
    wait(95);
    setAngleTargetAbsolute(180);
    wait(95);
    setDriveTargetUnits(300);
    wait(95);

    /*
    wait(97);
    setDriveTargetUnits(-100);
    wait(95);
    setDriveTargetUnits(500);
    wait(95);
    setDriveTargetUnits(-500);
    wait(95);
    verticalWings.set_value(true);
    */
}

void close_awp() {
    turnPID.set_kP(3.0);
    turnPID.set_kD(1.0);
    horizontalWings.set_value(true);
    pros::delay(500);
    horizontalWings.set_value(false);
    setDriveTargetUnits(75);
    pros::delay(500);
    setAngleTargetAbsolute(17);
    wait(95);
    turnPID.set_kP(turnP);
    turnPID.set_kD(turnD);
    setDriveTargetUnits(1415);
    intake.move(127);
    wait(95);
    pros::delay(750);
    intake.move(0);
    drivePID.set_kD(4.0);
    setDriveTargetUnits(-1570);
    pros::delay(2000);
    drivePID.set_kD(driveD);
    verticalWings.set_value(true);
    pros::delay(100);
    setAngleTargetAbsolute(-100);
    pros::delay(1000);
    verticalWings.set_value(false);
    setAngleTargetAbsolute(100);
    pros::delay(1000);
    intake.move(-127);
    pros::delay(500);
    intake.move(0);
    setAngleTargetAbsolute(-40);
    pros::delay(1000);
    setDriveTargetUnits(-500);
    pros::delay(1000);
    turnPID.set_kP(3.0);
    turnPID.set_kD(1.0);
    setAngleTargetAbsolute(-92.5);
    pros::delay(500);
    setDriveTargetUnits(-1000);
}

void close_elim() {

}

void far_awp() {
    
}

void far_elim() {
    intake.move(127);
    setDriveTargetUnits(50);
    pros::delay(500);
    setDriveTargetUnits(400);
    pros::delay(2000);
    intake.move(0);
    setDriveTargetUnits(-1090);
    pros::delay(2000);
    setAngleTargetAbsolute(-45);
    pros::delay(1000);
    verticalWings.set_value(true);
    setDriveTargetUnits(-650);
    pros::delay(1000);
    verticalWings.set_value(false);
    setDriveTargetUnits(100);
    pros::delay(1000);
    setDriveTargetUnits(-350);
    pros::delay(1000);
    setAngleTargetAbsolute(-85);
    pros::delay(1000);
    setDriveTargetUnits(-700);
    pros::delay(1000);
    setDriveTargetUnits(300);
    pros::delay(1000);
    turnPID.set_kD(3.0);
    setAngleTargetAbsolute(85);
    pros::delay(2000);
    setDriveTargetUnits(400);
    pros::delay(1000);
    setDriveTargetUnits(-500);
}

void wait(int percentComplete) {
    // Convert percent complete to a multiplier (95 -> 0.05)
    double errorMultiplier = (100 - percentComplete) / 100.0;

    // Delay if drive pid error is not within error threshold
    while (driveState == DRIVE &&
           (abs(targetDrive - drivePosition) >= 
           (targetDrive * errorMultiplier))){
            pros::delay(10);
            debug_print(0, "Wait type: Drive");
        }
       
    
    // Delay if turn pid error is not within error threshold
    while (driveState == TURN &&
           (angleDifference(orientation, targetAngle) >=
           (targetAngle * errorMultiplier))){
            debug_print(0, "Wait type: Turn");
             pros::delay(10);
        }
    
    debug_print(0, "Wait type: Neither");
    // Add small delay to complete movement
    pros::delay(300 * errorMultiplier);
    debug_print(0, "Wait type: Done");
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

double angleDifference(double a, double b) {
    double diff =  fmod(round((b - a + 180.0)), 360) - 180.0;
    return diff < -180.0 ? diff + 360.0 : diff;
}

