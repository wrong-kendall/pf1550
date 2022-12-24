#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct TempIntStat0 : public I2CRegister {
  struct Therm110IMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_0;
    Therm110IMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125IMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_0;
    Therm125IMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const Therm110IMask kTherm110IMask{BITS_0};
  static inline const Therm125IMask kTherm125IMask{BITS_2};
  TempIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x20;
};
} // namespace PMIC