#include "Pwrctrl3.h"
using namespace PMIC;

void Pwrctrl3::GotoShip() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kGotoShipMask.kMask & kGotoShipMask.GOTO_SHIP_EN));
  WriteRegister(data);
}

void Pwrctrl3::CoreOff() {
  auto register_data = ReadRegister();
  auto data = (register_data |
               (kGotoCoreOffMask.kMask & kGotoCoreOffMask.GOTO_CORE_OFF_EN));
  WriteRegister(data);
}