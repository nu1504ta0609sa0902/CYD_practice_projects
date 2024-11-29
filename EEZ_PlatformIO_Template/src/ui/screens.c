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

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var_slider_variable(value);
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            lv_spinner_set_anim_params(obj, 1000, 60);
            lv_obj_set_pos(obj, 11, 12);
            lv_obj_set_size(obj, 46, 40);
        }
        {
            // GreenBtn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.green_btn = obj;
            lv_obj_set_pos(obj, 102, 7);
            lv_obj_set_size(obj, 118, 50);
            lv_obj_add_event_cb(obj, action_set_led_green, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00e600), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Green");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // RedBtn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.red_btn = obj;
            lv_obj_set_pos(obj, 39, 70);
            lv_obj_set_size(obj, 118, 50);
            lv_obj_add_event_cb(obj, action_set_led_red, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Red");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // MillisLabel
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.millis_label = obj;
            lv_obj_set_pos(obj, 11, 191);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "millis(): 0000");
        }
        {
            // FlipScreenBtn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.flip_screen_btn = obj;
            lv_obj_set_pos(obj, 184, 203);
            lv_obj_set_size(obj, 127, 25);
            lv_obj_add_event_cb(obj, action_rotate_screen, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Rotate Screen");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // LightSensorLabel
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.light_sensor_label = obj;
            lv_obj_set_pos(obj, 11, 212);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Light Sensor: 0000");
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 11, 140);
            lv_obj_set_size(obj, 300, 10);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, 0);
        }
        {
            // SliderValueLabel
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.slider_value_label = obj;
            lv_obj_set_pos(obj, 111, 163);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Slider Value: 0");
        }
        {
            // BlueBtn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.blue_btn = obj;
            lv_obj_set_pos(obj, 165, 70);
            lv_obj_set_size(obj, 118, 50);
            lv_obj_add_event_cb(obj, action_set_led_blue, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Blue");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            lv_spinner_set_anim_params(obj, 1000, 60);
            lv_obj_set_pos(obj, 265, 12);
            lv_obj_set_size(obj, 46, 40);
        }
    }
}

void tick_screen_main() {
    {
        int32_t new_val = get_var_slider_variable();
        int32_t cur_val = lv_slider_get_value(objects.obj0);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj0;
            lv_slider_set_value(objects.obj0, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
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
