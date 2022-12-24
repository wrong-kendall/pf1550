#include "CoincellControl.h"

using namespace PMIC;

void CoincellControl::VCoin(uint8_t voltage) { WriteRegister(voltage); }
void CoincellControl::ChEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kChEnMask.kMask & kChEnMask.ENABLED));
  WriteRegister(data);
}
void CoincellControl::ChDisable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kChEnMask.kMask & kChEnMask.DISABLED));
  WriteRegister(data);
}
