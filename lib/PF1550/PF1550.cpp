#include "PF1550.h"

// DeviceInfo.h
const uint8_t DeviceId::kRegister = 0x00;
const DeviceId::DeviceIdMask DeviceId::kDeviceIdMask(BITS_2_1_0);
const uint8_t DeviceId::DeviceIdMask::kPF1550Mask = BITS_2;
const uint8_t DeviceId::DeviceIdMask::kPF1500Mask = BITS_NONE;

const uint8_t OtpFlavor::kRegister = 0x01;
const OtpFlavor::ModelMask OtpFlavor::kModelMask(BITS_ALL);
const uint8_t OtpFlavor::ModelMask::A0 = 0x00;
const uint8_t OtpFlavor::ModelMask::A1 = 0x01;
const uint8_t OtpFlavor::ModelMask::A2 = 0x02;
const uint8_t OtpFlavor::ModelMask::A3 = 0x03;
const uint8_t OtpFlavor::ModelMask::A4 = 0x04;
const uint8_t OtpFlavor::ModelMask::A5 = 0x05;
const uint8_t OtpFlavor::ModelMask::A6 = 0x06;
const uint8_t OtpFlavor::ModelMask::A7 = 0x07;
const uint8_t OtpFlavor::ModelMask::A8 = 0x08;
const uint8_t OtpFlavor::ModelMask::A9 = 0x09;

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

const uint8_t I2cAddr::kRegister = 0x68;
const I2cAddr::AddrMask I2cAddr::kAddrMask(BITS_2_1_0);
const uint8_t I2cAddr::AddrMask::DEFAULT = 0x08;
const uint8_t I2cAddr::AddrMask::X08 = BITS_NONE;
const uint8_t I2cAddr::AddrMask::X09 = BITS_0;
const uint8_t I2cAddr::AddrMask::X0A = BITS_1;
const uint8_t I2cAddr::AddrMask::X0B = BITS_1_0;
const uint8_t I2cAddr::AddrMask::X0C = BITS_2;
const uint8_t I2cAddr::AddrMask::X0D = BITS_2_0;
const uint8_t I2cAddr::AddrMask::X0E = BITS_2_1;
const uint8_t I2cAddr::AddrMask::X0F = BITS_2_1_0;

const uint8_t Rc16mhz::kRegister = 0x6B;
const Rc16mhz::Req16MhzMask Rc16mhz::kReq16MhzMask(BITS_0);
const uint8_t Rc16mhz::Req16MhzMask::ALWAYS_ON = BITS_1;
const uint8_t Rc16mhz::Req16MhzMask::STATEMACHINE_EN = BITS_NONE;
const Rc16mhz::ReqAcoreOnMask Rc16mhz::kReqAcoreOnMask(BITS_1);
const uint8_t Rc16mhz::ReqAcoreOnMask::ALWAYS_ON = BITS_1;
const uint8_t Rc16mhz::ReqAcoreOnMask::STATEMACHINE_EN = BITS_NONE;
const Rc16mhz::ReqAcoreHiPwrMask Rc16mhz::kReqAcoreHiPwrMask(BITS_2);
const uint8_t Rc16mhz::ReqAcoreHiPwrMask::LOW_POWER_STATEMACHINE_CONTROLLED =
    BITS_NONE;
const uint8_t Rc16mhz::ReqAcoreHiPwrMask::LOW_POWER_NEVER = BITS_2;
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

const uint8_t TempIntSense0::kRegister = 0x22;
const TempIntSense0::Therm110SMask TempIntSense0::kTherm110SMask(BITS_0);
const uint8_t TempIntSense0::Therm110SMask::BELOW = BITS_NONE;
const uint8_t TempIntSense0::Therm110SMask::ABOVE = BITS_0;
const TempIntSense0::Therm125SMask TempIntSense0::kTherm125SMask(BITS_2);
const uint8_t TempIntSense0::Therm125SMask::BELOW = BITS_NONE;
const uint8_t TempIntSense0::Therm125SMask::ABOVE = BITS_0;

const uint8_t OnkeyIntStat0::kRegister = 0x24;
const OnkeyIntStat0::OnkeyPushIMask OnkeyIntStat0::kOnkeyPushIMask(BITS_0);
const uint8_t OnkeyIntStat0::OnkeyPushIMask::CLEARED = BITS_NONE;
const uint8_t OnkeyIntStat0::OnkeyPushIMask::ACTIVE = BITS_0;
const OnkeyIntStat0::Onkey1SIMask OnkeyIntStat0::kOnkey1SIMask(BITS_1);
const uint8_t OnkeyIntStat0::Onkey1SIMask::CLEARED = BITS_NONE;
const uint8_t OnkeyIntStat0::Onkey1SIMask::ACTIVE = BITS_1;
const OnkeyIntStat0::Onkey2SIMask OnkeyIntStat0::kOnkey2SIMask(BITS_2);
const uint8_t OnkeyIntStat0::Onkey2SIMask::CLEARED = BITS_NONE;
const uint8_t OnkeyIntStat0::Onkey2SIMask::ACTIVE = BITS_2;
const OnkeyIntStat0::Onkey3SIMask OnkeyIntStat0::kOnkey3SIMask(BITS_3);
const uint8_t OnkeyIntStat0::Onkey3SIMask::CLEARED = BITS_NONE;
const uint8_t OnkeyIntStat0::Onkey3SIMask::ACTIVE = BITS_3;
const OnkeyIntStat0::Onkey4SIMask OnkeyIntStat0::kOnkey4SIMask(BITS_4);
const uint8_t OnkeyIntStat0::Onkey4SIMask::CLEARED = BITS_NONE;
const uint8_t OnkeyIntStat0::Onkey4SIMask::ACTIVE = BITS_4;
const OnkeyIntStat0::Onkey8SIMask OnkeyIntStat0::kOnkey8SIMask(BITS_5);
const uint8_t OnkeyIntStat0::Onkey8SIMask::CLEARED = BITS_NONE;
const uint8_t OnkeyIntStat0::Onkey8SIMask::ACTIVE = BITS_5;

const uint8_t OnkeyIntMask0::kRegister = 0x25;
const OnkeyIntMask0::OnkeyPushMMask OnkeyIntMask0::kOnkeyPushMMask(BITS_0);
const uint8_t OnkeyIntMask0::OnkeyPushMMask::REMOVED = BITS_NONE;
const uint8_t OnkeyIntMask0::OnkeyPushMMask::ENABLED = BITS_0;
const OnkeyIntMask0::Onkey1SMMask OnkeyIntMask0::kOnkey1SMMask(BITS_1);
const uint8_t OnkeyIntMask0::Onkey1SMMask::REMOVED = BITS_NONE;
const uint8_t OnkeyIntMask0::Onkey1SMMask::ENABLED = BITS_1;
const OnkeyIntMask0::Onkey2SMMask OnkeyIntMask0::kOnkey2SMMask(BITS_2);
const uint8_t OnkeyIntMask0::Onkey2SMMask::REMOVED = BITS_NONE;
const uint8_t OnkeyIntMask0::Onkey2SMMask::ENABLED = BITS_2;
const OnkeyIntMask0::Onkey3SMMask OnkeyIntMask0::kOnkey3SMMask(BITS_3);
const uint8_t OnkeyIntMask0::Onkey3SMMask::REMOVED = BITS_NONE;
const uint8_t OnkeyIntMask0::Onkey3SMMask::ENABLED = BITS_3;
const OnkeyIntMask0::Onkey4SMMask OnkeyIntMask0::kOnkey4SMMask(BITS_4);
const uint8_t OnkeyIntMask0::Onkey4SMMask::REMOVED = BITS_NONE;
const uint8_t OnkeyIntMask0::Onkey4SMMask::ENABLED = BITS_4;
const OnkeyIntMask0::Onkey8SMMask OnkeyIntMask0::kOnkey8SMMask(BITS_5);
const uint8_t OnkeyIntMask0::Onkey8SMMask::REMOVED = BITS_NONE;
const uint8_t OnkeyIntMask0::Onkey8SMMask::ENABLED = BITS_5;

const uint8_t OnkeyIntSense0::kRegister = 0x26;
const OnkeyIntSense0::OnkeyPushSMask OnkeyIntSense0::kOnkeyPushSMask(BITS_0);
const uint8_t OnkeyIntSense0::OnkeyPushSMask::NOT_PUSHED = BITS_NONE;
const uint8_t OnkeyIntSense0::OnkeyPushSMask::PUSHED = BITS_0;
const OnkeyIntSense0::Onkey1SSMask OnkeyIntSense0::kOnkey1SSMask(BITS_1);
const uint8_t OnkeyIntSense0::Onkey1SSMask::NOT_PUSHED = BITS_NONE;
const uint8_t OnkeyIntSense0::Onkey1SSMask::PUSHED = BITS_1;
const OnkeyIntSense0::Onkey2SSMask OnkeyIntSense0::kOnkey2SSMask(BITS_2);
const uint8_t OnkeyIntSense0::Onkey2SSMask::NOT_PUSHED = BITS_NONE;
const uint8_t OnkeyIntSense0::Onkey2SSMask::PUSHED = BITS_2;
const OnkeyIntSense0::Onkey3SSMask OnkeyIntSense0::kOnkey3SSMask(BITS_3);
const uint8_t OnkeyIntSense0::Onkey3SSMask::NOT_PUSHED = BITS_NONE;
const uint8_t OnkeyIntSense0::Onkey3SSMask::PUSHED = BITS_3;
const OnkeyIntSense0::Onkey4SSMask OnkeyIntSense0::kOnkey4SSMask(BITS_4);
const uint8_t OnkeyIntSense0::Onkey4SSMask::NOT_PUSHED = BITS_NONE;
const uint8_t OnkeyIntSense0::Onkey4SSMask::PUSHED = BITS_4;
const OnkeyIntSense0::Onkey8SSMask OnkeyIntSense0::kOnkey8SSMask(BITS_5);
const uint8_t OnkeyIntSense0::Onkey8SSMask::NOT_PUSHED = BITS_NONE;
const uint8_t OnkeyIntSense0::Onkey8SSMask::PUSHED = BITS_5;

const uint8_t MiscIntStat0::kRegister = 0x28;
const MiscIntStat0::PwrUpIMask MiscIntStat0::kPwrUpIMask(BITS_0);
const uint8_t MiscIntStat0::PwrUpIMask::NOT_ACTIVE = BITS_NONE;
const uint8_t MiscIntStat0::PwrUpIMask::ACTIVE = BITS_0;
const MiscIntStat0::PwrDnIMask MiscIntStat0::kPwrDnIMask(BITS_1);
const uint8_t MiscIntStat0::PwrDnIMask::NOT_ACTIVE = BITS_NONE;
const uint8_t MiscIntStat0::PwrDnIMask::ACTIVE = BITS_1;
const MiscIntStat0::PwrOnIMask MiscIntStat0::kPwrOnIMask(BITS_2);
const uint8_t MiscIntStat0::PwrOnIMask::NOT_ACTIVE = BITS_NONE;
const uint8_t MiscIntStat0::PwrOnIMask::ACTIVE = BITS_2;
const MiscIntStat0::LowSysWarnIMask MiscIntStat0::kLowSysWarnIMask(BITS_3);
const uint8_t MiscIntStat0::LowSysWarnIMask::NOT_ACTIVE = BITS_NONE;
const uint8_t MiscIntStat0::LowSysWarnIMask::ACTIVE = BITS_3;
const MiscIntStat0::SysOlvoIMask MiscIntStat0::kSysOlvoIMask(BITS_4);
const uint8_t MiscIntStat0::SysOlvoIMask::NOT_ACTIVE = BITS_NONE;
const uint8_t MiscIntStat0::SysOlvoIMask::ACTIVE = BITS_4;

