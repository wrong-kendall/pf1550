#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgSns : public I2CRegister {
  struct ChgSnsMask : public Mask {
    static inline const uint8_t PRECHARGE = BITS_NONE;
    static inline const uint8_t FAST_CHARGE_CC = BITS_0;
    static inline const uint8_t FAST_CHARGE_CV = BITS_1;
    static inline const uint8_t END_OF_CHARGE = BITS_1_0;
    static inline const uint8_t DONE = BITS_2;
    static inline const uint8_t TIMER_FAULT = BITS_2_1;
    static inline const uint8_t THERMISTOR_SUSPEND = BITS_2_1_0;
    static inline const uint8_t OFF_INVALID_OR_DISABLED = BITS_3;
    static inline const uint8_t OVERVOLTAGE = BITS_3_0;
    static inline const uint8_t CHG_THERMAL_OFF = BITS_3_1;
    static inline const uint8_t LINEAR_ONLY_NO_CHARGE = BITS_3_2;
    ChgSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdtSnsMask : public Mask {
    static inline const uint8_t CHG_OFF_WATCHDOG = BITS_5;
    static inline const uint8_t WATCHDOG_NOT_EXPIRED = BITS_NONE;
    WdtSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmSnsMask : public Mask {
    static inline const uint8_t WITHIN_THRESHOLDS = BITS_5;
    static inline const uint8_t OUTSIDE_THRESHOLDS = BITS_NONE;
    ThmSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct TregSnsMask : public Mask {
    static inline const uint8_t GREATER_THAN_THRESHOLD = BITS_7;
    static inline const uint8_t LESS_THAN_THRESHOLD = BITS_NONE;
    TregSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const ChgSnsMask kChgSnsMask{BITS_3_2_1_0};
  static inline const WdtSnsMask kWdtSnsMask{BITS_5};
  static inline const ThmSnsMask kThmSnsMask{BITS_6};
  static inline const TregSnsMask kTregSnsMask{BITS_7};

  ChgSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x07 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC