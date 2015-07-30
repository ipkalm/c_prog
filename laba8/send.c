// copyright 2015
/* send.c */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSZ     128

typedef struct msgbuf {
  long mtype;
  char mtext[MSGSZ];
} message_buf;

int main(void) {
  int msqid;
  int msgflg = IPC_CREAT | 0666;
  key_t key;
  message_buf sbuf;
  size_t buf_length;

  key = 10;

  printf("Calling msgget with key %#lx and flag %#o\n", key, msgflg);

  if ((msqid = msgget(key, msgflg)) < 0) {
    perror("msgget");
    exit(1);
  } else {
    printf("msgget: msgget succeeded: msqid = %d\n", msqid);
  }

  sbuf.mtype = 1;

  printf("msgget: msgget succeeded: msqid = %d\n", msqid);

  (void) strcpy(sbuf. mtext, "1111111111111111111");

  printf("msgget: msgget succeeded: msqid = %d\n", msqid);

  buf_length = strlen(sbuf.mtext) + 1;

  if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
    printf("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
    perror("msgsnd");
    exit(1);
  } else {
    printf("Message: \"%s\" Sent\n", sbuf.mtext);
  }



  sbuf.mtype = 2;

  printf("msgget: msgget succeeded: msqid = %d\n", msqid);

  (void) strcpy(sbuf. mtext, "22222222222222222222222222");

  printf("msgget: msgget succeeded: msqid = %d\n", msqid);

  buf_length = strlen(sbuf.mtext) + 1;

  if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
    printf("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
    perror("msgsnd");
    exit(1);
  } else {
    printf("Message: \"%s\" Sent\n", sbuf.mtext);
  }


  exit(0);
}
