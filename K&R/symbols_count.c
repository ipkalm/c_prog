#include <stdio.h>

int main(int argc, char *argv[]) {
  /* long count = 0; */
  /* while (getchar() != EOF) */
  /*   ++count; */

  double count = 0;

  for ( ; getchar() != EOF; ++count)
    ;

  printf("%.0f\n",count);
  return 0;
}
