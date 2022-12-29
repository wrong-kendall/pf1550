#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ThmAdjSetting : public I2CRegister {
  struct ThmWarmMask : public Mask {
    static inline const uint8_t _45C = BITS_NONE;
    static inline const uint8_t _50C = BITS_0;
    ThmWarmMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmCoolMask : public Mask {
    static inline const uint8_t _15C = BITS_NONE;
    static inline const uint8_t _10C = BITS_1;
    ThmCoolMask(uint8_t mask) : Mask(mask) {}
  };
  struct CvAdjMask : public Mask {
    static inline const uint8_t _60MV = BITS_NONE;
    static inline const uint8_t _100MV = BITS_2;
    static inline const uint8_t _160MV = BITS_3;
    static inline const uint8_t _200MV = BITS_3_2;
    CvAdjMask(uint8_t mask) : Mask(mask) {}
  };
  struct CcAdjMask : public Mask {
    static inline const uint8_t _25PCT = BITS_NONE;
    static inline const uint8_t _50PCT = BITS_4;
    static inline const uint8_t _75PCT = BITS_5;
    static inline const uint8_t _100PCT = BITS_5_4;
    CcAdjMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const ThmWarmMask kThmWarmMask{BITS_0};
  static inline const ThmCoolMask kThmCoolMask{BITS_1};
  static inline const CvAdjMask kCvAdjMask{BITS_3_2};
  static inline const CcAdjMask kCcAdjMask{BITS_5_4};

  ThmAdjSetting(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x1A + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC