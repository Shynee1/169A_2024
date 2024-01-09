#include "opcontrol.hpp"

void opcontrol() {
    // Anything inside this loop is run every frame
	while (true) { 
        // Read controller as voltage values (-127 to 127)
		double left = -controller.get_analog(ANALOG_LEFT_Y);
		double right = controller.get_analog(ANALOG_RIGHT_Y);

		leftMotorFront.move(left);
        leftMotorMiddle.move(left);
        leftMotorBack.move(left);  
        rightMotorFront.move(right);  
        rightMotorFront.move(right);
        rightMotorBack.move(right);
		
		pros::delay(TASK_DELAY);
	}
}