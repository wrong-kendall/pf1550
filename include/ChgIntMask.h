#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgIntMask : public I2CRegister {
  struct SupMMask : public Mask {
    static inline const uint8_t MASKED = BITS_NONE;
    static inline const uint8_t UNMASKED = BITS_0;
    SupMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocMMask : public Mask {
    static inline const uint8_t MASKED = BITS_NONE;
    static inline const uint8_t UNMASKED = BITS_1;
    Bat2SocMMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatMMask : public Mask {
    static inline const uint8_t MASKED = BITS_NONE;
    static inline const uint8_t UNMASKED = BITS_2;
    BatMMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgMMask : public Mask {
    static inline const uint8_t MASKED = BITS_NONE;
    static inline const uint8_t UNMASKED = BITS_3;
    ChgMMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusMMask : public Mask {
    static inline const uint8_t MASKED = BITS_NONE;
    static inline const uint8_t UNMASKED = BITS_5;
    VbusMMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmMMask : public Mask {
    static inline const uint8_t MASKED = BITS_6;
    static inline const uint8_t UNMASKED = BITS_NONE;
    VbusDpmMMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmMMask : public Mask {
    static inline const uint8_t MASKED = BITS_NONE;
    static inline const uint8_t UNMASKED = BITS_7;
    ThmMMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const SupMMask kSupMMask{BITS_0};
  static inline const Bat2SocMMask kBat2SocMMask{BITS_1};
  static inline const BatMMask kBatMMask{BITS_2};
  static inline const ChgMMask kChgMMask{BITS_3};
  static inline const VbusMMask kVbusMMask{BITS_5};
  static inline const VbusDpmMMask kVbusDpmMMask{BITS_6};
  static inline const ThmMMask kThmMMask{BITS_7};

  ChgIntMask(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x02 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC