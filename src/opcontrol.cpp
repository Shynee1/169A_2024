#include "opcontrol.hpp"

void opcontrol() {
	while (true) { 
        // Prevent tasks from altering drive
        driveState = CONTROLLER;
        // Read controller as voltage values (-127 to 127)
		double left = controller.get_analog(ANALOG_LEFT_Y);
		double right = controller.get_analog(ANALOG_RIGHT_Y);

        driveLeftFront.move(left);
        driveLeftMiddle.move(left);
        driveLeftBack.move(left);  
        driveRightFront.move(right);  
        driveRightMiddle.move(right);
        driveRightBack.move(right); 

        handle_two_bar();
        handle_pto();

		pros::delay(TASK_DELAY);
    }
}

void handle_pto() {
    if (controller.get_digital_new_press(PTO_TOGGLE))
        toggle_pto();
}

void handle_two_bar(){
    //ptoState = TWOBAR;

    if (controller.get_digital(FOUR_BAR_MANUAL_UP)){
        //setTwobarTargetRelative(-40);
        ptoMotorRight.move(127);
        ptoMotorLeft.move(127);
    }
    else if (controller.get_digital(FOUR_BAR_MANUAL_DOWN)){
        //setTwobarTargetRelative(40);
        ptoMotorRight.move(-127);
        ptoMotorLeft.move(-127);
    }
    else {
        ptoMotorRight.brake();
        ptoMotorLeft.brake();
    }  
}