const uint8_t MiscIntMask0::kRegister = 0x29;
const MiscIntMask0::PwrUpMMask MiscIntMask0::kPwrUpMMask(BITS_0);
const uint8_t MiscIntMask0::PwrUpMMask::REMOVED = BITS_NONE;
const uint8_t MiscIntMask0::PwrUpMMask::ENABLED = BITS_0;
const MiscIntMask0::PwrDnMMask MiscIntMask0::kPwrDnMMask(BITS_1);
const uint8_t MiscIntMask0::PwrDnMMask::REMOVED = BITS_NONE;
const uint8_t MiscIntMask0::PwrDnMMask::ENABLED = BITS_1;
const MiscIntMask0::PwrOnMMask MiscIntMask0::kPwrOnMMask(BITS_2);
const uint8_t MiscIntMask0::PwrOnMMask::REMOVED = BITS_NONE;
const uint8_t MiscIntMask0::PwrOnMMask::ENABLED = BITS_2;
const MiscIntMask0::LowSysWarnMMask MiscIntMask0::kLowSysWarnMMask(BITS_3);
const uint8_t MiscIntMask0::LowSysWarnMMask::REMOVED = BITS_NONE;
const uint8_t MiscIntMask0::LowSysWarnMMask::ENABLED = BITS_3;
const MiscIntMask0::SysOlvoMMask MiscIntMask0::kSysOlvoMMask(BITS_4);
const uint8_t MiscIntMask0::SysOlvoMMask::REMOVED = BITS_NONE;
const uint8_t MiscIntMask0::SysOlvoMMask::ENABLED = BITS_4;

const uint8_t MiscIntSense0::kRegister = 0x2A;
const MiscIntSense0::PwrUpSMask MiscIntSense0::kPwrUpSMask(BITS_0);
const uint8_t MiscIntSense0::PwrUpSMask::NOT_IN_PROGRESS = BITS_NONE;
const uint8_t MiscIntSense0::PwrUpSMask::IN_PROGRESS = BITS_0;
const MiscIntSense0::PwrDnSMask MiscIntSense0::kPwrDnSMask(BITS_1);
const uint8_t MiscIntSense0::PwrDnSMask::NOT_IN_PROGRESS = BITS_NONE;
const uint8_t MiscIntSense0::PwrDnSMask::IN_PROGRESS = BITS_1;
const MiscIntSense0::PwrOnSMask MiscIntSense0::kPwrOnSMask(BITS_2);
const uint8_t MiscIntSense0::PwrOnSMask::LOW = BITS_NONE;
const uint8_t MiscIntSense0::PwrOnSMask::HIGH = BITS_2;
const MiscIntSense0::LowSysWarnSMask MiscIntSense0::kLowSysWarnSMask(BITS_3);
const uint8_t MiscIntSense0::LowSysWarnSMask::BELOW = BITS_NONE;
const uint8_t MiscIntSense0::LowSysWarnSMask::ABOVE = BITS_3;
const MiscIntSense0::SysOlvoSMask MiscIntSense0::kSysOlvoSMask(BITS_4);
const uint8_t MiscIntSense0::SysOlvoSMask::BELOW = BITS_NONE;
const uint8_t MiscIntSense0::SysOlvoSMask::ABOVE = BITS_4;

const uint8_t CoincellControl::kRegister = 0x30;
const CoincellControl::VCoinMask CoincellControl::kVCoinMask(BITS_3_2_1_0);
const uint8_t CoincellControl::VCoinMask::_1_8 = BITS_NONE;
const uint8_t CoincellControl::VCoinMask::_1_9 = BITS_0;
const uint8_t CoincellControl::VCoinMask::_2_0 = BITS_1;
const uint8_t CoincellControl::VCoinMask::_2_1 = BITS_1_0;
const uint8_t CoincellControl::VCoinMask::_2_2 = BITS_2;
const uint8_t CoincellControl::VCoinMask::_2_3 = BITS_2_0;
const uint8_t CoincellControl::VCoinMask::_2_4 = BITS_2_1;
const uint8_t CoincellControl::VCoinMask::_2_5 = BITS_2_1_0;
const uint8_t CoincellControl::VCoinMask::_2_6 = BITS_3;
const uint8_t CoincellControl::VCoinMask::_2_7 = BITS_3_0;
const uint8_t CoincellControl::VCoinMask::_2_8 = BITS_3_1;
const uint8_t CoincellControl::VCoinMask::_2_9 = BITS_3_1_0;
const uint8_t CoincellControl::VCoinMask::_3_0 = BITS_3_2;
const uint8_t CoincellControl::VCoinMask::_3_1 = BITS_3_2_0;
const uint8_t CoincellControl::VCoinMask::_3_2 = BITS_3_2_1;
const uint8_t CoincellControl::VCoinMask::_3_3 = BITS_3_2_1_0;
const CoincellControl::ChEnMask CoincellControl::kChEnMask(BITS_4);
const uint8_t CoincellControl::ChEnMask::DISABLED = BITS_NONE;
const uint8_t CoincellControl::ChEnMask::ENABLED = BITS_4;

const uint8_t VsnvsCtrl::kRegister = 0x48;
const VsnvsCtrl::CLKPulseMask VsnvsCtrl::kCLKPulseMask(BITS_3);
const VsnvsCtrl::ForceBOSMask VsnvsCtrl::kForceBOSMask(BITS_4);
const uint8_t VsnvsCtrl::ForceBOSMask::FORCED = BITS_4;
const uint8_t VsnvsCtrl::ForceBOSMask::ONLY_VSYS_LT_VDIV = BITS_NONE;
const VsnvsCtrl::LiBGDisMask VsnvsCtrl::kLiBGDisMask(BITS_4);
const uint8_t VsnvsCtrl::LiBGDisMask::Vsnvs_BAND_GAP_DISABLED = BITS_NONE;
const uint8_t VsnvsCtrl::LiBGDisMask::Vsnvs_BAND_GAP_ENABLED = BITS_5;

const uint8_t VrefddrCtrl::kRegister = 0x4A;
const VrefddrCtrl::VrefddrEnMask VrefddrCtrl::kVrefddrEnMask(BITS_0);
const uint8_t VrefddrCtrl::VrefddrEnMask::ENABLE = BITS_0;
const uint8_t VrefddrCtrl::VrefddrEnMask::DISABLE = BITS_NONE;
const VrefddrCtrl::VrefddrStbyEnMask VrefddrCtrl::kVrefddrStbyEnMask(BITS_1);
const uint8_t VrefddrCtrl::VrefddrStbyEnMask::ENABLE = BITS_1;
const uint8_t VrefddrCtrl::VrefddrStbyEnMask::DISABLE = BITS_NONE;
const VrefddrCtrl::VrefddrOModeMask VrefddrCtrl::kVrefddrOModeMask(BITS_2);
const uint8_t VrefddrCtrl::VrefddrOModeMask::ENABLE = BITS_2;
const uint8_t VrefddrCtrl::VrefddrOModeMask::DISABLE = BITS_NONE;
const VrefddrCtrl::VrefddrLPwrMask VrefddrCtrl::kVrefddrLPwrMask(BITS_3);
const uint8_t VrefddrCtrl::VrefddrLPwrMask::ENABLE = BITS_3;
const uint8_t VrefddrCtrl::VrefddrLPwrMask::DISABLE = BITS_NONE;

const uint8_t VrefddrPwrDnSeq::kRegister = 0x65;
const VrefddrPwrDnSeq::VrefddrPwrDnSeqMask
    VrefddrPwrDnSeq::kVrefddrPwrDnSeqMask(BITS_2_1_0);

// TODO(kendall): Figure out the right register. This conflicts with RC_16MHz
const uint8_t Key1::kRegister = 0x6B;
const Key1::Key1Mask Key1::kKey1Mask(BITS_2_1_0);
// End Misc.h

// Charger.h
static const uint8_t SPECIFIC_REGISTER_OFFSET = 0x80;

const uint8_t ChgInt::kRegister = 0x00 + SPECIFIC_REGISTER_OFFSET;
const ChgInt::SupIMask ChgInt::kSupIMask(BITS_0);
const uint8_t ChgInt::SupIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::SupIMask::ACTIVE = BITS_0;
const ChgInt::Bat2SocIMask ChgInt::kBat2SocIMask(BITS_1);
const uint8_t ChgInt::Bat2SocIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::Bat2SocIMask::ACTIVE = BITS_1;
const ChgInt::BatIMask ChgInt::kBatIMask(BITS_2);
const uint8_t ChgInt::BatIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::BatIMask::ACTIVE = BITS_2;
const ChgInt::ChgIMask ChgInt::kChgIMask(BITS_3);
const uint8_t ChgInt::ChgIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::ChgIMask::ACTIVE = BITS_3;
const ChgInt::VbusIMask ChgInt::kVbusIMask(BITS_5);
const uint8_t ChgInt::VbusIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::VbusIMask::ACTIVE = BITS_5;
const ChgInt::VbusDpmIMask ChgInt::kVbusDpmIMask(BITS_6);
const uint8_t ChgInt::VbusDpmIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::VbusDpmIMask::ACTIVE = BITS_6;
const ChgInt::ThmIMask ChgInt::kThmIMask(BITS_7);
const uint8_t ChgInt::ThmIMask::CLEARED = BITS_NONE;
const uint8_t ChgInt::ThmIMask::ACTIVE = BITS_7;

const uint8_t ChgIntMask::kRegister = 0x02 + SPECIFIC_REGISTER_OFFSET;
const ChgIntMask::SupMMask ChgIntMask::kSupMMask(BITS_0);
const uint8_t ChgIntMask::SupMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::SupMMask::MASKED = BITS_0;
const ChgIntMask::Bat2SocMMask ChgIntMask::kBat2SocMMask(BITS_1);
const uint8_t ChgIntMask::Bat2SocMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::Bat2SocMMask::MASKED = BITS_1;
const ChgIntMask::BatMMask ChgIntMask::kBatMMask(BITS_2);
const uint8_t ChgIntMask::BatMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::BatMMask::MASKED = BITS_2;
const ChgIntMask::ChgMMask ChgIntMask::kChgMMask(BITS_3);
const uint8_t ChgIntMask::ChgMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::ChgMMask::MASKED = BITS_3;
const ChgIntMask::VbusMMask ChgIntMask::kVbusMMask(BITS_5);
const uint8_t ChgIntMask::VbusMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::VbusMMask::MASKED = BITS_5;
const ChgIntMask::VbusDpmMMask ChgIntMask::kVbusDpmMMask(BITS_6);
const uint8_t ChgIntMask::VbusDpmMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::VbusDpmMMask::MASKED = BITS_6;
const ChgIntMask::ThmMMask ChgIntMask::kThmMMask(BITS_7);
const uint8_t ChgIntMask::ThmMMask::UNMASKED = BITS_NONE;
const uint8_t ChgIntMask::ThmMMask::MASKED = BITS_7;

