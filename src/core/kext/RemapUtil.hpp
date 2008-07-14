#ifndef REMAPUTIL_HPP
#define REMAPUTIL_HPP

#include <IOKit/hidsystem/IOHIKeyboard.h>
#include "remap.hpp"
#include "keycode.hpp"

namespace org_pqrs_KeyRemap4MacBook {
  namespace RemapUtil {
    enum {
      // see IOHIPointing.cpp in darwin.
      POINTING_FIXED_SCALE = 65536, // (== << 16)
      POINTING_POINT_SCALE = 10, // (== SCROLL_WHEEL_TO_PIXEL_SCALE >> 16)
    };

    inline bool isKey(const RemapParams &params, KeyCode::KeyCode keyCode) {
      return params.ex_origKey == keyCode && *(params.key) == keyCode;
    }
    inline bool isModifierOn(unsigned int flags, ModifierFlag::ModifierFlag f) {
      return ((flags & f) == f);
    }
    inline bool isModifierOn(const RemapParams &params, ModifierFlag::ModifierFlag flag) {
      return isModifierOn(*(params.flags), flag);
    }

    KeyCode::KeyCode getModifierKeyCode(ModifierFlag::ModifierFlag flag);
    ModifierFlag::ModifierFlag getKeyCodeModifier(unsigned int keycode);
    void fnToNormal(const RemapParams &params);
    void toFN(const RemapParams &params);
    void toDelete(const RemapParams &params);

    inline bool isKeyDown(const RemapParams &params, KeyCode::KeyCode keyCode) {
      if (*(params.eventType) == KeyEvent::DOWN) {
        return isKey(params, keyCode);
      } else if (*(params.eventType) == KeyEvent::MODIFY) {
        return isModifierOn(params, getKeyCodeModifier(keyCode));
      } else {
        return false;
      }
    }

    KeyCode::KeyCode getEnterKeyCode(unsigned int keyboardType);
    inline KeyCode::KeyCode getEnterKeyCode(const RemapParams &params) { return getEnterKeyCode(*(params.keyboardType)); }
    CharCode::CharCode getEnterCharCode(KeyCode::KeyCode keyCode);
    bool isInternalKeyboard(unsigned int keyboardType);

    bool keyToKey(const RemapParams &params, KeyCode::KeyCode fromKeyCode, KeyCode::KeyCode toKeyCode);
    bool keyToKeyWithModifier(const RemapParams &params, KeyCode::KeyCode fromKeyCode, KeyCode::KeyCode toKeyCode, ModifierFlag::ModifierFlag toFlag);

    bool keyToKey_dependingShift(const RemapParams &params, KeyCode::KeyCode fromKeyCode,
                                 KeyCode::KeyCode toKeyCode_noflag1, CharCode::CharCode toCharCode_noflag1,
                                 KeyCode::KeyCode toKeyCode_noflag2, CharCode::CharCode toCharCode_noflag2,
                                 KeyCode::KeyCode toKeyCode_shiftL1, CharCode::CharCode toCharCode_shiftL1,
                                 KeyCode::KeyCode toKeyCode_shiftL2, CharCode::CharCode toCharCode_shiftL2,
                                 KeyCode::KeyCode toKeyCode_shiftR1, CharCode::CharCode toCharCode_shiftR1,
                                 KeyCode::KeyCode toKeyCode_shiftR2, CharCode::CharCode toCharCode_shiftR2);

    void keyToPointingButton(const RemapParams &params, KeyCode::KeyCode fromKeyCode, PointingButton::PointingButton toButton);

    bool keyToConsumer(const RemapParams &params, KeyCode::KeyCode fromKeyCode, ConsumerKeyCode::ConsumerKeyCode toKeyCode);
    bool consumerToKey(const RemapConsumerParams &params, ConsumerKeyCode::ConsumerKeyCode fromKeyCode, KeyCode::KeyCode toKeyCode);

    void ejectToKey(const RemapConsumerParams &params, KeyCode::KeyCode toKeyCode);

