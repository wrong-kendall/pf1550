#include "I2CRegister.h"

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
