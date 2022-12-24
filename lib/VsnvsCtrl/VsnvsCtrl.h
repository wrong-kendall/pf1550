#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct VsnvsCtrl : public I2CRegister {
  struct CLKPulseMask : public Mask {
    CLKPulseMask(uint8_t mask) : Mask(mask) {}
  };
  struct ForceBOSMask : public Mask {
    static inline const uint8_t FORCED = BITS_4;
    static inline const uint8_t ONLY_VSYS_LT_VDIV = BITS_NONE;
    ForceBOSMask(uint8_t mask) : Mask(mask) {}
  };
  struct LiBGDisMask : public Mask {
    static inline const uint8_t Vsnvs_BAND_GAP_DISABLED = BITS_NONE;
    static inline const uint8_t Vsnvs_BAND_GAP_ENABLED = BITS_5;
    LiBGDisMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const CLKPulseMask kCLKPulseMask{BITS_3};
  static inline const ForceBOSMask kForceBOSMask{BITS_4};
  static inline const LiBGDisMask kLiBGDisMask{BITS_5};
  VsnvsCtrl(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x48;
};
} // namespace PMIC