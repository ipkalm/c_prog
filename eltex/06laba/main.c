/* везде будут использованы не библиотечные ф-ии для работы с файлами, а
 * системные вызовы к ядру Linux, такие как open(), create(), read(), write() */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void exec_worker();

int main() {

  /* дескрипторы для файлов шахты и базы */
  int base, mine;

  /* счетчик для цикла */
  register int i;

  /* статус процесса */
  int status;
  
  /* хранение PID */
  pid_t pid;

  /* значения для файлов */
  const unsigned int s_mine = 15000;
  const unsigned int s_base = 0;
  const unsigned int *m = &s_mine;
  const unsigned int *b = &s_base;

  printf("SIZEOF(UNSIGNED INT) = %lu bytes\n", sizeof(s_base));

  /* флаги и режимы файлов */
  mode_t mods = S_IWUSR | S_IRUSR;
  mode_t flags = O_WRONLY | O_CREAT | O_TRUNC;

  /* создаем и открываем файлы, если существует затираем старый
   * помещаем значение */
  base = open("base.bin", flags, mods);
  if (base < 0) {
    fprintf(stderr, "ошибка создания файла базы\n");
    return 1;
  }
  write(base, b, sizeof(*b));

  mine = open("mine.bin", flags, mods);
  if (mine < 0) {
    fprintf(stderr, "ошибка создания файла шахты\n");
    return 1;
  }
  write(mine, m, sizeof(*m));

  /* закрываем файлы */
  close(base);
  close(mine);

  /* форк пяти процессов */
  for (i = 0; i < 5; ++i)
    if ((pid = fork()) == 0)
      exec_worker();

  /* читаем статус дочерних процессов, если статус не "0", то стартуем его еще
   * раз, и так до тех пор пока дочерний процесс не вернет "0" */
  while ((pid = wait(&status)) > 0) {
    if ((status >> 8) != 0) {
      if ((pid = fork()) == 0) exec_worker();
    } else {
      printf("завершен процесс PID=%i, status=%i\n", pid, status >> 8);
    }
  }
  printf("Всё кончено!\n");

  return 0;
}

void exec_worker() {
  if (execl("./worker", "worker", NULL) < 0) {
    perror("ошибка при запуске дочернего процесса");
    exec_worker();
  }
}
