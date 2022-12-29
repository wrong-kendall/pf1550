#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct LedPwm : public I2CRegister {
  struct LedPwmMask : public Mask {
    static inline const uint8_t _0_32 = BITS_NONE;
    static inline const uint8_t _1_32 = BITS_0;
    static inline const uint8_t _2_32 = BITS_1;
    static inline const uint8_t _3_32 = BITS_1_0;
    static inline const uint8_t _4_32 = BITS_2;
    static inline const uint8_t _5_32 = BITS_2_0;
    static inline const uint8_t _6_32 = BITS_2_1;
    static inline const uint8_t _7_32 = BITS_2_1_0;
    static inline const uint8_t _8_32 = BITS_3;
    static inline const uint8_t _9_32 = BITS_3_0;
    static inline const uint8_t _10_32 = BITS_3_1;
    static inline const uint8_t _11_32 = BITS_3_1_0;
    static inline const uint8_t _12_32 = BITS_3_2;
    static inline const uint8_t _13_32 = BITS_3_2_0;
    static inline const uint8_t _14_32 = BITS_3_2_1;
    static inline const uint8_t _15_32 = BITS_3_2_1_0;
    static inline const uint8_t _16_32 = BITS_4;
    static inline const uint8_t _17_32 = BITS_4_0;
    static inline const uint8_t _18_32 = BITS_4_1;
    static inline const uint8_t _19_32 = BITS_4_1_0;
    static inline const uint8_t _20_32 = BITS_4_2;
    static inline const uint8_t _21_32 = BITS_4_2_0;
    static inline const uint8_t _22_32 = BITS_4_2_1;
    static inline const uint8_t _23_32 = BITS_4_2_1_0;
    static inline const uint8_t _24_32 = BITS_4_3;
    static inline const uint8_t _25_32 = BITS_4_3_0;
    static inline const uint8_t _26_32 = BITS_4_3_1;
    static inline const uint8_t _27_32 = BITS_4_3_1_0;
    static inline const uint8_t _28_32 = BITS_4_3_2;
    static inline const uint8_t _29_32 = BITS_4_3_2_0;
    static inline const uint8_t _30_32 = BITS_4_3_2_1;
    static inline const uint8_t _31_32 = BITS_4_3_2_1_0;
    LedPwmMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedRampMask : public Mask {
    static inline const uint8_t DISABLE = BITS_NONE;
    static inline const uint8_t ENABLE = BITS_6;
    LedRampMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedEnMask : public Mask {
    static inline const uint8_t DISABLE = BITS_NONE;
    static inline const uint8_t ENABLE = BITS_7;
    LedEnMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const LedPwmMask kLedPwmMask{BITS_5_4_3_2_1_0};
  static inline const LedRampMask kLedRampMask{BITS_6};
  static inline const LedEnMask kLedEnMask{BITS_7};
  LedPwm(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x1C + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC