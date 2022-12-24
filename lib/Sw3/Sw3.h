#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "SWx.h"
#include "common_bitmasks.h"

namespace PMIC {
namespace Sw3 {
struct Volt : public SWx::Volt {
  Volt(uint8_t device_address) : SWx::Volt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x3E;
};
struct StbyVolt : public SWx::StbyVolt {
  StbyVolt(uint8_t device_address) : SWx::StbyVolt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x3F;
};
struct SlpVolt : public SWx::SlpVolt {
  SlpVolt(uint8_t device_address) : SWx::SlpVolt(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x40;
};
struct Ctrl : public SWx::Ctrl {
  Ctrl(uint8_t device_address) : SWx::Ctrl(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x41;
};
struct Ctrl1 : public SWx::Ctrl1 {
  Ctrl1(uint8_t device_address) : SWx::Ctrl1(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x42;
};
struct PwrDnSeq : public SWx::PwrDnSeq {
  PwrDnSeq(uint8_t device_address) : SWx::PwrDnSeq(device_address, kRegister){};

private:
  static inline const uint8_t kRegister = 0x61;
};
} // namespace Sw3
} // namespace PMIC