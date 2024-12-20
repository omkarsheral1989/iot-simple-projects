#include "SPIFFS.h"

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(20); // wait for serial port to connect. Needed for native USB port only
  }

  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  File file = SPIFFS.open("/sample.txt");
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.println("\nFile Content:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void loop() {

}
