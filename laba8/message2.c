// copyright 2015
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

/* Redefines the message structure */
typedef struct mymsgbuf {
  long mtype;
  int num;
} mess_t;

int main(void) {
  int qid;
  key_t msgkey;
  pid_t pid;
  unsigned int seedp;
  mess_t buf;

  int length;
  int cont;

  length = sizeof(mess_t) - sizeof(long);

  msgkey = ftok(".", 'm');

  qid = msgget(msgkey, IPC_CREAT | 0660);

  if (!(pid = fork())) {
    printf("SON - QID = %d\n", qid);

    srand(time(0));

    for (cont = 0; cont < 10; cont++) {
      sleep(rand_r(&seedp)%4);
      buf.mtype = 1;
      buf.num = rand_r(&seedp)%100;
      msgsnd(qid, &buf, length, 0);
      printf("SON - MESSAGE NUMBER %d: %d\n", cont+1, buf.num);
    }

    return 0;
  }

  printf("FATHER - QID = %d\n", qid);

  for (cont = 0; cont < 10; cont++) {
    sleep(rand_r(&seedp)%4);
    msgrcv(qid, &buf, length, 1, 0);
    printf("FATHER - MESSAGE NUMBER %d: %d\n", cont+1, buf.num);
  }

  msgctl(qid, IPC_RMID, 0);

  return 0;
}
