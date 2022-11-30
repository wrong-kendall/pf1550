#ifdef UNIT_TEST
#include "PF1550.h"
#include <Arduino.h>
#include <unity.h>
using namespace fakeit;

void setUp(void) {}

struct PF1550Test {
  static void test_some_old_bullshit() {
    PF1550<DeviceId, OTPFlavor> pf1550(0x08);
    TEST_ASSERT_EQUAL(0x00, pf1550.get_register<DeviceId>().kRegisterAddress);
    TEST_ASSERT_EQUAL(0x01, pf1550.get_register<OTPFlavor>().kRegisterAddress);
  }
};

int main(int argc, char **argv) {
  UNITY_BEGIN();
  PF1550Test pf1550_test;
  RUN_TEST(pf1550_test.test_some_old_bullshit);
  UNITY_END();
}
#endif
