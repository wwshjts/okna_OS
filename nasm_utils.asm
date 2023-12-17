[BITS 32]

[GLOBAL load_idtr]
[GLOBAL interupt]
[GLOBAL sti]
[GLOBAL cli]
[GLOBAL outb]
[GLOBAL inb]
[GLOBAL experiment]

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

experiment:
    mov eax, 1
    mov ecx, 2
    mov edx, 3
    mov ebx, 4
    mov esi, 5
    mov edi, 6
    mov ebp, 7
    int 42


outb:
    mov dx, [esp+4]
    mov al, [esp+8]
    out dx, al
    ret