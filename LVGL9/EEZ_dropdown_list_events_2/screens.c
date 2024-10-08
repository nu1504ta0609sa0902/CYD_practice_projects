#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ddCars
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_cars = obj;
            lv_obj_set_pos(obj, 6, 10);
            lv_obj_set_size(obj, 308, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Ford\nKia\nBYD\nTesla");
        }
        {
            // labelShowSelection
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_show_selection = obj;
            lv_obj_set_pos(obj, 6, 211);
            lv_obj_set_size(obj, 308, 29);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taNewOptions
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_new_options = obj;
            lv_obj_set_pos(obj, 6, 49);
            lv_obj_set_size(obj, 254, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
        }
        {
            // btnAddOption
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_add_option = obj;
            lv_obj_set_pos(obj, 269, 49);
            lv_obj_set_size(obj, 45, 36);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Add");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // kbInput
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kb_input = obj;
            lv_obj_set_pos(obj, 6, 95);
            lv_obj_set_size(obj, 308, 116);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_UPPER);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.kb_input, objects.ta_new_options);
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
