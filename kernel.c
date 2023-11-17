#ifndef _TYPES_H #include"types.h"
#endif

#ifndef _UTILS_H
    #include"utils.h"
#endif

#include"vga_print.h"
#include"idt.h"
#include"kernel_allocator.h"
void _load_idtr(byte*);
void _interupt();
void _cli();

void kernel() {
    init_printer();
    byte* trmps = kernel_calloc(IDT_SIZE, sizeof(void*));
    make_tramplins(trmps);
    byte* idt = kernel_calloc(IDT_SIZE, sizeof(gate_descriptor));
    make_idt(idt, trmps);
    byte* idtr = kernel_malloc(sizeof(word) + sizeof(hword));
    make_idtr(idt, idtr);
    _load_idtr(idtr);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < i; j++) {
            print(" ");
        }
        print("%d\n", i);
    }
    //int i = 1/0;
    //_interupt();
    _cli();
    for(;;);
}
