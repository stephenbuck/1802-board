/**
 * CAS (cassette I/O) Subsystem
 */

#ifndef __CAS_H__
#define __CAS_H__

#include "cas_fmt.h"
#include "cas_swi.h"
#include "cas_led.h"
#include "cas_rem.h"
#include "cas_vio.h"
#include "cas_sdc.h"
#include "cas_sio.h"
#include "cas_cli.h"
#include "cas_xfr.h"

#define CAS_SWI_PIN      10
#define CAS_SWI_NUM      8

#define CAS_LED_PIN      20
#define CAS_LED_NUM      4

#define CAS_REM_PIN      32
#define CAS_REM_NUM      1

#define CAS_VIO_PORT     6
#define CAS_VIO_NUM      2

#define CAS_CLI_BAUD     9600
#define CAS_CLI_GREET    "Cassette I/O"
#define CAS_CLI_PROMPT   ">"

struct cas {

  struct cas_swi swi;
  struct cas_led led;
  struct cas_rem rem;
  struct cas_vio vio;
  struct cas_sdc sdc;
  struct cas_sio sio;
  struct cas_cli cli;

  struct cas_xfr_src src_vio;
  struct cas_xfr_src src_aud;
  struct cas_xfr_src src_wav;
  struct cas_xfr_src src_dat;

  struct cas_xfr_dst dst_vio;
  struct cas_xfr_dst dst_aud;
  struct cas_xfr_dst dst_wav;
  struct cas_xfr_dst dst_dat;
};

#endif
