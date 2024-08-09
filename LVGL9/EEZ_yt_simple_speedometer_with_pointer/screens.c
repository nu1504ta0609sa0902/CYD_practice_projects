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
      lv_obj_t *obj = lv_obj_create(parent_obj);
      lv_obj_set_pos(obj, 0, 0);
      lv_obj_set_size(obj, 320, 240);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // scaleNumber
          lv_obj_t *obj = lv_scale_create(parent_obj);
          objects.scale_number = obj;
          lv_obj_set_pos(obj, 25, 61);
          lv_obj_set_size(obj, 240, 240);
          lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_OUTER);

          //Set sccale positions and angles
          lv_scale_set_rotation(obj, 180);         //Start scale From 3 O'clock + 180 degrees
          lv_scale_set_angle_range(obj, 180);      //Scale angle range shown in the GUI
          lv_scale_set_range(obj, 0, 180);         //Scale value range, what is displayed
          lv_scale_set_total_tick_count(obj, 46);  //total number of ticks minor and major
          lv_scale_set_major_tick_every(obj, 3);   //Show major one every X

          lv_scale_set_label_show(obj, true);
          lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
          lv_obj_set_style_line_color(obj, lv_color_hex(0xff09e823), LV_PART_ITEMS | LV_STATE_DEFAULT);
          lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
          lv_obj_set_style_line_color(obj, lv_color_hex(0xffea2914), LV_PART_INDICATOR | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff21f3ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
          lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0608f5), LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_arc_color(obj, lv_color_hex(0xff0215ff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
          // imgNeedle
          lv_obj_t *obj = lv_img_create(parent_obj);
          objects.img_needle = obj;
          lv_obj_set_pos(obj, 60, 96);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_img_set_src(obj, &img_img_needle);
          lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
          lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
          // arcRainbow
          lv_obj_t *obj = lv_arc_create(parent_obj);
          objects.arc_rainbow = obj;
          lv_obj_set_pos(obj, 30, 66);
          lv_obj_set_size(obj, 230, 230);

          //Update to position the Arc
          lv_arc_set_range(obj, 0, 180);      //Arc value will go from 0 to 180
          lv_arc_set_bg_angles(obj, 180, 0);  //Arc will start at 180 deg and go to 0 (or use start and end angles)

          lv_obj_set_style_arc_width(obj, 22, LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_arc_width(obj, 22, LV_PART_INDICATOR | LV_STATE_DEFAULT);
          lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
          lv_obj_set_style_arc_image_src(obj, &img_image_arc_bg, LV_PART_INDICATOR | LV_STATE_DEFAULT);
          lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
      }
    }
    {
      // lableArcValue
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.lable_arc_value = obj;
      lv_obj_set_pos(obj, -3, 0);
      lv_obj_set_size(obj, 76, 31);
      lv_label_set_text(obj, "000");
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff56c1ed), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // lableMPH
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.lable_mph = obj;
      lv_obj_set_pos(obj, 73, 8);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "mp/h");
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffdb6464), LV_PART_MAIN | LV_STATE_DEFAULT);
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
