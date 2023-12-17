#include "utils.h"
#include "interrupts.h"
#include "tramplins.h"
#include "kernel_allocator.h"

#define IDT_SIZE 256
#define INTERRUPT_GATE 0xE
#define TRAP_GATE 0xF

static void** make_tramplins();

#pragma pack(push, 1)
typedef struct{
    hword low_shift;
    hword selector;
    byte space;
    byte info;
    hword high_shift;
} gate_descriptor;
#pragma pack(pop)

static gate_descriptor* idt;

static void load_idtr(byte*);

void panic(context *ctx){
    print("Kernel panic: inhandled interrupt %x. Context of interrupted process:\n", ctx->vector);
    print("EAX = %x\n", ctx->eax);
    print("ECX = %x\n", ctx->ecx);
    print("EDX = %x\n", ctx->edx);
    print("EBX = %x\n", ctx->ebx);
    print("ESI = %x\n", ctx->esi);
    print("EDI = %x\n", ctx->edi);
    print("EBP = %x\n", ctx->ebp);
    print("ESP = %x\n", ctx->esp);
    print("DS = %x\n", ctx->ds);
    print("CS = %x\n", ctx->cs);
    print("ES = %x\n", ctx->es);
    print("FS = %x\n", ctx->fs);
    print("GS = %x\n", ctx->gs);
    print("EFLAGS (interrupted) = %x\n", ctx->eflags);
    for(;;);
}

word timer = 0;
void timer_interrupt() {
    print("%d ", timer);
    timer++;
}

void make_idt() {
    void** tramplins = make_tramplins();
    idt = (gate_descriptor*) kernel_malloc(IDT_SIZE * sizeof(gate_descriptor));
    for(int vector = 0; vector < IDT_SIZE; vector++){
        byte* handler = tramplins[vector];
        hword low_shift = (hword) handler;
        hword high_shift = (hword) (((word) handler) >> 16);
        idt[vector].low_shift = low_shift;
        idt[vector].high_shift = high_shift;
        idt[vector].selector = 8; //code segment
        // if exception
        if (vector < 0x20) {
            idt[vector].info = 0b10000000 + TRAP_GATE;
        } else {
            idt[vector].info = 0b10000000 + INTERRUPT_GATE;
        }
        idt[vector].space = 0;
    }
}

void make_idtr(){
    byte* idtr = kernel_malloc(sizeof(hword) + sizeof(word));
    *((hword*)idtr) = IDT_SIZE * sizeof(gate_descriptor) - 1;
    *((word*)(idtr + 2)) = (word)idt;
    load_idtr(idtr);
}

