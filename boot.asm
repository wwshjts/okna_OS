[BITS 16]
;Управление передается по физическому адресу 0x007С00

;Настраиваем стек
;Распологаем вершину по адрессу 0x007C00
;Стек растет вниз
;Данные BIOS распологаются по 0x500 (таблица прерываний) 

cli
xor ax, ax				; устанавливаем регистр ax в ноль
mov	ss, ax				; выбираем сегмент с базой 0 
mov sp, 0x7C00			; устанавливаем cмещение относительно сегмента


; регистр ds не определен в начале работы

mov ax, 0x7C0
mov ds, ax				; устанавливаем селектор сегмента в 0x7C0

;настраиваем прерывание для чтения данных
mov cx, 0x1				; начальный сектор 1 цилиндр 0
xor dh, dh				; головка 0
mov bx, 0x2000
mov es, bx				; селектор сегмента чтения 
xor bx, bx
;BIOS устанавливает номер загрузочного диска в регистр dl перед передачей управления VBR
xor di, di				; количество ошибок

read_another:
	; всегда обновляем ax т.к. после прерывания он затирается
	mov ah, 0x2				; номер функции
	mov al, 0x1				; читаем по одному сектору
	int 0x13

	jnc no_error			; если ошибки не было 
	inc di
	cmp di, 4				; если ошибок меньше 4
	jl read_another			; пытаемся прочитать ещё раз

	mov ah, 0xE				; иначе
	mov al, '!'				; символ, который выведется на экран при ошибке
	int 0x10				; прерывание для вывода на экран	
	jmp endless_loop		; уходим в бесконечный цикл

	no_error:
	xor di, di

	inc cl 					; инкрементируем сектор
	cmp cl, 0x12			; если сектор в диапазоне [1; 18]
	jle update_end			; инкрементировать координаты не нужно
	
	;инкрементируем координаты
	mov cl, 1				; начальное значение сектора 1
	inc dh					; инкрементируем номер головки т.к. переполнились
	
	cmp dh, 1				; если головка в диапазоне [0; 1] 
	jle update_end			; инкерментировать цилиндр не нужно

	xor dh, dh 				; иначе
	inc ch					; инкрементируем цилиндр
					  		; за его переполнением не следим
	update_end:			
							; обновляем селектор сегмента 
	mov si, es				; чтобы прочитать следующие 512 байт  
	add si, 0x20
	mov es, si 
	
	cmp si, 0x8000			; если селктор физический адрес не на 0x80000
	jg read_another			; продолжаем


lgdt [gdt_descriptor]		; устанавливаем GDTR - регистр, содержащий значение дескриптора GDT

mov eax, cr0				; выставляем бит номер 0 (PE, Protected Mode Enable) в регистре CR0
or	al, 1
mov	cr0, eax


jmp CODE_SEG:protected_mode_tramplin + 0x7C00	; Прыжком мы переходим в защищённый 32-битный режим,
												; но всё ещё находимся в коде, загруженном по адресу 0x7C00
endless_loop:
	jmp endless_loop

gdt_start:
	dq 0x0 					; null descriptor
	gdt_code:
		dw 0FFFFh			; лимит
		dw 0				; база сегмента
		db 0				; база сегмента
		db 10011010b		; access byte
		db 11001111b		; флаги + лимит
		db 0				; база сегмента
	gdt_data:
		dw 0FFFFh
		dw 0
		db 0
		db 10010010b		; также, но executable bit = 0
		db 11001111b
		db 0
gdt_end:

gdt_descriptor:						; Дескриптор GDT
	dw gdt_end - gdt_start - 1
	dd gdt_start + 0x20000			; Линейный адрес GDT в копии VBR

CODE_SEG equ gdt_code - gdt_start	; Определение констант
DATA_SEG equ gdt_data - gdt_start

[BITS 32]
protected_mode_tramplin:
	mov eax, DATA_SEG				; устанавливаем data segment registers
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	xor ax, ax						; устанавливаем стек
	mov esp, 0x20000
	jmp CODE_SEG:0x20200			; переходим в си


times 510-($-$$) db 0		; Добиваем размер загрузочного сектора в 510байт
dw 0xAA55					; И последние два байта загрузочного сектора в little endian
