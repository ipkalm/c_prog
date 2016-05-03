#include <stdio.h>

int main(int argc, char *argv[]) {

  int symbol;

  while ((symbol = getchar()) != EOF) {
    if (symbol == '\t') {
      putchar('\\');
      putchar('t');
    }
    else if (symbol == '\b') {
      putchar('\\');
      putchar('b');
    }
    else if (symbol == '\\') {
      putchar('\\');
      putchar('\\');
    }
    else {
      putchar(symbol);
    }
  }

  return 0;
}
