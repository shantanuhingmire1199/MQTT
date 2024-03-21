#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* mqtt_server = "mqtt_server_address";
const int mqtt_port = 1883;
const char* mqtt_username = "mqtt_username";
const char* mqtt_password = "mqtt_password";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  connectToWiFi();
  connectToMQTT();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void connectToWiFi() {
  // WiFi connection code
}

void connectToMQTT() {
  client.setServer(mqtt_server, mqtt_port);
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client", mqtt_username, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
