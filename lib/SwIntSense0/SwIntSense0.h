#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntSense0 : public I2CRegister {
  struct Sw1LsSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_0;
    Sw1LsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_1;
    Sw2LsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_2;
    Sw3LsSMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1LsSMask kSw1LsSMask{BITS_0};
  static inline const Sw2LsSMask kSw2LsSMask{BITS_1};
  static inline const Sw3LsSMask kSw3LsSMask{BITS_2};

  SwIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0A;
};
} // namespace PMIC