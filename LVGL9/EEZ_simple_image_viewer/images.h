#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_arsenal;
extern const lv_img_dsc_t img_tottenham;
extern const lv_img_dsc_t img_aston_villa;
extern const lv_img_dsc_t img_brentford;
extern const lv_img_dsc_t img_brighton;
extern const lv_img_dsc_t img_chelsea;
extern const lv_img_dsc_t img_fulham;
extern const lv_img_dsc_t img_liverpool;
extern const lv_img_dsc_t img_man_city;
extern const lv_img_dsc_t img_newcastle;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[10];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/