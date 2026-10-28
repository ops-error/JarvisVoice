#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "display_manager.h"

namespace {

    constexpr int SCREEN_WIDTH = 128;
    constexpr int SCREEN_HEIGHT = 64;

    constexpr int SDA_PIN = 21;
    constexpr int SCL_PIN = 22;

    constexpr uint8_t OLED_ADDRESS = 0x3C;

    Adafruit_SSD1306 display(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        &Wire,
        -1
    );
}

namespace DisplayManager {
    bool begin() {
        Wire.begin(SDA_PIN, SCL_PIN);

        if (!display.begin(
            SSD1306_SWITCHCAPVCC,
            OLED_ADDRESS
        )) {
            return false;
        }

        display.clearDisplay();
        display.setTextColor(SSD1306_WHITE);
        display.display();

        return true;
    }

    void showMwssage(
        const char* title,
        const char* message
    ) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println(title);

        display.drawLine(
            0, 12, SCREEN_WIDTH -1, 12, SSD1306_WHITE
        );

        display.setTextSize(2);
        display.setCursor(0, 28);
        display.println(message);

        display.display();
    }

    void showAnswer(Answer answer) {
        switch(answer) {
            case Answer::Yes:
                showMwssage("Answer", "Yes");
                break;
            case Answer::No:
                showMwssage("Answer", "No");
                break;
            case Answer::Unknown:
                showMwssage("Answer", "Unknown");
                break;
        }
    }
}