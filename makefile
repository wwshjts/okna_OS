.PHONY: all

all: boot

boot: boot.img boot.bin kernel.bin
	dd if=/dev/zero of=boot.img bs=1024 count=1440
	dd if=boot.bin of=boot.img conv=notrunc
	dd if=kernel.bin of=boot.img conv=notrunc seek=1

boot.bin: boot.asm
	nasm -fbin boot.asm -o boot.bin
