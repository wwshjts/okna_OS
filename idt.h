#ifndef _TYPES_H
    #include"types.h"
#endif
#define IDT_SIZE 256
//TODO литл эндиан?
//TODO поля меньше байта?
#pragma pack(push, 1)
typedef struct{
    hword low_shift;
    hword selector;
    byte space;
    byte info;
    hword high_shift;
} gate_descriptor;
#pragma pack(pop)

void make_idt(byte* idt);
void make_idtr(byte* idt, byte* idtr);
void tramplin_00();
static void kernel_panic(const char* fmt, int vector); 
