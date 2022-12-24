#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct TempIntSense0 : public I2CRegister {
  struct Therm110SMask : public Mask {
    static inline const uint8_t BELOW = BITS_NONE;
    static inline const uint8_t ABOVE = BITS_0;
    Therm110SMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125SMask : public Mask {
    static inline const uint8_t BELOW = BITS_NONE;
    static inline const uint8_t ABOVE = BITS_0;
    Therm125SMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const Therm110SMask kTherm110SMask{BITS_0};
  static inline const Therm125SMask kTherm125SMask{BITS_2};
  TempIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x22;
};

} // namespace PMIC