const uint8_t ChgIntOk::kRegister = 0x04 + SPECIFIC_REGISTER_OFFSET;
const ChgIntOk::SupOkMask ChgIntOk::kSupOkMask(BITS_0);
const uint8_t ChgIntOk::SupOkMask::NOT_DETECTED = BITS_NONE;
const uint8_t ChgIntOk::SupOkMask::DETECTED = BITS_0;
const ChgIntOk::Bat2SocOkMask ChgIntOk::kBat2SocOkMask(BITS_1);
const uint8_t ChgIntOk::Bat2SocOkMask::NOT_OVERCURRENT = BITS_NONE;
const uint8_t ChgIntOk::Bat2SocOkMask::OVERCURRENT = BITS_1;
const ChgIntOk::BatOkMask ChgIntOk::kBatOkMask(BITS_2);
const uint8_t ChgIntOk::BatOkMask::BAT_ISSUE = BITS_NONE;
const uint8_t ChgIntOk::BatOkMask::BAT_OK = BITS_2;
const ChgIntOk::ChgOkMask ChgIntOk::kChgOkMask(BITS_3);
const uint8_t ChgIntOk::ChgOkMask::NOT_CHARGING = BITS_NONE;
const uint8_t ChgIntOk::ChgOkMask::CHG_OK = BITS_3;
const ChgIntOk::VbusOkMask ChgIntOk::kVbusOkMask(BITS_5);
const uint8_t ChgIntOk::VbusOkMask::INVALID = BITS_NONE;
const uint8_t ChgIntOk::VbusOkMask::VALID = BITS_5;
const ChgIntOk::VbusDpmOkMask ChgIntOk::kVbusDpmOkMask(BITS_6);
const uint8_t ChgIntOk::VbusDpmOkMask::NO_DPM = BITS_NONE;
const uint8_t ChgIntOk::VbusDpmOkMask::DPM = BITS_6;
const ChgIntOk::ThmOkMask ChgIntOk::kThmOkMask(BITS_7);
const uint8_t ChgIntOk::ThmOkMask::OUTSIDE_THRESHOLD = BITS_NONE;
const uint8_t ChgIntOk::ThmOkMask::WITHIN_THRESHOLD = BITS_7;

const uint8_t VbusSns::kRegister = 0x06 + SPECIFIC_REGISTER_OFFSET;
const VbusSns::VbusUvloSnsMask VbusSns::kVbusUvloSnsMask(BITS_2);
const uint8_t VbusSns::VbusUvloSnsMask::VBUS_GT_UVLO = BITS_NONE;
const uint8_t VbusSns::VbusUvloSnsMask::VBUS_DETACHED = BITS_2;
const VbusSns::VbusIn2SysSnsMask VbusSns::kVbusIn2SysSnsMask(BITS_3);
const uint8_t VbusSns::VbusIn2SysSnsMask::GT = BITS_NONE;
const uint8_t VbusSns::VbusIn2SysSnsMask::LT = BITS_3;
const VbusSns::VbusOvloSnsMask VbusSns::kVbusOvloSnsMask(BITS_4);
const uint8_t VbusSns::VbusOvloSnsMask::GT = BITS_NONE;
const uint8_t VbusSns::VbusOvloSnsMask::LT = BITS_4;
const VbusSns::VbusValidMask VbusSns::kVbusValidMask(BITS_5);
const uint8_t VbusSns::VbusValidMask::INVALID = BITS_NONE;
const uint8_t VbusSns::VbusValidMask::VALID = BITS_5;
const VbusSns::VbusDpmSnsMask VbusSns::kVbusDpmSnsMask(BITS_7);
const uint8_t VbusSns::VbusDpmSnsMask::NOT_TRIGGERED = BITS_NONE;
const uint8_t VbusSns::VbusDpmSnsMask::TRIGGERED = BITS_7;

const uint8_t ChgSns::kRegister = 0x07 + SPECIFIC_REGISTER_OFFSET;
const ChgSns::ChgSnsMask ChgSns::kChgSnsMask(BITS_3_2_1_0);
const uint8_t ChgSns::ChgSnsMask::PRECHARGE = BITS_NONE;
const uint8_t ChgSns::ChgSnsMask::FAST_CHARGE_CC = BITS_0;
const uint8_t ChgSns::ChgSnsMask::FAST_CHARGE_CV = BITS_1;
const uint8_t ChgSns::ChgSnsMask::END_OF_CHARGE = BITS_1_0;
const uint8_t ChgSns::ChgSnsMask::DONE = BITS_2;
const uint8_t ChgSns::ChgSnsMask::TIMER_FAULT = BITS_2_1;
const uint8_t ChgSns::ChgSnsMask::THERMISTOR_SUSPEND = BITS_2_1_0;
const uint8_t ChgSns::ChgSnsMask::OFF_INVALID_OR_DISABLED = BITS_3;
const uint8_t ChgSns::ChgSnsMask::OVERVOLTAGE = BITS_3_0;
const uint8_t ChgSns::ChgSnsMask::CHG_THERMAL_OFF = BITS_3_1;
const uint8_t ChgSns::ChgSnsMask::LINEAR_ONLY_NO_CHARGE = BITS_3_2;
const ChgSns::WdtSnsMask ChgSns::kWdtSnsMask(BITS_5);
const uint8_t ChgSns::WdtSnsMask::WATCHDOG_NOT_EXPIRED = BITS_NONE;
const uint8_t ChgSns::WdtSnsMask::CHG_OFF_WATCHDOG = BITS_5;
const ChgSns::ThmSnsMask ChgSns::kThmSnsMask(BITS_6);
const uint8_t ChgSns::ThmSnsMask::OUTSIDE_THRESHOLDS = BITS_NONE;
const uint8_t ChgSns::ThmSnsMask::WITHIN_THRESHOLDS = BITS_5;
const ChgSns::TregSnsMask ChgSns::kTregSnsMask(BITS_7);
const uint8_t ChgSns::TregSnsMask::LESS_THAN_THRESHOLD = BITS_NONE;
const uint8_t ChgSns::TregSnsMask::GREATER_THAN_THRESHOLD = BITS_7;

const uint8_t BattSns::kRegister = 0x08 + SPECIFIC_REGISTER_OFFSET;
const BattSns::BattSnsMask BattSns::kBattSnsMask(BITS_2_1_0);
const uint8_t BattSns::BattSnsMask::VBUS_INVALID = BITS_NONE;
const uint8_t BattSns::BattSnsMask::VBATT_LT_PRECHG = BITS_0;
const uint8_t BattSns::BattSnsMask::CHG_SUSPENDED = BITS_1;
const uint8_t BattSns::BattSnsMask::VBATT_GT_PRECHG = BITS_2;
const uint8_t BattSns::BattSnsMask::OVERVOLTAGE = BITS_2_0;
const uint8_t BattSns::BattSnsMask::NOT_DETECTED = BITS_2_1;
const BattSns::BattOCSnsMask BattSns::kBattOCSnsMask(BITS_5);
const uint8_t BattSns::BattOCSnsMask::NOFAULT = BITS_NONE;
const uint8_t BattSns::BattOCSnsMask::FAULT = BITS_5;

const uint8_t ChgOper::kRegister = 0x09 + SPECIFIC_REGISTER_OFFSET;
const ChgOper::ChgOperMask ChgOper::kChgOperMask(BITS_1_0);
const uint8_t ChgOper::ChgOperMask::CHG_OFF_LINEAR_OFF = BITS_NONE;
const uint8_t ChgOper::ChgOperMask::CHG_OFF_LINEAR_ON = BITS_0;
const uint8_t ChgOper::ChgOperMask::CHG_ON_LINEAR_ON = BITS_1;
const ChgOper::WdtEnMask ChgOper::kWdtEnMask(BITS_3);
const uint8_t ChgOper::WdtEnMask::WATCHDOG_DISABLED = BITS_NONE;
const uint8_t ChgOper::WdtEnMask::WATCHDOG_ENABLED = BITS_3;
const ChgOper::DisBattFetMask ChgOper::kDisBattFetMask(BITS_4);
const uint8_t ChgOper::DisBattFetMask::FET_STATEMACHINE = BITS_NONE;
const uint8_t ChgOper::DisBattFetMask::FET_FORCED_OFF = BITS_4;

const uint8_t ChgTmr::kRegister = 0x0A + SPECIFIC_REGISTER_OFFSET;
const ChgTmr::FChgTimeMask ChgTmr::kFChgTimeMask(BITS_2_1_0);
const uint8_t ChgTmr::FChgTimeMask::DISABLE = BITS_NONE;
const uint8_t ChgTmr::FChgTimeMask::_2HR = BITS_0;
const uint8_t ChgTmr::FChgTimeMask::_4HR = BITS_1;
const uint8_t ChgTmr::FChgTimeMask::_6HR = BITS_1_0;
const uint8_t ChgTmr::FChgTimeMask::_8HR = BITS_2;
const uint8_t ChgTmr::FChgTimeMask::_10HR = BITS_2_0;
const uint8_t ChgTmr::FChgTimeMask::_12HR = BITS_2_1;
const uint8_t ChgTmr::FChgTimeMask::_14HR = BITS_2_1_0;
const ChgTmr::EoCTimeMask ChgTmr::kEoCTimeMask(BITS_5_4_3);
const uint8_t ChgTmr::EoCTimeMask::_0M = BITS_NONE;
const uint8_t ChgTmr::EoCTimeMask::_10M = BITS_3;
const uint8_t ChgTmr::EoCTimeMask::_20M = BITS_4;
const uint8_t ChgTmr::EoCTimeMask::_30M = BITS_4_3;
const uint8_t ChgTmr::EoCTimeMask::_40M = BITS_5;
const uint8_t ChgTmr::EoCTimeMask::_50M = BITS_5_3;
const uint8_t ChgTmr::EoCTimeMask::_60M = BITS_5_4;
const uint8_t ChgTmr::EoCTimeMask::_70M = BITS_2_1_0;
const ChgTmr::TPreChgMask ChgTmr::kTPreChgMask(BITS_7);
const uint8_t ChgTmr::TPreChgMask::_30M = BITS_NONE;
const uint8_t ChgTmr::TPreChgMask::_45M = BITS_7;

const uint8_t ChgEocCnfg::kRegister = 0x0D + SPECIFIC_REGISTER_OFFSET;
const ChgEocCnfg::ChgRestartMask ChgEocCnfg::kChgRestartMask(BITS_1_0);
const uint8_t ChgEocCnfg::ChgRestartMask::_100MV = BITS_NONE;
const uint8_t ChgEocCnfg::ChgRestartMask::_150MV = BITS_0;
const uint8_t ChgEocCnfg::ChgRestartMask::_200MV = BITS_1;
const uint8_t ChgEocCnfg::ChgRestartMask::DISABLED = BITS_1_0;
const ChgEocCnfg::IEoCMask ChgEocCnfg::kIEoCMask(BITS_6_5_4);
const uint8_t ChgEocCnfg::IEoCMask::_5MA = BITS_NONE;
const uint8_t ChgEocCnfg::IEoCMask::_10MA = BITS_4;
const uint8_t ChgEocCnfg::IEoCMask::_20MA = BITS_5;
const uint8_t ChgEocCnfg::IEoCMask::_30MA = BITS_5_4;
const uint8_t ChgEocCnfg::IEoCMask::_50MA = BITS_6;

