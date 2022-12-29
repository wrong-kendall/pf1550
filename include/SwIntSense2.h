#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntSense2 : public I2CRegister {
  struct Sw1DvsDoneSMask : public Mask {
    static inline const uint8_t NOT_IN_PROGRESS = BITS_NONE;
    static inline const uint8_t IN_PROGRESS = BITS_0;
    Sw1DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneSMask : public Mask {
    static inline const uint8_t NOT_IN_PROGRESS = BITS_NONE;
    static inline const uint8_t IN_PROGRESS = BITS_1;
    Sw2DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneSMask : public Mask {
    static inline const uint8_t NOT_IN_PROGRESS = BITS_NONE;
    static inline const uint8_t IN_PROGRESS = BITS_2;
    Sw3DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1DvsDoneSMask kSw1DvsDoneSMask{BITS_0};
  static inline const Sw2DvsDoneSMask kSw2DvsDoneSMask{BITS_1};
  static inline const Sw3DvsDoneSMask kSw3DvsDoneSMask{BITS_2};

  SwIntSense2(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x10;
};
} // namespace PMIC