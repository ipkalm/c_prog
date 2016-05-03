#include <stdio.h>

void go_south_east(int *lat, int *lon);

int main() {
  int latitude = 32;
  int longtitude = -64;

  go_south_east(&latitude, &longtitude);

  printf("Стоп! Теперь наши координаты: [%i, %i]\n", latitude, longtitude);
  return 0;
}

void go_south_east(int *lat, int *lon) {
  *lat = *lat - 1;
  *lon = *lon + 1;
}

