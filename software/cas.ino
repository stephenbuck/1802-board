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
 * RAW2INP (dst=INP)
 * RAW2BIN (dst=BIN)
 * RAW2WAV (dst=WAV)
 * RAW2STX (dst=STX)
 *
 * DEC2WAV (src=DEC, dst=WAV)
 * WAV2ENC (src=WAV, dst=ENC)
 *
 * WAV2RAW (src=WAV, dst=RAW)
 * STX2RAW (src=STX, dst=RAW)
 * BIN2RAW (src=BIN, dst=RAW)
 * OUT2RAW (src=OUT, dst=RAW)
 */

/*

void raw2inp(byte raw) {
  append to input queue
}

void raw2bin(byte raw) {
  append to bin file
}

void raw2wav(byte raw) {
  encode to wav buffer
}

void raw2stx(byte raw) {
  write to stx
}

void dec2wav() {
  decode to wav buffer
}

void wav2enc() {
  wav buffer to encoder
}

byte wav2raw() {
  decode from wav buffer
}

byte srx2raw() {
  read from stx
}

byte bin2raw() {
  read from bin file
}

byte out2raw() {
  append raw to queue
}

*/

/**
 * INP (src=RAW)
 * ---
 * INP <= DEC
 * [DEC2WAV]->[WAV2RAW]->[RAW2INP]
 *
 * INP <= DSK
 * [DSK2WAV]->[WAV2RAW]->[RAW2INP]
 *
 * INP <= BIN
 * [BIN2RAW]->[RAW2INP]
 *
 * INP <= OUT
 * [OUT2RAW]->[RAW2INP]
 *
 * INP <= SRX
 * [SRX2RAW]->[RAW2INP]
 *
 *
 * DSK (src=WAV)
 * ---
 * DSK <= DEC
 * [DEC2WAV]->[WAV2DSK]
 *
 * DSK <= OUT
 * [OUT2RAW]->[RAW2WAV]->[WAV2DSK]
 *
 * DSK <= BIN
 * [BIN2RAW]->[RAW2WAV]->[WAV2DSK]
 *
 * DSK <= DSK
 * [DSK2WAV]->[WAV2DSK]
 *
 * DSK <= SRX
 * [SRX2RAW]->[RAW2WAV]->[WAV2DSK]
 *
 *
 * BIN (src=RAW)
 * --- 
 * BIN <= DSK
 * [DSK2WAV]->[WAV2RAW]->[RAW2BIN]
 *
 * BIN <= OUT
 * [OUT2RAW]->[RAW2BIN]
 *
 * BIN <= DEC
 * [DEC2WAV]->[WAV2RAW]->[RAW2BIN]
 *
 * BIN <= BIN
 * [BIN2RAW]->[RAW2BIN]
 *
 * BIN <= SRX
 * [SRX2RAW]->[RAW2BIN]
 *
 *
 * ENC (src=WAV)
 * ---
 * ENC <= OUT
 * [OUT2RAW]->[RAW2WAV]->[WAV2ENC]
 *
 * ENC <= DSK
 * [DSK2WAV]->[WAV2ENC]
 *
 * ENC <= BIN
 * [BIN2RAW]->[RAW2WAV]->[WAV2ENC]
 *
 * ENC <= DEC
 * [DEC2RAW]->[RAW2WAV]->[WAV2ENC]
 *
 * ENC <= SRX
 * [SRX2RAW]->[RAW2WAV]->[WAV2ENC]
 *
 * 
 * STX (src=RAW)
 * ---
 * STX <= OUT
 * [OUT2RAW]->[RAW2STX]
 *
 * STX <= DSK
 * [DSK2WAV]->[WAV2RAW]->[RAW2STX]
 *
 * STX <= BIN
 * [BIN2RAW]->[RAW2STX]
 *
 * STX <= DEC
 * [DEC2WAV]->[WAV2RAW]->[RAW2STX]
 *
 * STX <= SRX
 * [SRX2RAW]->[RAW2STX]
 */

/**
 * SRC VIO (Inp=VIO, Out=RAW)
 */
static void src_vio_func(struct cas_xfr_src * self) {
}

/**
 * SRC AUD (Inp=INP, Out=WAV)
 */
static void src_aud_func(struct cas_xfr_src * self) {
}

/**
 * SRC WAV (Inp=WAV, Out=DAT)
 */
static void src_wav_func(struct cas_xfr_src * self) {
}

/**
 * SRC DAT (Inp=DAT, Out=RAW)
 */
static void src_dat_func(struct cas_xfr_src * self) {
}

/**
 * DST VIO (Inp=RAW, Out=VIO)
 */
static void dst_vio_func(struct cas_xfr_dst * self) {
}

/**
 * DST AUD (Inp=WAV, Out=OUT)
 */
static void dst_aud_func(struct cas_xfr_dst * self) {
}

/**
 * DST WAV (Inp=DAT, Out=WAV)
 */
static void dst_wav_func(struct cas_xfr_dst * self) {
}

/**
 * DST DAT (Inp=RAW, Out=DAT)
 */
static void dst_dat_func(struct cas_xfr_dst * self) {
}

/**
 * Initialize the CAS subsystem.
 */
void setup() {

  cas_swi_init(&cas.swi, CAS_SWI_PIN, CAS_SWI_NUM);
  cas_led_init(&cas.led, CAS_LED_PIN, CAS_LED_NUM);
  cas_rem_init(&cas.rem, CAS_REM_PIN, CAS_REM_NUM);
  cas_vio_init(&cas.vio, CAS_VIO_PORT, CAS_VIO_NUM);
  cas_sdc_init(&cas.sdc);
  cas_sio_init(&cas.sio);
  cas_cli_init(&cas.cli, CAS_CLI_BAUD, CAS_CLI_GREET, CAS_CLI_PROMPT, cmds);

  // Initialize the src objects
  cas_xfr_src_init(&cas.src_vio, "SRC_VIO", src_vio_func);
  cas_xfr_src_init(&cas.src_aud, "SRC_AUD", src_aud_func);
  cas_xfr_src_init(&cas_src_wav, "SRC_WAV", src_wav_func);
  cas_xfr_src_init(&cas_src_dat, "SRC_DAT", src_dat_func);

  // Initialize the dst objects
  cas_xfr_dst_init(&cas_dst_vio, "DST_VIO", dst_vio_func);
  cas_xfr_dst_init(&cas_dst_aud, "DST_AUD", dst_aud_func);
  cas_xfr_dst_init(&cas_dst_wav, "DST_WAV", dst_wav_func);
  cas_xfr_dst_init(&cas_dst_dat, "DST_DAT", dst_dat_func);
}

/**
 * Loop callback to service CAS.
 */
void loop() {
  cas_cli_loop(&cas.cli);
}

