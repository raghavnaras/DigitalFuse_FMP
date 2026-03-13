#ifndef FAULT_CLASSIFIER_H
#define FAULT_CLASSIFIER_H

/**
 * fault_classifier.h
 * 
 * This module handles the logic of categorizing the fault
 * once we have determined our RMSE (Root Mean Squared Error).
 * 
 */

#include <stdint.h>

typedef enum {
    STATE_HEALTHY,
    STATE_WARNING,
    STATE_FAULT_SOFT,
    STATE_FAULT_HARD
} FaultState_t;

FaultState_t classifier_evaluate(float rmse);

#endif // FAULT_CLASSIFIER_H