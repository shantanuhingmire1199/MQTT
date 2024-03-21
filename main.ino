#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* mqtt_server = "mqtt_server_address";
const int mqtt_port = 1883;
const char* mqtt_username = "mqtt_username";
const char* mqtt_password = "mqtt_password";
const char* mqtt_topic_config = "esp32/config";
const char* mqtt_topic_control = "esp32/control";

WiFiClient espClient;
PubSubClient client(espClient);

const int num_relays = 2;
const int relay_pins[num_relays] = {GPIO_PIN_1, GPIO_PIN_2};
const int num_light_bulbs = 2;

void setup() {
  Serial.begin(9600);
  connectToWiFi();
  connectToMQTT();
  client.subscribe(mqtt_topic_control); // Subscribe to control topic
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
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
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle received messages here
  payload[length] = '\0'; // Null terminate the payload
  
  String messageTopic = String(topic);
  String messagePayload = String((char *)payload);

  Serial.print("Message arrived [");
  Serial.print(messageTopic);
  Serial.print("] ");
  Serial.println(messagePayload);

  // Check if the message topic matches the control topic
  if (messageTopic.equals(mqtt_topic_control)) {
    // Check the payload content to determine action
    if (messagePayload.equals("light_on")) {
      // Turn on the lights
      // Implement your relay control logic here
      Serial.println("Turning on the lights...");
      // For example, if you're using relays
      // digitalWrite(relay_pins[0], HIGH);
      // digitalWrite(relay_pins[1], HIGH);
    } else if (messagePayload.equals("light_off")) {
      // Turn off the lights
      // Implement your relay control logic here
      Serial.println("Turning off the lights...");
      // For example, if you're using relays
      // digitalWrite(relay_pins[0], LOW);
      // digitalWrite(relay_pins[1], LOW);
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client", mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe(mqtt_topic_control);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
