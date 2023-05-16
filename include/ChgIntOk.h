#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct ChgIntOk : public I2CRegister {
  struct SupOkMask : public Mask {
    static inline const uint8_t DETECTED = BITS_0;
    static inline const uint8_t NOT_DETECTED = BITS_NONE;
    SupOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocOkMask : public Mask {
    static inline const uint8_t OVERCURRENT = BITS_1;
    static inline const uint8_t NOT_OVERCURRENT = BITS_NONE;
    Bat2SocOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatOkMask : public Mask {
    static inline const uint8_t BAT_OK = BITS_2;
    static inline const uint8_t BAT_ISSUE = BITS_NONE;
    BatOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgOkMask : public Mask {
    static inline const uint8_t CHG_OK = BITS_3;
    static inline const uint8_t NOT_CHARGING = BITS_NONE;
    ChgOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusOkMask : public Mask {
    static inline const uint8_t INVALID = BITS_NONE;
    static inline const uint8_t VALID = BITS_5;
    VbusOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmOkMask : public Mask {
    static inline const uint8_t DPM = BITS_6;
    static inline const uint8_t NO_DPM = BITS_NONE;
    VbusDpmOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmOkMask : public Mask {
    static inline const uint8_t WITHIN_THRESHOLD = BITS_7;
    static inline const uint8_t OUTSIDE_THRESHOLD = BITS_NONE;
    ThmOkMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const SupOkMask kSupOkMask{BITS_0};
  static inline const Bat2SocOkMask kBat2SocOkMask{BITS_1};
  static inline const BatOkMask kBatOkMask{BITS_2};
  static inline const ChgOkMask kChgOkMask{BITS_3};
  static inline const VbusOkMask kVbusOkMask{BITS_5};
  static inline const VbusDpmOkMask kVbusDpmOkMask{BITS_6};
  static inline const ThmOkMask kThmOkMask{BITS_7};

  ChgIntOk(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

  bool IsCharging();

private:
  static inline const uint8_t kRegister = 0x04 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC