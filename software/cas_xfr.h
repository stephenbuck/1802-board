/**
 * CAS XFR (data transfer) Subsystem
 */

#ifndef __CAS_XFR_H__
#define __CAS_XFR_H__

struct cas_xfr_src {
  char * name;
  char * type;
  void * func;
};

struct cas_xfr_dst {
  char * name;
  char * type;
  void * func;
};

void   cas_xfr_src_init (struct cas_xfr_src * self, char * name, char * type, void * func);
char * cas_xfr_src_name (struct cas_xfr_src * self);
char * cas_xfr_src_type (struct cas_xfr_src * self);
void * cas_xfr_src_func (struct cas_xfr_src * self);

void   cas_xfr_dst_init (struct cas_xfr_dst * self, char * name, char * type, void * func);
char * cas_xfr_dst_name (struct cas_xfr_dst * self);
char * cas_xfr_dst_type (struct cas_xfr_dst * self);
char * cas_xfr_dst_func (struct cas_xfr_dst * self);

#endif

