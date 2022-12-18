#include "PF1550.h"

using namespace PMIC;

// DeviceInfo.h
const DeviceId::DeviceIdMask DeviceId::kDeviceIdMask(BITS_2_1_0);

const OtpFlavor::ModelMask OtpFlavor::kModelMask(BITS_ALL);

const SiliconRev::MetalLayerRevMask SiliconRev::kMetalLayerRevMask(BITS_2_1_0);
const SiliconRev::FullLayerRevMask SiliconRev::kFullLayerRevMask(BITS_5_4_3);
const SiliconRev::FabFinMask SiliconRev::kFabFinMask(BITS_7_6);

const StateInfo::StateMask StateInfo::kStateMask(BITS_ALL);

const I2cAddr::AddrMask I2cAddr::kAddrMask(BITS_2_1_0);

const Rc16mhz::Req16MhzMask Rc16mhz::kReq16MhzMask(BITS_0);
const Rc16mhz::ReqAcoreOnMask Rc16mhz::kReqAcoreOnMask(BITS_1);
const Rc16mhz::ReqAcoreHiPwrMask Rc16mhz::kReqAcoreHiPwrMask(BITS_2);
// End DeviceInfo.h

// Misc.h
const IntCategory::ChgIntMask IntCategory::kChgIntMask(BITS_0);
const IntCategory::Sw1IntMask IntCategory::kSw1IntMask(BITS_1);
const IntCategory::Sw2IntMask IntCategory::kSw2IntMask(BITS_2);
const IntCategory::Sw3IntMask IntCategory::kSw3IntMask(BITS_3);
const IntCategory::LdoIntMask IntCategory::kLdoIntMask(BITS_4);
const IntCategory::OnkeyIntMask IntCategory::kOnkeyIntMask(BITS_5);
const IntCategory::TempIntMask IntCategory::kTempIntMask(BITS_6);
const IntCategory::MiscIntMask IntCategory::kMiscIntMask(BITS_7);

const TempIntStat0::Therm110IMask TempIntStat0::kTherm110IMask(BITS_0);
const TempIntStat0::Therm125IMask TempIntStat0::kTherm125IMask(BITS_2);

const TempIntMask0::Therm110MMask TempIntMask0::kTherm110MMask(BITS_0);
const TempIntMask0::Therm125MMask TempIntMask0::kTherm125MMask(BITS_2);

const TempIntSense0::Therm110SMask TempIntSense0::kTherm110SMask(BITS_0);
const TempIntSense0::Therm125SMask TempIntSense0::kTherm125SMask(BITS_2);

const OnkeyIntStat0::OnkeyPushIMask OnkeyIntStat0::kOnkeyPushIMask(BITS_0);
const OnkeyIntStat0::Onkey1SIMask OnkeyIntStat0::kOnkey1SIMask(BITS_1);
const OnkeyIntStat0::Onkey2SIMask OnkeyIntStat0::kOnkey2SIMask(BITS_2);
const OnkeyIntStat0::Onkey3SIMask OnkeyIntStat0::kOnkey3SIMask(BITS_3);
const OnkeyIntStat0::Onkey4SIMask OnkeyIntStat0::kOnkey4SIMask(BITS_4);
const OnkeyIntStat0::Onkey8SIMask OnkeyIntStat0::kOnkey8SIMask(BITS_5);

const OnkeyIntMask0::OnkeyPushMMask OnkeyIntMask0::kOnkeyPushMMask(BITS_0);
const OnkeyIntMask0::Onkey1SMMask OnkeyIntMask0::kOnkey1SMMask(BITS_1);
const OnkeyIntMask0::Onkey2SMMask OnkeyIntMask0::kOnkey2SMMask(BITS_2);
const OnkeyIntMask0::Onkey3SMMask OnkeyIntMask0::kOnkey3SMMask(BITS_3);
const OnkeyIntMask0::Onkey4SMMask OnkeyIntMask0::kOnkey4SMMask(BITS_4);
const OnkeyIntMask0::Onkey8SMMask OnkeyIntMask0::kOnkey8SMMask(BITS_5);