const uint8_t ChgCurrCnfg::kRegister = 0x0E + SPECIFIC_REGISTER_OFFSET;
const ChgCurrCnfg::ChgCcMask ChgCurrCnfg::kChgCcMask(BITS_4_3_2_1_0);
const uint8_t ChgCurrCnfg::ChgCcMask::_100MA = BITS_NONE;
const uint8_t ChgCurrCnfg::ChgCcMask::_150MA = BITS_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_200MA = BITS_1;
const uint8_t ChgCurrCnfg::ChgCcMask::_250MA = BITS_1_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_300MA = BITS_2;
const uint8_t ChgCurrCnfg::ChgCcMask::_350MA = BITS_2_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_400MA = BITS_2_1;
const uint8_t ChgCurrCnfg::ChgCcMask::_450MA = BITS_2_1_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_500MA = BITS_3;
const uint8_t ChgCurrCnfg::ChgCcMask::_550MA = BITS_3_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_600MA = BITS_3_1;
const uint8_t ChgCurrCnfg::ChgCcMask::_650MA = BITS_3_1_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_700MA = BITS_3_2;
const uint8_t ChgCurrCnfg::ChgCcMask::_750MA = BITS_3_2_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_800MA = BITS_3_2_1;
const uint8_t ChgCurrCnfg::ChgCcMask::_850MA = BITS_3_2_1_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_900MA = BITS_4;
const uint8_t ChgCurrCnfg::ChgCcMask::_950MA = BITS_4_0;
const uint8_t ChgCurrCnfg::ChgCcMask::_1000MA = BITS_4_1;
const ChgCurrCnfg::PreChgLbThrsMask ChgCurrCnfg::kPreChgLbThrsMask(BITS_6_5);
const uint8_t ChgCurrCnfg::PreChgLbThrsMask::_2_8V = BITS_NONE;
const uint8_t ChgCurrCnfg::PreChgLbThrsMask::_2_7V = BITS_5;
const uint8_t ChgCurrCnfg::PreChgLbThrsMask::_2_9V = BITS_6;
const uint8_t ChgCurrCnfg::PreChgLbThrsMask::_3_0V = BITS_6_5;

const uint8_t BattReg::kRegister = 0x0F + SPECIFIC_REGISTER_OFFSET;
const BattReg::ChgCvMask BattReg::kChgCvMask(BITS_5_4_3_2_1_0);
const uint8_t BattReg::ChgCvMask::_3_50V = BITS_NONE;
const uint8_t BattReg::ChgCvMask::_3_50V_1 = BITS_0;
const uint8_t BattReg::ChgCvMask::_3_50V_2 = BITS_1;
const uint8_t BattReg::ChgCvMask::_3_50V_3 = BITS_1_0;
const uint8_t BattReg::ChgCvMask::_3_50V_4 = BITS_2;
const uint8_t BattReg::ChgCvMask::_3_50V_5 = BITS_2_0;
const uint8_t BattReg::ChgCvMask::_3_50V_6 = BITS_2_1;
const uint8_t BattReg::ChgCvMask::_3_50V_7 = BITS_2_1_0;
const uint8_t BattReg::ChgCvMask::_3_50V_8 = BITS_3;
const uint8_t BattReg::ChgCvMask::_3_52V = BITS_3_0;
const uint8_t BattReg::ChgCvMask::_3_54V = BITS_3_1;
const uint8_t BattReg::ChgCvMask::_3_56V = BITS_3_1_0;
const uint8_t BattReg::ChgCvMask::_3_58V = BITS_3_2;
const uint8_t BattReg::ChgCvMask::_3_60V = BITS_3_2_0;
const uint8_t BattReg::ChgCvMask::_3_62V = BITS_3_2_1;
const uint8_t BattReg::ChgCvMask::_3_64V = BITS_3_2_1_0;
const uint8_t BattReg::ChgCvMask::_3_66V = BITS_4;
const uint8_t BattReg::ChgCvMask::_3_68V = BITS_4_0;
const uint8_t BattReg::ChgCvMask::_3_70V = BITS_4_1;
const uint8_t BattReg::ChgCvMask::_3_72V = BITS_4_1_0;
const uint8_t BattReg::ChgCvMask::_3_74V = BITS_4_2;
const uint8_t BattReg::ChgCvMask::_3_76V = BITS_4_2_0;
const uint8_t BattReg::ChgCvMask::_3_78V = BITS_4_2_1;
const uint8_t BattReg::ChgCvMask::_3_80V = BITS_4_2_1_0;
const uint8_t BattReg::ChgCvMask::_3_82V = BITS_4_3;
const uint8_t BattReg::ChgCvMask::_3_84V = BITS_4_3_0;
const uint8_t BattReg::ChgCvMask::_3_86V = BITS_4_3_1;
const uint8_t BattReg::ChgCvMask::_3_88V = BITS_4_3_1_0;
const uint8_t BattReg::ChgCvMask::_3_90V = BITS_4_3_2;
const uint8_t BattReg::ChgCvMask::_3_92V = BITS_4_3_2_0;
const uint8_t BattReg::ChgCvMask::_3_94V = BITS_4_3_2_1;
const uint8_t BattReg::ChgCvMask::_3_96V = BITS_4_3_2_1_0;
const uint8_t BattReg::ChgCvMask::_3_98V = BITS_5;
const uint8_t BattReg::ChgCvMask::_4_00V = BITS_5_0;
const uint8_t BattReg::ChgCvMask::_4_02V = BITS_5_1;
const uint8_t BattReg::ChgCvMask::_4_04V = BITS_5_1_0;
const uint8_t BattReg::ChgCvMask::_4_06V = BITS_5_2;
const uint8_t BattReg::ChgCvMask::_4_08V = BITS_5_2_0;
const uint8_t BattReg::ChgCvMask::_4_10V = BITS_5_2_1;
const uint8_t BattReg::ChgCvMask::_4_12V = BITS_5_2_1_0;
const uint8_t BattReg::ChgCvMask::_4_14V = BITS_5_3;
const uint8_t BattReg::ChgCvMask::_4_16V = BITS_5_3_0;
const uint8_t BattReg::ChgCvMask::_4_18V = BITS_5_3_1;
const uint8_t BattReg::ChgCvMask::_4_20V = BITS_5_3_1_0;
const uint8_t BattReg::ChgCvMask::_4_22V = BITS_5_3_2;
const uint8_t BattReg::ChgCvMask::_4_24V = BITS_5_3_2_0;
const uint8_t BattReg::ChgCvMask::_4_26V = BITS_5_3_2_1;
const uint8_t BattReg::ChgCvMask::_4_28V = BITS_5_3_2_1_0;
const uint8_t BattReg::ChgCvMask::_4_30V = BITS_5_4;
const uint8_t BattReg::ChgCvMask::_4_32V = BITS_5_4_0;
const uint8_t BattReg::ChgCvMask::_4_34V = BITS_5_4_1;
const uint8_t BattReg::ChgCvMask::_4_36V = BITS_5_4_1_0;
const uint8_t BattReg::ChgCvMask::_4_38V = BITS_5_4_2;
const uint8_t BattReg::ChgCvMask::_4_40V = BITS_5_4_2_0;
const uint8_t BattReg::ChgCvMask::_4_42V = BITS_5_4_2_1;
const uint8_t BattReg::ChgCvMask::_4_44V = BITS_5_4_2_1_0;
const uint8_t BattReg::ChgCvMask::_4_44V_1 = BITS_5_4_3;
const uint8_t BattReg::ChgCvMask::_4_44V_2 = BITS_5_4_3_0;
const uint8_t BattReg::ChgCvMask::_4_44V_3 = BITS_5_4_3_1;
const uint8_t BattReg::ChgCvMask::_4_44V_4 = BITS_5_4_3_1_0;
const uint8_t BattReg::ChgCvMask::_4_44V_5 = BITS_5_4_3_2;
const uint8_t BattReg::ChgCvMask::_4_44V_6 = BITS_5_4_3_2_0;
const uint8_t BattReg::ChgCvMask::_4_44V_7 = BITS_5_4_3_2_1;
const uint8_t BattReg::ChgCvMask::_4_44V_8 = BITS_5_4_3_2_1_0;
const BattReg::VsysMinMask BattReg::kVsysMinMask(BITS_7_6);
const uint8_t BattReg::VsysMinMask::_3_5V = BITS_NONE;
const uint8_t BattReg::VsysMinMask::_3_7V = BITS_6;
const uint8_t BattReg::VsysMinMask::_4_3V = BITS_7;

const uint8_t BatfetCnfg::kRegister = 0x11 + SPECIFIC_REGISTER_OFFSET;
const BatfetCnfg::WdtClrMask BatfetCnfg::kWdtClrMask(BITS_1_0);
const uint8_t BatfetCnfg::WdtClrMask::NOT_CLEARED = BITS_NONE;
const uint8_t BatfetCnfg::WdtClrMask::CLEARED = BITS_0;
const uint8_t BatfetCnfg::WdtClrMask::NOT_CLEARED_1 = BITS_1;
const uint8_t BatfetCnfg::WdtClrMask::NOT_CLEARED_2 = BITS_1_0;
const BatfetCnfg::BOVRCDisBattFetMask BatfetCnfg::kBOVRCDisBattFetMask(BITS_3);
const uint8_t BatfetCnfg::BOVRCDisBattFetMask::CHARGER_CONTROLLED = BITS_NONE;
const uint8_t BatfetCnfg::BOVRCDisBattFetMask::NOT_TURNED_OFF_BY_OVC = BITS_3;
const BatfetCnfg::BattFetOCMask BatfetCnfg::kBattFetOCMask(BITS_5_4);
const uint8_t BatfetCnfg::BattFetOCMask::DISABLED = BITS_NONE;
const uint8_t BatfetCnfg::BattFetOCMask::_2_2A = BITS_4;
const uint8_t BatfetCnfg::BattFetOCMask::_2_8A = BITS_5;
const uint8_t BatfetCnfg::BattFetOCMask::_3_2A = BITS_5_4;
const BatfetCnfg::WdTimeMask BatfetCnfg::kWdTimeMask(BITS_6);
const uint8_t BatfetCnfg::WdTimeMask::_80s = BITS_NONE;
const uint8_t BatfetCnfg::WdTimeMask::_32s = BITS_6;
const BatfetCnfg::BOVRCNoVBusMask BatfetCnfg::kBOVRCNoVBusMask(BITS_7);
const uint8_t BatfetCnfg::BOVRCNoVBusMask::ENABLED = BITS_7;
const uint8_t BatfetCnfg::BOVRCNoVBusMask::DISABLED = BITS_NONE;

const uint8_t ThmRegCnfg::kRegister = 0x12 + SPECIFIC_REGISTER_OFFSET;
const ThmRegCnfg::ThmCnfgMask ThmRegCnfg::kThmCnfgMask(BITS_1_0);
const uint8_t ThmRegCnfg::ThmCnfgMask::THM_DOES_NOT_CONTROL = BITS_NONE;
const uint8_t ThmRegCnfg::ThmCnfgMask::THM_CONTROLS = BITS_0;
const uint8_t ThmRegCnfg::ThmCnfgMask::JEITA1 = BITS_1;
const uint8_t ThmRegCnfg::ThmCnfgMask::JEITA2 = BITS_1_0;
const ThmRegCnfg::RegTempMask ThmRegCnfg::kRegTempMask(BITS_3_2);
const uint8_t ThmRegCnfg::RegTempMask::_80C = BITS_NONE;
const uint8_t ThmRegCnfg::RegTempMask::_95C = BITS_2;
const uint8_t ThmRegCnfg::RegTempMask::_110C = BITS_3;
const uint8_t ThmRegCnfg::RegTempMask::_125C = BITS_3_2;
const ThmRegCnfg::ThmColdMask ThmRegCnfg::kThmColdMask(BITS_4);
const uint8_t ThmRegCnfg::ThmColdMask::_MINUS_10C = BITS_4;
const uint8_t ThmRegCnfg::ThmColdMask::_0C = BITS_NONE;
const ThmRegCnfg::ThmHotMask ThmRegCnfg::kThmHotMask(BITS_5);
const uint8_t ThmRegCnfg::ThmHotMask::_55C = BITS_5;
const uint8_t ThmRegCnfg::ThmHotMask::_60C = BITS_NONE;
const ThmRegCnfg::TempFbEnMask ThmRegCnfg::kTempFbEnMask(BITS_7);
const uint8_t ThmRegCnfg::TempFbEnMask::DISABLED = BITS_NONE;
const uint8_t ThmRegCnfg::TempFbEnMask::ENABLED = BITS_7;

