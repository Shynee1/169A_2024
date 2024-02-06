#include "brainutility.hpp"

lv_obj_t* create_button(lv_obj_t* parent, lv_dimension dimensions, int id, std::string text, std::array<lv_style_t, 2>& buttonStyle) {
    lv_obj_t* button = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button, dimensions.x, dimensions.y);
    lv_obj_set_size(button, dimensions.w, dimensions.h);
    lv_obj_set_free_num(button, id);

    lv_obj_t* label = create_label(button, 0, 0, text);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    set_button_style(button, buttonStyle);

    return button;
}

lv_obj_t* create_label(lv_obj_t* parent, lv_coord_t x, lv_coord_t y, std::string text) {
    lv_obj_t* label = lv_label_create(parent, NULL);
    lv_label_set_text(label, text.c_str());
    lv_obj_set_pos(label, x, y);
    return label;
}

lv_obj_t* create_page(lv_obj_t* parent, lv_color_t backgroundColor, bool start) {
    static lv_style_t style;
    lv_style_copy(&style, &lv_style_plain);
    style.body.main_color = backgroundColor;
	style.body.grad_color = backgroundColor;
    style.text.color = LV_COLOR_WHITE; 

	lv_obj_t* page = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(page, LV_HOR_RES, LV_VER_RES);
    lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style(page, &style);
    lv_obj_set_hidden(page, !start);
    if (start) currentPage = page;
    
    return page;
}

lv_obj_t* create_image(lv_obj_t* parent, const lv_img_dsc_t* src, lv_align_t alignment) {
    lv_obj_t* image = lv_img_create(parent, NULL);
	lv_img_set_src(image, src);
	lv_obj_align(image, NULL, alignment, 0, 0);
    return image;
}

lv_obj_t* create_dropdown(lv_obj_t* parent, lv_dimension dimensions, const char* list) {
    lv_obj_t* dropdown = lv_ddlist_create(lv_scr_act(), NULL);
	lv_ddlist_set_options(dropdown, list);
    lv_obj_set_pos(dropdown, dimensions.x, dimensions.y);
    lv_obj_set_size(dropdown, dimensions.w, dimensions.h);
    return dropdown;
}

std::array<lv_style_t, 2> create_button_style(lv_color_t text, lv_color_t released, lv_color_t pressed, lv_color_t border) {
    std::array<lv_style_t, 2> buttonStyles;

    for (int i = 0; i < 2; i++) {
        lv_style_copy(&buttonStyles[i], &lv_style_plain);
        buttonStyles[i].text.color = text;
        buttonStyles[i].body.border.color = border;
        buttonStyles[i].body.border.width = BUTTON_BORDER_WIDTH;
        buttonStyles[i].body.radius = BUTTON_CORNER_RADIUS;
    }

    buttonStyles[0].body.main_color = released;
    buttonStyles[0].body.grad_color = released;

    buttonStyles[1].body.main_color = pressed;
    buttonStyles[1].body.grad_color = pressed;

    return buttonStyles;
}

lv_style_t create_label_style(lv_font_t* font, lv_color_t color) {
    lv_style_t textStyle;
    lv_style_copy(&textStyle, &lv_style_plain);
    textStyle.text.font = font;
    textStyle.text.color = color;
    return textStyle;
}

void set_button_style(lv_obj_t* button, std::array<lv_style_t, 2>& style) {
    lv_btn_set_style(button, LV_BTN_STYLE_REL, &style[0]);
    lv_btn_set_style(button, LV_BTN_STYLE_PR, &style[1]);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_REL, &style[0]);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_PR, &style[1]);
}

void changePage(int newPageId) {
    lv_obj_set_hidden(currentPage, true);
    currentPage = pages[newPageId];
    lv_obj_set_hidden(currentPage, false);
}

lv_res_t button_callback(lv_obj_t* button) {
    uint8_t id = lv_obj_get_free_num(button);

    if (id == PROG_BUTTON_ID){
        lv_obj_set_hidden(awpButton, true);
        lv_obj_set_hidden(elimButton, true);
    } else if (id == RED_BUTTON_ID || id == BLUE_BUTTON_ID){
        lv_obj_set_hidden(awpButton, false);
        lv_obj_set_hidden(elimButton, false);
    }
    
    if (id == AWP_BUTTON_ID || id == ELIM_BUTTON_ID) 
        autoSelectorIndex *= id;
    else 
        autoSelectorIndex = id;

    return LV_RES_OK;
}

lv_res_t dropdown_callback(lv_obj_t* dropdown) {
    int selectedId = lv_ddlist_get_selected(dropdown);
    changePage(selectedId);

    return LV_RES_OK;
}

void debug_print(std::string text) {
    std::string currText = lv_label_get_text(debugLabel);
    currText += "\n" + text;
    lv_label_set_text(debugLabel, currText.c_str());
}

void debug_clear() {
    lv_label_set_text(debugLabel, "");
}