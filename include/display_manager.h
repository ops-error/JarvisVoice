#pragma once

enum class Answer{
    Yes,
    No,
    Unknown
};

namespace DisplayManager {
    bool begin();

    void showAnswer(Answer answer);

    void showMessage(
        const char* title,
        const char* message
    );
}