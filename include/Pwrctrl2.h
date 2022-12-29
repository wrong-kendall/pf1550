#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct Pwrctrl2 : public I2CRegister {
  struct UvdetMask : public Mask {
    static inline const uint8_t _2_65_RISE_2_55_FALL = BITS_NONE;
    static inline const uint8_t _2_8_RISE_2_7_FALL = BITS_0;
    static inline const uint8_t _3_0_RISE_2_9_FALL = BITS_1;
    static inline const uint8_t _3_1_RISE_3_0_FALL = BITS_1_0;
    UvdetMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnMask : public Mask {
    static inline const uint8_t _3_3_RISE_3_1_FALL = BITS_NONE;
    static inline const uint8_t _3_5_RISE_3_3_FALL = BITS_2;
    static inline const uint8_t _3_7_RISE_3_5_FALL = BITS_3;
    static inline const uint8_t _3_9_RISE_3_7_FALL = BITS_3_2;
    LowSysWarnMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const UvdetMask kUvdetMask{BITS_1_0};
  static inline const LowSysWarnMask kLowSysWarnMask{BITS_3_2};

  Pwrctrl2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x5A;
};
} // namespace PMIC