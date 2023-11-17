#include"types.h"
#include"vga_print.h"
void cli();

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