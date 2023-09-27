#!/bin/bash
#Флаг "-d" запускает виртуальную машину в удаленном режиме
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
	qemu-system-i386 -monitor stdio boot.img 
elif [ "$1" == "-d" ]; then
	qemu-system-i386  boot.img -s -S -vnc  &
else
	echo Unknown option "$1"
fi

