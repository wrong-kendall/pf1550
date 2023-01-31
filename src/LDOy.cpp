#include "LDOy.h"
using namespace PMIC;

// TODO(kendall): Simplify these because I've definitely overcomplicated things.

void LDOy::Ctrl::Enable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kEnableMask.kMask & kEnableMask.ENABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::Disable() {
  auto register_data = ReadRegister();
  auto data = (register_data & (~kEnableMask.kMask | kEnableMask.DISABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::StbyEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kStbyMask.kMask & kStbyMask.ENABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::StbyDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data & (~kStbyMask.kMask | kStbyMask.DISABLED));
  WriteRegister(data);
}
void LDOy::Ctrl::OmodeEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOmodeMask.kMask & kOmodeMask.ENABLED));
  WriteRegister(data);
}

void LDOy::Ctrl::OmodeDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data & (~kOmodeMask.kMask | kOmodeMask.DISABLED));
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
      (register_data & (~kLPwrMask.kMask | kLPwrMask.NOT_IN_SLP_AND_STBY));
  WriteRegister(data);
}
void LDOy::Ctrl::LdoMode() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kLsMask.kMask & kLsMask.LDO_MODE));
  WriteRegister(data);
}

void LDOy::Ctrl::SwMode() {
  auto register_data = ReadRegister();
  auto data = (register_data & (~kLsMask.kMask | kLsMask.SWITCH_MODE));
  WriteRegister(data);
}
