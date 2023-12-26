#include "types.h"
#include "utils.h"
#include "vga_print.h"
#include "interrupts.h"
#include "intel_8259A.h"
#include "kernel_allocator.h"
#include "page_translation.h"

void interupt();
void experiment();

void kernel() {
    enable_page_translation();
    //enable_large_page_translation();
    init_printer();
    make_idt();
    make_idtr();
    initialize_intel_8259A();
    //experiment();
    change_device(Keyboard, 1);
    //change_device(Timer, 1);
    sti();
    //while (1) {print("*");}
    for(;;);
}