    void fireKeyWithModifiers(const RemapParams &params, unsigned int flags, unsigned int eventType, unsigned int keyCode, unsigned int charCode);
    bool keypad2spaces(const RemapParams &params);
    inline bool key2spaces(const RemapParams &params, unsigned int flags,
                           KeyCode::KeyCode key1, KeyCode::KeyCode key2, KeyCode::KeyCode key3,
                           KeyCode::KeyCode key4, KeyCode::KeyCode key5, KeyCode::KeyCode key6,
                           KeyCode::KeyCode key7, KeyCode::KeyCode key8, KeyCode::KeyCode key9,
                           KeyCode::KeyCode key10 = KeyCode::NONE,
                           KeyCode::KeyCode key11 = KeyCode::NONE,
                           KeyCode::KeyCode key12 = KeyCode::NONE,
                           KeyCode::KeyCode key13 = KeyCode::NONE,
                           KeyCode::KeyCode key14 = KeyCode::NONE,
                           KeyCode::KeyCode key15 = KeyCode::NONE,
                           KeyCode::KeyCode key16 = KeyCode::NONE) {
      KeyCode::KeyCode keyCode = KeyCode::NONE;
      CharCode::CharCode charCode = CharCode::NONE;

      // --------------------------------------------------
      if (RemapUtil::isKey(params, key1)) { keyCode = KeyCode::KEY_1; charCode = CharCode::KEY_1; }
      if (RemapUtil::isKey(params, key2)) { keyCode = KeyCode::KEY_2; charCode = CharCode::KEY_2; }
      if (RemapUtil::isKey(params, key3)) { keyCode = KeyCode::KEY_3; charCode = CharCode::KEY_3; }
      if (RemapUtil::isKey(params, key4)) { keyCode = KeyCode::KEY_4; charCode = CharCode::KEY_4; }
      if (RemapUtil::isKey(params, key5)) { keyCode = KeyCode::KEY_5; charCode = CharCode::KEY_5; }
      if (RemapUtil::isKey(params, key6)) { keyCode = KeyCode::KEY_6; charCode = CharCode::KEY_6; }
      if (RemapUtil::isKey(params, key7)) { keyCode = KeyCode::KEY_7; charCode = CharCode::KEY_7; }
      if (RemapUtil::isKey(params, key8)) { keyCode = KeyCode::KEY_8; charCode = CharCode::KEY_8; }
      if (RemapUtil::isKey(params, key9)) { keyCode = KeyCode::KEY_9; charCode = CharCode::KEY_9; }
      if (RemapUtil::isKey(params, key10)) { keyCode = KeyCode::KEY_0; charCode = CharCode::KEY_0; }

      if (keyCode != KeyCode::NONE) {
        RemapUtil::fireKeyWithModifiers(params, flags, *(params.eventType), keyCode, charCode);
        *(params.ex_dropKey) = true;
        return true;
      }

      // --------------------------------------------------
      if (RemapUtil::isKey(params, key11)) { keyCode = KeyCode::KEY_1; charCode = CharCode::KEY_1; }
      if (RemapUtil::isKey(params, key12)) { keyCode = KeyCode::KEY_2; charCode = CharCode::KEY_2; }
      if (RemapUtil::isKey(params, key13)) { keyCode = KeyCode::KEY_3; charCode = CharCode::KEY_3; }
      if (RemapUtil::isKey(params, key14)) { keyCode = KeyCode::KEY_4; charCode = CharCode::KEY_4; }
      if (RemapUtil::isKey(params, key15)) { keyCode = KeyCode::KEY_5; charCode = CharCode::KEY_5; }
      if (RemapUtil::isKey(params, key16)) { keyCode = KeyCode::KEY_6; charCode = CharCode::KEY_6; }

      if (keyCode != KeyCode::NONE) {
        RemapUtil::fireKeyWithModifiers(params, flags | ModifierFlag::OPTION_L, *(params.eventType), keyCode, charCode);
        *(params.ex_dropKey) = true;
        return true;
      }

      return false;
    }

    void jis_toggle_eisuu_kana(const RemapParams &params, KeyCode::KeyCode fromKeyCode);

    // ----------------------------------------
    void pointingRelativeToScroll(const RemapPointingParams_relative &params);
  }

  class FlagStatus {
  public:
    FlagStatus(ModifierFlag::ModifierFlag _flag) : flag(_flag), key(RemapUtil::getModifierKeyCode(_flag)) {}
    void initialize(const RemapParams &params);

    void reset(void) { count = 0; }
    void increase(void) { ++count; }
    void decrease(void) { --count; }
    void temporary_increase(void) { ++temporary_count; }
    void temporary_decrease(void) { --temporary_count; }

    bool isHeldDown(void) const { return (count + temporary_count) > 0; }
    unsigned int getFlag(void) const { return flag; }
    unsigned int makeFlag(void) const { return (isHeldDown()) ? flag : 0; }

    KeyCode::KeyCode getKeyCode(void) const { return key; }

  private:
    const ModifierFlag::ModifierFlag flag;
    const KeyCode::KeyCode key;
    int count;
    int temporary_count;
  };

  class AllFlagStatus {
  public:
    FlagStatus capslock;
    FlagStatus shiftL;
    FlagStatus shiftR;
    FlagStatus controlL;
    FlagStatus controlR;
    FlagStatus optionL;
    FlagStatus optionR;
    FlagStatus commandL;
    FlagStatus commandR;
    FlagStatus fn;

    int numHeldDownKeys;

    AllFlagStatus(void) :
      capslock(ModifierFlag::CAPSLOCK),
      shiftL(ModifierFlag::SHIFT_L),
      shiftR(ModifierFlag::SHIFT_R),
      controlL(ModifierFlag::CONTROL_L),
      controlR(ModifierFlag::CONTROL_R),
      optionL(ModifierFlag::OPTION_L),
      optionR(ModifierFlag::OPTION_R),
      commandL(ModifierFlag::COMMAND_L),
      commandR(ModifierFlag::COMMAND_R),
      fn(ModifierFlag::FN)
    {}
    void initialize(const RemapParams &params);
    unsigned int makeFlags(unsigned int keyCode);
    unsigned int makeFlags(const RemapParams &params);
    void reset(void);

    FlagStatus *getFlagStatus(ModifierFlag::ModifierFlag flag);
    FlagStatus *getFlagStatus(KeyCode::KeyCode keyCode);

    // ----------------------------------------
    bool isHeldDown_command(void) { return commandL.isHeldDown() || commandR.isHeldDown(); }
    bool isHeldDown_control(void) { return controlL.isHeldDown() || controlR.isHeldDown(); }
    bool isHeldDown_option(void) { return optionL.isHeldDown() || optionR.isHeldDown(); }
    bool isHeldDown_shift(void) { return shiftL.isHeldDown() || shiftR.isHeldDown(); }

    void temporaryDecrease_command(void) {
      if (commandL.isHeldDown()) {
        commandL.temporary_decrease();
      } else {
        commandR.temporary_decrease();
      }
    }
    void temporaryDecrease_option(void) {
      if (optionL.isHeldDown()) {
        optionL.temporary_decrease();
      } else {
        optionR.temporary_decrease();
      }
    }
    void temporaryDecrease_shift(void) {
      if (shiftL.isHeldDown()) {
        shiftL.temporary_decrease();
      } else {
        shiftR.temporary_decrease();
      }
    }

    // ----------------------------------------
    void temporary_flags_reset(void);
    void temporary_flags_restore(KeyCode::KeyCode keyCode);
  };
  extern AllFlagStatus allFlagStatus;

  // ----------------------------------------------------------------------
  class FireExtraKey {
  public:
    enum Type {
      TYPE_BEFORE,
      TYPE_AFTER,
    };
    void set(FireExtraKey::Type _type, unsigned int _eventType, unsigned int _flags, unsigned int _key, unsigned int _charCode) {
      type = _type;
      eventType = _eventType;
      flags = _flags;
      key = _key;
      charCode = _charCode;
    }
    unsigned int getType(void) const { return type; }
    unsigned int getEventType(void) const { return eventType; }
    unsigned int getFlags(void) const { return flags; }
    unsigned int getKey(void) const { return key; }
    unsigned int getCharCode(void) const { return charCode; }

