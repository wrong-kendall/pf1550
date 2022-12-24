#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgEocCnfg : public I2CRegister {
  struct ChgRestartMask : public Mask {
    static inline const uint8_t _100MV = BITS_NONE;
    static inline const uint8_t _150MV = BITS_0;
    static inline const uint8_t _200MV = BITS_1;
    static inline const uint8_t DISABLED = BITS_1_0;
    ChgRestartMask(uint8_t mask) : Mask(mask) {}
  };
  struct IEoCMask : public Mask {
    static inline const uint8_t _5MA = BITS_NONE;
    static inline const uint8_t _10MA = BITS_4;
    static inline const uint8_t _20MA = BITS_5;
    static inline const uint8_t _30MA = BITS_5_4;
    static inline const uint8_t _50MA = BITS_6;
    IEoCMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const ChgRestartMask kChgRestartMask{BITS_1_0};
  static inline const IEoCMask kIEoCMask{BITS_6_5_4};
  ChgEocCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0D + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC