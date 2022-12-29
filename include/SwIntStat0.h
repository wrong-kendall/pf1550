#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntStat0 : public I2CRegister {
  struct Sw1LsIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_0;
    Sw1LsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_1;
    Sw2LsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_2;
    Sw3LsIMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1LsIMask kSw1LsIMask{BITS_0};
  static inline const Sw2LsIMask kSw2LsIMask{BITS_1};
  static inline const Sw3LsIMask kSw3LsIMask{BITS_2};

  SwIntStat0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x08;
};
} // namespace PMIC