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
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  {
    lv_obj_t *parent_obj = obj;
    {
      // outerBorderCircle
      lv_obj_t *obj = lv_spinner_create(parent_obj);
      lv_spinner_set_anim_params(obj, 10000, 360);
      objects.outer_border_circle = obj;
      lv_obj_set_pos(obj, 43, 3);
      lv_obj_set_size(obj, 235, 235);
      lv_obj_set_style_arc_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_width(obj, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_color(obj, lv_color_hex(0xff008dff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // innerBorderCircle
      lv_obj_t *obj = lv_spinner_create(parent_obj);
      lv_spinner_set_anim_params(obj, 1000, 60);
      objects.inner_border_circle = obj;
      lv_obj_set_pos(obj, 48, 8);
      lv_obj_set_size(obj, 225, 225);
      lv_obj_set_style_arc_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_width(obj, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_color(obj, lv_color_hex(0xff84fffa), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // arcBehindScale
      lv_obj_t *obj = lv_arc_create(parent_obj);
      objects.arc_behind_scale = obj;
      lv_obj_set_pos(obj, 43, 3);
      lv_obj_set_size(obj, 235, 235);
      lv_arc_set_value(obj, 222);

      //Update ARC angle start and end positions
      lv_arc_set_bg_angles(obj, 180, 90);  //Main arc to start from 180 and go to 270 (+180->3'Oclock + 90)
      lv_arc_set_range(obj, 0, 240);       //Value range for the arc

      lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_width(obj, 30, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_opa(obj, 30, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_color(obj, lv_color_hex(0xffe7f963), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    }
    {
      // scaleOuter0to240
      lv_obj_t *obj = lv_scale_create(parent_obj);
      objects.scale_outer0to240 = obj;
      lv_obj_set_pos(obj, 56, 16);
      lv_obj_set_size(obj, 210, 210);
      lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);

      //Update to position the scale
      lv_scale_set_rotation(obj, 180);     //Start scale From 3 O'clock + 180 degrees
      lv_scale_set_angle_range(obj, 270);  //Scale angle range from set rotation start angle
      lv_scale_set_range(obj, 0, 240);     //Scale value range, what is displayed

      lv_scale_set_total_tick_count(obj, 61);
      lv_scale_set_major_tick_every(obj, 5);
      lv_scale_set_label_show(obj, true);
      lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_line_color(obj, lv_color_hex(0xff0cf8f8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_color(obj, lv_color_hex(0xff0500ff), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // scaleInner0to150
      lv_obj_t *obj = lv_scale_create(parent_obj);
      objects.scale_inner0to150 = obj;
      lv_obj_set_pos(obj, 75, 36);
      lv_obj_set_size(obj, 170, 170);
      lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);

      //Update to position the scale
      lv_scale_set_rotation(obj, 180);     //Start scale From 3 O'clock + 180 degrees
      lv_scale_set_angle_range(obj, 270);  //Scale angle range from set rotation start angle to where it it should end
      lv_scale_set_range(obj, 0, 150);     //Scale value range, what is displayed

      lv_scale_set_total_tick_count(obj, 31);
      lv_scale_set_major_tick_every(obj, 3);
      lv_scale_set_label_show(obj, true);
      lv_obj_set_style_length(obj, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
      lv_obj_set_style_line_color(obj, lv_color_hex(0xff28ea8c), LV_PART_ITEMS | LV_STATE_DEFAULT);
      lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_line_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff06ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_line_width(obj, 33, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // arcSpeedometer
      lv_obj_t *obj = lv_arc_create(parent_obj);
      objects.arc_speedometer = obj;
      lv_obj_set_pos(obj, 110, 70);
      lv_obj_set_size(obj, 100, 100);

      //Update start and end position of the ARC
      lv_arc_set_bg_angles(obj, 180, 90);  //Main arc to start from 180 and go to 270 (+180->3'Oclock + 90)
      lv_arc_set_range(obj, 0, 240);       //Value range for the arc

      // lv_arc_set_value(obj, 25);
      // lv_arc_set_bg_start_angle(obj, 135);
      // lv_arc_set_bg_end_angle(obj, 45);
      lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_image_src(obj, &img_arc_full_small2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // labelSpeedKmh_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.label_speed_kmh_1 = obj;
      lv_obj_set_pos(obj, 122, 104);
      lv_obj_set_size(obj, 71, 33);
      lv_label_set_text(obj, "000");
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_opa(obj, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff85fde9), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // labelSpeedKmh
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.label_speed_kmh = obj;
      lv_obj_set_pos(obj, 126, 105);
      lv_obj_set_size(obj, 71, 33);
      lv_label_set_text(obj, "000");
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff4ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 120, 180);  //Update position
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "mp/h");
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff4b5e61), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 110, 200);  //Update position
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "km/h");
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff6ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
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
