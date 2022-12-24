#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct DeviceId : public I2CRegister {
  struct DeviceIdMask : public Mask {
    static inline const uint8_t kPF1550Mask = BITS_2;
    static inline const uint8_t kPF1500Mask = BITS_NONE;
    DeviceIdMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const DeviceIdMask kDeviceIdMask{BITS_2_1_0};
  DeviceId(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

  // TODO(kendall): Add Family

private:
  static inline const uint8_t kRegister = 0x00;
};
} // namespace PMIC