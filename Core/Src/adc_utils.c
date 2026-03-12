#include "adc_utils.h"

/*
 * This value is specific to the STM32F446RE since our ADC 
 * spits out 12-bit values
 */
#define ADC_MAX_COUNT 4095U

static float adc_to_normalized(uint32_t raw_val) {
    float f_val = (float)raw_val / (float)ADC_MAX_COUNT;
    return f_val;
}

void adc_buf_to_float(uint32_t *raw_buf, float *float_buf, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        float_buf[i] = adc_to_normalized(raw_buf[i]);
    }
}