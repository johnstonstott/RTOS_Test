#include <Arduino.h>

#define LED_BUILTIN 2

void addNum(void *parameter) {
  int num = 0;
  while(true) {
    num++;
    Serial.println("Completed addNum on core " + String(xPortGetCoreID()));
  }
}

void subNum(void *parameter) {
  int num = 32767;
  while(true) {
    num--;
    Serial.println("Completed subNum on core " + String(xPortGetCoreID()));
  }
}

void toggleLED(void *parameter) {
  int durations[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
  int dur = 0;
  while(true) {
    if(dur < 9) {
      dur++;
    } else {
      dur = 0;
    }

    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(durations[dur]);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(100);

    Serial.println("Completed toggleLED on core " + String(xPortGetCoreID()));
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreate(toggleLED, "Toggle LED", 1000, NULL, 1, NULL);
  xTaskCreate(addNum, "Add Num", 1000, NULL, 1, NULL);
  xTaskCreate(subNum, "Sub Num", 1000, NULL, 1, NULL);
}

void loop() { }
