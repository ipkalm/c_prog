#include <stdio.h>

int main(int argc, char *argv[]) {

  unsigned int symbol;
  unsigned int counter;

  counter = 0;

  while ((symbol = getchar()) != EOF) {
    if (symbol == '\t' || symbol == ' ' || symbol == '\n') {
      ++counter;
    }
    else {
      if (counter > 0) {
        putchar('\n');
        counter = 0;
      }
      putchar(symbol);
    }
  }

  return 0;
}
