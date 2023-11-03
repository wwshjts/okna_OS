#define SCREEN_START 0xB8000
//screen size in byte
#define SCREEN_SIZE 4000
#define WIDTH 80
#define HEIGHT 25

enum {BLACK, BLUE, GREEN, CYAN, RED, PURPLE, BROWN, GRAY, DARK_GRAY, LIGHT_BLUE, 
    LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_PURPLE, YELLOW, WHITE};

typedef unsigned char byte;
typedef unsigned short int hword;

int x, y;

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

void memzero(byte* start, int size){
    for(int i = 0; i < size; i++){
        *(start + i) = 0;
    }
}

void memcpy(byte* from, byte* to, int size){
    for(int i = 0; i < size; i++){
        *(to + i) = *(from + i);
    }
}

//0xB8000 + 2*(y*80 + x) - точка (x, y) на экране
//Кодировка отображения символа - 1 бит мигание, 3 бита цвет заднего фона, 4 переднего, 8 кодa символа
//80 - столбцов 25 - строчек
int to_address(){
    return SCREEN_START + 2*(y*WIDTH + x);
}

// очистка экрана
void vga_clear_screen(){
    memzero((byte*)SCREEN_START, SCREEN_SIZE);
}

// печать символа в позиции (x, y)
void vga_print_char(char symbol){
    *((byte*)(to_address())) = symbol;
    //TODO полубайт?
    *((byte*)(to_address() + 1)) = WHITE;
    update_x_y();
}

// печать строки
void vga_print_str(char* str){
    while(*str){
        vga_print_char(*(str++));
    }
}

//очищает экран и запускает печать с координаты (0, 0)
void init_printer(){
    vga_clear_screen();
    x = 0;
    y = 0;
}

void update_x_y(){
    x++;
    y += (x) / WIDTH; //x out of line
    x = x % WIDTH;
    if (y / HEIGHT){
        y--;
        memcpy(((byte*)(SCREEN_START + 2*WIDTH)), ((byte*)SCREEN_START), SCREEN_SIZE - 2*WIDTH);
        memzero(((byte*)SCREEN_START + SCREEN_SIZE - 2*WIDTH), 2*WIDTH);
    }
}

void print_num(int n){
    if (n < 0){
        vga_print_char('-');
        n = -n;
    }
    if (n > 9){
        print_num(n / 10);
    }
    vga_print_char((n % 10) + '0');
}

void print_hex(int n){
    if (n < 0){
        vga_print_char('-');
        n = -n;
    }
    if (n > 15){
        print_hex(n / 16);
    }
    int a = n % 16;
    if (a > 9){
        vga_print_char(a + 'a' - 10);
    }else{
        vga_print_char(a + '0');
    }
}

//printf c ограниченным набором спецификаторов формата
//%s - строка, %d - 32-битное десятичное, %x - 32-битное шестнадцатиричное
//При достижении конца экрана текст сдвигается вверх на одну строку
//TODO реализовать нормальный va_list
void print(char* fmt, ...){
    char** arg_ptr = &fmt + 1;
    while(*fmt) {
        if( (*fmt == '%') && (*(fmt + 1))){
            fmt++;
            switch (*fmt){
            case 'd':
                print_num(*(arg_ptr++));
            break;
            case 'x':
                print_hex(*(arg_ptr++));
            break;
            case 's':
                vga_print_str(*(arg_ptr++));
            break;
            case '%':
                vga_print_char(*(fmt));
            break;
            //TODO подумать над % без экранирования
            }
        }
        else if (*fmt == '\n'){
            *((hword*)(to_address())) = 0;
            y++;
            x = -1;
            update_x_y();
        }else{
           vga_print_char(*fmt);
        }
        fmt++;
    }
}
