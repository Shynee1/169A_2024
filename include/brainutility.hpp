#pragma once
#include "globals.hpp"
#include <fstream>

struct lv_dimension {
    lv_coord_t x, y, w, h;
};

constexpr lv_coord_t BUTTON_BORDER_WIDTH = 2;
constexpr lv_coord_t BUTTON_CORNER_RADIUS = 5;
constexpr char PAGES[] = "Auto Selector\nLogo Display\nDebug Text";
constexpr int PROG_BUTTON_ID = 0;
constexpr int NEAR_BUTTON_ID = 1;
constexpr int FAR_BUTTON_ID  = 2;
constexpr int AWP_BUTTON_ID = 3;
constexpr int ELIM_BUTTON_ID = 4;

typedef FILE* file_t;

// Object creation
lv_obj_t* create_button(lv_obj_t* parent, lv_dimension dimensions, int id, std::string text, std::array<lv_style_t, 2>& buttonStyle);
lv_obj_t* create_label(lv_obj_t* parent, lv_coord_t x, lv_coord_t y, std::string text);
lv_obj_t* create_page(lv_obj_t* parent, lv_color_t backgroundColor, bool start);
lv_obj_t* create_image(lv_obj_t* parent, const lv_img_dsc_t* src, lv_align_t alignment);
lv_obj_t* create_image(lv_obj_t* parent, const lv_img_dsc_t* src, lv_dimension dimensions);
lv_obj_t* create_image(lv_obj_t* parent, std::string filepath, lv_dimension dimensions);
lv_obj_t* create_dropdown(lv_obj_t* parent, lv_dimension dimensions, const char* list);

// Style creation
std::array<lv_style_t, 2> create_button_style(lv_color_t text, lv_color_t released, lv_color_t pressed, lv_color_t border);
lv_style_t create_label_style(lv_font_t* font, lv_color_t color);

// Runtime functions
void set_button_style(lv_obj_t* button, std::array<lv_style_t, 2>& style);
void changePage(int newPageId);
void debug_print(std::string text);
void debug_print(int line, std::string text );
void debug_clear();
int find_nth_pos(std::string str, char c, int n);

// LVGL callbacks
lv_res_t button_callback(lv_obj_t* button);
lv_res_t dropdown_callback(lv_obj_t* dropdown);
lv_res_t file_open_callback(void* file_p, const char* filepath, lv_fs_mode_t mode);
lv_res_t file_close_callback(void* file_p);
lv_res_t file_read_callback(void* file_p, void* buf, uint32_t btr, uint32_t* bw);
lv_res_t file_seek_callback(void* file_p, uint32_t pos);
lv_res_t file_tell_callback(void* file_p, uint32_t* pos);