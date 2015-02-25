#include <Stdio.h>
#include <stdlib.h>

int main()
{
  char card_name[3];
  puts("Введите название карты: ");
  scanf("%2s", card_name);
  int val = 0;
  int count = 0;
  
  if (card_name[0] == 'K'){
    val = 10;
  } else if (card_name[0] == 'Q'){
    val = 10;
  } else if (card_name[0] == 'J'){
    val = 10;
  } else if (card_name[0] == 'A'){
    val = 11;
  } else {
    val = atoi(card_name);
  }

  if ((3<=val) && (val<=6)){
    count++;
    puts("Счетчик увеличился");
  } else if (val == 10){
    count--;
    puts("Счетчик уменьшился");
  }
  
  return 0;
}
