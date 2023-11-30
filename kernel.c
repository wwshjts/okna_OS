#include "types.h"
#include "utils.h"
#include "vga_print.h"
#include "idt.h"
#include "intel_8259A.h"
#include "kernel_allocator.h"

void interupt();

void kernel() {
    init_printer();
    make_idt();
    make_idtr();
    initialize_intel_8259A();
    sti();
    //interupt();
    for(;;);
}
