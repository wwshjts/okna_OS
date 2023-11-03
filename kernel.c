#define SCREEN_START 0xB8000
//screen size in byte
#define SCREEN_SIZE 4000
#define WIDTH 80
#define HEIGHT 25

enum {BLACK, BLUE, GREEN, CYAN, RED, PURPLE, BROWN, GRAY, DARK_GRAY, LIGHT_BLUE, 
    LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_PURPLE, YELLOW, WHITE};

typedef unsigned char byte; 
typedef unsigned short int hword;

void kernel() {
    //TODO x y  - global
    int x, y;
    init_printer(&x, &y);
    //print(&x, &y, "%d is good %x is better %s", 12, 12, "Hello, world");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < i; j++) {
            print(&x, &y, " ");
        }
        print(&x, &y, "%d\n", i);
    }
    for(;;);
}

void memzero(int start, int size){
    for(int i = 0; i < size; i += 2){
        *((hword*)(SCREEN_START + start + i)) = 0;
    }
}

void memcpy(int form, int to, int size){
    for(int i = 0; i < size; i += 2){
        *((hword*)(SCREEN_START + to + i)) = *((hword*)(SCREEN_START + form + i));
    }
}

//0xB8000 + 2*(y*80 + x) - точка (x, y) на экране
//Кодировка отображения символа - 1 бит мигание, 3 бита цвет заднего фона, 4 переднего, 8 кодa символа
//80 - столбцов 25 - строчек
int to_address(int x, int y){
    return SCREEN_START + 2*(y*WIDTH + x);
}
 // очистка экрана
void vga_clear_screen(){
    memzero(0, SCREEN_SIZE);
}

// печать символа в позиции (x, y)
void vga_print_char(unsigned char symbol, int* x, int* y){
    *((byte*)(to_address(*x, *y))) = symbol;
    //TODO полубайт
    *((byte*)(to_address(*x, *y) + 1)) = WHITE;
    update_x_y(x, y);
}

//очищает экран и запускает печать с координаты (0, 0)
void init_printer(int *x, int* y){
    vga_clear_screen();
    *x = 0;
    *y = 0;
}

void update_x_y(int* x, int* y){
    (*x)++;
    *y += (*x) / WIDTH; //x out of line
    *x = *x % WIDTH;
    if ((*y) > 24){
        (*y)--;
        memcpy(2*WIDTH, 0, SCREEN_SIZE - 2*WIDTH);
        memzero(SCREEN_SIZE - 2*WIDTH, 2*WIDTH);
    }
    //*((byte*)(SCREEN_START + 2*((*y)*80 + (*x)))) = '|';
    //*((byte*)(SCREEN_START + 2*((*y)*80 + (*x)) + 1)) = 143;
}

void print_num(int* x, int* y, int n){
    if (n < 0){
        vga_print_char('-', x, y);
        n = -n;
    }
    if (n > 9){
        print_num(x, y, n / 10);
    }
    vga_print_char((n % 10) + 48, x, y);
}

void print_hex(int* x, int* y, int n){
    if (n < 0){
        vga_print_char('-', x, y);
        n = -n;
    }
    if (n > 15){
        print_hex(x, y, n / 16);
    }
    int a = n % 16;
    if (a > 9){
        vga_print_char(a + 87, x, y);
    }else{
        vga_print_char(a + 48, x, y);
    }
}

//printf c ограниченным набором спецификаторов формата
//%s - строка, %d - 32-битное десятичное, %x - 32-битное шестнадцатиричное
//При достижении конца экрана текст сдвигается вверх на одну строку
//TODO реализовать нормальный va_list
void print(int* x, int* y, char* fmt, ...){
    byte** arg_ptr = &fmt + 1;
    while(*fmt) {
        if( (*fmt == '%') && (*(fmt + 1))){
            fmt++;
            switch (*fmt){
            case 'd':
                print_num(x, y, *(arg_ptr));
                arg_ptr++;
            break;
            case 'x':
                print_hex(x,y, *(arg_ptr));
                arg_ptr++;
            break;
            case 's':
                byte* str = *arg_ptr;
                while(*str){
                    vga_print_char(*(str++), x, y);
                }
                arg_ptr++;
            break;
            //TODO подумать над % без экранирования
            }
        }
        else if (*fmt == '\n'){
            *((hword*)(to_address(*x, *y))) = 0;
            (*y)++;
            (*x) = -1;
            update_x_y(x, y);
        }else{
           vga_print_char(*fmt, x, y);
        }
        fmt++;
    }
}
