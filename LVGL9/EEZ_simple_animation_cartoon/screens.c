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
    {
        lv_obj_t *parent_obj = obj;
        {
            // labelHeader
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_header = obj;
            lv_obj_set_pos(obj, 24, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Simple Animation Cartoon");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    {
      //---------------------------------------------------------
      // Creates the animation cartoon
      //---------------------------------------------------------
      lv_color_t bd_color = lv_palette_lighten(LV_PALETTE_AMBER, 5);
      lv_color_t bd_color_teeths = lv_color_black();
      uint32_t pause_at_the_end = 2000;

      uint32_t start_size = 5;
      uint32_t end_size = 140;
      uint32_t anim_duration = 4000;
      uint32_t revert_back_duration = 1000;
      uint32_t pause_before_starting_anim_again = 200;
      uint32_t start_X_position = -110;
      uint32_t end_X_position = 95;

      //Create object circle for the hair
      lv_obj_t *hair1 = lv_obj_create(parent_obj);
      lv_obj_align(hair1, LV_ALIGN_LEFT_MID, 10, 10);
      lv_obj_set_style_radius(hair1, LV_RADIUS_CIRCLE, 0);
      lv_obj_set_style_bg_color(hair1, lv_color_black(), 0);
      animateObject(hair1, start_size, end_size, anim_duration, pause_at_the_end, revert_back_duration, pause_before_starting_anim_again, start_X_position, end_X_position);  //Go from 50 to 5
      //animateObject(hair1, 5, 140, 4000, pause_at_the_end, 1000, 200, start_X_position,  95);  //Go from 50 to 5

      //Create object square for the body
      lv_obj_t *body1 = lv_obj_create(parent_obj);
      lv_obj_align(body1, LV_ALIGN_LEFT_MID, 10, 135);
      lv_obj_set_style_bg_color(body1, lv_color_black(), 0);
      lv_obj_set_style_border_width(body1, 5, 0);
      animateObject(body1, 5, 150, 4000, pause_at_the_end, 1000, 200, start_X_position, 90);  //Go from 50 to 5

      //Create object square for the ear 1
      lv_obj_t *ear1 = lv_obj_create(parent_obj);
      lv_obj_align(ear1, LV_ALIGN_LEFT_MID, 10, 50);
      lv_obj_set_style_radius(ear1, LV_RADIUS_CIRCLE, 0);
      lv_obj_set_style_bg_color(ear1, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
      lv_obj_set_style_border_width(ear1, 5, 0);
      animateObject(ear1, 5, 30, 4000, pause_at_the_end, 1000, 200, start_X_position, 90);  //Go from 50 to 5

      //Create object square for the ear 2
      lv_obj_t *ear2 = lv_obj_create(parent_obj);
      lv_obj_align(ear2, LV_ALIGN_LEFT_MID, 10, 50);
      lv_obj_set_style_radius(ear2, LV_RADIUS_CIRCLE, 0);
      lv_obj_set_style_bg_color(ear2, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
      lv_obj_set_style_border_width(ear2, 5, 0);
      animateObject(ear2, 5, 30, 4000, pause_at_the_end, 1000, 200, start_X_position, 210);  //Go from 50 to 5

      //Create object circle for the face
      lv_obj_t *face1 = lv_obj_create(parent_obj);
      lv_obj_align(face1, LV_ALIGN_LEFT_MID, 10, 25);
      lv_obj_set_style_radius(face1, LV_RADIUS_CIRCLE, 0);
      lv_obj_set_style_bg_color(face1, lv_palette_main(LV_PALETTE_PURPLE), 0);
      lv_obj_set_style_border_color(face1, bd_color, 0);
      lv_obj_set_style_border_width(face1, 5, 0);
      animateObject(face1, 5, 120, 4000, pause_at_the_end, 1000, 200, start_X_position, 105);  //Go from 50 to 5


      // Create object eye 1
      lv_obj_t *eye1 = lv_obj_create(parent_obj);
      lv_obj_align(eye1, LV_ALIGN_LEFT_MID, 10, 20);
      lv_obj_set_style_radius(eye1, LV_RADIUS_CIRCLE, 0);
      lv_obj_set_style_bg_color(eye1, lv_palette_main(LV_PALETTE_GREY), 0);
      lv_obj_set_style_border_color(eye1, bd_color, 0);
      lv_obj_set_style_border_width(eye1, 5, 0);
      animateObject(eye1, 100, 25, 4000, pause_at_the_end, 1000, 200, start_X_position, 130);  //Go from 5 to 50

      //Create object eye 2
      lv_obj_t *eye2 = lv_obj_create(parent_obj);
      lv_obj_align(eye2, LV_ALIGN_LEFT_MID, 10, 20);
      lv_obj_set_style_radius(eye2, LV_RADIUS_CIRCLE, 0);
      lv_obj_set_style_bg_color(eye2, lv_palette_main(LV_PALETTE_CYAN), 0);
      animateObject(eye2, 100, 25, 4000, pause_at_the_end, 1000, 200, start_X_position, 180);  //Same size


      // //Create object for teeth
      lv_obj_t *object5 = lv_obj_create(parent_obj);
      lv_obj_align(object5, LV_ALIGN_LEFT_MID, 10, 50);
      lv_obj_set_style_bg_color(object5, lv_palette_main(LV_PALETTE_DEEP_ORANGE), 0);
      lv_obj_set_style_border_color(object5, bd_color_teeths, 0);
      lv_obj_set_style_border_width(object5, 2, 0);
      animateObject(object5, 100, 15, 4000, pause_at_the_end, 1000, 200, start_X_position, 135);  //Go from 50 to 5

      // //Create object 5 teeth
      lv_obj_t *object6 = lv_obj_create(parent_obj);
      lv_obj_align(object6, LV_ALIGN_LEFT_MID, 10, 55);
      lv_obj_set_style_bg_color(object6, lv_palette_main(LV_PALETTE_DEEP_ORANGE), 0);
      lv_obj_set_style_border_color(object6, bd_color_teeths, 0);
      lv_obj_set_style_border_width(object6, 2, 0);
      animateObject(object6, 100, 15, 4000, pause_at_the_end, 1000, 200, start_X_position, 145);  //Go from 50 to 5

      // //Create object 5 teeth
      lv_obj_t *object7 = lv_obj_create(parent_obj);
      lv_obj_align(object7, LV_ALIGN_LEFT_MID, 10, 55);
      lv_obj_set_style_bg_color(object7, lv_palette_main(LV_PALETTE_DEEP_ORANGE), 0);
      lv_obj_set_style_border_color(object7, bd_color_teeths, 0);
      lv_obj_set_style_border_width(object7, 2, 0);
      animateObject(object7, 100, 15, 4000, pause_at_the_end, 1000, 200, start_X_position, 155);  //Go from 50 to 5

      // //Create object 5 teeth
      lv_obj_t *object8 = lv_obj_create(parent_obj);
      lv_obj_align(object8, LV_ALIGN_LEFT_MID, 10, 55);
      lv_obj_set_style_bg_color(object8, lv_palette_main(LV_PALETTE_DEEP_ORANGE), 0);
      lv_obj_set_style_border_color(object8, bd_color_teeths, 0);
      lv_obj_set_style_border_width(object8, 2, 0);
      animateObject(object8, 100, 15, 4000, pause_at_the_end, 1000, 200, start_X_position, 165);  //Go from 50 to 5

      // //Create object 5 teeth
      lv_obj_t *object9 = lv_obj_create(parent_obj);
      lv_obj_align(object9, LV_ALIGN_LEFT_MID, 10, 50);
      lv_obj_set_style_bg_color(object9, lv_palette_main(LV_PALETTE_DEEP_ORANGE), 0);
      lv_obj_set_style_border_color(object9, bd_color_teeths, 0);
      lv_obj_set_style_border_width(object9, 2, 0);
      animateObject(object9, 100, 15, 4000, pause_at_the_end, 1000, 200, start_X_position, 175);  //Go from 50 to 5
    }
    }
}

	
	
//Callback to change the size
static void anim_size_cb(void *var, int32_t v) {
  lv_obj_set_size((lv_obj_t *)var, v, v);
}

//Callback to move it along the X-axis
static void anim_x_cb(void *var, int32_t v) {
  lv_obj_set_x((lv_obj_t *)var, v);
}

void animateObject(lv_obj_t *obj, int32_t startSize, int32_t endSize, int32_t duration, int32_t pauseAtTheEnd,
                   int32_t revertBackDuration, int32_t delayBeforeRunningAgain, int32_t startX, int32_t endX) {

  lv_anim_t animationObj;                                            //Create animation object
  lv_anim_init(&animationObj);                                       //Initialie animation object
  lv_anim_set_var(&animationObj, obj);                               //This is normally the Screen or other GUI elements ARC/Bar
  lv_anim_set_values(&animationObj, startSize, endSize);             //Start and end size
  lv_anim_set_duration(&animationObj, duration);                     //Length of the animation
  lv_anim_set_playback_delay(&animationObj, pauseAtTheEnd);          //Pause at the end of the duration before palying back
  lv_anim_set_playback_duration(&animationObj, revertBackDuration);  //Anim time to come backwards to original position
  lv_anim_set_repeat_delay(&animationObj, delayBeforeRunningAgain);  //Pause before replaying the animation
  lv_anim_set_repeat_count(&animationObj, LV_ANIM_REPEAT_INFINITE);  //Number of times to repeat
  lv_anim_set_path_cb(&animationObj, lv_anim_path_ease_in_out);      //Choose what the animation should do

  //Set callback function to set the size and animate
  lv_anim_set_exec_cb(&animationObj, anim_size_cb);
  lv_anim_start(&animationObj);

  //Set callback function to position and animate (move it from startX -> endX x-axis)
  lv_anim_set_exec_cb(&animationObj, anim_x_cb);
  lv_anim_set_values(&animationObj, startX, endX);  //Start and end X-axis position
  lv_anim_start(&animationObj);
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
