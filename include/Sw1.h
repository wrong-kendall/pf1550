#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "SWx.h"
#include "common_bitmasks.h"

namespace PMIC {
namespace Sw1 {
struct Volt : public SWx::Volt {
  Volt(uint8_t device_address) : SWx::Volt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x32;
};
struct StbyVolt : public SWx::StbyVolt {
  StbyVolt(uint8_t device_address) : SWx::StbyVolt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x33;
};
struct SlpVolt : public SWx::SlpVolt {
  SlpVolt(uint8_t device_address) : SWx::SlpVolt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x34;
};
struct Ctrl : public SWx::Ctrl {
  Ctrl(uint8_t device_address) : SWx::Ctrl(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x35;
};
struct Ctrl1 : public SWx::Ctrl1 {
  Ctrl1(uint8_t device_address) : SWx::Ctrl1(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x36;
  // Misnamed in data sheet as SLP_VOLT
};
struct PwrDnSeq : public SWx::PwrDnSeq {
  PwrDnSeq(uint8_t device_address) : SWx::PwrDnSeq(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x5F;
};
} // namespace Sw1
} // namespace PMIC