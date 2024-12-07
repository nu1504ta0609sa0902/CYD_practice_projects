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
            // panelSpeedometer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_speedometer = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // scale0To270
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    objects.scale0_to270 = obj;
                    lv_obj_set_pos(obj, 20, -2);
                    lv_obj_set_size(obj, 250, 250);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);
                    lv_scale_set_range(obj, 0, 270);
                    lv_scale_set_total_tick_count(obj, 61);
                    lv_scale_set_major_tick_every(obj, 5);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffff0005), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_length(obj, 12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xff0026ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff00ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // imgHoveringNeedle
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            objects.img_hovering_needle = obj;
                            lv_obj_set_pos(obj, 31, 30);
                            lv_obj_set_size(obj, 190, 190);
                            lv_img_set_src(obj, &img_pointer_315);
                            lv_img_set_angle(obj, 1110);
                            lv_obj_set_style_image_opa(obj, 125, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // arcShadowBG
                            lv_obj_t *obj = lv_arc_create(parent_obj);
                            objects.arc_shadow_bg = obj;
                            lv_obj_set_pos(obj, 1, 0);
                            lv_obj_set_size(obj, 250, 250);
                            lv_arc_set_range(obj, 0, 270);
                            lv_arc_set_value(obj, 111);
                            lv_arc_set_bg_start_angle(obj, 135);
                            lv_arc_set_bg_end_angle(obj, 45);
                            lv_obj_set_style_arc_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_opa(obj, 88, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffd9f100), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // scaleInside
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    objects.scale_inside = obj;
                    lv_obj_set_pos(obj, 65, 43);
                    lv_obj_set_size(obj, 160, 160);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_OUTER);
                    lv_scale_set_range(obj, 0, 270);
                    lv_scale_set_total_tick_count(obj, 25);
                    lv_scale_set_major_tick_every(obj, 2);
                    lv_scale_set_label_show(obj, false);
                    lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_length(obj, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xff0a03ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff00e0ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // spinnerInside
                    lv_obj_t *obj = lv_spinner_create(parent_obj);
                    lv_spinner_set_anim_params(obj, 10000, 270);
                    objects.spinner_inside = obj;
                    lv_obj_set_pos(obj, 73, 51);
                    lv_obj_set_size(obj, 145, 145);
                    lv_obj_set_style_arc_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff0a27f9), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff80f188), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                }
                {
                    // labelMPH
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_mph = obj;
                    lv_obj_set_pos(obj, 121, 75);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "MPH");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffec1010), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // labelMilageBG
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_milage_bg = obj;
                    lv_obj_set_pos(obj, 69, 105);
                    lv_obj_set_size(obj, 144, 52);
                    lv_label_set_text(obj, "000");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff7c83ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 55, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // labelMilageFG
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_milage_fg = obj;
                    lv_obj_set_pos(obj, 74, 105);
                    lv_obj_set_size(obj, 144, 52);
                    lv_label_set_text(obj, "000");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff00fdff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
