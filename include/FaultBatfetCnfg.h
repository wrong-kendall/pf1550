#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct FaultBatfetCnfg : I2CRegister {
  struct WdFltBfFetEnMask : public Mask {
    static inline const uint8_t OPENED = BITS_NONE;
    static inline const uint8_t CLOSED = BITS_0;
    WdFltBfFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmSusBFetEnMask : public Mask {
    static inline const uint8_t OPENED = BITS_NONE;
    static inline const uint8_t CLOSED = BITS_1;
    ThmSusBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct TShdnBFetEnMask : public Mask {
    static inline const uint8_t OPENED = BITS_NONE;
    static inline const uint8_t CLOSED = BITS_2;
    TShdnBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct TmrFltBFetEnMask : public Mask {
    static inline const uint8_t OPENED = BITS_NONE;
    static inline const uint8_t CLOSED = BITS_3;
    TmrFltBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const WdFltBfFetEnMask kWdFltBfFetEnMask{BITS_0};
  static inline const ThmSusBFetEnMask kThmSusBFetEnMask{BITS_1};
  static inline const TShdnBFetEnMask kTShdnBFetEnMask{BITS_2};
  static inline const TmrFltBFetEnMask kTmrFltBFetEnMask{BITS_3};

  FaultBatfetCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x1D + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC