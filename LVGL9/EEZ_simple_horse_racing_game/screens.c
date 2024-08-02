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
    {
        lv_obj_t *parent_obj = obj;
        {
            // PanelHorseRacingGame
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_horse_racing_game = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // panelRaceSelection
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel_race_selection = obj;
                    lv_obj_set_pos(obj, -15, -15);
                    lv_obj_set_size(obj, 320, 52);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ddHorseSelection
                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                            objects.dd_horse_selection = obj;
                            lv_obj_set_pos(obj, -10, -10);
                            lv_obj_set_size(obj, 124, LV_SIZE_CONTENT);
                            lv_dropdown_set_options(obj, "Select Horse\n1\n2\n3\n4");
                        }
                        {
                            // btnStartRace
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_start_race = obj;
                            lv_obj_set_pos(obj, 120, -10);
                            lv_obj_set_size(obj, 84, 37);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -8, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Start Race");
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 1, 89);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "H1");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 0, 129);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "H2");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 1, 169);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "H3");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 1, 211);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "H4");
        }
        {
            // labelResult
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_result = obj;
            lv_obj_set_pos(obj, 11, 59);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Info:");
        }
        {
            // sliderHorse1
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_horse1 = obj;
            lv_obj_set_pos(obj, 17, 80);
            lv_obj_set_size(obj, 298, 35);
            lv_slider_set_range(obj, 0, 210);
            lv_obj_set_style_bg_opa(obj, 51, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_tiny_horse_red, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // sliderHorse2
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_horse2 = obj;
            lv_obj_set_pos(obj, 17, 121);
            lv_obj_set_size(obj, 297, 35);
            lv_slider_set_range(obj, 0, 210);
            lv_obj_set_style_bg_image_src(obj, &img_tiny_horse_yellow, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 51, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // sliderHorse3
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_horse3 = obj;
            lv_obj_set_pos(obj, 17, 161);
            lv_obj_set_size(obj, 296, 35);
            lv_slider_set_range(obj, 0, 210);
            lv_obj_set_style_bg_image_src(obj, &img_tiny_horse_green, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 51, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // sliderHorse4
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_horse4 = obj;
            lv_obj_set_pos(obj, 17, 202);
            lv_obj_set_size(obj, 296, 35);
            lv_slider_set_range(obj, 0, 210);
            lv_obj_set_style_bg_image_src(obj, &img_tiny_horse_blue, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 51, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // labelTotalWins
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_total_wins = obj;
            lv_obj_set_pos(obj, 227, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Won: 0");
        }
        {
            // labelTotalLosses
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_total_losses = obj;
            lv_obj_set_pos(obj, 231, 25);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Lost: 0");
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
