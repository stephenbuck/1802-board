/**
 * CAS SWI (switch) Subsystem
 */
 
#include "cas_swi.h"

#include <Arduino.h>

/**
 * Initialize the SWI subsystem.
 */
void cas_swi_init(struct cas_swi * self, int pin, int num) {

  // Initialize the SWI object
  self->pin = pin;
  self->num = num;
  
  // Initialize the SWI(s)
  for (int swi = 0; swi < self->num; ++swi) {
    pinMode(self->pin + swi, INPUT_PULLUP);
  }
}

/**
 * Get the status of a switch.
 */
bool cas_swi_get(struct cas_swi * self, int swi) {
  return digitalRead(self->pin + swi);
}
