#include"types.h"

void enable_page_translation();
void enable_large_page_translation();
word* make_page_table();
void turn_on_PTE(word* page_table, int i, word frame_address);
void turn_on_PDE(word* page_directory, int i, word table_address);