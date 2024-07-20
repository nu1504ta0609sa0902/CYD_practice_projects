#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *screen2;
    lv_obj_t *screen3;
    lv_obj_t *screen4;
    lv_obj_t *last_screen;
    lv_obj_t *label_info_last;
    lv_obj_t *label_info_main;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SCREEN2 = 2,
    SCREEN_ID_SCREEN3 = 3,
    SCREEN_ID_SCREEN4 = 4,
    SCREEN_ID_LAST_SCREEN = 5,
};

void create_screen_main();
void tick_screen_main();

void create_screen_screen2();
void tick_screen_screen2();

void create_screen_screen3();
void tick_screen_screen3();

void create_screen_screen4();
void tick_screen_screen4();

void create_screen_last_screen();
void tick_screen_last_screen();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/