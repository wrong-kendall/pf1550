#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct CoincellControl : public I2CRegister {
  struct VCoinMask : public Mask {
    static inline const uint8_t _1_8 = BITS_NONE;
    static inline const uint8_t _1_9 = BITS_0;
    static inline const uint8_t _2_0 = BITS_1;
    static inline const uint8_t _2_1 = BITS_1_0;
    static inline const uint8_t _2_2 = BITS_2;
    static inline const uint8_t _2_3 = BITS_2_0;
    static inline const uint8_t _2_4 = BITS_2_1;
    static inline const uint8_t _2_5 = BITS_2_1_0;
    static inline const uint8_t _2_6 = BITS_3;
    static inline const uint8_t _2_7 = BITS_3_0;
    static inline const uint8_t _2_8 = BITS_3_1;
    static inline const uint8_t _2_9 = BITS_3_1_0;
    static inline const uint8_t _3_0 = BITS_3_2;
    static inline const uint8_t _3_1 = BITS_3_2_0;
    static inline const uint8_t _3_2 = BITS_3_2_1;
    static inline const uint8_t _3_3 = BITS_3_2_1_0;
    VCoinMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChEnMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_4;
    ChEnMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const VCoinMask kVCoinMask{BITS_3_2_1_0};
  static inline const ChEnMask kChEnMask{BITS_4};
  CoincellControl(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}
  void VCoin(uint8_t voltage);
  void ChEnable();
  void ChDisable();

private:
  static inline const uint8_t kRegister = 0x30;
};
} // namespace PMIC