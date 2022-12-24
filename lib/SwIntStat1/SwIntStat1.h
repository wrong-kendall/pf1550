#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntStat1 : public I2CRegister {
  struct Sw1HsIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_0;
    Sw1HsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_1;
    Sw2HsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_2;
    Sw3HsIMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1HsIMask kSw1HsIMask{BITS_0};
  static inline const Sw2HsIMask kSw2HsIMask{BITS_1};
  static inline const Sw3HsIMask kSw3HsIMask{BITS_2};

  SwIntStat1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0B;
};
} // namespace PMIC