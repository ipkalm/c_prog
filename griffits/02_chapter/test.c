#include <stdio.h>

int main() {
  char food[5];
  
  printf("Введите любимую еду: ");
  fgets(food, sizeof(food), stdin);
  printf("Вы ввели: %s\n", food);

  return 0;
}