const OnkeyIntSense0::OnkeyPushSMask OnkeyIntSense0::kOnkeyPushSMask(BITS_0);
const OnkeyIntSense0::Onkey1SSMask OnkeyIntSense0::kOnkey1SSMask(BITS_1);
const OnkeyIntSense0::Onkey2SSMask OnkeyIntSense0::kOnkey2SSMask(BITS_2);
const OnkeyIntSense0::Onkey3SSMask OnkeyIntSense0::kOnkey3SSMask(BITS_3);
const OnkeyIntSense0::Onkey4SSMask OnkeyIntSense0::kOnkey4SSMask(BITS_4);
const OnkeyIntSense0::Onkey8SSMask OnkeyIntSense0::kOnkey8SSMask(BITS_5);

const MiscIntStat0::PwrUpIMask MiscIntStat0::kPwrUpIMask(BITS_0);
const MiscIntStat0::PwrDnIMask MiscIntStat0::kPwrDnIMask(BITS_1);
const MiscIntStat0::PwrOnIMask MiscIntStat0::kPwrOnIMask(BITS_2);
const MiscIntStat0::LowSysWarnIMask MiscIntStat0::kLowSysWarnIMask(BITS_3);
const MiscIntStat0::SysOlvoIMask MiscIntStat0::kSysOlvoIMask(BITS_4);

const MiscIntMask0::PwrUpMMask MiscIntMask0::kPwrUpMMask(BITS_0);
const MiscIntMask0::PwrDnMMask MiscIntMask0::kPwrDnMMask(BITS_1);
const MiscIntMask0::PwrOnMMask MiscIntMask0::kPwrOnMMask(BITS_2);
const MiscIntMask0::LowSysWarnMMask MiscIntMask0::kLowSysWarnMMask(BITS_3);
const MiscIntMask0::SysOlvoMMask MiscIntMask0::kSysOlvoMMask(BITS_4);

const MiscIntSense0::PwrUpSMask MiscIntSense0::kPwrUpSMask(BITS_0);
const MiscIntSense0::PwrDnSMask MiscIntSense0::kPwrDnSMask(BITS_1);
const MiscIntSense0::PwrOnSMask MiscIntSense0::kPwrOnSMask(BITS_2);
const MiscIntSense0::LowSysWarnSMask MiscIntSense0::kLowSysWarnSMask(BITS_3);
const MiscIntSense0::SysOlvoSMask MiscIntSense0::kSysOlvoSMask(BITS_4);

const CoincellControl::VCoinMask CoincellControl::kVCoinMask(BITS_3_2_1_0);
const CoincellControl::ChEnMask CoincellControl::kChEnMask(BITS_4);

const VsnvsCtrl::CLKPulseMask VsnvsCtrl::kCLKPulseMask(BITS_3);
const VsnvsCtrl::ForceBOSMask VsnvsCtrl::kForceBOSMask(BITS_4);
const VsnvsCtrl::LiBGDisMask VsnvsCtrl::kLiBGDisMask(BITS_4);

const VrefddrCtrl::VrefddrEnMask VrefddrCtrl::kVrefddrEnMask(BITS_0);
const VrefddrCtrl::VrefddrStbyEnMask VrefddrCtrl::kVrefddrStbyEnMask(BITS_1);
const VrefddrCtrl::VrefddrOModeMask VrefddrCtrl::kVrefddrOModeMask(BITS_2);
const VrefddrCtrl::VrefddrLPwrMask VrefddrCtrl::kVrefddrLPwrMask(BITS_3);

const VrefddrPwrDnSeq::VrefddrPwrDnSeqMask
    VrefddrPwrDnSeq::kVrefddrPwrDnSeqMask(BITS_2_1_0);

// TODO(kendall): Figure out the right register. This conflicts with RC_16MHz
const Key1::Key1Mask Key1::kKey1Mask(BITS_2_1_0);
// End Misc.h

// Charger.h

