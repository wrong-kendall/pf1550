#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "SWx.h"
#include "common_bitmasks.h"

namespace PMIC {
namespace Sw2 {
struct Volt : public SWx::Volt {
  Volt(uint8_t device_address) : SWx::Volt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x38;
};
struct StbyVolt : public SWx::StbyVolt {
  StbyVolt(uint8_t device_address) : SWx::StbyVolt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x39;
};
struct SlpVolt : public SWx::SlpVolt {
  SlpVolt(uint8_t device_address) : SWx::SlpVolt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x3A;
};
struct Ctrl : public SWx::Ctrl {
  Ctrl(uint8_t device_address) : SWx::Ctrl(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x3B;
};
struct Ctrl1 : public SWx::Ctrl1 {
  Ctrl1(uint8_t device_address) : SWx::Ctrl1(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x3C;
};
struct PwrDnSeq : public SWx::PwrDnSeq {
  PwrDnSeq(uint8_t device_address) : SWx::PwrDnSeq(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x60;
};
} // namespace Sw2
} // namespace PMIC