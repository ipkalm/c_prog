// Copyright 2015
/*-------------------------------------------*/
/* mesg.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
  int msgid;
  key_t key = 10;

  msgid = msgget(key, 0666 | IPC_CREAT | IPC_EXCL);
  printf("Message queue created with id %d\n", msgid);

  return 0;
}
/*-------------------------------------------*/