const ChgInt::SupIMask ChgInt::kSupIMask(BITS_0);
const ChgInt::Bat2SocIMask ChgInt::kBat2SocIMask(BITS_1);
const ChgInt::BatIMask ChgInt::kBatIMask(BITS_2);
const ChgInt::ChgIMask ChgInt::kChgIMask(BITS_3);
const ChgInt::VbusIMask ChgInt::kVbusIMask(BITS_5);
const ChgInt::VbusDpmIMask ChgInt::kVbusDpmIMask(BITS_6);
const ChgInt::ThmIMask ChgInt::kThmIMask(BITS_7);

const ChgIntMask::SupMMask ChgIntMask::kSupMMask(BITS_0);
const ChgIntMask::Bat2SocMMask ChgIntMask::kBat2SocMMask(BITS_1);
const ChgIntMask::BatMMask ChgIntMask::kBatMMask(BITS_2);
const ChgIntMask::ChgMMask ChgIntMask::kChgMMask(BITS_3);
const ChgIntMask::VbusMMask ChgIntMask::kVbusMMask(BITS_5);
const ChgIntMask::VbusDpmMMask ChgIntMask::kVbusDpmMMask(BITS_6);
const ChgIntMask::ThmMMask ChgIntMask::kThmMMask(BITS_7);

const ChgIntOk::SupOkMask ChgIntOk::kSupOkMask(BITS_0);
const ChgIntOk::Bat2SocOkMask ChgIntOk::kBat2SocOkMask(BITS_1);
const ChgIntOk::BatOkMask ChgIntOk::kBatOkMask(BITS_2);
const ChgIntOk::ChgOkMask ChgIntOk::kChgOkMask(BITS_3);
const ChgIntOk::VbusOkMask ChgIntOk::kVbusOkMask(BITS_5);
const ChgIntOk::VbusDpmOkMask ChgIntOk::kVbusDpmOkMask(BITS_6);
const ChgIntOk::ThmOkMask ChgIntOk::kThmOkMask(BITS_7);

const VbusSns::VbusUvloSnsMask VbusSns::kVbusUvloSnsMask(BITS_2);
const VbusSns::VbusIn2SysSnsMask VbusSns::kVbusIn2SysSnsMask(BITS_3);
const VbusSns::VbusOvloSnsMask VbusSns::kVbusOvloSnsMask(BITS_4);
const VbusSns::VbusValidMask VbusSns::kVbusValidMask(BITS_5);
const VbusSns::VbusDpmSnsMask VbusSns::kVbusDpmSnsMask(BITS_7);

const ChgSns::ChgSnsMask ChgSns::kChgSnsMask(BITS_3_2_1_0);
const ChgSns::WdtSnsMask ChgSns::kWdtSnsMask(BITS_5);
const ChgSns::ThmSnsMask ChgSns::kThmSnsMask(BITS_6);
const ChgSns::TregSnsMask ChgSns::kTregSnsMask(BITS_7);

const BattSns::BattSnsMask BattSns::kBattSnsMask(BITS_2_1_0);
const BattSns::BattOCSnsMask BattSns::kBattOCSnsMask(BITS_5);

const ChgOper::ChgOperMask ChgOper::kChgOperMask(BITS_1_0);
const ChgOper::WdtEnMask ChgOper::kWdtEnMask(BITS_3);
const ChgOper::DisBattFetMask ChgOper::kDisBattFetMask(BITS_4);

const ChgTmr::FChgTimeMask ChgTmr::kFChgTimeMask(BITS_2_1_0);
const ChgTmr::EoCTimeMask ChgTmr::kEoCTimeMask(BITS_5_4_3);
const ChgTmr::TPreChgMask ChgTmr::kTPreChgMask(BITS_7);

const ChgEocCnfg::ChgRestartMask ChgEocCnfg::kChgRestartMask(BITS_1_0);
const ChgEocCnfg::IEoCMask ChgEocCnfg::kIEoCMask(BITS_6_5_4);

const ChgCurrCnfg::ChgCcMask ChgCurrCnfg::kChgCcMask(BITS_4_3_2_1_0);
const ChgCurrCnfg::PreChgLbThrsMask ChgCurrCnfg::kPreChgLbThrsMask(BITS_6_5);

