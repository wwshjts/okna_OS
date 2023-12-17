#include "intel_8259A.h"
#include "interrupts.h"
#include "utils.h"

void exception_00(context* ctx){panic(ctx);}
void exception_01(context* ctx){panic(ctx);}
void exception_02(context* ctx){panic(ctx);}
void exception_03(context* ctx){panic(ctx);}
void exception_04(context* ctx){panic(ctx);}
void exception_05(context* ctx){panic(ctx);}
void exception_06(context* ctx){panic(ctx);}
void exception_07(context* ctx){panic(ctx);}
void exception_08(context* ctx){panic(ctx);}
void exception_09(context* ctx){panic(ctx);}
void exception_0A(context* ctx){panic(ctx);}
void exception_0B(context* ctx){panic(ctx);}
void exception_0C(context* ctx){panic(ctx);}
void exception_0D(context* ctx){panic(ctx);}
void exception_0E(context* ctx){panic(ctx);}
void exception_0F(context* ctx){panic(ctx);}
void exception_10(context* ctx){panic(ctx);}
void exception_11(context* ctx){panic(ctx);}
void exception_12(context* ctx){panic(ctx);}
void exception_13(context* ctx){panic(ctx);}
void exception_14(context* ctx){panic(ctx);}
void exception_15(context* ctx){panic(ctx);}
void exception_16(context* ctx){panic(ctx);}
void exception_17(context* ctx){panic(ctx);}
void exception_18(context* ctx){panic(ctx);}
void exception_19(context* ctx){panic(ctx);}
void exception_1A(context* ctx){panic(ctx);}
void exception_1B(context* ctx){panic(ctx);}
void exception_1C(context* ctx){panic(ctx);}
void exception_1D(context* ctx){panic(ctx);}
void exception_1E(context* ctx){panic(ctx);}
void exception_1F(context* ctx){panic(ctx);}
void hardware_interrupt_20(context* ctx){
    sti();
    timer_interrupt(ctx);
    eoi(0x20);
}
void hardware_interrupt_21(context* ctx){panic(ctx); eoi(0x21); sti();}
void hardware_interrupt_22(context* ctx){panic(ctx); eoi(0x22); sti();}
void hardware_interrupt_23(context* ctx){panic(ctx); eoi(0x23); sti();}
void hardware_interrupt_24(context* ctx){panic(ctx); eoi(0x24); sti();}
void hardware_interrupt_25(context* ctx){panic(ctx); eoi(0x25); sti();}
void hardware_interrupt_26(context* ctx){panic(ctx); eoi(0x26); sti();}
void hardware_interrupt_27(context* ctx){panic(ctx); eoi(0x27); sti();}
void hardware_interrupt_28(context* ctx){panic(ctx); eoi(0x28); sti();}
void hardware_interrupt_29(context* ctx){panic(ctx); eoi(0x29); sti();}
void hardware_interrupt_2A(context* ctx){panic(ctx); eoi(0x2A); sti();}
void hardware_interrupt_2B(context* ctx){panic(ctx); eoi(0x2B); sti();}
void hardware_interrupt_2C(context* ctx){panic(ctx); eoi(0x2C); sti();}
void hardware_interrupt_2D(context* ctx){panic(ctx); eoi(0x2D); sti();}
void hardware_interrupt_2E(context* ctx){panic(ctx); eoi(0x2E); sti();}
void hardware_interrupt_2F(context* ctx){panic(ctx); eoi(0x2F); sti();}
void hardware_interrupt_30(context* ctx){panic(ctx); eoi(0x30); sti();}
void syscall_31(context* ctx){panic(ctx); sti();}
void syscall_32(context* ctx){panic(ctx); sti();}
void syscall_33(context* ctx){panic(ctx); sti();}
void syscall_34(context* ctx){panic(ctx); sti();}
void syscall_35(context* ctx){panic(ctx); sti();}
void syscall_36(context* ctx){panic(ctx); sti();}
void syscall_37(context* ctx){panic(ctx); sti();}
void syscall_38(context* ctx){panic(ctx); sti();}
void syscall_39(context* ctx){panic(ctx); sti();}
void syscall_3A(context* ctx){panic(ctx); sti();}
void syscall_3B(context* ctx){panic(ctx); sti();}
void syscall_3C(context* ctx){panic(ctx); sti();}
void syscall_3D(context* ctx){panic(ctx); sti();}
void syscall_3E(context* ctx){panic(ctx); sti();}
void syscall_3F(context* ctx){panic(ctx); sti();}
void syscall_40(context* ctx){panic(ctx); sti();}
void syscall_41(context* ctx){panic(ctx); sti();}
void syscall_42(context* ctx){panic(ctx); sti();}
void syscall_43(context* ctx){panic(ctx); sti();}
void syscall_44(context* ctx){panic(ctx); sti();}
void syscall_45(context* ctx){panic(ctx); sti();}
void syscall_46(context* ctx){panic(ctx); sti();}
void syscall_47(context* ctx){panic(ctx); sti();}
void syscall_48(context* ctx){panic(ctx); sti();}
void syscall_49(context* ctx){panic(ctx); sti();}
void syscall_4A(context* ctx){panic(ctx); sti();}
void syscall_4B(context* ctx){panic(ctx); sti();}
void syscall_4C(context* ctx){panic(ctx); sti();}
void syscall_4D(context* ctx){panic(ctx); sti();}
void syscall_4E(context* ctx){panic(ctx); sti();}
void syscall_4F(context* ctx){panic(ctx); sti();}
void syscall_50(context* ctx){panic(ctx); sti();}
void syscall_51(context* ctx){panic(ctx); sti();}
void syscall_52(context* ctx){panic(ctx); sti();}
void syscall_53(context* ctx){panic(ctx); sti();}
void syscall_54(context* ctx){panic(ctx); sti();}
void syscall_55(context* ctx){panic(ctx); sti();}
void syscall_56(context* ctx){panic(ctx); sti();}
void syscall_57(context* ctx){panic(ctx); sti();}
void syscall_58(context* ctx){panic(ctx); sti();}
void syscall_59(context* ctx){panic(ctx); sti();}
void syscall_5A(context* ctx){panic(ctx); sti();}
void syscall_5B(context* ctx){panic(ctx); sti();}
void syscall_5C(context* ctx){panic(ctx); sti();}
void syscall_5D(context* ctx){panic(ctx); sti();}
void syscall_5E(context* ctx){panic(ctx); sti();}
void syscall_5F(context* ctx){panic(ctx); sti();}
void syscall_60(context* ctx){panic(ctx); sti();}
void syscall_61(context* ctx){panic(ctx); sti();}
void syscall_62(context* ctx){panic(ctx); sti();}
void syscall_63(context* ctx){panic(ctx); sti();}
void syscall_64(context* ctx){panic(ctx); sti();}
void syscall_65(context* ctx){panic(ctx); sti();}
void syscall_66(context* ctx){panic(ctx); sti();}
void syscall_67(context* ctx){panic(ctx); sti();}
void syscall_68(context* ctx){panic(ctx); sti();}
void syscall_69(context* ctx){panic(ctx); sti();}
void syscall_6A(context* ctx){panic(ctx); sti();}
void syscall_6B(context* ctx){panic(ctx); sti();}
void syscall_6C(context* ctx){panic(ctx); sti();}
void syscall_6D(context* ctx){panic(ctx); sti();}
void syscall_6E(context* ctx){panic(ctx); sti();}
void syscall_6F(context* ctx){panic(ctx); sti();}
void syscall_70(context* ctx){panic(ctx); sti();}
void syscall_71(context* ctx){panic(ctx); sti();}
void syscall_72(context* ctx){panic(ctx); sti();}
void syscall_73(context* ctx){panic(ctx); sti();}
void syscall_74(context* ctx){panic(ctx); sti();}
void syscall_75(context* ctx){panic(ctx); sti();}
void syscall_76(context* ctx){panic(ctx); sti();}
void syscall_77(context* ctx){panic(ctx); sti();}
void syscall_78(context* ctx){panic(ctx); sti();}
void syscall_79(context* ctx){panic(ctx); sti();}
void syscall_7A(context* ctx){panic(ctx); sti();}
void syscall_7B(context* ctx){panic(ctx); sti();}
void syscall_7C(context* ctx){panic(ctx); sti();}
void syscall_7D(context* ctx){panic(ctx); sti();}
void syscall_7E(context* ctx){panic(ctx); sti();}
void syscall_7F(context* ctx){panic(ctx); sti();}
void syscall_80(context* ctx){panic(ctx); sti();}
void syscall_81(context* ctx){panic(ctx); sti();}
void syscall_82(context* ctx){panic(ctx); sti();}
void syscall_83(context* ctx){panic(ctx); sti();}
void syscall_84(context* ctx){panic(ctx); sti();}
void syscall_85(context* ctx){panic(ctx); sti();}
void syscall_86(context* ctx){panic(ctx); sti();}
void syscall_87(context* ctx){panic(ctx); sti();}
void syscall_88(context* ctx){panic(ctx); sti();}
void syscall_89(context* ctx){panic(ctx); sti();}
void syscall_8A(context* ctx){panic(ctx); sti();}
void syscall_8B(context* ctx){panic(ctx); sti();}
void syscall_8C(context* ctx){panic(ctx); sti();}
void syscall_8D(context* ctx){panic(ctx); sti();}
void syscall_8E(context* ctx){panic(ctx); sti();}
void syscall_8F(context* ctx){panic(ctx); sti();}
void syscall_90(context* ctx){panic(ctx); sti();}
void syscall_91(context* ctx){panic(ctx); sti();}
void syscall_92(context* ctx){panic(ctx); sti();}
void syscall_93(context* ctx){panic(ctx); sti();}
void syscall_94(context* ctx){panic(ctx); sti();}
void syscall_95(context* ctx){panic(ctx); sti();}
void syscall_96(context* ctx){panic(ctx); sti();}
void syscall_97(context* ctx){panic(ctx); sti();}
void syscall_98(context* ctx){panic(ctx); sti();}
void syscall_99(context* ctx){panic(ctx); sti();}
void syscall_9A(context* ctx){panic(ctx); sti();}
void syscall_9B(context* ctx){panic(ctx); sti();}
void syscall_9C(context* ctx){panic(ctx); sti();}
void syscall_9D(context* ctx){panic(ctx); sti();}
void syscall_9E(context* ctx){panic(ctx); sti();}
void syscall_9F(context* ctx){panic(ctx); sti();}
void syscall_A0(context* ctx){panic(ctx); sti();}
void syscall_A1(context* ctx){panic(ctx); sti();}
void syscall_A2(context* ctx){panic(ctx); sti();}
void syscall_A3(context* ctx){panic(ctx); sti();}
void syscall_A4(context* ctx){panic(ctx); sti();}
void syscall_A5(context* ctx){panic(ctx); sti();}
void syscall_A6(context* ctx){panic(ctx); sti();}
void syscall_A7(context* ctx){panic(ctx); sti();}
void syscall_A8(context* ctx){panic(ctx); sti();}
void syscall_A9(context* ctx){panic(ctx); sti();}
void syscall_AA(context* ctx){panic(ctx); sti();}
void syscall_AB(context* ctx){panic(ctx); sti();}
void syscall_AC(context* ctx){panic(ctx); sti();}
void syscall_AD(context* ctx){panic(ctx); sti();}
void syscall_AE(context* ctx){panic(ctx); sti();}
void syscall_AF(context* ctx){panic(ctx); sti();}
void syscall_B0(context* ctx){panic(ctx); sti();}
void syscall_B1(context* ctx){panic(ctx); sti();}
void syscall_B2(context* ctx){panic(ctx); sti();}
void syscall_B3(context* ctx){panic(ctx); sti();}
void syscall_B4(context* ctx){panic(ctx); sti();}
void syscall_B5(context* ctx){panic(ctx); sti();}
void syscall_B6(context* ctx){panic(ctx); sti();}
void syscall_B7(context* ctx){panic(ctx); sti();}
void syscall_B8(context* ctx){panic(ctx); sti();}
void syscall_B9(context* ctx){panic(ctx); sti();}
void syscall_BA(context* ctx){panic(ctx); sti();}
void syscall_BB(context* ctx){panic(ctx); sti();}
void syscall_BC(context* ctx){panic(ctx); sti();}
void syscall_BD(context* ctx){panic(ctx); sti();}
void syscall_BE(context* ctx){panic(ctx); sti();}
void syscall_BF(context* ctx){panic(ctx); sti();}
void syscall_C0(context* ctx){panic(ctx); sti();}
void syscall_C1(context* ctx){panic(ctx); sti();}
void syscall_C2(context* ctx){panic(ctx); sti();}
void syscall_C3(context* ctx){panic(ctx); sti();}
void syscall_C4(context* ctx){panic(ctx); sti();}
void syscall_C5(context* ctx){panic(ctx); sti();}
void syscall_C6(context* ctx){panic(ctx); sti();}
void syscall_C7(context* ctx){panic(ctx); sti();}
void syscall_C8(context* ctx){panic(ctx); sti();}
void syscall_C9(context* ctx){panic(ctx); sti();}
void syscall_CA(context* ctx){panic(ctx); sti();}
void syscall_CB(context* ctx){panic(ctx); sti();}
void syscall_CC(context* ctx){panic(ctx); sti();}
void syscall_CD(context* ctx){panic(ctx); sti();}
void syscall_CE(context* ctx){panic(ctx); sti();}
void syscall_CF(context* ctx){panic(ctx); sti();}
void syscall_D0(context* ctx){panic(ctx); sti();}
void syscall_D1(context* ctx){panic(ctx); sti();}
void syscall_D2(context* ctx){panic(ctx); sti();}
void syscall_D3(context* ctx){panic(ctx); sti();}
void syscall_D4(context* ctx){panic(ctx); sti();}
void syscall_D5(context* ctx){panic(ctx); sti();}
void syscall_D6(context* ctx){panic(ctx); sti();}
void syscall_D7(context* ctx){panic(ctx); sti();}
void syscall_D8(context* ctx){panic(ctx); sti();}
void syscall_D9(context* ctx){panic(ctx); sti();}
void syscall_DA(context* ctx){panic(ctx); sti();}
void syscall_DB(context* ctx){panic(ctx); sti();}
void syscall_DC(context* ctx){panic(ctx); sti();}
void syscall_DD(context* ctx){panic(ctx); sti();}
void syscall_DE(context* ctx){panic(ctx); sti();}
void syscall_DF(context* ctx){panic(ctx); sti();}
void syscall_E0(context* ctx){panic(ctx); sti();}
void syscall_E1(context* ctx){panic(ctx); sti();}
void syscall_E2(context* ctx){panic(ctx); sti();}
void syscall_E3(context* ctx){panic(ctx); sti();}
void syscall_E4(context* ctx){panic(ctx); sti();}
void syscall_E5(context* ctx){panic(ctx); sti();}
void syscall_E6(context* ctx){panic(ctx); sti();}
void syscall_E7(context* ctx){panic(ctx); sti();}
void syscall_E8(context* ctx){panic(ctx); sti();}
void syscall_E9(context* ctx){panic(ctx); sti();}
void syscall_EA(context* ctx){panic(ctx); sti();}
void syscall_EB(context* ctx){panic(ctx); sti();}
void syscall_EC(context* ctx){panic(ctx); sti();}
void syscall_ED(context* ctx){panic(ctx); sti();}
void syscall_EE(context* ctx){panic(ctx); sti();}
void syscall_EF(context* ctx){panic(ctx); sti();}
void syscall_F0(context* ctx){panic(ctx); sti();}
void syscall_F1(context* ctx){panic(ctx); sti();}
void syscall_F2(context* ctx){panic(ctx); sti();}
void syscall_F3(context* ctx){panic(ctx); sti();}
void syscall_F4(context* ctx){panic(ctx); sti();}
void syscall_F5(context* ctx){panic(ctx); sti();}
void syscall_F6(context* ctx){panic(ctx); sti();}
void syscall_F7(context* ctx){panic(ctx); sti();}
void syscall_F8(context* ctx){panic(ctx); sti();}
void syscall_F9(context* ctx){panic(ctx); sti();}
void syscall_FA(context* ctx){panic(ctx); sti();}
void syscall_FB(context* ctx){panic(ctx); sti();}
void syscall_FC(context* ctx){panic(ctx); sti();}
void syscall_FD(context* ctx){panic(ctx); sti();}
void syscall_FE(context* ctx){panic(ctx); sti();}
void syscall_FF(context* ctx){panic(ctx); sti();}

void interrupt_handler(context* ctx) {
    switch(ctx->vector) {
        case 0x00 : exception_00(ctx);break;
        case 0x01 : exception_01(ctx);break;
        case 0x02 : exception_02(ctx);break;
        case 0x03 : exception_03(ctx);break;
        case 0x04 : exception_04(ctx);break;
        case 0x05 : exception_05(ctx);break;
        case 0x06 : exception_06(ctx);break;
        case 0x07 : exception_07(ctx);break;
        case 0x08 : exception_08(ctx);break;
        case 0x09 : exception_09(ctx);break;
        case 0x0A : exception_0A(ctx);break;
        case 0x0B : exception_0B(ctx);break;
        case 0x0C : exception_0C(ctx);break;
        case 0x0D : exception_0D(ctx);break;
        case 0x0E : exception_0E(ctx);break;
        case 0x0F : exception_0F(ctx);break;
        case 0x10 : exception_10(ctx);break;
        case 0x11 : exception_11(ctx);break;
        case 0x12 : exception_12(ctx);break;
        case 0x13 : exception_13(ctx);break;
        case 0x14 : exception_14(ctx);break;
        case 0x15 : exception_15(ctx);break;
        case 0x16 : exception_16(ctx);break;
        case 0x17 : exception_17(ctx);break;
        case 0x18 : exception_18(ctx);break;
        case 0x19 : exception_19(ctx);break;
        case 0x1A : exception_1A(ctx);break;
        case 0x1B : exception_1B(ctx);break;
        case 0x1C : exception_1C(ctx);break;
        case 0x1D : exception_1D(ctx);break;
        case 0x1E : exception_1E(ctx);break;
        case 0x1F : exception_1F(ctx);break;
        case 0x20 : hardware_interrupt_20(ctx);break;
        case 0x21 : hardware_interrupt_21(ctx);break;
        case 0x22 : hardware_interrupt_22(ctx);break;
        case 0x23 : hardware_interrupt_23(ctx);break;
        case 0x24 : hardware_interrupt_24(ctx);break;
        case 0x25 : hardware_interrupt_25(ctx);break;
        case 0x26 : hardware_interrupt_26(ctx);break;
        case 0x27 : hardware_interrupt_27(ctx);break;
        case 0x28 : hardware_interrupt_28(ctx);break;
        case 0x29 : hardware_interrupt_29(ctx);break;
        case 0x2A : hardware_interrupt_2A(ctx);break;
        case 0x2B : hardware_interrupt_2B(ctx);break;
        case 0x2C : hardware_interrupt_2C(ctx);break;
        case 0x2D : hardware_interrupt_2D(ctx);break;
        case 0x2E : hardware_interrupt_2E(ctx);break;
        case 0x2F : hardware_interrupt_2F(ctx);break;
        case 0x30 : hardware_interrupt_30(ctx);break;
        case 0x31 : syscall_31(ctx);break;
        case 0x32 : syscall_32(ctx);break;
        case 0x33 : syscall_33(ctx);break;
        case 0x34 : syscall_34(ctx);break;
        case 0x35 : syscall_35(ctx);break;
        case 0x36 : syscall_36(ctx);break;
        case 0x37 : syscall_37(ctx);break;
        case 0x38 : syscall_38(ctx);break;
        case 0x39 : syscall_39(ctx);break;
        case 0x3A : syscall_3A(ctx);break;
        case 0x3B : syscall_3B(ctx);break;
        case 0x3C : syscall_3C(ctx);break;
        case 0x3D : syscall_3D(ctx);break;
        case 0x3E : syscall_3E(ctx);break;
        case 0x3F : syscall_3F(ctx);break;
        case 0x40 : syscall_40(ctx);break;
        case 0x41 : syscall_41(ctx);break;
        case 0x42 : syscall_42(ctx);break;
        case 0x43 : syscall_43(ctx);break;
        case 0x44 : syscall_44(ctx);break;
        case 0x45 : syscall_45(ctx);break;
        case 0x46 : syscall_46(ctx);break;
        case 0x47 : syscall_47(ctx);break;
        case 0x48 : syscall_48(ctx);break;
        case 0x49 : syscall_49(ctx);break;
        case 0x4A : syscall_4A(ctx);break;
        case 0x4B : syscall_4B(ctx);break;
        case 0x4C : syscall_4C(ctx);break;
        case 0x4D : syscall_4D(ctx);break;
        case 0x4E : syscall_4E(ctx);break;
        case 0x4F : syscall_4F(ctx);break;
        case 0x50 : syscall_50(ctx);break;
        case 0x51 : syscall_51(ctx);break;
        case 0x52 : syscall_52(ctx);break;
        case 0x53 : syscall_53(ctx);break;
        case 0x54 : syscall_54(ctx);break;
        case 0x55 : syscall_55(ctx);break;
        case 0x56 : syscall_56(ctx);break;
        case 0x57 : syscall_57(ctx);break;
        case 0x58 : syscall_58(ctx);break;
        case 0x59 : syscall_59(ctx);break;
        case 0x5A : syscall_5A(ctx);break;
        case 0x5B : syscall_5B(ctx);break;
        case 0x5C : syscall_5C(ctx);break;
        case 0x5D : syscall_5D(ctx);break;
        case 0x5E : syscall_5E(ctx);break;
        case 0x5F : syscall_5F(ctx);break;
        case 0x60 : syscall_60(ctx);break;
        case 0x61 : syscall_61(ctx);break;
        case 0x62 : syscall_62(ctx);break;
        case 0x63 : syscall_63(ctx);break;
        case 0x64 : syscall_64(ctx);break;
        case 0x65 : syscall_65(ctx);break;
        case 0x66 : syscall_66(ctx);break;
        case 0x67 : syscall_67(ctx);break;
        case 0x68 : syscall_68(ctx);break;
        case 0x69 : syscall_69(ctx);break;
        case 0x6A : syscall_6A(ctx);break;
        case 0x6B : syscall_6B(ctx);break;
        case 0x6C : syscall_6C(ctx);break;
        case 0x6D : syscall_6D(ctx);break;
        case 0x6E : syscall_6E(ctx);break;
        case 0x6F : syscall_6F(ctx);break;
        case 0x70 : syscall_70(ctx);break;
        case 0x71 : syscall_71(ctx);break;
        case 0x72 : syscall_72(ctx);break;
        case 0x73 : syscall_73(ctx);break;
        case 0x74 : syscall_74(ctx);break;
        case 0x75 : syscall_75(ctx);break;
        case 0x76 : syscall_76(ctx);break;
        case 0x77 : syscall_77(ctx);break;
        case 0x78 : syscall_78(ctx);break;
        case 0x79 : syscall_79(ctx);break;
        case 0x7A : syscall_7A(ctx);break;
        case 0x7B : syscall_7B(ctx);break;
        case 0x7C : syscall_7C(ctx);break;
        case 0x7D : syscall_7D(ctx);break;
        case 0x7E : syscall_7E(ctx);break;
        case 0x7F : syscall_7F(ctx);break;
        case 0x80 : syscall_80(ctx);break;
        case 0x81 : syscall_81(ctx);break;
        case 0x82 : syscall_82(ctx);break;
        case 0x83 : syscall_83(ctx);break;
        case 0x84 : syscall_84(ctx);break;
        case 0x85 : syscall_85(ctx);break;
        case 0x86 : syscall_86(ctx);break;
        case 0x87 : syscall_87(ctx);break;
        case 0x88 : syscall_88(ctx);break;
        case 0x89 : syscall_89(ctx);break;
        case 0x8A : syscall_8A(ctx);break;
        case 0x8B : syscall_8B(ctx);break;
        case 0x8C : syscall_8C(ctx);break;
        case 0x8D : syscall_8D(ctx);break;
        case 0x8E : syscall_8E(ctx);break;
        case 0x8F : syscall_8F(ctx);break;
        case 0x90 : syscall_90(ctx);break;
        case 0x91 : syscall_91(ctx);break;
        case 0x92 : syscall_92(ctx);break;
        case 0x93 : syscall_93(ctx);break;
        case 0x94 : syscall_94(ctx);break;
        case 0x95 : syscall_95(ctx);break;
        case 0x96 : syscall_96(ctx);break;
        case 0x97 : syscall_97(ctx);break;
        case 0x98 : syscall_98(ctx);break;
        case 0x99 : syscall_99(ctx);break;
        case 0x9A : syscall_9A(ctx);break;
        case 0x9B : syscall_9B(ctx);break;
        case 0x9C : syscall_9C(ctx);break;
        case 0x9D : syscall_9D(ctx);break;
        case 0x9E : syscall_9E(ctx);break;
        case 0x9F : syscall_9F(ctx);break;
        case 0xA0 : syscall_A0(ctx);break;
        case 0xA1 : syscall_A1(ctx);break;
        case 0xA2 : syscall_A2(ctx);break;
        case 0xA3 : syscall_A3(ctx);break;
        case 0xA4 : syscall_A4(ctx);break;
        case 0xA5 : syscall_A5(ctx);break;
        case 0xA6 : syscall_A6(ctx);break;
        case 0xA7 : syscall_A7(ctx);break;
        case 0xA8 : syscall_A8(ctx);break;
        case 0xA9 : syscall_A9(ctx);break;
        case 0xAA : syscall_AA(ctx);break;
        case 0xAB : syscall_AB(ctx);break;
        case 0xAC : syscall_AC(ctx);break;
        case 0xAD : syscall_AD(ctx);break;
        case 0xAE : syscall_AE(ctx);break;
        case 0xAF : syscall_AF(ctx);break;
        case 0xB0 : syscall_B0(ctx);break;
        case 0xB1 : syscall_B1(ctx);break;
        case 0xB2 : syscall_B2(ctx);break;
        case 0xB3 : syscall_B3(ctx);break;
        case 0xB4 : syscall_B4(ctx);break;
        case 0xB5 : syscall_B5(ctx);break;
        case 0xB6 : syscall_B6(ctx);break;
        case 0xB7 : syscall_B7(ctx);break;
        case 0xB8 : syscall_B8(ctx);break;
        case 0xB9 : syscall_B9(ctx);break;
        case 0xBA : syscall_BA(ctx);break;
        case 0xBB : syscall_BB(ctx);break;
        case 0xBC : syscall_BC(ctx);break;
        case 0xBD : syscall_BD(ctx);break;
        case 0xBE : syscall_BE(ctx);break;
        case 0xBF : syscall_BF(ctx);break;
        case 0xC0 : syscall_C0(ctx);break;
        case 0xC1 : syscall_C1(ctx);break;
        case 0xC2 : syscall_C2(ctx);break;
        case 0xC3 : syscall_C3(ctx);break;
        case 0xC4 : syscall_C4(ctx);break;
        case 0xC5 : syscall_C5(ctx);break;
        case 0xC6 : syscall_C6(ctx);break;
        case 0xC7 : syscall_C7(ctx);break;
        case 0xC8 : syscall_C8(ctx);break;
        case 0xC9 : syscall_C9(ctx);break;
        case 0xCA : syscall_CA(ctx);break;
        case 0xCB : syscall_CB(ctx);break;
        case 0xCC : syscall_CC(ctx);break;
        case 0xCD : syscall_CD(ctx);break;
        case 0xCE : syscall_CE(ctx);break;
        case 0xCF : syscall_CF(ctx);break;
        case 0xD0 : syscall_D0(ctx);break;
        case 0xD1 : syscall_D1(ctx);break;
        case 0xD2 : syscall_D2(ctx);break;
        case 0xD3 : syscall_D3(ctx);break;
        case 0xD4 : syscall_D4(ctx);break;
        case 0xD5 : syscall_D5(ctx);break;
        case 0xD6 : syscall_D6(ctx);break;
        case 0xD7 : syscall_D7(ctx);break;
        case 0xD8 : syscall_D8(ctx);break;
        case 0xD9 : syscall_D9(ctx);break;
        case 0xDA : syscall_DA(ctx);break;
        case 0xDB : syscall_DB(ctx);break;
        case 0xDC : syscall_DC(ctx);break;
        case 0xDD : syscall_DD(ctx);break;
        case 0xDE : syscall_DE(ctx);break;
        case 0xDF : syscall_DF(ctx);break;
        case 0xE0 : syscall_E0(ctx);break;
        case 0xE1 : syscall_E1(ctx);break;
        case 0xE2 : syscall_E2(ctx);break;
        case 0xE3 : syscall_E3(ctx);break;
        case 0xE4 : syscall_E4(ctx);break;
        case 0xE5 : syscall_E5(ctx);break;
        case 0xE6 : syscall_E6(ctx);break;
        case 0xE7 : syscall_E7(ctx);break;
        case 0xE8 : syscall_E8(ctx);break;
        case 0xE9 : syscall_E9(ctx);break;
        case 0xEA : syscall_EA(ctx);break;
        case 0xEB : syscall_EB(ctx);break;
        case 0xEC : syscall_EC(ctx);break;
        case 0xED : syscall_ED(ctx);break;
        case 0xEE : syscall_EE(ctx);break;
        case 0xEF : syscall_EF(ctx);break;
        case 0xF0 : syscall_F0(ctx);break;
        case 0xF1 : syscall_F1(ctx);break;
        case 0xF2 : syscall_F2(ctx);break;
        case 0xF3 : syscall_F3(ctx);break;
        case 0xF4 : syscall_F4(ctx);break;
        case 0xF5 : syscall_F5(ctx);break;
        case 0xF6 : syscall_F6(ctx);break;
        case 0xF7 : syscall_F7(ctx);break;
        case 0xF8 : syscall_F8(ctx);break;
        case 0xF9 : syscall_F9(ctx);break;
        case 0xFA : syscall_FA(ctx);break;
        case 0xFB : syscall_FB(ctx);break;
        case 0xFC : syscall_FC(ctx);break;
        case 0xFD : syscall_FD(ctx);break;
        case 0xFE : syscall_FE(ctx);break;
        case 0xFF : syscall_FF(ctx);break;
    }
}