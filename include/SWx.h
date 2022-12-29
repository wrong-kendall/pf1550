#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
namespace SWx {
/**/
struct OtpSWxDvsSelEnVolt {
  static inline const uint8_t _0_6000 = BITS_NONE;
  static inline const uint8_t _0_6125 = BITS_0;
  static inline const uint8_t _0_6250 = BITS_1;
  static inline const uint8_t _0_6375 = BITS_1_0;
  static inline const uint8_t _0_6500 = BITS_2;
  static inline const uint8_t _0_6625 = BITS_2_0;
  static inline const uint8_t _0_6750 = BITS_2_1;
  static inline const uint8_t _0_6875 = BITS_2_1_0;
  static inline const uint8_t _0_7000 = BITS_3;
  static inline const uint8_t _0_7125 = BITS_3_0;
  static inline const uint8_t _0_7250 = BITS_3_1;
  static inline const uint8_t _0_7375 = BITS_3_1_0;
  static inline const uint8_t _0_7500 = BITS_3_2;
  static inline const uint8_t _0_7625 = BITS_3_2_0;
  static inline const uint8_t _0_7750 = BITS_3_2_1;
  static inline const uint8_t _0_7875 = BITS_3_2_1_0;
  static inline const uint8_t _0_8000 = BITS_4;
  static inline const uint8_t _0_8125 = BITS_4_0;
  static inline const uint8_t _0_8250 = BITS_4_1;
  static inline const uint8_t _0_8375 = BITS_4_1_0;
  static inline const uint8_t _0_8500 = BITS_4_2;
  static inline const uint8_t _0_8625 = BITS_4_2_0;
  static inline const uint8_t _0_8750 = BITS_4_2_1;
  static inline const uint8_t _0_8875 = BITS_4_2_1_0;
  static inline const uint8_t _0_9000 = BITS_4_3;
  static inline const uint8_t _0_9125 = BITS_4_3_0;
  static inline const uint8_t _0_9250 = BITS_4_3_1;
  static inline const uint8_t _0_9375 = BITS_4_3_1_0;
  static inline const uint8_t _0_9500 = BITS_4_3_2;
  static inline const uint8_t _0_9625 = BITS_4_3_2_0;
  static inline const uint8_t _0_9750 = BITS_4_3_2_1;
  static inline const uint8_t _0_9875 = BITS_4_3_2_1_0;
  static inline const uint8_t _1_0000 = BITS_5;
  static inline const uint8_t _1_0125 = BITS_5_0;
  static inline const uint8_t _1_0250 = BITS_5_1;
  static inline const uint8_t _1_0375 = BITS_5_1_0;
  static inline const uint8_t _1_0500 = BITS_5_2;
  static inline const uint8_t _1_0625 = BITS_5_2_0;
  static inline const uint8_t _1_0750 = BITS_5_2_1;
  static inline const uint8_t _1_0875 = BITS_5_2_1_0;
  static inline const uint8_t _1_1000 = BITS_5_3;
  static inline const uint8_t _1_1125 = BITS_5_3_0;
  static inline const uint8_t _1_125 = BITS_5_3_1;
  static inline const uint8_t _1_1375 = BITS_5_3_1_0;
  static inline const uint8_t _1_1500 = BITS_5_3_2;
  static inline const uint8_t _1_1625 = BITS_5_3_2_0;
  static inline const uint8_t _1_1750 = BITS_5_3_2_1;
  static inline const uint8_t _1_1875 = BITS_5_3_2_1_0;
  static inline const uint8_t _1_2000 = BITS_5_4;
  static inline const uint8_t _1_2125 = BITS_5_4_0;
  static inline const uint8_t _1_2250 = BITS_5_4_1;
  static inline const uint8_t _1_2375 = BITS_5_4_1_0;
  static inline const uint8_t _1_2500 = BITS_5_4_2;
  static inline const uint8_t _1_2625 = BITS_5_4_2_0;
  static inline const uint8_t _1_2750 = BITS_5_4_2_1;
  static inline const uint8_t _1_2875 = BITS_5_4_2_1_0;
  static inline const uint8_t _1_3000 = BITS_5_4_3;
  static inline const uint8_t _1_3125 = BITS_5_4_3_0;
  static inline const uint8_t _1_3250 = BITS_5_4_3_1;
  static inline const uint8_t _1_3375 = BITS_5_4_3_1_0;
  static inline const uint8_t _1_3500 = BITS_5_4_3_2;
  static inline const uint8_t _1_3625 = BITS_5_4_3_2_0;
  static inline const uint8_t _1_3750 = BITS_5_4_3_2_1;
  static inline const uint8_t _1_3875 = BITS_5_4_3_2_1_0;
};

struct OtpSWxDvsSelDisVolt {
  static inline const uint8_t _1_10 = BITS_NONE;
  static inline const uint8_t _1_20 = BITS_0;
  static inline const uint8_t _1_35 = BITS_1;
  static inline const uint8_t _1_50 = BITS_1_0;
  static inline const uint8_t _1_80 = BITS_2;
  static inline const uint8_t _2_50 = BITS_2_0;
  // TODO(kendall): This is absurd. Figure this out...
  static inline const uint8_t _3_30_0 = BITS_2_1;
  static inline const uint8_t _3_30_1 = BITS_2_1_0;
  static inline const uint8_t _3_30_2 = BITS_3;
  static inline const uint8_t _3_30_3 = BITS_3_0;
  static inline const uint8_t _3_30_4 = BITS_3_1;
  static inline const uint8_t _3_30_5 = BITS_3_1_0;
  static inline const uint8_t _3_30_6 = BITS_3_2;
  static inline const uint8_t _3_30_7 = BITS_3_2_0;
  static inline const uint8_t _3_30_8 = BITS_3_2_1;
  static inline const uint8_t _3_30_9 = BITS_3_2_1_0;
  static inline const uint8_t _3_30_10 = BITS_4;
  static inline const uint8_t _3_30_11 = BITS_4_0;
  static inline const uint8_t _3_30_12 = BITS_4_1;
  static inline const uint8_t _3_30_13 = BITS_4_1_0;
  static inline const uint8_t _3_30_14 = BITS_4_2;
  static inline const uint8_t _3_30_15 = BITS_4_2_0;
  static inline const uint8_t _3_30_16 = BITS_4_2_1;
  static inline const uint8_t _3_30_17 = BITS_4_2_1_0;
  static inline const uint8_t _3_30_18 = BITS_4_3;
  static inline const uint8_t _3_30_19 = BITS_4_3_0;
  static inline const uint8_t _3_30_20 = BITS_4_3_1;
  static inline const uint8_t _3_30_21 = BITS_4_3_1_0;
  static inline const uint8_t _3_30_22 = BITS_4_3_2;
  static inline const uint8_t _3_30_23 = BITS_4_3_2_0;
  static inline const uint8_t _3_30_24 = BITS_4_3_2_1;
  static inline const uint8_t _3_30_25 = BITS_4_3_2_1_0;
  static inline const uint8_t _3_30_26 = BITS_5;
  static inline const uint8_t _3_30_27 = BITS_5_0;
  static inline const uint8_t _3_30_28 = BITS_5_1;
  static inline const uint8_t _3_30_29 = BITS_5_1_0;
  static inline const uint8_t _3_30_30 = BITS_5_2;
  static inline const uint8_t _3_30_31 = BITS_5_2_0;
  static inline const uint8_t _3_30_32 = BITS_5_2_1;
  static inline const uint8_t _3_30_33 = BITS_5_2_1_0;
  static inline const uint8_t _3_30_34 = BITS_5_3;
  static inline const uint8_t _3_30_35 = BITS_5_3_0;
  static inline const uint8_t _3_30_36 = BITS_5_3_1;
  static inline const uint8_t _3_30_37 = BITS_5_3_1_0;
  static inline const uint8_t _3_30_38 = BITS_5_3_2;
  static inline const uint8_t _3_30_39 = BITS_5_3_2_0;
  static inline const uint8_t _3_30_40 = BITS_5_3_2_1;
  static inline const uint8_t _3_30_41 = BITS_5_3_2_1_0;
  static inline const uint8_t _3_30_42 = BITS_5_4;
  static inline const uint8_t _3_30_43 = BITS_5_4_0;
  static inline const uint8_t _3_30_44 = BITS_5_4_1;
  static inline const uint8_t _3_30_45 = BITS_5_4_1_0;
  static inline const uint8_t _3_30_46 = BITS_5_4_2;
  static inline const uint8_t _3_30_47 = BITS_5_4_2_0;
  static inline const uint8_t _3_30_48 = BITS_5_4_2_1;
  static inline const uint8_t _3_30_49 = BITS_5_4_2_1_0;
  static inline const uint8_t _3_30_50 = BITS_5_4_3;
  static inline const uint8_t _3_30_51 = BITS_5_4_3_0;
  static inline const uint8_t _3_30_52 = BITS_5_4_3_1;
  static inline const uint8_t _3_30_53 = BITS_5_4_3_1_0;
  static inline const uint8_t _3_30_54 = BITS_5_4_3_2;
  static inline const uint8_t _3_30_55 = BITS_5_4_3_2_0;
  static inline const uint8_t _3_30_56 = BITS_5_4_3_2_1;
  static inline const uint8_t _3_30_57 = BITS_5_4_3_2_1_0;
};
struct Volt : public I2CRegister {
  struct VoltMask : public Mask {
    VoltMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const VoltMask kVoltMask{BITS_5_4_3_2_1_0};
  Volt(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};

struct StbyVolt : public I2CRegister {
  struct StbyVoltMask : public Mask {
    StbyVoltMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const StbyVoltMask kStbyVoltMask{BITS_5_4_3_2_1_0};
  StbyVolt(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};
struct SlpVolt : public I2CRegister {
  struct SlpVoltMask : public Mask {
    SlpVoltMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const SlpVoltMask kSlpVoltMask{BITS_5_4_3_2_1_0};
  SlpVolt(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};

struct Ctrl : public I2CRegister {
  struct EnableMask : public Mask {
    static inline const uint8_t ENABLED = BITS_0;
    static inline const uint8_t DISABLED = BITS_NONE;
    EnableMask(uint8_t mask) : Mask(mask) {}
  };
  struct StbyMask : public Mask {
    static inline const uint8_t ENABLED = BITS_1;
    static inline const uint8_t DISABLED = BITS_NONE;
    StbyMask(uint8_t mask) : Mask(mask) {}
  };
  struct OmodeMask : public Mask {
    static inline const uint8_t ENABLED = BITS_2;
    static inline const uint8_t DISABLED = BITS_NONE;
    OmodeMask(uint8_t mask) : Mask(mask) {}
  };
  struct LPwrMask : public Mask {
    static inline const uint8_t ENABLED = BITS_3;
    static inline const uint8_t DISABLED = BITS_NONE;
    LPwrMask(uint8_t mask) : Mask(mask) {}
  };

