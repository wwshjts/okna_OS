[BITS 32]

[GLOBAL _load_idtr]
[GLOBAL _interupt]
[GLOBAL _sti]
[GLOBAL _cli]
[GLOBAL _outb]
[GLOBAL _inb]
[GLOBAL _experiment]
[GLOBAL _setPGInCr0]
[GLOBAL _setPSEInCr4]
[GLOBAL _setCr3]

_load_idtr:
    mov ebx, [esp+4]
    lidt [ebx]
    ret

_interupt:
    INT 0x42
    ret

_cli:
    cli
    ret

_sti:
    sti
    ret

_inb:
    mov dx, [esp+4]
    in al, dx
    ret

_outb:
    mov dx, [esp+4]
    mov al, [esp+8]
    out dx, al
    ret

_setPGInCr0:
    mov eax, cr0
    or  eax, 0b10000000000000000000000000000000    ; 31 bit
    mov cr0, eax
    ret

_setPSEInCr4:
    mov eax, cr4
    or  eax, 0b1000    ; 4 bit
    mov cr4, eax
    ret

_setCr3:
    mov eax, [esp+4]
    mov cr3, eax
    ret

_experiment:
    mov eax, 1
    mov ecx, 2
    mov edx, 3
    mov ebx, 4
    mov esi, 5
    mov edi, 6
    mov ebp, 7
    int 42