const uint8_t VbusInLimCnfg::kRegister = 0x14 + SPECIFIC_REGISTER_OFFSET;
const VbusInLimCnfg::VbusLinILimMask
    VbusInLimCnfg::kVbusLinILimMask(BITS_7_6_5_4_3);
const uint8_t VbusInLimCnfg::VbusLinILimMask::_10MA = BITS_NONE;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_15MA = BITS_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_20MA = BITS_4;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_25MA = BITS_4_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_30MA = BITS_5;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_35MA = BITS_5_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_40MA = BITS_5_4;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_45MA = BITS_5_4_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_50MA = BITS_6;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_100MA = BITS_6_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_150MA = BITS_6_4;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_200MA = BITS_6_4_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_300MA = BITS_6_5;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_400MA = BITS_6_5_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_500MA = BITS_6_5_4;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_600MA = BITS_6_5_4_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_700MA = BITS_7;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_800MA = BITS_7_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_900MA = BITS_7_4;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_1000MA = BITS_7_4_3;
const uint8_t VbusInLimCnfg::VbusLinILimMask::_1500MA = BITS_7_5;

const uint8_t VbusLinDpm::kRegister = 0x15 + SPECIFIC_REGISTER_OFFSET;
const VbusLinDpm::VbusDpmRegMask VbusLinDpm::kVbusDpmRegMask(BITS_2_1_0);
const uint8_t VbusLinDpm::VbusDpmRegMask::_3_9V = BITS_NONE;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_0V = BITS_0;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_1V = BITS_1;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_2V = BITS_1_0;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_3V = BITS_2;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_4V = BITS_2_0;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_5V = BITS_2_1;
const uint8_t VbusLinDpm::VbusDpmRegMask::_4_6V = BITS_2_1_0;
const VbusLinDpm::PreChgdBattThrshMask
    VbusLinDpm::kPreChgdBattThrshMask(BITS_4_3);
const VbusLinDpm::VinDpmStopMask VbusLinDpm::kVinDpmStopMask(BITS_5);
const uint8_t VbusLinDpm::VinDpmStopMask::_200MV = BITS_NONE;
const uint8_t VbusLinDpm::VinDpmStopMask::_250MV = BITS_5;
const VbusLinDpm::FetScaleMask VbusLinDpm::kFetScaleMask(BITS_7);

const uint8_t UsbPhyLdoCnfg::kRegister = 0x16 + SPECIFIC_REGISTER_OFFSET;
const UsbPhyLdoCnfg::ActDisPhyMask UsbPhyLdoCnfg::kActDisPhyMask(BITS_0);
const uint8_t UsbPhyLdoCnfg::ActDisPhyMask::NO_DISCHARGE = BITS_NONE;
const uint8_t UsbPhyLdoCnfg::ActDisPhyMask::DISCHARGE = BITS_0;
const UsbPhyLdoCnfg::UsbPhyMask UsbPhyLdoCnfg::kUsbPhyMask(BITS_1);
const uint8_t UsbPhyLdoCnfg::UsbPhyMask::_3_3V = BITS_NONE;
const uint8_t UsbPhyLdoCnfg::UsbPhyMask::_4_9V = BITS_1;
const UsbPhyLdoCnfg::UsbPhyLdoMask UsbPhyLdoCnfg::kUsbPhyLdoMask(BITS_2);
const uint8_t UsbPhyLdoCnfg::UsbPhyLdoMask::DISABLED = BITS_NONE;
const uint8_t UsbPhyLdoCnfg::UsbPhyLdoMask::ENABLED = BITS_2;

const uint8_t DbncDelayTime::kRegister = 0x18 + SPECIFIC_REGISTER_OFFSET;
const DbncDelayTime::VbusOvTdbMask DbncDelayTime::kVbusOvTdbMask(BITS_1_0);
const uint8_t DbncDelayTime::VbusOvTdbMask::_10US = BITS_NONE;
const uint8_t DbncDelayTime::VbusOvTdbMask::_100US = BITS_0;
const uint8_t DbncDelayTime::VbusOvTdbMask::_1MS = BITS_1;
const uint8_t DbncDelayTime::VbusOvTdbMask::_10MS = BITS_1_0;
const DbncDelayTime::UsbPhyTdbMask DbncDelayTime::kUsbPhyTdbMask(BITS_3_2);
const uint8_t DbncDelayTime::UsbPhyTdbMask::_0MS = BITS_NONE;
const uint8_t DbncDelayTime::UsbPhyTdbMask::_16MS = BITS_2;
const uint8_t DbncDelayTime::UsbPhyTdbMask::_32MS = BITS_3;
const DbncDelayTime::SysWkUpDlyMask DbncDelayTime::kSysWkUpDlyMask(BITS_5_4);
const uint8_t DbncDelayTime::SysWkUpDlyMask::_8MS = BITS_NONE;
const uint8_t DbncDelayTime::SysWkUpDlyMask::_16MS = BITS_4;
const uint8_t DbncDelayTime::SysWkUpDlyMask::_32MS = BITS_5;
const uint8_t DbncDelayTime::SysWkUpDlyMask::_100MS = BITS_5_4;

const uint8_t ChgIntCnfg::kRegister = 0x19 + SPECIFIC_REGISTER_OFFSET;
const ChgIntCnfg::ChgIntGenMask ChgIntCnfg::kChgIntGenMask(BITS_0);
const uint8_t ChgIntCnfg::ChgIntGenMask::INT_ONLY_FC_TO_CV = BITS_NONE;
const uint8_t ChgIntCnfg::ChgIntGenMask::INT_ON_TRANSITION = BITS_0;
const ChgIntCnfg::EoCIntMask ChgIntCnfg::kEoCIntMask(BITS_1);
const uint8_t ChgIntCnfg::EoCIntMask::NO_EOC_INT = BITS_NONE;
const uint8_t ChgIntCnfg::EoCIntMask::EOC_INT = BITS_1;

const uint8_t ThmAdjSetting::kRegister = 0x1A + SPECIFIC_REGISTER_OFFSET;
const ThmAdjSetting::ThmWarmMask ThmAdjSetting::kThmWarmMask(BITS_0);
const uint8_t ThmAdjSetting::ThmWarmMask::_45C = BITS_NONE;
const uint8_t ThmAdjSetting::ThmWarmMask::_50C = BITS_0;
const ThmAdjSetting::ThmCoolMask ThmAdjSetting::kThmCoolMask(BITS_1);
const uint8_t ThmAdjSetting::ThmCoolMask::_15C = BITS_NONE;
const uint8_t ThmAdjSetting::ThmCoolMask::_10C = BITS_1;
const ThmAdjSetting::CvAdjMask ThmAdjSetting::kCvAdjMask(BITS_3_2);
const uint8_t ThmAdjSetting::CvAdjMask::_60MV = BITS_NONE;
const uint8_t ThmAdjSetting::CvAdjMask::_100MV = BITS_2;
const uint8_t ThmAdjSetting::CvAdjMask::_160MV = BITS_3;
const uint8_t ThmAdjSetting::CvAdjMask::_200MV = BITS_3_2;
const ThmAdjSetting::CcAdjMask ThmAdjSetting::kCcAdjMask(BITS_5_4);
const uint8_t ThmAdjSetting::CcAdjMask::_25PCT = BITS_NONE;
const uint8_t ThmAdjSetting::CcAdjMask::_50PCT = BITS_4;
const uint8_t ThmAdjSetting::CcAdjMask::_75PCT = BITS_5;
const uint8_t ThmAdjSetting::CcAdjMask::_100PCT = BITS_5_4;

const uint8_t Vbus2SysCnfg::kRegister = 0x1B + SPECIFIC_REGISTER_OFFSET;
const Vbus2SysCnfg::Vbus2SysTdbMask Vbus2SysCnfg::kVbus2SysTdbMask(BITS_1_0);
const uint8_t Vbus2SysCnfg::Vbus2SysTdbMask::_100US = BITS_0;
const uint8_t Vbus2SysCnfg::Vbus2SysTdbMask::_1MS = BITS_1;
const uint8_t Vbus2SysCnfg::Vbus2SysTdbMask::_10MS = BITS_1_0;
const Vbus2SysCnfg::Vbus2SysThrshMask Vbus2SysCnfg::kVbus2SysThrshMask(BITS_2);
const uint8_t Vbus2SysCnfg::Vbus2SysThrshMask::_50MV = BITS_NONE;
const uint8_t Vbus2SysCnfg::Vbus2SysThrshMask::_175MV = BITS_2;

const uint8_t LedPwm::kRegister = 0x1C + SPECIFIC_REGISTER_OFFSET;
const LedPwm::LedPwmMask LedPwm::kLedPwmMask(BITS_5_4_3_2_1_0);
const uint8_t LedPwm::LedPwmMask::_0_32 = BITS_NONE;
const uint8_t LedPwm::LedPwmMask::_1_32 = BITS_0;
const uint8_t LedPwm::LedPwmMask::_2_32 = BITS_1;
const uint8_t LedPwm::LedPwmMask::_3_32 = BITS_1_0;
const uint8_t LedPwm::LedPwmMask::_4_32 = BITS_2;
const uint8_t LedPwm::LedPwmMask::_5_32 = BITS_2_0;
const uint8_t LedPwm::LedPwmMask::_6_32 = BITS_2_1;
const uint8_t LedPwm::LedPwmMask::_7_32 = BITS_2_1_0;
const uint8_t LedPwm::LedPwmMask::_8_32 = BITS_3;
const uint8_t LedPwm::LedPwmMask::_9_32 = BITS_3_0;
const uint8_t LedPwm::LedPwmMask::_10_32 = BITS_3_1;
const uint8_t LedPwm::LedPwmMask::_11_32 = BITS_3_1_0;
const uint8_t LedPwm::LedPwmMask::_12_32 = BITS_3_2;
const uint8_t LedPwm::LedPwmMask::_13_32 = BITS_3_2_0;
const uint8_t LedPwm::LedPwmMask::_14_32 = BITS_3_2_1;
const uint8_t LedPwm::LedPwmMask::_15_32 = BITS_3_2_1_0;
const uint8_t LedPwm::LedPwmMask::_16_32 = BITS_4;
const uint8_t LedPwm::LedPwmMask::_17_32 = BITS_4_0;
const uint8_t LedPwm::LedPwmMask::_18_32 = BITS_4_1;
const uint8_t LedPwm::LedPwmMask::_19_32 = BITS_4_1_0;
const uint8_t LedPwm::LedPwmMask::_20_32 = BITS_4_2;
const uint8_t LedPwm::LedPwmMask::_21_32 = BITS_4_2_0;
const uint8_t LedPwm::LedPwmMask::_22_32 = BITS_4_2_1;
const uint8_t LedPwm::LedPwmMask::_23_32 = BITS_4_2_1_0;
const uint8_t LedPwm::LedPwmMask::_24_32 = BITS_4_3;
const uint8_t LedPwm::LedPwmMask::_25_32 = BITS_4_3_0;
const uint8_t LedPwm::LedPwmMask::_26_32 = BITS_4_3_1;
const uint8_t LedPwm::LedPwmMask::_27_32 = BITS_4_3_1_0;
const uint8_t LedPwm::LedPwmMask::_28_32 = BITS_4_3_2;
const uint8_t LedPwm::LedPwmMask::_29_32 = BITS_4_3_2_0;
const uint8_t LedPwm::LedPwmMask::_30_32 = BITS_4_3_2_1;
const uint8_t LedPwm::LedPwmMask::_31_32 = BITS_4_3_2_1_0;
const LedPwm::LedRampMask LedPwm::kLedRampMask(BITS_6);
const uint8_t LedPwm::LedRampMask::DISABLE = BITS_NONE;
const uint8_t LedPwm::LedRampMask::ENABLE = BITS_6;
const LedPwm::LedEnMask LedPwm::kLedEnMask(BITS_7);
const uint8_t LedPwm::LedEnMask::DISABLE = BITS_NONE;
const uint8_t LedPwm::LedEnMask::ENABLE = BITS_7;

