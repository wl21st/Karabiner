#include <sys/types.h>
#include <sys/sysctl.h>

#include "config.hpp"
#include "version.hpp"

namespace org_pqrs_KeyRemap4MacBook {
  Config config;
  int config_changed = 0;

  int sysctlFunc SYSCTL_HANDLER_ARGS
  {
    int error = sysctl_handle_int(oidp, oidp->oid_arg1, oidp->oid_arg2,  req);
    if (! error && req->newptr) {
      config_changed = 1;
    }
    return error;
  }

  // ----------------------------------------------------------------------
  // SYSCTL staff
  // http://developer.apple.com/documentation/Darwin/Conceptual/KernelProgramming/boundaries/chapter_14_section_7.html#//apple_ref/doc/uid/TP30000905-CH217-TPXREF116
  SYSCTL_DECL(_keyremap4macbook);
  SYSCTL_NODE(, OID_AUTO, keyremap4macbook, CTLFLAG_RW, 0, "KeyRemap4MacBook");

  SYSCTL_DECL(_keyremap4macbook_remap);
  SYSCTL_NODE(_keyremap4macbook, OID_AUTO, remap, CTLFLAG_RW, 0, "remap");

  SYSCTL_DECL(_keyremap4macbook_option);
  SYSCTL_NODE(_keyremap4macbook, OID_AUTO, option, CTLFLAG_RW, 0, "option");

