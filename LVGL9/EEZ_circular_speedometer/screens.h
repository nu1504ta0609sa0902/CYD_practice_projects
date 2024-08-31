#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *arc_behind_scale;
    lv_obj_t *arc_speedometer;
    lv_obj_t *inner_border_circle;
    lv_obj_t *label_speed_kmh;
    lv_obj_t *label_speed_kmh_1;
    lv_obj_t *outer_border_circle;
    lv_obj_t *scale_inner0to150;
    lv_obj_t *scale_outer0to240;
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