/**
 * CAS (cassette I/O) Subsystem
 */

#ifndef __CAS_H__
#define __CAS_H__

#include "cas_fmt.h"
#include "cas_swi.h"
#include "cas_led.h"
#include "cas_rem.h"
#include "cas_sdc.h"
#include "cas_sio.h"
#include "cas_cli.h"

#define CAS_SWI_PIN      10
#define CAS_SWI_NUM      8

#define CAS_LED_PIN      20
#define CAS_LED_NUM      4

#define CAS_REM_PIN      32
#define CAS_REM_NUM      1

#define CAS_CLI_BAUD     9600
#define CAS_CLI_GREET    "Cassette I/O"
#define CAS_CLI_PROMPT   ">"

struct cas {
  struct cas_swi swi;
  struct cas_led led;
  struct cas_rem rem;
  struct cas_sdc sdc;
  struct cas_sio sio;
  struct cas_cli cli;
};

#endif
