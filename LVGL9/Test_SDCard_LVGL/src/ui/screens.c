#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ddTeamNames
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_team_names = obj;
            lv_obj_set_pos(obj, 13, 16);
            lv_obj_set_size(obj, 293, 38);
            lv_dropdown_set_options(obj, "");
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelTeam_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_team_1 = obj;
            lv_obj_set_pos(obj, 0, 93);
            lv_obj_set_size(obj, 104, 25);
            lv_label_set_text(obj, "Est.: ");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelTeam_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_team_2 = obj;
            lv_obj_set_pos(obj, 0, 62);
            lv_obj_set_size(obj, 104, 25);
            lv_label_set_text(obj, "Stadium: ");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelTeam_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_team_3 = obj;
            lv_obj_set_pos(obj, 0, 123);
            lv_obj_set_size(obj, 104, 25);
            lv_label_set_text(obj, "Won: ");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelTeam_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_team_4 = obj;
            lv_obj_set_pos(obj, 0, 153);
            lv_obj_set_size(obj, 104, 25);
            lv_label_set_text(obj, "Runner Up: ");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelTeam_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_team_5 = obj;
            lv_obj_set_pos(obj, 0, 183);
            lv_obj_set_size(obj, 104, 25);
            lv_label_set_text(obj, "Years In PL: ");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelEstablished
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_established = obj;
            lv_obj_set_pos(obj, 129, 91);
            lv_obj_set_size(obj, 84, 30);
            lv_label_set_text(obj, " ");
            lv_obj_set_style_text_font(obj, &ui_font_orbitron_17, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffd400), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelStadiumName
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_stadium_name = obj;
            lv_obj_set_pos(obj, 104, 61);
            lv_obj_set_size(obj, 202, 30);
            lv_label_set_text(obj, " ");
            lv_obj_set_style_text_font(obj, &ui_font_orbitron_17, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelTitlesWon
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_titles_won = obj;
            lv_obj_set_pos(obj, 129, 121);
            lv_obj_set_size(obj, 84, 30);
            lv_label_set_text(obj, " ");
            lv_obj_set_style_text_font(obj, &ui_font_orbitron_17, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff1b), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelRunnersUp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_runners_up = obj;
            lv_obj_set_pos(obj, 129, 151);
            lv_obj_set_size(obj, 84, 30);
            lv_label_set_text(obj, " ");
            lv_obj_set_style_text_font(obj, &ui_font_orbitron_17, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffb3ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // labelYearsInPL
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_years_in_pl = obj;
            lv_obj_set_pos(obj, 129, 181);
            lv_obj_set_size(obj, 84, 30);
            lv_label_set_text(obj, " ");
            lv_obj_set_style_text_font(obj, &ui_font_orbitron_17, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // imgLogo
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_logo = obj;
            lv_obj_set_pos(obj, 191, 87);
            lv_obj_set_size(obj, 115, 125);
            lv_img_set_src(obj, &img_tottenham_hotspur);
            lv_img_set_pivot(obj, 17, 23);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // imgSymbol_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_symbol_1 = obj;
            lv_obj_set_pos(obj, 104, 93);
            lv_obj_set_size(obj, 25, 25);
        }
        {
            // imgSymbol_3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_symbol_3 = obj;
            lv_obj_set_pos(obj, 104, 123);
            lv_obj_set_size(obj, 25, 25);
        }
        {
            // imgSymbol_4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_symbol_4 = obj;
            lv_obj_set_pos(obj, 104, 153);
            lv_obj_set_size(obj, 25, 25);
        }
        {
            // imgSymbol_5
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_symbol_5 = obj;
            lv_obj_set_pos(obj, 104, 183);
            lv_obj_set_size(obj, 25, 25);
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
