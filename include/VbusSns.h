#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct VbusSns : public I2CRegister {
  struct VbusUvloSnsMask : public Mask {
    static inline const uint8_t VBUS_DETACHED = BITS_NONE;
    static inline const uint8_t VBUS_GT_UVLO = BITS_2;
    VbusUvloSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusIn2SysSnsMask : public Mask {
    static inline const uint8_t GT = BITS_NONE;
    static inline const uint8_t LT = BITS_3;
    VbusIn2SysSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusOvloSnsMask : public Mask {
    static inline const uint8_t GT = BITS_NONE;
    static inline const uint8_t LT = BITS_4;
    VbusOvloSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusValidMask : public Mask {
    static inline const uint8_t INVALID = BITS_NONE;
    static inline const uint8_t VALID = BITS_5;
    VbusValidMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmSnsMask : public Mask {
    static inline const uint8_t NOT_TRIGGERED = BITS_NONE;
    static inline const uint8_t TRIGGERED = BITS_7;
    VbusDpmSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const VbusUvloSnsMask kVbusUvloSnsMask{BITS_2};
  static inline const VbusIn2SysSnsMask kVbusIn2SysSnsMask{BITS_3};
  static inline const VbusOvloSnsMask kVbusOvloSnsMask{BITS_4};
  static inline const VbusValidMask kVbusValidMask{BITS_5};
  static inline const VbusDpmSnsMask kVbusDpmSnsMask{BITS_7};

  VbusSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x06 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC