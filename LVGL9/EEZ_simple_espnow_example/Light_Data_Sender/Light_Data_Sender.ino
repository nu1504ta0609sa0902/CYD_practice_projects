/**
*     SENDER collects states and sends it to CYD
        - MASTER

      - 1 ESP32 + Photoresistor sensor to get reading
        - Receiving Boards MAC Address: 08:b6:1f:b9:5a:8c
        - Sending Board MAC Address: a0:dd:6c:85:af:ac

  GREAT ESP-NOW example here:
  https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  https://dronebotworkshop.com/esp-now/
*/

#include <WiFi.h>
#include <esp_now.h>

// REPLACE WITH THE RECEIVER'S MAC Address 08:b6:1f:b9:5a:8c
uint8_t broadcastAddress[] = {0x08, 0xB6, 0x1F, 0xB9, 0x5A, 0x8C};

//Don't forget to add pinMode(pinToUse, OUTPUT);
#define LIGHT_SENSOR_PIN 34 // ESP32 pin GIOP36 (ADC0)
#define LED_15 25           // Optional LED on breadboard


// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
    int id; // must be unique for each sender board
    bool lightIsOn;  // centimeter
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Create peer interface
esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  
  //Set pin modes
  pinMode(LED_15, OUTPUT);
}
 
void loop() {
  
  // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  //int light = map(analogValue, 1023, 0, 10, 0);
  int lightResistance = map(analogValue, 0, 1023, 0, 10);
  Serial.print(analogValue);   // the raw analog reading
  Serial.print(" -> ");   // the raw analog reading
  Serial.print(lightResistance);   // convert analogueValue to between 0 and 10
  Serial.println();

  bool isOn = false;
  // Higher value = Darker = More resistance so turn the light on
  if(lightResistance > 25){
    //Time to turn the light on
    Serial.print("ON");
    digitalWrite(LED_15, HIGH);
    isOn = true;
  }else{
    Serial.print("OFF");
    digitalWrite(LED_15, LOW);
    isOn = false;
  }

  
  // Set values to send
  myData.id = 1;
  myData.lightIsOn = isOn;

  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }

  delay(1000);
}