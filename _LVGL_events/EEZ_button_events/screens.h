#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *btn_all_event;
    lv_obj_t *btn_change_colour;
    lv_obj_t *btn_clicked;
    lv_obj_t *btn_long_clicked;
    lv_obj_t *label_all_event;
    lv_obj_t *label_change_colour;
    lv_obj_t *label_click_result;
    lv_obj_t *label_long_click;
    lv_obj_t *lable_btn_clicked;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/