mangling = '' 
exceptions_with_error_code = {0x8, 0xA, 0xB, 0xC, 0xD, 0xE, 0x11, 0x15, 0x1D, 0x1E}
tab = " " * 4

exceptions = {i for i in range(0x20)}
hardware = {i for i in range(0x20, 0x30+1)}

interrupt_handler = """
void interrupt_handler(context* ctx) {
    switch(ctx->vector) {
"""

collect_context = """
collect_context:
    ; 0x10 смещение DATA_SEG в GTD
    mov eax, 0x10
    mov ds, eax
    mov es, eax
    push ds
    push es
    push fs
    push gs
    pusha
    call interrupt_handler
"""


with open("tramplins.h", "w") as out:
    out.write("void interrupt_handler();\n")
    for i in range(0xFF + 1):
        out.write(f"void tramplin_{i:02X}();\n") 

with open("interrupt_handlers.h", "w") as out:
    out.write("void interrupt_handler(context*);")

with open("interrupt_handlers.c", "w") as out:
    out.write('#include "intel_8259A.h"\n')
    out.write('#include "interrupts.h"\n')
    out.write('#include "utils.h"\n')

    out.write("\n")

    for i in range(0xFF + 1):
        if i in hardware:
            out.write(f'void hardware_interrupt_{i:02X}(context* ctx){{panic(ctx); eoi(0x{i:02X}); sti();}}\n')
        elif i in exceptions:
            out.write(f'void exception_{i:02X}(context* ctx){{panic(ctx);}}\n')
        else:
            out.write(f'void syscall_{i:02X}(context* ctx){{panic(ctx); sti();}}\n')

    out.write(interrupt_handler)
    for i in range(0xFF + 1): 
        out.write(2*tab + f'case 0x{i:02X} : ')
        if i in hardware:
            out.write(f'hardware_interrupt_{i:02X}(ctx);')
        elif i in exceptions:
            out.write(f'exception_{i:02X}(ctx);')
        else:
            out.write(f'syscall_{i:02X}(ctx);')
        out.write('break;\n')
    out.write(tab + "}\n")
    out.write("}")


with open("tramplins.asm", 'w') as out:
    out.write("[BITS 32]\n")
    out.write(f'[EXTERN {mangling}interrupt_handler]\n')
    for i in range(0xFF + 1):
        out.write(f'[GLOBAL {mangling}tramplin_{i:02X}]\n')

    out.write("\n")

    out.write(collect_context)
    for i in range(0xFF + 1):
        out.write(f'{mangling}tramplin_{i:02X}:\n')
        if (i not in exceptions_with_error_code):
            out.write(tab + f'push 0x00\n')
        out.write(tab + f'push 0x{i:02X}\n')
        out.write(tab + "jmp collect_context\n")
