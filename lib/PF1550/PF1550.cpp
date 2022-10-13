#include "PF1550.h"

// DeviceInfo.h
const uint8_t DeviceId::kRegister = 0x00;
const DeviceId::DeviceIdMask DeviceId::kDeviceIdMask(BITS_2_1_0);
const uint8_t DeviceId::DeviceIdMask::kPF1550Mask = BITS_2;
const uint8_t DeviceId::DeviceIdMask::kPF1500Mask = BITS_NONE;

const uint8_t OTPFlavor::kRegister = 0x01;
const OTPFlavor::ModelMask OTPFlavor::kModelMask(BITS_ALL);
const uint8_t OTPFlavor::ModelMask::A0 = 0x00;
const uint8_t OTPFlavor::ModelMask::A1 = 0x01;
const uint8_t OTPFlavor::ModelMask::A2 = 0x02;
const uint8_t OTPFlavor::ModelMask::A3 = 0x03;
const uint8_t OTPFlavor::ModelMask::A4 = 0x04;
const uint8_t OTPFlavor::ModelMask::A5 = 0x05;
const uint8_t OTPFlavor::ModelMask::A6 = 0x06;
const uint8_t OTPFlavor::ModelMask::A7 = 0x07;
const uint8_t OTPFlavor::ModelMask::A8 = 0x08;
const uint8_t OTPFlavor::ModelMask::A9 = 0x09;

const uint8_t SiliconRev::kRegister = 0x02;
const SiliconRev::MetalLayerRevMask SiliconRev::kMetalLayerRevMask(BITS_2_1_0);
const SiliconRev::FullLayerRevMask SiliconRev::kFullLayerRevMask(BITS_5_4_3);
const SiliconRev::FabFinMask SiliconRev::kFabFinMask(BITS_7_6);

const uint8_t StateInfo::kRegister = 0x67;
const StateInfo::StateMask StateInfo::kStateMask(BITS_ALL);
const uint8_t StateInfo::StateMask::WAIT = BITS_NONE;
const uint8_t StateInfo::StateMask::RUN = BITS_3_2;
const uint8_t StateInfo::StateMask::STANDBY = BITS_3_2_0;
const uint8_t StateInfo::StateMask::SLEEP = BITS_3_2_1;
const uint8_t StateInfo::StateMask::REG_DISABLE = BITS_5_3_1_0;

const uint8_t I2CAddr::kRegister = 0x68;
const I2CAddr::AddrMask I2CAddr::kAddrMask(BITS_2_1_0);
const uint8_t I2CAddr::AddrMask::DEFAULT = 0x08;
const uint8_t I2CAddr::AddrMask::X08 = BITS_NONE;
const uint8_t I2CAddr::AddrMask::X09 = BITS_0;
const uint8_t I2CAddr::AddrMask::X0A = BITS_1;
const uint8_t I2CAddr::AddrMask::X0B = BITS_1_0;
const uint8_t I2CAddr::AddrMask::X0C = BITS_2;
const uint8_t I2CAddr::AddrMask::X0D = BITS_2_0;
const uint8_t I2CAddr::AddrMask::X0E = BITS_2_1;
const uint8_t I2CAddr::AddrMask::X0F = BITS_2_1_0;

const uint8_t RC16Mhz::kRegister = 0x6B;
const RC16Mhz::Req16MhzMask RC16Mhz::kReq16MhzMask(BITS_0);
const uint8_t RC16Mhz::Req16MhzMask::ALWAYS_ON = BITS_1;
const uint8_t RC16Mhz::Req16MhzMask::STATEMACHINE_EN = BITS_NONE;
const RC16Mhz::ReqAcoreOnMask RC16Mhz::kReqAcoreOnMask(BITS_1);
const uint8_t RC16Mhz::ReqAcoreOnMask::ALWAYS_ON = BITS_1;
const uint8_t RC16Mhz::ReqAcoreOnMask::STATEMACHINE_EN = BITS_NONE;
const RC16Mhz::ReqAcoreHiPwrMask RC16Mhz::kReqAcoreHiPwrMask(BITS_2);
const uint8_t RC16Mhz::ReqAcoreHiPwrMask::LOW_POWER_STATEMACHINE_CONTROLLED =
    BITS_NONE;
const uint8_t RC16Mhz::ReqAcoreHiPwrMask::LOW_POWER_NEVER = BITS_2;
// End DeviceInfo.h

// Misc.h
const uint8_t IntCategory::kRegister = 0x06;
const IntCategory::ChgIntMask IntCategory::kChgIntMask(BITS_0);
const uint8_t IntCategory::ChgIntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::ChgIntMask::OR_BITS = BITS_0;
const IntCategory::Sw1IntMask IntCategory::kSw1IntMask(BITS_1);
const uint8_t IntCategory::Sw1IntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::Sw1IntMask::ANY = BITS_1;
const IntCategory::Sw2IntMask IntCategory::kSw2IntMask(BITS_2);
const uint8_t IntCategory::Sw2IntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::Sw2IntMask::ANY = BITS_2;
const IntCategory::Sw3IntMask IntCategory::kSw3IntMask(BITS_3);
const uint8_t IntCategory::Sw3IntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::Sw3IntMask::ANY = BITS_3;
const IntCategory::LdoIntMask IntCategory::kLdoIntMask(BITS_4);
const uint8_t IntCategory::LdoIntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::LdoIntMask::ANY = BITS_4;
const IntCategory::OnkeyIntMask IntCategory::kOnkeyIntMask(BITS_5);
const uint8_t IntCategory::OnkeyIntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::OnkeyIntMask::ANY = BITS_5;
const IntCategory::TempIntMask IntCategory::kTempIntMask(BITS_6);
const uint8_t IntCategory::TempIntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::TempIntMask::ANY = BITS_6;
const IntCategory::MiscIntMask IntCategory::kMiscIntMask(BITS_7);
const uint8_t IntCategory::MiscIntMask::CLEAR = BITS_NONE;
const uint8_t IntCategory::MiscIntMask::ANY = BITS_7;

const uint8_t TempIntStat0::kRegister = 0x20;
const TempIntStat0::Therm110IMask TempIntStat0::kTherm110IMask(BITS_0);
const uint8_t TempIntStat0::Therm110IMask::CLEARED = BITS_NONE;
const uint8_t TempIntStat0::Therm110IMask::ACTIVE = BITS_0;
const TempIntStat0::Therm125IMask TempIntStat0::kTherm125IMask(BITS_2);
const uint8_t TempIntStat0::Therm125IMask::CLEARED = BITS_NONE;
const uint8_t TempIntStat0::Therm125IMask::ACTIVE = BITS_0;

const uint8_t TempIntMask0::kRegister = 0x21;
const TempIntMask0::Therm110MMask TempIntMask0::kTherm110MMask(BITS_0);
const uint8_t TempIntMask0::Therm110MMask::REMOVED = BITS_NONE;
const uint8_t TempIntMask0::Therm110MMask::ENABLED = BITS_0;
const TempIntMask0::Therm125MMask TempIntMask0::kTherm125MMask(BITS_2);
const uint8_t TempIntMask0::Therm125MMask::REMOVED = BITS_NONE;
const uint8_t TempIntMask0::Therm125MMask::ENABLED = BITS_0;
