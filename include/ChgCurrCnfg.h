#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgCurrCnfg : public I2CRegister {
  struct ChgCcMask : public Mask {
    static inline const uint8_t _100MA = BITS_NONE;
    static inline const uint8_t _150MA = BITS_0;
    static inline const uint8_t _200MA = BITS_1;
    static inline const uint8_t _250MA = BITS_1_0;
    static inline const uint8_t _300MA = BITS_2;
    static inline const uint8_t _350MA = BITS_2_0;
    static inline const uint8_t _400MA = BITS_2_1;
    static inline const uint8_t _450MA = BITS_2_1_0;
    static inline const uint8_t _500MA = BITS_3;
    static inline const uint8_t _550MA = BITS_3_0;
    static inline const uint8_t _600MA = BITS_3_1;
    static inline const uint8_t _650MA = BITS_3_1_0;
    static inline const uint8_t _700MA = BITS_3_2;
    static inline const uint8_t _750MA = BITS_3_2_0;
    static inline const uint8_t _800MA = BITS_3_2_1;
    static inline const uint8_t _850MA = BITS_3_2_1_0;
    static inline const uint8_t _900MA = BITS_4;
    static inline const uint8_t _950MA = BITS_4_0;
    static inline const uint8_t _1000MA = BITS_4_1;
    ChgCcMask(uint8_t mask) : Mask(mask) {}
  };
  struct PreChgLbThrsMask : public Mask {
    static inline const uint8_t _2_8V = BITS_NONE;
    static inline const uint8_t _2_7V = BITS_5;
    static inline const uint8_t _2_9V = BITS_6;
    static inline const uint8_t _3_0V = BITS_6_5;
    PreChgLbThrsMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const ChgCcMask kChgCcMask{BITS_4_3_2_1_0};
  static inline const PreChgLbThrsMask kPreChgLbThrsMask{BITS_6_5};

  ChgCurrCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0E + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC