#pragma once
#include "I2CRegister.h"
#include "I2cAddr.h"
#include "Mask.h"
#include "common_bitmasks.h"
#include <Arduino.h>
#include <Wire.h>
#include <tuple>

namespace PMIC {

constexpr int count_first_falses() { return 0; }
template <typename... B> constexpr int count_first_falses(bool b1, B... b) {
  if (b1)
    return 0;
  else
    return 1 + count_first_falses(b...);
}

template <class... Registers> class PF1550 {
public:
  std::tuple<Registers...> registers_;
  PF1550(uint8_t device_address = I2cAddr::kAddrMask.I2C_ADDR_DEFAULT)
      : registers_(Registers(device_address)...) {}

  template <typename R> decltype(auto) get_register() {
    return std::get<count_first_falses((std::is_same<Registers, R>::value)...)>(
        registers_);
  }

  void Initialize() { Wire.begin(); };
  friend class PF1550Test;
};
} // namespace PMIC