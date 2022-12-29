#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct OtpFlavor : public I2CRegister {
  struct ModelMask : public Mask {
    static inline const uint8_t A0 = 0x00;
    static inline const uint8_t A1 = 0x01;
    static inline const uint8_t A2 = 0x02;
    static inline const uint8_t A3 = 0x03;
    static inline const uint8_t A4 = 0x04;
    static inline const uint8_t A5 = 0x05;
    static inline const uint8_t A6 = 0x06;
    static inline const uint8_t A7 = 0x07;
    static inline const uint8_t A8 = 0x08;
    static inline const uint8_t A9 = 0x09;
    ModelMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const ModelMask kModelMask{BITS_ALL};
  OtpFlavor(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x01;
};
} // namespace PMIC