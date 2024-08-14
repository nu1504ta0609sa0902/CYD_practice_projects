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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc3ce12), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnClicked
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_clicked = obj;
            lv_obj_set_pos(obj, 17, 50);
            lv_obj_set_size(obj, 135, 80);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lableBtnClicked
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lable_btn_clicked = obj;
                    lv_obj_set_pos(obj, 24, 24);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Click Me");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0012), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btnLongClicked
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_long_clicked = obj;
            lv_obj_set_pos(obj, 164, 50);
            lv_obj_set_size(obj, 135, 80);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // labelLongClick
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_long_click = obj;
                    lv_obj_set_pos(obj, 3, 24);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Long Click Me");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0012), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // labelClickResult
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_click_result = obj;
            lv_obj_set_pos(obj, 17, 17);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Event: ");
        }
        {
            // btnAllEvent
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_all_event = obj;
            lv_obj_set_pos(obj, 16, 142);
            lv_obj_set_size(obj, 135, 80);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // labelAllEvent
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_all_event = obj;
                    lv_obj_set_pos(obj, -5, 24);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Handle All Event");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0012), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btnChangeColour
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_change_colour = obj;
            lv_obj_set_pos(obj, 164, 142);
            lv_obj_set_size(obj, 135, 80);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // labelChangeColour
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_change_colour = obj;
                    lv_obj_set_pos(obj, 0, 24);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Change Colour");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0012), LV_PART_MAIN | LV_STATE_DEFAULT);
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
