#pragma once
#include "globals.hpp"

struct lv_dimension {
    lv_coord_t x, y, w, h;
};

constexpr lv_coord_t BUTTON_BORDER_WIDTH = 2;
constexpr lv_coord_t BUTTON_CORNER_RADIUS = 5;

lv_obj_t* create_button(lv_obj_t* parent, lv_dimension dimensions, int id, std::string text);
lv_obj_t* create_label(lv_obj_t* parent, lv_coord_t x, lv_coord_t y, std::string text);
lv_obj_t* create_page(lv_obj_t* parent, lv_color_t backgroundColor, bool start = false);
lv_obj_t* create_image(lv_obj_t* parent, const lv_img_dsc_t* src, lv_align_t alignment);
std::array<lv_style_t, 2> create_button_style(lv_color_t text, lv_color_t released, lv_color_t pressed, lv_color_t border);
lv_style_t create_label_style(lv_font_t* font, lv_color_t color);
void set_button_style(lv_obj_t* button, std::array<lv_style_t, 2>& style);
void changePage(lv_obj_t* newPage);