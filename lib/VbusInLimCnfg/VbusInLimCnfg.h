#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct VbusInLimCnfg : public I2CRegister {
  struct VbusLinILimMask : public Mask {
    static inline const uint8_t _10MA = BITS_NONE;
    static inline const uint8_t _15MA = BITS_3;
    static inline const uint8_t _20MA = BITS_4;
    static inline const uint8_t _25MA = BITS_4_3;
    static inline const uint8_t _30MA = BITS_5;
    static inline const uint8_t _35MA = BITS_5_3;
    static inline const uint8_t _40MA = BITS_5_4;
    static inline const uint8_t _45MA = BITS_5_4_3;
    static inline const uint8_t _50MA = BITS_6;
    static inline const uint8_t _100MA = BITS_6_3;
    static inline const uint8_t _150MA = BITS_6_4;
    static inline const uint8_t _200MA = BITS_6_4_3;
    static inline const uint8_t _300MA = BITS_6_5;
    static inline const uint8_t _400MA = BITS_6_5_3;
    static inline const uint8_t _500MA = BITS_6_5_4;
    static inline const uint8_t _600MA = BITS_6_5_4_3;
    static inline const uint8_t _700MA = BITS_7;
    static inline const uint8_t _800MA = BITS_7_3;
    static inline const uint8_t _900MA = BITS_7_4;
    static inline const uint8_t _1000MA = BITS_7_4_3;
    static inline const uint8_t _1500MA = BITS_7_5;
    VbusLinILimMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const VbusLinILimMask kVbusLinILimMask{BITS_7_6_5_4_3};
  VbusInLimCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x14 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC