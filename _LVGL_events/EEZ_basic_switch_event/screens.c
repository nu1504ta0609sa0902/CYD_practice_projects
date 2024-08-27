#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // panelSwitch
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_switch = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // switchLabelShowCount
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.switch_label_show_count = obj;
                    lv_obj_set_pos(obj, -5, -7);
                    lv_obj_set_size(obj, 70, 30);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff6b186), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // switchLabelChangeText
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.switch_label_change_text = obj;
                    lv_obj_set_pos(obj, -6, 27);
                    lv_obj_set_size(obj, 70, 30);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3f686), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // switchButtonChangeText
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.switch_button_change_text = obj;
                    lv_obj_set_pos(obj, -5, 75);
                    lv_obj_set_size(obj, 70, 30);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff9dfe8a), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // switchButtonChangeColor
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.switch_button_change_color = obj;
                    lv_obj_set_pos(obj, -5, 113);
                    lv_obj_set_size(obj, 70, 30);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff87f6f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // switchButtonChangeColorRandom
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.switch_button_change_color_random = obj;
                    lv_obj_set_pos(obj, -5, 153);
                    lv_obj_set_size(obj, 70, 30);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff8ea3f7), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // labelCount
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_count = obj;
                    lv_obj_set_pos(obj, 83, -2);
                    lv_obj_set_size(obj, 188, 20);
                    lv_label_set_text(obj, "0");
                }
                {
                    // labelText
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_text = obj;
                    lv_obj_set_pos(obj, 84, 32);
                    lv_obj_set_size(obj, 188, 20);
                    lv_label_set_text(obj, "Hello");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // btnText
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_text = obj;
                    lv_obj_set_pos(obj, 84, 75);
                    lv_obj_set_size(obj, 188, 30);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // btnTextLabel
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.btn_text_label = obj;
                            lv_obj_set_pos(obj, 36, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Change Text");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // btnChangeColor
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_change_color = obj;
                    lv_obj_set_pos(obj, 83, 113);
                    lv_obj_set_size(obj, 188, 30);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // btnChangeColorLabel
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.btn_change_color_label = obj;
                            lv_obj_set_pos(obj, 27, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Change Colour");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // btnChangeColorRandom
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_change_color_random = obj;
                    lv_obj_set_pos(obj, 84, 153);
                    lv_obj_set_size(obj, 188, 30);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // btnChangeColorRandomLabel
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.btn_change_color_random_label = obj;
                            lv_obj_set_pos(obj, 24, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Random Colour");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            // labelEventFired
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_event_fired = obj;
            lv_obj_set_pos(obj, 10, 212);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Event: ");
        }
    }
}

void tick_screen_main() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
