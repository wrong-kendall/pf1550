#include "common_bitmasks.h"
#include <inttypes.h>
#include <tuple>

class I2CRegister {
public:
  const uint8_t kDeviceAddress;
  const uint8_t kRegisterAddress;

  uint8_t ReadRegister() {
    return I2CRegister::ReadRegister(kDeviceAddress, kRegisterAddress);
  }

  bool WriteRegister(uint8_t data) {
    return I2CRegister::WriteRegister(kDeviceAddress, kRegisterAddress, data);
  }

  inline uint8_t ReadRegister(uint8_t device_address,
                              uint8_t register_address) {
    return 0;
  }
  inline bool WriteRegister(uint8_t device_address, uint8_t register_address,
                            uint8_t data) {
    return true;
  }

public:
  I2CRegister(uint8_t device_address, uint8_t register_address)
      : kDeviceAddress(device_address), kRegisterAddress(register_address) {}
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

  // TODO(kendall): Add Family

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

struct VbusSns : public I2CRegister {
  struct VbusUvloSnsMask : public Mask {
    static const uint8_t VBUS_DETACHED;
    static const uint8_t VBUS_GT_UVLO;
    VbusUvloSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusIn2SysSnsMask : public Mask {
    static const uint8_t GT;
    static const uint8_t LT;
    VbusIn2SysSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusOvloSnsMask : public Mask {
    static const uint8_t GT;
    static const uint8_t LT;
    VbusOvloSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusValidMask : public Mask {
    static const uint8_t INVALID;
    static const uint8_t VALID;
    VbusValidMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmSnsMask : public Mask {
    static const uint8_t NOT_TRIGGERED;
    static const uint8_t TRIGGERED;
    VbusDpmSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static const VbusUvloSnsMask kVbusUvloSnsMask;
  static const VbusIn2SysSnsMask kVbusIn2SysSnsMask;
  static const VbusOvloSnsMask kVbusOvloSnsMask;
  static const VbusValidMask kVbusValidMask;
  static const VbusDpmSnsMask kVbusDpmSnsMask;

  VbusSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgSns : public I2CRegister {
  struct ChgSnsMask : public Mask {
    static const uint8_t PRECHARGE;
    static const uint8_t FAST_CHARGE_CC;
    static const uint8_t FAST_CHARGE_CV;
    static const uint8_t END_OF_CHARGE;
    static const uint8_t DONE;
    static const uint8_t TIMER_FAULT;
    static const uint8_t THERMISTOR_SUSPEND;
    static const uint8_t OFF_INVALID_OR_DISABLED;
    static const uint8_t OVERVOLTAGE;
    static const uint8_t CHG_THERMAL_OFF;
    static const uint8_t LINEAR_ONLY_NO_CHARGE;
    ChgSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdtSnsMask : public Mask {
    static const uint8_t CHG_OFF_WATCHDOG;
    static const uint8_t WATCHDOG_NOT_EXPIRED;
    WdtSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmSnsMask : public Mask {
    static const uint8_t WITHIN_THRESHOLDS;
    static const uint8_t OUTSIDE_THRESHOLDS;
    ThmSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct TregSnsMask : public Mask {
    static const uint8_t GREATER_THAN_THRESHOLD;
    static const uint8_t LESS_THAN_THRESHOLD;
    TregSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static const ChgSnsMask kChgSnsMask;
  static const WdtSnsMask kWdtSnsMask;
  static const ThmSnsMask kThmSnsMask;
  static const TregSnsMask kTregSnsMask;

  ChgSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct BattSns : public I2CRegister {
  struct BattSnsMask : public Mask {
    static const uint8_t VBUS_INVALID;
    static const uint8_t VBATT_LT_PRECHG;
    static const uint8_t CHG_SUSPENDED;
    static const uint8_t VBATT_GT_PRECHG;
    static const uint8_t OVERVOLTAGE;
    static const uint8_t NOT_DETECTED;
    BattSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct BattOCSnsMask : public Mask {
    static const uint8_t NOFAULT;
    static const uint8_t FAULT;
    BattOCSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static const BattSnsMask kBattSnsMask;
  static const BattOCSnsMask kBattOCSnsMask;

  BattSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgOper : public I2CRegister {
  struct ChgOperMask : public Mask {
    static const uint8_t CHG_OFF_LINEAR_OFF;
    static const uint8_t CHG_OFF_LINEAR_ON;
    static const uint8_t CHG_ON_LINEAR_ON;
    ChgOperMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdtEnMask : public Mask {
    static const uint8_t WATCHDOG_DISABLED;
    static const uint8_t WATCHDOG_ENABLED;
    WdtEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct DisBattFetMask : public Mask {
    static const uint8_t FET_STATEMACHINE;
    static const uint8_t FET_FORCED_OFF;
    DisBattFetMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgOperMask kChgOperMask;
  static const WdtEnMask kWdtEnMask;
  static const DisBattFetMask kDisBattFetMask;

  ChgOper(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgTmr : public I2CRegister {
  struct FChgTimeMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t _2HR;
    static const uint8_t _4HR;
    static const uint8_t _6HR;
    static const uint8_t _8HR;
    static const uint8_t _10HR;
    static const uint8_t _12HR;
    static const uint8_t _14HR;
    FChgTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct EoCTimeMask : public Mask {
    static const uint8_t _0M;
    static const uint8_t _10M;
    static const uint8_t _20M;
    static const uint8_t _30M;
    static const uint8_t _40M;
    static const uint8_t _50M;
    static const uint8_t _60M;
    static const uint8_t _70M;
    EoCTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct TPreChgMask : public Mask {
    static const uint8_t _30M;
    static const uint8_t _45M;
    TPreChgMask(uint8_t mask) : Mask(mask) {}
  };
  static const FChgTimeMask kFChgTimeMask;
  static const EoCTimeMask kEoCTimeMask;
  static const TPreChgMask kTPreChgMask;

  ChgTmr(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgEoCCnfg : public I2CRegister {
  struct ChgRestartMask : public Mask {
    static const uint8_t _100MV;
    static const uint8_t _150MV;
    static const uint8_t _200MV;
    static const uint8_t DISABLED;
    ChgRestartMask(uint8_t mask) : Mask(mask) {}
  };
  struct IEoCMask : public Mask {
    static const uint8_t _5MA;
    static const uint8_t _10MA;
    static const uint8_t _20MA;
    static const uint8_t _30MA;
    static const uint8_t _50MA;
    IEoCMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgRestartMask kChgRestartMask;
  static const IEoCMask kIEoCMask;
  ChgEoCCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgCurrCnfg : public I2CRegister {
  struct ChgCcMask : public Mask {
    static const uint8_t _100MA;
    static const uint8_t _150MA;
    static const uint8_t _200MA;
    static const uint8_t _250MA;
    static const uint8_t _300MA;
    static const uint8_t _350MA;
    static const uint8_t _400MA;
    static const uint8_t _450MA;
    static const uint8_t _500MA;
    static const uint8_t _550MA;
    static const uint8_t _600MA;
    static const uint8_t _650MA;
    static const uint8_t _700MA;
    static const uint8_t _750MA;
    static const uint8_t _800MA;
    static const uint8_t _850MA;
    static const uint8_t _900MA;
    static const uint8_t _950MA;
    static const uint8_t _1000MA;
    ChgCcMask(uint8_t mask) : Mask(mask) {}
  };
  struct PreChgLbThrsMask : public Mask {
    static const uint8_t _2_8V;
    static const uint8_t _2_7V;
    static const uint8_t _2_9V;
    static const uint8_t _3_0V;
    PreChgLbThrsMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgCcMask kChgCcMask;
  static const PreChgLbThrsMask kPreChgLbThrsMask;

  ChgCurrCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct BattReg : public I2CRegister {
  struct ChgCvMask : public Mask {
    static const uint8_t _3_50V;
    static const uint8_t _3_50V_1;
    static const uint8_t _3_50V_2;
    static const uint8_t _3_50V_3;
    static const uint8_t _3_50V_4;
    static const uint8_t _3_50V_5;
    static const uint8_t _3_50V_6;
    static const uint8_t _3_50V_7;
    static const uint8_t _3_50V_8;
    static const uint8_t _3_52V;
    static const uint8_t _3_54V;
    static const uint8_t _3_56V;
    static const uint8_t _3_58V;
    static const uint8_t _3_60V;
    static const uint8_t _3_62V;
    static const uint8_t _3_64V;
    static const uint8_t _3_66V;
    static const uint8_t _3_68V;
    static const uint8_t _3_70V;
    static const uint8_t _3_72V;
    static const uint8_t _3_74V;
    static const uint8_t _3_76V;
    static const uint8_t _3_78V;
    static const uint8_t _3_80V;
    static const uint8_t _3_82V;
    static const uint8_t _3_84V;
    static const uint8_t _3_86V;
    static const uint8_t _3_88V;
    static const uint8_t _3_90V;
    static const uint8_t _3_92V;
    static const uint8_t _3_94V;
    static const uint8_t _3_96V;
    static const uint8_t _3_98V;
    static const uint8_t _4_00V;
    static const uint8_t _4_02V;
    static const uint8_t _4_04V;
    static const uint8_t _4_06V;
    static const uint8_t _4_08V;
    static const uint8_t _4_10V;
    static const uint8_t _4_12V;
    static const uint8_t _4_14V;
    static const uint8_t _4_16V;
    static const uint8_t _4_18V;
    static const uint8_t _4_20V;
    static const uint8_t _4_22V;
    static const uint8_t _4_24V;
    static const uint8_t _4_26V;
    static const uint8_t _4_28V;
    static const uint8_t _4_30V;
    static const uint8_t _4_32V;
    static const uint8_t _4_34V;
    static const uint8_t _4_36V;
    static const uint8_t _4_38V;
    static const uint8_t _4_40V;
    static const uint8_t _4_42V;
    static const uint8_t _4_44V;
    static const uint8_t _4_44V_1;
    static const uint8_t _4_44V_2;
    static const uint8_t _4_44V_3;
    static const uint8_t _4_44V_4;
    static const uint8_t _4_44V_5;
    static const uint8_t _4_44V_6;
    static const uint8_t _4_44V_7;
    static const uint8_t _4_44V_8;
    ChgCvMask(uint8_t mask) : Mask(mask) {}
  };
  struct VsysMinMask : public Mask {
    static const uint8_t _3_5V;
    static const uint8_t _3_7V;
    static const uint8_t _4_3V;
    VsysMinMask(uint8_t mask) : Mask(mask) {}
  };
  static const ChgCvMask kChgCvMask;
  static const VsysMinMask kVsysMinMask;

  BattReg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct BattFetCnfg : public I2CRegister {
  struct WdtClrMask : public Mask {
    static const uint8_t NOT_CLEARED;
    static const uint8_t CLEARED;
    static const uint8_t NOT_CLEARED_1;
    static const uint8_t NOT_CLEARED_2;
    WdtClrMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdBattFetOffMask : public Mask {
    WdBattFetOffMask(uint8_t mask) : Mask(mask) {}
  };
  struct BOVRCDisBattFetMask : public Mask {
    static const uint8_t CHARGER_CONTROLLED;
    static const uint8_t NOT_TURNED_OFF_BY_OVC;
    BOVRCDisBattFetMask(uint8_t mask) : Mask(mask) {}
  };
  struct BattFetOCMask : public Mask {
    static const uint8_t DISABLED;
    static const uint8_t _2_2A;
    static const uint8_t _2_8A;
    static const uint8_t _3_2A;
    BattFetOCMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdTimeMask : public Mask {
    static const uint8_t _80s;
    static const uint8_t _32s;
    WdTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct BOVRCNoVBusMask : public Mask {
    static const uint8_t ENABLED;
    static const uint8_t DISABLED;
    BOVRCNoVBusMask(uint8_t mask) : Mask(mask) {}
  };
  static const WdtClrMask kWdtClrMask;
  static const WdBattFetOffMask kWdBattFetOffMask;
  static const BOVRCDisBattFetMask kBOVRCDisBattFetMask;
  static const BattFetOCMask kBattFetOCMask;
  static const WdTimeMask kWdTimeMask;
  static const BOVRCNoVBusMask kBOVRCNoVBusMask;

  BattFetCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ThmRegCnfg : public I2CRegister {
  struct ThmCnfgMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t THM_DOES_NOT_CONTROL;
    static const uint8_t THM_CONTROLS;
    static const uint8_t JEITA1;
    static const uint8_t JEITA2;
    ThmCnfgMask(uint8_t mask) : Mask(mask) {}
  };
  struct RegTempMask : public Mask {
    static const uint8_t _80C;
    static const uint8_t _95C;
    static const uint8_t _110C;
    static const uint8_t _125C;
    RegTempMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmColdMask : public Mask {
    static const uint8_t _MINUS_10C;
    static const uint8_t _0C;
    ThmColdMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmHotMask : public Mask {
    static const uint8_t _55C;
    static const uint8_t _60C;
    ThmHotMask(uint8_t mask) : Mask(mask) {}
  };
  struct TempFbEnMask : public Mask {
    static const uint8_t DISABLED;
    static const uint8_t ENABLED;
    TempFbEnMask(uint8_t mask) : Mask(mask) {}
  };

  static const ThmCnfgMask kThmCnfgMask;
  static const RegTempMask kRegTempMask;
  static const ThmColdMask kThmColdMask;
  static const ThmHotMask kThmHotMask;
  static const TempFbEnMask kTempFbEnMask;
  ThmRegCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct VbusInLimCnfg : public I2CRegister {
  struct VbusLinILimMask : public Mask {
    static const uint8_t _10MA;
    static const uint8_t _15MA;
    static const uint8_t _20MA;
    static const uint8_t _25MA;
    static const uint8_t _30MA;
    static const uint8_t _35MA;
    static const uint8_t _40MA;
    static const uint8_t _45MA;
    static const uint8_t _50MA;
    static const uint8_t _100MA;
    static const uint8_t _150MA;
    static const uint8_t _200MA;
    static const uint8_t _300MA;
    static const uint8_t _400MA;
    static const uint8_t _500MA;
    static const uint8_t _600MA;
    static const uint8_t _700MA;
    static const uint8_t _800MA;
    static const uint8_t _900MA;
    static const uint8_t _1000MA;
    static const uint8_t _1500MA;
    VbusLinILimMask(uint8_t mask) : Mask(mask) {}
  };
  static const VbusLinILimMask kVbusLinILimMask;
  VbusInLimCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct VbusLinDpm : public I2CRegister {
  struct VbusDpmRegMask : public Mask {
    static const uint8_t _3_9V;
    static const uint8_t _4_0V;
    static const uint8_t _4_1V;
    static const uint8_t _4_2V;
    static const uint8_t _4_3V;
    static const uint8_t _4_4V;
    static const uint8_t _4_5V;
    static const uint8_t _4_6V;
    VbusDpmRegMask(uint8_t mask) : Mask(mask) {}
  };
  struct PreChgdBattThrshMask : public Mask {
    PreChgdBattThrshMask(uint8_t mask) : Mask(mask) {}
  };
  struct VinDpmStopMask : public Mask {
    static const uint8_t _200MV;
    static const uint8_t _250MV;
    VinDpmStopMask(uint8_t mask) : Mask(mask) {}
  };
  struct FetScaleMask : public Mask {
    FetScaleMask(uint8_t mask) : Mask(mask) {}
  };

  static const VbusDpmRegMask kVbusDpmRegMask;
  static const PreChgdBattThrshMask kPreChgdBattThrshMask;
  static const VinDpmStopMask kVinDpmStopMask;
  static const FetScaleMask kFetScaleMask;

  VbusLinDpm(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct UsbPhyLdoCnfg : public I2CRegister {
  struct ActDisPhyMask : public Mask {
    static const uint8_t NO_DISCHARGE;
    static const uint8_t DISCHARGE;
    ActDisPhyMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyMask : public Mask {
    static const uint8_t _3_3V;
    static const uint8_t _4_9V;
    UsbPhyMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyLdoMask : public Mask {
    static const uint8_t DISABLED;
    static const uint8_t ENABLED;
    UsbPhyLdoMask(uint8_t mask) : Mask(mask) {}
  };

  static const ActDisPhyMask kActDisPhyMask;
  static const UsbPhyMask kUsbPhyMask;
  static const UsbPhyLdoMask kUsbPhyLdoMask;

private:
  static const uint8_t kRegister;
};
struct DbncDelayTime : public I2CRegister {
  struct VbusOvTdbMask : public Mask {
    static const uint8_t _10US;
    static const uint8_t _100US;
    static const uint8_t _1MS;
    static const uint8_t _10MS;
    VbusOvTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyTdbMask : public Mask {
    static const uint8_t _0MS;
    static const uint8_t _16MS;
    static const uint8_t _32MS;
    UsbPhyTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysWkUpDlyMask : public Mask {
    static const uint8_t _8MS;
    static const uint8_t _16MS;
    static const uint8_t _32MS;
    static const uint8_t _100MS;
    SysWkUpDlyMask(uint8_t mask) : Mask(mask) {}
  };

  static const VbusOvTdbMask kVbusOvTdbMask;
  static const UsbPhyTdbMask kUsbPhyTdbMask;
  static const SysWkUpDlyMask kSysWkUpDlyMask;

  DbncDelayTime(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct ChgIntCnfg : public I2CRegister {
  struct ChgIntGenMask : public Mask {
    static const uint8_t INT_ONLY_FC_TO_CV;
    static const uint8_t INT_ON_TRANSITION;
    ChgIntGenMask(uint8_t mask) : Mask(mask) {}
  };
  struct EoCIntMask : public Mask {
    static const uint8_t NO_EOC_INT;
    static const uint8_t EOC_INT;
    EoCIntMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgIntGenMask kChgIntGenMask;
  static const EoCIntMask kEoCIntMask;
  ChgIntCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct ThmAdjSetting : public I2CRegister {
  struct ThmWarmMask : public Mask {
    static const uint8_t _45C;
    static const uint8_t _50C;
    ThmWarmMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmCoolMask : public Mask {
    static const uint8_t _15C;
    static const uint8_t _10C;
    ThmCoolMask(uint8_t mask) : Mask(mask) {}
  };
  struct CvAdjMask : public Mask {
    static const uint8_t _60MV;
    static const uint8_t _100MV;
    static const uint8_t _160MV;
    static const uint8_t _200MV;
    CvAdjMask(uint8_t mask) : Mask(mask) {}
  };
  struct CcAdjMask : public Mask {
    static const uint8_t MASK;
    static const uint8_t _25PCT;
    static const uint8_t _50PCT;
    static const uint8_t _75PCT;
    static const uint8_t _100PCT;
    CcAdjMask(uint8_t mask) : Mask(mask) {}
  };
  static const ThmWarmMask kThmWarmMask;
  static const ThmCoolMask kThmCoolMask;
  static const CvAdjMask kCvAdjMask;
  static const CcAdjMask kCcAdjMask;

  ThmAdjSetting(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct Vbus2SysCnfg : public I2CRegister {
  struct Vbus2SysTdbMask : public Mask {
    static const uint8_t _100US;
    static const uint8_t _1MS;
    static const uint8_t _10MS;
    Vbus2SysTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct Vbus2SysThrshMask : public Mask {
    static const uint8_t _50MV;
    static const uint8_t _175MV;
    Vbus2SysThrshMask(uint8_t mask) : Mask(mask) {}
  };

  static const Vbus2SysTdbMask kVbus2SysTdbMask;
  static const Vbus2SysThrshMask kVbus2SysThrshMask;

  Vbus2SysCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct LedPwm : public I2CRegister {
  struct LedPwmMask : public Mask {
    static const uint8_t _0_32;
    static const uint8_t _1_32;
    static const uint8_t _2_32;
    static const uint8_t _3_32;
    static const uint8_t _4_32;
    static const uint8_t _5_32;
    static const uint8_t _6_32;
    static const uint8_t _7_32;
    static const uint8_t _8_32;
    static const uint8_t _9_32;
    static const uint8_t _10_32;
    static const uint8_t _11_32;
    static const uint8_t _12_32;
    static const uint8_t _13_32;
    static const uint8_t _14_32;
    static const uint8_t _15_32;
    static const uint8_t _16_32;
    static const uint8_t _17_32;
    static const uint8_t _18_32;
    static const uint8_t _19_32;
    static const uint8_t _20_32;
    static const uint8_t _21_32;
    static const uint8_t _22_32;
    static const uint8_t _23_32;
    static const uint8_t _24_32;
    static const uint8_t _25_32;
    static const uint8_t _26_32;
    static const uint8_t _27_32;
    static const uint8_t _28_32;
    static const uint8_t _29_32;
    static const uint8_t _30_32;
    static const uint8_t _31_32;
    LedPwmMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedRampMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t ENABLE;
    LedRampMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedEnMask : public Mask {
    static const uint8_t DISABLE;
    static const uint8_t ENABLE;
    LedEnMask(uint8_t mask) : Mask(mask) {}
  };

  static const LedPwmMask kLedPwmMask;
  static const LedRampMask kLedRampMask;
  static const LedEnMask kLedEnMask;
  LedPwm(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct FaultBatFetCnfg : I2CRegister {
  struct WdFltBfFetEnMask : public Mask {
    static const uint8_t OPENED;
    static const uint8_t CLOSED;
    WdFltBfFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmSusBFetEnMask : public Mask {
    static const uint8_t OPENED;
    static const uint8_t CLOSED;
    ThmSusBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct TShdnBFetEnMask : public Mask {
    static const uint8_t OPENED;
    static const uint8_t CLOSED;
    TShdnBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct TmrFltBFetEnMask : public Mask {
    static const uint8_t OPENED;
    static const uint8_t CLOSED;
    TmrFltBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  static const WdFltBfFetEnMask kWdFltBfFetEnMask;
  static const ThmSusBFetEnMask kThmSusBFetEnMask;
  static const TShdnBFetEnMask kTShdnBFetEnMask;
  static const TmrFltBFetEnMask kTmrFltBFetEnMask;

  FaultBatFetCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct LedCnfg : public I2CRegister {
  struct LedFreqMask : public Mask {
    static const uint8_t _1HZ;
    static const uint8_t _0_5HZ;
    static const uint8_t _256HZ;
    static const uint8_t _8HZ;
    LedFreqMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedCurrentMask : public Mask {
    static const uint8_t _6MA;
    LedCurrentMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedCfgMask : public Mask {
    static const uint8_t CHG_ON_FAULT_FLASH;
    static const uint8_t CHG_FLASH_FAULT_ON;
    LedCfgMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedOvrdMask : public Mask {
    static const uint8_t STATEMACHINE_CONTROLLED;
    static const uint8_t SOFTWARE_CONTROLLED;
    LedOvrdMask(uint8_t mask) : Mask(mask) {}
  };

  static const LedOvrdMask kLedOvrdMask;
  static const LedFreqMask kLedFreqMask;
  static const LedCurrentMask kLedCurrentMask;
  static const LedCfgMask kLedCfgMask;

  LedCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

// Pwrctrl.h
struct Pwrctrl0 : public I2CRegister {
  struct StandbyDlyMask : public Mask {
    static const uint8_t NO_DELAY;
    // TODO(kendall): WTF? these don't make sense
    static const uint8_t _1_32KHZ_DELAY;
    static const uint8_t _2_32KHZ_DELAY;
    static const uint8_t _3_32KHZ_DELAY;
    StandbyDlyMask(uint8_t mask) : Mask(mask) {}
  };
  struct StandbyInvMask : public Mask {
    static const uint8_t ACTIVE_HIGH;
    static const uint8_t ACTIVE_LOW;
    StandbyInvMask(uint8_t mask) : Mask(mask) {}
  };
  struct PoRDlyMask : public Mask {
    static const uint8_t RESETBMCU_DELAY_2MS;
    static const uint8_t RESETBMCU_DELAY_4MS;
    static const uint8_t RESETBMCU_DELAY_8MS;
    static const uint8_t RESETBMCU_DELAY_16MS;
    static const uint8_t RESETBMCU_DELAY_128MS;
    static const uint8_t RESETBMCU_DELAY_256MS;
    static const uint8_t RESETBMCU_DELAY_1024MS;
    PoRDlyMask(uint8_t mask) : Mask(mask) {}
  };
  struct TgResetMask : public Mask {
    static const uint8_t _4S;
    static const uint8_t _8S;
    static const uint8_t _12S;
    static const uint8_t _16S;
    TgResetMask(uint8_t mask) : Mask(mask) {}
  };

  static const StandbyDlyMask kStandbyDlyMask;
  static const StandbyInvMask kStandbyInvMask;
  static const PoRDlyMask kPoRDlyMask;
  static const TgResetMask kTgResetMask;

  Pwrctrl0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct Pwrctrl1 : public I2CRegister {
  struct PwronDbncMask : public Mask {
    // TODO(knedall): WTF? the first 2 are duplicated
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_1;
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_2;
    static const uint8_t _125MS_FALL_31_25MS_RISE;
    static const uint8_t _750MS_FALL_31_25MS_RISE;
    PwronDbncMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyBbncMask : public Mask {
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_1;
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_2;
    static const uint8_t _125MS_FALL_31_25MS_RISE;
    static const uint8_t _750MS_FALL_31_25MS_RISE;
    OnkeyBbncMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwronRstEnMask : public Mask {
    static const uint8_t LONG_PRESS_SLEEP_OR_REGS_DISABLE;
    static const uint8_t LONG_PRESS_NO_SLEEP_OR_REGS_DISABLE;
    PwronRstEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct RestartEnMask : public Mask {
    static const uint8_t RESTART_AFTER_5S;
    static const uint8_t NO_EFFECT;
    RestartEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct RegScpEnMask : public Mask {
    static const uint8_t SHUTDOWN_LDO_ON_CURRENT_LIMIT_FAULT;
    static const uint8_t NO_SHUTDOWN_LDO_ON_CURRENT_LIMIT_FAULT;
    RegScpEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyRstEnmask : public Mask {
    static const uint8_t ONKEY_RESET;
    static const uint8_t NO_ONKEY_RESET;
    OnkeyRstEnmask(uint8_t mask) : Mask(mask) {}
  };
  static const PwronDbncMask kPwronDbncMask;
  static const OnkeyBbncMask kOnkeyBbncMask;
  static const PwronRstEnMask kPwronRstEnMask;
  static const RestartEnMask kRestartEnMask;
  static const RegScpEnMask kRegScpEnMask;
  static const OnkeyRstEnmask kOnkeyRstEnmask;
  Pwrctrl1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct Pwrctrl2 : public I2CRegister {
  struct UvdetMask : public Mask {
    static const uint8_t _2_65_RISE_2_55_FALL;
    static const uint8_t _2_8_RISE_2_7_FALL;
    static const uint8_t _3_0_RISE_2_9_FALL;
    static const uint8_t _3_1_RISE_3_0_FALL;
    UvdetMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnMask : public Mask {
    static const uint8_t _3_3_RISE_3_1_FALL;
    static const uint8_t _3_5_RISE_3_3_FALL;
    static const uint8_t _3_7_RISE_3_5_FALL;
    static const uint8_t _3_9_RISE_3_7_FALL;
    LowSysWarnMask(uint8_t mask) : Mask(mask) {}
  };

  static const LowSysWarnMask kLowSysWarnMask;
  static const UvdetMask kUvdetMask;

  Pwrctrl2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct Pwrctrl3 : public I2CRegister {
  struct GotoShipMask : public Mask {
    static const uint8_t GOTO_SHIP_EN;
    GotoShipMask(uint8_t mask) : Mask(mask) {}
  };
  struct CoreOffMask : public Mask {
    static const uint8_t CORE_OFF_EN;
    CoreOffMask(uint8_t mask) : Mask(mask) {}
  };

  static const GotoShipMask kGotoShipMask;
  static const CoreOffMask kCoreOffMask;

  Pwrctrl3(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
// End of pwrctrl.h

// LDOy.h
struct LdoIntStat0 : public I2CRegister {
  struct Ldo1FaultIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Ldo1FaultIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Ldo2FaultIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultIMask : public Mask {
    static const uint8_t CLEARED;
    static const uint8_t ACTIVE;
    Ldo3FaultIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Ldo1FaultIMask kLdo1FaultIMask;
  static const Ldo2FaultIMask kLdo2FaultIMask;
  static const Ldo3FaultIMask kLdo3FaultIMask;

  LdoIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct LdoIntMask0 : public I2CRegister {
  struct Ldo1FaultMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Ldo1FaultMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Ldo2FaultMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Ldo3FaultMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Ldo1FaultMMask kLdo1FaultMMask;
  static const Ldo2FaultMMask kLdo2FaultMMask;
  static const Ldo3FaultMMask kLdo3FaultMMask;

  LdoIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct LdoIntSense0 : public I2CRegister {
  struct Ldo1FaultSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Ldo1FaultSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Ldo2FaultSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Ldo3FaultSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Ldo1FaultSMask kLdo1FaultSMask;
  static const Ldo2FaultSMask kLdo2FaultSMask;
  static const Ldo3FaultSMask kLdo3FaultSMask;

  LdoIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct LDOy {
  struct Volt : public I2CRegister {
    struct VoltMask : public Mask {
      static const uint8_t MASK;
      static const uint8_t _0_75;
      static const uint8_t _0_80;
      static const uint8_t _0_85;
      static const uint8_t _0_90;
      static const uint8_t _0_95;
      static const uint8_t _1_00;
      static const uint8_t _1_05;
      static const uint8_t _1_10;
      static const uint8_t _1_15;
      static const uint8_t _1_20;
      static const uint8_t _1_25;
      static const uint8_t _1_30;
      static const uint8_t _1_35;
      static const uint8_t _1_40;
      static const uint8_t _1_45;
      static const uint8_t _1_50;
      static const uint8_t _1_80;
      static const uint8_t _1_90;
      static const uint8_t _2_00;
      static const uint8_t _2_10;
      static const uint8_t _2_20;
      static const uint8_t _2_30;
      static const uint8_t _2_40;
      static const uint8_t _2_50;
      static const uint8_t _2_60;
      static const uint8_t _2_70;
      static const uint8_t _2_80;
      static const uint8_t _2_90;
      static const uint8_t _3_00;
      static const uint8_t _3_10;
      static const uint8_t _3_20;
      static const uint8_t _3_30;
      VoltMask(uint8_t mask) : Mask(mask) {}
    };

    static const VoltMask kVoltMask;
    Volt(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
  struct Ctrl : public I2CRegister {
    struct EnableMask : public Mask {
      static const uint8_t MASK;
      static const uint8_t ENABLED;
      EnableMask(uint8_t mask) : Mask(mask) {}
    };
    struct StbyMask : public Mask {
      static const uint8_t MASK;
      static const uint8_t ENABLED;
      StbyMask(uint8_t mask) : Mask(mask) {}
    };
    struct OmodeMask : public Mask {
      static const uint8_t MASK;
      static const uint8_t ENABLED;
      OmodeMask(uint8_t mask) : Mask(mask) {}
    };
    struct LPwrMask : public Mask {
      static const uint8_t MASK;
      static const uint8_t IN_SLP_AND_STBY;
      static const uint8_t NOT_IN_SLP_AND_STBY;
      LPwrMask(uint8_t mask) : Mask(mask) {}
    };
    struct LsMask : public Mask {
      static const uint8_t MASK;
      static const uint8_t SWITCH_MODE;
      static const uint8_t LDO_MODE;
      LsMask(uint8_t mask) : Mask(mask) {}
    };

    static const EnableMask kEnableMask;
    static const StbyMask kStbyMask;
    static const OmodeMask kOmodeMask;
    static const LPwrMask kLPwrMask;
    static const LsMask kLsMask;

    Ctrl(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
  struct PwrDnSeq : public I2CRegister {
    struct PwrDnSeqMask : public Mask {
      static const uint8_t MASK;
      PwrDnSeqMask(uint8_t mask) : Mask(mask) {}
    };

    static const PwrDnSeqMask kPwrDnSeqMask;
    PwrDnSeq(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
};
// end of LDOy.h
// Swx.h

struct SwIntStat0 : public I2CRegister {
  struct Sw1LsIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw1LsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw2LsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw3LsIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1LsIMask kSw1LsIMask;
  static const Sw2LsIMask kSw2LsIMask;
  static const Sw3LsIMask kSw3LsIMask;

  SwIntStat0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntMask0 : public I2CRegister {
  struct Sw1LsMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw1LsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw2LsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw3LsMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1LsMMask kSw1LsMMask;
  static const Sw2LsMMask kSw2LsMMask;
  static const Sw3LsMMask kSw3LsMMask;

  SwIntMask0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntSense0 : public I2CRegister {
  struct Sw1LsSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Sw1LsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Sw2LsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Sw3LsSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1LsSMask kSw1LsSMask;
  static const Sw2LsSMask kSw2LsSMask;
  static const Sw3LsSMask kSw3LsSMask;

  SwIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntStat1 : public I2CRegister {
  struct Sw1HsIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw1HsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw2HsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw3HsIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1HsIMask kSw1HsIMask;
  static const Sw2HsIMask kSw2HsIMask;
  static const Sw3HsIMask kSw3HsIMask;

  SwIntStat1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntMask1 : public I2CRegister {
  struct Sw1HsMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw1HsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw2HsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw3HsMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1HsMMask kSw1HsMMask;
  static const Sw2HsMMask kSw2HsMMask;
  static const Sw3HsMMask kSw3HsMMask;

  SwIntMask1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntSense1 : public I2CRegister {
  struct Sw1HsSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Sw1HsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Sw2HsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsSMask : public Mask {
    static const uint8_t FAULT_REMOVED;
    static const uint8_t FAULT_EXISTS;
    Sw3HsSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1HsSMask kSw1HsSMask;
  static const Sw2HsSMask kSw2HsSMask;
  static const Sw3HsSMask kSw3HsSMask;

  SwIntSense1(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct SwIntStat2 : public I2CRegister {
  struct Sw1DvsDoneIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw1DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw2DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneIMask : public Mask {
    static const uint8_t CLEAR;
    static const uint8_t INT;
    Sw3DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1DvsDoneIMask kSw1DvsDoneIMask;
  static const Sw2DvsDoneIMask kSw2DvsDoneIMask;
  static const Sw3DvsDoneIMask kSw3DvsDoneIMask;

  SwIntStat2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntMask2 : public I2CRegister {
  struct Sw1DvsDoneMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw1DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw2DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneMMask : public Mask {
    static const uint8_t REMOVED;
    static const uint8_t ENABLED;
    Sw3DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1DvsDoneMMask kSw1DvsDoneMMask;
  static const Sw2DvsDoneMMask kSw2DvsDoneMMask;
  static const Sw3DvsDoneMMask kSw3DvsDoneMMask;

  SwIntMask2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};
struct SwIntSense2 : public I2CRegister {
  struct Sw1DvsDoneSMask : public Mask {
    static const uint8_t NOT_IN_PROGRESS;
    static const uint8_t IN_PROGRESS;
    Sw1DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneSMask : public Mask {
    static const uint8_t NOT_IN_PROGRESS;
    static const uint8_t IN_PROGRESS;
    Sw2DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneSMask : public Mask {
    static const uint8_t NOT_IN_PROGRESS;
    static const uint8_t IN_PROGRESS;
    Sw3DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1DvsDoneSMask kSw1DvsDoneSMask;
  static const Sw2DvsDoneSMask kSw2DvsDoneSMask;
  static const Sw3DvsDoneSMask kSw3DvsDoneSMask;

  SwIntSense2(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};

struct SWx {
  struct OtpSWxDvsSelEnVolt {
    static const uint8_t _0_6000;
    static const uint8_t _0_6125;
    static const uint8_t _0_6250;
    static const uint8_t _0_6375;
    static const uint8_t _0_6500;
    static const uint8_t _0_6625;
    static const uint8_t _0_6750;
    static const uint8_t _0_6875;
    static const uint8_t _0_7000;
    static const uint8_t _0_7125;
    static const uint8_t _0_7250;
    static const uint8_t _0_7375;
    static const uint8_t _0_7500;
    static const uint8_t _0_7625;
    static const uint8_t _0_7750;
    static const uint8_t _0_7875;
    static const uint8_t _0_8000;
    static const uint8_t _0_8125;
    static const uint8_t _0_8250;
    static const uint8_t _0_8375;
    static const uint8_t _0_8500;
    static const uint8_t _0_8625;
    static const uint8_t _0_8750;
    static const uint8_t _0_8875;
    static const uint8_t _0_9000;
    static const uint8_t _0_9125;
    static const uint8_t _0_9250;
    static const uint8_t _0_9375;
    static const uint8_t _0_9500;
    static const uint8_t _0_9625;
    static const uint8_t _0_9750;
    static const uint8_t _0_9875;
    static const uint8_t _1_0000;
    static const uint8_t _1_0125;
    static const uint8_t _1_0250;
    static const uint8_t _1_0375;
    static const uint8_t _1_0500;
    static const uint8_t _1_0625;
    static const uint8_t _1_0750;
    static const uint8_t _1_0875;
    static const uint8_t _1_1000;
    static const uint8_t _1_1125;
    static const uint8_t _1_125;
    static const uint8_t _1_1375;
    static const uint8_t _1_1500;
    static const uint8_t _1_1625;
    static const uint8_t _1_1750;
    static const uint8_t _1_1875;
    static const uint8_t _1_2000;
    static const uint8_t _1_2125;
    static const uint8_t _1_2250;
    static const uint8_t _1_2375;
    static const uint8_t _1_2500;
    static const uint8_t _1_2625;
    static const uint8_t _1_2750;
    static const uint8_t _1_2875;
    static const uint8_t _1_3000;
    static const uint8_t _1_3125;
    static const uint8_t _1_3250;
    static const uint8_t _1_3375;
    static const uint8_t _1_3500;
    static const uint8_t _1_3625;
    static const uint8_t _1_3750;
    static const uint8_t _1_3875;
  };

  struct OtpSWxDvsSelDisVolt {
    static const uint8_t _1_10;
    static const uint8_t _1_20;
    static const uint8_t _1_35;
    static const uint8_t _1_50;
    static const uint8_t _1_80;
    static const uint8_t _2_50;
    // TODO(kendall): This is absurd. Figure this out...
    static const uint8_t _3_30_0;
    static const uint8_t _3_30_1;
    static const uint8_t _3_30_2;
    static const uint8_t _3_30_3;
    static const uint8_t _3_30_4;
    static const uint8_t _3_30_5;
    static const uint8_t _3_30_6;
    static const uint8_t _3_30_7;
    static const uint8_t _3_30_8;
    static const uint8_t _3_30_9;
    static const uint8_t _3_30_10;
    static const uint8_t _3_30_11;
    static const uint8_t _3_30_12;
    static const uint8_t _3_30_13;
    static const uint8_t _3_30_14;
    static const uint8_t _3_30_15;
    static const uint8_t _3_30_16;
    static const uint8_t _3_30_17;
    static const uint8_t _3_30_18;
    static const uint8_t _3_30_19;
    static const uint8_t _3_30_20;
    static const uint8_t _3_30_21;
    static const uint8_t _3_30_22;
    static const uint8_t _3_30_23;
    static const uint8_t _3_30_24;
    static const uint8_t _3_30_25;
    static const uint8_t _3_30_26;
    static const uint8_t _3_30_27;
    static const uint8_t _3_30_28;
    static const uint8_t _3_30_29;
    static const uint8_t _3_30_30;
    static const uint8_t _3_30_31;
    static const uint8_t _3_30_32;
    static const uint8_t _3_30_33;
    static const uint8_t _3_30_34;
    static const uint8_t _3_30_35;
    static const uint8_t _3_30_36;
    static const uint8_t _3_30_37;
    static const uint8_t _3_30_38;
    static const uint8_t _3_30_39;
    static const uint8_t _3_30_40;
    static const uint8_t _3_30_41;
    static const uint8_t _3_30_42;
    static const uint8_t _3_30_43;
    static const uint8_t _3_30_44;
    static const uint8_t _3_30_45;
    static const uint8_t _3_30_46;
    static const uint8_t _3_30_47;
    static const uint8_t _3_30_48;
    static const uint8_t _3_30_49;
    static const uint8_t _3_30_50;
    static const uint8_t _3_30_51;
    static const uint8_t _3_30_52;
    static const uint8_t _3_30_53;
    static const uint8_t _3_30_54;
    static const uint8_t _3_30_55;
    static const uint8_t _3_30_56;
    static const uint8_t _3_30_57;
  };
  struct Volt : public I2CRegister {
    // TODO(kendall): I think you left off here trying to figure out how to
    // make VoltMask generic
    struct VoltMask : public Mask {
      VoltMask(uint8_t mask) : Mask(mask) {}
    };
    static const VoltMask kVoltMask;
    Volt(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };

  struct StbyVolt : public I2CRegister {
    struct StbyVoltMask : public Mask {
      StbyVoltMask(uint8_t mask) : Mask(mask) {}
    };
    static const StbyVoltMask kStbyVoltMask;
    StbyVolt(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
  struct SlpVolt : public I2CRegister {
    struct SlpVoltMask : public Mask {
      SlpVoltMask(uint8_t mask) : Mask(mask) {}
    };
    static const SlpVoltMask kSlpVoltMask;
    SlpVolt(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
  struct PwrUp : public I2CRegister {
    struct PwrUpSeqMask : public Mask {
      PwrUpSeqMask(uint8_t mask) : Mask(mask) {}
      // TODO(kendall): Figure these out
    };
    static const PwrUpSeqMask kPwrUpSeqMask;
    PwrUp(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };

  struct Ctrl : public I2CRegister {
    struct EnableMask : public Mask {
      static const uint8_t ENABLED;
      static const uint8_t DISABLED;
      EnableMask(uint8_t mask) : Mask(mask) {}
    };
    struct StbyMask : public Mask {
      static const uint8_t ENABLED;
      static const uint8_t DISABLED;
      StbyMask(uint8_t mask) : Mask(mask) {}
    };
    struct OmodeMask : public Mask {
      static const uint8_t ENABLED;
      static const uint8_t DISABLED;
      OmodeMask(uint8_t mask) : Mask(mask) {}
    };
    struct LPwrMask : public Mask {
      static const uint8_t ENABLED;
      static const uint8_t DISABLED;
      LPwrMask(uint8_t mask) : Mask(mask) {}
    };

    struct DvsSpeedMask : public Mask {
      static const uint8_t _12_5MV_DIV_2US;
      static const uint8_t _12_5MV_DIV_4US;
      DvsSpeedMask(uint8_t mask) : Mask(mask) {}
    };
    struct FPwmInDvsMask : public Mask {
      static const uint8_t FORCE;
      static const uint8_t NO_FORCE;
      FPwmInDvsMask(uint8_t mask) : Mask(mask) {}
    };
    struct FPwmMask : public Mask {
      static const uint8_t FPWM_ON;
      static const uint8_t NO_FPWM;
      FPwmMask(uint8_t mask) : Mask(mask) {}
    };

    struct RDisMask : public Mask {
      static const uint8_t ENABLED;
      static const uint8_t DISABLED;
      RDisMask(uint8_t mask) : Mask(mask) {}
    };

    static const EnableMask kEnableMask;
    static const StbyMask kStbyMask;
    static const OmodeMask kOmodeMask;
    static const LPwrMask kLPwrMask;
    static const DvsSpeedMask kDvsSpeedMask;
    static const FPwmInDvsMask kFPwmInDvsMask;
    static const FPwmMask kFPwmMask;
    static const RDisMask kRDisMask;
    Ctrl(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
  struct Ctrl1 : public I2CRegister {
    struct ILimMask : public Mask {
      static const uint8_t _1A;
      static const uint8_t _1_2A;
      static const uint8_t _1_5A;
      static const uint8_t _2A;
      ILimMask(uint8_t mask) : Mask(mask) {}
    };
    struct TmodeMask : public Mask {
      static const uint8_t T_ON;
      static const uint8_t T_OFF;
      TmodeMask(uint8_t mask) : Mask(mask) {}
    };

    static const TmodeMask kTmodeMask;
    static const ILimMask kILimMask;

    Ctrl1(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
  struct PwrDn : public I2CRegister {
    struct PwrDnSeqMask : public Mask {
      // TODO(kendall): Figure these out.
      PwrDnSeqMask(uint8_t mask) : Mask(mask) {}
    };
    static const PwrDnSeqMask kPwrDnSeqMask;

    PwrDn(uint8_t device_address, uint8_t register_address)
        : I2CRegister(device_address, register_address) {}
  };
};
// end of Swx.h

// TODO(kendall): Ask if he wants attribution
// Below is courtesy of ...
constexpr int count_first_falses() { return 0; }
template <typename... B> constexpr int count_first_falses(bool b1, B... b) {
  if (b1)
    return 0;
  else
    return 1 + count_first_falses(b...);
}

template <class... Registers> class PF1550 {
public:
  std::tuple<Registers...> registers_;
  PF1550(uint8_t device_address) : registers_(Registers(device_address)...) {}

  template <typename R> decltype(auto) get_register() {
    return std::get<count_first_falses((std::is_same<Registers, R>::value)...)>(
        registers_);
  }
  friend class PF1550Test;
};