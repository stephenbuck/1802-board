/**
 * CAS CLI Subsystem
 */

#include "cas_cli.h"

#include <HardwareSerial.h>

/**
 * Initialize the CLI subsystem.
 */
void cas_cli_init(struct cas_cli * self, int baud, char * greeting, char * prompt, struct cas_cli_cmd * cmds) {

  self->baud     = baud;
  self->greeting = greeting;
  self->prompt   = prompt;
  self->buff[0]  = '\0';
  self->next     = 0;
  self->cmds     = cmds;

  // Initialize the serial port
  Serial.begin(baud);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only.
  }

  // Print the greeting andBUFFLEN prompt
  cas_cli_println(self, self->greeting);
  cas_cli_print(self, self->prompt);
}

/**
 * Loop callback to service CLI.
 */
void cas_cli_loop(struct cas_cli * self) {

  // If there's a character available...
  if (Serial.available() > 0) {

    // Read the character
    char ch = Serial.read();

    // If it's the line terminator...
    if (ch == CAS_CLI_TERM) {

      // Execute the buffer
      cas_cli_exec(self, self->buff);

      // Reset the buffer
      self->buff[0] = '\0';
      self->next = 0;

      // Print the prompt
      cas_cli_println(self, self->prompt);
    }

    // If it's a printable character...
    else if (isprint(ch) && (self->next < CAS_CLI_BUFF)) {

      // Append to the buffer
      self->buff[self->next++] = ch;
      self->buff[self->next] = '\0';
    }
  }
}

/**
 * Execute CLI buffer.
 */
void cas_cli_exec(struct cas_cli * self, char * buff) {
  cas_cli_println(self, buff);
}

/**
 * Print message to CLI output.
 */
void cas_cli_print(struct cas_cli * self, char * msg) {
  Serial.print(msg);
  Serial.flush();
}

/**
 * Print message and newline to CLI output.
 */
void cas_cli_println(struct cas_cli * self, char * msg) {
  Serial.println(msg);
  Serial.flush();
}

/**
 * Print help to CLI output.
 */
void cas_cli_help(struct cas_cli * self) {
  for (cas_cli_cmd * cmd = self->cmds; cmd->name != NULL; ++cmd) {
    cas_cli_print(self, cmd->name);
    cas_cli_print(self, ": ");
    cas_cli_println(self, cmd->help);
  }
}
