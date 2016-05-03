#include <stdio.h>
#include "orders.h"

int main() {

  fruit_order apples = {"яблок", "Англия", .amount.count = 144, COUNT};

  fruit_order strawberries = {"клубники", "Испания", .amount.weight = 17.6, POUNDS};

  fruit_order oj = {"апельсниново сока", "США", .amount.volume = 10.5, PINTS};

  display(apples);
  display(strawberries);
  display(oj);

  return 0;
}

void display(fruit_order order) {
  printf("Этот заказ содержит ");

  if (order.units == PINTS)
    printf("%2.2f пинт %s\n", order.amount.volume , order.name);
  else if (order.units == POUNDS)
    printf("%2.2f фунтов %s\n", order.amount.weight, order.name);
  else
    printf("%i %s\n", order.amount.count, order.name);
}
