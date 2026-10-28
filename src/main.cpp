#include <Arduino.h>
#include "display_manager.h"

void setup() {
  Serial.begin(115200);

  if (!DisplayManager::begin()) {
    Serial.println("Failed to initialize display");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("OLED initialized successfully");

  DisplayManager::showAnswer(Answer::Yes);
  delay(2000);

  DisplayManager::showAnswer(Answer::No);
  delay(2000);

  DisplayManager::showAnswer(Answer::Unknown);
}

void loop() {
  
}
