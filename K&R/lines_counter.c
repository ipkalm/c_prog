#include <stdio.h>

int main(int argc, char *argv[]) {

  int count, symbol;

  count = 0;

  while ((symbol = getchar()) != EOF)
    if (symbol == '\n')
      ++count;

  printf("%d\n", count);

  return 0;
}
