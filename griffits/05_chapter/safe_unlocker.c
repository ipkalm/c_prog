#include <stdio.h>
#include "safe_unlocker.h"

int main() {
  
  swag gold = { "ЗОЛОТО!", 1000000.0 };
  combination numbers = { &gold, "6502" };
  safe s = { numbers, "RAMACON250" };

  s.numbers.swag->description;

  return 0;
}
