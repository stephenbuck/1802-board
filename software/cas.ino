/**
 * CAS (cassette I/O) Subsystem
 */
 
#include "cas.h"

//********************************************************************************
// Private
//********************************************************************************

/**
 * The CAS formats.
 */

static struct cas_fmt fmts[] = {
  { "Kansas City" },
  { "MITS Altair" },
  {}
};

/**
 * Print CLI help command.
 */
static void cas_cmd_help(struct cas_cli * cli, struct cas_cli_cmd * cmd, int argc, char * * argv) {
  cas_cli_help(cli);
}

/**
 * Print CAS formats command.
 */
static void cas_cmd_fmts(struct cas_cli * cli, struct cas_cli_cmd * cmd, int argc, char * * argv) {
  for (struct cas_fmt * fmt = fmts; fmt->name != NULL; ++fmt) {
    cas_cli_println(cli, fmt->name);
  }
}

/**
 * The CLI commands.
 */
static struct cas_cli_cmd cmds[] = {
  { "?",    cas_cmd_help, "List commands" },
  { "help", cas_cmd_help, "List commands" },
  { "fmts", cas_cmd_fmts, "List formats"  },
  {}
};

/**
 * The CAS object.
 */
static struct cas cas;

//********************************************************************************
// Public
//********************************************************************************

/**
 * Initialize the CAS subsystem.
 */
void setup() {
  cas_swi_init(&cas.swi, CAS_SWI_PIN, CAS_SWI_NUM);
  cas_led_init(&cas.led, CAS_LED_PIN, CAS_LED_NUM);
  cas_rem_init(&cas.rem, CAS_REM_PIN, CAS_REM_NUM);
  cas_sdc_init(&cas.sdc);
  cas_sio_init(&cas.sio);
  cas_cli_init(&cas.cli, CAS_CLI_BAUD, CAS_CLI_GREET, CAS_CLI_PROMPT, cmds);
}

/**
 * Loop callback to service CAS.
 */
void loop() {
  cas_cli_loop(&cas.cli);
}
