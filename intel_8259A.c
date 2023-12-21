#include "intel_8259A.h"

#define MASTER_COMMAND 0x20
#define MASTER_DATA 0x21
#define SLAVE_COMMAND 0xA0
#define SLAVE_DATA 0xA1
#define DIAGNOSTIC_PORT_BIOS 0x80


void initialize_intel_8259A(){
    outb(MASTER_COMMAND, 0b00010001); //ICW1
    outb(DIAGNOSTIC_PORT_BIOS, 0); //Synchronization
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

    outb(MASTER_DATA, 0b11111011); //mask IRQ
    outb(SLAVE_DATA, 0b11111111); // 1 - turn off, 0 - turn on
}

void eoi(word irq) {
    outb(MASTER_COMMAND, 0x20);
    if (irq >= 0x28) {
        outb(SLAVE_COMMAND, 0x20);
    }
}

void showMask() {
    byte mask = inb(MASTER_DATA);
    outb(DIAGNOSTIC_PORT_BIOS, 0);
    print("mask %x\n", mask);
}

//change: 1 - turn on, 0 - turn of
void change_device(enum Device device, int change){
    int shift;
    hword port = MASTER_DATA;
    switch (device){
    case Timer:
        shift = 0;
        break;
    case Keyboard:
        shift = 1;
        break;
    case Slave:
        shift = 2;
        break;
    }
    byte mask = inb(MASTER_DATA);
    if ((mask >> shift) & 1 == change){
        if (change){
            outb(port, mask - (1 << shift));
        } else {
            outb(port, mask + (1 << shift));
        }
    }
}