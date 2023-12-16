mangling = '' 
exceptions_with_error_code = {0x8, 0xA, 0xB, 0xC, 0xD, 0xE, 0x11, 0x15, 0x1D, 0x1E}
tab = " " * 4

with open("nasm_interrupts.asm", 'w') as out:
    for i in range(0xFF + 1):
        out.write(f'[GLOBAL {mangling}tramplin_{i:02X}]\n')

    out.write("\n")

    for i in range(0xFF + 1):
        out.write(f'{mangling}tramplin_{i:02X}:\n')
        if (i not in exceptions_with_error_code):
            out.write(tab + f'push 0x00\n')
        out.write(tab + f'push 0x{i:02X}\n')
        out.write(tab + f"jmp collect_context\n")


    
