#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntMask1 : public I2CRegister {
  struct Sw1HsMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    Sw1HsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_1;
    Sw2HsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_2;
    Sw3HsMMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1HsMMask kSw1HsMMask{BITS_0};
  static inline const Sw2HsMMask kSw2HsMMask{BITS_1};
  static inline const Sw3HsMMask kSw3HsMMask{BITS_2};

  SwIntMask1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0C;
};
} // namespace PMIC