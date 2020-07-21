/**
 * CAS REM Subsystem
 */

#include "cas_rem.h"

#include <Arduino.h>

/**
 * Initialize the REM subsystem.
 */
void cas_rem_init(struct cas_rem * self, int pin, int num) {

  // Initialize the REM object
  self->pin = pin;
  self->num = num;
  
  // Initialize the REM(s)
  for (int rem = 0; rem < self->num; ++rem) {
    pinMode(self->pin + rem, OUTPUT);
    digitalWrite(self->pin + rem, LOW);
  }
}

/**
 * Set the status of a REM.
 */
void cas_rem_set(struct cas_rem * self, int rem, bool on) {
  digitalWrite(self->pin + rem, on ? HIGH : LOW);
}
