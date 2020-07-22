/**
 * CAS XFR (data transfer) Subsystem
 */

#include "cas_xfr.h"

/**
 * Initialize an src object.
 */
void cas_xfr_src_init(struct cas_xfr_src * self, char * name, char * type, void * func) {
  self->name = name;
  self->type = type;
  self->func = func;
}

/**
 * Get the name of an src.
 */
char * cas_xfr_src_name(struct cas_xfr_src * self) {
  return self->name;
}

/**
 * Get the type of an src.
 */
char * cas_xfr_src_type(struct cas_xfr_src * self) {
  return self->type;
}

/**
 * Get the func of an src.
 */
void * cas_xfr_src_func(struct cas_xfr_src * self) {
  return self->func;
}

/**
 * Initialize a dst object.
 */
void cas_xfr_dst_init(struct cas_xfr_dst * self, char * name, char * type, void * func) {
  self->name = name;
  self->type = type;
  self->func = func;
}

/**
 * Get the name of a dst.
 */
char * cas_xfr_dst_name(struct cas_xfr_dst * self) {
  return self->name;
}

/**
 * Get the type of a dst.
 */
char * cas_xfr_dst_type(struct cas_xfr_dst * self) {
  return self->type;
}

/**
 * Get the func of a dst.
 */
void * cas_xfr_dst_func(struct cas_xfr_dst * self) {
  return self->func;
}

