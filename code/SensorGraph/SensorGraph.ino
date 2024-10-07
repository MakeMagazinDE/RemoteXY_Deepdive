#define REMOTEXY_MODE__ESP32CORE_BLE
#define REMOTEXY_BLUETOOTH_NAME "SensorGraph"

#include <BLEDevice.h>
#include <Adafruit_BME280.h>
#include <RemoteXY.h>

Adafruit_BME280 sensor;

#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =
  { 255,0,0,8,0,21,0,17,0,0,0,31,1,200,84,1,1,1,0,68,
  7,3,186,76,2,8,36,135 };
  
struct {
  float graph_temp;
  float graph_humidity;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)

void setup() {
  RemoteXY_Init(); 
  Serial.begin(115200);
  if (!sensor.begin(0x76)) {
    Serial.println("BME280-Sensor wurde nicht gefunden!");
    while (true)
      delay(10);
  }
}

void loop() { 
  RemoteXY_Handler();
  RemoteXY.graph_temp = sensor.readTemperature();
  RemoteXY.graph_humidity = sensor.readHumidity();
}
