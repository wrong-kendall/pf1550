#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct DbncDelayTime : public I2CRegister {
  struct VbusOvTdbMask : public Mask {
    static inline const uint8_t _10US = BITS_NONE;
    static inline const uint8_t _100US = BITS_0;
    static inline const uint8_t _1MS = BITS_1;
    static inline const uint8_t _10MS = BITS_1_0;
    VbusOvTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyTdbMask : public Mask {
    static inline const uint8_t _0MS = BITS_NONE;
    static inline const uint8_t _16MS = BITS_2;
    static inline const uint8_t _32MS = BITS_3;
    UsbPhyTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysWkUpDlyMask : public Mask {
    static inline const uint8_t _8MS = BITS_NONE;
    static inline const uint8_t _16MS = BITS_4;
    static inline const uint8_t _32MS = BITS_5;
    static inline const uint8_t _100MS = BITS_5_4;
    SysWkUpDlyMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const VbusOvTdbMask kVbusOvTdbMask{BITS_1_0};
  static inline const UsbPhyTdbMask kUsbPhyTdbMask{BITS_3_2};
  static inline const SysWkUpDlyMask kSysWkUpDlyMask{BITS_5_4};

  DbncDelayTime(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x18 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC