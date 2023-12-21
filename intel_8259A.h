#include"types.h"

#ifndef _intel_8259A_H
    #define _intel_8259A_H
    byte inb(hword port);
    void outb(hword port, byte data);
    void initialize_intel_8259A();
    void eoi(word);
    enum Device {
        Timer,
        Keyboard,
        Slave
    };
    void change_device(enum Device device, int change);
#endif