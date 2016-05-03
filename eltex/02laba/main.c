#include <stdio.h>
#include <string.h>
#include <time.h>

void display(char *array[], int size);
void swap(char **a, char **b);
void bublesort(char *array[], int size);

char *array[] = {
  "Привет, мир",
  "Всё хорошо, что хорошо кончается",
  "I'll be back",
  "I'll be master",
  "Who is your daddy?",
  "My woman from Tokio",
  "Всё пропало! Три магнитофона!"
};

const int size = 7;

int main(int argc, char *argv[])
{
  long int start, end;

  printf("\n\tBEFORE SORT:\n");
  display(array, size);
  
  start = clock();
  bublesort(array, size);
  end = clock();

  printf("\n\n\tAFTER SORT:\n");
  display(array, size);

  printf("\nTikov bublesort = %li\n", end - start);

  return 0;
}

void bublesort(char *array[], int size) 
{
  int i, j;
  
 for(i = 0; i < size - 1; i++)
    for(j = i + 1; j < size; j++)
      if (strcmp(array[i], array[j]) > 0)
        swap(&array[i], &array[j]);
}

void swap(char **a, char **b)
{
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

void display(char *array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%s\n", array[i]);
}
