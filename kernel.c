#include "types.h"
#include "utils.h"
#include "vga_print.h"
#include "idt.h"
#include "kernel_allocator.h"

void interupt();

void kernel() {
    make_idt();
    make_idtr();
    interupt();
    for(;;);
}
