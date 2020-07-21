/**
 * CAS LED Subsystem
 */

#ifndef __CAS_LED_H__
#define __CAS_LED_H__

#include <stdbool.h>

struct cas_led {
  int pin;
  int num;
};

void cas_led_init (struct cas_led * self, int pin, int num);
void cas_led_set  (struct cas_led * self, int led, bool on);

#endif
