with open("idt.c", 'w') as out:
    for i in range(0xFF + 1):
        out.write(f'static void tramplin_{i:02X}() {"{"}panic_handler(0x{i:02X});{"}"}\n')
    arr_str = 'static void** tramplins = {'
    for i in range(0xFF):
        arr_str += f'tramplin_{i:02X}, '
    arr_str += f'tramplin_FF' + "}\n"
    out.write(arr_str)

    
