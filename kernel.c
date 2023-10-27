void kernel() {
  //vga_clear_screen()
  //vga_print_str("Hello, world!", 32, 12);

  int x, y;
  init_printer(&x, &y);
  for (int i = 0; i < 30; i++) {
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

 // очистка экрана
void vga_clear_screen(){
  for(int i = 0; i < 4000; i++){          // 4000 = 2 * 25 * 80
    *((short int*)(0xB8000 + i)) = 0;
  }
}

// печать символа в позиции (x, y)
void vga_print_char(unsigned char symbol, int x, int y){
  *((short int*)(0xB8000 + 2*(y*80 + x))) = symbol;
  *((short int*)(0xB8000 + 2*(y*80 + x) + 1)) = 15;
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
  if ((*x) > 79){
    (*x) -= 79;
    (*y)++;
  }
  if ((*y) > 24){
    (*y)--;
    for(int i = 0; i < 3840; i++){
      *((short int*)(0xB8000 + i)) = *((short int*)(0xB8000 + i + 160));
    }
    for(int i = 3840; i < 4000; i++){
      *((short int*)(0xB8000 + i)) = 0;
    }
  }
  *((short int*)(0xB8000 + 2*((*y)*80 + (*x)))) = '|';
  *((short int*)(0xB8000 + 2*((*y)*80 + (*x)) + 1)) = 143;
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
      *((short int*)(0xB8000 + 2*((*y)*80 + (*x)))) = 0;
      *((short int*)(0xB8000 + 2*((*y)*80 + (*x)) + 1)) = 0;
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