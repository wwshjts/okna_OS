#include "utils.h"
#include "kernel_allocator.h"
#include "page_translation.h"

void enable_page_translation() {
    word* page_directory = kernel_calloc(1024, 4);
    word* page_table = kernel_calloc(1024, 4);
    for (int i = 0; i < 1024; i++){
        page_table[i] = (0b000000000111) | (i * 4 * 1024); //12 right bit from frame address mast be 0
    }
    page_directory[0] = (0b000000000111) | ((word)page_table); //12 right bit from Page Table Address mast be 0
    setCr3((word)page_directory);
    setPGInCr0();
}

void enable_large_page_translation() {
    word* page_directory = kernel_calloc(1024, 4);
    page_directory[0] = (0b000000000000010000111) | (0); //22 right bit from frame address mast be 0
    setCr3((word)page_directory);
    setPSEInCr4();
    setPGInCr0();
}

void turn_on_PTE(word* page_table, int i, word frame_address) {
    page_table[i] = (0b111) | (frame_address); //12 right bit from frameAddress mast be 0
    invlPG(frame_address);
}

void turn_on_PDE(word* page_directory, int i, word table_address) {
    page_directory[i] = (0b111) | (table_address); //12 right bit from Page Table Address mast be 0
}

void turn_on_PDE_large_page(word* page_directory, int i, word frame_address) {
    page_directory[i] = (0b10000111) | (frame_address); //22 right bit from frame address mast be 0
    invlPG(frame_address);
}