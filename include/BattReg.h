#pragma once
#include "I2CRegister.h"
#include "Mask.h"
#include "common_bitmasks.h"

namespace PMIC {
struct BattReg : public I2CRegister {
  struct ChgCvMask : public Mask {
    static inline const uint8_t _3_50V = BITS_NONE;
    static inline const uint8_t _3_50V_1 = BITS_0;
    static inline const uint8_t _3_50V_2 = BITS_1;
    static inline const uint8_t _3_50V_3 = BITS_1_0;
    static inline const uint8_t _3_50V_4 = BITS_2;
    static inline const uint8_t _3_50V_5 = BITS_2_0;
    static inline const uint8_t _3_50V_6 = BITS_2_1;
    static inline const uint8_t _3_50V_7 = BITS_2_1_0;
    static inline const uint8_t _3_50V_8 = BITS_3;
    static inline const uint8_t _3_52V = BITS_3_0;
    static inline const uint8_t _3_54V = BITS_3_1;
    static inline const uint8_t _3_56V = BITS_3_1_0;
    static inline const uint8_t _3_58V = BITS_3_2;
    static inline const uint8_t _3_60V = BITS_3_2_0;
    static inline const uint8_t _3_62V = BITS_3_2_1;
    static inline const uint8_t _3_64V = BITS_3_2_1_0;
    static inline const uint8_t _3_66V = BITS_4;
    static inline const uint8_t _3_68V = BITS_4_0;
    static inline const uint8_t _3_70V = BITS_4_1;
    static inline const uint8_t _3_72V = BITS_4_1_0;
    static inline const uint8_t _3_74V = BITS_4_2;
    static inline const uint8_t _3_76V = BITS_4_2_0;
    static inline const uint8_t _3_78V = BITS_4_2_1;
    static inline const uint8_t _3_80V = BITS_4_2_1_0;
    static inline const uint8_t _3_82V = BITS_4_3;
    static inline const uint8_t _3_84V = BITS_4_3_0;
    static inline const uint8_t _3_86V = BITS_4_3_1;
    static inline const uint8_t _3_88V = BITS_4_3_1_0;
    static inline const uint8_t _3_90V = BITS_4_3_2;
    static inline const uint8_t _3_92V = BITS_4_3_2_0;
    static inline const uint8_t _3_94V = BITS_4_3_2_1;
    static inline const uint8_t _3_96V = BITS_4_3_2_1_0;
    static inline const uint8_t _3_98V = BITS_5;
    static inline const uint8_t _4_00V = BITS_5_0;
    static inline const uint8_t _4_02V = BITS_5_1;
    static inline const uint8_t _4_04V = BITS_5_1_0;
    static inline const uint8_t _4_06V = BITS_5_2;
    static inline const uint8_t _4_08V = BITS_5_2_0;
    static inline const uint8_t _4_10V = BITS_5_2_1;
    static inline const uint8_t _4_12V = BITS_5_2_1_0;
    static inline const uint8_t _4_14V = BITS_5_3;
    static inline const uint8_t _4_16V = BITS_5_3_0;
    static inline const uint8_t _4_18V = BITS_5_3_1;
    static inline const uint8_t _4_20V = BITS_5_3_1_0;
    static inline const uint8_t _4_22V = BITS_5_3_2;
    static inline const uint8_t _4_24V = BITS_5_3_2_0;
    static inline const uint8_t _4_26V = BITS_5_3_2_1;
    static inline const uint8_t _4_28V = BITS_5_3_2_1_0;
    static inline const uint8_t _4_30V = BITS_5_4;
    static inline const uint8_t _4_32V = BITS_5_4_0;
    static inline const uint8_t _4_34V = BITS_5_4_1;
    static inline const uint8_t _4_36V = BITS_5_4_1_0;
    static inline const uint8_t _4_38V = BITS_5_4_2;
    static inline const uint8_t _4_40V = BITS_5_4_2_0;
    static inline const uint8_t _4_42V = BITS_5_4_2_1;
    static inline const uint8_t _4_44V = BITS_5_4_2_1_0;
    static inline const uint8_t _4_44V_1 = BITS_5_4_3;
    static inline const uint8_t _4_44V_2 = BITS_5_4_3_0;
    static inline const uint8_t _4_44V_3 = BITS_5_4_3_1;
    static inline const uint8_t _4_44V_4 = BITS_5_4_3_1_0;
    static inline const uint8_t _4_44V_5 = BITS_5_4_3_2;
    static inline const uint8_t _4_44V_6 = BITS_5_4_3_2_0;
    static inline const uint8_t _4_44V_7 = BITS_5_4_3_2_1;
    static inline const uint8_t _4_44V_8 = BITS_5_4_3_2_1_0;
    ChgCvMask(uint8_t mask) : Mask(mask) {}
  };
  struct VsysMinMask : public Mask {
    static inline const uint8_t _3_5V = BITS_NONE;
    static inline const uint8_t _3_7V = BITS_6;
    static inline const uint8_t _4_3V = BITS_7;
    VsysMinMask(uint8_t mask) : Mask(mask) {}
  };
  static inline const ChgCvMask kChgCvMask{BITS_5_4_3_2_1_0};
  static inline const VsysMinMask kVsysMinMask{BITS_7_6};

  BattReg(uint8_t device_address) : I2CRegister(device_address, kRegister) {}

private:
  static inline const uint8_t kRegister = 0x0F + SPECIFIC_REGISTER_OFFSET;
};
} // namespace PMIC