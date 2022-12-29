#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct Rc16mhz : public I2CRegister {
  struct Req16MhzMask : public Mask {
    static inline const uint8_t ALWAYS_ON = BITS_1;
    static inline const uint8_t STATEMACHINE_EN = BITS_NONE;
    Req16MhzMask(uint8_t mask) : Mask(mask) {}
  };
  struct ReqAcoreOnMask : public Mask {
    static inline const uint8_t ALWAYS_ON = BITS_1;
    static inline const uint8_t STATEMACHINE_EN = BITS_NONE;
    ReqAcoreOnMask(uint8_t mask) : Mask(mask) {}
  };
  struct ReqAcoreHiPwrMask : public Mask {
    static inline const uint8_t LOW_POWER_STATEMACHINE_CONTROLLED = BITS_NONE;
    static inline const uint8_t LOW_POWER_NEVER = BITS_2;
    ReqAcoreHiPwrMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const Req16MhzMask kReq16MhzMask{BITS_0};
  static inline const ReqAcoreOnMask kReqAcoreOnMask{BITS_1};
  static inline const ReqAcoreHiPwrMask kReqAcoreHiPwrMask{BITS_2};
  Rc16mhz(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x6B;
};
} // namespace PMIC