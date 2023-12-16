[BITS 32]

[GLOBAL load_idtr]
[GLOBAL interupt]
[GLOBAL sti]
[GLOBAL cli]
[GLOBAL outb]
[GLOBAL inb]

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

inb:
    mov dx, [esp+4]
    in al, dx
    ret

outb:
    mov dx, [esp+4]
    mov al, [esp+8]
    out dx, al
    ret