#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntSense1 : public I2CRegister {
  struct Sw1HsSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_0;
    Sw1HsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_1;
    Sw2HsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_2;
    Sw3HsSMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1HsSMask kSw1HsSMask{BITS_0};
  static inline const Sw2HsSMask kSw2HsSMask{BITS_1};
  static inline const Sw3HsSMask kSw3HsSMask{BITS_2};

  SwIntSense1(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0D;
};
} // namespace PMIC