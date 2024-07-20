#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

int currentScreen = 1;         //Main Screen=1 keep track of which screen we are in.
int totalNumberOfScreens = 5;  //MUST change to number of screens

void my_event(lv_event_t *e) {
  lv_obj_t *screen = lv_event_get_current_target(e);
  lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());

  //Log which way we are swiping
  printf("Dir: %d\n", dir);
  switch (dir) {
    case LV_DIR_LEFT:
      //Go towards the last screen
      if (currentScreen < totalNumberOfScreens) {
        loadScreen(currentScreen + 1);
        currentScreen = currentScreen + 1;
        lv_label_set_text(objects.label_info_last, "");
      } else {
        lv_label_set_text(objects.label_info_last, "SWIPE RIGTH\nSWIPE RIGHT");
      }
      break;
    case LV_DIR_RIGHT:
      //Go towards teh Main/First screen
      if (currentScreen > 1) {
        loadScreen(currentScreen - 1);
        currentScreen = currentScreen - 1;
        lv_label_set_text(objects.label_info_main, "");
      } else {
        lv_label_set_text(objects.label_info_main, "SWIPE LEFT\nSWIPE LEFT");
      }
      break;
  }
}



void create_screen_main() {
  lv_obj_t *obj = lv_obj_create(0);
  objects.main = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 320, 240);
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe3fc0b), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(obj, my_event, LV_EVENT_GESTURE, NULL);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 55, 21);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "MAIN SCREEN");
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_checkbox_create(parent_obj);
      lv_obj_set_pos(obj, 108, 110);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_checkbox_set_text(obj, "Checkbox");
    }
    {
      // labelInfoMain
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.label_info_main = obj;
      lv_obj_set_pos(obj, 55, 175);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "");
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
  lv_obj_add_event_cb(obj, my_event, LV_EVENT_GESTURE, NULL);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 54, 26);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 2");
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_slider_create(parent_obj);
      lv_obj_set_pos(obj, 54, 120);
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
  lv_obj_add_event_cb(obj, my_event, LV_EVENT_GESTURE, NULL);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 64, 24);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 3");
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_switch_create(parent_obj);
      lv_obj_set_pos(obj, 64, 136);
      lv_obj_set_size(obj, 93, 25);
    }
  }
}

void tick_screen_screen3() {
}

void create_screen_screen4() {
  lv_obj_t *obj = lv_obj_create(0);
  objects.screen4 = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 320, 240);
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe3fc0b), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(obj, my_event, LV_EVENT_GESTURE, NULL);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 64, 24);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Screen 4");
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_roller_create(parent_obj);
      lv_obj_set_pos(obj, 64, 90);
      lv_obj_set_size(obj, 80, 100);
      lv_roller_set_options(obj, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
    }
  }
}

void tick_screen_screen4() {
}

void create_screen_last_screen() {
  lv_obj_t *obj = lv_obj_create(0);
  objects.last_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 320, 240);
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe3fc0b), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(obj, my_event, LV_EVENT_GESTURE, NULL);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 64, 24);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "Last Screen");
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_dropdown_create(parent_obj);
      lv_obj_set_pos(obj, 64, 88);
      lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
      lv_dropdown_set_options(obj, "Option 1\nOption 2\nOption 3");
    }
    {
      // labelInfoLast
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.label_info_last = obj;
      lv_obj_set_pos(obj, 59, 169);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_label_set_text(obj, "");
    }
  }
}

void tick_screen_last_screen() {
}


void create_screens() {
  lv_disp_t *dispp = lv_disp_get_default();
  lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);

  create_screen_main();
  create_screen_screen2();
  create_screen_screen3();
  create_screen_screen4();
  create_screen_last_screen();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
  tick_screen_main,
  tick_screen_screen2,
  tick_screen_screen3,
  tick_screen_screen4,
  tick_screen_last_screen,
};

void tick_screen(int screen_index) {
  tick_screen_funcs[screen_index]();
}
