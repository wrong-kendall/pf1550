#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgInt : public I2CRegister {
  struct SupIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_0;
    SupIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_1;
    Bat2SocIMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_2;
    BatIMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_3;
    ChgIMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_5;
    VbusIMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_6;
    VbusDpmIMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_7;
    ThmIMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const SupIMask kSupIMask{BITS_0};
  static inline const Bat2SocIMask kBat2SocIMask{BITS_1};
  static inline const BatIMask kBatIMask{BITS_2};
  static inline const ChgIMask kChgIMask{BITS_3};
  static inline const VbusIMask kVbusIMask{BITS_5};
  static inline const VbusDpmIMask kVbusDpmIMask{BITS_6};
  static inline const ThmIMask kThmIMask{BITS_7};

  ChgInt(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x00 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC