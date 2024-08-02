#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *btn_start_race;
    lv_obj_t *dd_horse_selection;
    lv_obj_t *label_result;
    lv_obj_t *label_total_losses;
    lv_obj_t *label_total_wins;
    lv_obj_t *panel_horse_racing_game;
    lv_obj_t *panel_race_selection;
    lv_obj_t *slider_horse1;
    lv_obj_t *slider_horse2;
    lv_obj_t *slider_horse3;
    lv_obj_t *slider_horse4;
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