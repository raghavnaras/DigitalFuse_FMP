#ifndef ADC_UTILS_H
#define ADC_UTILS_H

/**
 * adc_utils.h
 * 
 * This module serves as a utlity for handling the computation 
 * logic needed to convert the adc buffer into normalized float
 * values before passing over to the signal analyzer. 
 * 
 * The normalization is needed so that the signal analyzer stays
 * hardware agnostic. If in the future we switch to a device that 
 * supports a 16-bit ADC, if we didn't normalize our data, our 
 * thresholds would be all out of wack. 
 * 
 */

#include <stdint.h>

/**
 * @brief Convert entire ADC buffer to normalized float array
 * @param raw_buf  Input buffer of raw 12-bit ADC counts
 * @param float_buf Output buffer of normalized floats (0.0 - 1.0)
 * @param num_samples Number of samples to convert
 */
void adc_buf_to_float(uint32_t *raw_buf, float *float_buf, int num_samples);

#endif /* ADC_UTILS_H */