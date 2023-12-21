#include"types.h"

void make_page_directory();
word* make_page_table();
void turn_on_PTE(word* page_table, int i, word frame_address);
void turn_on_PDE(word* page_directory, int i, word table_address);