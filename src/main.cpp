#include <Arduino.h>

#define LED_BUILTIN 2

void task1(void *parameter) {
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 10;
  xLastWakeTime = xTaskGetTickCount();

  while(true) {
    Serial.println("task1 (freq 10) done at " + String(xLastWakeTime));
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}

void task2(void *parameter) {
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 20;
  xLastWakeTime = xTaskGetTickCount();

  while(true) {
    Serial.println("task2 (freq 20) done at " + String(xLastWakeTime));
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}

void task3(void *parameter) {
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 30;
  xLastWakeTime = xTaskGetTickCount();

  while(true) {
    Serial.println("task3 (freq 30) done at " + String(xLastWakeTime));
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}

void task4(void *parameter) {
  while(true) {
    Serial.println("task4 done at " + String(xTaskGetTickCount()));
    vTaskDelay(100);
  }
}

void toggleLED(void *parameter) {
  while(true) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(100);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(100);

    Serial.println("toggleLED done");
  }

}

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreate(toggleLED, "Toggle LED", 1000, NULL, 1, NULL);
  xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
  xTaskCreate(task2, "Task 2", 1000, NULL, 1, NULL);
  xTaskCreate(task3, "Task 3", 1000, NULL, 1, NULL);
  xTaskCreate(task4, "Task 4", 1000, NULL, 1, NULL);
}

void loop() { }
