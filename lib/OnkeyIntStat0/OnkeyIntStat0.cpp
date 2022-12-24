#include "OnkeyIntStat0.h"
using namespace PMIC;
bool OnkeyIntStat0::AnyOnkeyActive() {
  auto register_data = ReadRegister();
  // If any bit is set, return true;
  return register_data > 0;
}
void OnkeyIntStat0::ClearAllOnkey() { WriteRegister(0x0); }
void OnkeyIntStat0::ClearOnkeyPushI() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kOnkeyPushIMask.kMask & kOnkeyPushIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::OnkeyPushIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkeyPushIMask.kMask) == kOnkeyPushIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey1SIActive() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey1SIMask.kMask & kOnkey1SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey1SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey1SIMask.kMask) == kOnkey1SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey2SIActive() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey2SIMask.kMask & kOnkey2SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey2SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey2SIMask.kMask) == kOnkey2SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey3SI() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey3SIMask.kMask & kOnkey3SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey3SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey3SIMask.kMask) == kOnkey3SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey4SIActive() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey4SIMask.kMask & kOnkey4SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey4SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey4SIMask.kMask) == kOnkey4SIMask.ACTIVE;
}
void OnkeyIntStat0::ClearOnkey8SI() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey8SIMask.kMask & kOnkey8SIMask.CLEARED));
  WriteRegister(data);
}
bool OnkeyIntStat0::Onkey8SIActive() {
  auto register_data = ReadRegister();
  return (register_data & kOnkey8SIMask.kMask) == kOnkey4SIMask.ACTIVE;
}