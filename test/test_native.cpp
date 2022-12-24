#ifdef UNIT_TEST
#include "BatfetCnfg.h"
#include "BattReg.h"
#include "BattSns.h"
#include "ChgCurrCnfg.h"
#include "ChgEocCnfg.h"
#include "ChgInt.h"
#include "ChgIntCnfg.h"
#include "ChgIntMask.h"
#include "ChgIntOk.h"
#include "ChgOper.h"
#include "ChgSns.h"
#include "ChgTmr.h"
#include "CoincellControl.h"
#include "DbncDelayTime.h"
#include "DeviceId.h"
#include "FaultBatfetCnfg.h"
#include "I2cAddr.h"
#include "IntCategory.h"
#include "Ldo1.h"
#include "Ldo2.h"
#include "Ldo3.h"
#include "LdoIntMask0.h"
#include "LdoIntSense0.h"
#include "LdoIntStat0.h"
#include "LedCnfg.h"
#include "LedPwm.h"
#include "MiscIntMask0.h"
#include "MiscIntSense0.h"
#include "MiscIntStat0.h"
#include "OnkeyIntMask0.h"
#include "OnkeyIntSense0.h"
#include "OnkeyIntStat0.h"
#include "OtpFlavor.h"
#include "PF1550.h"
#include "Pwrctrl0.h"
#include "Pwrctrl1.h"
#include "Pwrctrl2.h"
#include "Pwrctrl3.h"
#include "Rc16mhz.h"
#include "SiliconRev.h"
#include "StateInfo.h"
#include "Sw1.h"
#include "Sw2.h"
#include "Sw3.h"
#include "SwIntMask0.h"
#include "SwIntMask1.h"
#include "SwIntMask2.h"
#include "SwIntSense0.h"
#include "SwIntSense1.h"
#include "SwIntSense2.h"
#include "SwIntStat0.h"
#include "SwIntStat1.h"
#include "SwIntStat2.h"
#include "TempIntMask0.h"
#include "TempIntSense0.h"
#include "TempIntStat0.h"
#include "ThmAdjSetting.h"
#include "ThmRegCnfg.h"
#include "UsbPhyLdoCnfg.h"
#include "Vbus2SysCnfg.h"
#include "VbusInLimCnfg.h"
#include "VbusLinDpm.h"
#include "VbusSns.h"
#include "VrefddrCtrl.h"
#include "VrefddrPwrDnSeq.h"
#include "VsnvsCtrl.h"
#include <Arduino.h>
#include <unity.h>
using namespace fakeit;
using namespace PMIC;

