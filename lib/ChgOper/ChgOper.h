#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgOper : public I2CRegister {
  struct ChgOperMask : public Mask {
    static inline const uint8_t CHG_OFF_LINEAR_OFF = BITS_NONE;
    static inline const uint8_t CHG_OFF_LINEAR_ON = BITS_0;
    static inline const uint8_t CHG_ON_LINEAR_ON = BITS_1;
    ChgOperMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdtEnMask : public Mask {
    static inline const uint8_t WATCHDOG_DISABLED = BITS_NONE;
    static inline const uint8_t WATCHDOG_ENABLED = BITS_3;
    WdtEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct DisBattFetMask : public Mask {
    static inline const uint8_t FET_STATEMACHINE = BITS_NONE;
    static inline const uint8_t FET_FORCED_OFF = BITS_4;
    DisBattFetMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const ChgOperMask kChgOperMask{BITS_1_0};
  static inline const WdtEnMask kWdtEnMask{BITS_3};
  static inline const DisBattFetMask kDisBattFetMask{BITS_4};

  ChgOper(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x09 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC