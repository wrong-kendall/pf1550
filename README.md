# pf1550

# Example
```
#include "DeviceId.h"
#include "I2cAddr.h"
#include "Ldo1.h"
#include "Ldo2.h"
#include "Ldo3.h"
#include "PF1550.h"
#include "Pwrctrl3.h"
#include "StateInfo.h"
#include <Arduino.h>
using namespace PMIC;

PF1550<DeviceId, I2cAddr, Ldo1::Ctrl, Ldo2::Ctrl, Ldo3::Ctrl, Ldo1::Volt,
       Ldo2::Volt, Ldo3::Volt, Pwrctrl3, StateInfo>
    pf1550;

void ldo_status(LDOy::Ctrl ctrl, LDOy::Volt volt, int ldo_number) {
  Serial.print("Ldo");
  Serial.print(ldo_number);
  Serial.print("Ctrl: ");
  int ctrl_status = ctrl.ReadRegister();
  Serial.println(ctrl_status, BIN);
  Serial.print("Ldo");
  Serial.print(ldo_number);
  Serial.print("Volt: ");
  int volt_status = volt.ReadRegister();
  Serial.println(volt_status, BIN);
}

void setup() {
  Serial.begin(115200);
  while (!Serial.available())
    ;
  pf1550.Initialize();
  int device_address = pf1550.GetRegister<I2cAddr>().ReadRegister();
  Serial.print("Found PF1550 @ ");
  Serial.println(device_address + 8, BIN);
  Serial.print("StateInfo is currently : ");
  int stateinfo = pf1550.GetRegister<StateInfo>().ReadRegister();
  Serial.println(stateinfo, BIN);
  Serial.print("Pwrctrl3 set to: ");
  int pwrctrl3 = pf1550.GetRegister<Pwrctrl3>().ReadRegister();
  Serial.println(pwrctrl3, BIN);
  Serial.println("Enabling GOTO_CORE_OFF");
  pf1550.GetRegister<Pwrctrl3>().CoreOff();
  Serial.print("Pwrctrl3 set to: ");
  pwrctrl3 = pf1550.GetRegister<Pwrctrl3>().ReadRegister();
  Serial.println(pwrctrl3, BIN);
  ldo_status(pf1550.GetRegister<Ldo1::Ctrl>(), pf1550.GetRegister<Ldo1::Volt>(),
             1);
  ldo_status(pf1550.GetRegister<Ldo2::Ctrl>(), pf1550.GetRegister<Ldo2::Volt>(),
             2);
  ldo_status(pf1550.GetRegister<Ldo3::Ctrl>(), pf1550.GetRegister<Ldo3::Volt>(),
             3);
  Serial.println("Disabling all LDOs");
  pf1550.GetRegister<Ldo1::Ctrl>().Disable();
  pf1550.GetRegister<Ldo2::Ctrl>().Disable();
  pf1550.GetRegister<Ldo3::Ctrl>().Disable();
  ldo_status(pf1550.GetRegister<Ldo1::Ctrl>(), pf1550.GetRegister<Ldo1::Volt>(),
             1);
  ldo_status(pf1550.GetRegister<Ldo2::Ctrl>(), pf1550.GetRegister<Ldo2::Volt>(),
             2);
  ldo_status(pf1550.GetRegister<Ldo3::Ctrl>(), pf1550.GetRegister<Ldo3::Volt>(),
             3);
}

void toggle_ldos() {
  delay(5000);
  Serial.println("Turning on LDO1");
  pf1550.GetRegister<Ldo1::Ctrl>().Enable();
  delay(5000);
  Serial.println("Turning off LDO1");
  pf1550.GetRegister<Ldo1::Ctrl>().Disable();
  delay(5000);
  Serial.println("Turning on LDO2");
  pf1550.GetRegister<Ldo2::Ctrl>().Enable();
  delay(5000);
  Serial.println("Turning off LDO2");
  pf1550.GetRegister<Ldo2::Ctrl>().Disable();
  delay(5000);
  Serial.println("Turning on LDO3");
  pf1550.GetRegister<Ldo3::Ctrl>().Enable();
  delay(5000);
  Serial.println("Turning off LDO2");
  pf1550.GetRegister<Ldo3::Ctrl>().Disable();
}

void loop() {
  toggle_ldos();
}
```
