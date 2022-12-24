#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct BatfetCnfg : public I2CRegister {
  struct WdtClrMask : public Mask {
    static inline const uint8_t NOT_CLEARED = BITS_0;
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t NOT_CLEARED_1 = BITS_1;
    static inline const uint8_t NOT_CLEARED_2 = BITS_1_0;
    WdtClrMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdBattFetOffMask : public Mask {
    WdBattFetOffMask(uint8_t mask) : Mask(mask) {}
  };
  struct BOVRCDisBattFetMask : public Mask {
    static inline const uint8_t CHARGER_CONTROLLED = BITS_NONE;
    static inline const uint8_t NOT_TURNED_OFF_BY_OVC = BITS_3;
    BOVRCDisBattFetMask(uint8_t mask) : Mask(mask) {}
  };
  struct BattFetOCMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t _2_2A = BITS_4;
    static inline const uint8_t _2_8A = BITS_5;
    static inline const uint8_t _3_2A = BITS_5_4;
    BattFetOCMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdTimeMask : public Mask {
    static inline const uint8_t _80s = BITS_NONE;
    static inline const uint8_t _32s = BITS_6;
    WdTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct BOVRCNoVBusMask : public Mask {
    static inline const uint8_t ENABLED = BITS_7;
    static inline const uint8_t DISABLED = BITS_NONE;
    BOVRCNoVBusMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const WdtClrMask kWdtClrMask{BITS_1_0};
  static inline const WdBattFetOffMask kWdBattFetOffMask{BITS_2};
  static inline const BOVRCDisBattFetMask kBOVRCDisBattFetMask{BITS_3};
  static inline const BattFetOCMask kBattFetOCMask{BITS_5_4};
  static inline const WdTimeMask kWdTimeMask{BITS_6};
  static inline const BOVRCNoVBusMask kBOVRCNoVBusMask{BITS_7};

  BatfetCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x11 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC