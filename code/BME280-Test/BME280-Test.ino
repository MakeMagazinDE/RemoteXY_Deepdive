#include <Adafruit_BME280.h>

const float SEA_LEVEL_PRESSURE_HPA = 1013.25;

Adafruit_BME280 sensor;

void setup() {
    Serial.begin(9600);
    if (!sensor.begin(0x76)) {
        Serial.println("BME280-Sensor wurde nicht gefunden!");
        while (true)
            delay(10);
    }
}

void loop() { 
    Serial.printf("Temperatur = %.2f °C\n", sensor.readTemperature());
    Serial.printf("Luftdruck = %.2f hPa\n", sensor.readPressure() / 100.0f);
    Serial.printf("Geschätzte Höhe = %.2f m\n", sensor.readAltitude(SEA_LEVEL_PRESSURE_HPA));
    Serial.printf("Luftfeuchtigkeit = %.2f %%\n\n", sensor.readHumidity());
    delay(5000);
}
