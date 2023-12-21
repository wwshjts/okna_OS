#include "utils.h"
#include "kernel_allocator.h"
#include "page_broadcast.h"

void make_page_directory() {
    word* page_table = make_page_table();
    word* page_directory = kernel_calloc(1024, 4);
    turn_on_PDE(page_directory, 0, (word)page_table);
    setCr3((word)page_directory);
    setPGInCr0();
}

word* make_page_table() {
    word* page_table = kernel_calloc(1024, 4);
    for (int i = 0; i < 1024; i++){
        //page_table[i] = (0b111000000111) + (i * 4 * 1024);
        turn_on_PTE(page_table, i, i * 4 * 1024);
    }
    return page_table;
}

void turn_on_PTE(word* page_table, int i, word frame_address) {
    page_table[i] = (0b111000000111) + (frame_address); //12 right bit from frameAddress mast be 0
}

void turn_on_PDE(word* page_directory, int i, word table_address) {
    page_directory[i] = (0b111000000000) + (table_address); //12 right bit from Page Table Address mast be 0
}