void setUp(void) { ArduinoFakeReset(); }
namespace PMIC {
struct PF1550Test {
  static void test_DeviceId_address() {
    PF1550<DeviceId> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x0, pf1550.get_register<DeviceId>().kRegisterAddress);
  }
  static void test_OtpFlavor_address() {
    PF1550<OtpFlavor> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x1, pf1550.get_register<OtpFlavor>().kRegisterAddress);
  }

  static void test_SiliconRev_address() {
    PF1550<SiliconRev> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x2, pf1550.get_register<SiliconRev>().kRegisterAddress);
  }

  static void test_IntCategory_address() {
    PF1550<IntCategory> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x6, pf1550.get_register<IntCategory>().kRegisterAddress);
  }

  static void test_SwIntStat0_address() {
    PF1550<SwIntStat0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x8, pf1550.get_register<SwIntStat0>().kRegisterAddress);
  }

  static void test_SwIntMask0_address() {
    PF1550<SwIntMask0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x9, pf1550.get_register<SwIntMask0>().kRegisterAddress);
  }

  static void test_SwIntSense0_address() {
    PF1550<SwIntSense0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0xa, pf1550.get_register<SwIntSense0>().kRegisterAddress);
  }

  static void test_SwIntStat1_address() {
    PF1550<SwIntStat1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0xb, pf1550.get_register<SwIntStat1>().kRegisterAddress);
  }

  static void test_SwIntMask1_address() {
    PF1550<SwIntMask1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0xc, pf1550.get_register<SwIntMask1>().kRegisterAddress);
  }

  static void test_SwIntSense1_address() {
    PF1550<SwIntSense1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0xd, pf1550.get_register<SwIntSense1>().kRegisterAddress);
  }

  static void test_SwIntStat2_address() {
    PF1550<SwIntStat2> pf1550(0x08);
    TEST_ASSERT_EQUAL(0xe, pf1550.get_register<SwIntStat2>().kRegisterAddress);
  }

  static void test_SwIntMask2_address() {
    PF1550<SwIntMask2> pf1550(0x08);
    TEST_ASSERT_EQUAL(0xf, pf1550.get_register<SwIntMask2>().kRegisterAddress);
  }

  static void test_SwIntSense2_address() {
    PF1550<SwIntSense2> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x10,
                      pf1550.get_register<SwIntSense2>().kRegisterAddress);
  }

  static void test_LdoIntStat0_address() {
    PF1550<LdoIntStat0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x18,
                      pf1550.get_register<LdoIntStat0>().kRegisterAddress);
  }

  static void test_LdoIntMask0_address() {
    PF1550<LdoIntMask0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x19,
                      pf1550.get_register<LdoIntMask0>().kRegisterAddress);
  }

  static void test_LdoIntSense0_address() {
    PF1550<LdoIntSense0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x1a,
                      pf1550.get_register<LdoIntSense0>().kRegisterAddress);
  }

  static void test_TempIntStat0_address() {
    PF1550<TempIntStat0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x20,
                      pf1550.get_register<TempIntStat0>().kRegisterAddress);
  }

  static void test_TempIntMask0_address() {
    PF1550<TempIntMask0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x21,
                      pf1550.get_register<TempIntMask0>().kRegisterAddress);
  }

  static void test_TempIntSense0_address() {
    PF1550<TempIntSense0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x22,
                      pf1550.get_register<TempIntSense0>().kRegisterAddress);
  }

  static void test_OnkeyIntStat0_address() {
    PF1550<OnkeyIntStat0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x24,
                      pf1550.get_register<OnkeyIntStat0>().kRegisterAddress);
  }

  static void test_OnkeyIntMask0_address() {
    PF1550<OnkeyIntMask0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x25,
                      pf1550.get_register<OnkeyIntMask0>().kRegisterAddress);
  }

  static void test_OnkeyIntSense0_address() {
    PF1550<OnkeyIntSense0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x26,
                      pf1550.get_register<OnkeyIntSense0>().kRegisterAddress);
  }

  static void test_MiscIntStat0_address() {
    PF1550<MiscIntStat0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x28,
                      pf1550.get_register<MiscIntStat0>().kRegisterAddress);
  }

  static void test_MiscIntMask0_address() {
    PF1550<MiscIntMask0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x29,
                      pf1550.get_register<MiscIntMask0>().kRegisterAddress);
  }

  static void test_MiscIntSense0_address() {
    PF1550<MiscIntSense0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x2a,
                      pf1550.get_register<MiscIntSense0>().kRegisterAddress);
  }

  static void test_CoincellControl_address() {
    PF1550<CoincellControl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x30,
                      pf1550.get_register<CoincellControl>().kRegisterAddress);
  }

  static void test_Sw1Volt_address() {
    PF1550<Sw1::Volt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x32, pf1550.get_register<Sw1::Volt>().kRegisterAddress);
  }

  static void test_Sw1StbyVolt_address() {
    PF1550<Sw1::StbyVolt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x33,
                      pf1550.get_register<Sw1::StbyVolt>().kRegisterAddress);
  }

  static void test_Sw1SlpVolt_address() {
    PF1550<Sw1::SlpVolt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x34,
                      pf1550.get_register<Sw1::SlpVolt>().kRegisterAddress);
  }

  static void test_Sw1Ctrl_address() {
    PF1550<Sw1::Ctrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x35, pf1550.get_register<Sw1::Ctrl>().kRegisterAddress);
  }

  static void test_Sw1Ctrl1_address() {
    PF1550<Sw1::Ctrl1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x36, pf1550.get_register<Sw1::Ctrl1>().kRegisterAddress);
  }

  static void test_Sw2Volt_address() {
    PF1550<Sw2::Volt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x38, pf1550.get_register<Sw2::Volt>().kRegisterAddress);
  }

  static void test_Sw2StbyVolt_address() {
    PF1550<Sw2::StbyVolt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x39,
                      pf1550.get_register<Sw2::StbyVolt>().kRegisterAddress);
  }

  static void test_Sw2SlpVolt_address() {
    PF1550<Sw2::SlpVolt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x3a,
                      pf1550.get_register<Sw2::SlpVolt>().kRegisterAddress);
  }

  static void test_Sw2Ctrl_address() {
    PF1550<Sw2::Ctrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x3b, pf1550.get_register<Sw2::Ctrl>().kRegisterAddress);
  }

  static void test_Sw2Ctrl1_address() {
    PF1550<Sw2::Ctrl1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x3c, pf1550.get_register<Sw2::Ctrl1>().kRegisterAddress);
  }

  static void test_Sw3Volt_address() {
    PF1550<Sw3::Volt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x3e, pf1550.get_register<Sw3::Volt>().kRegisterAddress);
  }

  static void test_Sw3StbyVolt_address() {
    PF1550<Sw3::StbyVolt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x3f,
                      pf1550.get_register<Sw3::StbyVolt>().kRegisterAddress);
  }

  static void test_Sw3SlpVolt_address() {
    PF1550<Sw3::SlpVolt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x40,
                      pf1550.get_register<Sw3::SlpVolt>().kRegisterAddress);
  }

  static void test_Sw3Ctrl_address() {
    PF1550<Sw3::Ctrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x41, pf1550.get_register<Sw3::Ctrl>().kRegisterAddress);
  }

  static void test_Sw3Ctrl1_address() {
    PF1550<Sw3::Ctrl1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x42, pf1550.get_register<Sw3::Ctrl1>().kRegisterAddress);
  }

  static void test_VsnvsCtrl_address() {
    PF1550<VsnvsCtrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x48, pf1550.get_register<VsnvsCtrl>().kRegisterAddress);
  }

  static void test_VrefddrCtrl_address() {
    PF1550<VrefddrCtrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x4a,
                      pf1550.get_register<VrefddrCtrl>().kRegisterAddress);
  }

  static void test_Ldo1Volt_address() {
    PF1550<Ldo1::Volt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x4c, pf1550.get_register<Ldo1::Volt>().kRegisterAddress);
  }

  static void test_Ldo1Ctrl_address() {
    PF1550<Ldo1::Ctrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x4d, pf1550.get_register<Ldo1::Ctrl>().kRegisterAddress);
  }

  static void test_Ldo2Volt_address() {
    PF1550<Ldo2::Volt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x4f, pf1550.get_register<Ldo2::Volt>().kRegisterAddress);
  }

  static void test_Ldo2Ctrl_address() {
    PF1550<Ldo2::Ctrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x50, pf1550.get_register<Ldo2::Ctrl>().kRegisterAddress);
  }

  static void test_Ldo3Volt_address() {
    PF1550<Ldo3::Volt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x52, pf1550.get_register<Ldo3::Volt>().kRegisterAddress);
  }

  static void test_Ldo3Ctrl_address() {
    PF1550<Ldo3::Ctrl> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x53, pf1550.get_register<Ldo3::Ctrl>().kRegisterAddress);
  }

  static void test_Pwrctrl0_address() {
    PF1550<Pwrctrl0> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x58, pf1550.get_register<Pwrctrl0>().kRegisterAddress);
  }

  static void test_Pwrctrl1_address() {
    PF1550<Pwrctrl1> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x59, pf1550.get_register<Pwrctrl1>().kRegisterAddress);
  }

  static void test_Pwrctrl2_address() {
    PF1550<Pwrctrl2> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x5a, pf1550.get_register<Pwrctrl2>().kRegisterAddress);
  }

  static void test_Pwrctrl3_address() {
    PF1550<Pwrctrl3> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x5b, pf1550.get_register<Pwrctrl3>().kRegisterAddress);
  }

  static void test_Sw1PwrDnSeq_address() {
    PF1550<Sw1::PwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x5f,
                      pf1550.get_register<Sw1::PwrDnSeq>().kRegisterAddress);
  }

  static void test_Sw2PwrDnSeq_address() {
    PF1550<Sw2::PwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x60,
                      pf1550.get_register<Sw2::PwrDnSeq>().kRegisterAddress);
  }

  static void test_Sw3PwrDnSeq_address() {
    PF1550<Sw3::PwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x61,
                      pf1550.get_register<Sw3::PwrDnSeq>().kRegisterAddress);
  }

  static void test_Ldo1PwrDnSeq_address() {
    PF1550<Ldo1::PwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x62,
                      pf1550.get_register<Ldo1::PwrDnSeq>().kRegisterAddress);
  }

  static void test_Ldo2PwrDnSeq_address() {
    PF1550<Ldo2::PwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x63,
                      pf1550.get_register<Ldo2::PwrDnSeq>().kRegisterAddress);
  }

  static void test_Ldo3PwrDnSeq_address() {
    PF1550<Ldo3::PwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x64,
                      pf1550.get_register<Ldo3::PwrDnSeq>().kRegisterAddress);
  }
  static void test_VrefddrPwrDnSeq_address() {
    PF1550<VrefddrPwrDnSeq> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x65,
                      pf1550.get_register<VrefddrPwrDnSeq>().kRegisterAddress);
  }

  static void test_StateInfo_address() {
    PF1550<StateInfo> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x67, pf1550.get_register<StateInfo>().kRegisterAddress);
  }

  static void test_I2cAddr_address() {
    PF1550<I2cAddr> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x68, pf1550.get_register<I2cAddr>().kRegisterAddress);
  }

  static void test_Rc16mhz_address() {
    PF1550<Rc16mhz> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x6b, pf1550.get_register<Rc16mhz>().kRegisterAddress);
  }

  static void test_ChgInt_address() {
    PF1550<ChgInt> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x80, pf1550.get_register<ChgInt>().kRegisterAddress);
  }

  static void test_ChgIntMask_address() {
    PF1550<ChgIntMask> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x82, pf1550.get_register<ChgIntMask>().kRegisterAddress);
  }

  static void test_ChgIntOk_address() {
    PF1550<ChgIntOk> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x84, pf1550.get_register<ChgIntOk>().kRegisterAddress);
  }

  static void test_VbusSns_address() {
    PF1550<VbusSns> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x86, pf1550.get_register<VbusSns>().kRegisterAddress);
  }

  static void test_ChgSns_address() {
    PF1550<ChgSns> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x87, pf1550.get_register<ChgSns>().kRegisterAddress);
  }

  static void test_BattSns_address() {
    PF1550<BattSns> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x88, pf1550.get_register<BattSns>().kRegisterAddress);
  }

  static void test_ChgOper_address() {
    PF1550<ChgOper> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x89, pf1550.get_register<ChgOper>().kRegisterAddress);
  }

  static void test_ChgTmr_address() {
    PF1550<ChgTmr> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x8a, pf1550.get_register<ChgTmr>().kRegisterAddress);
  }

  static void test_ChgEocCnfg_address() {
    PF1550<ChgEocCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x8d, pf1550.get_register<ChgEocCnfg>().kRegisterAddress);
  }

  static void test_ChgCurrCnfg_address() {
    PF1550<ChgCurrCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x8e,
                      pf1550.get_register<ChgCurrCnfg>().kRegisterAddress);
  }

  static void test_BattReg_address() {
    PF1550<BattReg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x8f, pf1550.get_register<BattReg>().kRegisterAddress);
  }

  static void test_BatfetCnfg_address() {
    PF1550<BatfetCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x91, pf1550.get_register<BatfetCnfg>().kRegisterAddress);
  }

  static void test_ThmRegCnfg_address() {
    PF1550<ThmRegCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x92, pf1550.get_register<ThmRegCnfg>().kRegisterAddress);
  }

  static void test_VbusInLimCnfg_address() {
    PF1550<VbusInLimCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x94,
                      pf1550.get_register<VbusInLimCnfg>().kRegisterAddress);
  }

  static void test_VbusLinDpm_address() {
    PF1550<VbusLinDpm> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x95, pf1550.get_register<VbusLinDpm>().kRegisterAddress);
  }

  static void test_UsbPhyLdoCnfg_address() {
    PF1550<UsbPhyLdoCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x96,
                      pf1550.get_register<UsbPhyLdoCnfg>().kRegisterAddress);
  }

  static void test_DbncDelayTime_address() {
    PF1550<DbncDelayTime> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x98,
                      pf1550.get_register<DbncDelayTime>().kRegisterAddress);
  }

  static void test_ChgIntCnfg_address() {
    PF1550<ChgIntCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x99, pf1550.get_register<ChgIntCnfg>().kRegisterAddress);
  }

  static void test_ThmAdjSetting_address() {
    PF1550<ThmAdjSetting> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x9a,
                      pf1550.get_register<ThmAdjSetting>().kRegisterAddress);
  }

  static void test_Vbus2SysCnfg_address() {
    PF1550<Vbus2SysCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x9b,
                      pf1550.get_register<Vbus2SysCnfg>().kRegisterAddress);
  }

  static void test_LedPwm_address() {
    PF1550<LedPwm> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x9c, pf1550.get_register<LedPwm>().kRegisterAddress);
  }

  static void test_FaultBatfetCnfg_address() {
    PF1550<FaultBatfetCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x9d,
                      pf1550.get_register<FaultBatfetCnfg>().kRegisterAddress);
  }

  static void test_LedCnfg_address() {
    PF1550<LedCnfg> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x9e, pf1550.get_register<LedCnfg>().kRegisterAddress);
  }

  static void test_ReadRegister() {
    uint8_t device_address = 0x08;
    When(OverloadedMethod(ArduinoFake(Wire), begin, void(void))).AlwaysReturn();
    When(OverloadedMethod(ArduinoFake(Wire), beginTransmission, void(uint8_t)))
        .AlwaysReturn();
    When(OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t)))
        .Return(true);
    When(OverloadedMethod(ArduinoFake(Wire), endTransmission, uint8_t(bool)))
        .Return(0);
    When(OverloadedMethod(ArduinoFake(Wire), requestFrom,
                          uint8_t(uint8_t, uint8_t)))
        .Return(0);
    When(OverloadedMethod(ArduinoFake(Wire), available, int(void))).Return(1);
    When(OverloadedMethod(ArduinoFake(Wire), read, int(void))).Return(1);

    PF1550<DeviceId, I2cAddr> pf1550(device_address);
    pf1550.Initialize();
    pf1550.get_register<DeviceId>().ReadRegister();

    Verify(OverloadedMethod(ArduinoFake(Wire), begin, void(void))).Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), beginTransmission, void(uint8_t))
               .Using(device_address))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t))
               .Using(pf1550.get_register<DeviceId>().kRegisterAddress))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), endTransmission, uint8_t(bool))
               .Using(false))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), requestFrom,
                            uint8_t(uint8_t, uint8_t))
               .Using(device_address, 1))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), available, int(void)))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), read, int(void))).Exactly(1);
  }

  static void test_WriteRegister() {
    uint8_t device_address = 0x08;
    uint8_t data = 0x02;
    When(OverloadedMethod(ArduinoFake(Wire), begin, void(void))).AlwaysReturn();
    When(OverloadedMethod(ArduinoFake(Wire), beginTransmission, void(uint8_t)))
        .AlwaysReturn();
    When(OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t)))
        .AlwaysReturn(true);
    When(OverloadedMethod(ArduinoFake(Wire), endTransmission, uint8_t(void)))
        .AlwaysReturn(0);

    PF1550<Pwrctrl3> pf1550(device_address);
    pf1550.Initialize();
    pf1550.get_register<Pwrctrl3>().WriteRegister(data);

    Verify(OverloadedMethod(ArduinoFake(Wire), begin, void(void))).Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), beginTransmission, void(uint8_t))
               .Using(device_address))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t))
               .Using(pf1550.get_register<Pwrctrl3>().kRegisterAddress))
        .Exactly(1);
    Verify(
        OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t)).Using(data))
        .Exactly(1);
    Verify(OverloadedMethod(ArduinoFake(Wire), endTransmission, uint8_t(void)))
        .Exactly(1);
  }
};
} // namespace PMIC