  private:
    Type type;
    unsigned int eventType;
    unsigned int flags;
    unsigned int key;
    unsigned int charCode;
  };

  class ListFireExtraKey {
  public:
    enum {
      FIREEXTRAKEY_MAXNUM = 32,
    };
    void reset(void) { size = 0; }
    bool isEmpty(void) { return size == 0; }
    void add(FireExtraKey::Type type, unsigned int eventType, unsigned int flags, unsigned int key, unsigned int charCode) {
      if (size >= FIREEXTRAKEY_MAXNUM) return;
      list[size].set(type, eventType, flags, key, charCode);
      ++size;
    }
    void fire(FireExtraKey::Type type, KeyboardEventCallback callback,
              OSObject *target,
              unsigned int charSet, unsigned int origCharCode, unsigned int origCharSet, unsigned int keyboardType,
              AbsoluteTime ts, OSObject *sender, void *refcon);

    // utility
    void addKey(unsigned int flags, KeyCode::KeyCode keyCode, CharCode::CharCode charCode) {
      if (RemapUtil::getKeyCodeModifier(keyCode) != ModifierFlag::NONE) {
        add(FireExtraKey::TYPE_AFTER, KeyEvent::MODIFY, flags, keyCode, charCode);
      } else {
        add(FireExtraKey::TYPE_AFTER, KeyEvent::DOWN, flags, keyCode, charCode);
        add(FireExtraKey::TYPE_AFTER, KeyEvent::UP, flags, keyCode, charCode);
      }
    }

  private:
    FireExtraKey list[FIREEXTRAKEY_MAXNUM];
    int size;
  };

  extern ListFireExtraKey listFireExtraKey;

  // ----------------------------------------------------------------------
  class FireConsumerKey {
  public:
    void set(unsigned int _eventType, unsigned int _flags, unsigned int _key) {
      eventType = _eventType;
      flags = _flags;
      key = _key;
    }
    unsigned int getEventType(void) const { return eventType; }
    unsigned int getFlags(void) const { return flags; }
    unsigned int getKey(void) const { return key; }

  private:
    unsigned int eventType;
    unsigned int flags;
    unsigned int key;
  };

  class ListFireConsumerKey {
  public:
    enum {
      FIRECONSUMERKEY_MAXNUM = 4,
    };
    void reset(void) { size = 0; }
    bool isEmpty(void) { return size == 0; }
    void add(unsigned int eventType, unsigned int flags, unsigned int key) {
      if (size >= FIRECONSUMERKEY_MAXNUM) return;
      list[size].set(eventType, flags, key);
      ++size;
    }
    void fire(KeyboardSpecialEventCallback callback, OSObject *target, AbsoluteTime ts, OSObject *sender, void *refcon);

  private:
    FireConsumerKey list[FIRECONSUMERKEY_MAXNUM];
    int size;
  };

  extern ListFireConsumerKey listFireConsumerKey;

  // ----------------------------------------------------------------------
  // for emacsmode
  class ModifierCanceling {
  public:
    void keyRelease(const RemapParams &params, ModifierFlag::ModifierFlag modifierFlag);
    void restore(const RemapParams &params, ModifierFlag::ModifierFlag modifierFlag);

  private:
    bool isSendKeyRelease;
  };

  // --------------------
  class IntervalChecker {
  public:
    void begin(void);
    bool checkThreshold(uint32_t millisec);

  private:
    uint32_t secs;
    uint32_t microsecs;
  };

