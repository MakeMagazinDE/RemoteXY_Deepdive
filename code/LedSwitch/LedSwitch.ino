// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"

#include <BLEDevice.h>
#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 36 bytes
  { 255,1,0,0,0,29,0,17,0,0,0,31,1,106,200,1,1,1,0,2,
  28,13,44,22,0,2,26,31,31,79,78,0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {
    // input variables
  uint8_t switch_01; // =1 if switch ON and =0 if OFF
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0
} RemoteXY;   
#pragma pack(pop)
 
#define PIN_SWITCH_01 2

void setup() {
  RemoteXY_Init();  
  pinMode(PIN_SWITCH_01, OUTPUT);
}

void loop() { 
  RemoteXY_Handler();
  digitalWrite(PIN_SWITCH_01, (RemoteXY.switch_01 == 0) ? LOW : HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
}
