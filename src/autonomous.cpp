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
    far_elim();
}

void prog() {
    setDriveTargetUnits(-550);
    pros::delay(1000);
    turnPID.set_kP(2.0);
    setAngleTargetAbsolute(47);
    pros::delay(1000);
    setDriveTargetUnits(-500);
    pros::delay(1000);
    setDriveTargetUnits(350);
    pros::delay(750);
    setAngleTargetAbsolute(5);
    pros::delay(1000);
    setDriveTargetUnits(300);
    pros::delay(750);
    turnPID.set_kP(turnP);
    setAngleTargetAbsolute(-64);
    pros::delay(1000);
    setDriveTargetUnits(-175);  
    pros::delay(750);
    verticalWings.set_value(true);
    pros::delay(500);
    //ptoMotorRight.move(-110);
    //ptoMotorLeft.move(-110);
    pros::delay(5000);
    verticalWings.set_value(false);
    ptoMotorRight.move(0);
    ptoMotorLeft.move(0);
    setAngleTargetAbsolute(0);
    pros::delay(1000);
    setDriveTargetUnits(500);
    pros::delay(1000);
    turnPID.set_kP(1.5);
    setAngleTargetAbsolute(-45);
    pros::delay(1000);
    /*
    setDriveTargetUnits(2800);
    pros::delay(3000);
    horizontalWings.set_value(true);
    pros::delay(100);
    setAngleTargetAbsolute(-90);
    pros::delay(1000);
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
    setDriveTargetUnits(1375);
    intake.move(127);
    wait(95);
    pros::delay(750);
    intake.move(0);
    drivePID.set_kD(4.0);
    setDriveTargetUnits(-1525);
    pros::delay(2000);
    drivePID.set_kD(driveD);
    verticalWings.set_value(true);
    pros::delay(100);
    setAngleTargetAbsolute(-100);
    pros::delay(1000);
    verticalWings.set_value(false);
    setAngleTargetAbsolute(100);
    pros::delay(1000);
    setDriveTargetUnits(450);
    pros::delay(1000);
    turnPID.set_kP(2.0);
    setAngleTargetAbsolute(90);
    pros::delay(750);
    setDriveTargetUnits(675);  
    pros::delay(1000);
    intake.move(-127);
}

void close_elim() {
    turnPID.set_kP(3.0);
    turnPID.set_kD(1.0);
    horizontalWings.set_value(true);
    pros::delay(500);
    horizontalWings.set_value(false);
    setDriveTargetUnits(75);
    pros::delay(500);
    setAngleTargetAbsolute(16);
    wait(95);
    turnPID.set_kP(turnP);
    turnPID.set_kD(turnD);
    setDriveTargetUnits(1375);
    intake.move(127);
    wait(95);
    pros::delay(750);
    intake.move(0);
    setDriveTargetUnits(-50);
    pros::delay(500);
    setAngleTargetAbsolute(95);
    pros::delay(750);
    horizontalWings.set_value(true);
    pros::delay(100);
    setDriveTargetUnits(620);
    pros::delay(1000);
    setDriveTargetUnits(-620);
    pros::delay(1000);
    horizontalWings.set_value(false);
    pros::delay(100);
    setAngleTargetAbsolute(18);
    pros::delay(1000);
    drivePID.set_kD(4.0);
    setDriveTargetUnits(-1425);
    pros::delay(2000);
    drivePID.set_kD(driveD);
    verticalWings.set_value(true);
    pros::delay(100);
    setAngleTargetAbsolute(-100);
    pros::delay(1000);
    verticalWings.set_value(false);
    setAngleTargetAbsolute(100);
    pros::delay(1000);
    setDriveTargetUnits(450);
    pros::delay(1000);
    turnPID.set_kP(2.0);
    setAngleTargetAbsolute(90);
    pros::delay(750);
    intake.move(-127);
    pros::delay(750);
    setDriveTargetUnits(620);  
    pros::delay(1000);
    setDriveTargetUnits(-200);
}

void far_awp() {
    
}

void far_elim() {
    intake.move(127);
    setDriveTargetUnits(50);
    pros::delay(500);
    setDriveTargetUnits(225);
    pros::delay(800);
    intake.move(0);
    drivePID.set_kP(0.2);
    drivePID.set_kD(0);
    setDriveTargetUnits(-1050);
    pros::delay(800);
    drivePID.set_kP(0.35);
    turnPID.set_kP(1.7);
    setAngleTargetAbsolute(-40);
    pros::delay(500);
    verticalWings.set_value(true);
    pros::delay(100);
    setDriveTargetUnits(-575);
    pros::delay(600);
    drivePID.set_kP(driveP);
    drivePID.set_kD(driveD);
    setAngleTargetAbsolute(-70);
    pros::delay(600);
    verticalWings.set_value(false);
    pros::delay(100);
    setAngleTargetAbsolute(-35);
    pros::delay(600);
    setDriveTargetUnits(-275);
    pros::delay(700);
    setAngleTargetAbsolute(-90);
    pros::delay(1000);
    setDriveTargetUnits(-700);
    pros::delay(750);
    setDriveTargetUnits(350);
    pros::delay(400);
    setAngleTargetAbsolute(95);
    pros::delay(1000);
    intake.move(-127); 
    pros::delay(700); 
    setDriveTargetUnits(500);
    pros::delay(750);
    intake.move(0);
    setDriveTargetUnits(-475);
    pros::delay(1200);
    setAngleTargetAbsolute(25);
    pros::delay(1000);
    intake.move(127);
    setDriveTargetUnits(1500);
    pros::delay(1000);
    setAngleTargetAbsolute(140);
    pros::delay(700);
    intake.move(-127);
    setDriveTargetUnits(500);
    pros::delay(1000);
    setDriveTargetUnits(-100);
    pros::delay(300);
    intake.move(127);
    setAngleTargetAbsolute(40);
    pros::delay(750);
    setDriveTargetUnits(600);
    pros::delay(1000);
    setAngleTargetAbsolute(160);
    pros::delay(1000);
    horizontalWings.set_value(true);
    intake.move(-127);
    pros::delay(100);
    setDriveTargetUnits(1200);
    pros::delay(1000);
    intake.move(0);
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

