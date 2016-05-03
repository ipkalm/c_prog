#include <stdio.h>

struct fish {
  const char * name;
  const char * species;
  int teeth;
  int age;
};

int main() {

  struct fish snappy = {"Зубастик", "пиранья", 69, 4};

  printf("Кличка = %s\n", snappy.name);

  return 0;
}
