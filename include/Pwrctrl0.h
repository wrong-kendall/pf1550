#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct Pwrctrl0 : public I2CRegister {
  struct StandbyDlyMask : public Mask {
    static inline const uint8_t NO_DELAY = BITS_NONE;
    // TODO(kendall): WTF? these don't make sense
    static inline const uint8_t _1_32KHZ_DELAY = BITS_0;
    static inline const uint8_t _2_32KHZ_DELAY = BITS_1;
    static inline const uint8_t _3_32KHZ_DELAY = BITS_1_0;
    StandbyDlyMask(uint8_t mask) : Mask(mask) {}
  };
  struct StandbyInvMask : public Mask {
    static inline const uint8_t ACTIVE_HIGH = BITS_NONE;
    static inline const uint8_t ACTIVE_LOW = BITS_2;
    StandbyInvMask(uint8_t mask) : Mask(mask) {}
  };
  struct PoRDlyMask : public Mask {
    static inline const uint8_t RESETBMCU_DELAY_2MS = BITS_NONE;
    static inline const uint8_t RESETBMCU_DELAY_4MS = BITS_3;
    static inline const uint8_t RESETBMCU_DELAY_8MS = BITS_4_3;
    static inline const uint8_t RESETBMCU_DELAY_16MS = BITS_5;
    static inline const uint8_t RESETBMCU_DELAY_128MS = BITS_5_3;
    static inline const uint8_t RESETBMCU_DELAY_256MS = BITS_5_4;
    static inline const uint8_t RESETBMCU_DELAY_1024MS = BITS_5_4_3;
    PoRDlyMask(uint8_t mask) : Mask(mask) {}
  };
  struct TgResetMask : public Mask {
    static inline const uint8_t _4S = BITS_NONE;
    static inline const uint8_t _8S = BITS_6;
    static inline const uint8_t _12S = BITS_7;
    static inline const uint8_t _16S = BITS_7_6;
    TgResetMask(uint8_t mask) : Mask(mask) {}
  };

  static inline const StandbyDlyMask kStandbyDlyMask{BITS_1_0};
  static inline const StandbyInvMask kStandbyInvMask{BITS_2};
  static inline const PoRDlyMask kPoRDlyMask{BITS_5_4_3};
  static inline const TgResetMask kTgResetMask{BITS_7_6};

  Pwrctrl0(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x58;
};
} // namespace PMIC