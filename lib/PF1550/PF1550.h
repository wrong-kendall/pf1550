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

struct _STATE_INFO {
  static const uint8_t REG = 0x67;
  static const uint8_t MASK = BITS_5_4_3_2_1_0;
  struct _STATE {
  } STATE;
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
struct _I2C_ADDR {
  static const uint8_t REG = 0x68;
  static const uint8_t MASK = BITS_2_1_0;
  struct _ADDR {
  } ADDR;
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

struct _RC_16MHZ {
  static const uint8_t REG = 0x6B;
  struct _ACORE_ON {
    static const uint8_t MASK = BITS_1;
  } ACORE_ON;
  struct _REQ_ACORE_HIPWR {
    static const uint8_t MASK = BITS_2;
    static const uint8_t LOW_POWER_STATEMACHINE_CONTROLLED = BITS_NONE;
    static const uint8_t LOW_POWER_NEVER = BITS_2;
  } REQ_ACORE_HIPWR;
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
  static const Therm125MMask kTherm125MMask;
  static const Therm110MMask kTherm110MMask;
  TempIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister;
};