#include <stdio.h>
#include "pool_puzzle.h"

int main() {

  struct fish snappy = {"Зубастик", "пиранья", 69, 4};

  catalog(snappy);
  label(snappy);

  return 0;
}

void catalog(struct fish f) {
  printf("%s, - это %s с %i зубами. Ему %i года.\n", f.name, f.species, f.teeth, f.age);
}

void label(struct fish f) {
  printf("Кличка: %s\nРазновидность: %s\n%i года, %i зубов\n", f.name, f.species, f.age, f.teeth);
}
