[BITS 32]

[GLOBAL load_idtr]
[GLOBAL interupt]
[GLOBAL cli]
[GLOBAL sti]

load_idtr:
    mov ebx, [esp+4]
    lidt [ebx]
    ret

interupt:
    INT 0x42
    ret

cli:
    cli
    ret

sti:
    sti
    ret
