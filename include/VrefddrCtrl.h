#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct VrefddrCtrl : public I2CRegister {
  struct VrefddrEnMask : public Mask {
    static inline const uint8_t DISABLE = BITS_0;
    static inline const uint8_t ENABLE = BITS_NONE;
    VrefddrEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct VrefddrStbyEnMask : public Mask {
    static inline const uint8_t DISABLE = BITS_1;
    static inline const uint8_t ENABLE = BITS_NONE;
    VrefddrStbyEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct VrefddrOModeMask : public Mask {
    static inline const uint8_t DISABLE = BITS_2;
    static inline const uint8_t ENABLE = BITS_NONE;
    VrefddrOModeMask(uint8_t mask) : Mask(mask) {}
  };
  struct VrefddrLPwrMask : public Mask {
    static inline const uint8_t DISABLE = BITS_3;
    static inline const uint8_t ENABLE = BITS_NONE;
    VrefddrLPwrMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const VrefddrEnMask kVrefddrEnMask{BITS_0};
  static inline const VrefddrStbyEnMask kVrefddrStbyEnMask{BITS_1};
  static inline const VrefddrOModeMask kVrefddrOModeMask{BITS_2};
  static inline const VrefddrLPwrMask kVrefddrLPwrMask{BITS_3};
  VrefddrCtrl(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x4A;
};
} // namespace PMIC