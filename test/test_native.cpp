#ifdef UNIT_TEST
#include "PF1550.h"
#include <Arduino.h>
#include <unity.h>
using namespace fakeit;

void setUp(void) {}

void test_some_old_bullshit() {
  DeviceId x(10);
  TEST_ASSERT_EQUAL(0b00000111, x.kDeviceIdMask.kMask);
  TEST_ASSERT_EQUAL(69, x.kRegisterAddress);
}

int main(int argc, char **argv) {
  UNITY_BEGIN();
  RUN_TEST(test_some_old_bullshit);
  UNITY_END();
}
#endif
