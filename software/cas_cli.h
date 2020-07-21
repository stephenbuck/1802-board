/**
 * CAS CLI Subsystem
 */

#ifndef __CAS_CLI_H__
#define __CAS_CLI_H__

#define CAS_CLI_BUFF       128
#define CAS_CLI_TERM       '\n'

struct cas_cli_cmd {
  char * name;
  void (*func) (struct cas_cli * cli, struct cas_cli_cmd * cmd, int argc, char * * argv);
  char * help;
};

struct cas_cli {
  int    baud;
  char * greeting;
  char * prompt;
  char   buff[CAS_CLI_BUFF + 1];
  int    next;
  struct cas_cli_cmd * cmds;
};

void cas_cli_init    (struct cas_cli * self, int baud, char * greeting, char * prompt, struct cas_cli_cmd * cmds);
void cas_cli_loop    (struct cas_cli * self);
void cas_cli_exec    (struct cas_cli * self, char * buff);
void cas_cli_print   (struct cas_cli * self, char * msg);
void cas_cli_println (struct cas_cli * self, char * msg);
void cas_cli_help    (struct cas_cli * self);

#endif
