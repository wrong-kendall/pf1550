#pragma once
#include <Arduino.h>
namespace PMIC {
class I2CRegister {
public:
  const uint8_t kDeviceAddress;
  const uint8_t kRegisterAddress;

  inline uint8_t ReadRegister(uint8_t device_address, uint8_t register_address);
  inline bool WriteRegister(uint8_t device_address, uint8_t register_address,
                            uint8_t data);
  uint8_t ReadRegister();
  bool WriteRegister(uint8_t data);

public:
  I2CRegister(uint8_t device_address, uint8_t register_address)
      : kDeviceAddress(device_address), kRegisterAddress(register_address) {}
};
} // namespace PMIC
