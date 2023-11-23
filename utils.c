#include"types.h"
#include"vga_print.h"
#include"utils.h"

void memzero(byte* start, int size){
    for(int i = 0; i < size; i++){
        *(start + i) = 0;
    }
}

void memcpy(byte* from, byte* to, int size){
    for(int i = 0; i < size; i++){
        *(to + i) = *(from + i);
    }
}

void kernel_panic(const char* fmt, int vector){
    cli();
    init_printer();
    print(fmt, vector);
    for(;;);
}

/*
------ COMMAND DATA
Master  0x20   0x21
Slave   0xA0   0xA1
*/
void initialize_intel_8259A(){
    outb(0x20, 0b00010001); //ICW1
    outb(0x80, 0); //Синхронизация
    outb(0x21, 0x20); //ICW2
    outb(0x80, 0);
    outb(0x21, 0b00000100); //ICW3
    outb(0x80, 0);
    outb(0x21, 0b00000001); //ICW4

    outb(0xA0, 0b00010001); //ICW1
    outb(0x80, 0);
    outb(0xA1, 0x28); //ICW2
    outb(0x80, 0);
    outb(0xA1, 2); //ICW3
    outb(0x80, 0);
    outb(0xA1, 0b00000001); //ICW4

    outb(0x21, 0b11111001); //маска IRQ
    outb(0xA1, 0b11111111); // 0 - включён, 1 - выключен
}