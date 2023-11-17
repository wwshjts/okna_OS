[BITS 32]

[GLOBAL _load_idtr]
[GLOBAL kernel_panic]
[GLOBAL _interupt]
[GLOBAL _cli]
[EXTERN init_printer]
[EXTERN print]

kernel_panic:
    cli
    push ebp
    mov ebp, esp
    call init_printer    
    mov eax, [ebp+12]
    push eax
    mov eax, [ebp+8]
    push eax
    call print
    loop:
        jmp loop

_load_idtr:
    mov ebx, [esp+4]
    lidt [ebx]
    ret

_interupt:
    INT 0x42

_cli:
    sti
