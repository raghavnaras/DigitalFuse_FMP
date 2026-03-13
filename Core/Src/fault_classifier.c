#include "fault_classifier.h"

/*
 * Classifies transmission line health based on RMSE of the reflected chirp signal.
 *
 * Thresholds derived from hardware measurements:
 *   Healthy baseline (jumper connected):    RMSE ≈ 0.0015
 *   Open circuit (jumper disconnected):     RMSE ≈ 0.41
 *
 * Classification:
 *   RMSE < 0.010  -> STATE_HEALTHY      (normal operation, baseline stable)
 *   RMSE < 0.100  -> STATE_WARNING      (minor deviation, early warning)
 *   RMSE < 0.500  -> STATE_FAULT_SOFT   (moderate fault detected)
 *   RMSE >= 0.500 -> STATE_FAULT_HARD   (severe fault: open/short circuit)
 */

FaultState_t classifier_evaluate(float rmse) {
    if (rmse < 0.010f) {
        return STATE_HEALTHY;
    } else if (rmse < 0.100f) {
        return STATE_WARNING;
    } else if (rmse < 0.500f) {
        return STATE_FAULT_SOFT;
    } else {
        return STATE_FAULT_HARD;
    }
}