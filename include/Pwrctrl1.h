#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct Pwrctrl1 : public I2CRegister {
  struct PwronDbncMask : public Mask {
    // TODO(knedall): WTF? the first 2 are duplicated
    static inline const uint8_t _31_25MS_FALL_31_25MS_RISE_1 = BITS_NONE;
    static inline const uint8_t _31_25MS_FALL_31_25MS_RISE_2 = BITS_0;
    static inline const uint8_t _125MS_FALL_31_25MS_RISE = BITS_1;
    static inline const uint8_t _750MS_FALL_31_25MS_RISE = BITS_1_0;
    PwronDbncMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyBbncMask : public Mask {
    static inline const uint8_t _31_25MS_FALL_31_25MS_RISE_1 = BITS_NONE;
    static inline const uint8_t _31_25MS_FALL_31_25MS_RISE_2 = BITS_2;
    static inline const uint8_t _125MS_FALL_31_25MS_RISE = BITS_3;
    static inline const uint8_t _750MS_FALL_31_25MS_RISE = BITS_3_2;
    OnkeyBbncMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwronRstEnMask : public Mask {
    static inline const uint8_t LONG_PRESS_SLEEP_OR_REGS_DISABLE = BITS_4;
    static inline const uint8_t LONG_PRESS_NO_SLEEP_OR_REGS_DISABLE = BITS_NONE;
    PwronRstEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct RestartEnMask : public Mask {
    static inline const uint8_t RESTART_AFTER_5S = BITS_5;
    static inline const uint8_t NO_EFFECT = BITS_NONE;
    RestartEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct RegScpEnMask : public Mask {
    static inline const uint8_t _LDO_ON_CURRENT_LIMIT_FAULT = BITS_6;
    static inline const uint8_t _SHUTDOWN_LDO_ON_CURRENT_LIMIT_FAULT =
        BITS_NONE;
    RegScpEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyRstEnmask : public Mask {
    static inline const uint8_t ONKEY_RESET = BITS_7;
    static inline const uint8_t NO_ONKEY_RESET = BITS_NONE;
    OnkeyRstEnmask(uint8_t mask) : Mask(mask) {}
  };
  static inline const PwronDbncMask kPwronDbncMask{BITS_1_0};
  static inline const OnkeyBbncMask kOnkeyBbncMask{BITS_3_2};
  static inline const PwronRstEnMask kPwronRstEnMask{BITS_4};
  static inline const RestartEnMask kRestartEnMask{BITS_5};
  static inline const RegScpEnMask kRegScpEnMask{BITS_6};
  static inline const OnkeyRstEnmask kOnkeyRstEnmask{BITS_7};
  Pwrctrl1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x59;
};
} // namespace PMIC