const BattReg::ChgCvMask BattReg::kChgCvMask(BITS_5_4_3_2_1_0);
const BattReg::VsysMinMask BattReg::kVsysMinMask(BITS_7_6);

const BatfetCnfg::WdtClrMask BatfetCnfg::kWdtClrMask(BITS_1_0);
const BatfetCnfg::BOVRCDisBattFetMask BatfetCnfg::kBOVRCDisBattFetMask(BITS_3);
const BatfetCnfg::BattFetOCMask BatfetCnfg::kBattFetOCMask(BITS_5_4);
const BatfetCnfg::WdTimeMask BatfetCnfg::kWdTimeMask(BITS_6);
const BatfetCnfg::BOVRCNoVBusMask BatfetCnfg::kBOVRCNoVBusMask(BITS_7);

const ThmRegCnfg::ThmCnfgMask ThmRegCnfg::kThmCnfgMask(BITS_1_0);
const ThmRegCnfg::RegTempMask ThmRegCnfg::kRegTempMask(BITS_3_2);
const ThmRegCnfg::ThmColdMask ThmRegCnfg::kThmColdMask(BITS_4);
const ThmRegCnfg::ThmHotMask ThmRegCnfg::kThmHotMask(BITS_5);
const ThmRegCnfg::TempFbEnMask ThmRegCnfg::kTempFbEnMask(BITS_7);

const VbusInLimCnfg::VbusLinILimMask
    VbusInLimCnfg::kVbusLinILimMask(BITS_7_6_5_4_3);

const VbusLinDpm::VbusDpmRegMask VbusLinDpm::kVbusDpmRegMask(BITS_2_1_0);
const VbusLinDpm::PreChgdBattThrshMask
    VbusLinDpm::kPreChgdBattThrshMask(BITS_4_3);
const VbusLinDpm::VinDpmStopMask VbusLinDpm::kVinDpmStopMask(BITS_5);
const VbusLinDpm::FetScaleMask VbusLinDpm::kFetScaleMask(BITS_7);

const UsbPhyLdoCnfg::ActDisPhyMask UsbPhyLdoCnfg::kActDisPhyMask(BITS_0);
const UsbPhyLdoCnfg::UsbPhyMask UsbPhyLdoCnfg::kUsbPhyMask(BITS_1);
const UsbPhyLdoCnfg::UsbPhyLdoMask UsbPhyLdoCnfg::kUsbPhyLdoMask(BITS_2);

const DbncDelayTime::VbusOvTdbMask DbncDelayTime::kVbusOvTdbMask(BITS_1_0);
const DbncDelayTime::UsbPhyTdbMask DbncDelayTime::kUsbPhyTdbMask(BITS_3_2);
const DbncDelayTime::SysWkUpDlyMask DbncDelayTime::kSysWkUpDlyMask(BITS_5_4);

const ChgIntCnfg::ChgIntGenMask ChgIntCnfg::kChgIntGenMask(BITS_0);
const ChgIntCnfg::EoCIntMask ChgIntCnfg::kEoCIntMask(BITS_1);

const ThmAdjSetting::ThmWarmMask ThmAdjSetting::kThmWarmMask(BITS_0);
const ThmAdjSetting::ThmCoolMask ThmAdjSetting::kThmCoolMask(BITS_1);
const ThmAdjSetting::CvAdjMask ThmAdjSetting::kCvAdjMask(BITS_3_2);
const ThmAdjSetting::CcAdjMask ThmAdjSetting::kCcAdjMask(BITS_5_4);

const Vbus2SysCnfg::Vbus2SysTdbMask Vbus2SysCnfg::kVbus2SysTdbMask(BITS_1_0);
const Vbus2SysCnfg::Vbus2SysThrshMask Vbus2SysCnfg::kVbus2SysThrshMask(BITS_2);

const LedPwm::LedPwmMask LedPwm::kLedPwmMask(BITS_5_4_3_2_1_0);
const LedPwm::LedRampMask LedPwm::kLedRampMask(BITS_6);
const LedPwm::LedEnMask LedPwm::kLedEnMask(BITS_7);

