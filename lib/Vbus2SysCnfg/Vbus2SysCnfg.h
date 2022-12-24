#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct Vbus2SysCnfg : public I2CRegister {
  struct Vbus2SysTdbMask : public Mask {
    static inline const uint8_t _100US = BITS_0;
    static inline const uint8_t _1MS = BITS_1;
    static inline const uint8_t _10MS = BITS_1_0;
    Vbus2SysTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct Vbus2SysThrshMask : public Mask {
    static inline const uint8_t _50MV = BITS_NONE;
    static inline const uint8_t _175MV = BITS_2;
    Vbus2SysThrshMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Vbus2SysTdbMask kVbus2SysTdbMask{BITS_1_0};
  static inline const Vbus2SysThrshMask kVbus2SysThrshMask{BITS_2};

  Vbus2SysCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x1B + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC