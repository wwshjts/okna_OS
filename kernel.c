#ifndef _TYPES_H
    #include"types.h"
#endif

#ifndef _UTILS_H
    #include"utils.h"
#endif
#include"vga_print.h"

void kernel() {
    init_printer();
    //print("%d is good %x is better %s\n", 12, 12, "Hello, world");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < i; j++) {
            print(" ");
        }
        print("%d\n", i);
    }
    for(;;);
}