  struct DvsSpeedMask : public Mask {
    static inline const uint8_t _12_5MV_DIV_2US = BITS_4;
    static inline const uint8_t _12_5MV_DIV_4US = BITS_NONE;
    DvsSpeedMask(uint8_t mask) : Mask(mask) {}
  };
  struct FPwmInDvsMask : public Mask {
    static inline const uint8_t FORCE = BITS_5;
    static inline const uint8_t NO_FORCE = BITS_NONE;
    FPwmInDvsMask(uint8_t mask) : Mask(mask) {}
  };
  struct FPwmMask : public Mask {
    static inline const uint8_t FPWM_ON = BITS_6;
    static inline const uint8_t NO_FPWM = BITS_NONE;
    FPwmMask(uint8_t mask) : Mask(mask) {}
  };

  struct RDisMask : public Mask {
    static inline const uint8_t ENABLED = BITS_7;
    static inline const uint8_t DISABLED = BITS_NONE;
    RDisMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const EnableMask kEnableMask{BITS_0};
  static inline const StbyMask kStbyMask{BITS_1};
  static inline const OmodeMask kOmodeMask{BITS_2};
  static inline const LPwrMask kLPwrMask{BITS_3};
  static inline const DvsSpeedMask kDvsSpeedMask{BITS_4};
  static inline const FPwmInDvsMask kFPwmInDvsMask{BITS_5};
  static inline const FPwmMask kFPwmMask{BITS_6};
  static inline const RDisMask kRDisMask{BITS_7};
  Ctrl(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
  void Enable();
  void Disable();
  void StbyEnable();
  void StbyDisable();
  void OmodeEnable();
  void OmodeDisable();
  void LPwrEnable();
  void LPwrDisable();
  void DvsSpeed2us();
  void DvsSpeed4us();
  void FPwmInDvsForce();
  void FPwmInDvsNoForce();
  void FPwmEnable();
  void FPwmDisable();
  void RDisEnable();
  void RDisDisable();
};
struct Ctrl1 : public I2CRegister {
  struct ILimMask : public Mask {
    static inline const uint8_t _1A = BITS_NONE;
    static inline const uint8_t _1_2A = BITS_0;
    static inline const uint8_t _1_5A = BITS_1;
    static inline const uint8_t _2A = BITS_1_0;
    ILimMask(uint8_t mask) : Mask(mask) {}
  };
  struct TmodeMask : public Mask {
    static inline const uint8_t T_ON = BITS_4;
    static inline const uint8_t T_OFF = BITS_NONE;
    TmodeMask(uint8_t mask) : Mask(mask) {}
  };

  static const TmodeMask kTmodeMask;
  static const ILimMask kILimMask;

  Ctrl1(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};
struct PwrDnSeq : public I2CRegister {
  struct PwrDnSeqMask : public Mask {
    // TODO(kendall): Figure these out.
    PwrDnSeqMask(uint8_t mask) : Mask(mask) {}
  };
  static const PwrDnSeqMask kPwrDnSeqMask;

  PwrDnSeq(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};
}; // namespace SWx
} // namespace PMIC