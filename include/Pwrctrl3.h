#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct Pwrctrl3 : public I2CRegister {
  struct GotoShipMask : public Mask {
    static inline const uint8_t GOTO_SHIP_EN = BITS_0;
    GotoShipMask(uint8_t mask) : Mask(mask) {}
  };
  struct GotoCoreOffMask : public Mask {
    static inline const uint8_t GOTO_CORE_OFF_EN = BITS_1;
    GotoCoreOffMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const GotoShipMask kGotoShipMask{BITS_0};
  static inline const GotoCoreOffMask kGotoCoreOffMask{BITS_1};

  Pwrctrl3(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

  void GotoShip();
  void CoreOff();

private:
  static inline const uint8_t kRegister = 0x5B;
};
} // namespace PMIC