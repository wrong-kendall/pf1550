#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ThmRegCnfg : public I2CRegister {
  struct ThmCnfgMask : public Mask {
    static inline const uint8_t THM_DOES_NOT_CONTROL = BITS_NONE;
    static inline const uint8_t THM_CONTROLS = BITS_0;
    static inline const uint8_t JEITA1 = BITS_1;
    static inline const uint8_t JEITA2 = BITS_1_0;
    ThmCnfgMask(uint8_t mask) : Mask(mask) {}
  };
  struct RegTempMask : public Mask {
    static inline const uint8_t _80C = BITS_NONE;
    static inline const uint8_t _95C = BITS_2;
    static inline const uint8_t _110C = BITS_3;
    static inline const uint8_t _125C = BITS_3_2;
    RegTempMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmColdMask : public Mask {
    static inline const uint8_t _MINUS_10C = BITS_4;
    static inline const uint8_t _0C = BITS_NONE;
    ThmColdMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmHotMask : public Mask {
    static inline const uint8_t _55C = BITS_5;
    static inline const uint8_t _60C = BITS_NONE;
    ThmHotMask(uint8_t mask) : Mask(mask) {}
  };
  struct TempFbEnMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_7;
    TempFbEnMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const ThmCnfgMask kThmCnfgMask{BITS_1_0};
  static inline const RegTempMask kRegTempMask{BITS_3_2};
  static inline const ThmColdMask kThmColdMask{BITS_4};
  static inline const ThmHotMask kThmHotMask{BITS_5};
  static inline const TempFbEnMask kTempFbEnMask{BITS_7};
  ThmRegCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x12 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC