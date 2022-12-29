#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgIntCnfg : public I2CRegister {
  struct ChgIntGenMask : public Mask {
    static inline const uint8_t INT_ONLY_FC_TO_CV = BITS_NONE;
    static inline const uint8_t INT_ON_TRANSITION = BITS_0;
    ChgIntGenMask(uint8_t mask) : Mask(mask) {}
  };
  struct EoCIntMask : public Mask {
    static inline const uint8_t NO_EOC_INT = BITS_NONE;
    static inline const uint8_t EOC_INT = BITS_1;
    EoCIntMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const ChgIntGenMask kChgIntGenMask{BITS_0};
  static inline const EoCIntMask kEoCIntMask{BITS_1};
  ChgIntCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x19 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC