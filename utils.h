#include"types.h"

#ifndef _UTILS_H
    #define _UTILS_H
    void cli();
    void sti();
    void memzero(byte* start, int size);
    void memcpy(byte* from, byte* to, int size);
    void kernel_panic(const char* fmt, int vector);
    void setPGInCr0();
    void setPSEInCr4();
    void setCr3(word cr3);
#endif
