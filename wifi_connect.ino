#include <WiFi.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

void setup() {
  Serial.begin(9600);
  connectToWiFi();
}

void loop() {
  // Your main code here
}

void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