static void** make_tramplins () {
    void** tramplins = kernel_calloc(IDT_SIZE, sizeof(gate_descriptor));
    tramplins[0x00] = tramplin_00;
    tramplins[0x01] = tramplin_01;
    tramplins[0x02] = tramplin_02;
    tramplins[0x03] = tramplin_03;
    tramplins[0x04] = tramplin_04;
    tramplins[0x05] = tramplin_05;
    tramplins[0x06] = tramplin_06;
    tramplins[0x07] = tramplin_07;
    tramplins[0x08] = tramplin_08;
    tramplins[0x09] = tramplin_09;
    tramplins[0x0A] = tramplin_0A;
    tramplins[0x0B] = tramplin_0B;
    tramplins[0x0C] = tramplin_0C;
    tramplins[0x0D] = tramplin_0D;
    tramplins[0x0E] = tramplin_0E;
    tramplins[0x0F] = tramplin_0F;
    tramplins[0x10] = tramplin_10;
    tramplins[0x11] = tramplin_11;
    tramplins[0x12] = tramplin_12;
    tramplins[0x13] = tramplin_13;
    tramplins[0x14] = tramplin_14;
    tramplins[0x15] = tramplin_15;
    tramplins[0x16] = tramplin_16;
    tramplins[0x17] = tramplin_17;
    tramplins[0x18] = tramplin_18;
    tramplins[0x19] = tramplin_19;
    tramplins[0x1A] = tramplin_1A;
    tramplins[0x1B] = tramplin_1B;
    tramplins[0x1C] = tramplin_1C;
    tramplins[0x1D] = tramplin_1D;
    tramplins[0x1E] = tramplin_1E;
    tramplins[0x1F] = tramplin_1F;
    tramplins[0x20] = tramplin_20;
    tramplins[0x21] = tramplin_21;
    tramplins[0x22] = tramplin_22;
    tramplins[0x23] = tramplin_23;
    tramplins[0x24] = tramplin_24;
    tramplins[0x25] = tramplin_25;
    tramplins[0x26] = tramplin_26;
    tramplins[0x27] = tramplin_27;
    tramplins[0x28] = tramplin_28;
    tramplins[0x29] = tramplin_29;
    tramplins[0x2A] = tramplin_2A;
    tramplins[0x2B] = tramplin_2B;
    tramplins[0x2C] = tramplin_2C;
    tramplins[0x2D] = tramplin_2D;
    tramplins[0x2E] = tramplin_2E;
    tramplins[0x2F] = tramplin_2F;
    tramplins[0x30] = tramplin_30;
    tramplins[0x31] = tramplin_31;
    tramplins[0x32] = tramplin_32;
    tramplins[0x33] = tramplin_33;
    tramplins[0x34] = tramplin_34;
    tramplins[0x35] = tramplin_35;
    tramplins[0x36] = tramplin_36;
    tramplins[0x37] = tramplin_37;
    tramplins[0x38] = tramplin_38;
    tramplins[0x39] = tramplin_39;
    tramplins[0x3A] = tramplin_3A;
    tramplins[0x3B] = tramplin_3B;
    tramplins[0x3C] = tramplin_3C;
    tramplins[0x3D] = tramplin_3D;
    tramplins[0x3E] = tramplin_3E;
    tramplins[0x3F] = tramplin_3F;
    tramplins[0x40] = tramplin_40;
    tramplins[0x41] = tramplin_41;
    tramplins[0x42] = tramplin_42;
    tramplins[0x43] = tramplin_43;
    tramplins[0x44] = tramplin_44;
    tramplins[0x45] = tramplin_45;
    tramplins[0x46] = tramplin_46;
    tramplins[0x47] = tramplin_47;
    tramplins[0x48] = tramplin_48;
    tramplins[0x49] = tramplin_49;
    tramplins[0x4A] = tramplin_4A;
    tramplins[0x4B] = tramplin_4B;
    tramplins[0x4C] = tramplin_4C;
    tramplins[0x4D] = tramplin_4D;
    tramplins[0x4E] = tramplin_4E;
    tramplins[0x4F] = tramplin_4F;
    tramplins[0x50] = tramplin_50;
    tramplins[0x51] = tramplin_51;
    tramplins[0x52] = tramplin_52;
    tramplins[0x53] = tramplin_53;
    tramplins[0x54] = tramplin_54;
    tramplins[0x55] = tramplin_55;
    tramplins[0x56] = tramplin_56;
    tramplins[0x57] = tramplin_57;
    tramplins[0x58] = tramplin_58;
    tramplins[0x59] = tramplin_59;
    tramplins[0x5A] = tramplin_5A;
    tramplins[0x5B] = tramplin_5B;
    tramplins[0x5C] = tramplin_5C;
    tramplins[0x5D] = tramplin_5D;
    tramplins[0x5E] = tramplin_5E;
    tramplins[0x5F] = tramplin_5F;
    tramplins[0x60] = tramplin_60;
    tramplins[0x61] = tramplin_61;
    tramplins[0x62] = tramplin_62;
    tramplins[0x63] = tramplin_63;
    tramplins[0x64] = tramplin_64;
    tramplins[0x65] = tramplin_65;
    tramplins[0x66] = tramplin_66;
    tramplins[0x67] = tramplin_67;
    tramplins[0x68] = tramplin_68;
    tramplins[0x69] = tramplin_69;
    tramplins[0x6A] = tramplin_6A;
    tramplins[0x6B] = tramplin_6B;
    tramplins[0x6C] = tramplin_6C;
    tramplins[0x6D] = tramplin_6D;
    tramplins[0x6E] = tramplin_6E;
    tramplins[0x6F] = tramplin_6F;
    tramplins[0x70] = tramplin_70;
    tramplins[0x71] = tramplin_71;
    tramplins[0x72] = tramplin_72;
    tramplins[0x73] = tramplin_73;
    tramplins[0x74] = tramplin_74;
    tramplins[0x75] = tramplin_75;
    tramplins[0x76] = tramplin_76;
    tramplins[0x77] = tramplin_77;
    tramplins[0x78] = tramplin_78;
    tramplins[0x79] = tramplin_79;
    tramplins[0x7A] = tramplin_7A;
    tramplins[0x7B] = tramplin_7B;
    tramplins[0x7C] = tramplin_7C;
    tramplins[0x7D] = tramplin_7D;
    tramplins[0x7E] = tramplin_7E;
    tramplins[0x7F] = tramplin_7F;
    tramplins[0x80] = tramplin_80;
    tramplins[0x81] = tramplin_81;
    tramplins[0x82] = tramplin_82;
    tramplins[0x83] = tramplin_83;
    tramplins[0x84] = tramplin_84;
    tramplins[0x85] = tramplin_85;
    tramplins[0x86] = tramplin_86;
    tramplins[0x87] = tramplin_87;
    tramplins[0x88] = tramplin_88;
    tramplins[0x89] = tramplin_89;
    tramplins[0x8A] = tramplin_8A;
    tramplins[0x8B] = tramplin_8B;
    tramplins[0x8C] = tramplin_8C;
    tramplins[0x8D] = tramplin_8D;
    tramplins[0x8E] = tramplin_8E;
    tramplins[0x8F] = tramplin_8F;
    tramplins[0x90] = tramplin_90;
    tramplins[0x91] = tramplin_91;
    tramplins[0x92] = tramplin_92;
    tramplins[0x93] = tramplin_93;
    tramplins[0x94] = tramplin_94;
    tramplins[0x95] = tramplin_95;
    tramplins[0x96] = tramplin_96;
    tramplins[0x97] = tramplin_97;
    tramplins[0x98] = tramplin_98;
    tramplins[0x99] = tramplin_99;
    tramplins[0x9A] = tramplin_9A;
    tramplins[0x9B] = tramplin_9B;
    tramplins[0x9C] = tramplin_9C;
    tramplins[0x9D] = tramplin_9D;
    tramplins[0x9E] = tramplin_9E;
    tramplins[0x9F] = tramplin_9F;
    tramplins[0xA0] = tramplin_A0;
    tramplins[0xA1] = tramplin_A1;
    tramplins[0xA2] = tramplin_A2;
    tramplins[0xA3] = tramplin_A3;
    tramplins[0xA4] = tramplin_A4;
    tramplins[0xA5] = tramplin_A5;
    tramplins[0xA6] = tramplin_A6;
    tramplins[0xA7] = tramplin_A7;
    tramplins[0xA8] = tramplin_A8;
    tramplins[0xA9] = tramplin_A9;
    tramplins[0xAA] = tramplin_AA;
    tramplins[0xAB] = tramplin_AB;
    tramplins[0xAC] = tramplin_AC;
    tramplins[0xAD] = tramplin_AD;
    tramplins[0xAE] = tramplin_AE;
    tramplins[0xAF] = tramplin_AF;
    tramplins[0xB0] = tramplin_B0;
    tramplins[0xB1] = tramplin_B1;
    tramplins[0xB2] = tramplin_B2;
    tramplins[0xB3] = tramplin_B3;
    tramplins[0xB4] = tramplin_B4;
    tramplins[0xB5] = tramplin_B5;
    tramplins[0xB6] = tramplin_B6;
    tramplins[0xB7] = tramplin_B7;
    tramplins[0xB8] = tramplin_B8;
    tramplins[0xB9] = tramplin_B9;
    tramplins[0xBA] = tramplin_BA;
    tramplins[0xBB] = tramplin_BB;
    tramplins[0xBC] = tramplin_BC;
    tramplins[0xBD] = tramplin_BD;
    tramplins[0xBE] = tramplin_BE;
    tramplins[0xBF] = tramplin_BF;
    tramplins[0xC0] = tramplin_C0;
    tramplins[0xC1] = tramplin_C1;
    tramplins[0xC2] = tramplin_C2;
    tramplins[0xC3] = tramplin_C3;
    tramplins[0xC4] = tramplin_C4;
    tramplins[0xC5] = tramplin_C5;
    tramplins[0xC6] = tramplin_C6;
    tramplins[0xC7] = tramplin_C7;
    tramplins[0xC8] = tramplin_C8;
    tramplins[0xC9] = tramplin_C9;
    tramplins[0xCA] = tramplin_CA;
    tramplins[0xCB] = tramplin_CB;
    tramplins[0xCC] = tramplin_CC;
    tramplins[0xCD] = tramplin_CD;
    tramplins[0xCE] = tramplin_CE;
    tramplins[0xCF] = tramplin_CF;
    tramplins[0xD0] = tramplin_D0;
    tramplins[0xD1] = tramplin_D1;
    tramplins[0xD2] = tramplin_D2;
    tramplins[0xD3] = tramplin_D3;
    tramplins[0xD4] = tramplin_D4;
    tramplins[0xD5] = tramplin_D5;
    tramplins[0xD6] = tramplin_D6;
    tramplins[0xD7] = tramplin_D7;
    tramplins[0xD8] = tramplin_D8;
    tramplins[0xD9] = tramplin_D9;
    tramplins[0xDA] = tramplin_DA;
    tramplins[0xDB] = tramplin_DB;
    tramplins[0xDC] = tramplin_DC;
    tramplins[0xDD] = tramplin_DD;
    tramplins[0xDE] = tramplin_DE;
    tramplins[0xDF] = tramplin_DF;
    tramplins[0xE0] = tramplin_E0;
    tramplins[0xE1] = tramplin_E1;
    tramplins[0xE2] = tramplin_E2;
    tramplins[0xE3] = tramplin_E3;
    tramplins[0xE4] = tramplin_E4;
    tramplins[0xE5] = tramplin_E5;
    tramplins[0xE6] = tramplin_E6;
    tramplins[0xE7] = tramplin_E7;
    tramplins[0xE8] = tramplin_E8;
    tramplins[0xE9] = tramplin_E9;
    tramplins[0xEA] = tramplin_EA;
    tramplins[0xEB] = tramplin_EB;
    tramplins[0xEC] = tramplin_EC;
    tramplins[0xED] = tramplin_ED;
    tramplins[0xEE] = tramplin_EE;
    tramplins[0xEF] = tramplin_EF;
    tramplins[0xF0] = tramplin_F0;
    tramplins[0xF1] = tramplin_F1;
    tramplins[0xF2] = tramplin_F2;
    tramplins[0xF3] = tramplin_F3;
    tramplins[0xF4] = tramplin_F4;
    tramplins[0xF5] = tramplin_F5;
    tramplins[0xF6] = tramplin_F6;
    tramplins[0xF7] = tramplin_F7;
    tramplins[0xF8] = tramplin_F8;
    tramplins[0xF9] = tramplin_F9;
    tramplins[0xFA] = tramplin_FA;
    tramplins[0xFB] = tramplin_FB;
    tramplins[0xFC] = tramplin_FC;
    tramplins[0xFD] = tramplin_FD;
    tramplins[0xFE] = tramplin_FE;
    tramplins[0xFF] = tramplin_FF;
    return tramplins;
}

