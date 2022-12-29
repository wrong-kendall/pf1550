#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct TempIntMask0 : public I2CRegister {
  struct Therm110MMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    Therm110MMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125MMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    Therm125MMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110MMask kTherm110MMask;
  static const Therm125MMask kTherm125MMask;
  TempIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x21;
};
} // namespace PMIC