#include "main.h"
#include "globals.hpp"
#include "brainutility.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	fourBarRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	fourBarLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	dropdown = lv_ddlist_create(lv_scr_act(), NULL);
	lv_ddlist_set_options(dropdown, PAGES);
	lv_obj_set_size(dropdown, 150, 75);
	lv_obj_align(dropdown, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

	autoSelector = create_page(lv_scr_act(), LV_COLOR_BLACK, true);
	//displayPage = create_page(lv_scr_act(), LV_COLOR_MAKE(36,30,32));

	standardButtonStyle = create_button_style(LV_COLOR_WHITE, LV_COLOR_BLACK, LV_COLOR_WHITE, LV_COLOR_WHITE);
	redButtonStyle = create_button_style(LV_COLOR_WHITE, LV_COLOR_RED, LV_COLOR_WHITE, LV_COLOR_BLACK);
	blueButtonStyle = create_button_style(LV_COLOR_WHITE, LV_COLOR_BLUE, LV_COLOR_WHITE, LV_COLOR_BLACK);

	lv_obj_t* progSelectButton = create_button(autoSelector, {0, 0, 100, 50}, 0, "PROG");
	lv_obj_t* redSelectButton = create_button(autoSelector, {0, 75, 100, 50}, 1, "Red");
	lv_obj_t* blueSelectButton = create_button(autoSelector, {0, 150, 100, 50}, 2, "Blue");
	set_button_style(progSelectButton, standardButtonStyle);
	set_button_style(redSelectButton, redButtonStyle);
	set_button_style(blueSelectButton, blueButtonStyle);
	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}