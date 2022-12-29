#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct OnkeyIntStat0 : public I2CRegister {
  struct OnkeyPushIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_0;
    OnkeyPushIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_1;
    Onkey1SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_2;
    Onkey2SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_3;
    Onkey3SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_4;
    Onkey4SIMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SIMask : public Mask {
    static inline const uint8_t CLEARED = BITS_NONE;
    static inline const uint8_t ACTIVE = BITS_5;
    Onkey8SIMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const OnkeyPushIMask kOnkeyPushIMask{BITS_0};
  static inline const Onkey1SIMask kOnkey1SIMask{BITS_1};
  static inline const Onkey2SIMask kOnkey2SIMask{BITS_2};
  static inline const Onkey3SIMask kOnkey3SIMask{BITS_3};
  static inline const Onkey4SIMask kOnkey4SIMask{BITS_4};
  static inline const Onkey8SIMask kOnkey8SIMask{BITS_5};
  OnkeyIntStat0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

  bool AnyOnkeyActive();
  void ClearAllOnkey();
  void ClearOnkeyPushI();
  bool OnkeyPushIActive();
  void ClearOnkey1SIActive();
  bool Onkey1SIActive();
  void ClearOnkey2SIActive();
  bool Onkey2SIActive();
  void ClearOnkey3SI();
  bool Onkey3SIActive();
  void ClearOnkey4SIActive();
  bool Onkey4SIActive();
  void ClearOnkey8SI();
  bool Onkey8SIActive();

private:
  static inline const uint8_t kRegister = 0x24;
};
} // namespace PMIC