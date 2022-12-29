#pragma once
#include "I2CRegister.h"
#include "LDOy.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
namespace Ldo3 {
struct Volt : public LDOy::Volt {
  Volt(uint8_t device_address) : LDOy::Volt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x52;
};
struct Ctrl : public LDOy::Ctrl {
  Ctrl(uint8_t device_address) : LDOy::Ctrl(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x53;
};
struct PwrDnSeq : public LDOy::PwrDnSeq {
  PwrDnSeq(uint8_t device_address)
      : LDOy::PwrDnSeq(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x64;
};
} // namespace Ldo3

} // namespace PMIC