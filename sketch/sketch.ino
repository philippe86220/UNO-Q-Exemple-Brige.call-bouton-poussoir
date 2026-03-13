#include <Arduino.h>
#include <Arduino_RouterBridge.h>

const byte pin = 8;
const unsigned long debounceMs = 20;

unsigned long lastTime = 0;

void setup() {
  pinMode(pin, INPUT_PULLUP);
  Bridge.begin();
  Monitor.begin();
  Monitor.println("MCU ready");
  lastTime = millis();
}

void loop() {
  if ((digitalRead(pin) == LOW) && (millis() - lastTime > debounceMs)) {
    requestTime();
    lastTime = millis();

    while (digitalRead(pin) == LOW) { }
  }
}

void requestTime() {
  String timeString;
  RpcCall rpc = Bridge.call("get_system_time");

  if (rpc.result(timeString)) {
    Monitor.println("Time received from MPU: " + timeString);
  } else {
    Monitor.println("RPC error code: " + String(rpc.getErrorCode()));
    Monitor.println("RPC error message: " + rpc.getErrorMessage());
  }
}