const uint8_t FaultBatfetCnfg::kRegister = 0x1D + SPECIFIC_REGISTER_OFFSET;
const FaultBatfetCnfg::WdFltBfFetEnMask
    FaultBatfetCnfg::kWdFltBfFetEnMask(BITS_0);
const uint8_t FaultBatfetCnfg::WdFltBfFetEnMask::OPENED = BITS_NONE;
const uint8_t FaultBatfetCnfg::WdFltBfFetEnMask::CLOSED = BITS_0;
const FaultBatfetCnfg::ThmSusBFetEnMask
    FaultBatfetCnfg::kThmSusBFetEnMask(BITS_1);
const uint8_t FaultBatfetCnfg::ThmSusBFetEnMask::CLOSED = BITS_1;
const uint8_t FaultBatfetCnfg::ThmSusBFetEnMask::OPENED = BITS_NONE;
const FaultBatfetCnfg::TShdnBFetEnMask
    FaultBatfetCnfg::kTShdnBFetEnMask(BITS_2);
const uint8_t FaultBatfetCnfg::TShdnBFetEnMask::CLOSED = BITS_2;
const uint8_t FaultBatfetCnfg::TShdnBFetEnMask::OPENED = BITS_NONE;
const FaultBatfetCnfg::TmrFltBFetEnMask
    FaultBatfetCnfg::kTmrFltBFetEnMask(BITS_3);
const uint8_t FaultBatfetCnfg::TmrFltBFetEnMask::OPENED = BITS_NONE;
const uint8_t FaultBatfetCnfg::TmrFltBFetEnMask::CLOSED = BITS_3;

const uint8_t LedCnfg::kRegister = 0x1E + SPECIFIC_REGISTER_OFFSET;
const LedCnfg::LedFreqMask LedCnfg::kLedFreqMask(BITS_1_0);
const uint8_t LedCnfg::LedFreqMask::_1HZ = BITS_NONE;
const uint8_t LedCnfg::LedFreqMask::_0_5HZ = BITS_0;
const uint8_t LedCnfg::LedFreqMask::_256HZ = BITS_1;
const uint8_t LedCnfg::LedFreqMask::_8HZ = BITS_1_0;
const LedCnfg::LedCurrentMask LedCnfg::kLedCurrentMask(BITS_3_2);
const uint8_t LedCnfg::LedCurrentMask::_6MA = BITS_2;
const LedCnfg::LedCfgMask LedCnfg::kLedCfgMask(BITS_4);
const uint8_t LedCnfg::LedCfgMask::CHG_FLASH_FAULT_ON = BITS_4;
const uint8_t LedCnfg::LedCfgMask::CHG_ON_FAULT_FLASH = BITS_NONE;
const LedCnfg::LedOvrdMask LedCnfg::kLedOvrdMask(BITS_5);
const uint8_t LedCnfg::LedOvrdMask::STATEMACHINE_CONTROLLED = BITS_NONE;
const uint8_t LedCnfg::LedOvrdMask::SOFTWARE_CONTROLLED = BITS_5;
// End charger.h

// Pwrctrl.h
const uint8_t Pwrctrl0::kRegister = 0x58;
const Pwrctrl0::StandbyDlyMask Pwrctrl0::kStandbyDlyMask(BITS_1_0);
// TODO(kendall): WTF? these don't make sense
const uint8_t Pwrctrl0::StandbyDlyMask::_1_32KHZ_DELAY = BITS_0;
const uint8_t Pwrctrl0::StandbyDlyMask::_2_32KHZ_DELAY = BITS_1;
const uint8_t Pwrctrl0::StandbyDlyMask::_3_32KHZ_DELAY = BITS_1_0;
const Pwrctrl0::StandbyInvMask Pwrctrl0::kStandbyInvMask(BITS_2);
const uint8_t Pwrctrl0::StandbyInvMask::ACTIVE_HIGH = BITS_NONE;
const uint8_t Pwrctrl0::StandbyInvMask::ACTIVE_LOW = BITS_2;
const Pwrctrl0::PoRDlyMask Pwrctrl0::kPoRDlyMask(BITS_5_4_3);
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_2MS = BITS_NONE;
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_4MS = BITS_3;
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_8MS = BITS_4_3;
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_16MS = BITS_5;
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_128MS = BITS_5_3;
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_256MS = BITS_5_4;
const uint8_t Pwrctrl0::PoRDlyMask::RESETBMCU_DELAY_1024MS = BITS_5_4_3;
const Pwrctrl0::TgResetMask Pwrctrl0::kTgResetMask(BITS_7_6);
const uint8_t Pwrctrl0::TgResetMask::_4S = BITS_NONE;
const uint8_t Pwrctrl0::TgResetMask::_8S = BITS_6;
const uint8_t Pwrctrl0::TgResetMask::_12S = BITS_7;
const uint8_t Pwrctrl0::TgResetMask::_16S = BITS_7_6;

const uint8_t Pwrctrl1::kRegister = 0x59;
const Pwrctrl1::PwronDbncMask Pwrctrl1::kPwronDbncMask(BITS_1_0);
const uint8_t Pwrctrl1::PwronDbncMask::_31_25MS_FALL_31_25MS_RISE_1 = BITS_NONE;
const uint8_t Pwrctrl1::PwronDbncMask::_31_25MS_FALL_31_25MS_RISE_2 = BITS_0;
const uint8_t Pwrctrl1::PwronDbncMask::_125MS_FALL_31_25MS_RISE = BITS_1;
const uint8_t Pwrctrl1::PwronDbncMask::_750MS_FALL_31_25MS_RISE = BITS_1_0;
const Pwrctrl1::OnkeyBbncMask Pwrctrl1::kOnkeyBbncMask(BITS_3_2);
const uint8_t Pwrctrl1::OnkeyBbncMask::_31_25MS_FALL_31_25MS_RISE_1 = BITS_NONE;
const uint8_t Pwrctrl1::OnkeyBbncMask::_31_25MS_FALL_31_25MS_RISE_2 = BITS_2;
const uint8_t Pwrctrl1::OnkeyBbncMask::_125MS_FALL_31_25MS_RISE = BITS_3;
const uint8_t Pwrctrl1::OnkeyBbncMask::_750MS_FALL_31_25MS_RISE = BITS_3_2;
const Pwrctrl1::PwronRstEnMask Pwrctrl1::kPwronRstEnMask(BITS_4);
const uint8_t Pwrctrl1::PwronRstEnMask::LONG_PRESS_SLEEP_OR_REGS_DISABLE =
    BITS_4;
const uint8_t Pwrctrl1::PwronRstEnMask::LONG_PRESS_NO_SLEEP_OR_REGS_DISABLE =
    BITS_NONE;
const Pwrctrl1::RestartEnMask Pwrctrl1::kRestartEnMask(BITS_5);
const uint8_t Pwrctrl1::RestartEnMask::RESTART_AFTER_5S = BITS_5;
const uint8_t Pwrctrl1::RestartEnMask::NO_EFFECT = BITS_NONE;
const Pwrctrl1::RegScpEnMask Pwrctrl1::kRegScpEnMask(BITS_6);
const uint8_t Pwrctrl1::RegScpEnMask::SHUTDOWN_LDO_ON_CURRENT_LIMIT_FAULT =
    BITS_6;
const uint8_t Pwrctrl1::RegScpEnMask::NO_SHUTDOWN_LDO_ON_CURRENT_LIMIT_FAULT =
    BITS_NONE;
const Pwrctrl1::OnkeyRstEnmask Pwrctrl1::kOnkeyRstEnmask(BITS_7);
const uint8_t Pwrctrl1::OnkeyRstEnmask::ONKEY_RESET = BITS_7;
const uint8_t Pwrctrl1::OnkeyRstEnmask::NO_ONKEY_RESET = BITS_NONE;

const uint8_t Pwrctrl2::kRegister = 0x5A;
const Pwrctrl2::UvdetMask Pwrctrl2::kUvdetMask(BITS_1_0);
const uint8_t Pwrctrl2::UvdetMask::_2_65_RISE_2_55_FALL = BITS_NONE;
const uint8_t Pwrctrl2::UvdetMask::_2_8_RISE_2_7_FALL = BITS_0;
const uint8_t Pwrctrl2::UvdetMask::_3_0_RISE_2_9_FALL = BITS_1;
const uint8_t Pwrctrl2::UvdetMask::_3_1_RISE_3_0_FALL = BITS_1_0;
const Pwrctrl2::LowSysWarnMask Pwrctrl2::kLowSysWarnMask(BITS_3_2);
const uint8_t Pwrctrl2::LowSysWarnMask::_3_3_RISE_3_1_FALL = BITS_NONE;
const uint8_t Pwrctrl2::LowSysWarnMask::_3_5_RISE_3_3_FALL = BITS_2;
const uint8_t Pwrctrl2::LowSysWarnMask::_3_7_RISE_3_5_FALL = BITS_3;
const uint8_t Pwrctrl2::LowSysWarnMask::_3_9_RISE_3_7_FALL = BITS_3_2;

const uint8_t Pwrctrl3::kRegister = 0x5B;
const Pwrctrl3::GotoShipMask Pwrctrl3::kGotoShipMask(BITS_0);
const uint8_t Pwrctrl3::GotoShipMask::GOTO_SHIP_EN = BITS_0;
const Pwrctrl3::CoreOffMask Pwrctrl3::kCoreOffMask(BITS_1);
const uint8_t Pwrctrl3::CoreOffMask::CORE_OFF_EN = BITS_1;
// End of pwrctrl.h
// LDOy.h
const uint8_t LdoIntStat0::kRegister = 0x18;
const LdoIntStat0::Ldo1FaultIMask LdoIntStat0::kLdo1FaultIMask(BITS_0);
const uint8_t LdoIntStat0::Ldo1FaultIMask::CLEARED = BITS_NONE;
const uint8_t LdoIntStat0::Ldo1FaultIMask::ACTIVE = BITS_0;
const LdoIntStat0::Ldo2FaultIMask LdoIntStat0::kLdo2FaultIMask(BITS_1);
const uint8_t LdoIntStat0::Ldo2FaultIMask::CLEARED = BITS_NONE;
const uint8_t LdoIntStat0::Ldo2FaultIMask::ACTIVE = BITS_1;
const LdoIntStat0::Ldo3FaultIMask LdoIntStat0::kLdo3FaultIMask(BITS_2);
const uint8_t LdoIntStat0::Ldo3FaultIMask::CLEARED = BITS_NONE;
const uint8_t LdoIntStat0::Ldo3FaultIMask::ACTIVE = BITS_2;

const uint8_t LdoIntMask0::kRegister = 0x19;
const LdoIntMask0::Ldo1FaultMMask LdoIntMask0::kLdo1FaultMMask(BITS_0);
const uint8_t LdoIntMask0::Ldo1FaultMMask::REMOVED = BITS_NONE;
const uint8_t LdoIntMask0::Ldo1FaultMMask::ENABLED = BITS_0;
const LdoIntMask0::Ldo2FaultMMask LdoIntMask0::kLdo2FaultMMask(BITS_1);
const uint8_t LdoIntMask0::Ldo2FaultMMask::REMOVED = BITS_NONE;
const uint8_t LdoIntMask0::Ldo2FaultMMask::ENABLED = BITS_1;
const LdoIntMask0::Ldo3FaultMMask LdoIntMask0::kLdo3FaultMMask(BITS_2);
const uint8_t LdoIntMask0::Ldo3FaultMMask::REMOVED = BITS_NONE;
const uint8_t LdoIntMask0::Ldo3FaultMMask::ENABLED = BITS_2;

