#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct VbusLinDpm : public I2CRegister {
  struct VbusDpmRegMask : public Mask {
    static inline const uint8_t _3_9V = BITS_NONE;
    static inline const uint8_t _4_0V = BITS_0;
    static inline const uint8_t _4_1V = BITS_1;
    static inline const uint8_t _4_2V = BITS_1_0;
    static inline const uint8_t _4_3V = BITS_2;
    static inline const uint8_t _4_4V = BITS_2_0;
    static inline const uint8_t _4_5V = BITS_2_1;
    static inline const uint8_t _4_6V = BITS_2_1_0;
    VbusDpmRegMask(uint8_t mask) : Mask(mask) {}
  };
  struct PreChgdBattThrshMask : public Mask {
    PreChgdBattThrshMask(uint8_t mask) : Mask(mask) {}
  };
  struct VinDpmStopMask : public Mask {
    static inline const uint8_t _200MV = BITS_NONE;
    static inline const uint8_t _250MV = BITS_5;
    VinDpmStopMask(uint8_t mask) : Mask(mask) {}
  };
  struct FetScaleMask : public Mask {
    FetScaleMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const VbusDpmRegMask kVbusDpmRegMask{BITS_2_1_0};
  static inline const PreChgdBattThrshMask kPreChgdBattThrshMask{BITS_4_3};
  static inline const VinDpmStopMask kVinDpmStopMask{BITS_5};
  static inline const FetScaleMask kFetScaleMask{BITS_7};

  VbusLinDpm(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x15 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC