#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
namespace LDOy {
struct Volt : public I2CRegister {
  struct VoltMask : public Mask {
    static inline const uint8_t _0_75 = BITS_NONE;
    static inline const uint8_t _0_80 = BITS_0;
    static inline const uint8_t _0_85 = BITS_1;
    static inline const uint8_t _0_90 = BITS_1_0;
    static inline const uint8_t _0_95 = BITS_2;
    static inline const uint8_t _1_00 = BITS_2_0;
    static inline const uint8_t _1_05 = BITS_2_1;
    static inline const uint8_t _1_10 = BITS_2_1_0;
    static inline const uint8_t _1_15 = BITS_3;
    static inline const uint8_t _1_20 = BITS_3_0;
    static inline const uint8_t _1_25 = BITS_3_1;
    static inline const uint8_t _1_30 = BITS_3_1_0;
    static inline const uint8_t _1_35 = BITS_3_2;
    static inline const uint8_t _1_40 = BITS_3_2_0;
    static inline const uint8_t _1_45 = BITS_3_2_1;
    static inline const uint8_t _1_50 = BITS_3_2_1_0;
    static inline const uint8_t _1_80 = BITS_4;
    static inline const uint8_t _1_90 = BITS_4_0;
    static inline const uint8_t _2_00 = BITS_4_1;
    static inline const uint8_t _2_10 = BITS_4_1_0;
    static inline const uint8_t _2_20 = BITS_4_2;
    static inline const uint8_t _2_30 = BITS_4_2_0;
    static inline const uint8_t _2_40 = BITS_4_2_1;
    static inline const uint8_t _2_50 = BITS_4_2_1_0;
    static inline const uint8_t _2_60 = BITS_4_3;
    static inline const uint8_t _2_70 = BITS_4_3_0;
    static inline const uint8_t _2_80 = BITS_4_3_1;
    static inline const uint8_t _2_90 = BITS_4_3_1_0;
    static inline const uint8_t _3_00 = BITS_4_3_2;
    static inline const uint8_t _3_10 = BITS_4_3_2_0;
    static inline const uint8_t _3_20 = BITS_4_3_2_1;
    static inline const uint8_t _3_30 = BITS_4_3_2_1_0;
    VoltMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const VoltMask kVoltMask{BITS_4_3_2_1_0};
  Volt(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};
struct Ctrl : public I2CRegister {
  struct EnableMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_0;
    EnableMask(uint8_t mask) : Mask(mask) {}
  };
  struct StbyMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_1;
    StbyMask(uint8_t mask) : Mask(mask) {}
  };
  struct OmodeMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_2;
    OmodeMask(uint8_t mask) : Mask(mask) {}
  };
  struct LPwrMask : public Mask {
    static inline const uint8_t IN_SLP_AND_STBY = BITS_3;
    static inline const uint8_t NOT_IN_SLP_AND_STBY = BITS_NONE;
    LPwrMask(uint8_t mask) : Mask(mask) {}
  };
  struct LsMask : public Mask {
    static inline const uint8_t SWITCH_MODE = BITS_4;
    static inline const uint8_t LDO_MODE = BITS_NONE;
    LsMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const EnableMask kEnableMask{BITS_0};
  static inline const StbyMask kStbyMask{BITS_1};
  static inline const OmodeMask kOmodeMask{BITS_2};
  static inline const LPwrMask kLPwrMask{BITS_3};
  static inline const LsMask kLsMask{BITS_4};

  Ctrl(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
  void Enable();
  void Disable();
  void StbyEnable();
  void StbyDisable();
  void OmodeEnable();
  void OmodeDisable();
  void ForceLPwr();
  void DisableLPwr();
  void LdoMode();
  void SwMode();
};
struct PwrDnSeq : public I2CRegister {
  struct PwrDnSeqMask : public Mask {
    PwrDnSeqMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const PwrDnSeqMask kPwrDnSeqMask{BITS_2_1_0};
  PwrDnSeq(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};
}; // namespace LDOy
} // namespace PMIC