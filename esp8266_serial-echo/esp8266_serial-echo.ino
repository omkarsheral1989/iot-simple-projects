/*
  Whatever is sent from serial port is written back to it.
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  delay(500);
  
  Serial.println("");
  Serial.println("Hello! this is echo mode. Whatever you write will return u back");

}

void loop() {
  if (Serial.available() > 0) {
    Serial.write(Serial.read());
  }
}
