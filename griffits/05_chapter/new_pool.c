#include <stdio.h>
#include "new_pool.h"

int main() {

  struct fish snappy = {"Зубастик", "пиранья", 0,0, {{"мясо", 0.09}, {"купаться в джакузи", 7.5}}};
  label(snappy);

  return 0;
}

void label(struct fish f) {
  printf("Кличка: %s\nРазновидность: %s\n%i года, %i зубов\nДавать %2.2f кг %s и разрешать %s на протяжении %2.2f часов\n",
      f.name, f.species, f.age, f.teeth, 
      f.care.food.weight, f.care.food.ingredients, 
      f.care.exercise.description, f.care.exercise.duration);
}
