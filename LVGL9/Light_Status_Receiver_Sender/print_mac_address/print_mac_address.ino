/**
*     GET MAC addresss 

  GREAT ESP-NOW example here:
  https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  https://dronebotworkshop.com/esp-now/
*/
#include <WiFi.h>
#include <esp_wifi.h>

void setup() {
  Serial.begin(115200);

  Serial.print("ESP Board MAC Address: ");
  WiFi.mode(WIFI_STA);
  WiFi.STA.begin();
  uint8_t baseMac[6];
  esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
  if (ret == ESP_OK) {
    Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                  baseMac[0], baseMac[1], baseMac[2],
                  baseMac[3], baseMac[4], baseMac[5]);
  } else {
    Serial.println("Failed to read MAC address");
  }
}

void loop() {
}