  // ----------------------------------------------------------------------
  namespace FireFunc {
    typedef void (*FireFunc)(const RemapParams &params);
    void firefunc_nop(const RemapParams &params);
    void firefunc_backslash(const RemapParams &params);
    void firefunc_commandO(const RemapParams &params);
    void firefunc_commandSpace(const RemapParams &params);
    void firefunc_enter(const RemapParams &params);
    void firefunc_escape(const RemapParams &params);
    void firefunc_escape_noflags(const RemapParams &params);
    void firefunc_exposeAll(const RemapParams &params);
    void firefunc_return_noflags(const RemapParams &params);
    void firefunc_space(const RemapParams &params);
    void firefunc_tab(const RemapParams &params);
    void firefunc_emacsmode_controlK(const RemapParams &params, bool first);
    void firefunc_emacsmode_controlK_2nd(const RemapParams &params);
    void firefunc_emacsmode_ex_controlU(const RemapParams &params);
    void firefunc_jis_kana(const RemapParams &params);
    void firefunc_jis_kana_x2(const RemapParams &params);
    void firefunc_jis_eisuu(const RemapParams &params);
    void firefunc_jis_eisuu_x2(const RemapParams &params);
    void firefunc_jis_toggle_eisuu_kana(const RemapParams &params);
    void firefunc_jis_eisuu_escape(const RemapParams &params);
  }

  namespace ExtraRepeatFunc {
    void call_firefunc(FireFunc::FireFunc firefunc, KeyboardEventCallback callback, OSObject *target, unsigned int flags, unsigned int keyboardType, AbsoluteTime ts, OSObject *sender, void *refcon);

    void extraRepeatFunc_enter(KeyboardEventCallback callback, OSObject *target, unsigned int flags, unsigned int keyboardType, AbsoluteTime ts, OSObject *sender, void *refcon);
    void extraRepeatFunc_space(KeyboardEventCallback callback, OSObject *target, unsigned int flags, unsigned int keyboardType, AbsoluteTime ts, OSObject *sender, void *refcon);
    void extraRepeatFunc_emacsmode_controlK(KeyboardEventCallback callback, OSObject *target, unsigned int flags, unsigned int keyboardType, AbsoluteTime ts, OSObject *sender, void *refcon);

    void register_keyCombination(KeyCode::KeyCode keyCode1, CharCode::CharCode charCode1, KeyCode::KeyCode keyCode2, CharCode::CharCode charCode2);
    void extraRepeatFunc_keyCombination(KeyboardEventCallback callback, OSObject *target, unsigned int flags, unsigned int keyboardType, AbsoluteTime ts, OSObject *sender, void *refcon);
  }

  // ----------------------------------------
  // for SandS like behavior remappings (remap_space2shift, remap_enter2optionL_commandSpace, ...)
  class KeyOverlaidModifier {
  public:
    void remap(const RemapParams &params, KeyCode::KeyCode fromKeyCode, ModifierFlag::ModifierFlag toFlag, FireFunc::FireFunc firefunc, ExtraRepeatFunc::ExtraRepeatFunc extraRepeatFunc = NULL);

  private:
    bool useAsModifier;
    bool isClick;
    IntervalChecker ic;
  };

  // ----------------------------------------
  // Command_R+Command_L to Escape, ...
  class KeyOverlaidModifierCombination {
  public:
    void remap(const RemapParams &params, ModifierFlag::ModifierFlag fromFlag1, ModifierFlag::ModifierFlag fromFlag2, FireFunc::FireFunc firefunc);

  private:
    bool isModifier1HeldDown;
    bool isCallFireFunc;
    bool isClick;
  };

  class KeyWithModifierToKey {
  public:
    bool remap(const RemapParams &params, KeyCode::KeyCode fromKeyCode, ModifierFlag::ModifierFlag fromFlag, KeyCode::KeyCode toKeyCode);

  private:
    ModifierCanceling modifierCanceling;
  };

  // ----------------------------------------
  // A modifier has DoublePressed key action.
  class DoublePressModifier {
  public:
    void remap(const RemapParams &params, KeyCode::KeyCode fromKeyCode, ModifierFlag::ModifierFlag toFlag, FireFunc::FireFunc firefunc);

  private:
    int pressCount;
  };

