#include"types.h"

#ifndef _UTILS_H
    #define _UTILS_H
    byte inb(hword port);
    void outb(hword port, byte data);
    void initialize_intel_8259A();
#endif