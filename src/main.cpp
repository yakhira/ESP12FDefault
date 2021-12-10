#include "setup/wifi.h"

// -------- DEFAULT SKETCH PARAMETERS --------
const int SKETCH_VERSION = 1; 

ESPWiFi espwifi("ESP12-F");

void setup() {
	Serial.begin(74880);
	espwifi.wifiConnect();
	espwifi.updateSketch(SKETCH_VERSION);
	Serial.println(WIFI_AP);
	Serial.println(WiFi.getMode());

	// GPIO16 + RST
	// ESP.deepSleepInstant(60e6);
}

void loop() {
	if (WiFi.getMode() == WIFI_STA) {
		if (WiFi.status() != WL_CONNECTED) {
			WiFi.reconnect();
		}
	}

	espwifi.stateCheck();
}