const FaultBatfetCnfg::WdFltBfFetEnMask
    FaultBatfetCnfg::kWdFltBfFetEnMask(BITS_0);
const FaultBatfetCnfg::ThmSusBFetEnMask
    FaultBatfetCnfg::kThmSusBFetEnMask(BITS_1);
const FaultBatfetCnfg::TShdnBFetEnMask
    FaultBatfetCnfg::kTShdnBFetEnMask(BITS_2);
const FaultBatfetCnfg::TmrFltBFetEnMask
    FaultBatfetCnfg::kTmrFltBFetEnMask(BITS_3);

const LedCnfg::LedFreqMask LedCnfg::kLedFreqMask(BITS_1_0);
const LedCnfg::LedCurrentMask LedCnfg::kLedCurrentMask(BITS_3_2);
const LedCnfg::LedCfgMask LedCnfg::kLedCfgMask(BITS_4);
const LedCnfg::LedOvrdMask LedCnfg::kLedOvrdMask(BITS_5);
// End charger.h

// Pwrctrl.h
const Pwrctrl0::StandbyDlyMask Pwrctrl0::kStandbyDlyMask(BITS_1_0);
// TODO(kendall): WTF? these don't make sense
const Pwrctrl0::StandbyInvMask Pwrctrl0::kStandbyInvMask(BITS_2);
const Pwrctrl0::PoRDlyMask Pwrctrl0::kPoRDlyMask(BITS_5_4_3);
const Pwrctrl0::TgResetMask Pwrctrl0::kTgResetMask(BITS_7_6);

const Pwrctrl1::PwronDbncMask Pwrctrl1::kPwronDbncMask(BITS_1_0);
const Pwrctrl1::OnkeyBbncMask Pwrctrl1::kOnkeyBbncMask(BITS_3_2);
const Pwrctrl1::PwronRstEnMask Pwrctrl1::kPwronRstEnMask(BITS_4);
const Pwrctrl1::RestartEnMask Pwrctrl1::kRestartEnMask(BITS_5);
const Pwrctrl1::RegScpEnMask Pwrctrl1::kRegScpEnMask(BITS_6);
const Pwrctrl1::OnkeyRstEnmask Pwrctrl1::kOnkeyRstEnmask(BITS_7);

const Pwrctrl2::UvdetMask Pwrctrl2::kUvdetMask(BITS_1_0);
const Pwrctrl2::LowSysWarnMask Pwrctrl2::kLowSysWarnMask(BITS_3_2);

const Pwrctrl3::GotoShipMask Pwrctrl3::kGotoShipMask(BITS_0);
const Pwrctrl3::CoreOffMask Pwrctrl3::kCoreOffMask(BITS_1);
// End of pwrctrl.h
// LDOy.h
const LdoIntStat0::Ldo1FaultIMask LdoIntStat0::kLdo1FaultIMask(BITS_0);
const LdoIntStat0::Ldo2FaultIMask LdoIntStat0::kLdo2FaultIMask(BITS_1);
const LdoIntStat0::Ldo3FaultIMask LdoIntStat0::kLdo3FaultIMask(BITS_2);

const LdoIntMask0::Ldo1FaultMMask LdoIntMask0::kLdo1FaultMMask(BITS_0);
const LdoIntMask0::Ldo2FaultMMask LdoIntMask0::kLdo2FaultMMask(BITS_1);
const LdoIntMask0::Ldo3FaultMMask LdoIntMask0::kLdo3FaultMMask(BITS_2);

const LdoIntSense0::Ldo1FaultSMask LdoIntSense0::kLdo1FaultSMask(BITS_0);
const LdoIntSense0::Ldo2FaultSMask LdoIntSense0::kLdo2FaultSMask(BITS_1);
const LdoIntSense0::Ldo3FaultSMask LdoIntSense0::kLdo3FaultSMask(BITS_2);

const LDOy::Volt::VoltMask LDOy::Volt::kVoltMask(BITS_3_2_1_0);

