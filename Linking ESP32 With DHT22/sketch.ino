#include "DHTesp.h"
const int DHT_PIN = 15;


DHTesp dhtSensor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}


void loop() {
  // put your main code here, to run repeatedly:
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  Serial.println("Temp: " + String(data.temperature, 2) + "°C");
  Serial.println("Humidity: " + String(data.humidity, 1) + "%");
  Serial.println("---");
  delay(2000); // Wait for a new reading from the sensor (DHT22 has ~0.5Hz sample rate)
}



