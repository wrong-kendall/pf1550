#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SiliconRev : public I2CRegister {
  struct MetalLayerRevMask : public Mask {
    MetalLayerRevMask(uint8_t mask) : Mask(mask) {}
  };
  struct FullLayerRevMask : public Mask {
    FullLayerRevMask(uint8_t mask) : Mask(mask) {}
  };
  struct FabFinMask : public Mask {
    FabFinMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const MetalLayerRevMask kMetalLayerRevMask{BITS_2_1_0};
  static inline const FullLayerRevMask kFullLayerRevMask{BITS_5_4_3};
  static inline const FabFinMask kFabFinMask{BITS_7_6};
  SiliconRev(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x02;
};
} // namespace PMIC