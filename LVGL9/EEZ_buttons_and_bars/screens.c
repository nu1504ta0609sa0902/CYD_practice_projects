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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff68f3f3), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // barTemperature
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.bar_temperature = obj;
            lv_obj_set_pos(obj, 202, 14);
            lv_obj_set_size(obj, 45, 213);
            lv_bar_set_range(obj, 0, 210);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_temperature_bar, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // scaleTemperature
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.scale_temperature = obj;
            lv_obj_set_pos(obj, 262, 14);
            lv_obj_set_size(obj, 40, 213);
            lv_scale_set_mode(obj, LV_SCALE_MODE_VERTICAL_RIGHT);
            lv_scale_set_range(obj, 0, 210);
            lv_scale_set_total_tick_count(obj, 31);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, true);
            lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // lableValueC
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lable_value_c = obj;
            lv_obj_set_pos(obj, 23, 14);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Celcius: ");
        }
        {
            // lableValueFarenheit
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lable_value_farenheit = obj;
            lv_obj_set_pos(obj, 23, 43);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Fahrenheit: ");
        }
        {
            // cbxPause
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.cbx_pause = obj;
            lv_obj_set_pos(obj, 23, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Pause ");
        }
        {
            // btnResetValue
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_reset_value = obj;
            lv_obj_set_pos(obj, 23, 112);
            lv_obj_set_size(obj, 153, 50);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // bthReset
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.bth_reset = obj;
                    lv_obj_set_pos(obj, 42, 9);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Reset");
                }
            }
        }
        {
            // btnRandomValue
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_random_value = obj;
            lv_obj_set_pos(obj, 24, 177);
            lv_obj_set_size(obj, 152, 50);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btnRandom
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.btn_random = obj;
                    lv_obj_set_pos(obj, 30, 9);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Random");
                }
            }
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
