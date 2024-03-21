# ESP32 MQTT Light Control

This project demonstrates how to control lights using MQTT messages with an ESP32 microcontroller. It allows you to remotely turn the lights on or off using any MQTT client, such as a mobile app or desktop application.

## Requirements

- ESP32 microcontroller
- WiFi network
- MQTT broker/server
- Light bulbs or devices connected to relays controlled by the ESP32

## Setup

1. **Hardware Setup:**
   - Connect the ESP32 to the WiFi network.
   - Connect the light bulbs or devices to the relay pins on the ESP32.

2. **Software Setup:**
   - Install the required libraries: `WiFi.h`, `PubSubClient.h`.
   - Configure the WiFi and MQTT settings in the code (`ssid`, `password`, `mqtt_server`, `mqtt_port`, `mqtt_username`, `mqtt_password`).
   - Customize the MQTT topics (`mqtt_topic_control`) and pins (`relay_pins`) as needed.

3. **Upload Code:**
   - Upload the provided Arduino sketch to the ESP32 microcontroller using the Arduino IDE or your preferred method.

4. **MQTT Broker:**
   - Ensure that an MQTT broker/server is running and accessible from the ESP32.
   - Note down the MQTT broker address, port, username, and password.

5. **Control Lights:**
   - Use any MQTT client, such as a mobile app or desktop application, to publish messages to the control topic (`esp32/control`).
   - Send the message "light_on" to turn on the lights and "light_off" to turn off the lights.

## Usage

- After uploading the code to the ESP32 and setting up the MQTT broker, you can remotely control the lights using MQTT messages.
- Ensure that the ESP32 is connected to the WiFi network and the MQTT broker to receive and process the messages.
- Monitor the serial output of the ESP32 to observe the status and debug any issues.

## Troubleshooting

- If the lights are not responding to MQTT messages, check the serial output of the ESP32 for any error messages.
- Verify the WiFi and MQTT configurations in the code.
- Ensure that the MQTT broker is running and accessible from the ESP32.

## Contributors

- Shantanu H (https://github.com/shantanuhingmire1199)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
