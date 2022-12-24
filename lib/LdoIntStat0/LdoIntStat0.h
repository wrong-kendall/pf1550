#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct LdoIntStat0 : public I2CRegister {
  struct Ldo1FaultIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_0;
    Ldo1FaultIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_1;
    Ldo2FaultIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_2;
    Ldo3FaultIMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Ldo1FaultIMask kLdo1FaultIMask{BITS_0};
  static inline const Ldo2FaultIMask kLdo2FaultIMask{BITS_1};
  static inline const Ldo3FaultIMask kLdo3FaultIMask{BITS_2};

  LdoIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x18;
};
} // namespace PMIC