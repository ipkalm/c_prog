#include <stdio.h>

#define SIZE 10

int main(int argc, char *argv[]) {

  int symbol, i, nwhite, nother;
  int ndigit[SIZE] = { 0 };

  nwhite = nother = 0;

  /* for (i = 0; i < SIZE ; ++i) */
  /*   ndigit[i] = 0; */

  while ((symbol = getchar()) != EOF) {
    if (symbol >= '0' && symbol <= '9')
      ++ndigit[symbol - '0'];
    else if (symbol == ' ' || symbol == '\n' || symbol == '\t')
      ++nwhite;
    else
      ++nother;
  }

  printf("digits = ");
  for (i = 0; i < SIZE; ++i)
    printf("%d", ndigit[i]);

  printf(", separator-scharacters = %d, other symbols = %d\n", nwhite, nother);
  
  return 0;
}
