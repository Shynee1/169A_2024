#include "autonomous.hpp"

void autonomous() {
    driveState = DRIVE;
    tare_motors();
    switch (autoSelectorIndex){
        case PROG_BUTTON_ID:
            prog();
            break;
        case (RED_BUTTON_ID * AWP_BUTTON_ID):
            far_awp();
            break;
        case (RED_BUTTON_ID * ELIM_BUTTON_ID):
            far_elim();
            break;
        case (BLUE_BUTTON_ID * AWP_BUTTON_ID):
            close_awp();
            break;
        case (BLUE_BUTTON_ID * ELIM_BUTTON_ID):
            far_awp();
            break;
    }
}

void prog() {

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

