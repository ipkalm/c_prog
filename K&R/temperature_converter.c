#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  int far;
  int cel;

  far = LOWER;

  /*  printf("cel    far\n");
      while (far <= upper) {

      far = 9.0 * cel / 5 + 32;
      printf("%3d %6d\n", cel, far);
      cel += step;

      cel = 5.0 * (far-32) / 9;
      printf("%3.0f %6.1f\n", far, cel);
      far = far + step;
      }*/

  for (far = LOWER; far <= UPPER; far += STEP)
    printf("%3d %6.1f\n", far, (5.0/9)*(far-32));

  return 0;
}
