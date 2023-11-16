#include"stddef.h" 
#include"types.h"
#define START_ADR 0x100000
#define STOP_ADR 0x400000
static byte* start = (byte*) START_ADR;
static byte* stop = (byte*) STOP_ADR;
static byte* offset = (byte*) START_ADR;

byte* kernel_malloc(word size){
    //TODO
    /*if(offset + size >= stop){
        return NULL;
    }*/
    byte* res = offset;
    offset += size;
    return res;
}

byte* kernel_calloc(word n, word size){
    /*TODO
    if(offset + n * size >= stop){
        return NULL;
    }*/
    byte* res = offset;
    offset += n * size;
    return res;
}

byte* kernel_realloc(void* old_addr, word new_size){
    return kernel_malloc(new_size);
}

void kernel_free(void* addr){}