int main(int argc, char **argv) {
  UNITY_BEGIN();
  PMIC::PF1550Test pf1550_test;
  RUN_TEST(pf1550_test.test_DeviceId_address);
  RUN_TEST(pf1550_test.test_OtpFlavor_address);
  RUN_TEST(pf1550_test.test_SiliconRev_address);
  RUN_TEST(pf1550_test.test_IntCategory_address);
  RUN_TEST(pf1550_test.test_SwIntStat0_address);
  RUN_TEST(pf1550_test.test_SwIntMask0_address);
  RUN_TEST(pf1550_test.test_SwIntSense0_address);
  RUN_TEST(pf1550_test.test_SwIntStat1_address);
  RUN_TEST(pf1550_test.test_SwIntMask1_address);
  RUN_TEST(pf1550_test.test_SwIntSense1_address);
  RUN_TEST(pf1550_test.test_SwIntStat2_address);
  RUN_TEST(pf1550_test.test_SwIntMask2_address);
  RUN_TEST(pf1550_test.test_SwIntSense2_address);
  RUN_TEST(pf1550_test.test_LdoIntStat0_address);
  RUN_TEST(pf1550_test.test_LdoIntMask0_address);
  RUN_TEST(pf1550_test.test_LdoIntSense0_address);
  RUN_TEST(pf1550_test.test_TempIntStat0_address);
  RUN_TEST(pf1550_test.test_TempIntMask0_address);
  RUN_TEST(pf1550_test.test_TempIntSense0_address);
  RUN_TEST(pf1550_test.test_OnkeyIntStat0_address);
  RUN_TEST(pf1550_test.test_OnkeyIntMask0_address);
  RUN_TEST(pf1550_test.test_OnkeyIntSense0_address);
  RUN_TEST(pf1550_test.test_MiscIntStat0_address);
  RUN_TEST(pf1550_test.test_MiscIntMask0_address);
  RUN_TEST(pf1550_test.test_MiscIntSense0_address);
  RUN_TEST(pf1550_test.test_CoincellControl_address);
  RUN_TEST(pf1550_test.test_Sw1Volt_address);
  RUN_TEST(pf1550_test.test_Sw1StbyVolt_address);
  RUN_TEST(pf1550_test.test_Sw1SlpVolt_address);
  RUN_TEST(pf1550_test.test_Sw1Ctrl_address);
  RUN_TEST(pf1550_test.test_Sw1Ctrl1_address);
  RUN_TEST(pf1550_test.test_Sw2Volt_address);
  RUN_TEST(pf1550_test.test_Sw2StbyVolt_address);
  RUN_TEST(pf1550_test.test_Sw2SlpVolt_address);
  RUN_TEST(pf1550_test.test_Sw2Ctrl_address);
  RUN_TEST(pf1550_test.test_Sw2Ctrl1_address);
  RUN_TEST(pf1550_test.test_Sw3Volt_address);
  RUN_TEST(pf1550_test.test_Sw3StbyVolt_address);
  RUN_TEST(pf1550_test.test_Sw3SlpVolt_address);
  RUN_TEST(pf1550_test.test_Sw3Ctrl_address);
  RUN_TEST(pf1550_test.test_Sw3Ctrl1_address);
  RUN_TEST(pf1550_test.test_VsnvsCtrl_address);
  RUN_TEST(pf1550_test.test_VrefddrCtrl_address);
  RUN_TEST(pf1550_test.test_Ldo1Volt_address);
  RUN_TEST(pf1550_test.test_Ldo1Ctrl_address);
  RUN_TEST(pf1550_test.test_Ldo2Volt_address);
  RUN_TEST(pf1550_test.test_Ldo2Ctrl_address);
  RUN_TEST(pf1550_test.test_Ldo3Volt_address);
  RUN_TEST(pf1550_test.test_Ldo3Ctrl_address);
  RUN_TEST(pf1550_test.test_Pwrctrl0_address);
  RUN_TEST(pf1550_test.test_Pwrctrl1_address);
  RUN_TEST(pf1550_test.test_Pwrctrl2_address);
  RUN_TEST(pf1550_test.test_Pwrctrl3_address);
  RUN_TEST(pf1550_test.test_Sw1PwrDnSeq_address);
  RUN_TEST(pf1550_test.test_Sw2PwrDnSeq_address);
  RUN_TEST(pf1550_test.test_Sw3PwrDnSeq_address);
  RUN_TEST(pf1550_test.test_Ldo1PwrDnSeq_address);
  RUN_TEST(pf1550_test.test_Ldo2PwrDnSeq_address);
  RUN_TEST(pf1550_test.test_Ldo3PwrDnSeq_address);
  RUN_TEST(pf1550_test.test_VrefddrPwrDnSeq_address);
  RUN_TEST(pf1550_test.test_StateInfo_address);
  RUN_TEST(pf1550_test.test_I2cAddr_address);
  RUN_TEST(pf1550_test.test_Rc16mhz_address);
  RUN_TEST(pf1550_test.test_ChgInt_address);
  RUN_TEST(pf1550_test.test_ChgIntMask_address);
  RUN_TEST(pf1550_test.test_ChgIntOk_address);
  RUN_TEST(pf1550_test.test_VbusSns_address);
  RUN_TEST(pf1550_test.test_ChgSns_address);
  RUN_TEST(pf1550_test.test_BattSns_address);
  RUN_TEST(pf1550_test.test_ChgOper_address);
  RUN_TEST(pf1550_test.test_ChgTmr_address);
  RUN_TEST(pf1550_test.test_ChgEocCnfg_address);
  RUN_TEST(pf1550_test.test_ChgCurrCnfg_address);
  RUN_TEST(pf1550_test.test_BattReg_address);
  RUN_TEST(pf1550_test.test_BatfetCnfg_address);
  RUN_TEST(pf1550_test.test_ThmRegCnfg_address);
  RUN_TEST(pf1550_test.test_VbusInLimCnfg_address);
  RUN_TEST(pf1550_test.test_VbusLinDpm_address);
  RUN_TEST(pf1550_test.test_UsbPhyLdoCnfg_address);
  RUN_TEST(pf1550_test.test_DbncDelayTime_address);
  RUN_TEST(pf1550_test.test_ChgIntCnfg_address);
  RUN_TEST(pf1550_test.test_ThmAdjSetting_address);
  RUN_TEST(pf1550_test.test_Vbus2SysCnfg_address);
  RUN_TEST(pf1550_test.test_LedPwm_address);
  RUN_TEST(pf1550_test.test_FaultBatfetCnfg_address);
  RUN_TEST(pf1550_test.test_LedCnfg_address);
  RUN_TEST(pf1550_test.test_ReadRegister);
  RUN_TEST(pf1550_test.test_WriteRegister);
  UNITY_END();
}
#endif
