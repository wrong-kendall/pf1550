#include "common_bitmasks.h"
#include <inttypes.h>

/*
struct X : public I2CRegister {
  struct YMask : public Mask {
    YMask(uint8_t mask) : Mask(mask) {}
  };
  static const YMask kYMask;
  X(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
*/

class I2CRegister {
public:
  const uint8_t kDeviceAddress;
  const uint8_t kRegisterAddress;

public:
  I2CRegister(uint8_t device_address, uint8_t register_address)
      : kDeviceAddress(device_address), kRegisterAddress(register_address) {}

  uint8_t ReadRegister() {
    return I2CRegister::ReadRegister(kDeviceAddress, kRegisterAddress);
  }

  bool WriteRegister(uint8_t data) {
    return I2CRegister::WriteRegister(kDeviceAddress, kRegisterAddress, data);
  }

  static uint8_t ReadRegister(uint8_t device_address,
                              uint8_t register_address) {
    return 0;
  }
  static bool WriteRegister(uint8_t device_address, uint8_t register_address,
                            uint8_t data) {
    return true;
  }
};

struct Mask {
  const uint8_t kMask;
  Mask(uint8_t mask) : kMask(mask) {}
};

// DeviceInfo.h
struct DeviceId : public I2CRegister {
  struct DeviceIdMask : public Mask {
    static const uint8_t kPF1550Mask;
    static const uint8_t kPF1500Mask;
    DeviceIdMask(uint8_t mask) : Mask(mask) {}
  };

