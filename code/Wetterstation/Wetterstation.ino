#define REMOTEXY_MODE__ESP32CORE_BLE
#define REMOTEXY_BLUETOOTH_NAME "BME280-Sensor"

#include <RemoteXY.h>
#include <BLEDevice.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 sensor;

#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =
  { 255,0,0,24,0,82,0,17,0,0,0,31,1,200,84,1,1,4,0,67,
  140,18,26,15,4,8,31,12,67,140,35,29,15,4,24,31,12,129,26,20,
  95,12,24,84,101,109,112,101,114,97,116,117,114,32,40,194,176,67,41,58,
  0,129,27,37,116,12,24,76,117,102,116,102,101,117,99,104,116,105,103,107,
  101,105,116,32,40,37,41,58,0 };
  
struct {
  char text_temp[12];
  char text_humidity[12];
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
  dtostrf(sensor.readTemperature(), 0, 1, RemoteXY.text_temp);
  dtostrf(sensor.readHumidity(), 0, 1, RemoteXY.text_humidity);
}
