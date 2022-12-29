#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntMask0 : public I2CRegister {
  struct Sw1LsMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    Sw1LsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_1;
    Sw2LsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_2;
    Sw3LsMMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1LsMMask kSw1LsMMask{BITS_0};
  static inline const Sw2LsMMask kSw2LsMMask{BITS_1};
  static inline const Sw3LsMMask kSw3LsMMask{BITS_2};

  SwIntMask0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x09;
};
} // namespace PMIC