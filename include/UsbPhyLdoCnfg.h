#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct UsbPhyLdoCnfg : public I2CRegister {
  struct ActDisPhyMask : public Mask {
    static inline const uint8_t NO_DISCHARGE = BITS_NONE;
    static inline const uint8_t DISCHARGE = BITS_0;
    ActDisPhyMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyMask : public Mask {
    static inline const uint8_t _3_3V = BITS_NONE;
    static inline const uint8_t _4_9V = BITS_1;
    UsbPhyMask(uint8_t mask) : Mask(mask) {}
  };
  struct UsbPhyLdoMask : public Mask {
    static inline const uint8_t DISABLED = BITS_NONE;
    static inline const uint8_t ENABLED = BITS_2;
    UsbPhyLdoMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const ActDisPhyMask kActDisPhyMask{BITS_0};
  static inline const UsbPhyMask kUsbPhyMask{BITS_1};
  static inline const UsbPhyLdoMask kUsbPhyLdoMask{BITS_2};

  UsbPhyLdoCnfg(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x16 + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC