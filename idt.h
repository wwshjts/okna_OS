#ifndef _TYPES_H
    #include"types.h"
#endif
#define IDT_SIZE 256
#pragma pack(push, 1)
typedef struct{
    hword low_shift;
    hword selector;
    byte space;
    byte info;
    hword high_shift;
} gate_descriptor;
#pragma pack(pop)

void make_tramplins(void** ptr);
void make_idt(byte* idt, void** tramplins);
void make_idtr(byte* idt, byte* idtr);
