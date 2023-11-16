.PHONY: all clear

obj = utils.o vga_print.o

all: boot

boot: boot.bin kernel.bin
	dd if=/dev/zero of=boot.img bs=1024 count=1440
	dd if=boot.bin of=boot.img conv=notrunc
	dd if=kernel.bin of=boot.img conv=notrunc seek=1

kernel.bin: kernel.c utils.o vga_print.o
	gcc -m32 -ffreestanding -c -o  kernel.o -fno-pic kernel.c 
	ld -m i386pe -o kernel.tmp -Ttext 0x20200 kernel.o utils.o vga_print.o
	objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

utils.o:
	gcc -m32 -ffreestanding -c -o  utils.o -fno-pic utils.c

vga_print.o: 
	gcc -m32 -ffreestanding -c -o  vga_print.o -fno-pic vga_print.c

boot.bin: boot.asm
	nasm -fbin boot.asm -o boot.bin

clear :
	rm -f  $(obj)
