#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct LedCnfg : public I2CRegister {
  struct LedFreqMask : public Mask {
    static inline const uint8_t _1HZ = BITS_NONE;
    static inline const uint8_t _0_5HZ = BITS_0;
    static inline const uint8_t _256HZ = BITS_1;
    static inline const uint8_t _8HZ = BITS_1_0;
    LedFreqMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedCurrentMask : public Mask {
    static inline const uint8_t _6MA = BITS_2;
    LedCurrentMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedCfgMask : public Mask {
    static inline const uint8_t _ON_FAULT_FLASH = BITS_NONE;
    static inline const uint8_t _FLASH_FAULT_ON = BITS_4;
    LedCfgMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedOvrdMask : public Mask {
    static inline const uint8_t STATE_MACHINE_CONTROLLED = BITS_NONE;
    static inline const uint8_t SOFTWARE_CONTROLLED = BITS_5;
    LedOvrdMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const LedFreqMask kLedFreqMask{BITS_1_0};
  static inline const LedCurrentMask kLedCurrentMask{BITS_3_2};
  static inline const LedCfgMask kLedCfgMask{BITS_4};
  static inline const LedOvrdMask kLedOvrdMask{BITS_5};

  LedCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x1E + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC