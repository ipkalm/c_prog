#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "spies.h"

#define ANSWER 3
#define SUSPECT 40
#define QUESTION 80

int main() {

  char question[QUESTION];
  char suspect[SUSPECT];
  node * start_node = create("Носит ли подозреваемый усы?");
  start_node->no = create("Лоретта Барншворц");
  start_node->yes = create("Иван Ложкин");

  node * current;

  do {
    current = start_node;
    for(;;) {
      if (yes_no(current->question)) {
        if (current->yes) {
          current = current->yes;
        } else {
          printf("ПОДОЗРЕВАЕМЫЙ ОПОЗНАН\n");
          break;
        }
      } else if (current->no) {
        current = current->no;
      } else {
        // Присваиваем yes_node имя нового подозреваемого
        printf("Кто подозреваемый? ");
        fgets(suspect, SUSPECT, stdin);
        node * yes_node = create(suspect);
        current->yes = yes_node;

        // Присваиваем no_node копию этого вопроса
        node * no_node = create(current->question);
        current->no = no_node;

        // Затем заменяем этот вопрос на новый
        printf("Задайте мне вопрос, который подходит для %s, но не для %s. ", suspect, current->question);
        fgets(question, QUESTION, stdin);
        free(current->question);
        current->question = strdup(question);

        break;
      }
    }
  } while(yes_no("Выполнить еще раз? "));

  release(start_node);
  
  return 0;
}

int yes_no(char * question) {
  char answer[ANSWER];
  printf("%s (y/n): ", question);
  fgets(answer, ANSWER, stdin);
  return answer[0] == 'y';
}

node * create(char * question) {
  node * n = malloc(sizeof(node));
  n->question = strdup(question);
  n->yes = NULL;
  n->no = NULL;
  return n;
}

void release(node * n) {
  if (n) {
    if (n->no)
      release(n->no);
    if (n->yes)
      release(n->yes);
    if (n->question)
      free(n->question);
    free(n);
  }
}
