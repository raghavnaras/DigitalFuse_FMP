#include "signal_analysis.h"
#include <math.h>

#define MAX_SAMPLES 1000

/*
 * Internal float array we are storing to store our baseline 
 * results for when there is no change in the signal going out
 * versus in
*/
static float baseline[MAX_SAMPLES];
static int baseline_samples = 0;

void signal_set_baseline(float *reflected, int num_samples) {
    baseline_samples = num_samples;
    for (int i = 0; i < num_samples; i++) {
        baseline[i] = reflected[i];
    }
}

float signal_compute_rmse(float *reflected, int num_samples) {
    float sqe = 0.0f;
    float rmse = 0.0f;
    for (int i = 0; i < num_samples; i++) {
        float diff = baseline[i] - reflected[i]; 

        // Squaring the diff btwn baseline and reflected 
        float square = diff * diff;

        sqe += square;
    }
    rmse = sqrtf(sqe / baseline_samples);
    return rmse;
}
