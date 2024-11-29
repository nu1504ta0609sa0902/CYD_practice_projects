#include <Arduino.h>
#include <ui/actions.h>
#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include <ui/vars.h>

extern "C" void action_rotate_screen(lv_event_t *e)
{
    auto disp = lv_disp_get_default();
    auto rotation = (lv_display_rotation_t)((lv_disp_get_rotation(disp) + 1) % (LV_DISPLAY_ROTATION_270 + 1));
    lv_display_set_rotation(disp, rotation);
}

extern "C" void action_set_led_red(lv_event_t *e)
{
#ifdef BOARD_HAS_RGB_LED
    smartdisplay_led_set_rgb(255, 0, 0);
#endif
}

extern "C" void action_set_led_green(lv_event_t *e)
{
#ifdef BOARD_HAS_RGB_LED
    smartdisplay_led_set_rgb(0, 255, 0);
#endif
}

extern "C" void action_set_led_blue(lv_event_t *e)
{
#ifdef BOARD_HAS_RGB_LED
    smartdisplay_led_set_rgb(0, 0, 255);
#endif
}

int32_t slider_variable;
ulong next_millis;
auto lv_last_tick = millis();

// This getter is required to be implemented, but the current example doesn't use it.

extern "C" int32_t get_var_slider_variable() {
    return slider_variable;
}

extern "C" void set_var_slider_variable(int32_t value) {
    slider_variable = value;
}


void setup()
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);

    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();

    auto disp = lv_disp_get_default();

    lv_disp_set_rotation(disp, lv_display_rotation_t::LV_DISPLAY_ROTATION_90);

    ui_init();
}


void loop()
{
    auto const now = millis();

    // update the UI label elements every 50ms
    if (now > next_millis)
    {
        next_millis = now + 50;

        char text_buffer[32];

        sprintf(text_buffer, "millis(): %lu", now);
        lv_label_set_text(objects.millis_label, text_buffer);

#ifdef BOARD_HAS_CDS
        auto cdr = analogReadMilliVolts(CDS);
        sprintf(text_buffer, "Light Sensor: %d", cdr);
        lv_label_set_text(objects.light_sensor_label, text_buffer);
#endif

        sprintf(text_buffer, "Slider Value: %lu", slider_variable);
        lv_label_set_text(objects.slider_value_label, text_buffer);
    }

    // Update the ticker
    lv_tick_inc(now - lv_last_tick);
    lv_last_tick = now;
    // Update the UI
    lv_timer_handler();
    // This is important to call as it is what makes variables in EEZ studio
    // get updated automatically for active screen if they are used.
    ui_tick();
}