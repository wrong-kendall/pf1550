#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct MiscIntStat0 : public I2CRegister {
  struct PwrUpIMask : public Mask {
    static inline const uint8_t ACTIVE = BITS_NONE;
    static inline const uint8_t NOT_ACTIVE = BITS_0;
    PwrUpIMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnIMask : public Mask {
    static inline const uint8_t ACTIVE = BITS_NONE;
    static inline const uint8_t NOT_ACTIVE = BITS_1;
    PwrDnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnIMask : public Mask {
    static inline const uint8_t ACTIVE = BITS_NONE;
    static inline const uint8_t NOT_ACTIVE = BITS_2;
    PwrOnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnIMask : public Mask {
    static inline const uint8_t ACTIVE = BITS_NONE;
    static inline const uint8_t NOT_ACTIVE = BITS_3;
    LowSysWarnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoIMask : public Mask {
    static inline const uint8_t ACTIVE = BITS_NONE;
    static inline const uint8_t NOT_ACTIVE = BITS_4;
    SysOlvoIMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const PwrUpIMask kPwrUpIMask{BITS_0};
  static inline const PwrDnIMask kPwrDnIMask{BITS_1};
  static inline const PwrOnIMask kPwrOnIMask{BITS_2};
  static inline const LowSysWarnIMask kLowSysWarnIMask{BITS_3};
  static inline const SysOlvoIMask kSysOlvoIMask{BITS_4};
  MiscIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x28;
};
} // namespace PMIC