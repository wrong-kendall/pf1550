#include "ChgIntOk.h"
using namespace PMIC;

bool ChgIntOk::IsCharging() {
  auto register_data = ReadRegister();
  auto chg_ok = register_data & kChgOkMask.kMask;
  return chg_ok == ChgIntOk::ChgOkMask::CHG_OK;
}