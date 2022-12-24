#include "SWx.h"
using namespace PMIC;
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