#ifndef SIGNAL_ANALYSIS_H
#define SIGNAL_ANALYSIS_H

/**
 * signal_analysis.h
 * 
 * Signal Processing library 
 * Stores a baseline capture and computes RMSE against
 * subsequent captures to detect anomalies in the reflected signal
 * 
 */

#include <stdint.h>

/**
 * @brief Stores a captured signal as the baseline reference to compare against 
 * @param reflected  Input buffer containing the captured signal
 * @param num_samples Number of samples in the input buffer
 */
void signal_set_baseline(float *reflected, int num_samples);

/**
 * @brief Compute rmse of the reflected pulse
 * @param reflected  Input buffer containing the reflected pulse
 * @param num_samples Number of samples in the input buffer
 */
float signal_compute_rmse(float *reflected, int num_samples);

#endif /* SIGNAL_ANALYSIS_H */