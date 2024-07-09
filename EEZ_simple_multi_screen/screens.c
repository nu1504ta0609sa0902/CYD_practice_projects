#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;


static void event_handler_main_page(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    LV_LOG_USER("Clicked");
    loadScreen(SCREEN_ID_MAIN);
  }
}

static void event_handler_page2(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    LV_LOG_USER("Clicked");
    loadScreen(SCREEN_ID_SCREEN2);
  }
}

static void event_handler_page3(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    LV_LOG_USER("Clicked");
    loadScreen(SCREEN_ID_SCREEN3);
  }
}

void create_screen_main() {
  lv_obj_t *obj = lv_obj_create(0);
  objects.main = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 320, 240);
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe3fc0b), LV_PART_MAIN | LV_STATE_DEFAULT);
  {
    lv_obj_t *parent_obj = obj;
    {
      // main_btn_page2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.main_btn_page2 = obj;
      lv_obj_set_pos(obj, 21, 163);
      lv_obj_set_size(obj, 129, 50);
      lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_add_event_cb(obj, event_handler_page2, LV_EVENT_ALL, NULL);
    }
    {
      // main_btn_page3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.main_btn_page3 = obj;
      lv_obj_set_pos(obj, 168, 163);
      lv_obj_set_size(obj, 130, 50);
      lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_add_event_cb(obj, event_handler_page3, LV_EVENT_ALL, NULL);
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 54, 180);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 2");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 202, 180);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 3");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 118, 88);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "MAIN SCREEN");
    }
    {
      lv_obj_t *obj = lv_checkbox_create(parent_obj);
      lv_obj_set_pos(obj, 116, 26);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_checkbox_set_text(obj, "Checkbox");
    }
  }
}

void tick_screen_main() {
}

void create_screen_screen2() {
  lv_obj_t *obj = lv_obj_create(0);
  objects.screen2 = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 320, 240);
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe3fc0b), LV_PART_MAIN | LV_STATE_DEFAULT);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 356, 232);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Hello, world!");
    }
    {
      // sc2_btn_mainpage
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.sc2_btn_mainpage = obj;
      lv_obj_set_pos(obj, 21, 163);
      lv_obj_set_size(obj, 129, 50);
      lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_add_event_cb(obj, event_handler_main_page, LV_EVENT_ALL, NULL);
    }
    {
      // sc2_btn_page3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.sc2_btn_page3 = obj;
      lv_obj_set_pos(obj, 173, 163);
      lv_obj_set_size(obj, 125, 50);
      lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_add_event_cb(obj, event_handler_page3, LV_EVENT_ALL, NULL);
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 42, 180);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Main Screen");
    }
    {
      // btn_page2
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.btn_page2 = obj;
      lv_obj_set_pos(obj, 204, 180);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 3");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 132, 88);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 2");
    }
    {
      lv_obj_t *obj = lv_slider_create(parent_obj);
      lv_obj_set_pos(obj, 85, 29);
      lv_obj_set_size(obj, 150, 10);
      lv_slider_set_value(obj, 25, LV_ANIM_OFF);
    }
  }
}

void tick_screen_screen2() {
}

void create_screen_screen3() {
  lv_obj_t *obj = lv_obj_create(0);
  objects.screen3 = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 320, 240);
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe3fc0b), LV_PART_MAIN | LV_STATE_DEFAULT);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 356, 232);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Hello, world!");
    }
    {
      // sc3_btn_mainpage
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.sc3_btn_mainpage = obj;
      lv_obj_set_pos(obj, 21, 163);
      lv_obj_set_size(obj, 129, 50);
      lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_add_event_cb(obj, event_handler_main_page, LV_EVENT_ALL, NULL);
    }
    {
      // sc3_btn_page2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.sc3_btn_page2 = obj;
      lv_obj_set_pos(obj, 171, 163);
      lv_obj_set_size(obj, 127, 50);
      lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
      lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
      lv_obj_add_event_cb(obj, event_handler_page2, LV_EVENT_ALL, NULL);
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 42, 180);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Main Screen");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 203, 180);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 2");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 118, 88);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 3");
    }
    {
      lv_obj_t *obj = lv_switch_create(parent_obj);
      lv_obj_set_pos(obj, 110, 31);
      lv_obj_set_size(obj, 93, 25);
    }
  }
}

void tick_screen_screen3() {
}


void create_screens() {
  lv_disp_t *dispp = lv_disp_get_default();
  lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);

  create_screen_main();
  create_screen_screen2();
  create_screen_screen3();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
  tick_screen_main,
  tick_screen_screen2,
  tick_screen_screen3,
};

void tick_screen(int screen_index) {
  tick_screen_funcs[screen_index]();
}
