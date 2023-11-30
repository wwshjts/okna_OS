#include "intel_8259A.h"

#define MASTER_COMMAND 0x20
#define MASTER_DATA 0x21
#define SLAVE_COMMAND 0xA0
#define SLAVE_DATA 0xA1
#define DIAGNOSTIC_PORT_BIOS 0x80


void initialize_intel_8259A(){
    outb(MASTER_COMMAND, 0b00010001); //ICW1
    outb(DIAGNOSTIC_PORT_BIOS, 0); //Синхронизация
    outb(MASTER_DATA, 0x20); //ICW2
    outb(DIAGNOSTIC_PORT_BIOS, 0);
    outb(MASTER_DATA, 0b00000100); //ICW3
    outb(DIAGNOSTIC_PORT_BIOS, 0);
    outb(MASTER_DATA, 0b00000001); //ICW4

    outb(SLAVE_COMMAND, 0b00010001); //ICW1
    outb(DIAGNOSTIC_PORT_BIOS, 0);
    outb(SLAVE_DATA, 0x28); //ICW2
    outb(DIAGNOSTIC_PORT_BIOS, 0);
    outb(SLAVE_DATA, 2); //ICW3
    outb(DIAGNOSTIC_PORT_BIOS, 0);
    outb(SLAVE_DATA, 0b00000001); //ICW4

    outb(0x21, 0b11111001); //маска IRQ
    outb(0xA1, 0b11111111); // 0 - включён, 1 - выключен
}