const uint8_t LdoIntSense0::kRegister = 0x1A;
const LdoIntSense0::Ldo1FaultSMask LdoIntSense0::kLdo1FaultSMask(BITS_0);
const uint8_t LdoIntSense0::Ldo1FaultSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t LdoIntSense0::Ldo1FaultSMask::FAULT_EXISTS = BITS_0;
const LdoIntSense0::Ldo2FaultSMask LdoIntSense0::kLdo2FaultSMask(BITS_1);
const uint8_t LdoIntSense0::Ldo2FaultSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t LdoIntSense0::Ldo2FaultSMask::FAULT_EXISTS = BITS_1;
const LdoIntSense0::Ldo3FaultSMask LdoIntSense0::kLdo3FaultSMask(BITS_2);
const uint8_t LdoIntSense0::Ldo3FaultSMask::FAULT_REMOVED = BITS_NONE;

const LDOy::Volt::VoltMask LDOy::Volt::kVoltMask(BITS_3_2_1_0);
const uint8_t LDOy::Volt::VoltMask::_0_75 = BITS_NONE;
const uint8_t LDOy::Volt::VoltMask::_0_80 = BITS_0;
const uint8_t LDOy::Volt::VoltMask::_0_85 = BITS_1;
const uint8_t LDOy::Volt::VoltMask::_0_90 = BITS_1_0;
const uint8_t LDOy::Volt::VoltMask::_0_95 = BITS_2;
const uint8_t LDOy::Volt::VoltMask::_1_00 = BITS_2_0;
const uint8_t LDOy::Volt::VoltMask::_1_05 = BITS_2_1;
const uint8_t LDOy::Volt::VoltMask::_1_10 = BITS_2_1_0;
const uint8_t LDOy::Volt::VoltMask::_1_15 = BITS_3;
const uint8_t LDOy::Volt::VoltMask::_1_20 = BITS_3_0;
const uint8_t LDOy::Volt::VoltMask::_1_25 = BITS_3_1;
const uint8_t LDOy::Volt::VoltMask::_1_30 = BITS_3_1_0;
const uint8_t LDOy::Volt::VoltMask::_1_35 = BITS_3_2;
const uint8_t LDOy::Volt::VoltMask::_1_40 = BITS_3_2_0;
const uint8_t LDOy::Volt::VoltMask::_1_45 = BITS_3_2_1;
const uint8_t LDOy::Volt::VoltMask::_1_50 = BITS_3_2_1_0;
const uint8_t LDOy::Volt::VoltMask::_1_80 = BITS_4;
const uint8_t LDOy::Volt::VoltMask::_1_90 = BITS_4_0;
const uint8_t LDOy::Volt::VoltMask::_2_00 = BITS_4_1;
const uint8_t LDOy::Volt::VoltMask::_2_10 = BITS_4_1_0;
const uint8_t LDOy::Volt::VoltMask::_2_20 = BITS_4_2;
const uint8_t LDOy::Volt::VoltMask::_2_30 = BITS_4_2_0;
const uint8_t LDOy::Volt::VoltMask::_2_40 = BITS_4_2_1;
const uint8_t LDOy::Volt::VoltMask::_2_50 = BITS_4_2_1_0;
const uint8_t LDOy::Volt::VoltMask::_2_60 = BITS_4_3;
const uint8_t LDOy::Volt::VoltMask::_2_70 = BITS_4_3_0;
const uint8_t LDOy::Volt::VoltMask::_2_80 = BITS_4_3_1;
const uint8_t LDOy::Volt::VoltMask::_2_90 = BITS_4_3_1_0;
const uint8_t LDOy::Volt::VoltMask::_3_00 = BITS_4_3_2;
const uint8_t LDOy::Volt::VoltMask::_3_10 = BITS_4_3_2_0;
const uint8_t LDOy::Volt::VoltMask::_3_20 = BITS_4_3_2_1;
const uint8_t LDOy::Volt::VoltMask::_3_30 = BITS_4_3_2_1_0;

const LDOy::Ctrl::EnableMask LDOy::Ctrl::kEnableMask(BITS_0);
const uint8_t LDOy::Ctrl::EnableMask::ENABLED = BITS_0;
const LDOy::Ctrl::StbyMask LDOy::Ctrl::kStbyMask(BITS_1);
const uint8_t LDOy::Ctrl::StbyMask::ENABLED = BITS_1;
const LDOy::Ctrl::OmodeMask LDOy::Ctrl::kOmodeMask(BITS_2);
const uint8_t LDOy::Ctrl::OmodeMask::ENABLED = BITS_2;
const LDOy::Ctrl::LPwrMask LDOy::Ctrl::kLPwrMask(BITS_3);
const uint8_t LDOy::Ctrl::LPwrMask::IN_SLP_AND_STBY = BITS_3;
const uint8_t LDOy::Ctrl::LPwrMask::NOT_IN_SLP_AND_STBY = BITS_NONE;
const LDOy::Ctrl::LsMask LDOy::Ctrl::kLsMask(BITS_4);
const uint8_t LDOy::Ctrl::LsMask::SWITCH_MODE = BITS_4;
const uint8_t LDOy::Ctrl::LsMask::LDO_MODE = BITS_NONE;
const LDOy::PwrDnSeq::PwrDnSeqMask LDOy::PwrDnSeq::kPwrDnSeqMask(BITS_2_1_0);

const uint8_t Ldo1::Volt::kRegister = 0x4C;
const uint8_t Ldo1::Ctrl::kRegister = 0x4D;
const uint8_t Ldo1::PwrDnSeq::kRegister = 0x62;

const uint8_t Ldo2::Volt::kRegister = 0x4F;
const uint8_t Ldo2::Ctrl::kRegister = 0x50;
const uint8_t Ldo2::PwrDnSeq::kRegister = 0x63;

const uint8_t Ldo3::Volt::kRegister = 0x52;
const uint8_t Ldo3::Ctrl::kRegister = 0x53;
const uint8_t Ldo3::PwrDnSeq::kRegister = 0x64;

// end of LDOy.h

// swx.h
const uint8_t SwIntStat0::kRegister = 0x08;
const SwIntStat0::Sw1LsIMask SwIntStat0::kSw1LsIMask(BITS_0);
const uint8_t SwIntStat0::Sw1LsIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat0::Sw1LsIMask::INT = BITS_0;
const SwIntStat0::Sw2LsIMask SwIntStat0::kSw2LsIMask(BITS_1);
const uint8_t SwIntStat0::Sw2LsIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat0::Sw2LsIMask::INT = BITS_1;
const SwIntStat0::Sw3LsIMask SwIntStat0::kSw3LsIMask(BITS_2);
const uint8_t SwIntStat0::Sw3LsIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat0::Sw3LsIMask::INT = BITS_2;

const uint8_t SwIntMask0::kRegister = 0x09;
const SwIntMask0::Sw1LsMMask SwIntMask0::kSw1LsMMask(BITS_0);
const uint8_t SwIntMask0::Sw1LsMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask0::Sw1LsMMask::ENABLED = BITS_0;
const SwIntMask0::Sw2LsMMask SwIntMask0::kSw2LsMMask(BITS_1);
const uint8_t SwIntMask0::Sw2LsMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask0::Sw2LsMMask::ENABLED = BITS_1;
const SwIntMask0::Sw3LsMMask SwIntMask0::kSw3LsMMask(BITS_2);
const uint8_t SwIntMask0::Sw3LsMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask0::Sw3LsMMask::ENABLED = BITS_2;

const uint8_t SwIntSense0::kRegister = 0x0A;
const SwIntSense0::Sw1LsSMask SwIntSense0::kSw1LsSMask(BITS_0);
const uint8_t SwIntSense0::Sw1LsSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t SwIntSense0::Sw1LsSMask::FAULT_EXISTS = BITS_0;
const SwIntSense0::Sw2LsSMask SwIntSense0::kSw2LsSMask(BITS_1);
const uint8_t SwIntSense0::Sw2LsSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t SwIntSense0::Sw2LsSMask::FAULT_EXISTS = BITS_1;
const SwIntSense0::Sw3LsSMask SwIntSense0::kSw3LsSMask(BITS_2);
const uint8_t SwIntSense0::Sw3LsSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t SwIntSense0::Sw3LsSMask::FAULT_EXISTS = BITS_2;

const uint8_t SwIntStat1::kRegister = 0x0B;
const SwIntStat1::Sw1HsIMask SwIntStat1::kSw1HsIMask(BITS_0);
const uint8_t SwIntStat1::Sw1HsIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat1::Sw1HsIMask::INT = BITS_0;
const SwIntStat1::Sw2HsIMask SwIntStat1::kSw2HsIMask(BITS_1);
const uint8_t SwIntStat1::Sw2HsIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat1::Sw2HsIMask::INT = BITS_1;
const SwIntStat1::Sw3HsIMask SwIntStat1::kSw3HsIMask(BITS_2);
const uint8_t SwIntStat1::Sw3HsIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat1::Sw3HsIMask::INT = BITS_2;

const uint8_t SwIntMask1::kRegister = 0x0C;
const SwIntMask1::Sw1HsMMask SwIntMask1::kSw1HsMMask(BITS_0);
const uint8_t SwIntMask1::Sw1HsMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask1::Sw1HsMMask::ENABLED = BITS_0;
const SwIntMask1::Sw2HsMMask SwIntMask1::kSw2HsMMask(BITS_1);
const uint8_t SwIntMask1::Sw2HsMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask1::Sw2HsMMask::ENABLED = BITS_1;
const SwIntMask1::Sw3HsMMask SwIntMask1::kSw3HsMMask(BITS_2);
const uint8_t SwIntMask1::Sw3HsMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask1::Sw3HsMMask::ENABLED = BITS_2;

const uint8_t SwIntSense1::kRegister = 0x0D;
const SwIntSense1::Sw1HsSMask SwIntSense1::kSw1HsSMask(BITS_0);
const uint8_t SwIntSense1::Sw1HsSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t SwIntSense1::Sw1HsSMask::FAULT_EXISTS = BITS_0;
const SwIntSense1::Sw2HsSMask SwIntSense1::kSw2HsSMask(BITS_1);
const uint8_t SwIntSense1::Sw2HsSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t SwIntSense1::Sw2HsSMask::FAULT_EXISTS = BITS_1;
const SwIntSense1::Sw3HsSMask SwIntSense1::kSw3HsSMask(BITS_2);
const uint8_t SwIntSense1::Sw3HsSMask::FAULT_REMOVED = BITS_NONE;
const uint8_t SwIntSense1::Sw3HsSMask::FAULT_EXISTS = BITS_2;

const uint8_t SwIntStat2::kRegister = 0x0E;
const SwIntStat2::Sw1DvsDoneIMask SwIntStat2::kSw1DvsDoneIMask(BITS_0);
const uint8_t SwIntStat2::Sw1DvsDoneIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat2::Sw1DvsDoneIMask::INT = BITS_0;
const SwIntStat2::Sw2DvsDoneIMask SwIntStat2::kSw2DvsDoneIMask(BITS_1);
const uint8_t SwIntStat2::Sw2DvsDoneIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat2::Sw2DvsDoneIMask::INT = BITS_1;
const SwIntStat2::Sw3DvsDoneIMask SwIntStat2::kSw3DvsDoneIMask(BITS_2);
const uint8_t SwIntStat2::Sw3DvsDoneIMask::CLEAR = BITS_NONE;
const uint8_t SwIntStat2::Sw3DvsDoneIMask::INT = BITS_2;

