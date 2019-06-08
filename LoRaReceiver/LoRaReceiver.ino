#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    lcd.print((char)LoRa.read());
    }
    

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
