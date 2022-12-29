#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct I2cAddr : public I2CRegister {
  struct AddrMask : public Mask {
    static inline const uint8_t I2C_ADDR_DEFAULT = 0x08;
    static inline const uint8_t X08 = BITS_NONE;
    static inline const uint8_t X09 = BITS_0;
    static inline const uint8_t X0A = BITS_1;
    static inline const uint8_t X0B = BITS_1_0;
    static inline const uint8_t X0C = BITS_2;
    static inline const uint8_t X0D = BITS_2_0;
    static inline const uint8_t X0E = BITS_2_1;
    static inline const uint8_t X0F = BITS_2_1_0;
    AddrMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const AddrMask kAddrMask{BITS_2_1_0};
  I2cAddr(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x68;
};
} // namespace PMIC