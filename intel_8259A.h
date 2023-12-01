#include"types.h"

#ifndef _intel_8259A_H
    #define _intel_8259A_H
    byte inb(hword port);
    void outb(hword port, byte data);
    void initialize_intel_8259A();
    enum Device {
        Timer,
        Keyboard,
        Slave
    };
    void changeDevice(enum Device device, int change);
#endif