[BITS 32]

[GLOBAL load_idtr]
[GLOBAL kernel_panic]
[GLOBAL interupt]
[GLOBAL cli]
[GLOBAL sti]
[EXTERN init_printer]
[EXTERN print]

load_idtr:
    mov ebx, [esp+4]
    lidt [ebx]
    ret

interupt:
    INT 0x42

cli:
    cli
    ret
sti:
    sti
    ret
