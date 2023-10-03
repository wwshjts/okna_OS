#!/usr/bin/python
import sys
import os

ARGS_LEN = 2
KERNEL_SIZE = 324 * 2**10 - 512 

def get_check_sum(name:str) -> int:
    res = 0
    with open(name, 'rb') as fl:
        #Читаем один байт
        byte = fl.read(1)
        while byte:
            res += int.from_bytes(byte) 
            byte = fl.read(1)
    return res

if __name__ == "__main__":
    if len(sys.argv) > ARGS_LEN:
        print("Too many args")
        exit(1)

    res = os.system("make")
    if res > 0:
        print("Compilation error")
        exit(2)
    
    kernel_size = os.path.getsize('kernel.bin')
    if kernel_size > KERNEL_SIZE:
        print(f"Kernel is too big {kernel_size}\nrecommend size <{KERNEL_SIZE}")
        exit(1)
    
    check = get_check_sum("kernel.bin")
    check += get_check_sum("boot.bin")

    if len(sys.argv) < 2:
        os.system("qemu-system-i386 -monitor stdio boot.img") 
    elif sys.argv == "-d":
	    os.system("qemu-system-i386  boot.img -s -S -vnc  &")
    else:
        print("Unknown option")
        exit(3)

    

