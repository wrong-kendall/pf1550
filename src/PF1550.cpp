#include "PF1550.h"
using namespace PMIC;
inline uint8_t I2CRegister::ReadRegister(uint8_t device_address,
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
inline bool I2CRegister::WriteRegister(uint8_t device_address,
                                       uint8_t register_address, uint8_t data) {
  Wire.beginTransmission(kDeviceAddress);
  Wire.write(kRegisterAddress);
  Wire.write(data);
  Wire.endTransmission();
  return true;
}
uint8_t I2CRegister::ReadRegister() {
  return I2CRegister::ReadRegister(kDeviceAddress, kRegisterAddress);
}

bool I2CRegister::WriteRegister(uint8_t data) {
  return I2CRegister::WriteRegister(kDeviceAddress, kRegisterAddress, data);
}

bool OnkeyIntStat0::AnyOnkeyActive() {
  auto register_data = ReadRegister();
  // If any bit is set, return true;
  return register_data > 0;
}
void OnkeyIntStat0::ClearAllOnkey() { WriteRegister(0x0); }
void OnkeyIntStat0::ClearOnkeyPushI() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kOnkeyPushIMask.kMask & kOnkeyPushIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::OnkeyPushIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkeyPushIMask.kMask) == kOnkeyPushIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey1SIActive() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey1SIMask.kMask & kOnkey1SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey1SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey1SIMask.kMask) == kOnkey1SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey2SIActive() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey2SIMask.kMask & kOnkey2SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey2SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey2SIMask.kMask) == kOnkey2SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey3SI() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey3SIMask.kMask & kOnkey3SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey3SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey3SIMask.kMask) == kOnkey3SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey4SIActive() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey4SIMask.kMask & kOnkey4SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey4SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey4SIMask.kMask) == kOnkey4SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey8SI() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey8SIMask.kMask & kOnkey8SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey8SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey8SIMask.kMask) == kOnkey4SIMask.ACTIVE;
}

void OnkeyIntMask0::OnkeyPushMEnable() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kOnkeyPushMMask.kMask & kOnkeyPushMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::OnkeyPushMRemove() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kOnkeyPushMMask.kMask & kOnkeyPushMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey1SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey1SMMask.kMask & kOnkey1SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey1SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey1SMMask.kMask & kOnkey1SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey2SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey2SMMask.kMask & kOnkey2SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey2SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey2SMMask.kMask & kOnkey2SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey3SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey3SMMask.kMask & kOnkey3SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey3SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey3SMMask.kMask & kOnkey3SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey4SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey4SMMask.kMask & kOnkey4SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey4SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey4SMMask.kMask & kOnkey4SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey8SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey8SMMask.kMask & kOnkey8SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey8SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey8SMMask.kMask & kOnkey8SMMask.REMOVED));
  WriteRegister(data);
}
void CoincellControl::VCoin(uint8_t voltage) { WriteRegister(voltage); }
void CoincellControl::ChEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kChEnMask.kMask & kChEnMask.ENABLED));
  WriteRegister(data);
}
void CoincellControl::ChDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kChEnMask.kMask & kChEnMask.DISABLED));
  WriteRegister(data);
}

void Pwrctrl3::GotoShip() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kGotoShipMask.kMask & kGotoShipMask.GOTO_SHIP_EN));
  WriteRegister(data);
}

void Pwrctrl3::CoreOff() {
  auto register_data = ReadRegister();
  auto data = (register_data |
               (kGotoCoreOffMask.kMask & kGotoCoreOffMask.GOTO_CORE_OFF_EN));
  WriteRegister(data);
}

void LDOy::Ctrl::Enable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kEnableMask.kMask & kEnableMask.ENABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::Disable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kEnableMask.kMask & kEnableMask.DISABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::StbyEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kStbyMask.kMask & kStbyMask.ENABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::StbyDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kStbyMask.kMask & kStbyMask.DISABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::OmodeEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.ENABLED));
  WriteRegister(data);
}

void LDOy::Ctrl::OmodeDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.DISABLED));
  WriteRegister(data);
}

void LDOy::Ctrl::ForceLPwr() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kLPwrMask.kMask & kLPwrMask.IN_SLP_AND_STBY));
  WriteRegister(data);
}

void LDOy::Ctrl::DisableLPwr() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kLPwrMask.kMask & kLPwrMask.NOT_IN_SLP_AND_STBY));
  WriteRegister(data);
}
void LDOy::Ctrl::LdoMode() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kLsMask.kMask & kLsMask.LDO_MODE));
  WriteRegister(data);
}

void LDOy::Ctrl::SwMode() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kLsMask.kMask & kLsMask.SWITCH_MODE));
  WriteRegister(data);
}

void SWx::Ctrl::Enable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kEnableMask.kMask & kEnableMask.ENABLED));
  WriteRegister(data);
}
void SWx::Ctrl::Disable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kEnableMask.kMask & kEnableMask.DISABLED));
  WriteRegister(data);
}
void SWx::Ctrl::StbyEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kStbyMask.kMask & kStbyMask.ENABLED));
  WriteRegister(data);
}
void SWx::Ctrl::StbyDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kStbyMask.kMask & kStbyMask.DISABLED));
  WriteRegister(data);
}
void SWx::Ctrl::OmodeEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.ENABLED));
  WriteRegister(data);
}
void SWx::Ctrl::OmodeDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.DISABLED));
  WriteRegister(data);
}
void SWx::Ctrl::LPwrEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kLPwrMask.kMask & kLPwrMask.ENABLED));
  WriteRegister(data);
}
void SWx::Ctrl::LPwrDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kLPwrMask.kMask & kLPwrMask.DISABLED));
  WriteRegister(data);
}
void SWx::Ctrl::DvsSpeed2us() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kDvsSpeedMask.kMask & kDvsSpeedMask._12_5MV_DIV_2US));
  WriteRegister(data);
}
void SWx::Ctrl::DvsSpeed4us() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kDvsSpeedMask.kMask & kDvsSpeedMask._12_5MV_DIV_4US));
  WriteRegister(data);
}
void SWx::Ctrl::FPwmInDvsForce() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kFPwmInDvsMask.kMask & kFPwmInDvsMask.FORCE));
  WriteRegister(data);
}
void SWx::Ctrl::FPwmInDvsNoForce() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kFPwmInDvsMask.kMask & kFPwmInDvsMask.NO_FORCE));
  WriteRegister(data);
}
void SWx::Ctrl::FPwmEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kFPwmMask.kMask & kFPwmMask.FPWM_ON));
  WriteRegister(data);
}
void SWx::Ctrl::FPwmDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kFPwmMask.kMask & kFPwmMask.NO_FPWM));
  WriteRegister(data);
}
void SWx::Ctrl::RDisEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kRDisMask.kMask & kRDisMask.ENABLED));
  WriteRegister(data);
}
void SWx::Ctrl::RDisDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kRDisMask.kMask & kRDisMask.DISABLED));
  WriteRegister(data);
}