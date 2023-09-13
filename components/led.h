#ifndef LED_H
#define LED_H

#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "freertos/queue.h"

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (2) // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
#define LEDC_FREQUENCY          (5000) // Frequency in Hertz. Set frequency at 5 kHz
#define UPDATE_PERIOD            (100)

void ledc_init(void);
void ledc_init_with_pin(int PIN,int channel);

void fade(void *pvParameter);

void readFromQueue(void* queueToRead);

typedef struct {
    QueueHandle_t *channelQueue;
    QueueHandle_t *brightnessQueue;
} Queues;

#endif