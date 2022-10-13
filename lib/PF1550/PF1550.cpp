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

const uint8_t CoinCellControl::kRegister = 0x30;
const CoinCellControl::VCoinMask CoinCellControl::kVCoinMask(BITS_3_2_1_0);
const uint8_t CoinCellControl::VCoinMask::_1_8 = BITS_NONE;
const uint8_t CoinCellControl::VCoinMask::_1_9 = BITS_0;
const uint8_t CoinCellControl::VCoinMask::_2_0 = BITS_1;
const uint8_t CoinCellControl::VCoinMask::_2_1 = BITS_1_0;
const uint8_t CoinCellControl::VCoinMask::_2_2 = BITS_2;
const uint8_t CoinCellControl::VCoinMask::_2_3 = BITS_2_0;
const uint8_t CoinCellControl::VCoinMask::_2_4 = BITS_2_1;
const uint8_t CoinCellControl::VCoinMask::_2_5 = BITS_2_1_0;
const uint8_t CoinCellControl::VCoinMask::_2_6 = BITS_3;
const uint8_t CoinCellControl::VCoinMask::_2_7 = BITS_3_0;
const uint8_t CoinCellControl::VCoinMask::_2_8 = BITS_3_1;
const uint8_t CoinCellControl::VCoinMask::_2_9 = BITS_3_1_0;
const uint8_t CoinCellControl::VCoinMask::_3_0 = BITS_3_2;
const uint8_t CoinCellControl::VCoinMask::_3_1 = BITS_3_2_0;
const uint8_t CoinCellControl::VCoinMask::_3_2 = BITS_3_2_1;
const uint8_t CoinCellControl::VCoinMask::_3_3 = BITS_3_2_1_0;
const CoinCellControl::ChEnMask CoinCellControl::kChEnMask(BITS_4);
const uint8_t CoinCellControl::ChEnMask::DISABLED = BITS_NONE;
const uint8_t CoinCellControl::ChEnMask::ENABLED = BITS_4;

const uint8_t VSNVSCtrl::kRegister = 0x48;
const VSNVSCtrl::CLKPulseMask VSNVSCtrl::kCLKPulseMask(BITS_3);
const VSNVSCtrl::ForceBOSMask VSNVSCtrl::kForceBOSMask(BITS_4);
const uint8_t VSNVSCtrl::ForceBOSMask::FORCED = BITS_4;
const uint8_t VSNVSCtrl::ForceBOSMask::ONLY_VSYS_LT_VDIV = BITS_NONE;
const VSNVSCtrl::LiBGDisMask VSNVSCtrl::kLiBGDisMask(BITS_4);
const uint8_t VSNVSCtrl::LiBGDisMask::VSNVS_BAND_GAP_DISABLED = BITS_NONE;
const uint8_t VSNVSCtrl::LiBGDisMask::VSNVS_BAND_GAP_ENABLED = BITS_5;

const uint8_t VREFDDRCtrl::kRegister = 0x4A;
const VREFDDRCtrl::VREFDDREnMask VREFDDRCtrl::kVREFDDREnMask(BITS_0);
const uint8_t VREFDDRCtrl::VREFDDREnMask::ENABLE = BITS_0;
const uint8_t VREFDDRCtrl::VREFDDREnMask::DISABLE = BITS_NONE;
const VREFDDRCtrl::VREFDDRStbyEnMask VREFDDRCtrl::kVREFDDRStbyEnMask(BITS_1);
const uint8_t VREFDDRCtrl::VREFDDRStbyEnMask::ENABLE = BITS_1;
const uint8_t VREFDDRCtrl::VREFDDRStbyEnMask::DISABLE = BITS_NONE;
const VREFDDRCtrl::VREFDDROModeMask VREFDDRCtrl::kVREFDDROModeMask(BITS_2);
const uint8_t VREFDDRCtrl::VREFDDROModeMask::ENABLE = BITS_2;
const uint8_t VREFDDRCtrl::VREFDDROModeMask::DISABLE = BITS_NONE;
const VREFDDRCtrl::VREFDDRLPwrMask VREFDDRCtrl::kVREFDDRLPwrMask(BITS_3);
const uint8_t VREFDDRCtrl::VREFDDRLPwrMask::ENABLE = BITS_3;
const uint8_t VREFDDRCtrl::VREFDDRLPwrMask::DISABLE = BITS_NONE;

const uint8_t VREFDDRPwrDnSeq::kRegister = 0x65;
const VREFDDRPwrDnSeq::VREFDDRPwrDnSeqMask
    VREFDDRPwrDnSeq::kVREFDDRPwrDnSeqMask(BITS_2_1_0);