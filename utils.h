#ifndef _TYPES_H
    #include"types.h"
#endif
#define _UTILS_H

void cli();
void sti();
void memzero(byte* start, int size);
void memcpy(byte* from, byte* to, int size);
void kernel_panic(const char* fmt, int vector);
