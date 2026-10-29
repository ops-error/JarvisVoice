#include <Arduino.h>
// #include "driver/i2s.h"
// #include <math.h>
#include "display_manager.h"

// constexpr int I2S_SCK = 14;
// constexpr int I2S_WS = 15;
// constexpr int I2S_SD = 32;

// constexpr i2s_port_t I2S_PORT = I2S_NUM_0;
// constexpr int SAMPLE_RATE = 16000;
// constexpr int BUFFER_SIZE = 256;

// int32_t samples[BUFFER_SIZE];
// uint32_t lastPrint = 0;

void setup() {
  // Serial.begin(115200);
  // delay(1000);

  // Serial.println();
  // Serial.println("INMP441 micro test");

  // i2s_config_t i2s_config = {};
  // i2s_config.mode = static_cast<i2s_mode_t>(
  //   I2S_MODE_MASTER | I2S_MODE_RX
  // );

  // i2s_config.sample_rate = SAMPLE_RATE;
  // i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT;
  // i2s_config.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT;
  // i2s_config.communication_format = I2S_COMM_FORMAT_I2S;
  // i2s_config.intr_alloc_flags = ESP_INTR_FLAG_LEVEL1;
  // i2s_config.dma_buf_count = 4;
  // i2s_config.dma_buf_len = BUFFER_SIZE;
  // i2s_config.use_apll = false;
  // i2s_config.tx_desc_auto_clear = false;
  // i2s_config.fixed_mclk = 0;

  // i2s_pin_config_t pin_config = {};
  // pin_config.bck_io_num = I2S_SCK;
  // pin_config.ws_io_num = I2S_WS;
  // pin_config.data_out_num = I2S_PIN_NO_CHANGE;
  // pin_config.data_in_num = I2S_SD;

  // esp_err_t result = i2s_driver_install(
  //   I2S_PORT, &i2s_config, 0, nullptr
  // );

  // if (result != ESP_OK) {
  //   Serial.printf("I2S driver error: %d\n", result);
  //   while (true) {
  //     delay(1000);
  //   }
  // }

  // result = i2s_set_pin(I2S_PORT, &pin_config);

  // if (result != ESP_OK) {
  //   Serial.printf("I2S pin error: %d\n", result);
  //   while (true) {
  //     delay(1000);
  //   }
  // }

  // i2s_zero_dma_buffer(I2S_PORT);
  // Serial.println("I2S ready. Make some noise!!");

  // -----------------------------------------------

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
  // size_t bytes_read = 0;

  //   esp_err_t result = i2s_read(
  //       I2S_PORT,
  //       samples,
  //       sizeof(samples),
  //       &bytes_read,
  //       portMAX_DELAY
  //   );

  //   if (result != ESP_OK || bytes_read == 0) {
  //       Serial.println("Audio read error");
  //       delay(100);
  //       return;
  //   }

  //   size_t count = bytes_read / sizeof(int32_t);

  //   int32_t peak = 0;
  //   double sum_squares = 0;
  //   size_t audio_count = 0;

  //   // При L/R = GND используем левый канал:
  //   // индексы 0, 2, 4, 6...
  //   for (size_t i = 0; i < count; i += 2) {
  //       int32_t sample = samples[i] >> 8;

  //       int32_t magnitude = (sample < 0) ? -sample : sample;

  //       if (magnitude > peak) {
  //           peak = magnitude;
  //       }

  //       sum_squares +=
  //           static_cast<double>(sample) * sample;

  //       audio_count++;
  //   }

  //   double rms = sqrt(sum_squares / audio_count);

  //   static uint32_t last_print = 0;

  //   if (millis() - last_print >= 500) {
  //       last_print = millis();

  //       Serial.printf(
  //           "Peak: %ld | RMS: %.1f\n",
  //           (long)peak,
  //           rms
  //       );
  //   }
}
