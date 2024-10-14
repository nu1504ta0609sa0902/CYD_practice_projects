/* Using LVGL with Arduino requires some extra steps...
 *  
 * Be sure to read the docs here: https://docs.lvgl.io/master/integration/framework/arduino.html
 * but note you should use the lv_conf.h from the repo as it is pre-edited to work.
 * 
 * You can always edit your own lv_conf.h later and exclude the example options once the build environment is working.
 * 
 * Note you MUST move the 'examples' and 'demos' folders into the 'src' folder inside the lvgl library folder 
 * otherwise this will not compile, please see README.md in the repo.

 ALL examples here:
  https://docs.lvgl.io/master/examples.html

  LVGL setup:
    https://randomnerdtutorials.com/lvgl-esp32-tft-touchscreen-display-ili9341-arduino/
 * 
 */
#include <lvgl.h>
#include "ui.h"

#include <TFT_eSPI.h>

//A library for interfacing with the touch screen
//Can be installed from the library manager (Search for "XPT2046")
//https://github.com/PaulStoffregen/XPT2046_Touchscreen
#include <XPT2046_Touchscreen.h>

// ----------------------------
// Touch Screen pins
// ----------------------------

// The CYD touch uses some non default
// SPI pins

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33
SPIClass touchscreenSpi = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
uint16_t touchScreenMinimumX = 200, touchScreenMaximumX = 3700, touchScreenMinimumY = 240, touchScreenMaximumY = 3800;

/*Set to your screen resolution*/
#define TFT_HOR_RES 320
#define TFT_VER_RES 240

/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

#if LV_USE_LOG != 0
void my_print(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
#endif

/* LVGL calls it when a rendered image needs to copied to the display*/
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  /*Call it to tell LVGL you are ready*/
  lv_disp_flush_ready(disp);
}
/*Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) {
  if (touchscreen.touched()) {
    TS_Point p = touchscreen.getPoint();
    //Some very basic auto calibration so it doesn't go out of range
    if (p.x < touchScreenMinimumX) touchScreenMinimumX = p.x;
    if (p.x > touchScreenMaximumX) touchScreenMaximumX = p.x;
    if (p.y < touchScreenMinimumY) touchScreenMinimumY = p.y;
    if (p.y > touchScreenMaximumY) touchScreenMaximumY = p.y;
    //Map this to the pixel position
    data->point.x = map(p.x, touchScreenMinimumX, touchScreenMaximumX, 1, TFT_HOR_RES); /* Touchscreen X calibration */
    data->point.y = map(p.y, touchScreenMinimumY, touchScreenMaximumY, 1, TFT_VER_RES); /* Touchscreen Y calibration */
    data->state = LV_INDEV_STATE_PRESSED;
    /*
    Serial.print("Touch x ");
    Serial.print(data->point.x);
    Serial.print(" y ");
    Serial.println(data->point.y);
    */
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

lv_indev_t *indev;      //Touchscreen input device
uint8_t *draw_buf;      //draw_buf is allocated on heap otherwise the static area is too big on ESP32 at compile
uint32_t lastTick = 0;  //Used to track the tick timer



void setup() {
  // Comment the next line, If your code aleady include connection to Wifi in mode WIFI_STA (WIFI_AP and WIFI_AP_STA are not supported)
  // gpio_viewer.connectToWifi("SKY2FC50", "NDSFPSLDQR");

  //Some basic info on the Serial console
  String LVGL_Arduino = "LVGL demo ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(115200);
  Serial.println(LVGL_Arduino);

  //Initialise the touchscreen
  touchscreenSpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); /* Start second SPI bus for touchscreen */
  touchscreen.begin(touchscreenSpi);                                         /* Touchscreen init */
  touchscreen.setRotation(3);                                                /* Inverted landscape orientation to match screen */

  //Initialise LVGL
  lv_init();
  draw_buf = new uint8_t[DRAW_BUF_SIZE];
  lv_display_t *disp;
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, DRAW_BUF_SIZE);

  //Initialize the XPT2046 input device driver
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  //Examples
  //lv_example_scroll_1();

  //Done
  Serial.println("Setup done");

  //Initialise EEZ Gui
  ui_init();


  //Register event handlers
  lv_obj_add_event_cb(objects.btn_start_bar_anim, start_button_anim_event_cb, LV_EVENT_CLICKED, objects.bar1);
  lv_obj_add_event_cb(objects.btn_start_slider_anim, start_button_anim_event_cb, LV_EVENT_CLICKED, objects.slider1);
}


static void set_bar_value(void *obj, int32_t v) {
  lv_bar_set_value((lv_obj_t *)obj, v, LV_ANIM_ON);
}

static void start_button_anim_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);                     //Get the event code
  lv_obj_t *btn = (lv_obj_t *)lv_event_get_target(e);              //Switch that generated the event
  lv_obj_t *objToAnimate = (lv_obj_t *)lv_event_get_user_data(e);  //Label or other UI elements we want to update (Optional)

  if (code == LV_EVENT_CLICKED) {
    lv_anim_t a;       //Initialse Animation
    lv_anim_init(&a);  //Initialse Animation

    lv_anim_set_var(&a, objToAnimate);                      //Apply animation to this object
    lv_anim_set_values(&a, 0, 100);                         //Value range
    lv_anim_set_duration(&a, random(500, 5000));            //Length of animation
    lv_anim_set_playback_duration(&a, random(500, 5000));   //Time it the animation to return back to original position
    lv_anim_set_playback_delay(&a, random(500, 1500));      //Pause at the end of the duration before palying back
    lv_anim_set_repeat_delay(&a, random(500, 1500));        //Pause before replaying the animation again
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);  //Run repeatedly
    lv_anim_set_exec_cb(&a, set_bar_value);                 //This will set the animation position/value
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in);          //Use one of the pre-defined algo
    lv_anim_start(&a);                                      //Start animation
  }
}

void loop() {
  lv_tick_inc(millis() - lastTick);  //Update the tick timer. Tick is new for LVGL 9
  lastTick = millis();
  lv_timer_handler();  //Update the UI
  delay(5);
}