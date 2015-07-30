// copyright 2015

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
  int val;                  /* значение для SETVAL */
  struct semid_ds *buf;     /* буферы для  IPC_STAT, IPC_SET */
  unsigned short *array;    /* массивы для GETALL, SETALL */
  /* часть, особенная для Linux: */
  struct seminfo *__buf;    /* буфер для IPC_INFO */
};

int main(int argc, char *argv[]) {
  pid_t pid;
  key_t key;
  int semid;
  union semun arg;
  struct sembuf lock_res = {0, -1, 0};
  struct sembuf rel_res = {0, 1, 0};
  struct sembuf push[2] = {1, -1, IPC_NOWAIT, 2, 1, IPC_NOWAIT};
  struct sembuf pop[2] = {1, 1, IPC_NOWAIT, 2, -1, IPC_NOWAIT};
  int i;
  unsigned int seedp;

  if (argc < 2) {
    printf("Usage: bufdemo [dimension]\n");
    exit(0);
  }
  /* семафоры */
  key = ftok("/etc/fstab", getpid());

  /* создать набор из 3-х семафоров */
  semid = semget(key, 3, 0666 | IPC_CREAT);

  /* установить в семафре номер 0 (контроллер ресурсов)
     значение "1" */
  arg.val = 1;
  semctl(semid, 0, SETVAL, arg);

  /* установить в семафре номер 1 (контроллер свободного места)
     значение длины буфера */
  arg.val = atoi(argv[1]);
  semctl(semid, 1, SETVAL, arg);

  /* установить в семафре номер 2 (контроллер элементов в буфере)
     значение "0" */
  arg.val = 0;
  semctl(semid, 2, SETVAL, arg);

  /* fork */
  for (i = 0; i < 5; i++) {
    pid = fork();
    if (!pid) {
      for (i = 0; i < 20; i++) {
        sleep(rand_r(&seedp)%6);
        /* попытаться заблокировать ресурс семафор 0 */
        if (semop(semid, &lock_res, 1) == -1) {
          perror("semop:lock_res");
        }
        /* уменьшить свободное место  семафор 1
           добавить элемент семафор 2 */
        if (semop(semid, &push, 2) != -1) {
          printf("---> process: %d\n", getpid());
        } else {
          printf("---> process:%d BUFFER FULL\n", getpid());
        }
        /* разблокировать ресурс */
        semop(semid, &rel_res, 1);
      }
      exit(0);
    }
  }

  for (i = 0; i < 100; i++) {
    sleep(rand_r(&seedp)%3);
    /* попытаться заблокировать ресурс (семафор 0) */
    if (semop(semid, &lock_res, 1) == -1) {
      perror("semop:lock_res");
    }
    /* увеличить свободное место (семафор 1)
       взять элемет (семафор 2) */
    if (semop(semid, &pop, 2) != -1) {
      printf("<---- process:%d\n", getpid());
    } else {
      printf("<---- process:%d BUFFER EMPTY\n", getpid());
    }
    semop(semid, &rel_res, 1);
  }

  /* удалить семафоры */
  semctl(semid, 0, IPC_RMID);

  return 0;
}