const uint8_t SwIntMask2::kRegister = 0x0F;
const SwIntMask2::Sw1DvsDoneMMask SwIntMask2::kSw1DvsDoneMMask(BITS_0);
const uint8_t SwIntMask2::Sw1DvsDoneMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask2::Sw1DvsDoneMMask::ENABLED = BITS_0;
const SwIntMask2::Sw2DvsDoneMMask SwIntMask2::kSw2DvsDoneMMask(BITS_1);
const uint8_t SwIntMask2::Sw2DvsDoneMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask2::Sw2DvsDoneMMask::ENABLED = BITS_1;
const SwIntMask2::Sw3DvsDoneMMask SwIntMask2::kSw3DvsDoneMMask(BITS_2);
const uint8_t SwIntMask2::Sw3DvsDoneMMask::REMOVED = BITS_NONE;
const uint8_t SwIntMask2::Sw3DvsDoneMMask::ENABLED = BITS_2;

const uint8_t SwIntSense2::kRegister = 0x10;
const SwIntSense2::Sw1DvsDoneSMask SwIntSense2::kSw1DvsDoneSMask(BITS_0);
const uint8_t SwIntSense2::Sw1DvsDoneSMask::NOT_IN_PROGRESS = BITS_NONE;
const uint8_t SwIntSense2::Sw1DvsDoneSMask::IN_PROGRESS = BITS_0;
const SwIntSense2::Sw2DvsDoneSMask SwIntSense2::kSw2DvsDoneSMask(BITS_1);
const uint8_t SwIntSense2::Sw2DvsDoneSMask::NOT_IN_PROGRESS = BITS_NONE;
const uint8_t SwIntSense2::Sw2DvsDoneSMask::IN_PROGRESS = BITS_1;
const SwIntSense2::Sw3DvsDoneSMask SwIntSense2::kSw3DvsDoneSMask(BITS_2);
const uint8_t SwIntSense2::Sw3DvsDoneSMask::NOT_IN_PROGRESS = BITS_NONE;
const uint8_t SwIntSense2::Sw3DvsDoneSMask::IN_PROGRESS = BITS_2;

const struct SWx::Volt::VoltMask SWx::Volt::kVoltMask(BITS_5_4_3_2_1_0);
const SWx::SlpVolt::SlpVoltMask SWx::SlpVolt::kSlpVoltMask(BITS_5_4_3_2_1_0);
const SWx::StbyVolt::StbyVoltMask
    SWx::StbyVolt::kStbyVoltMask(BITS_5_4_3_2_1_0);

const uint8_t SWx::OtpSWxDvsSelDisVolt::_1_10 = BITS_NONE;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_1_20 = BITS_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_1_35 = BITS_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_1_50 = BITS_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_1_80 = BITS_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_2_50 = BITS_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_0 = BITS_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_1 = BITS_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_2 = BITS_3;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_3 = BITS_3_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_4 = BITS_3_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_5 = BITS_3_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_6 = BITS_3_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_7 = BITS_3_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_8 = BITS_3_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_9 = BITS_3_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_10 = BITS_4;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_11 = BITS_4_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_12 = BITS_4_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_13 = BITS_4_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_14 = BITS_4_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_15 = BITS_4_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_16 = BITS_4_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_17 = BITS_4_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_18 = BITS_4_3;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_19 = BITS_4_3_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_20 = BITS_4_3_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_21 = BITS_4_3_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_22 = BITS_4_3_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_23 = BITS_4_3_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_24 = BITS_4_3_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_25 = BITS_4_3_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_26 = BITS_5;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_27 = BITS_5_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_28 = BITS_5_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_29 = BITS_5_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_30 = BITS_5_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_31 = BITS_5_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_32 = BITS_5_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_33 = BITS_5_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_34 = BITS_5_3;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_35 = BITS_5_3_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_36 = BITS_5_3_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_37 = BITS_5_3_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_38 = BITS_5_3_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_39 = BITS_5_3_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_40 = BITS_5_3_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_41 = BITS_5_3_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_42 = BITS_5_4;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_43 = BITS_5_4_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_44 = BITS_5_4_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_45 = BITS_5_4_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_46 = BITS_5_4_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_47 = BITS_5_4_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_48 = BITS_5_4_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_49 = BITS_5_4_2_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_50 = BITS_5_4_3;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_51 = BITS_5_4_3_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_52 = BITS_5_4_3_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_53 = BITS_5_4_3_1_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_54 = BITS_5_4_3_2;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_55 = BITS_5_4_3_2_0;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_56 = BITS_5_4_3_2_1;
const uint8_t SWx::OtpSWxDvsSelDisVolt::_3_30_57 = BITS_5_4_3_2_1_0;

const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6000 = BITS_NONE;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6125 = BITS_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6250 = BITS_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6375 = BITS_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6500 = BITS_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6625 = BITS_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6750 = BITS_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_6875 = BITS_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7000 = BITS_3;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7125 = BITS_3_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7250 = BITS_3_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7375 = BITS_3_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7500 = BITS_3_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7625 = BITS_3_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7750 = BITS_3_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_7875 = BITS_3_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8000 = BITS_4;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8125 = BITS_4_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8250 = BITS_4_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8375 = BITS_4_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8500 = BITS_4_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8625 = BITS_4_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8750 = BITS_4_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_8875 = BITS_4_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9000 = BITS_4_3;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9125 = BITS_4_3_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9250 = BITS_4_3_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9375 = BITS_4_3_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9500 = BITS_4_3_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9625 = BITS_4_3_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9750 = BITS_4_3_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_0_9875 = BITS_4_3_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0000 = BITS_5;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0125 = BITS_5_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0250 = BITS_5_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0375 = BITS_5_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0500 = BITS_5_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0625 = BITS_5_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0750 = BITS_5_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_0875 = BITS_5_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1000 = BITS_5_3;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1125 = BITS_5_3_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_125 = BITS_5_3_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1375 = BITS_5_3_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1500 = BITS_5_3_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1625 = BITS_5_3_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1750 = BITS_5_3_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_1875 = BITS_5_3_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2000 = BITS_5_4;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2125 = BITS_5_4_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2250 = BITS_5_4_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2375 = BITS_5_4_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2500 = BITS_5_4_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2625 = BITS_5_4_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2750 = BITS_5_4_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_2875 = BITS_5_4_2_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3000 = BITS_5_4_3;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3125 = BITS_5_4_3_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3250 = BITS_5_4_3_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3375 = BITS_5_4_3_1_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3500 = BITS_5_4_3_2;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3625 = BITS_5_4_3_2_0;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3750 = BITS_5_4_3_2_1;
const uint8_t SWx::OtpSWxDvsSelEnVolt::_1_3875 = BITS_5_4_3_2_1_0;

const uint8_t Sw1::Volt::kRegister = 0x32;
const uint8_t Sw1::StbyVolt::kRegister = 0x33;
const uint8_t Sw1::SlpVolt::kRegister = 0x34;
const uint8_t Sw1::Ctrl::kRegister = 0x35;
// Misnamed in data sheet as SLP_VOLT
const uint8_t Sw1::Ctrl1::kRegister = 0x36;
const uint8_t Sw1::PwrDnSeq::kRegister = 0x5F;

const uint8_t Sw2::Volt::kRegister = 0x38;
const uint8_t Sw2::StbyVolt::kRegister = 0x39;
const uint8_t Sw2::SlpVolt::kRegister = 0x3A;
const uint8_t Sw2::Ctrl::kRegister = 0x3B;
const uint8_t Sw2::Ctrl1::kRegister = 0x3C;
const uint8_t Sw2::PwrDnSeq::kRegister = 0x60;

const uint8_t Sw3::Volt::kRegister = 0x3E;
const uint8_t Sw3::StbyVolt::kRegister = 0x3F;
const uint8_t Sw3::SlpVolt::kRegister = 0x40;
const uint8_t Sw3::Ctrl::kRegister = 0x41;
const uint8_t Sw3::Ctrl1::kRegister = 0x42;
const uint8_t Sw3::PwrDnSeq::kRegister = 0x61;

/*
const SWx::PwrUp::PwrUpSeqMask SWx::PwrUp::k

    : public I2CRegister {
      struct PwrUpSeqMask : public Mask {
        static const uint8_t MASK = BITS_2_1_0;
        PwrUpSeqMask(uint8_t mask) : Mask(mask) {}
        // TODO(kendall): Figure these out
      };
      static const PwrUpSeqMask kPwrUpSeqMask;
      PwrUp(uint8_t device_address, uint8_t register_address)
          : I2CRegister(device_address, register_address) {}
    };

    struct Ctrl : public I2CRegister {
      struct EnableMask : public Msak {
        static const uint8_t ENABLED = BITS_0;
        static const uint8_t DISABLED = BITS_NONE;
        EnableMask(uint8_t mask) : Mask(mask) {}
      };
      struct StbyMask : public Mask {
        static const uint8_t ENABLED = BITS_1;
        static const uint8_t DISABLED = BITS_NONE;
        StbyMask(uint8_t mask) : Mask(mask) {}
      };
      struct OmodeMask : public Mask {
        static const uint8_t ENABLED = BITS_2;
        static const uint8_t DISABLED = BITS_NONE;
        OmodeMask(uint8_t mask) : Mask(mask) {}
      };
      struct LPwrMask : public Mask {
        static const uint8_t ENABLED = BITS_3;
        static const uint8_t DISABLED = BITS_NONE;
        LPwrMask(uint8_t mask) : Mask(mask) {}
      };

      struct DvsSpeedMask : public Mask {
        static const uint8_t _12_5MV_DIV_2US = BITS_4;
        static const uint8_t _12_5MV_DIV_4US = BITS_NONE;
        DvsSpeedMask(uint8_t mask) : Mask(mask) {}
      };
      struct FPwmInDvsMask : public Mask {
        static const uint8_t FORCE = BITS_5;
        static const uint8_t NO_FORCE = BITS_NONE;
        FPwmInDvsMask(uint8_t mask) : Mask(mask) {}
      };
      struct FPwmMask {
        static const uint8_t FPWM_ON = BITS_6;
        static const uint8_t NO_FPWM = BITS_NONE;
        FPwmMask(uint8_t mask) : Mask(mask) {}
      };

      struct RDisMask : public Mask {
        static const uint8_t ENABLED = BITS_7;
        static const uint8_t DISABLED = BITS_NONE;
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
          : I2CRegister(device_address, register_address)
    };
    struct Ctrl1 : public I2CRegister {
      struct ILimMask : public Mask {
        static const uint8_t _1A = BITS_NONE;
        static const uint8_t _1_2A = BITS_0;
        static const uint8_t _1_5A = BITS_1;
        static const uint8_t _2A = BITS_1_0;
        ILimMask(uint8_t mask) : Mask(mask) {}
      };
      struct TmodeMask : public Mask {
        static const uint8_t T_ON = BITS_4;
        static const uint8_t T_OFF = BITS_NONE;
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
        static const uint8_t MASK = BITS_2_1_0;
        PwrDnSeqMask(uint8_t mask) : Mask(mask) {}
      };
      static const PwrDnSeqMask kPwrDnSeqMask;

      PwrDn(uint8_t device_address, register_address)
          : I2CRegister(device_address, register_address) {}
    };
    }
    ;
    */
// end of swx.h