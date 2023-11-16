#include"types.h"

byte* kernel_malloc(word size);
byte* kernel_calloc(word n, word size);
byte* kernel_realloc(void* old_addr, word new_size);
void kernel_free(void* addr);

