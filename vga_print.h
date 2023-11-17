#include "types.h"

#ifndef _VGA_PRINT_H
    #define _VGA_PRINT_H
    #define SCREEN_START 0xB8000
    #define SCREEN_SIZE 4000 // size in bytes
    #define WIDTH 80
    #define HEIGHT 25

    enum {BLACK, BLUE, GREEN, CYAN, RED, PURPLE, BROWN, GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_PURPLE, YELLOW, WHITE};


    void init_printer();

    void vga_clear_screen();

    void static update_x_y();

    void vga_print_char(char symbol);

    void vga_print_str(char* str);

    void print_num(int n);

    void print_hex(int n);

    void print(char* fmt, ...);

    int static to_address();
#endif
