#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *dd_team_names;
    lv_obj_t *img_logo;
    lv_obj_t *img_symbol_1;
    lv_obj_t *img_symbol_3;
    lv_obj_t *img_symbol_4;
    lv_obj_t *img_symbol_5;
    lv_obj_t *label_established;
    lv_obj_t *label_runners_up;
    lv_obj_t *label_stadium_name;
    lv_obj_t *label_team_1;
    lv_obj_t *label_team_2;
    lv_obj_t *label_team_3;
    lv_obj_t *label_team_4;
    lv_obj_t *label_team_5;
    lv_obj_t *label_titles_won;
    lv_obj_t *label_years_in_pl;
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