  static const DeviceIdMask kDeviceIdMask;
  DeviceId(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct OTPFlavor : public I2CRegister {
  struct ModelMask : public Mask {
    static const uint8_t A0;
    static const uint8_t A1;
    static const uint8_t A2;
    static const uint8_t A3;
    static const uint8_t A4;
    static const uint8_t A5;
    static const uint8_t A6;
    static const uint8_t A7;
    static const uint8_t A8;
    static const uint8_t A9;
    ModelMask(uint8_t mask) : Mask(mask) {}
  };
  static const ModelMask kModelMask;
  OTPFlavor(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct SiliconRev : public I2CRegister {
  struct MetalLayerRevMask : public Mask {
    MetalLayerRevMask(uint8_t mask) : Mask(mask) {}
  };
  struct FullLayerRevMask : public Mask {
    FullLayerRevMask(uint8_t mask) : Mask(mask) {}
  };
  struct FabFinMask : public Mask {
    FabFinMask(uint8_t mask) : Mask(mask) {}
  };
  static const MetalLayerRevMask kMetalLayerRevMask;
  static const FullLayerRevMask kFullLayerRevMask;
  static const FabFinMask kFabFinMask;
  SiliconRev(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct StateInfo : public I2CRegister {
  struct StateMask : public Mask {
    StateMask(uint8_t mask) : Mask(mask) {}
    static const uint8_t WAIT;
    static const uint8_t RUN;
    static const uint8_t STANDBY;
    static const uint8_t SLEEP;
    static const uint8_t REG_DISABLE;
  };
  static const StateMask kStateMask;
  StateInfo(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct I2CAddr : public I2CRegister {
  struct AddrMask : public Mask {
    static const uint8_t DEFAULT;
    static const uint8_t X08;
    static const uint8_t X09;
    static const uint8_t X0A;
    static const uint8_t X0B;
    static const uint8_t X0C;
    static const uint8_t X0D;
    static const uint8_t X0E;
    static const uint8_t X0F;
    AddrMask(uint8_t mask) : Mask(mask) {}
  };
  static const AddrMask kAddrMask;
  I2CAddr(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct RC16Mhz : public I2CRegister {
  struct Req16MhzMask : public Mask {
    static const uint8_t ALWAYS_ON;
    static const uint8_t STATEMACHINE_EN;
    Req16MhzMask(uint8_t mask) : Mask(mask) {}
  };
  struct ReqAcoreOnMask : public Mask {
    static const uint8_t ALWAYS_ON;
    static const uint8_t STATEMACHINE_EN;
    ReqAcoreOnMask(uint8_t mask) : Mask(mask) {}
  };
  struct ReqAcoreHiPwrMask : public Mask {
    static const uint8_t LOW_POWER_STATEMACHINE_CONTROLLED;
    static const uint8_t LOW_POWER_NEVER;
    ReqAcoreHiPwrMask(uint8_t mask) : Mask(mask) {}
  };
  static const Req16MhzMask kReq16MhzMask;
  static const ReqAcoreOnMask kReqAcoreOnMask;
  static const ReqAcoreHiPwrMask kReqAcoreHiPwrMask;
  RC16Mhz(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
// End DeviceInfo

// Misch.h
struct IntCategory : public I2CRegister {
  struct ChgIntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t OR_BITS;
    ChgIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw1IntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    Sw1IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2IntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    Sw2IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3IntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    Sw3IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct LdoIntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    LdoIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyIntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    OnkeyIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct TempIntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    TempIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct MiscIntMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t CLEAR;
    static const uint8_t ANY;
    MiscIntMask(uint8_t mask) : Mask(mask) {}
  };
  static const ChgIntMask kChgIntMask;
  static const Sw1IntMask kSw1IntMask;
  static const Sw2IntMask kSw2IntMask;
  static const Sw3IntMask kSw3IntMask;
  static const LdoIntMask kLdoIntMask;
  static const OnkeyIntMask kOnkeyIntMask;
  static const TempIntMask kTempIntMask;
  static const MiscIntMask kMiscIntMask;
  IntCategory(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct TempIntStat0 : public I2CRegister {
  struct Therm110IMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Therm110IMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125IMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Therm125IMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110IMask kTherm110IMask;
  static const Therm125IMask kTherm125IMask;
  TempIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct TempIntMask0 : public I2CRegister {
  struct Therm110MMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Therm110MMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125MMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Therm125MMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110MMask kTherm110MMask;
  static const Therm125MMask kTherm125MMask;
  TempIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct TempIntSense0 : public I2CRegister {
  struct Therm110SMask : public Mask {
    static const uint8_t BELOW;
    static const uint8_t ABOVE;
    Therm110SMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125SMask : public Mask {
    static const uint8_t BELOW;
    static const uint8_t ABOVE;
    Therm125SMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110SMask kTherm110SMask;
  static const Therm125SMask kTherm125SMask;
  TempIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct OnkeyIntStat0 : public I2CRegister {
  struct OnkeyPushIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    OnkeyPushIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Onkey1SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Onkey2SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Onkey3SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Onkey4SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Onkey8SIMask(uint8_t mask) : Mask(mask) {}
  };
  static const OnkeyPushIMask kOnkeyPushIMask;
  static const Onkey1SIMask kOnkey1SIMask;
  static const Onkey2SIMask kOnkey2SIMask;
  static const Onkey3SIMask kOnkey3SIMask;
  static const Onkey4SIMask kOnkey4SIMask;
  static const Onkey8SIMask kOnkey8SIMask;
  OnkeyIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct OnkeyIntMask0 : public I2CRegister {
  struct OnkeyPushMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    OnkeyPushMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    Onkey1SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    Onkey2SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    Onkey3SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    Onkey4SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    Onkey8SMMask(uint8_t mask) : Mask(mask) {}
  };
  static const OnkeyPushMMask kOnkeyPushMMask;
  static const Onkey1SMMask kOnkey1SMMask;
  static const Onkey2SMMask kOnkey2SMMask;
  static const Onkey3SMMask kOnkey3SMMask;
  static const Onkey4SMMask kOnkey4SMMask;
  static const Onkey8SMMask kOnkey8SMMask;
  OnkeyIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct OnkeyIntSense0 : public I2CRegister {
  struct OnkeyPushSMask : public Mask {
    static const uint8_t PUSHED;
    static const uint8_t NOT_PUSHED;
    OnkeyPushSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SSMask : public Mask {
    static const uint8_t PUSHED;
    static const uint8_t NOT_PUSHED;
    Onkey1SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SSMask : public Mask {
    static const uint8_t PUSHED;
    static const uint8_t NOT_PUSHED;
    Onkey2SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SSMask : public Mask {
    static const uint8_t PUSHED;
    static const uint8_t NOT_PUSHED;
    Onkey3SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SSMask : public Mask {
    static const uint8_t PUSHED;
    static const uint8_t NOT_PUSHED;
    Onkey4SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SSMask : public Mask {
    static const uint8_t PUSHED;
    static const uint8_t NOT_PUSHED;
    Onkey8SSMask(uint8_t mask) : Mask(mask) {}
  };
  static const OnkeyPushSMask kOnkeyPushSMask;
  static const Onkey1SSMask kOnkey1SSMask;
  static const Onkey2SSMask kOnkey2SSMask;
  static const Onkey3SSMask kOnkey3SSMask;
  static const Onkey4SSMask kOnkey4SSMask;
  static const Onkey8SSMask kOnkey8SSMask;
  OnkeyIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct MiscIntStat0 : public I2CRegister {
  struct PwrUpIMask : public Mask {
    static const uint8_t ACTIVE;
    static const uint8_t NOT_ACTIVE;
    PwrUpIMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnIMask : public Mask {
    static const uint8_t ACTIVE;
    static const uint8_t NOT_ACTIVE;
    PwrDnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnIMask : public Mask {
    static const uint8_t ACTIVE;
    static const uint8_t NOT_ACTIVE;
    PwrOnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnIMask : public Mask {
    static const uint8_t ACTIVE;
    static const uint8_t NOT_ACTIVE;
    LowSysWarnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoIMask : public Mask {
    static const uint8_t ACTIVE;
    static const uint8_t NOT_ACTIVE;
    SysOlvoIMask(uint8_t mask) : Mask(mask) {}
  };
  static const PwrOnIMask kPwrOnIMask;
  static const PwrDnIMask kPwrDnIMask;
  static const PwrUpIMask kPwrUpIMask;
  static const LowSysWarnIMask kLowSysWarnIMask;
  static const SysOlvoIMask kSysOlvoIMask;
  MiscIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct MiscIntMask0 : public I2CRegister {
  struct PwrUpMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    PwrUpMMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    PwrDnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    PwrOnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    LowSysWarnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoMMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t REMOVED;
    SysOlvoMMask(uint8_t mask) : Mask(mask) {}
  };
  static const PwrOnMMask kPwrOnMMask;
  static const PwrDnMMask kPwrDnMMask;
  static const PwrUpMMask kPwrUpMMask;
  static const LowSysWarnMMask kLowSysWarnMMask;
  static const SysOlvoMMask kSysOlvoMMask;
  MiscIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct MiscIntSense0 : public I2CRegister {
  struct PwrUpSMask : public Mask {
    static const uint8_t IN_PROGRESS;
    static const uint8_t NOT_IN_PROGRESS;
    PwrUpSMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnSMask : public Mask {
    static const uint8_t IN_PROGRESS;
    static const uint8_t NOT_IN_PROGRESS;
    PwrDnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnSMask : public Mask {
    static const uint8_t LOW;
    static const uint8_t HIGH;
    PwrOnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnSMask : public Mask {
    static const uint8_t ABOVE;
    static const uint8_t BELOW;
    LowSysWarnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoSMask : public Mask {
    static const uint8_t ABOVE;
    static const uint8_t BELOW;
    SysOlvoSMask(uint8_t mask) : Mask(mask) {}
  };
  static const PwrOnSMask kPwrOnSMask;
  static const PwrDnSMask kPwrDnSMask;
  static const PwrUpSMask kPwrUpSMask;
  static const LowSysWarnSMask kLowSysWarnSMask;
  static const SysOlvoSMask kSysOlvoSMask;
  MiscIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct CoinCellControl : public I2CRegister {
  struct VCoinMask : public Mask {
    static const uint8_t _1_8;
    static const uint8_t _1_9;
    static const uint8_t _2_0;
    static const uint8_t _2_1;
    static const uint8_t _2_2;
    static const uint8_t _2_3;
    static const uint8_t _2_4;
    static const uint8_t _2_5;
    static const uint8_t _2_6;
    static const uint8_t _2_7;
    static const uint8_t _2_8;
    static const uint8_t _2_9;
    static const uint8_t _3_0;
    static const uint8_t _3_1;
    static const uint8_t _3_2;
    static const uint8_t _3_3;
    VCoinMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChEnMask : public Mask {
    static const uint8_t DISABLED;
    static const uint8_t ENABLED;
    ChEnMask(uint8_t mask) : Mask(mask) {}
  };
  static const VCoinMask kVCoinMask;
  static const ChEnMask kChEnMask;
  CoinCellControl(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct VSNVSCtrl : public I2CRegister {
  struct CLKPulseMask : public Mask {
    CLKPulseMask(uint8_t mask) : Mask(mask) {}
  };
  struct ForceBOSMask : public Mask {
    static const uint8_t FORCED;
    static const uint8_t ONLY_VSYS_LT_VDIV;
    ForceBOSMask(uint8_t mask) : Mask(mask) {}
  };
  struct LiBGDisMask : public Mask {
    static const uint8_t VSNVS_BAND_GAP_DISABLED;
    static const uint8_t VSNVS_BAND_GAP_ENABLED;
    LiBGDisMask(uint8_t mask) : Mask(mask) {}
  };
  static const CLKPulseMask kCLKPulseMask;
  static const ForceBOSMask kForceBOSMask;
  static const LiBGDisMask kLiBGDisMask;
  VSNVSCtrl(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct VREFDDRCtrl : public I2CRegister {
  struct VREFDDREnMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t ENABLE;
    VREFDDREnMask(uint8_t mask) : Mask(mask) {}
  };
  struct VREFDDRStbyEnMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t ENABLE;
    VREFDDRStbyEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct VREFDDROModeMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t ENABLE;
    VREFDDROModeMask(uint8_t mask) : Mask(mask) {}
  };
  struct VREFDDRLPwrMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t ENABLE;
    VREFDDRLPwrMask(uint8_t mask) : Mask(mask) {}
  };
  static const VREFDDREnMask kVREFDDREnMask;
  static const VREFDDRStbyEnMask kVREFDDRStbyEnMask;
  static const VREFDDROModeMask kVREFDDROModeMask;
  static const VREFDDRLPwrMask kVREFDDRLPwrMask;
  VREFDDRCtrl(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct VREFDDRPwrDnSeq : public I2CRegister {
  struct VREFDDRPwrDnSeqMask : public Mask {
    // TODO(kendall): Add specific masks/values.
    VREFDDRPwrDnSeqMask(uint8_t mask) : Mask(mask) {}
  };
  static const VREFDDRPwrDnSeqMask kVREFDDRPwrDnSeqMask;
  VREFDDRPwrDnSeq(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct Key1 : public I2CRegister {
  struct Key1Mask : public Mask {
    // TODO(kendall): Add specific masks/values.
    Key1Mask(uint8_t mask) : Mask(mask) {}
  };
  static const Key1Mask kKey1Mask;
  Key1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
// End Misch.h

// Charger.h
struct ChgInt : public I2CRegister {
  struct SupIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    SupIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Bat2SocIMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    BatIMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    ChgIMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    VbusIMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    VbusDpmIMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    ThmIMask(uint8_t mask) : Mask(mask) {}
  };
  static const SupIMask kSupIMask;
  static const Bat2SocIMask kBat2SocIMask;
  static const BatIMask kBatIMask;
  static const ChgIMask kChgIMask;
  static const VbusIMask kVbusIMask;
  static const VbusDpmIMask kVbusDpmIMask;
  static const ThmIMask kThmIMask;

  ChgInt(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgIntMask : public I2CRegister {
  struct SupMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    SupMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    Bat2SocMMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    BatMMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    ChgMMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    VbusMMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    VbusDpmMMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmMMask : public Mask {
    static const uint8_t MASKED;
    static const uint8_t UNMASKED;
    ThmMMask(uint8_t mask) : Mask(mask) {}
  };
  static const SupMMask kSupMMask;
  static const Bat2SocMMask kBat2SocMMask;
  static const BatMMask kBatMMask;
  static const ChgMMask kChgMMask;
  static const VbusMMask kVbusMMask;
  static const VbusDpmMMask kVbusDpmMMask;
  static const ThmMMask kThmMMask;

  ChgIntMask(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgIntOk : public I2CRegister {
  struct SupOkMask : public Mask {
    static const uint8_t DETECTED;
    static const uint8_t NOT_DETECTED;
    SupOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocOkMask : public Mask {
    static const uint8_t OVERCURRENT;
    static const uint8_t NOT_OVERCURRENT;
    Bat2SocOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatOkMask : public Mask {
    static const uint8_t BAT_OK;
    static const uint8_t BAT_ISSUE;
    BatOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgOkMask : public Mask {
    static const uint8_t CHG_OK;
    static const uint8_t NOT_CHARGING;
    ChgOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusOkMask : public Mask {
    static const uint8_t INVALID;
    static const uint8_t VALID;
    VbusOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmOkMask : public Mask {
    static const uint8_t DPM;
    static const uint8_t NO_DPM;
    VbusDpmOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmOkMask : public Mask {
    static const uint8_t WITHIN_THRESHOLD;
    static const uint8_t OUTSIDE_THRESHOLD;
    ThmOkMask(uint8_t mask) : Mask(mask) {}
  };
  static const SupOkMask kSupOkMask;
  static const Bat2SocOkMask kBat2SocOkMask;
  static const BatOkMask kBatOkMask;
  static const ChgOkMask kChgOkMask;
  static const VbusOkMask kVbusOkMask;
  static const VbusDpmOkMask kVbusDpmOkMask;
  static const ThmOkMask kThmOkMask;

  ChgIntOk(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
