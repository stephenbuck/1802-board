/**
 * CAS SWI (switch) Subsystem
 */

#ifndef __CAS_SWI_H__
#define __CAS_SWI_H__

#include <stdbool.h>

struct cas_swi {
  int pin;
  int num;
};

void cas_swi_init (struct cas_swi * self, int pin, int num);
bool cas_swi_get  (struct cas_swi * self, int swi);

#endif
