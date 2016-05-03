#include <stdio.h>


int main(int argc, char *argv[]) {

  int symbol;
  unsigned char counter = 0;

  while ((symbol = getchar()) != EOF) {
    if (symbol == ' ') {
      ++counter;
    } else {
      if (counter > 0) {
        putchar(' ');
        counter = 0;
      }
      putchar(symbol);
    }
  }

  return 0;
}
