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
	print(&x, &y, "%d is good %x is better %s", 12, 12, "Hello, world");
	/*
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < i; j++) {
			print(&x, &y, " ", 0);      //!!!
		}
	print(&x, &y, "%d\n", i);
	}
	*/
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
	*((byte*)(to_address(x,y) + 1)) = WHITE;
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
      *((hword*)(SCREEN_START + i)) = *((hword*)(SCREEN_START + i + 160));
    }
    for(int i = 3840; i < 4000; i++){
      *((hword*)(SCREEN_START + i)) = 0;
    }
  }
  //TODO понять что это такое
  //*((hword*)(SCREEN_START + 2*((*y)*80 + (*x)))) = '|';
  //*((hword*)(SCREEN_START + 2*((*y)*80 + (*x)) + 1)) = 143;
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

//TODO реализовать нормальный va_list
void print(int* x, int* y, byte* fmt, ...){//va_list
	byte** arg_ptr = &fmt + 1;
	byte arg_flag = 0;
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
						vga_print_char(*(str++), *x, *y);
						update_x_y(x,y);
					}
					arg_ptr++;
				break;
				//TODO подумать над % без экранирования
			}
		}
		else{
			vga_print_char(*fmt, *x, *y);
			update_x_y(x, y);
		}
		fmt++;
	}
	/*
  for(int i = 0; fmt[i] != 0; i++){
    switch (fmt[i]){
    case '%':
      i++;
      if (fmt[i] != 0){
        switch (fmt[i]){
        case 's':
			byte* str = *(arg_ptr + args);
          for(int j = 0; str[j] != 0; j++){
            vga_print_char(str[j], *x, *y);
            update_x_y(x, y);
          }
			args++;
          break;

        case 'd':
          print_num(x, y, *(arg_ptr + args));
		  args += 1;
          break;

        case 'x':
          print_hex(x, y, *(arg_ptr + args));
			args+=1;
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
  */
}
