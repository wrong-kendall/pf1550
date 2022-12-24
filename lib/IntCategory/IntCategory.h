#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct IntCategory : public I2CRegister {
  struct ChgIntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t OR_BITS = BITS_0;
    ChgIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw1IntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_1;
    Sw1IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2IntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_2;
    Sw2IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3IntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_3;
    Sw3IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct LdoIntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_4;
    LdoIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyIntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_5;
    OnkeyIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct TempIntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_6;
    TempIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct MiscIntMask : public Mask {
    static inline const uint8_t CLEAR = BITS_NONE;
    static inline const uint8_t ANY = BITS_7;
    MiscIntMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const ChgIntMask kChgIntMask{BITS_0};
  static inline const Sw1IntMask kSw1IntMask{BITS_1};
  static inline const Sw2IntMask kSw2IntMask{BITS_2};
  static inline const Sw3IntMask kSw3IntMask{BITS_3};
  static inline const LdoIntMask kLdoIntMask{BITS_4};
  static inline const OnkeyIntMask kOnkeyIntMask{BITS_5};
  static inline const TempIntMask kTempIntMask{BITS_6};
  static inline const MiscIntMask kMiscIntMask{BITS_7};
  IntCategory(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x06;
};
} // namespace PMIC