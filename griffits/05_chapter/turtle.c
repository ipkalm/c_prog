#include <stdio.h>
#include "turtle.h"

int main () {
  
  turtle myturtle = {"Тортилла", "Кожистая черепаха", 99};

  happy_birthday(&myturtle);
  printf("%s прожила %i лет\n", myturtle.name, myturtle.age);

  return 0;
}

void happy_birthday(turtle *t) {
  t->age = t->age + 1;
  printf("С днём рождения, %s! Теперь тебе %i лет!\n",
      t->name, t->age);
}
