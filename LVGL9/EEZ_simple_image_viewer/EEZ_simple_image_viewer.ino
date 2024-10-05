/* 
 * This assumes you already have LVGL working with Arduino/ESP32
	- Arduino 	
		- C:\Users\kolap\Documents\Arduino
	- EEZ Studio 
		- C:\Users\kolap\eez-projects
		- C:\Users\kolap\Documents\Arduino\EEZ_studio_projects
	- Square Line
		- C:\Users\kolap\Documents\SquareLine\tutorials
		- C:\Users\kolap\Documents\SquareLine\tutorials\Export_UI_files		
		- C:\Users\kolap\Documents\Arduino\SQ_line_CYD
 1. Create UI with Squareline
  - Remember to set both screen width/height and Depth=16 bits as used by ESP32
  - File > Project settings set the following
    - Project Export Root
    - UI Files Export Path (This will contain files you will need to copy over to Arduino project)
      - Remember this location as you will need to copy the contents.
  - Export the UI code
    - Export > Export UI Files
      - This will create files in UI Files Export Path you created above
  - Create a new Arduino project 
	- Open an existing one
  - Copy all UI Files to the Arduino project root
  - In Arduino setup() add:
    - ui_init(); 
    - Run the program

 */

#include <lvgl.h>
#include "ui.h"
#include "images.h"

#include <TFT_eSPI.h>

#include <XPT2046_Touchscreen.h>
// A library for interfacing with the touch screen
//
// Can be installed from the library manager (Search for "XPT2046")
//https://github.com/PaulStoffregen/XPT2046_Touchscreen
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

  //Some basic info on the Serial console
  String LVGL_Arduino = "LVGL demo ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(115200);
  Serial.println(LVGL_Arduino);

  //Initialise the touchscreen
  touchscreenSpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); /* Start second SPI bus for touchscreen */
  touchscreen.begin(touchscreenSpi);                                         /* Touchscreen init */
  touchscreen.setRotation(3);                                                /* Inverted landscape orientation to match screen */

  //Initialise LVGL GUI
  lv_init();

  draw_buf = new uint8_t[DRAW_BUF_SIZE];
  lv_display_t *disp;
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, DRAW_BUF_SIZE);

  //Initialize the XPT2046 input device driver
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  //Done
  Serial.println("LVGL Setup done");

  //Integrate EEZ Studio GUI
  ui_init();


  //Register event handler
  lv_obj_add_event_cb(objects.btn_next_image, next_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(objects.btn_prev_image, prev_event_handler, LV_EVENT_CLICKED, NULL);
}

uint32_t currentPic = 0;
uint32_t totalNumberOfImages = 10;  //Number of images (After adding 10 bitmap image I started seeing memory issues)



static void next_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);         //Get the event code
  lv_obj_t *btn = (lv_obj_t *)lv_event_get_target(e);  //Switch that generated the event
  // lv_obj_t *image = (lv_obj_t *)lv_event_get_user_data(e);  //Label or other UI elements we want to update (Optional)

  if (code == LV_EVENT_CLICKED) {
    if (currentPic >= 0 && currentPic < totalNumberOfImages) {

      lv_image_set_src(objects.img_logo, NULL);
      setNewImage(currentPic);

      //Set to next image
      currentPic++;
    } else {
      //Set it to the first picture again
      currentPic = 0;
      setNewImage(currentPic);
    }
  }
}

static void prev_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);         //Get the event code
  lv_obj_t *btn = (lv_obj_t *)lv_event_get_target(e);  //Switch that generated the event
  // lv_obj_t *image = (lv_obj_t *)lv_event_get_user_data(e);  //Label or other UI elements we want to update (Optional)

  if (code == LV_EVENT_CLICKED) {
    if (currentPic >= 0 && currentPic < totalNumberOfImages) {
      lv_image_set_src(objects.img_logo, NULL);
      setNewImage(currentPic);
      //Set to next image
      currentPic--;
    } else {
      //Set it to the last picture picture again
      currentPic = 9;
      setNewImage(currentPic);
    }
  }
}

/**
  Football club logos from this
  https://github.com/luukhopman/football-logos/tree/master/logos
*/
void setNewImage(uint8_t currentPic) {
  if (currentPic == 0) {
    lv_image_set_src(objects.img_logo, &img_liverpool);
  } else if (currentPic == 1) {
    lv_image_set_src(objects.img_logo, &img_man_city);
  } else if (currentPic == 2) {
    lv_image_set_src(objects.img_logo, &img_arsenal);
  } else if (currentPic == 3) {
    lv_image_set_src(objects.img_logo, &img_chelsea);
  } else if (currentPic == 4) {
    lv_image_set_src(objects.img_logo, &img_aston_villa);
  } else if (currentPic == 5) {
    lv_image_set_src(objects.img_logo, &img_newcastle);
  } else if (currentPic == 6) {
    lv_image_set_src(objects.img_logo, &img_fulham);
  } else if (currentPic == 7) {
    lv_image_set_src(objects.img_logo, &img_tottenham);
  } else if (currentPic == 8) {
    lv_image_set_src(objects.img_logo, &img_brentford);
  } else if (currentPic == 9) {
    lv_image_set_src(objects.img_logo, &img_brighton);
  }
}


//Requires LVGL 9.1
void loop() {

  lv_tick_inc(millis() - lastTick);  //Update the tick timer. Tick is new for LVGL 9
  lastTick = millis();
  lv_timer_handler();  //Update the UI
  delay(5);
}