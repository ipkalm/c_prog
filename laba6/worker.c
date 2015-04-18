// код рабочего, кторый должен заблокировать файл шахты
// отнять 10 голда
// разблокировать файл шахты

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define CARGO 10
#define MAX_TRY 1

//int fileno(FILE * stream);
//int lockf(int fd, int cmd, off_t len);
//void exit(int exit_code);

int main(void)
{
  int fd_mine;
  int gold = 0;
  int kpd = 0;
  struct flock lck;
  pid_t pid = getpid();
  
  fd_mine = open("mine", O_RDWR);
  if (fd_mine < 0) {
    perror("mine");
    exit(2);
  }
  
  // задаем значение структуре блокировки файла
  lck.l_whence = 0; // смещение от начала
  lck.l_start = 0L; // начало блокировки с позиции 0
  lck.l_len = 0L; // и до конца
  
  for (;;) {
    lseek(fd_mine, 0L, 0);
    lck.l_type = F_WRLCK; // тип блокировки На запись
    fcntl(fd_mine, F_SETLKW, &lck);
    
    read(fd_mine, &gold, sizeof(int));
    
    if (gold > 9) {
      gold = gold - CARGO;
      kpd = kpd + CARGO;
      
      lseek(fd_mine, 0L, 0);
      write(fd_mine, &gold, sizeof(int));
      
      lck.l_type = F_UNLCK;
      fcntl(fd_mine, F_SETLK, &lck);
      
      //      sleep(0); // рабочий несет золото
    } else {
      lck.l_type = F_UNLCK; // тип блокировки - Разблокировать
      fcntl(fd_mine, F_SETLK, &lck);
      printf("натаскал %d золота (pid=%d)\n", kpd, pid);
      close(fd_mine);
      break;
    }
  }
  return 0;
}
