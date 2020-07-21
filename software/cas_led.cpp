/**
 * CAS LED Subsystem
 */

#include "cas_led.h"

#include <Arduino.h>

/**
 * Initialize the LED subsystem.
 */
void cas_led_init(struct cas_led * self, int pin, int num) {

  // Initialize the LED object
  self->pin = pin;
  self->num = num;

  // Initialize the LED(s)
  for (int led = 0; led < self->num; ++led) {
    pinMode(self->pin + led, OUTPUT);
    digitalWrite(self->pin + led, LOW);
  }
}

/**
 * Set the status of an LED.
 */
void cas_led_set(struct cas_led * self, int led, bool on) {
  digitalWrite(self->pin + led, on ? HIGH : LOW);
}
