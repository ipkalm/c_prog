#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_write(FILE *in, FILE *out, unsigned int size);

int main(int argc, char *argv[]) {

  unsigned int size;
  char *name = 0;
  char ext[] = ".out";
  FILE *input, *output;

  // проверка правильного количества агрументов (тип их не проверяется)
  if (argc != 3) {
    fputs("INCORRECT LAUNCH\n", stderr);
    exit(-1);
  }

  // открываем входящий файл
  if ((input = fopen (argv[1], "r")) == NULL) {
    fputs("CANT OPEN FILE\n", stderr);
    exit(-1);
  }

  // получаем длину допустимой строки
  size = atoi(argv[2]);

  // выделяем память под имя нового файла с учетом расширения,
  // но без учета NAME_MAX
  name = (char *) malloc(sizeof(argv[1]) + sizeof(ext));

  // копируем аргумент в имя
  strcpy(name, argv[1]);

  // приращиваем новое расширение к имени
  name = strcat(name, ext);

  // проверяем чтобы введеный пользователем размер не превышал размер BUFSIZE
  if (size > BUFSIZ) {
    fputs("SIZE BIGGER THEN BUFSIZE\n", stderr);
    exit(-2);
  }

  // создаём файл для выходных данных
  output = fopen (name, "w");

  // освобождаем память выделенную под имя выходного файла
  free(name);

  read_write(input, output, size);

  // закрываем файлы
  fclose(input);
  fclose(output);

  return 0;
}

void read_write(FILE *input, FILE *output, unsigned int size) {

  char c;
  register unsigned int i = 0; // текущий символ в строке
  register unsigned short int state = 0; // если 0 то копируем символы, если 1 - то нет

  while ((c = fgetc(input)) != EOF) { // считывается текущий символ
    if (state == 0) { // если состояние 0 то
      fputc(c, output); // копируем символ в выходной поток
      i++; // инкрементируем порядковый номер текущего символа строки
      if (i >= size) { // если положение текущего символа выходит за пределы размера
        state = 1; // изменяем состояние, что бы отключить копирование
        fputc('\n', output); // записываем символ новой строки
      }
    }
    if (c == '\n') { // когда текущий символ будет равен символу новой строки
      i = 0; // изменяем порядковый номер на 0
      state = 0; // включаем состояние записи символов
    }
  }
}
