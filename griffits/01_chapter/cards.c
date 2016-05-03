/*
 * Программа для оценивания важности карт.
 * Выпущено под публичной Лас-Вегаской лицензией.
 * © 2014 команда колледжа по блек-джеку.
 */

#include <stdio.h>
#include <stdlib.h>

int main() { 
  
  int val = 0;
  int count = 0;
  char card_name[3];

  while (card_name[0] != 'X') {
    puts("Введите название карты: ");
    scanf("%2s", card_name);

    switch (card_name[0]) {
      case 'J':
      case 'Q':
      case 'K':
        val = 10;
        break;
      case 'A':
        val = 11;
        break;
      case 'X':
        continue;
      default:
        val = atoi(card_name);
        if ((val < 2) || (val > 10)){
          puts("Некорректное значение");
          continue;
        }
    }

    if (val > 2 && val < 7)
      count++;
    else if (val == 10)
      count--;

    printf("Текущий счёт: %i\n", count);
  }
  
  return 0;
}
