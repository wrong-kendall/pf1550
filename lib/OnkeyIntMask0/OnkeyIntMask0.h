#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct OnkeyIntMask0 : public I2CRegister {
  struct OnkeyPushMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_0;
    OnkeyPushMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey1SMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_1;
    Onkey1SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey2SMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_2;
    Onkey2SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey3SMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_3;
    Onkey3SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey4SMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_4;
    Onkey4SMMask(uint8_t mask) : Mask(mask) {}
  };
  struct Onkey8SMMask : public Mask {
    static inline const uint8_t ENABLED = BITS_NONE;
    static inline const uint8_t REMOVED = BITS_5;
    Onkey8SMMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const OnkeyPushMMask kOnkeyPushMMask{BITS_0};
  static inline const Onkey1SMMask kOnkey1SMMask{BITS_1};
  static inline const Onkey2SMMask kOnkey2SMMask{BITS_2};
  static inline const Onkey3SMMask kOnkey3SMMask{BITS_3};
  static inline const Onkey4SMMask kOnkey4SMMask{BITS_4};
  static inline const Onkey8SMMask kOnkey8SMMask{BITS_5};
  OnkeyIntMask0(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

  void OnkeyPushMEnable();
  void OnkeyPushMRemove();
  void Onkey1SMEnable();
  void Onkey1SMRemove();
  void Onkey2SMEnable();
  void Onkey2SMRemove();
  void Onkey3SMEnable();
  void Onkey3SMRemove();
  void Onkey4SMEnable();
  void Onkey4SMRemove();
  void Onkey8SMEnable();
  void Onkey8SMRemove();

private:
  static inline const uint8_t kRegister = 0x25;
};
} // namespace PMIC