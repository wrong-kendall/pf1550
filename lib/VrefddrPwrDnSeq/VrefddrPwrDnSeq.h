#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct VrefddrPwrDnSeq : public I2CRegister {
  struct VrefddrPwrDnSeqMask : public Mask {
    // TODO(kendall): Add specific masks/values.
    VrefddrPwrDnSeqMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const VrefddrPwrDnSeqMask kVrefddrPwrDnSeqMask{BITS_2_1_0};
  VrefddrPwrDnSeq(uint8_t device_address)
      : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x65;
};

} // namespace PMIC