  SYSCTL_DECL(_keyremap4macbook_repeat);
  SYSCTL_NODE(_keyremap4macbook, OID_AUTO, repeat, CTLFLAG_RW, 0, "repeat");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_repeat, OID_AUTO, initial_wait, CTLTYPE_INT|CTLFLAG_RW,
              &(config.repeat_initial_wait), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_repeat, OID_AUTO, wait, CTLTYPE_INT|CTLFLAG_RW,
              &(config.repeat_wait), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, backquote2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_backquote2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, backquote2escape, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_backquote2escape), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, commandL2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_commandL2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, commandL2optionL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_commandL2optionL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, commandL2backquote, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_commandL2backquote), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, controlL2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_controlL2commandL), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, enter2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_enter2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, enter2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_enter2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, enter2fn, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_enter2fn), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, enter2optionL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_enter2optionL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, enter2semicolon, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_enter2semicolon), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, enter2space, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_enter2space), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, escape2backquote, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_escape2backquote), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, escape2rightclick, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_escape2rightclick), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, fn2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_fn2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, fn2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_fn2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, fn2optionL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_fn2optionL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, fn2shiftL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_fn2shiftL), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionL2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionL2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionL2shiftL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionL2shiftL), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionR2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionR2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionR2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionR2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionR2fn, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionR2fn), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionR2enter, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionR2enter), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionR2semicolon, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionR2semicolon), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, optionR2space, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_optionR2space), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, return2optionL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_return2optionL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, return2semicolon, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_return2semicolon), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, semicolon2return, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_semicolon2return), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, shiftL2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_shiftL2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, shiftL2space, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_shiftL2space), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, shiftR2fn, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_shiftR2fn), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, shiftR2escape, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_shiftR2escape), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, shiftR2space, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_shiftR2space), 0, &sysctlFunc, "I", "");

  // ----------------------------------------

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, space2shift, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_space2shift), 0, &sysctlFunc, "I", "");



  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, spaces_special, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_spaces_special),
              0, &sysctlFunc, "I",
              "Remap Cmd+A..Cmd+L as 'Cmd+Control+Shift+Option+1 .. Cmd+Control+Shift+Option+9'");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, deleteshift2tilde, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_deleteshift2tilde),
              0, &sysctlFunc, "I",
              "Remap Shift+Delete as '~'");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, qwerty2colemak, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_qwerty2colemak),
              0, &sysctlFunc, "I",
              "Turn QWERTY layout to Colemak layout");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, drop_funcshift, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_drop_funcshift),
              0, &sysctlFunc, "I",
              "Disable 'Shift + F1..F12'");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, tab2expose, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_tab2expose),
              0, &sysctlFunc, "I",
              "Use 'Tab' as F9");

  // ----------------------------------------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, keypad2spaces, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_keypad2spaces),
              0, &sysctlFunc, "I",
              "Use 'KeyPad' for Spaces");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, keypad2spaces_modifier_command, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_keypad2spaces_modifier_command),
              0, &sysctlFunc, "I",
              "Use 'KeyPad' for Spaces");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, keypad2spaces_modifier_control, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_keypad2spaces_modifier_control),
              0, &sysctlFunc, "I",
              "Use 'KeyPad' for Spaces");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, keypad2spaces_modifier_option, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_keypad2spaces_modifier_option),
              0, &sysctlFunc, "I",
              "Use 'KeyPad' for Spaces");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, keypad2spaces_modifier_shift, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_keypad2spaces_modifier_shift),
              0, &sysctlFunc, "I",
              "Use 'KeyPad' for Spaces");

  // ----------------------------------------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, hhkmode, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_hhkmode),
              0, &sysctlFunc, "I",
              "Use 'FH +[/;'' as 'up/down/left/right'");

  // ----------------------------------------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, emacsmode, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_emacsmode),
              0, &sysctlFunc, "I",
              "Emacs keybind");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlD, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlD),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + D' as 'forward delete'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlH, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlH),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + H' as 'delete'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlI, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlI),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + I' as 'tab'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlM, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlM),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + M' as 'return'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlPNBF, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlPNBF),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + P, N, B, F' as 'up, down, left, right'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlV, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlV),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + V' as 'PageDown', 'Option + V' as 'PageUp'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_controlLeftbracket, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_controlLeftbracket),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + [' as 'Escape'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_optionBF, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_optionBF),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Option + B, F' as 'Option + left, right'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_optionD, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_optionD),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Option + D' as 'Option + FORWARD_DELETE'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_ex_controlQ, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_ex_controlQ),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + Q' as 'PageUp'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_ex_controlW, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_ex_controlW),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + W' as 'Option + DELETE'");

  SYSCTL_PROC(_keyremap4macbook_option, OID_AUTO, emacsmode_ex_control12, CTLTYPE_INT|CTLFLAG_RW,
              &(config.option_emacsmode_ex_control12),
              0, &sysctlFunc, "I",
              "Emacs keybind 'Control + 1' as 'HOME', 'Control + 2' as 'END'");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_eisuu2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_eisuu2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_eisuu2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_eisuu2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_eisuu2optionL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_eisuu2optionL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_eisuu2shiftL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_eisuu2shiftL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_eisuu2tab, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_eisuu2tab), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_kana2commandL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_kana2commandL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_kana2controlL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_kana2controlL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_kana2optionL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_kana2optionL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_kana2shiftL, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_kana2shiftL), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_kana2return, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_kana2return), 0, &sysctlFunc, "I", "");

  // ----------------------------------------
  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_kanashift2eisuu, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_kanashift2eisuu),
              0, &sysctlFunc, "I",
              "Remap 'Shift + JIS KANA' as 'JIS EISUU'");

  SYSCTL_PROC(_keyremap4macbook_remap, OID_AUTO, jis_unify_kana_eisuu, CTLTYPE_INT|CTLFLAG_RW,
              &(config.remap_jis_unify_kana_eisuu),
              0, &sysctlFunc, "I",
              "Use 'JIS KANA Key' as 'KANA / EISUU'");

  SYSCTL_INT(_keyremap4macbook, OID_AUTO, debug, CTLTYPE_INT|CTLFLAG_RW,
             &(config.debug),
             0,
             "Output Debug Messages");

  SYSCTL_INT(_keyremap4macbook, OID_AUTO, changed, CTLTYPE_INT|CTLFLAG_RW,
             &config_changed,
             0,
             "Setting Changed Flag");

  SYSCTL_STRING(_keyremap4macbook, OID_AUTO, version, CTLFLAG_RD,
                config_version,
                0,
                "Output Version");

  // ----------------------------------------------------------------------
  void
  sysctl_register(void)
  {
    sysctl_register_oid(&sysctl__keyremap4macbook);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap);
    sysctl_register_oid(&sysctl__keyremap4macbook_option);
    sysctl_register_oid(&sysctl__keyremap4macbook_repeat);

    sysctl_register_oid(&sysctl__keyremap4macbook_repeat_initial_wait);
    sysctl_register_oid(&sysctl__keyremap4macbook_repeat_wait);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_backquote2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_backquote2escape);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_commandL2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_commandL2optionL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_commandL2backquote);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_controlL2commandL);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_enter2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_enter2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_enter2fn);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_enter2optionL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_enter2semicolon);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_enter2space);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_escape2backquote);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_escape2rightclick);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_fn2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_fn2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_fn2optionL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_fn2shiftL);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionL2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionL2shiftL);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionR2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionR2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionR2fn);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionR2enter);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionR2semicolon);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_optionR2space);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_return2optionL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_return2semicolon);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_semicolon2return);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_shiftL2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_shiftL2space);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_shiftR2fn);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_shiftR2escape);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_shiftR2space);



    sysctl_register_oid(&sysctl__keyremap4macbook_remap_space2shift);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_spaces_special);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_deleteshift2tilde);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_qwerty2colemak);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_drop_funcshift);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_tab2expose);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_keypad2spaces);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_command);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_control);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_option);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_shift);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_hhkmode);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_emacsmode);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlD);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlH);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlI);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlM);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlPNBF);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlV);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_controlLeftbracket);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_optionBF);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_optionD);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_ex_controlQ);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_ex_controlW);
    sysctl_register_oid(&sysctl__keyremap4macbook_option_emacsmode_ex_control12);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2optionL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2shiftL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2tab);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_kana2commandL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_kana2controlL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_kana2optionL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_kana2shiftL);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_kana2return);

    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_kanashift2eisuu);
    sysctl_register_oid(&sysctl__keyremap4macbook_remap_jis_unify_kana_eisuu);
    sysctl_register_oid(&sysctl__keyremap4macbook_debug);
    sysctl_register_oid(&sysctl__keyremap4macbook_changed);
    sysctl_register_oid(&sysctl__keyremap4macbook_version);
  }

  void
  sysctl_unregister(void)
  {
    sysctl_unregister_oid(&sysctl__keyremap4macbook);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_repeat);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_repeat_initial_wait);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_repeat_wait);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_backquote2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_backquote2escape);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_commandL2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_commandL2optionL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_commandL2backquote);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_controlL2commandL);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_enter2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_enter2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_enter2fn);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_enter2optionL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_enter2semicolon);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_enter2space);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_escape2backquote);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_escape2rightclick);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_fn2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_fn2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_fn2optionL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_fn2shiftL);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionL2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionL2shiftL);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionR2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionR2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionR2fn);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionR2enter);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionR2semicolon);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_optionR2space);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_return2optionL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_return2semicolon);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_semicolon2return);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_shiftL2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_shiftL2space);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_shiftR2fn);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_shiftR2escape);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_shiftR2space);


    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_space2shift);


    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_spaces_special);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_deleteshift2tilde);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_qwerty2colemak);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_drop_funcshift);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_tab2expose);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_keypad2spaces);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_command);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_control);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_option);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_keypad2spaces_modifier_shift);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_hhkmode);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_emacsmode);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlD);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlH);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlI);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlM);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlPNBF);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlV);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_controlLeftbracket);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_optionBF);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_optionD);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_ex_controlQ);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_ex_controlW);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_option_emacsmode_ex_control12);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2optionL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2shiftL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_eisuu2tab);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_kana2commandL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_kana2controlL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_kana2optionL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_kana2shiftL);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_kana2return);

    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_kanashift2eisuu);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_remap_jis_unify_kana_eisuu);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_debug);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_changed);
    sysctl_unregister_oid(&sysctl__keyremap4macbook_version);
  }
}
