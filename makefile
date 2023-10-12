.PHONY: all

all: boot

boot: boot.bin kernel.bin
	dd if=/dev/zero of=boot.img bs=1024 count=1440
	dd if=boot.bin of=boot.img conv=notrunc
	dd if=kernel.bin of=boot.img conv=notrunc seek=1

kernel.bin: kernel.c
	gcc -m32 -ffreestanding -c -o kernel.o kernel.c
	ld -m i386pe -o kernel.tmp -Ttext 0x20200 kernel.o
	objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

boot.bin: boot.asm
	nasm -fbin boot.asm -o boot.bin
