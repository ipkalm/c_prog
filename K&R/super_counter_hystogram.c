#include <stdio.h>

#define SIZE 10
#define HISTOGRAM_WIDTH 100

unsigned int range_line(unsigned int symbol, unsigned int all);

int main(int argc, char *argv[]) {

  int i;
  int j;

  int symbol;
  unsigned int other;
  unsigned int white;
  unsigned int all;

  unsigned int digits[SIZE] = { 0 };

  other = white = all = 0;

  while ((symbol = getchar()) != EOF) {
    ++all;
    if (symbol == ' ' || symbol == '\t' || symbol == '\n')
      ++white;
    else if (symbol >= '0' && symbol <= '9')
      ++digits[symbol - '0'];
    else
      ++other;
  }

  /* for (i = 0; i < SIZE; ++i) */
  /*   printf("digit %d    |%6u\n", i, digits[i]); */

  /* printf("separators |%6u\nother      |%6u\nall %u\n", white, other, all); */

  for (i = 0; i < SIZE; ++i) {
    printf("digit %4d : ", i);
    for (j = 0; j < range_line(digits[i], all); ++j)
      putchar('*');
    putchar('\n');
  }

  printf("separators : ");
  for (i = 0; i < range_line(white, all); ++i)
    putchar('*');
  putchar('\n');

  printf("other      : ");
  for (i = 0; i < range_line(other, all); ++i)
    putchar('*');
  putchar('\n');

  return 0;
}

unsigned int range_line(unsigned int symbol, unsigned int all) {
  return symbol * HISTOGRAM_WIDTH / all;
}
