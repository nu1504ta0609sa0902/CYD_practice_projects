#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_rotate_screen(lv_event_t * e);
extern void action_set_led_red(lv_event_t * e);
extern void action_set_led_green(lv_event_t * e);
extern void action_set_led_blue(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/