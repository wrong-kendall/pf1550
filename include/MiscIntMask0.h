#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct MiscIntMask0 : public I2CRegister {
  struct PwrUpMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_0;
    PwrUpMMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_1;
    PwrDnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_2;
    PwrOnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_3;
    LowSysWarnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_4;
    SysOlvoMMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const PwrUpMMask kPwrUpMMask{BITS_0};
  static inline const PwrDnMMask kPwrDnMMask{BITS_1};
  static inline const PwrOnMMask kPwrOnMMask{BITS_2};
  static inline const LowSysWarnMMask kLowSysWarnMMask{BITS_3};
  static inline const SysOlvoMMask kSysOlvoMMask{BITS_4};
  MiscIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x29;
};
} // namespace PMIC