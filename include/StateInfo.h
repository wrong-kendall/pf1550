#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct StateInfo : public I2CRegister {
  struct StateMask : public Mask {
    StateMask(uint8_t mask) : Mask(mask) {}
    static inline const uint8_t WAIT = BITS_NONE;
    static inline const uint8_t RUN = BITS_3_2;
    static inline const uint8_t STANDBY = BITS_3_2_0;
    static inline const uint8_t SLEEP = BITS_3_2_1;
    static inline const uint8_t REG_DISABLE = BITS_5_3_1_0;
  };
  static inline const StateMask kStateMask{BITS_ALL};
  StateInfo(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x67;
};
} // namespace PMIC