const LDOy::Ctrl::EnableMask LDOy::Ctrl::kEnableMask(BITS_0);
const LDOy::Ctrl::StbyMask LDOy::Ctrl::kStbyMask(BITS_1);
const LDOy::Ctrl::OmodeMask LDOy::Ctrl::kOmodeMask(BITS_2);
const LDOy::Ctrl::LPwrMask LDOy::Ctrl::kLPwrMask(BITS_3);
const LDOy::Ctrl::LsMask LDOy::Ctrl::kLsMask(BITS_4);
const LDOy::PwrDnSeq::PwrDnSeqMask LDOy::PwrDnSeq::kPwrDnSeqMask(BITS_2_1_0);

// end of LDOy.h

// swx.h
const SwIntStat0::Sw1LsIMask SwIntStat0::kSw1LsIMask(BITS_0);
const SwIntStat0::Sw2LsIMask SwIntStat0::kSw2LsIMask(BITS_1);
const SwIntStat0::Sw3LsIMask SwIntStat0::kSw3LsIMask(BITS_2);

const SwIntMask0::Sw1LsMMask SwIntMask0::kSw1LsMMask(BITS_0);
const SwIntMask0::Sw2LsMMask SwIntMask0::kSw2LsMMask(BITS_1);
const SwIntMask0::Sw3LsMMask SwIntMask0::kSw3LsMMask(BITS_2);

const SwIntSense0::Sw1LsSMask SwIntSense0::kSw1LsSMask(BITS_0);
const SwIntSense0::Sw2LsSMask SwIntSense0::kSw2LsSMask(BITS_1);
const SwIntSense0::Sw3LsSMask SwIntSense0::kSw3LsSMask(BITS_2);

const SwIntStat1::Sw1HsIMask SwIntStat1::kSw1HsIMask(BITS_0);
const SwIntStat1::Sw2HsIMask SwIntStat1::kSw2HsIMask(BITS_1);
const SwIntStat1::Sw3HsIMask SwIntStat1::kSw3HsIMask(BITS_2);

const SwIntMask1::Sw1HsMMask SwIntMask1::kSw1HsMMask(BITS_0);
const SwIntMask1::Sw2HsMMask SwIntMask1::kSw2HsMMask(BITS_1);
const SwIntMask1::Sw3HsMMask SwIntMask1::kSw3HsMMask(BITS_2);

const SwIntSense1::Sw1HsSMask SwIntSense1::kSw1HsSMask(BITS_0);
const SwIntSense1::Sw2HsSMask SwIntSense1::kSw2HsSMask(BITS_1);
const SwIntSense1::Sw3HsSMask SwIntSense1::kSw3HsSMask(BITS_2);

const SwIntStat2::Sw1DvsDoneIMask SwIntStat2::kSw1DvsDoneIMask(BITS_0);
const SwIntStat2::Sw2DvsDoneIMask SwIntStat2::kSw2DvsDoneIMask(BITS_1);
const SwIntStat2::Sw3DvsDoneIMask SwIntStat2::kSw3DvsDoneIMask(BITS_2);

const SwIntMask2::Sw1DvsDoneMMask SwIntMask2::kSw1DvsDoneMMask(BITS_0);
const SwIntMask2::Sw2DvsDoneMMask SwIntMask2::kSw2DvsDoneMMask(BITS_1);
const SwIntMask2::Sw3DvsDoneMMask SwIntMask2::kSw3DvsDoneMMask(BITS_2);

const SwIntSense2::Sw1DvsDoneSMask SwIntSense2::kSw1DvsDoneSMask(BITS_0);
const SwIntSense2::Sw2DvsDoneSMask SwIntSense2::kSw2DvsDoneSMask(BITS_1);
const SwIntSense2::Sw3DvsDoneSMask SwIntSense2::kSw3DvsDoneSMask(BITS_2);

const struct SWx::Volt::VoltMask SWx::Volt::kVoltMask(BITS_5_4_3_2_1_0);
const SWx::SlpVolt::SlpVoltMask SWx::SlpVolt::kSlpVoltMask(BITS_5_4_3_2_1_0);
const SWx::StbyVolt::StbyVoltMask
    SWx::StbyVolt::kStbyVoltMask(BITS_5_4_3_2_1_0);

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