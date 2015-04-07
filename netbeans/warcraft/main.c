/* 
 * File:   main.c
 * Author: astronaut
 *
 * Created on 6 апреля 2015 г., 17:40
 */

#include <stdio.h> // стандарнтый ввод вывод
#include <stdlib.h>
#include <unistd.h> // доступ к POSIX различные основные ф-ии конс-ты
#include <sys/types.h> // C POSIX с различными типами данных
#include <sys/wait.h>
#include <fcntl.h>

#define WORKERS 5
#define GOLD 15000

void mine_init(void);

int main(void)
{
	int i, pid[WORKERS], stat, status;

	// инициализации шахты
	mine_init();
	exit(1);

	for (i = 0; i < 5; i++) // создаем процессы рабочих
	{
		pid[i] = fork(); // порождаем дочерний процесс

		if (pid[i] == 0) {
			if (execl("./worker", "worker", NULL) < 0) // запускаем файл рабочего
			{
				printf("Ошибка во время запуска файла/процееса\n");
				exit(-2);
			} else {
				printf("Процесс-файл запущен pid=%d\n", pid[i]);
			}
			// выход из процесса
		}
	}

	for (i = 0; i < 5; i++) {
		status = waitpid(pid[i], &stat, WUNTRACED);
		if (pid[i] == status) {
			printf("рабочий №%d(pid:%d) закончил работу\n", i + 1, pid[i]);
		}
	}

	int q;
	FILE *fp = fopen("mine", "r");
	fread(&q, sizeof(int), 1, fp);
	printf("золота в шахте осталось %d\n", q);
	fclose(fp);

	return 0;
}

// инициализация шахты

void mine_init(void)
{
	int gold = GOLD;
	int x;
	int fd_mine;

	fd_mine = open("mine", O_RDWR);
	if (fd_mine < 0) {
		fd_mine = open("mine", O_CREAT);
	}

	lseek(fd_mine, 0L, 0);
	write(fd_mine, &gold, sizeof(int));

	lseek(fd_mine, 0L, 0);
	read(fd_mine, &x, sizeof(int));
	printf("стало - %d\n", x);

	close(fd_mine);
}