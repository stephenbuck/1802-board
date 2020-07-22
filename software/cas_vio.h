/**
 * CAS VIO (virtual I/O) Subsystem
 */

#ifndef __CAS_VIO_H__
#define __CAS_VIO_H__

#include <stdbool.h>

#define CAS_VIO_INPQ 16
#define CAS_VIO_OUTQ 16

struct cas_vio {
  int  port;
  int  inpn;
  byte inpq[CAS_VIO_INPQ];
  int  outn;
  byte outq[CAS_VIO_OUTQ];
};

void cas_vio_init   (struct cas_vio * self, int port);
void cas_vio_putraw (struct cas_vio * self, byte raw);
bool cas_vio_anyraw (struct cas_vio * self);
byte cas_vio_getraw (struct cas_vio * self);

#endif

