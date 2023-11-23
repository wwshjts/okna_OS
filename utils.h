#include"types.h"

#ifndef _UTILS_H
    #define _UTILS_H
    void cli();
    void sti();
    byte inb(hword port);
	void outb(hword port, byte data);
    void memzero(byte* start, int size);
    void memcpy(byte* from, byte* to, int size);
    void kernel_panic(const char* fmt, int vector);
    void initialize_intel_8259A();
#endif
