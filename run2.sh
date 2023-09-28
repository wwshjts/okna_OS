#!/bin/bash
if [ $# -gt 1 ]; then
	echo Too many args
	exit
fi

nasm -fbin boot.asm -o boot.bin

if [ $? -gt 0 ]; then
	echo Compilation error
	exit
fi

dd if=/dev/zero of=boot.img bs=1024 count=1440
dd if=boot.bin of=boot.img conv=notrunc


if [ $# -eq 0 ]; then
    bochs -f os.bxrc -q
else
	echo Unknown option "$1"
fi