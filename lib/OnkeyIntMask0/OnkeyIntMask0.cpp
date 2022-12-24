#include "OnkeyIntMask0.h"
using namespace PMIC;
void OnkeyIntMask0::OnkeyPushMEnable() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kOnkeyPushMMask.kMask & kOnkeyPushMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::OnkeyPushMRemove() {
  auto register_data = ReadRegister();
  auto data =
      (register_data | (kOnkeyPushMMask.kMask & kOnkeyPushMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey1SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey1SMMask.kMask & kOnkey1SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey1SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey1SMMask.kMask & kOnkey1SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey2SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey2SMMask.kMask & kOnkey2SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey2SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey2SMMask.kMask & kOnkey2SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey3SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey3SMMask.kMask & kOnkey3SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey3SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey3SMMask.kMask & kOnkey3SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey4SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey4SMMask.kMask & kOnkey4SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey4SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey4SMMask.kMask & kOnkey4SMMask.REMOVED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey8SMEnable() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey8SMMask.kMask & kOnkey8SMMask.ENABLED));
  WriteRegister(data);
}
void OnkeyIntMask0::Onkey8SMRemove() {
  auto register_data = ReadRegister();
  auto data = (register_data | (kOnkey8SMMask.kMask & kOnkey8SMMask.REMOVED));
  WriteRegister(data);
}