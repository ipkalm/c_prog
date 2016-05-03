#include <stdio.h>

int main() {
  
  float lon;
  float lat;
  char info[80];

  while (scanf("%f,%f,%79[^\n]", &lon, &lat, info) == 3)
    if ((lon > 25) && (lon < 35))
      if ((lat > -76) && (lat < -64))
        fprintf(stdout, "%f,%f,%s\n", lon, lat, info);

  return 0;
}
