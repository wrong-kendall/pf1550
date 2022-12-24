#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct LdoIntMask0 : public I2CRegister {
  struct Ldo1FaultMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    Ldo1FaultMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_1;
    Ldo2FaultMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_2;
    Ldo3FaultMMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Ldo1FaultMMask kLdo1FaultMMask{BITS_0};
  static inline const Ldo2FaultMMask kLdo2FaultMMask{BITS_1};
  static inline const Ldo3FaultMMask kLdo3FaultMMask{BITS_2};

  LdoIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x19;
};
} // namespace PMIC