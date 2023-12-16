mangling = '' 
exceptions_with_error_code = {0x8, 0xA, 0xB, 0xC, 0xD, 0xE, 0x11, 0x15, 0x1D, 0x1E}
tab = " " * 4

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


    
