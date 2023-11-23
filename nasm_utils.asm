[BITS 32]

[GLOBAL _load_idtr]
[GLOBAL _interupt]
[GLOBAL _sti]
[GLOBAL _cli]
[GLOBAL _outb]
[GLOBAL _inb]
[GLOBAL _interupt]

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

; читает байт из порта с номером DX
_inb:
    mov dx, [esp+4]
    in al, dx
    ; TODO: ret val
    ret

; пишет байт в порт с номером DX
_outb:
    mov dx, [esp+4]
    mov al, [esp+8]
    out dx, al
    ret