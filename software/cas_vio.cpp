/**
 * CAS VIO (virtual I/O) Subsystem
 */

#include "cas_vio.h"

/**
 * Initialize the VIO subsystem.
 */
void cas_vio_init(struct cas_vio * self, int port) {
  self->port = port;
  self->inpn = 0;
  self->outn = 0;
}

/**
 * Put raw byte to output queue.
 */
void cas_vio_putraw(struct cas_vio * self, byte raw) {
}

/**
 * Check if any data in input queue.
 */
bool cas_vio_anyraw(struct cas_vio * self) {
  return false;
}

/**
 * Get raw byte from input queue.
 */
byte cas_vio_getraw (struct cas_vio * self) {
  return 0;
}

