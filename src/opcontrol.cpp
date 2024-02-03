#include "opcontrol.hpp"

void opcontrol() {
	while (true) { 
        // Prevent tasks from altering drive
        autoDriveState = -1;
        // Read controller as voltage values (-127 to 127)
		double left = controller.get_analog(ANALOG_LEFT_Y);
		double right = controller.get_analog(ANALOG_RIGHT_Y);

        driveLeftBack.move(left);
        driveLeftMiddle.move(left);
        driveLeftBack.move(left);  
        driveRightFront.move(right);  
        driveRightMiddle.move(right);
        driveRightBack.move(right); 

        handle_four_bar();
    
		pros::delay(TASK_DELAY);
	}
}

void handle_four_bar(){
    if (controller.get_digital(FOUR_BAR_MANUAL_UP)){
        fourBarRight.move(127);
        fourBarLeft.move(127);
    }
    else if (controller.get_digital(FOUR_BAR_MANUAL_DOWN)){
        fourBarRight.move(-127);
        fourBarLeft.move(-127);
    }
    else {
        fourBarRight.brake();
        fourBarLeft.brake();
    }
}