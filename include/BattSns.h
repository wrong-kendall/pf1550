#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct BattSns : public I2CRegister {
  struct BattSnsMask : public Mask {
    static inline const uint8_t VBUS_INVALID = BITS_NONE;
    static inline const uint8_t VBATT_LT_PRECHG = BITS_0;
    static inline const uint8_t CHG_SUSPENDED = BITS_1;
    static inline const uint8_t VBATT_GT_PRECHG = BITS_2;
    static inline const uint8_t OVERVOLTAGE = BITS_2_0;
    static inline const uint8_t NOT_DETECTED = BITS_2_1;
    BattSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct BattOCSnsMask : public Mask {
    static inline const uint8_t NOFAULT = BITS_NONE;
    static inline const uint8_t FAULT = BITS_5;
    BattOCSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const BattSnsMask kBattSnsMask{BITS_2_1_0};
  static inline const BattOCSnsMask kBattOCSnsMask{BITS_5};

  BattSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x08 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC