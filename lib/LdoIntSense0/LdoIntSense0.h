#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct LdoIntSense0 : public I2CRegister {
  struct Ldo1FaultSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_0;
    Ldo1FaultSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_1;
    Ldo2FaultSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultSMask : public Mask {
    static inline const uint8_t FAULT_REMOVED = BITS_NONE;
    static inline const uint8_t FAULT_EXISTS = BITS_2;
    Ldo3FaultSMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Ldo1FaultSMask kLdo1FaultSMask{BITS_0};
  static inline const Ldo2FaultSMask kLdo2FaultSMask{BITS_1};
  static inline const Ldo3FaultSMask kLdo3FaultSMask{BITS_2};

  LdoIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x1A;
};
} // namespace PMIC