  // ----------------------------------------
  // Modifier Holding + Key -> Key
  class ModifierHoldingKeyToKey {
  public:
    void remap(const RemapParams &params, ModifierFlag::ModifierFlag fromFlag, KeyCode::KeyCode fromKeyCode, KeyCode::KeyCode toKeyCode);

  private:
    IntervalChecker ic;
    bool doremap;
    bool first;
  };


  // ----------------------------------------------------------------------
  class ClickWatcher {
  public:
    enum {
      CLICKWATCHER_MAXNUM = 8,
    };
    void reset(void);
    void click(void);

    void set(bool *b);
    void unset(bool *b);

  private:
    bool *watchlist[CLICKWATCHER_MAXNUM];
  };
  extern ClickWatcher clickWatcher;

  // --------------------
  class PointingButtonStatus {
  public:
    bool helddown_left;
    bool helddown_right;
    bool helddown_middle;

    bool *getButtonStatus(PointingButton::PointingButton button);
  };
  extern PointingButtonStatus pointingButtonStatus;

  // --------------------
  class FirePointingClick {
  public:
    void set(PointingButton::PointingButton _button) {
      button = _button;
    }
    PointingButton::PointingButton getButton(void) const { return button; }

  private:
    PointingButton::PointingButton button;
  };

  class ListFirePointingClick {
  public:
    enum {
      FIREPOINTINGCLICK_MAXNUM = 4,
    };
    void reset(void) { size = 0; }
    bool isEmpty(void) { return size == 0; }
    void add(PointingButton::PointingButton button);
    void fire(RelativePointerEventCallback callback, OSObject *target, OSObject *sender, AbsoluteTime ts);

  private:
    FirePointingClick list[FIREPOINTINGCLICK_MAXNUM];
    int size;
  };

  extern ListFirePointingClick listFirePointingClick;

  // --------------------
  class FirePointingScroll {
  public:
    void set(short int _deltaAxis1, short int _deltaAxis2, short int _deltaAxis3, IOFixed _fixedDelta1, IOFixed _fixedDelta2, IOFixed _fixedDelta3, SInt32 _pointDelta1, SInt32 _pointDelta2, SInt32 _pointDelta3) {
      enable = true;
      deltaAxis1 = _deltaAxis1;
      deltaAxis2 = _deltaAxis2;
      deltaAxis3 = _deltaAxis3;
      fixedDelta1 = _fixedDelta1;
      fixedDelta2 = _fixedDelta2;
      fixedDelta3 = _fixedDelta3;
      pointDelta1 = _pointDelta1;
      pointDelta2 = _pointDelta2;
      pointDelta3 = _pointDelta3;
    }
    void fire(ScrollWheelEventCallback callback, OSObject *target, IOHIPointing *pointing, AbsoluteTime ts);
    bool isEnable(void) const { return enable; }

  private:
    bool enable;
    short int deltaAxis1;
    short int deltaAxis2;
    short int deltaAxis3;
    IOFixed fixedDelta1;
    IOFixed fixedDelta2;
    IOFixed fixedDelta3;
    SInt32 pointDelta1;
    SInt32 pointDelta2;
    SInt32 pointDelta3;
  };

  extern FirePointingScroll firePointingScroll;

  // ----------------------------------------
  class ButtonRelativeToScroll {
  public:
    void remap(const RemapPointingParams_relative &params, PointingButton::PointingButton button);

  private:
    bool isButtonHeldDown;
  };

  // --------------------
  class JISKanaMode {
  public:
    enum Mode {
      JISKANAMODE_ASCII,
      JISKANAMODE_HIRAGANA,
      JISKANAMODE_KATAKANA,
    };

    Mode getMode(void) const { return mode; }
    void setMode(Mode _mode) { mode = _mode; }
    void setMode(unsigned int eventType, unsigned int keyCode, unsigned int flags);
    void toggle(void);
    bool iskana(void) const { return mode != JISKANAMODE_ASCII; }

  private:
    Mode mode;
  };
  extern JISKanaMode jisKanaMode;
}

#endif
