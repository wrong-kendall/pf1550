#pragma once
#include "common_bitmasks.h"
#include <Arduino.h>
#include <Wire.h>
#include <tuple>

namespace PMIC {
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

  // TODO(kendall): These should be in the cpp file.
  inline uint8_t ReadRegister(uint8_t device_address,
                              uint8_t register_address) {
    Wire.beginTransmission(kDeviceAddress);
    Wire.write(kRegisterAddress);
    Wire.endTransmission(false);
    Wire.requestFrom(kDeviceAddress, 1);
    uint8_t register_data = 0;
    if (Wire.available()) {
      register_data = Wire.read();
    }
    return register_data;
  }
  inline bool WriteRegister(uint8_t device_address, uint8_t register_address,
                            uint8_t data) {
    Wire.beginTransmission(kDeviceAddress);
    Wire.write(kRegisterAddress);
    Wire.write(data);
    Wire.endTransmission();
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
    static const uint8_t kPF1550Mask = BITS_2;
    static const uint8_t kPF1500Mask = BITS_NONE;
    DeviceIdMask(uint8_t mask) : Mask(mask) {}
  };

  static const DeviceIdMask kDeviceIdMask;
  DeviceId(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

  // TODO(kendall): Add Family

private:
  static const uint8_t kRegister = 0x00;
};

struct OtpFlavor : public I2CRegister {
  struct ModelMask : public Mask {
    static const uint8_t A0 = 0x00;
    static const uint8_t A1 = 0x01;
    static const uint8_t A2 = 0x02;
    static const uint8_t A3 = 0x03;
    static const uint8_t A4 = 0x04;
    static const uint8_t A5 = 0x05;
    static const uint8_t A6 = 0x06;
    static const uint8_t A7 = 0x07;
    static const uint8_t A8 = 0x08;
    static const uint8_t A9 = 0x09;
    ModelMask(uint8_t mask) : Mask(mask) {}
  };
  static const ModelMask kModelMask;
  OtpFlavor(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x01;
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
  static const uint8_t kRegister = 0x02;
};
struct StateInfo : public I2CRegister {
  struct StateMask : public Mask {
    StateMask(uint8_t mask) : Mask(mask) {}
    static const uint8_t WAIT = BITS_NONE;
    static const uint8_t RUN = BITS_3_2;
    static const uint8_t STANDBY = BITS_3_2_0;
    static const uint8_t SLEEP = BITS_3_2_1;
    static const uint8_t REG_DISABLE = BITS_5_3_1_0;
  };
  static const StateMask kStateMask;
  StateInfo(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x67;
};
struct I2cAddr : public I2CRegister {
  struct AddrMask : public Mask {
    static const uint8_t I2C_ADDR_DEFAULT = 0x08;
    static const uint8_t X08 = BITS_NONE;
    static const uint8_t X09 = BITS_0;
    static const uint8_t X0A = BITS_1;
    static const uint8_t X0B = BITS_1_0;
    static const uint8_t X0C = BITS_2;
    static const uint8_t X0D = BITS_2_0;
    static const uint8_t X0E = BITS_2_1;
    static const uint8_t X0F = BITS_2_1_0;
    AddrMask(uint8_t mask) : Mask(mask) {}
  };
  static const AddrMask kAddrMask;
  I2cAddr(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x68;
};

struct Rc16mhz : public I2CRegister {
  struct Req16MhzMask : public Mask {
    static const uint8_t ALWAYS_ON = BITS_1;
    static const uint8_t STATEMACHINE_EN = BITS_NONE;
    Req16MhzMask(uint8_t mask) : Mask(mask) {}
  };
  struct ReqAcoreOnMask : public Mask {
    static const uint8_t ALWAYS_ON = BITS_1;
    static const uint8_t STATEMACHINE_EN = BITS_NONE;
    ReqAcoreOnMask(uint8_t mask) : Mask(mask) {}
  };
  struct ReqAcoreHiPwrMask : public Mask {
    static const uint8_t LOW_POWER_STATEMACHINE_CONTROLLED = BITS_NONE;
    static const uint8_t LOW_POWER_NEVER = BITS_2;
    ReqAcoreHiPwrMask(uint8_t mask) : Mask(mask) {}
  };
  static const Req16MhzMask kReq16MhzMask;
  static const ReqAcoreOnMask kReqAcoreOnMask;
  static const ReqAcoreHiPwrMask kReqAcoreHiPwrMask;
  Rc16mhz(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x6B;
};
// End DeviceInfo

// Misch.h
struct IntCategory : public I2CRegister {
  struct ChgIntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t OR_BITS = BITS_0;
    ChgIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw1IntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_1;
    Sw1IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2IntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_2;
    Sw2IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3IntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_3;
    Sw3IntMask(uint8_t mask) : Mask(mask) {}
  };
  struct LdoIntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_4;
    LdoIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyIntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_5;
    OnkeyIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct TempIntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_6;
    TempIntMask(uint8_t mask) : Mask(mask) {}
  };
  struct MiscIntMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t ANY = BITS_7;
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
  static const uint8_t kRegister = 0x06;
};

struct TempIntStat0 : public I2CRegister {
  struct Therm110IMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_0;
    Therm110IMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125IMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_0;
    Therm125IMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110IMask kTherm110IMask;
  static const Therm125IMask kTherm125IMask;
  TempIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x20;
};

struct TempIntMask0 : public I2CRegister {
  struct Therm110MMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    Therm110MMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125MMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    Therm125MMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110MMask kTherm110MMask;
  static const Therm125MMask kTherm125MMask;
  TempIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x21;
};

struct TempIntSense0 : public I2CRegister {
  struct Therm110SMask : public Mask {
    static const uint8_t BELOW = BITS_NONE;
    static const uint8_t ABOVE = BITS_0;
    Therm110SMask(uint8_t mask) : Mask(mask) {}
  };
  struct Therm125SMask : public Mask {
    static const uint8_t BELOW = BITS_NONE;
    static const uint8_t ABOVE = BITS_0;
    Therm125SMask(uint8_t mask) : Mask(mask) {}
  };
  static const Therm110SMask kTherm110SMask;
  static const Therm125SMask kTherm125SMask;
  TempIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x22;
};
struct OnkeyIntStat0 : public I2CRegister {
  struct OnkeyPushIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_0;
    OnkeyPushIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_1;
    Onkey1SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_2;
    Onkey2SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_3;
    Onkey3SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_4;
    Onkey4SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_5;
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

  bool AnyOnkeyActive() {
    auto register_data = ReadRegister();
    // If any bit is set, return true;
    return register_data > 0;
  }
  void ClearAllOnkey() { WriteRegister(0x0); }
  void ClearOnkeyPushI() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kOnkeyPushIMask.kMask & kOnkeyPushIMask.CLEARED));
    WriteRegister(data);
  }
  bool OnkeyPushIActive() {
    auto register_data = ReadRegister();
    return (register_data & kOnkeyPushIMask.kMask) == kOnkeyPushIMask.ACTIVE;
  }
  void ClearOnkey1SIActive() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey1SIMask.kMask & kOnkey1SIMask.CLEARED));
    WriteRegister(data);
  }
  bool Onkey1SIActive() {
    auto register_data = ReadRegister();
    return (register_data & kOnkey1SIMask.kMask) == kOnkey1SIMask.ACTIVE;
  }
  void ClearOnkey2SIActive() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey2SIMask.kMask & kOnkey2SIMask.CLEARED));
    WriteRegister(data);
  }
  bool Onkey2SIActive() {
    auto register_data = ReadRegister();
    return (register_data & kOnkey2SIMask.kMask) == kOnkey2SIMask.ACTIVE;
  }
  void ClearOnkey3SI() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey3SIMask.kMask & kOnkey3SIMask.CLEARED));
    WriteRegister(data);
  }
  bool Onkey3SIActive() {
    auto register_data = ReadRegister();
    return (register_data & kOnkey3SIMask.kMask) == kOnkey3SIMask.ACTIVE;
  }
  void ClearOnkey4SIActive() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey4SIMask.kMask & kOnkey4SIMask.CLEARED));
    WriteRegister(data);
  }
  bool Onkey4SIActive() {
    auto register_data = ReadRegister();
    return (register_data & kOnkey4SIMask.kMask) == kOnkey4SIMask.ACTIVE;
  }
  void ClearOnkey8SI() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey8SIMask.kMask & kOnkey8SIMask.CLEARED));
    WriteRegister(data);
  }
  bool Onkey8SIActive() {
    auto register_data = ReadRegister();
    return (register_data & kOnkey8SIMask.kMask) == kOnkey4SIMask.ACTIVE;
  }

private:
  static const uint8_t kRegister = 0x24;
};

struct OnkeyIntMask0 : public I2CRegister {
  struct OnkeyPushMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_0;
    OnkeyPushMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_1;
    Onkey1SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_2;
    Onkey2SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_3;
    Onkey3SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_4;
    Onkey4SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_5;
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

  void OnkeyPushMEnable() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kOnkeyPushMMask.kMask & kOnkeyPushMMask.ENABLED));
    WriteRegister(data);
  }
  void OnkeyPushMRemove() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kOnkeyPushMMask.kMask & kOnkeyPushMMask.REMOVED));
    WriteRegister(data);
  }
  void Onkey1SMEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey1SMMask.kMask & kOnkey1SMMask.ENABLED));
    WriteRegister(data);
  }
  void Onkey1SMRemove() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey1SMMask.kMask & kOnkey1SMMask.REMOVED));
    WriteRegister(data);
  }
  void Onkey2SMEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey2SMMask.kMask & kOnkey2SMMask.ENABLED));
    WriteRegister(data);
  }
  void Onkey2SMRemove() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey2SMMask.kMask & kOnkey2SMMask.REMOVED));
    WriteRegister(data);
  }
  void Onkey3SMEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey3SMMask.kMask & kOnkey3SMMask.ENABLED));
    WriteRegister(data);
  }
  void Onkey3SMRemove() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey3SMMask.kMask & kOnkey3SMMask.REMOVED));
    WriteRegister(data);
  }
  void Onkey4SMEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey4SMMask.kMask & kOnkey4SMMask.ENABLED));
    WriteRegister(data);
  }
  void Onkey4SMRemove() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey4SMMask.kMask & kOnkey4SMMask.REMOVED));
    WriteRegister(data);
  }
  void Onkey8SMEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey8SMMask.kMask & kOnkey8SMMask.ENABLED));
    WriteRegister(data);
  }
  void Onkey8SMRemove() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOnkey8SMMask.kMask & kOnkey8SMMask.REMOVED));
    WriteRegister(data);
  }

