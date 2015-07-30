// copyright 2015

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

union semun {
  int val;                  /* значение для SETVAL */
  struct semid_ds *buf;     /* буферы для  IPC_STAT, IPC_SET */
  unsigned short *array;    /* массивы для GETALL, SETALL */
  /* часть, особенная для Linux: */
  struct seminfo *__buf;    /* буфер для IPC_INFO */
} arg;


int main(void) {
  key_t key;
  int semid;

  key = ftok("/etc/fstab", getpid());

  /* create only one semaphore */
  semid = semget(key, 1, 0666 | IPC_CREAT);

  /* в семафоре 0 установить значение 1 */
  arg.val = 1;
  semctl(semid, 0, SETVAL, arg);

  sleep(10);
  
  /* удалить семафор */
  semctl(semid, 0, IPC_RMID);

  return 0;
}
