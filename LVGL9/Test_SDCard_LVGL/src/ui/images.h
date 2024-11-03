#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_arsenal;
extern const lv_img_dsc_t img_aston_villa;
extern const lv_img_dsc_t img_bournemouth;
extern const lv_img_dsc_t img_brentford;
extern const lv_img_dsc_t img_brighton;
extern const lv_img_dsc_t img_chelsea;
extern const lv_img_dsc_t img_crystal_palace;
extern const lv_img_dsc_t img_everton;
extern const lv_img_dsc_t img_fulham;
extern const lv_img_dsc_t img_ipswich_town;
extern const lv_img_dsc_t img_leicester_city;
extern const lv_img_dsc_t img_liverpool;
extern const lv_img_dsc_t img_manchester_city;
extern const lv_img_dsc_t img_manchester_united;
extern const lv_img_dsc_t img_newcastle_united;
extern const lv_img_dsc_t img_nottingham_forest;
extern const lv_img_dsc_t img_southampton;
extern const lv_img_dsc_t img_tottenham_hotspur;
extern const lv_img_dsc_t img_west_ham_united;
extern const lv_img_dsc_t img_wolves;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[20];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/