private:
  static const uint8_t kRegister = 0x25;
};

struct OnkeyIntSense0 : public I2CRegister {
  struct OnkeyPushSMask : public Mask {
    static const uint8_t PUSHED = BITS_NONE;
    static const uint8_t NOT_PUSHED = BITS_0;
    OnkeyPushSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SSMask : public Mask {
    static const uint8_t PUSHED = BITS_NONE;
    static const uint8_t NOT_PUSHED = BITS_1;
    Onkey1SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SSMask : public Mask {
    static const uint8_t PUSHED = BITS_NONE;
    static const uint8_t NOT_PUSHED = BITS_2;
    Onkey2SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SSMask : public Mask {
    static const uint8_t PUSHED = BITS_NONE;
    static const uint8_t NOT_PUSHED = BITS_3;
    Onkey3SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SSMask : public Mask {
    static const uint8_t PUSHED = BITS_NONE;
    static const uint8_t NOT_PUSHED = BITS_4;
    Onkey4SSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SSMask : public Mask {
    static const uint8_t PUSHED = BITS_NONE;
    static const uint8_t NOT_PUSHED = BITS_5;
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
  static const uint8_t kRegister = 0x26;
};

struct MiscIntStat0 : public I2CRegister {
  struct PwrUpIMask : public Mask {
    static const uint8_t ACTIVE = BITS_NONE;
    static const uint8_t NOT_ACTIVE = BITS_0;
    PwrUpIMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnIMask : public Mask {
    static const uint8_t ACTIVE = BITS_NONE;
    static const uint8_t NOT_ACTIVE = BITS_1;
    PwrDnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnIMask : public Mask {
    static const uint8_t ACTIVE = BITS_NONE;
    static const uint8_t NOT_ACTIVE = BITS_2;
    PwrOnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnIMask : public Mask {
    static const uint8_t ACTIVE = BITS_NONE;
    static const uint8_t NOT_ACTIVE = BITS_3;
    LowSysWarnIMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoIMask : public Mask {
    static const uint8_t ACTIVE = BITS_NONE;
    static const uint8_t NOT_ACTIVE = BITS_4;
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
  static const uint8_t kRegister = 0x28;
};

struct MiscIntMask0 : public I2CRegister {
  struct PwrUpMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_0;
    PwrUpMMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_1;
    PwrDnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_2;
    PwrOnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_3;
    LowSysWarnMMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoMMask : public Mask {
    static const uint8_t ENABLED = BITS_NONE;
    static const uint8_t REMOVED = BITS_4;
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
  static const uint8_t kRegister = 0x29;
};

struct MiscIntSense0 : public I2CRegister {
  struct PwrUpSMask : public Mask {
    static const uint8_t IN_PROGRESS = BITS_NONE;
    static const uint8_t NOT_IN_PROGRESS = BITS_0;
    PwrUpSMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrDnSMask : public Mask {
    static const uint8_t IN_PROGRESS = BITS_NONE;
    static const uint8_t NOT_IN_PROGRESS = BITS_1;
    PwrDnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwrOnSMask : public Mask {
    static const uint8_t PWR_ON_LOW = BITS_NONE;
    static const uint8_t PWR_ON_HIGH = BITS_2;
    PwrOnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnSMask : public Mask {
    static const uint8_t ABOVE = BITS_NONE;
    static const uint8_t BELOW = BITS_3;
    LowSysWarnSMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysOlvoSMask : public Mask {
    static const uint8_t ABOVE = BITS_NONE;
    static const uint8_t BELOW = BITS_4;
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
  static const uint8_t kRegister = 0x2A;
};

struct CoincellControl : public I2CRegister {
  struct VCoinMask : public Mask {
    static const uint8_t _1_8 = BITS_NONE;
    static const uint8_t _1_9 = BITS_0;
    static const uint8_t _2_0 = BITS_1;
    static const uint8_t _2_1 = BITS_1_0;
    static const uint8_t _2_2 = BITS_2;
    static const uint8_t _2_3 = BITS_2_0;
    static const uint8_t _2_4 = BITS_2_1;
    static const uint8_t _2_5 = BITS_2_1_0;
    static const uint8_t _2_6 = BITS_3;
    static const uint8_t _2_7 = BITS_3_0;
    static const uint8_t _2_8 = BITS_3_1;
    static const uint8_t _2_9 = BITS_3_1_0;
    static const uint8_t _3_0 = BITS_3_2;
    static const uint8_t _3_1 = BITS_3_2_0;
    static const uint8_t _3_2 = BITS_3_2_1;
    static const uint8_t _3_3 = BITS_3_2_1_0;
    VCoinMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChEnMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t ENABLED = BITS_4;
    ChEnMask(uint8_t mask) : Mask(mask) {}
  };
  static const VCoinMask kVCoinMask;
  static const ChEnMask kChEnMask;
  CoincellControl(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}
  void VCoin(uint8_t voltage) { WriteRegister(voltage); }
  void ChEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kChEnMask.kMask & kChEnMask.ENABLED));
    WriteRegister(data);
  }
  void ChDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kChEnMask.kMask & kChEnMask.DISABLED));
    WriteRegister(data);
  }

private:
  static const uint8_t kRegister = 0x30;
};

struct VsnvsCtrl : public I2CRegister {
  struct CLKPulseMask : public Mask {
    CLKPulseMask(uint8_t mask) : Mask(mask) {}
  };
  struct ForceBOSMask : public Mask {
    static const uint8_t FORCED = BITS_4;
    static const uint8_t ONLY_VSYS_LT_VDIV = BITS_NONE;
    ForceBOSMask(uint8_t mask) : Mask(mask) {}
  };
  struct LiBGDisMask : public Mask {
    static const uint8_t Vsnvs_BAND_GAP_DISABLED = BITS_NONE;
    static const uint8_t Vsnvs_BAND_GAP_ENABLED = BITS_5;
    LiBGDisMask(uint8_t mask) : Mask(mask) {}
  };
  static const CLKPulseMask kCLKPulseMask;
  static const ForceBOSMask kForceBOSMask;
  static const LiBGDisMask kLiBGDisMask;
  VsnvsCtrl(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x48;
};

struct VrefddrCtrl : public I2CRegister {
  struct VrefddrEnMask : public Mask {
    static const uint8_t DISABLE = BITS_0;
    static const uint8_t ENABLE = BITS_NONE;
    VrefddrEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct VrefddrStbyEnMask : public Mask {
    static const uint8_t DISABLE = BITS_1;
    static const uint8_t ENABLE = BITS_NONE;
    VrefddrStbyEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct VrefddrOModeMask : public Mask {
    static const uint8_t DISABLE = BITS_2;
    static const uint8_t ENABLE = BITS_NONE;
    VrefddrOModeMask(uint8_t mask) : Mask(mask) {}
  };
  struct VrefddrLPwrMask : public Mask {
    static const uint8_t DISABLE = BITS_3;
    static const uint8_t ENABLE = BITS_NONE;
    VrefddrLPwrMask(uint8_t mask) : Mask(mask) {}
  };
  static const VrefddrEnMask kVrefddrEnMask;
  static const VrefddrStbyEnMask kVrefddrStbyEnMask;
  static const VrefddrOModeMask kVrefddrOModeMask;
  static const VrefddrLPwrMask kVrefddrLPwrMask;
  VrefddrCtrl(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x4A;
};
struct VrefddrPwrDnSeq : public I2CRegister {
  struct VrefddrPwrDnSeqMask : public Mask {
    // TODO(kendall): Add specific masks/values.
    VrefddrPwrDnSeqMask(uint8_t mask) : Mask(mask) {}
  };
  static const VrefddrPwrDnSeqMask kVrefddrPwrDnSeqMask;
  VrefddrPwrDnSeq(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x65;
};

struct Key1 : public I2CRegister {
  struct Key1Mask : public Mask {
    // TODO(kendall): Add specific masks/values.
    Key1Mask(uint8_t mask) : Mask(mask) {}
  };
  static const Key1Mask kKey1Mask;
  Key1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x6B;
};
// End Misch.h

// Charger.h
// TODO(kendall): Find a better place for this. Also rename it to
// SPECIFIC_CHARGER_REGISTERS_OFFSET
static const uint8_t SPECIFIC_REGISTER_OFFSET = 0x80;
struct ChgInt : public I2CRegister {
  struct SupIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_0;
    SupIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_1;
    Bat2SocIMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_2;
    BatIMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_3;
    ChgIMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_5;
    VbusIMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_6;
    VbusDpmIMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_7;
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
  static const uint8_t kRegister = 0x00 + SPECIFIC_REGISTER_OFFSET;
};

struct ChgIntMask : public I2CRegister {
  struct SupMMask : public Mask {
    static const uint8_t MASKED = BITS_NONE;
    static const uint8_t UNMASKED = BITS_0;
    SupMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocMMask : public Mask {
    static const uint8_t MASKED = BITS_NONE;
    static const uint8_t UNMASKED = BITS_1;
    Bat2SocMMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatMMask : public Mask {
    static const uint8_t MASKED = BITS_NONE;
    static const uint8_t UNMASKED = BITS_2;
    BatMMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgMMask : public Mask {
    static const uint8_t MASKED = BITS_NONE;
    static const uint8_t UNMASKED = BITS_3;
    ChgMMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusMMask : public Mask {
    static const uint8_t MASKED = BITS_NONE;
    static const uint8_t UNMASKED = BITS_5;
    VbusMMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmMMask : public Mask {
    static const uint8_t MASKED = BITS_6;
    static const uint8_t UNMASKED = BITS_NONE;
    VbusDpmMMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmMMask : public Mask {
    static const uint8_t MASKED = BITS_NONE;
    static const uint8_t UNMASKED = BITS_7;
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
  static const uint8_t kRegister = 0x02 + SPECIFIC_REGISTER_OFFSET;
};

struct ChgIntOk : public I2CRegister {
  struct SupOkMask : public Mask {
    static const uint8_t DETECTED = BITS_NONE;
    static const uint8_t NOT_DETECTED = BITS_0;
    SupOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct Bat2SocOkMask : public Mask {
    static const uint8_t OVERCURRENT = BITS_NONE;
    static const uint8_t NOT_OVERCURRENT = BITS_1;
    Bat2SocOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct BatOkMask : public Mask {
    static const uint8_t BAT_OK = BITS_NONE;
    static const uint8_t BAT_ISSUE = BITS_2;
    BatOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct ChgOkMask : public Mask {
    static const uint8_t CHG_OK = BITS_NONE;
    static const uint8_t NOT_CHARGING = BITS_3;
    ChgOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusOkMask : public Mask {
    static const uint8_t INVALID = BITS_NONE;
    static const uint8_t VALID = BITS_5;
    VbusOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmOkMask : public Mask {
    static const uint8_t DPM = BITS_NONE;
    static const uint8_t NO_DPM = BITS_6;
    VbusDpmOkMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmOkMask : public Mask {
    static const uint8_t WITHIN_THRESHOLD = BITS_NONE;
    static const uint8_t OUTSIDE_THRESHOLD = BITS_7;
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
  static const uint8_t kRegister = 0x04 + SPECIFIC_REGISTER_OFFSET;
};

struct VbusSns : public I2CRegister {
  struct VbusUvloSnsMask : public Mask {
    static const uint8_t VBUS_DETACHED = BITS_NONE;
    static const uint8_t VBUS_GT_UVLO = BITS_2;
    VbusUvloSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusIn2SysSnsMask : public Mask {
    static const uint8_t GT = BITS_NONE;
    static const uint8_t LT = BITS_3;
    VbusIn2SysSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusOvloSnsMask : public Mask {
    static const uint8_t GT = BITS_NONE;
    static const uint8_t LT = BITS_4;
    VbusOvloSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusValidMask : public Mask {
    static const uint8_t INVALID = BITS_NONE;
    static const uint8_t VALID = BITS_5;
    VbusValidMask(uint8_t mask) : Mask(mask) {}
  };
  struct VbusDpmSnsMask : public Mask {
    static const uint8_t NOT_TRIGGERED = BITS_NONE;
    static const uint8_t TRIGGERED = BITS_7;
    VbusDpmSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static const VbusUvloSnsMask kVbusUvloSnsMask;
  static const VbusIn2SysSnsMask kVbusIn2SysSnsMask;
  static const VbusOvloSnsMask kVbusOvloSnsMask;
  static const VbusValidMask kVbusValidMask;
  static const VbusDpmSnsMask kVbusDpmSnsMask;

  VbusSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x06 + SPECIFIC_REGISTER_OFFSET;
};

struct ChgSns : public I2CRegister {
  struct ChgSnsMask : public Mask {
    static const uint8_t PRECHARGE = BITS_NONE;
    static const uint8_t FAST_CHARGE_CC = BITS_0;
    static const uint8_t FAST_CHARGE_CV = BITS_1;
    static const uint8_t END_OF_CHARGE = BITS_1_0;
    static const uint8_t DONE = BITS_2;
    static const uint8_t TIMER_FAULT = BITS_2_1;
    static const uint8_t THERMISTOR_SUSPEND = BITS_2_1_0;
    static const uint8_t OFF_INVALID_OR_DISABLED = BITS_3;
    static const uint8_t OVERVOLTAGE = BITS_3_0;
    static const uint8_t CHG_THERMAL_OFF = BITS_3_1;
    static const uint8_t LINEAR_ONLY_NO_CHARGE = BITS_3_2;
    ChgSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdtSnsMask : public Mask {
    static const uint8_t CHG_OFF_WATCHDOG = BITS_5;
    static const uint8_t WATCHDOG_NOT_EXPIRED = BITS_NONE;
    WdtSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmSnsMask : public Mask {
    static const uint8_t WITHIN_THRESHOLDS = BITS_5;
    static const uint8_t OUTSIDE_THRESHOLDS = BITS_NONE;
    ThmSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct TregSnsMask : public Mask {
    static const uint8_t GREATER_THAN_THRESHOLD = BITS_7;
    static const uint8_t LESS_THAN_THRESHOLD = BITS_NONE;
    TregSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static const ChgSnsMask kChgSnsMask;
  static const WdtSnsMask kWdtSnsMask;
  static const ThmSnsMask kThmSnsMask;
  static const TregSnsMask kTregSnsMask;

  ChgSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x07 + SPECIFIC_REGISTER_OFFSET;
};

struct BattSns : public I2CRegister {
  struct BattSnsMask : public Mask {
    static const uint8_t VBUS_INVALID = BITS_NONE;
    static const uint8_t VBATT_LT_PRECHG = BITS_0;
    static const uint8_t CHG_SUSPENDED = BITS_1;
    static const uint8_t VBATT_GT_PRECHG = BITS_2;
    static const uint8_t OVERVOLTAGE = BITS_2_0;
    static const uint8_t NOT_DETECTED = BITS_2_1;
    BattSnsMask(uint8_t mask) : Mask(mask) {}
  };
  struct BattOCSnsMask : public Mask {
    static const uint8_t NOFAULT = BITS_NONE;
    static const uint8_t FAULT = BITS_5;
    BattOCSnsMask(uint8_t mask) : Mask(mask) {}
  };
  static const BattSnsMask kBattSnsMask;
  static const BattOCSnsMask kBattOCSnsMask;

  BattSns(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x08 + SPECIFIC_REGISTER_OFFSET;
};

struct ChgOper : public I2CRegister {
  struct ChgOperMask : public Mask {
    static const uint8_t CHG_OFF_LINEAR_OFF = BITS_NONE;
    static const uint8_t CHG_OFF_LINEAR_ON = BITS_0;
    static const uint8_t CHG_ON_LINEAR_ON = BITS_1;
    ChgOperMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdtEnMask : public Mask {
    static const uint8_t WATCHDOG_DISABLED = BITS_NONE;
    static const uint8_t WATCHDOG_ENABLED = BITS_3;
    WdtEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct DisBattFetMask : public Mask {
    static const uint8_t FET_STATEMACHINE = BITS_NONE;
    static const uint8_t FET_FORCED_OFF = BITS_4;
    DisBattFetMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgOperMask kChgOperMask;
  static const WdtEnMask kWdtEnMask;
  static const DisBattFetMask kDisBattFetMask;

  ChgOper(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x09 + SPECIFIC_REGISTER_OFFSET;
};

struct ChgTmr : public I2CRegister {
  struct FChgTimeMask : public Mask {
    static const uint8_t DISABLE = BITS_NONE;
    static const uint8_t _2HR = BITS_0;
    static const uint8_t _4HR = BITS_1;
    static const uint8_t _6HR = BITS_1_0;
    static const uint8_t _8HR = BITS_2;
    static const uint8_t _10HR = BITS_2_0;
    static const uint8_t _12HR = BITS_2_1;
    static const uint8_t _14HR = BITS_2_1_0;
    FChgTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct EoCTimeMask : public Mask {
    static const uint8_t _0M = BITS_NONE;
    static const uint8_t _10M = BITS_3;
    static const uint8_t _20M = BITS_4;
    static const uint8_t _30M = BITS_4_3;
    static const uint8_t _40M = BITS_5;
    static const uint8_t _50M = BITS_5_3;
    static const uint8_t _60M = BITS_5_4;
    static const uint8_t _70M = BITS_2_1_0;
    EoCTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct TPreChgMask : public Mask {
    static const uint8_t _30M = BITS_NONE;
    static const uint8_t _45M = BITS_7;
    TPreChgMask(uint8_t mask) : Mask(mask) {}
  };
  static const FChgTimeMask kFChgTimeMask;
  static const EoCTimeMask kEoCTimeMask;
  static const TPreChgMask kTPreChgMask;

  ChgTmr(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0A + SPECIFIC_REGISTER_OFFSET;
};

struct ChgEocCnfg : public I2CRegister {
  struct ChgRestartMask : public Mask {
    static const uint8_t _100MV = BITS_NONE;
    static const uint8_t _150MV = BITS_0;
    static const uint8_t _200MV = BITS_1;
    static const uint8_t DISABLED = BITS_1_0;
    ChgRestartMask(uint8_t mask) : Mask(mask) {}
  };
  struct IEoCMask : public Mask {
    static const uint8_t _5MA = BITS_NONE;
    static const uint8_t _10MA = BITS_4;
    static const uint8_t _20MA = BITS_5;
    static const uint8_t _30MA = BITS_5_4;
    static const uint8_t _50MA = BITS_6;
    IEoCMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgRestartMask kChgRestartMask;
  static const IEoCMask kIEoCMask;
  ChgEocCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0D + SPECIFIC_REGISTER_OFFSET;
};

struct ChgCurrCnfg : public I2CRegister {
  struct ChgCcMask : public Mask {
    static const uint8_t _100MA = BITS_NONE;
    static const uint8_t _150MA = BITS_0;
    static const uint8_t _200MA = BITS_1;
    static const uint8_t _250MA = BITS_1_0;
    static const uint8_t _300MA = BITS_2;
    static const uint8_t _350MA = BITS_2_0;
    static const uint8_t _400MA = BITS_2_1;
    static const uint8_t _450MA = BITS_2_1_0;
    static const uint8_t _500MA = BITS_3;
    static const uint8_t _550MA = BITS_3_0;
    static const uint8_t _600MA = BITS_3_1;
    static const uint8_t _650MA = BITS_3_1_0;
    static const uint8_t _700MA = BITS_3_2;
    static const uint8_t _750MA = BITS_3_2_0;
    static const uint8_t _800MA = BITS_3_2_1;
    static const uint8_t _850MA = BITS_3_2_1_0;
    static const uint8_t _900MA = BITS_4;
    static const uint8_t _950MA = BITS_4_0;
    static const uint8_t _1000MA = BITS_4_1;
    ChgCcMask(uint8_t mask) : Mask(mask) {}
  };
  struct PreChgLbThrsMask : public Mask {
    static const uint8_t _2_8V = BITS_NONE;
    static const uint8_t _2_7V = BITS_5;
    static const uint8_t _2_9V = BITS_6;
    static const uint8_t _3_0V = BITS_6_5;
    PreChgLbThrsMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgCcMask kChgCcMask;
  static const PreChgLbThrsMask kPreChgLbThrsMask;

  ChgCurrCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0E + SPECIFIC_REGISTER_OFFSET;
};

struct BattReg : public I2CRegister {
  struct ChgCvMask : public Mask {
    static const uint8_t _3_50V = BITS_NONE;
    static const uint8_t _3_50V_1 = BITS_0;
    static const uint8_t _3_50V_2 = BITS_1;
    static const uint8_t _3_50V_3 = BITS_1_0;
    static const uint8_t _3_50V_4 = BITS_2;
    static const uint8_t _3_50V_5 = BITS_2_0;
    static const uint8_t _3_50V_6 = BITS_2_1;
    static const uint8_t _3_50V_7 = BITS_2_1_0;
    static const uint8_t _3_50V_8 = BITS_3;
    static const uint8_t _3_52V = BITS_3_0;
    static const uint8_t _3_54V = BITS_3_1;
    static const uint8_t _3_56V = BITS_3_1_0;
    static const uint8_t _3_58V = BITS_3_2;
    static const uint8_t _3_60V = BITS_3_2_0;
    static const uint8_t _3_62V = BITS_3_2_1;
    static const uint8_t _3_64V = BITS_3_2_1_0;
    static const uint8_t _3_66V = BITS_4;
    static const uint8_t _3_68V = BITS_4_0;
    static const uint8_t _3_70V = BITS_4_1;
    static const uint8_t _3_72V = BITS_4_1_0;
    static const uint8_t _3_74V = BITS_4_2;
    static const uint8_t _3_76V = BITS_4_2_0;
    static const uint8_t _3_78V = BITS_4_2_1;
    static const uint8_t _3_80V = BITS_4_2_1_0;
    static const uint8_t _3_82V = BITS_4_3;
    static const uint8_t _3_84V = BITS_4_3_0;
    static const uint8_t _3_86V = BITS_4_3_1;
    static const uint8_t _3_88V = BITS_4_3_1_0;
    static const uint8_t _3_90V = BITS_4_3_2;
    static const uint8_t _3_92V = BITS_4_3_2_0;
    static const uint8_t _3_94V = BITS_4_3_2_1;
    static const uint8_t _3_96V = BITS_4_3_2_1_0;
    static const uint8_t _3_98V = BITS_5;
    static const uint8_t _4_00V = BITS_5_0;
    static const uint8_t _4_02V = BITS_5_1;
    static const uint8_t _4_04V = BITS_5_1_0;
    static const uint8_t _4_06V = BITS_5_2;
    static const uint8_t _4_08V = BITS_5_2_0;
    static const uint8_t _4_10V = BITS_5_2_1;
    static const uint8_t _4_12V = BITS_5_2_1_0;
    static const uint8_t _4_14V = BITS_5_3;
    static const uint8_t _4_16V = BITS_5_3_0;
    static const uint8_t _4_18V = BITS_5_3_1;
    static const uint8_t _4_20V = BITS_5_3_1_0;
    static const uint8_t _4_22V = BITS_5_3_2;
    static const uint8_t _4_24V = BITS_5_3_2_0;
    static const uint8_t _4_26V = BITS_5_3_2_1;
    static const uint8_t _4_28V = BITS_5_3_2_1_0;
    static const uint8_t _4_30V = BITS_5_4;
    static const uint8_t _4_32V = BITS_5_4_0;
    static const uint8_t _4_34V = BITS_5_4_1;
    static const uint8_t _4_36V = BITS_5_4_1_0;
    static const uint8_t _4_38V = BITS_5_4_2;
    static const uint8_t _4_40V = BITS_5_4_2_0;
    static const uint8_t _4_42V = BITS_5_4_2_1;
    static const uint8_t _4_44V = BITS_5_4_2_1_0;
    static const uint8_t _4_44V_1 = BITS_5_4_3;
    static const uint8_t _4_44V_2 = BITS_5_4_3_0;
    static const uint8_t _4_44V_3 = BITS_5_4_3_1;
    static const uint8_t _4_44V_4 = BITS_5_4_3_1_0;
    static const uint8_t _4_44V_5 = BITS_5_4_3_2;
    static const uint8_t _4_44V_6 = BITS_5_4_3_2_0;
    static const uint8_t _4_44V_7 = BITS_5_4_3_2_1;
    static const uint8_t _4_44V_8 = BITS_5_4_3_2_1_0;
    ChgCvMask(uint8_t mask) : Mask(mask) {}
  };
  struct VsysMinMask : public Mask {
    static const uint8_t _3_5V = BITS_NONE;
    static const uint8_t _3_7V = BITS_6;
    static const uint8_t _4_3V = BITS_7;
    VsysMinMask(uint8_t mask) : Mask(mask) {}
  };
  static const ChgCvMask kChgCvMask;
  static const VsysMinMask kVsysMinMask;

  BattReg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0F + SPECIFIC_REGISTER_OFFSET;
};
struct BatfetCnfg : public I2CRegister {
  struct WdtClrMask : public Mask {
    static const uint8_t NOT_CLEARED = BITS_0;
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t NOT_CLEARED_1 = BITS_1;
    static const uint8_t NOT_CLEARED_2 = BITS_1_0;
    WdtClrMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdBattFetOffMask : public Mask {
    WdBattFetOffMask(uint8_t mask) : Mask(mask) {}
  };
  struct BOVRCDisBattFetMask : public Mask {
    static const uint8_t CHARGER_CONTROLLED = BITS_NONE;
    static const uint8_t NOT_TURNED_OFF_BY_OVC = BITS_3;
    BOVRCDisBattFetMask(uint8_t mask) : Mask(mask) {}
  };
  struct BattFetOCMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t _2_2A = BITS_4;
    static const uint8_t _2_8A = BITS_5;
    static const uint8_t _3_2A = BITS_5_4;
    BattFetOCMask(uint8_t mask) : Mask(mask) {}
  };
  struct WdTimeMask : public Mask {
    static const uint8_t _80s = BITS_NONE;
    static const uint8_t _32s = BITS_6;
    WdTimeMask(uint8_t mask) : Mask(mask) {}
  };
  struct BOVRCNoVBusMask : public Mask {
    static const uint8_t ENABLED = BITS_7;
    static const uint8_t DISABLED = BITS_NONE;
    BOVRCNoVBusMask(uint8_t mask) : Mask(mask) {}
  };
  static const WdtClrMask kWdtClrMask;
  static const WdBattFetOffMask kWdBattFetOffMask;
  static const BOVRCDisBattFetMask kBOVRCDisBattFetMask;
  static const BattFetOCMask kBattFetOCMask;
  static const WdTimeMask kWdTimeMask;
  static const BOVRCNoVBusMask kBOVRCNoVBusMask;

  BatfetCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x11 + SPECIFIC_REGISTER_OFFSET;
};

struct ThmRegCnfg : public I2CRegister {
  struct ThmCnfgMask : public Mask {
    static const uint8_t THM_DOES_NOT_CONTROL = BITS_NONE;
    static const uint8_t THM_CONTROLS = BITS_0;
    static const uint8_t JEITA1 = BITS_1;
    static const uint8_t JEITA2 = BITS_1_0;
    ThmCnfgMask(uint8_t mask) : Mask(mask) {}
  };
  struct RegTempMask : public Mask {
    static const uint8_t _80C = BITS_NONE;
    static const uint8_t _95C = BITS_2;
    static const uint8_t _110C = BITS_3;
    static const uint8_t _125C = BITS_3_2;
    RegTempMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmColdMask : public Mask {
    static const uint8_t _MINUS_10C = BITS_4;
    static const uint8_t _0C = BITS_NONE;
    ThmColdMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmHotMask : public Mask {
    static const uint8_t _55C = BITS_5;
    static const uint8_t _60C = BITS_NONE;
    ThmHotMask(uint8_t mask) : Mask(mask) {}
  };
  struct TempFbEnMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t ENABLED = BITS_7;
    TempFbEnMask(uint8_t mask) : Mask(mask) {}
  };

  static const ThmCnfgMask kThmCnfgMask;
  static const RegTempMask kRegTempMask;
  static const ThmColdMask kThmColdMask;
  static const ThmHotMask kThmHotMask;
  static const TempFbEnMask kTempFbEnMask;
  ThmRegCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x12 + SPECIFIC_REGISTER_OFFSET;
};

struct VbusInLimCnfg : public I2CRegister {
  struct VbusLinILimMask : public Mask {
    static const uint8_t _10MA = BITS_NONE;
    static const uint8_t _15MA = BITS_3;
    static const uint8_t _20MA = BITS_4;
    static const uint8_t _25MA = BITS_4_3;
    static const uint8_t _30MA = BITS_5;
    static const uint8_t _35MA = BITS_5_3;
    static const uint8_t _40MA = BITS_5_4;
    static const uint8_t _45MA = BITS_5_4_3;
    static const uint8_t _50MA = BITS_6;
    static const uint8_t _100MA = BITS_6_3;
    static const uint8_t _150MA = BITS_6_4;
    static const uint8_t _200MA = BITS_6_4_3;
    static const uint8_t _300MA = BITS_6_5;
    static const uint8_t _400MA = BITS_6_5_3;
    static const uint8_t _500MA = BITS_6_5_4;
    static const uint8_t _600MA = BITS_6_5_4_3;
    static const uint8_t _700MA = BITS_7;
    static const uint8_t _800MA = BITS_7_3;
    static const uint8_t _900MA = BITS_7_4;
    static const uint8_t _1000MA = BITS_7_4_3;
    static const uint8_t _1500MA = BITS_7_5;
    VbusLinILimMask(uint8_t mask) : Mask(mask) {}
  };
  static const VbusLinILimMask kVbusLinILimMask;
  VbusInLimCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x14 + SPECIFIC_REGISTER_OFFSET;
};

struct VbusLinDpm : public I2CRegister {
  struct VbusDpmRegMask : public Mask {
    static const uint8_t _3_9V = BITS_NONE;
    static const uint8_t _4_0V = BITS_0;
    static const uint8_t _4_1V = BITS_1;
    static const uint8_t _4_2V = BITS_1_0;
    static const uint8_t _4_3V = BITS_2;
    static const uint8_t _4_4V = BITS_2_0;
    static const uint8_t _4_5V = BITS_2_1;
    static const uint8_t _4_6V = BITS_2_1_0;
    VbusDpmRegMask(uint8_t mask) : Mask(mask) {}
  };
  struct PreChgdBattThrshMask : public Mask {
    PreChgdBattThrshMask(uint8_t mask) : Mask(mask) {}
  };
  struct VinDpmStopMask : public Mask {
    static const uint8_t _200MV = BITS_NONE;
    static const uint8_t _250MV = BITS_5;
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
  static const uint8_t kRegister = 0x15 + SPECIFIC_REGISTER_OFFSET;
};

struct UsbPhyLdoCnfg : public I2CRegister {
  struct ActDisPhyMask : public Mask {
    static const uint8_t NO_DISCHARGE = BITS_NONE;
    static const uint8_t DISCHARGE = BITS_0;
    ActDisPhyMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyMask : public Mask {
    static const uint8_t _3_3V = BITS_NONE;
    static const uint8_t _4_9V = BITS_1;
    UsbPhyMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyLdoMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t ENABLED = BITS_2;
    UsbPhyLdoMask(uint8_t mask) : Mask(mask) {}
  };

  static const ActDisPhyMask kActDisPhyMask;
  static const UsbPhyMask kUsbPhyMask;
  static const UsbPhyLdoMask kUsbPhyLdoMask;

  UsbPhyLdoCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x16 + SPECIFIC_REGISTER_OFFSET;
};
struct DbncDelayTime : public I2CRegister {
  struct VbusOvTdbMask : public Mask {
    static const uint8_t _10US = BITS_NONE;
    static const uint8_t _100US = BITS_0;
    static const uint8_t _1MS = BITS_1;
    static const uint8_t _10MS = BITS_1_0;
    VbusOvTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyTdbMask : public Mask {
    static const uint8_t _0MS = BITS_NONE;
    static const uint8_t _16MS = BITS_2;
    static const uint8_t _32MS = BITS_3;
    UsbPhyTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct SysWkUpDlyMask : public Mask {
    static const uint8_t _8MS = BITS_NONE;
    static const uint8_t _16MS = BITS_4;
    static const uint8_t _32MS = BITS_5;
    static const uint8_t _100MS = BITS_5_4;
    SysWkUpDlyMask(uint8_t mask) : Mask(mask) {}
  };

  static const VbusOvTdbMask kVbusOvTdbMask;
  static const UsbPhyTdbMask kUsbPhyTdbMask;
  static const SysWkUpDlyMask kSysWkUpDlyMask;

  DbncDelayTime(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x18 + SPECIFIC_REGISTER_OFFSET;
};

struct ChgIntCnfg : public I2CRegister {
  struct ChgIntGenMask : public Mask {
    static const uint8_t INT_ONLY_FC_TO_CV = BITS_NONE;
    static const uint8_t INT_ON_TRANSITION = BITS_0;
    ChgIntGenMask(uint8_t mask) : Mask(mask) {}
  };
  struct EoCIntMask : public Mask {
    static const uint8_t NO_EOC_INT = BITS_NONE;
    static const uint8_t EOC_INT = BITS_1;
    EoCIntMask(uint8_t mask) : Mask(mask) {}
  };

  static const ChgIntGenMask kChgIntGenMask;
  static const EoCIntMask kEoCIntMask;
  ChgIntCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x19 + SPECIFIC_REGISTER_OFFSET;
};
struct ThmAdjSetting : public I2CRegister {
  struct ThmWarmMask : public Mask {
    static const uint8_t _45C = BITS_NONE;
    static const uint8_t _50C = BITS_0;
    ThmWarmMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmCoolMask : public Mask {
    static const uint8_t _15C = BITS_NONE;
    static const uint8_t _10C = BITS_1;
    ThmCoolMask(uint8_t mask) : Mask(mask) {}
  };
  struct CvAdjMask : public Mask {
    static const uint8_t _60MV = BITS_NONE;
    static const uint8_t _100MV = BITS_2;
    static const uint8_t _160MV = BITS_3;
    static const uint8_t _200MV = BITS_3_2;
    CvAdjMask(uint8_t mask) : Mask(mask) {}
  };
  struct CcAdjMask : public Mask {
    static const uint8_t _25PCT = BITS_NONE;
    static const uint8_t _50PCT = BITS_4;
    static const uint8_t _75PCT = BITS_5;
    static const uint8_t _100PCT = BITS_5_4;
    CcAdjMask(uint8_t mask) : Mask(mask) {}
  };
  static const ThmWarmMask kThmWarmMask;
  static const ThmCoolMask kThmCoolMask;
  static const CvAdjMask kCvAdjMask;
  static const CcAdjMask kCcAdjMask;

  ThmAdjSetting(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x1A + SPECIFIC_REGISTER_OFFSET;
};

struct Vbus2SysCnfg : public I2CRegister {
  struct Vbus2SysTdbMask : public Mask {
    static const uint8_t _100US = BITS_0;
    static const uint8_t _1MS = BITS_1;
    static const uint8_t _10MS = BITS_1_0;
    Vbus2SysTdbMask(uint8_t mask) : Mask(mask) {}
  };
  struct Vbus2SysThrshMask : public Mask {
    static const uint8_t _50MV = BITS_NONE;
    static const uint8_t _175MV = BITS_2;
    Vbus2SysThrshMask(uint8_t mask) : Mask(mask) {}
  };

  static const Vbus2SysTdbMask kVbus2SysTdbMask;
  static const Vbus2SysThrshMask kVbus2SysThrshMask;

  Vbus2SysCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x1B + SPECIFIC_REGISTER_OFFSET;
};

struct LedPwm : public I2CRegister {
  struct LedPwmMask : public Mask {
    static const uint8_t _0_32 = BITS_NONE;
    static const uint8_t _1_32 = BITS_0;
    static const uint8_t _2_32 = BITS_1;
    static const uint8_t _3_32 = BITS_1_0;
    static const uint8_t _4_32 = BITS_2;
    static const uint8_t _5_32 = BITS_2_0;
    static const uint8_t _6_32 = BITS_2_1;
    static const uint8_t _7_32 = BITS_2_1_0;
    static const uint8_t _8_32 = BITS_3;
    static const uint8_t _9_32 = BITS_3_0;
    static const uint8_t _10_32 = BITS_3_1;
    static const uint8_t _11_32 = BITS_3_1_0;
    static const uint8_t _12_32 = BITS_3_2;
    static const uint8_t _13_32 = BITS_3_2_0;
    static const uint8_t _14_32 = BITS_3_2_1;
    static const uint8_t _15_32 = BITS_3_2_1_0;
    static const uint8_t _16_32 = BITS_4;
    static const uint8_t _17_32 = BITS_4_0;
    static const uint8_t _18_32 = BITS_4_1;
    static const uint8_t _19_32 = BITS_4_1_0;
    static const uint8_t _20_32 = BITS_4_2;
    static const uint8_t _21_32 = BITS_4_2_0;
    static const uint8_t _22_32 = BITS_4_2_1;
    static const uint8_t _23_32 = BITS_4_2_1_0;
    static const uint8_t _24_32 = BITS_4_3;
    static const uint8_t _25_32 = BITS_4_3_0;
    static const uint8_t _26_32 = BITS_4_3_1;
    static const uint8_t _27_32 = BITS_4_3_1_0;
    static const uint8_t _28_32 = BITS_4_3_2;
    static const uint8_t _29_32 = BITS_4_3_2_0;
    static const uint8_t _30_32 = BITS_4_3_2_1;
    static const uint8_t _31_32 = BITS_4_3_2_1_0;
    LedPwmMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedRampMask : public Mask {
    static const uint8_t DISABLE = BITS_NONE;
    static const uint8_t ENABLE = BITS_6;
    LedRampMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedEnMask : public Mask {
    static const uint8_t DISABLE = BITS_NONE;
    static const uint8_t ENABLE = BITS_7;
    LedEnMask(uint8_t mask) : Mask(mask) {}
  };

  static const LedPwmMask kLedPwmMask;
  static const LedRampMask kLedRampMask;
  static const LedEnMask kLedEnMask;
  LedPwm(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x1C + SPECIFIC_REGISTER_OFFSET;
};

struct FaultBatfetCnfg : I2CRegister {
  struct WdFltBfFetEnMask : public Mask {
    static const uint8_t OPENED = BITS_NONE;
    static const uint8_t CLOSED = BITS_0;
    WdFltBfFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct ThmSusBFetEnMask : public Mask {
    static const uint8_t OPENED = BITS_NONE;
    static const uint8_t CLOSED = BITS_1;
    ThmSusBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct TShdnBFetEnMask : public Mask {
    static const uint8_t OPENED = BITS_NONE;
    static const uint8_t CLOSED = BITS_2;
    TShdnBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct TmrFltBFetEnMask : public Mask {
    static const uint8_t OPENED = BITS_NONE;
    static const uint8_t CLOSED = BITS_3;
    TmrFltBFetEnMask(uint8_t mask) : Mask(mask) {}
  };
  static const WdFltBfFetEnMask kWdFltBfFetEnMask;
  static const ThmSusBFetEnMask kThmSusBFetEnMask;
  static const TShdnBFetEnMask kTShdnBFetEnMask;
  static const TmrFltBFetEnMask kTmrFltBFetEnMask;

  FaultBatfetCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x1D + SPECIFIC_REGISTER_OFFSET;
};
struct LedCnfg : public I2CRegister {
  struct LedFreqMask : public Mask {
    static const uint8_t _1HZ = BITS_NONE;
    static const uint8_t _0_5HZ = BITS_0;
    static const uint8_t _256HZ = BITS_1;
    static const uint8_t _8HZ = BITS_1_0;
    LedFreqMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedCurrentMask : public Mask {
    static const uint8_t _6MA = BITS_2;
    LedCurrentMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedCfgMask : public Mask {
    static const uint8_t _ON_FAULT_FLASH = BITS_NONE;
    static const uint8_t _FLASH_FAULT_ON = BITS_4;
    LedCfgMask(uint8_t mask) : Mask(mask) {}
  };
  struct LedOvrdMask : public Mask {
    static const uint8_t STATE_MACHINE_CONTROLLED = BITS_NONE;
    static const uint8_t SOFTWARE_CONTROLLED = BITS_5;
    LedOvrdMask(uint8_t mask) : Mask(mask) {}
  };

  static const LedOvrdMask kLedOvrdMask;
  static const LedFreqMask kLedFreqMask;
  static const LedCurrentMask kLedCurrentMask;
  static const LedCfgMask kLedCfgMask;

  LedCnfg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x1E + SPECIFIC_REGISTER_OFFSET;
};

// Pwrctrl.h
struct Pwrctrl0 : public I2CRegister {
  struct StandbyDlyMask : public Mask {
    static const uint8_t NO_DELAY = BITS_NONE;
    // TODO(kendall): WTF? these don't make sense
    static const uint8_t _1_32KHZ_DELAY = BITS_0;
    static const uint8_t _2_32KHZ_DELAY = BITS_1;
    static const uint8_t _3_32KHZ_DELAY = BITS_1_0;
    StandbyDlyMask(uint8_t mask) : Mask(mask) {}
  };
  struct StandbyInvMask : public Mask {
    static const uint8_t ACTIVE_HIGH = BITS_NONE;
    static const uint8_t ACTIVE_LOW = BITS_2;
    StandbyInvMask(uint8_t mask) : Mask(mask) {}
  };
  struct PoRDlyMask : public Mask {
    static const uint8_t RESETBMCU_DELAY_2MS = BITS_NONE;
    static const uint8_t RESETBMCU_DELAY_4MS = BITS_3;
    static const uint8_t RESETBMCU_DELAY_8MS = BITS_4_3;
    static const uint8_t RESETBMCU_DELAY_16MS = BITS_5;
    static const uint8_t RESETBMCU_DELAY_128MS = BITS_5_3;
    static const uint8_t RESETBMCU_DELAY_256MS = BITS_5_4;
    static const uint8_t RESETBMCU_DELAY_1024MS = BITS_5_4_3;
    PoRDlyMask(uint8_t mask) : Mask(mask) {}
  };
  struct TgResetMask : public Mask {
    static const uint8_t _4S = BITS_NONE;
    static const uint8_t _8S = BITS_6;
    static const uint8_t _12S = BITS_7;
    static const uint8_t _16S = BITS_7_6;
    TgResetMask(uint8_t mask) : Mask(mask) {}
  };

  static const StandbyDlyMask kStandbyDlyMask;
  static const StandbyInvMask kStandbyInvMask;
  static const PoRDlyMask kPoRDlyMask;
  static const TgResetMask kTgResetMask;

  Pwrctrl0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x58;
};

struct Pwrctrl1 : public I2CRegister {
  struct PwronDbncMask : public Mask {
    // TODO(knedall): WTF? the first 2 are duplicated
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_1 = BITS_NONE;
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_2 = BITS_0;
    static const uint8_t _125MS_FALL_31_25MS_RISE = BITS_1;
    static const uint8_t _750MS_FALL_31_25MS_RISE = BITS_1_0;
    PwronDbncMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyBbncMask : public Mask {
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_1 = BITS_NONE;
    static const uint8_t _31_25MS_FALL_31_25MS_RISE_2 = BITS_2;
    static const uint8_t _125MS_FALL_31_25MS_RISE = BITS_3;
    static const uint8_t _750MS_FALL_31_25MS_RISE = BITS_3_2;
    OnkeyBbncMask(uint8_t mask) : Mask(mask) {}
  };
  struct PwronRstEnMask : public Mask {
    static const uint8_t LONG_PRESS_SLEEP_OR_REGS_DISABLE = BITS_4;
    static const uint8_t LONG_PRESS_NO_SLEEP_OR_REGS_DISABLE = BITS_NONE;
    PwronRstEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct RestartEnMask : public Mask {
    static const uint8_t RESTART_AFTER_5S = BITS_5;
    static const uint8_t NO_EFFECT = BITS_NONE;
    RestartEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct RegScpEnMask : public Mask {
    static const uint8_t _LDO_ON_CURRENT_LIMIT_FAULT = BITS_6;
    static const uint8_t _SHUTDOWN_LDO_ON_CURRENT_LIMIT_FAULT = BITS_NONE;
    RegScpEnMask(uint8_t mask) : Mask(mask) {}
  };
  struct OnkeyRstEnmask : public Mask {
    static const uint8_t ONKEY_RESET = BITS_7;
    static const uint8_t NO_ONKEY_RESET = BITS_NONE;
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
  static const uint8_t kRegister = 0x59;
};

struct Pwrctrl2 : public I2CRegister {
  struct UvdetMask : public Mask {
    static const uint8_t _2_65_RISE_2_55_FALL = BITS_NONE;
    static const uint8_t _2_8_RISE_2_7_FALL = BITS_0;
    static const uint8_t _3_0_RISE_2_9_FALL = BITS_1;
    static const uint8_t _3_1_RISE_3_0_FALL = BITS_1_0;
    UvdetMask(uint8_t mask) : Mask(mask) {}
  };
  struct LowSysWarnMask : public Mask {
    static const uint8_t _3_3_RISE_3_1_FALL = BITS_NONE;
    static const uint8_t _3_5_RISE_3_3_FALL = BITS_2;
    static const uint8_t _3_7_RISE_3_5_FALL = BITS_3;
    static const uint8_t _3_9_RISE_3_7_FALL = BITS_3_2;
    LowSysWarnMask(uint8_t mask) : Mask(mask) {}
  };

  static const LowSysWarnMask kLowSysWarnMask;
  static const UvdetMask kUvdetMask;

  Pwrctrl2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x5A;
};

struct Pwrctrl3 : public I2CRegister {
  struct GotoShipMask : public Mask {
    static const uint8_t GOTO_SHIP_EN = BITS_0;
    GotoShipMask(uint8_t mask) : Mask(mask) {}
  };
  struct GotoCoreOffMask : public Mask {
    static const uint8_t GOTO_CORE_OFF_EN = BITS_1;
    GotoCoreOffMask(uint8_t mask) : Mask(mask) {}
  };

  static const GotoShipMask kGotoShipMask;
  static const GotoCoreOffMask kGotoCoreOffMask;

  Pwrctrl3(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

  void GotoShip() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kGotoShipMask.kMask & kGotoShipMask.GOTO_SHIP_EN));
    WriteRegister(data);
  }

  void CoreOff() {
    auto register_data = ReadRegister();
    auto data = (register_data |
                 (kGotoCoreOffMask.kMask & kGotoCoreOffMask.GOTO_CORE_OFF_EN));
    WriteRegister(data);
  }

private:
  static const uint8_t kRegister = 0x5B;
};
// End of pwrctrl.h

// LDOy.h
struct LdoIntStat0 : public I2CRegister {
  struct Ldo1FaultIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_0;
    Ldo1FaultIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_1;
    Ldo2FaultIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultIMask : public Mask {
    static const uint8_t CLEARED = BITS_NONE;
    static const uint8_t ACTIVE = BITS_2;
    Ldo3FaultIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Ldo1FaultIMask kLdo1FaultIMask;
  static const Ldo2FaultIMask kLdo2FaultIMask;
  static const Ldo3FaultIMask kLdo3FaultIMask;

  LdoIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x18;
};
struct LdoIntMask0 : public I2CRegister {
  struct Ldo1FaultMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    Ldo1FaultMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_1;
    Ldo2FaultMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_2;
    Ldo3FaultMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Ldo1FaultMMask kLdo1FaultMMask;
  static const Ldo2FaultMMask kLdo2FaultMMask;
  static const Ldo3FaultMMask kLdo3FaultMMask;

  LdoIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x19;
};

struct LdoIntSense0 : public I2CRegister {
  struct Ldo1FaultSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_0;
    Ldo1FaultSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo2FaultSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_1;
    Ldo2FaultSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Ldo3FaultSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_2;
    Ldo3FaultSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Ldo1FaultSMask kLdo1FaultSMask;
  static const Ldo2FaultSMask kLdo2FaultSMask;
  static const Ldo3FaultSMask kLdo3FaultSMask;

  LdoIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x1A;
};

namespace LDOy {
struct Volt : public I2CRegister {
  struct VoltMask : public Mask {
    static const uint8_t _0_75 = BITS_NONE;
    static const uint8_t _0_80 = BITS_0;
    static const uint8_t _0_85 = BITS_1;
    static const uint8_t _0_90 = BITS_1_0;
    static const uint8_t _0_95 = BITS_2;
    static const uint8_t _1_00 = BITS_2_0;
    static const uint8_t _1_05 = BITS_2_1;
    static const uint8_t _1_10 = BITS_2_1_0;
    static const uint8_t _1_15 = BITS_3;
    static const uint8_t _1_20 = BITS_3_0;
    static const uint8_t _1_25 = BITS_3_1;
    static const uint8_t _1_30 = BITS_3_1_0;
    static const uint8_t _1_35 = BITS_3_2;
    static const uint8_t _1_40 = BITS_3_2_0;
    static const uint8_t _1_45 = BITS_3_2_1;
    static const uint8_t _1_50 = BITS_3_2_1_0;
    static const uint8_t _1_80 = BITS_4;
    static const uint8_t _1_90 = BITS_4_0;
    static const uint8_t _2_00 = BITS_4_1;
    static const uint8_t _2_10 = BITS_4_1_0;
    static const uint8_t _2_20 = BITS_4_2;
    static const uint8_t _2_30 = BITS_4_2_0;
    static const uint8_t _2_40 = BITS_4_2_1;
    static const uint8_t _2_50 = BITS_4_2_1_0;
    static const uint8_t _2_60 = BITS_4_3;
    static const uint8_t _2_70 = BITS_4_3_0;
    static const uint8_t _2_80 = BITS_4_3_1;
    static const uint8_t _2_90 = BITS_4_3_1_0;
    static const uint8_t _3_00 = BITS_4_3_2;
    static const uint8_t _3_10 = BITS_4_3_2_0;
    static const uint8_t _3_20 = BITS_4_3_2_1;
    static const uint8_t _3_30 = BITS_4_3_2_1_0;
    VoltMask(uint8_t mask) : Mask(mask) {}
  };

  static const VoltMask kVoltMask;
  Volt(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
};
struct Ctrl : public I2CRegister {
  struct EnableMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    EnableMask(uint8_t mask) : Mask(mask) {}
  };
  struct StbyMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t ENABLED = BITS_1;
    StbyMask(uint8_t mask) : Mask(mask) {}
  };
  struct OmodeMask : public Mask {
    static const uint8_t DISABLED = BITS_NONE;
    static const uint8_t ENABLED = BITS_2;
    OmodeMask(uint8_t mask) : Mask(mask) {}
  };
  struct LPwrMask : public Mask {
    static const uint8_t IN_SLP_AND_STBY = BITS_3;
    static const uint8_t NOT_IN_SLP_AND_STBY = BITS_NONE;
    LPwrMask(uint8_t mask) : Mask(mask) {}
  };
  struct LsMask : public Mask {
    static const uint8_t SWITCH_MODE = BITS_4;
    static const uint8_t LDO_MODE = BITS_NONE;
    LsMask(uint8_t mask) : Mask(mask) {}
  };

  static const EnableMask kEnableMask;
  static const StbyMask kStbyMask;
  static const OmodeMask kOmodeMask;
  static const LPwrMask kLPwrMask;
  static const LsMask kLsMask;

  Ctrl(uint8_t device_address, uint8_t register_address)
      : I2CRegister(device_address, register_address) {}
  void Enable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kEnableMask.kMask & kEnableMask.ENABLED));
    WriteRegister(data);
  }
  void Disable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kEnableMask.kMask & kEnableMask.DISABLED));
    WriteRegister(data);
  }
  void StbyEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kStbyMask.kMask & kStbyMask.ENABLED));
    WriteRegister(data);
  }
  void StbyDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kStbyMask.kMask & kStbyMask.DISABLED));
    WriteRegister(data);
  }
  void OmodeEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.ENABLED));
    WriteRegister(data);
  }

  void OmodeDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.DISABLED));
    WriteRegister(data);
  }

  void ForceLPwr() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kLPwrMask.kMask & kLPwrMask.IN_SLP_AND_STBY));
    WriteRegister(data);
  }

  void DisableLPwr() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kLPwrMask.kMask & kLPwrMask.NOT_IN_SLP_AND_STBY));
    WriteRegister(data);
  }
  void LdoMode() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kLsMask.kMask & kLsMask.LDO_MODE));
    WriteRegister(data);
  }

  void SwMode() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kLsMask.kMask & kLsMask.SWITCH_MODE));
    WriteRegister(data);
  }
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
}; // namespace LDOy

namespace Ldo1 {
struct Volt : public LDOy::Volt {
  Volt(uint8_t device_address) : LDOy::Volt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x4C;
};
struct Ctrl : public LDOy::Ctrl {
  Ctrl(uint8_t device_address) : LDOy::Ctrl(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x4D;
};
struct PwrDnSeq : public LDOy::PwrDnSeq {
  PwrDnSeq(uint8_t device_address)
      : LDOy::PwrDnSeq(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x62;
};
} // namespace Ldo1
namespace Ldo2 {
struct Volt : public LDOy::Volt {
  Volt(uint8_t device_address) : LDOy::Volt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x4F;
};
struct Ctrl : public LDOy::Ctrl {
  Ctrl(uint8_t device_address) : LDOy::Ctrl(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x50;
};
struct PwrDnSeq : public LDOy::PwrDnSeq {
  PwrDnSeq(uint8_t device_address)
      : LDOy::PwrDnSeq(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x63;
};
} // namespace Ldo2
namespace Ldo3 {
struct Volt : public LDOy::Volt {
  Volt(uint8_t device_address) : LDOy::Volt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x52;
};
struct Ctrl : public LDOy::Ctrl {
  Ctrl(uint8_t device_address) : LDOy::Ctrl(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x53;
};
struct PwrDnSeq : public LDOy::PwrDnSeq {
  PwrDnSeq(uint8_t device_address)
      : LDOy::PwrDnSeq(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x64;
};
} // namespace Ldo3

// end of LDOy.h
// Swx.h

struct SwIntStat0 : public I2CRegister {
  struct Sw1LsIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_0;
    Sw1LsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_1;
    Sw2LsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_2;
    Sw3LsIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1LsIMask kSw1LsIMask;
  static const Sw2LsIMask kSw2LsIMask;
  static const Sw3LsIMask kSw3LsIMask;

  SwIntStat0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x08;
};
struct SwIntMask0 : public I2CRegister {
  struct Sw1LsMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    Sw1LsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_1;
    Sw2LsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_2;
    Sw3LsMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1LsMMask kSw1LsMMask;
  static const Sw2LsMMask kSw2LsMMask;
  static const Sw3LsMMask kSw3LsMMask;

  SwIntMask0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x09;
};
struct SwIntSense0 : public I2CRegister {
  struct Sw1LsSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_0;
    Sw1LsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2LsSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_1;
    Sw2LsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3LsSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_2;
    Sw3LsSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1LsSMask kSw1LsSMask;
  static const Sw2LsSMask kSw2LsSMask;
  static const Sw3LsSMask kSw3LsSMask;

  SwIntSense0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0A;
};
struct SwIntStat1 : public I2CRegister {
  struct Sw1HsIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_0;
    Sw1HsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_1;
    Sw2HsIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_2;
    Sw3HsIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1HsIMask kSw1HsIMask;
  static const Sw2HsIMask kSw2HsIMask;
  static const Sw3HsIMask kSw3HsIMask;

  SwIntStat1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0B;
};
struct SwIntMask1 : public I2CRegister {
  struct Sw1HsMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    Sw1HsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_1;
    Sw2HsMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_2;
    Sw3HsMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1HsMMask kSw1HsMMask;
  static const Sw2HsMMask kSw2HsMMask;
  static const Sw3HsMMask kSw3HsMMask;

  SwIntMask1(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0C;
};
struct SwIntSense1 : public I2CRegister {
  struct Sw1HsSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_0;
    Sw1HsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2HsSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_1;
    Sw2HsSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3HsSMask : public Mask {
    static const uint8_t FAULT_REMOVED = BITS_NONE;
    static const uint8_t FAULT_EXISTS = BITS_2;
    Sw3HsSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1HsSMask kSw1HsSMask;
  static const Sw2HsSMask kSw2HsSMask;
  static const Sw3HsSMask kSw3HsSMask;

  SwIntSense1(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0D;
};

struct SwIntStat2 : public I2CRegister {
  struct Sw1DvsDoneIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_0;
    Sw1DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_1;
    Sw2DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneIMask : public Mask {
    static const uint8_t CLEAR = BITS_NONE;
    static const uint8_t INT = BITS_2;
    Sw3DvsDoneIMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1DvsDoneIMask kSw1DvsDoneIMask;
  static const Sw2DvsDoneIMask kSw2DvsDoneIMask;
  static const Sw3DvsDoneIMask kSw3DvsDoneIMask;

  SwIntStat2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0E;
};
struct SwIntMask2 : public I2CRegister {
  struct Sw1DvsDoneMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_0;
    Sw1DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_1;
    Sw2DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneMMask : public Mask {
    static const uint8_t REMOVED = BITS_NONE;
    static const uint8_t ENABLED = BITS_2;
    Sw3DvsDoneMMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1DvsDoneMMask kSw1DvsDoneMMask;
  static const Sw2DvsDoneMMask kSw2DvsDoneMMask;
  static const Sw3DvsDoneMMask kSw3DvsDoneMMask;

  SwIntMask2(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x0F;
};
struct SwIntSense2 : public I2CRegister {
  struct Sw1DvsDoneSMask : public Mask {
    static const uint8_t NOT_IN_PROGRESS = BITS_NONE;
    static const uint8_t IN_PROGRESS = BITS_0;
    Sw1DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw2DvsDoneSMask : public Mask {
    static const uint8_t NOT_IN_PROGRESS = BITS_NONE;
    static const uint8_t IN_PROGRESS = BITS_1;
    Sw2DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };
  struct Sw3DvsDoneSMask : public Mask {
    static const uint8_t NOT_IN_PROGRESS = BITS_NONE;
    static const uint8_t IN_PROGRESS = BITS_2;
    Sw3DvsDoneSMask(uint8_t mask) : Mask(mask) {}
  };

  static const Sw1DvsDoneSMask kSw1DvsDoneSMask;
  static const Sw2DvsDoneSMask kSw2DvsDoneSMask;
  static const Sw3DvsDoneSMask kSw3DvsDoneSMask;

  SwIntSense2(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static const uint8_t kRegister = 0x10;
};

namespace SWx {
/**/
struct OtpSWxDvsSelEnVolt {
  static const uint8_t _0_6000 = BITS_NONE;
  static const uint8_t _0_6125 = BITS_0;
  static const uint8_t _0_6250 = BITS_1;
  static const uint8_t _0_6375 = BITS_1_0;
  static const uint8_t _0_6500 = BITS_2;
  static const uint8_t _0_6625 = BITS_2_0;
  static const uint8_t _0_6750 = BITS_2_1;
  static const uint8_t _0_6875 = BITS_2_1_0;
  static const uint8_t _0_7000 = BITS_3;
  static const uint8_t _0_7125 = BITS_3_0;
  static const uint8_t _0_7250 = BITS_3_1;
  static const uint8_t _0_7375 = BITS_3_1_0;
  static const uint8_t _0_7500 = BITS_3_2;
  static const uint8_t _0_7625 = BITS_3_2_0;
  static const uint8_t _0_7750 = BITS_3_2_1;
  static const uint8_t _0_7875 = BITS_3_2_1_0;
  static const uint8_t _0_8000 = BITS_4;
  static const uint8_t _0_8125 = BITS_4_0;
  static const uint8_t _0_8250 = BITS_4_1;
  static const uint8_t _0_8375 = BITS_4_1_0;
  static const uint8_t _0_8500 = BITS_4_2;
  static const uint8_t _0_8625 = BITS_4_2_0;
  static const uint8_t _0_8750 = BITS_4_2_1;
  static const uint8_t _0_8875 = BITS_4_2_1_0;
  static const uint8_t _0_9000 = BITS_4_3;
  static const uint8_t _0_9125 = BITS_4_3_0;
  static const uint8_t _0_9250 = BITS_4_3_1;
  static const uint8_t _0_9375 = BITS_4_3_1_0;
  static const uint8_t _0_9500 = BITS_4_3_2;
  static const uint8_t _0_9625 = BITS_4_3_2_0;
  static const uint8_t _0_9750 = BITS_4_3_2_1;
  static const uint8_t _0_9875 = BITS_4_3_2_1_0;
  static const uint8_t _1_0000 = BITS_5;
  static const uint8_t _1_0125 = BITS_5_0;
  static const uint8_t _1_0250 = BITS_5_1;
  static const uint8_t _1_0375 = BITS_5_1_0;
  static const uint8_t _1_0500 = BITS_5_2;
  static const uint8_t _1_0625 = BITS_5_2_0;
  static const uint8_t _1_0750 = BITS_5_2_1;
  static const uint8_t _1_0875 = BITS_5_2_1_0;
  static const uint8_t _1_1000 = BITS_5_3;
  static const uint8_t _1_1125 = BITS_5_3_0;
  static const uint8_t _1_125 = BITS_5_3_1;
  static const uint8_t _1_1375 = BITS_5_3_1_0;
  static const uint8_t _1_1500 = BITS_5_3_2;
  static const uint8_t _1_1625 = BITS_5_3_2_0;
  static const uint8_t _1_1750 = BITS_5_3_2_1;
  static const uint8_t _1_1875 = BITS_5_3_2_1_0;
  static const uint8_t _1_2000 = BITS_5_4;
  static const uint8_t _1_2125 = BITS_5_4_0;
  static const uint8_t _1_2250 = BITS_5_4_1;
  static const uint8_t _1_2375 = BITS_5_4_1_0;
  static const uint8_t _1_2500 = BITS_5_4_2;
  static const uint8_t _1_2625 = BITS_5_4_2_0;
  static const uint8_t _1_2750 = BITS_5_4_2_1;
  static const uint8_t _1_2875 = BITS_5_4_2_1_0;
  static const uint8_t _1_3000 = BITS_5_4_3;
  static const uint8_t _1_3125 = BITS_5_4_3_0;
  static const uint8_t _1_3250 = BITS_5_4_3_1;
  static const uint8_t _1_3375 = BITS_5_4_3_1_0;
  static const uint8_t _1_3500 = BITS_5_4_3_2;
  static const uint8_t _1_3625 = BITS_5_4_3_2_0;
  static const uint8_t _1_3750 = BITS_5_4_3_2_1;
  static const uint8_t _1_3875 = BITS_5_4_3_2_1_0;
};

struct OtpSWxDvsSelDisVolt {
  static const uint8_t _1_10 = BITS_NONE;
  static const uint8_t _1_20 = BITS_0;
  static const uint8_t _1_35 = BITS_1;
  static const uint8_t _1_50 = BITS_1_0;
  static const uint8_t _1_80 = BITS_2;
  static const uint8_t _2_50 = BITS_2_0;
  // TODO(kendall): This is absurd. Figure this out...
  static const uint8_t _3_30_0 = BITS_2_1;
  static const uint8_t _3_30_1 = BITS_2_1_0;
  static const uint8_t _3_30_2 = BITS_3;
  static const uint8_t _3_30_3 = BITS_3_0;
  static const uint8_t _3_30_4 = BITS_3_1;
  static const uint8_t _3_30_5 = BITS_3_1_0;
  static const uint8_t _3_30_6 = BITS_3_2;
  static const uint8_t _3_30_7 = BITS_3_2_0;
  static const uint8_t _3_30_8 = BITS_3_2_1;
  static const uint8_t _3_30_9 = BITS_3_2_1_0;
  static const uint8_t _3_30_10 = BITS_4;
  static const uint8_t _3_30_11 = BITS_4_0;
  static const uint8_t _3_30_12 = BITS_4_1;
  static const uint8_t _3_30_13 = BITS_4_1_0;
  static const uint8_t _3_30_14 = BITS_4_2;
  static const uint8_t _3_30_15 = BITS_4_2_0;
  static const uint8_t _3_30_16 = BITS_4_2_1;
  static const uint8_t _3_30_17 = BITS_4_2_1_0;
  static const uint8_t _3_30_18 = BITS_4_3;
  static const uint8_t _3_30_19 = BITS_4_3_0;
  static const uint8_t _3_30_20 = BITS_4_3_1;
  static const uint8_t _3_30_21 = BITS_4_3_1_0;
  static const uint8_t _3_30_22 = BITS_4_3_2;
  static const uint8_t _3_30_23 = BITS_4_3_2_0;
  static const uint8_t _3_30_24 = BITS_4_3_2_1;
  static const uint8_t _3_30_25 = BITS_4_3_2_1_0;
  static const uint8_t _3_30_26 = BITS_5;
  static const uint8_t _3_30_27 = BITS_5_0;
  static const uint8_t _3_30_28 = BITS_5_1;
  static const uint8_t _3_30_29 = BITS_5_1_0;
  static const uint8_t _3_30_30 = BITS_5_2;
  static const uint8_t _3_30_31 = BITS_5_2_0;
  static const uint8_t _3_30_32 = BITS_5_2_1;
  static const uint8_t _3_30_33 = BITS_5_2_1_0;
  static const uint8_t _3_30_34 = BITS_5_3;
  static const uint8_t _3_30_35 = BITS_5_3_0;
  static const uint8_t _3_30_36 = BITS_5_3_1;
  static const uint8_t _3_30_37 = BITS_5_3_1_0;
  static const uint8_t _3_30_38 = BITS_5_3_2;
  static const uint8_t _3_30_39 = BITS_5_3_2_0;
  static const uint8_t _3_30_40 = BITS_5_3_2_1;
  static const uint8_t _3_30_41 = BITS_5_3_2_1_0;
  static const uint8_t _3_30_42 = BITS_5_4;
  static const uint8_t _3_30_43 = BITS_5_4_0;
  static const uint8_t _3_30_44 = BITS_5_4_1;
  static const uint8_t _3_30_45 = BITS_5_4_1_0;
  static const uint8_t _3_30_46 = BITS_5_4_2;
  static const uint8_t _3_30_47 = BITS_5_4_2_0;
  static const uint8_t _3_30_48 = BITS_5_4_2_1;
  static const uint8_t _3_30_49 = BITS_5_4_2_1_0;
  static const uint8_t _3_30_50 = BITS_5_4_3;
  static const uint8_t _3_30_51 = BITS_5_4_3_0;
  static const uint8_t _3_30_52 = BITS_5_4_3_1;
  static const uint8_t _3_30_53 = BITS_5_4_3_1_0;
  static const uint8_t _3_30_54 = BITS_5_4_3_2;
  static const uint8_t _3_30_55 = BITS_5_4_3_2_0;
  static const uint8_t _3_30_56 = BITS_5_4_3_2_1;
  static const uint8_t _3_30_57 = BITS_5_4_3_2_1_0;
};
struct Volt : public I2CRegister {
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
// TODO(kendall): Figure out if this is actually a register.
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
  void Enable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kEnableMask.kMask & kEnableMask.ENABLED));
    WriteRegister(data);
  }
  void Disable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kEnableMask.kMask & kEnableMask.DISABLED));
    WriteRegister(data);
  }
  void StbyEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kStbyMask.kMask & kStbyMask.ENABLED));
    WriteRegister(data);
  }
  void StbyDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kStbyMask.kMask & kStbyMask.DISABLED));
    WriteRegister(data);
  }
  void OmodeEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.ENABLED));
    WriteRegister(data);
  }
  void OmodeDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.DISABLED));
    WriteRegister(data);
  }
  void LPwrEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kLPwrMask.kMask & kLPwrMask.ENABLED));
    WriteRegister(data);
  }
  void LPwrDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kLPwrMask.kMask & kLPwrMask.DISABLED));
    WriteRegister(data);
  }
  void DvsSpeed2us() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kDvsSpeedMask.kMask & kDvsSpeedMask._12_5MV_DIV_2US));
    WriteRegister(data);
  }
  void DvsSpeed4us() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kDvsSpeedMask.kMask & kDvsSpeedMask._12_5MV_DIV_4US));
    WriteRegister(data);
  }
  void FPwmInDvsForce() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kFPwmInDvsMask.kMask & kFPwmInDvsMask.FORCE));
    WriteRegister(data);
  }
  void FPwmInDvsNoForce() {
    auto register_data = ReadRegister();
    auto data =
        (register_data | (kFPwmInDvsMask.kMask & kFPwmInDvsMask.NO_FORCE));
    WriteRegister(data);
  }
  void FPwmEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kFPwmMask.kMask & kFPwmMask.FPWM_ON));
    WriteRegister(data);
  }
  void FPwmDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kFPwmMask.kMask & kFPwmMask.NO_FPWM));
    WriteRegister(data);
  }
  void RDisEnable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kRDisMask.kMask & kRDisMask.ENABLED));
    WriteRegister(data);
  }
  void RDisDisable() {
    auto register_data = ReadRegister();
    auto data = (register_data | (kRDisMask.kMask & kRDisMask.DISABLED));
    WriteRegister(data);
  }
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

namespace Sw1 {
struct Volt : public SWx::Volt {
  Volt(uint8_t device_address) : SWx::Volt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x32;
};
struct StbyVolt : public SWx::StbyVolt {
  StbyVolt(uint8_t device_address) : SWx::StbyVolt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x33;
};
struct SlpVolt : public SWx::SlpVolt {
  SlpVolt(uint8_t device_address) : SWx::SlpVolt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x34;
};
struct PwrUp : public SWx::PwrUp {
  PwrUp(uint8_t device_address) : SWx::PwrUp(device_address, kRegister){};

private:
  static const uint8_t kRegister;
};
struct Ctrl : public SWx::Ctrl {
  Ctrl(uint8_t device_address) : SWx::Ctrl(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x35;
};
struct Ctrl1 : public SWx::Ctrl1 {
  Ctrl1(uint8_t device_address) : SWx::Ctrl1(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x36;
  // Misnamed in data sheet as SLP_VOLT
};
struct PwrDnSeq : public SWx::PwrDnSeq {
  PwrDnSeq(uint8_t device_address) : SWx::PwrDnSeq(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x5F;
};

} // namespace Sw1
namespace Sw2 {
struct Volt : public SWx::Volt {
  Volt(uint8_t device_address) : SWx::Volt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x38;
};
struct StbyVolt : public SWx::StbyVolt {
  StbyVolt(uint8_t device_address) : SWx::StbyVolt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x39;
};
struct SlpVolt : public SWx::SlpVolt {
  SlpVolt(uint8_t device_address) : SWx::SlpVolt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x3A;
};
struct PwrUp : public SWx::PwrUp {
  PwrUp(uint8_t device_address) : SWx::PwrUp(device_address, kRegister){};

private:
  static const uint8_t kRegister;
};
struct Ctrl : public SWx::Ctrl {
  Ctrl(uint8_t device_address) : SWx::Ctrl(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x3B;
};
struct Ctrl1 : public SWx::Ctrl1 {
  Ctrl1(uint8_t device_address) : SWx::Ctrl1(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x3C;
};
struct PwrDnSeq : public SWx::PwrDnSeq {
  PwrDnSeq(uint8_t device_address) : SWx::PwrDnSeq(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x60;
};

} // namespace Sw2
namespace Sw3 {
struct Volt : public SWx::Volt {
  Volt(uint8_t device_address) : SWx::Volt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x3E;
};
struct StbyVolt : public SWx::StbyVolt {
  StbyVolt(uint8_t device_address) : SWx::StbyVolt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x3F;
};
struct SlpVolt : public SWx::SlpVolt {
  SlpVolt(uint8_t device_address) : SWx::SlpVolt(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x40;
};
struct PwrUp : public SWx::PwrUp {
  PwrUp(uint8_t device_address) : SWx::PwrUp(device_address, kRegister){};

private:
  static const uint8_t kRegister;
};
struct Ctrl : public SWx::Ctrl {
  Ctrl(uint8_t device_address) : SWx::Ctrl(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x41;
};
struct Ctrl1 : public SWx::Ctrl1 {
  Ctrl1(uint8_t device_address) : SWx::Ctrl1(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x42;
};
struct PwrDnSeq : public SWx::PwrDnSeq {
  PwrDnSeq(uint8_t device_address) : SWx::PwrDnSeq(device_address, kRegister){};

private:
  static const uint8_t kRegister = 0x61;
};

} // namespace Sw3
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
  PF1550(uint8_t device_address = I2cAddr::kAddrMask.I2C_ADDR_DEFAULT)
      : registers_(Registers(device_address)...) {}

  template <typename R> decltype(auto) get_register() {
    return std::get<count_first_falses((std::is_same<Registers, R>::value)...)>(
        registers_);
  }

  void Initialize() { Wire.begin(); };
  friend class PF1550Test;
};
} // namespace PMIC