#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct OnkeyIntSense0 : public I2CRegister {
  struct OnkeyPushSMask : public Mask {
    static inline const uint8_t PUSHED = BITS_NONE;
    static inline const uint8_t NOT_PUSHED = BITS_0;
    OnkeyPushSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SSMask : public Mask {
    static inline const uint8_t PUSHED = BITS_NONE;
    static inline const uint8_t NOT_PUSHED = BITS_1;
    Onkey1SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SSMask : public Mask {
    static inline const uint8_t PUSHED = BITS_NONE;
    static inline const uint8_t NOT_PUSHED = BITS_2;
    Onkey2SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SSMask : public Mask {
    static inline const uint8_t PUSHED = BITS_NONE;
    static inline const uint8_t NOT_PUSHED = BITS_3;
    Onkey3SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SSMask : public Mask {
    static inline const uint8_t PUSHED = BITS_NONE;
    static inline const uint8_t NOT_PUSHED = BITS_4;
    Onkey4SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SSMask : public Mask {
    static inline const uint8_t PUSHED = BITS_NONE;
    static inline const uint8_t NOT_PUSHED = BITS_5;
    Onkey8SSMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const OnkeyPushSMask kOnkeyPushSMask{BITS_0};
  static inline const Onkey1SSMask kOnkey1SSMask{BITS_1};
  static inline const Onkey2SSMask kOnkey2SSMask{BITS_2};
  static inline const Onkey3SSMask kOnkey3SSMask{BITS_3};
  static inline const Onkey4SSMask kOnkey4SSMask{BITS_4};
  static inline const Onkey8SSMask kOnkey8SSMask{BITS_5};
  OnkeyIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x26;
};
} // namespace PMIC