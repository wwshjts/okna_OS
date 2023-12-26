.PHONY: all clear

obj = utils.o vga_print.o kernel_allocator.o interrupts.o nasm_utils.o intel_8259A.o \
	  tramplins.o interrupt_handlers.o page_translation.o

all: boot

boot: boot.bin kernel.bin
	dd if=/dev/zero of=boot.img bs=1024 count=1440
	dd if=boot.bin of=boot.img conv=notrunc
	dd if=kernel.bin of=boot.img conv=notrunc seek=1

kernel.bin: kernel.c $(obj) 
	gcc -m32 -ffreestanding -c -o  kernel.o -fno-pic kernel.c 
	ld -m i386pe -o kernel.tmp -Ttext 0x20200 kernel.o $(obj)
	objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

utils.o: utils.c
	gcc -m32 -ffreestanding -c -o  utils.o -fno-pic utils.c

vga_print.o: vga_print.c
	gcc -m32 -ffreestanding -c -o  vga_print.o -fno-pic vga_print.c

kernel_allocator.o: kernel_allocator.c
	gcc -m32 -ffreestanding -c -o  kernel_allocator.o -fno-pic kernel_allocator.c

interrupts.o : interrupts.c
	gcc -m32 -ffreestanding -c -o  interrupts.o -fno-pic interrupts.c

intel_8259A.o : intel_8259A.c
	gcc -m32 -ffreestanding -c -o  intel_8259A.o -fno-pic intel_8259A.c

page_translation.o : page_translation.c
	gcc -m32 -ffreestanding -c -o  page_translation.o -fno-pic page_translation.c

nasm_utils.o : nasm_utils.asm
	nasm -felf nasm_utils.asm -o nasm_utils.o

tramplins.o : tramplins.asm
	nasm -felf tramplins.asm -o tramplins.o

interrupt_handlers.o : interrupt_handlers.c
	gcc -m32 -ffreestanding -c -o  interrupt_handlers.o -fno-pic interrupt_handlers.c

boot.bin: boot.asm
	nasm -fbin boot.asm -o boot.bin

clear :
	rm -f  $(obj)
