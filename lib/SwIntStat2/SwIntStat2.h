#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct SwIntStat2 : public I2CRegister {
  struct Sw1DvsDoneIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_0;
    Sw1DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_1;
    Sw2DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneIMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t INT = BITS_2;
    Sw3DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const Sw1DvsDoneIMask kSw1DvsDoneIMask{BITS_0};
  static inline const Sw2DvsDoneIMask kSw2DvsDoneIMask{BITS_1};
  static inline const Sw3DvsDoneIMask kSw3DvsDoneIMask{BITS_2};

  SwIntStat2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0E;
};
} // namespace PMIC