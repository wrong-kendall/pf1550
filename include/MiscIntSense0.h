#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct MiscIntSense0 : public I2CRegister {
  struct PwrUpSMask : public Mask {
    static inline const uint8_t IN_PROGRESS = BITS_NONE;
    static inline const uint8_t NOT_IN_PROGRESS = BITS_0;
    PwrUpSMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnSMask : public Mask {
    static inline const uint8_t IN_PROGRESS = BITS_NONE;
    static inline const uint8_t NOT_IN_PROGRESS = BITS_1;
    PwrDnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnSMask : public Mask {
    static inline const uint8_t PWR_ON_LOW = BITS_NONE;
    static inline const uint8_t PWR_ON_HIGH = BITS_2;
    PwrOnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnSMask : public Mask {
    static inline const uint8_t ABOVE = BITS_NONE;
    static inline const uint8_t BELOW = BITS_3;
    LowSysWarnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoSMask : public Mask {
    static inline const uint8_t ABOVE = BITS_NONE;
    static inline const uint8_t BELOW = BITS_4;
    SysOlvoSMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const PwrUpSMask kPwrUpSMask{BITS_0};
  static inline const PwrDnSMask kPwrDnSMask{BITS_1};
  static inline const PwrOnSMask kPwrOnSMask{BITS_2};
  static inline const LowSysWarnSMask kLowSysWarnSMask{BITS_3};
  static inline const SysOlvoSMask kSysOlvoSMask{BITS_4};
  MiscIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x2A;
};
} // namespace PMIC