#pragma once
#include <inttypes.h>
namespace PMIC {
struct Mask {
  const uint8_t kMask;
  Mask(uint8_t mask) : kMask(mask) {}
};
} // namespace PMIC