#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgTmr : public I2CRegister {
  struct FChgTimeMask : public Mask {
    static inline const uint8_t DISABLE = BITS_NONE;
    static inline const uint8_t _2HR = BITS_0;
    static inline const uint8_t _4HR = BITS_1;
    static inline const uint8_t _6HR = BITS_1_0;
    static inline const uint8_t _8HR = BITS_2;
    static inline const uint8_t _10HR = BITS_2_0;
    static inline const uint8_t _12HR = BITS_2_1;
    static inline const uint8_t _14HR = BITS_2_1_0;
    FChgTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct EoCTimeMask : public Mask {
    static inline const uint8_t _0M = BITS_NONE;
    static inline const uint8_t _10M = BITS_3;
    static inline const uint8_t _20M = BITS_4;
    static inline const uint8_t _30M = BITS_4_3;
    static inline const uint8_t _40M = BITS_5;
    static inline const uint8_t _50M = BITS_5_3;
    static inline const uint8_t _60M = BITS_5_4;
    static inline const uint8_t _70M = BITS_2_1_0;
    EoCTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct TPreChgMask : public Mask {
    static inline const uint8_t _30M = BITS_NONE;
    static inline const uint8_t _45M = BITS_7;
    TPreChgMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const FChgTimeMask kFChgTimeMask{BITS_2_1_0};
  static inline const EoCTimeMask kEoCTimeMask{BITS_5_4_3};
  static inline const TPreChgMask kTPreChgMask{BITS_7};

  ChgTmr(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0A + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC