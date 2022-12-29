#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntMask2 : public I2CRegister {
  struct Sw1DvsDoneMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    Sw1DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_1;
    Sw2DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneMMask : public Mask {
    static inline const uint8_t REMOVED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_2;
    Sw3DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1DvsDoneMMask kSw1DvsDoneMMask{BITS_0};
  static inline const Sw2DvsDoneMMask kSw2DvsDoneMMask{BITS_1};
  static inline const Sw3DvsDoneMMask kSw3DvsDoneMMask{BITS_2};

  SwIntMask2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0F;
};
} // namespace PMIC