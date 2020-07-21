/**
 * CAS REM Subsystem
 */

#ifndef __CAS_REM_H__
#define __CAS_REM_H__

#include <stdbool.h>

struct cas_rem {
  int pin;
  int num;
};

void cas_rem_init (struct cas_rem * self, int pin, int num);
void cas_rem_set  (struct cas_rem * self, int rem, bool on);

#endif
