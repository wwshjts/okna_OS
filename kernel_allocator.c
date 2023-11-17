#include"stddef.h" 
#include"types.h"
#include"utils.h"
#define START_ADR 0x100000
#define STOP_ADR 0x400000
#define OUT_OF_MEM_CODE 0x42
static byte* start = (byte*) START_ADR;
static byte* stop = (byte*) STOP_ADR;
static byte* offset = (byte*) START_ADR;

byte* kernel_malloc(word size){
    if(offset + size >= stop){
        kernel_panic("Run out of memory", OUT_OF_MEM_CODE);
    }
    byte* res = offset;
    offset += size;
    return res;
}

byte* kernel_calloc(word n, word size){
    if(offset + n * size >= stop){
        kernel_panic("Run out of memory", OUT_OF_MEM_CODE);
    }
    byte* res = offset;
    memzero(res, size);
    offset += n * size;
    return res;
}


byte* kernel_realloc(void* old_addr, word old_size, word new_size){
    byte* new_addr = kernel_malloc(new_size);
    memcpy(old_addr, new_addr, old_size);
    kernel_free(old_addr);
    return new_addr;
}


void kernel_free(void* addr){}

