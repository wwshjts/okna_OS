#define SCREEN_START 0xB8000
//screen size in hword (2 byte)
#define SCREEN_SIZE 4000 
#define WIDTH 80
#define HEIGHT 25

enum {BLACK, BLUE, GREEN, CYAN, RED, PURPLE, BROWN, GRAY, DARK_GRAY, LIGHT_BLUE, 
	LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_PURPLE, YELLOW, WHITE};

typedef unsigned char byte; 
typedef unsigned short int hword;

void kernel() {
	//vga_clear_screen()
	//vga_print_str("Hello, world!", 32, 12);
	int x, y;
	init_printer(&x, &y);
	x++;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < i; j++) {
			print(&x, &y, " ", 0);      //!!!
		}
	print(&x, &y, "%d\n", i);
	}
	for(;;);
}

//0xB8000 + 2*(y*80 + x) - точка (x, y) на экране
//Кодировка отображения символа - 1 бит мигание, 3 бита цвет заднего фона, 4 переднего, 8 кодa символа
//80 - столбцов 25 - строчек
int to_address(int x, int y){
	return SCREEN_START + 2*(y*WIDTH + x);
}
 // очистка экрана
void vga_clear_screen(){
	for(int i = 0; i < SCREEN_SIZE; i++){          // 4000 = 2 * 25 * 80
		*((hword*)(SCREEN_START + i)) = 0;
	}
}

// печать символа в позиции (x, y)
void vga_print_char(unsigned char symbol, int x, int y){
	*((byte*)(to_address(x,y))) = symbol;
	*((byte*)(to_address(x,y) + 1)) = YELLOW;
}

// печать строки, начиная с позиции (x, y)
void vga_print_str(unsigned char* str, int x, int y){
  for(int i = 0; str[i] != 0; i++){
    vga_print_char(str[i], x, y);
    x++;
    if (x > 79){
      x -= 79;
      y++;
    }
  }
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
    for(int i = 0; i < 3840; i++){
      *((short int*)(SCREEN_START + i)) = *((short int*)(SCREEN_START + i + 160));
    }
    for(int i = 3840; i < 4000; i++){
      *((short int*)(SCREEN_START + i)) = 0;
    }
  }
  //TODO понять что это такое
  *((short int*)(SCREEN_START + 2*((*y)*80 + (*x)))) = '|';
  *((short int*)(SCREEN_START + 2*((*y)*80 + (*x)) + 1)) = 143;
}

void print_num(int* x, int* y, int n){
  if (n < 0){
    vga_print_char('-', *x, *y);
    update_x_y(x, y);
    n = -n;
  }
  if (n > 9){
    print_num(x, y, n / 10);
  }
  vga_print_char((n % 10) + 48, *x, *y);
  update_x_y(x, y);
}

void print_hex(int* x, int* y, int n){
  if (n < 0){
    vga_print_char('-', *x, *y);
    update_x_y(x, y);
    n = -n;
  }
  if (n > 15){
    print_num(x, y, n / 16);
  }
  int a = n % 16;
  if (a > 9){
    vga_print_char(a + 87, *x, *y);
  }else{
    vga_print_char(a + 48, *x, *y);
  }
  update_x_y(x, y);
}

//printf c ограниченным набором спецификаторов формата
//%s - строка, %d - 32-битное десятичное, %x - 32-битное шестнадцатиричное
//При достижении конца экрана текст сдвигается вверх на одну строку
void print(int* x, int* y, unsigned char* fmt, int n){//va_list
  for(int i = 0; fmt[i] != 0; i++){
    switch (fmt[i]){
    case '%':
      i++;
      if (fmt[i] != 0){
        switch (fmt[i]){
        case 's':
          /*for(int j = 0; n[j] != 0; j++){
            vga_print_char(n[j], *x, *y);
            update_x_y(x, y);
          }*/
          break;

        case 'd':
          print_num(x, y, n);
          break;

        case 'x':
          print_hex(x, y, n);
          break;

        default:
          vga_print_char('%', *x, *y);
          update_x_y(x, y);
          vga_print_char(fmt[i], *x, *y);
          update_x_y(x, y);
          break;
        }
      }else{
        vga_print_char('%', *x, *y);
        update_x_y(x, y);
      }
      break;

    case '\n':
      *((short int*)(SCREEN_START + 2*((*y)*80 + (*x)))) = 0;
      *((short int*)(SCREEN_START + 2*((*y)*80 + (*x)) + 1)) = 0;
      (*y)++;
      (*x) = -1;
      update_x_y(x, y);
      break;

    default:
      vga_print_char(fmt[i], *x, *y);
      update_x_y(x, y);
      break;
    }
  }
}
