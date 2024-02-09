#include "main.h"
#include "globals.hpp"
#include "brainutility.hpp"
#include "tasks.hpp"

//LV_IMG_DECLARE(logo);
//LV_IMG_DECLARE(mike);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	ptoMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	ptoMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	tare_motors();

	initializeFileDrive();

	standardButtonStyle = create_button_style(LV_COLOR_WHITE, LV_COLOR_BLACK, LV_COLOR_WHITE, LV_COLOR_WHITE);
	redButtonStyle = create_button_style(LV_COLOR_WHITE, LV_COLOR_RED, LV_COLOR_WHITE, LV_COLOR_BLACK);
	blueButtonStyle = create_button_style(LV_COLOR_WHITE, LV_COLOR_BLUE, LV_COLOR_WHITE, LV_COLOR_BLACK);

	lv_color_t color = LV_COLOR_MAKE(36,30,32);

	pages[0] = create_page(lv_scr_act(), LV_COLOR_BLACK, false);
	pages[1] = create_page(lv_scr_act(), color, false);
	pages[2] = create_page(lv_scr_act(), LV_COLOR_BLACK, true);

	dropdown = create_dropdown(lv_scr_act(), {10, 10, 175, 50}, PAGES);
	lv_ddlist_set_action(dropdown, dropdown_callback);

	initializeAutoSelector();
	initializeDisplayLogo();
	initializeDebugScreen();

	debug_print(0, "Hello World");

	pros::Task moveTask(move);
	pros::Task turnTask(turn);
}

void initializeFileDrive() {
	memset(&drive, 0, sizeof(lv_fs_drv_t));
	drive.file_size = sizeof(FILE*);
	drive.letter = 'D';
	drive.open = file_open_callback;
	drive.close = file_close_callback;
	drive.read = file_read_callback;
	drive.seek = file_seek_callback;
	drive.tell = file_tell_callback;
	lv_fs_add_drv(&drive);
}

void initializeAutoSelector() {
	lv_obj_t* placeholder = create_button(pages[0], {10, 10, 1, 1}, 100, "H", standardButtonStyle);
	lv_obj_t* progButton = create_button(pages[0], {10, 72, 175, 46}, PROG_BUTTON_ID, "PROG", standardButtonStyle);
	lv_obj_t* redTeamButton = create_button(pages[0], {10, 123, 175, 46}, NEAR_BUTTON_ID, "Near Side", redButtonStyle);
	lv_obj_t* blueTeamButton = create_button(pages[0], {10, 174, 175, 46}, FAR_BUTTON_ID, "Far Side", blueButtonStyle);

	awpButton = create_button(pages[0], {195, 72, 130, 148}, AWP_BUTTON_ID, "AWP", standardButtonStyle);
	elimButton = create_button(pages[0], {330, 72, 130, 148}, ELIM_BUTTON_ID, "Elims", standardButtonStyle);
	lv_obj_set_hidden(awpButton, true);
	lv_obj_set_hidden(elimButton, true);

	lv_btn_set_action(progButton, LV_BTN_ACTION_CLICK, button_callback);
	lv_btn_set_action(redTeamButton, LV_BTN_ACTION_CLICK, button_callback);
	lv_btn_set_action(blueTeamButton, LV_BTN_ACTION_CLICK, button_callback);
	lv_btn_set_action(awpButton, LV_BTN_ACTION_CLICK, button_callback);
	lv_btn_set_action(elimButton, LV_BTN_ACTION_CLICK, button_callback);

	//mikeFace = create_image(pages[0], &mike, {205, 10, 265, 60});
}

void initializeDisplayLogo() {
	//logoImage = create_image(pages[1], &logo, LV_ALIGN_CENTER);
}

void initializeDebugScreen() {
	lv_obj_t* placeholder = create_label(pages[2], 0, 0, "");
	debugLabel = create_label(pages[2], 10, 60, "");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	
}

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